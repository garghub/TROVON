static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_2 -> V_5 ) ;
F_2 ( V_2 -> V_6 ) ;
F_2 ( V_2 -> V_7 ) ;
F_3 ( V_2 ) ;
F_4 ( V_4 , L_1 , V_8 ) ;
}
static int F_5 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 = NULL ;
int V_13 ;
int V_14 = 0 ;
F_6 ( & V_15 ) ;
V_13 = F_7 ( V_9 ) ;
V_12 = F_8 ( & V_16 , V_13 ) ;
if ( ! V_12 ) {
F_9 ( L_2 , V_13 ) ;
V_14 = - V_17 ;
goto exit;
}
V_2 = F_10 ( V_12 ) ;
if ( ! V_2 ) {
F_9 ( L_3 , V_13 ) ;
V_14 = - V_17 ;
goto exit;
}
F_6 ( & V_2 -> V_18 ) ;
if ( ! V_2 -> V_19 ) {
F_9 ( L_4 ) ;
V_14 = - V_17 ;
} else if ( V_2 -> V_20 ) {
F_9 ( L_5 ) ;
V_14 = - V_21 ;
} else {
V_2 -> V_20 = true ;
V_10 -> V_22 = V_2 ;
F_4 ( V_2 -> V_4 , L_6 ) ;
}
F_11 ( & V_2 -> V_18 ) ;
exit:
F_11 ( & V_15 ) ;
return V_14 ;
}
static int F_12 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
struct V_1 * V_2 = NULL ;
int V_14 = 0 ;
V_2 = V_10 -> V_22 ;
if ( ! V_2 ) {
F_9 ( L_7 ) ;
return - V_17 ;
}
F_6 ( & V_2 -> V_18 ) ;
if ( ! V_2 -> V_19 ) {
F_9 ( L_4 ) ;
V_14 = - V_17 ;
} else if ( ! V_2 -> V_20 ) {
F_9 ( L_8 ) ;
V_14 = - V_23 ;
} else {
V_2 -> V_20 = false ;
F_4 ( V_2 -> V_4 , L_9 ) ;
}
F_11 ( & V_2 -> V_18 ) ;
return V_14 ;
}
static int F_13 ( struct V_1 * V_2 )
{
unsigned int V_24 ;
unsigned long V_25 ;
int V_26 = 0 ;
int V_14 = 0 ;
struct V_27 * V_28 = NULL ;
if ( ! V_2 -> V_29 ) {
V_24 = F_14 ( V_2 -> V_30 ,
V_2 -> V_31 -> V_32 ) ;
V_26 = V_2 -> V_31 -> V_33 ;
F_15 ( V_2 -> V_5 , V_2 -> V_30 , V_24 ,
V_2 -> V_34 ,
sizeof( V_2 -> V_34 ) ,
V_35 , V_2 , V_26 ) ;
V_2 -> V_5 -> V_36 = 0 ;
} else {
V_28 = F_16 ( sizeof( struct V_27 ) ,
V_37 ) ;
if ( V_28 == NULL )
return - V_38 ;
V_28 -> V_39 = 0x21 ;
V_28 -> V_40 = 0x09 ;
V_28 -> V_41 = F_17 ( 0x0200 ) ;
V_28 -> V_42 = F_17 ( 0x0001 ) ;
V_28 -> V_43 = F_17 ( 0x0008 ) ;
V_24 = F_18 ( V_2 -> V_30 , 0 ) ;
F_19 ( V_2 -> V_5 , V_2 -> V_30 ,
V_24 , ( unsigned char * ) V_28 ,
V_2 -> V_34 ,
sizeof( V_2 -> V_34 ) ,
V_35 , V_2 ) ;
V_2 -> V_5 -> V_36 = 0 ;
}
F_20 ( & V_2 -> V_44 . V_45 ) ;
V_2 -> V_44 . V_46 = true ;
F_21 () ;
V_14 = F_22 ( V_2 -> V_5 , V_37 ) ;
if ( V_14 ) {
V_2 -> V_44 . V_46 = false ;
F_21 () ;
F_23 ( L_10 , V_14 ) ;
} else {
F_11 ( & V_2 -> V_18 ) ;
V_14 = F_24 (
& V_2 -> V_44 . V_45 ) ;
if ( V_14 ) {
F_25 ( V_2 -> V_5 ) ;
F_23 ( L_11 ) ;
}
F_6 ( & V_2 -> V_18 ) ;
V_14 = V_2 -> V_44 . V_47 ;
if ( V_14 )
F_23 ( L_12 , V_14 ) ;
}
F_3 ( V_28 ) ;
V_25 = F_26 ( V_2 -> V_48 ) ;
F_27 ( V_49 ) ;
F_28 ( V_25 ) ;
return V_14 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_14 ;
const unsigned char V_50 [ 8 ] = { 0x01 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x20 } ;
if ( ! V_2 ) {
F_9 ( L_7 ) ;
return - V_17 ;
}
if ( ! V_2 -> V_51 ) {
F_9 ( L_13 ) ;
return - V_17 ;
}
memcpy ( V_2 -> V_34 , V_50 , sizeof( V_50 ) ) ;
V_14 = F_13 ( V_2 ) ;
return V_14 ;
}
static int F_30 ( struct V_1 * V_2 ,
unsigned int V_52 , unsigned int V_53 ,
unsigned int V_54 , unsigned int V_55 ,
unsigned int V_56 , unsigned int V_57 ,
unsigned int V_58 )
{
unsigned char V_59 [ V_60 ] [ 8 ] ;
int V_14 = 0 ;
int V_61 ;
if ( ! V_2 ) {
F_9 ( L_7 ) ;
return - V_17 ;
}
switch ( V_2 -> V_62 ) {
case V_63 :
V_59 [ 0 ] [ 0 ] = 0x80 ;
V_59 [ 0 ] [ 1 ] = V_52 ;
V_59 [ 0 ] [ 2 ] = V_53 - 1 ;
V_59 [ 0 ] [ 3 ] = V_54 ;
V_59 [ 0 ] [ 4 ] = V_56 ;
V_59 [ 0 ] [ 5 ] = V_57 ;
V_59 [ 0 ] [ 6 ] = V_58 ;
V_59 [ 1 ] [ 0 ] = 0x80 ;
V_59 [ 1 ] [ 1 ] = 0 ;
V_59 [ 1 ] [ 2 ] = 0 ;
V_59 [ 1 ] [ 3 ] = 0 ;
V_59 [ 1 ] [ 4 ] = 0 ;
V_59 [ 1 ] [ 5 ] = 0 ;
V_59 [ 1 ] [ 6 ] = 0 ;
if ( V_2 -> V_64 == 0xffdc ) {
V_59 [ 0 ] [ 7 ] = 0x50 ;
V_59 [ 1 ] [ 7 ] = 0x51 ;
} else {
V_59 [ 0 ] [ 7 ] = 0x88 ;
V_59 [ 1 ] [ 7 ] = 0x8a ;
}
break;
case V_65 :
V_59 [ 0 ] [ 0 ] = V_52 ;
V_59 [ 0 ] [ 1 ] = V_53 - 1 ;
V_59 [ 0 ] [ 2 ] = V_54 ;
V_59 [ 0 ] [ 3 ] = V_55 ;
V_59 [ 0 ] [ 4 ] = V_56 ;
V_59 [ 0 ] [ 5 ] = V_57 ;
V_59 [ 0 ] [ 6 ] = V_58 ;
V_59 [ 0 ] [ 7 ] = 0x40 ;
V_59 [ 1 ] [ 0 ] = 0 ;
V_59 [ 1 ] [ 1 ] = 0 ;
V_59 [ 1 ] [ 2 ] = 1 ;
V_59 [ 1 ] [ 3 ] = 0 ;
V_59 [ 1 ] [ 4 ] = 0 ;
V_59 [ 1 ] [ 5 ] = 0 ;
V_59 [ 1 ] [ 6 ] = 0 ;
V_59 [ 1 ] [ 7 ] = 0x42 ;
break;
default:
return - V_17 ;
}
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ ) {
memcpy ( V_2 -> V_34 , V_59 [ V_61 ] , 8 ) ;
V_14 = F_13 ( V_2 ) ;
if ( V_14 ) {
F_9 ( L_14 , V_61 ) ;
break;
}
}
return V_14 ;
}
static T_1 F_31 ( struct V_3 * V_66 ,
struct V_67 * V_68 ,
char * V_69 )
{
struct V_1 * V_2 = F_32 ( V_66 ) ;
if ( ! V_2 )
return - V_17 ;
F_6 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_70 )
strcpy ( V_69 , L_15 ) ;
else
strcpy ( V_69 , L_16 ) ;
F_33 ( V_66 , L_17 ) ;
F_11 ( & V_2 -> V_18 ) ;
return strlen ( V_69 ) ;
}
static T_1 F_34 ( struct V_3 * V_66 ,
struct V_67 * V_68 ,
const char * V_69 , T_2 V_71 )
{
struct V_1 * V_2 ;
V_2 = F_32 ( V_66 ) ;
if ( ! V_2 )
return - V_17 ;
F_6 ( & V_2 -> V_18 ) ;
V_2 -> V_70 = true ;
F_29 ( V_2 ) ;
F_11 ( & V_2 -> V_18 ) ;
return V_71 ;
}
static T_1 F_35 ( struct V_3 * V_66 ,
struct V_67 * V_68 , char * V_69 )
{
struct V_1 * V_2 = F_32 ( V_66 ) ;
T_2 V_72 ;
if ( ! V_2 )
return - V_17 ;
F_6 ( & V_2 -> V_18 ) ;
if ( ! V_2 -> V_19 ) {
V_72 = snprintf ( V_69 , V_73 , L_18 ) ;
} else {
V_72 = snprintf ( V_69 , V_73 ,
L_19
L_20
L_21 , V_2 -> V_20 ?
L_22 : L_23 ) ;
}
F_11 ( & V_2 -> V_18 ) ;
return V_72 ;
}
static T_1 F_36 ( struct V_3 * V_66 ,
struct V_67 * V_68 ,
const char * V_69 , T_2 V_71 )
{
struct V_1 * V_2 = F_32 ( V_66 ) ;
T_1 V_14 ;
unsigned int V_52 , V_53 , V_54 , V_55 , V_56 , V_57 , V_58 ;
if ( ! V_2 )
return - V_17 ;
F_6 ( & V_2 -> V_18 ) ;
if ( ! V_2 -> V_19 ) {
V_14 = - V_17 ;
goto exit;
} else if ( V_2 -> V_20 ) {
V_14 = - V_21 ;
goto exit;
}
if ( sscanf ( V_69 , L_24 , & V_52 , & V_53 , & V_54 , & V_55 ,
& V_56 , & V_57 , & V_58 ) != 7 ) {
V_14 = - V_74 ;
goto exit;
}
if ( ( V_53 < 1 || V_53 > 12 ) ||
( V_54 < 1 || V_54 > 31 ) || ( V_55 > 6 ) ||
( V_56 > 23 ) || ( V_57 > 59 ) || ( V_58 > 59 ) ) {
V_14 = - V_74 ;
goto exit;
}
V_14 = F_30 ( V_2 , V_52 , V_53 , V_54 , V_55 ,
V_56 , V_57 , V_58 ) ;
if ( V_14 )
goto exit;
V_14 = V_71 ;
exit:
F_11 ( & V_2 -> V_18 ) ;
return V_14 ;
}
static T_1 F_37 ( struct V_10 * V_10 , const char T_3 * V_69 ,
T_2 V_75 , T_4 * V_76 )
{
int V_61 ;
int V_77 ;
int V_78 ;
int V_14 = 0 ;
struct V_1 * V_2 ;
const unsigned char V_79 [] = {
0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0xFF , 0xFF } ;
V_2 = V_10 -> V_22 ;
if ( ! V_2 ) {
F_23 ( L_7 ) ;
return - V_17 ;
}
F_6 ( & V_2 -> V_18 ) ;
if ( ! V_2 -> V_51 ) {
F_23 ( L_13 ) ;
V_14 = - V_17 ;
goto exit;
}
if ( V_75 <= 0 || V_75 > 32 ) {
F_23 ( L_25 ) ;
V_14 = - V_74 ;
goto exit;
}
if ( F_38 ( V_2 -> V_44 . V_80 , V_69 , V_75 ) ) {
V_14 = - V_81 ;
goto exit;
}
for ( V_61 = V_75 ; V_61 < 32 ; ++ V_61 )
V_2 -> V_44 . V_80 [ V_61 ] = ' ' ;
for ( V_61 = 32 ; V_61 < 35 ; ++ V_61 )
V_2 -> V_44 . V_80 [ V_61 ] = 0xFF ;
V_77 = 0 ;
V_78 = 0 ;
do {
memcpy ( V_2 -> V_34 , V_2 -> V_44 . V_80 + V_77 , 7 ) ;
V_2 -> V_34 [ 7 ] = ( unsigned char ) V_78 ;
V_14 = F_13 ( V_2 ) ;
if ( V_14 ) {
F_23 ( L_26 , V_78 / 2 ) ;
goto exit;
} else {
V_78 += 2 ;
V_77 += 7 ;
}
} while ( V_77 < 35 );
memcpy ( V_2 -> V_34 , & V_79 , sizeof( V_79 ) ) ;
V_2 -> V_34 [ 7 ] = ( unsigned char ) V_78 ;
V_14 = F_13 ( V_2 ) ;
if ( V_14 )
F_23 ( L_26 , V_78 / 2 ) ;
exit:
F_11 ( & V_2 -> V_18 ) ;
return ( ! V_14 ) ? V_75 : V_14 ;
}
static T_1 F_39 ( struct V_10 * V_10 , const char T_3 * V_69 ,
T_2 V_75 , T_4 * V_76 )
{
int V_14 = 0 ;
struct V_1 * V_2 ;
V_2 = V_10 -> V_22 ;
if ( ! V_2 ) {
F_23 ( L_7 ) ;
return - V_17 ;
}
F_6 ( & V_2 -> V_18 ) ;
if ( ! V_2 -> V_19 ) {
F_23 ( L_27 ) ;
V_14 = - V_17 ;
goto exit;
}
if ( V_75 != 8 ) {
F_23 ( L_28 ,
( int ) V_75 ) ;
V_14 = - V_74 ;
goto exit;
}
if ( F_38 ( V_2 -> V_34 , V_69 , 8 ) ) {
V_14 = - V_81 ;
goto exit;
}
V_14 = F_13 ( V_2 ) ;
if ( V_14 ) {
F_23 ( L_29 ) ;
goto exit;
} else {
F_4 ( V_2 -> V_4 , L_30 ,
V_8 , ( int ) V_75 ) ;
}
exit:
F_11 ( & V_2 -> V_18 ) ;
return ( ! V_14 ) ? V_75 : V_14 ;
}
static void V_35 ( struct V_82 * V_82 )
{
struct V_1 * V_2 ;
if ( ! V_82 )
return;
V_2 = (struct V_1 * ) V_82 -> V_83 ;
if ( ! V_2 )
return;
V_2 -> V_44 . V_47 = V_82 -> V_47 ;
V_2 -> V_44 . V_46 = false ;
F_21 () ;
F_40 ( & V_2 -> V_44 . V_45 ) ;
}
static void F_41 ( unsigned long V_84 )
{
struct V_1 * V_2 = (struct V_1 * ) V_84 ;
if ( V_2 -> V_62 != V_85 )
return;
F_42 ( V_2 -> V_86 , V_87 , V_2 -> V_88 ) ;
F_42 ( V_2 -> V_86 , V_89 , V_2 -> V_90 ) ;
F_43 ( V_2 -> V_86 , V_91 , 0x00 ) ;
F_44 ( V_2 -> V_86 ) ;
}
static int F_45 ( struct V_92 * V_93 , T_5 * V_94 )
{
int V_14 ;
struct V_1 * V_2 = V_93 -> V_95 ;
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_96 = false ;
unsigned char V_97 [] = {
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x86 } ;
if ( * V_94 && ! ( * V_94 & V_93 -> V_98 ) )
F_46 ( V_4 , L_31 ) ;
if ( * V_94 & V_99 ) {
F_4 ( V_4 , L_32 ) ;
V_97 [ 0 ] = 0x01 ;
* V_94 = V_99 ;
} else if ( * V_94 & V_100 ) {
F_4 ( V_4 , L_33 ) ;
if ( ! V_101 )
F_4 ( V_4 , L_34 ) ;
* V_94 = V_100 ;
} else {
F_46 ( V_4 , L_35 ) ;
if ( ! V_101 )
F_4 ( V_4 , L_34 ) ;
* V_94 = V_100 ;
}
memcpy ( V_2 -> V_34 , & V_97 , sizeof( V_97 ) ) ;
if ( ! F_47 ( & V_2 -> V_18 ) ) {
V_96 = true ;
F_6 ( & V_2 -> V_18 ) ;
}
V_14 = F_13 ( V_2 ) ;
if ( V_14 )
goto V_102;
V_2 -> V_94 = * V_94 ;
V_2 -> V_103 = false ;
V_102:
if ( V_96 )
F_11 ( & V_2 -> V_18 ) ;
return V_14 ;
}
static inline int F_48 ( const struct V_104 * V_105 , const struct V_104 * V_106 )
{
int V_107 = 0 ;
int V_108 = 0 ;
if ( V_106 -> V_109 > V_105 -> V_109 ) {
V_107 = 1000000 ;
V_108 -- ;
}
V_107 += V_105 -> V_109 - V_106 -> V_109 ;
V_108 += V_105 -> V_110 - V_106 -> V_110 ;
V_108 *= 1000 ;
V_107 /= 1000 ;
V_108 += V_107 ;
if ( V_108 < 0 )
V_108 = 1000 ;
return V_108 ;
}
static int F_49 ( int V_105 , int V_106 , T_6 V_25 , T_6 V_111 )
{
struct V_104 V_112 ;
static struct V_104 V_113 = { 0 , 0 } ;
static struct V_104 V_114 = { 0 , 0 } ;
static int V_115 , V_116 , V_117 , V_118 ;
int V_119 = 0 ;
int V_120 , V_121 ;
F_50 ( & V_112 ) ;
V_120 = F_48 ( & V_112 , & V_113 ) ;
V_121 = F_48 ( & V_112 , & V_114 ) ;
if ( V_120 > 100 ) {
V_115 = 0 ;
V_116 = 0 ;
V_118 = 0 ;
}
V_115 += V_105 ;
V_116 += V_106 ;
V_113 = V_112 ;
if ( abs ( V_115 ) > V_111 || abs ( V_116 ) > V_111 ) {
if ( abs ( V_116 ) > abs ( V_115 ) )
V_119 = ( V_116 > 0 ) ? 0x7F : 0x80 ;
else
V_119 = ( V_115 > 0 ) ? 0x7F00 : 0x8000 ;
V_115 = 0 ;
V_116 = 0 ;
if ( V_119 == V_117 ) {
V_118 ++ ;
if ( V_118 > 3 ) {
switch ( V_119 ) {
case 0x7F :
V_116 = 17 * V_111 / 30 ;
break;
case 0x80 :
V_116 -= 17 * V_111 / 30 ;
break;
case 0x7F00 :
V_115 = 17 * V_111 / 30 ;
break;
case 0x8000 :
V_115 -= 17 * V_111 / 30 ;
break;
}
}
if ( V_118 == 2 && V_121 < V_25 ) {
V_119 = 0 ;
V_118 = 1 ;
}
} else {
V_117 = V_119 ;
V_118 = 1 ;
V_114 = V_112 ;
}
}
return V_119 ;
}
static T_7 F_51 ( struct V_1 * V_2 , T_7 V_122 )
{
T_7 V_123 ;
T_7 V_124 ;
bool V_125 = false ;
V_123 = F_52 ( V_2 -> V_126 , V_122 ) ;
V_2 -> V_127 = 0x0 ;
V_2 -> V_128 = V_122 ;
if ( V_123 == V_129 ) {
V_124 = V_122 & ~ 0x4000 ;
V_123 = F_52 ( V_2 -> V_126 , V_124 ) ;
if ( V_123 != V_129 )
V_125 = true ;
}
V_2 -> V_130 = V_125 ;
return V_123 ;
}
static T_7 F_53 ( struct V_1 * V_2 , T_7 V_122 )
{
T_7 V_123 ;
#define F_54 0x7000
#define F_55 0x8000
if ( V_122 & 0x80000000 )
V_122 = V_122 | F_54 | F_55 ;
V_2 -> V_128 = V_122 ;
V_123 = F_52 ( V_2 -> V_126 , V_122 ) ;
V_2 -> V_130 = false ;
return V_123 ;
}
static T_7 F_56 ( struct V_1 * V_2 , T_5 V_131 )
{
int V_61 ;
T_7 V_123 = V_129 ;
struct V_132 * V_133 = V_2 -> V_134 -> V_133 ;
for ( V_61 = 0 ; V_133 [ V_61 ] . V_135 != 0 ; V_61 ++ ) {
if ( V_133 [ V_61 ] . V_135 == ( V_131 | 0xffee ) ) {
V_123 = V_133 [ V_61 ] . V_123 ;
break;
}
}
V_2 -> V_130 = false ;
return V_123 ;
}
static bool F_57 ( struct V_1 * V_2 ,
unsigned char * V_69 , int V_72 )
{
signed char V_136 = 0x00 , V_137 = 0x00 ;
T_8 V_138 = 1 ;
bool V_139 = true ;
int V_140 = 0 ;
unsigned long V_141 ;
F_58 ( & V_2 -> V_142 , V_141 ) ;
if ( V_2 -> V_64 != 0xffdc && ( V_69 [ 0 ] & 0x01 ) && V_72 == 5 ) {
V_136 = V_69 [ 2 ] ;
V_137 = V_69 [ 3 ] ;
V_138 = 1 ;
} else if ( V_2 -> V_64 == 0xffdc && ( V_69 [ 0 ] & 0x40 ) &&
! ( ( V_69 [ 1 ] & 0x01 ) || ( ( V_69 [ 1 ] >> 2 ) & 0x01 ) ) ) {
V_136 = ( V_69 [ 1 ] & 0x08 ) | ( V_69 [ 1 ] & 0x10 ) >> 2 |
( V_69 [ 1 ] & 0x20 ) >> 4 | ( V_69 [ 1 ] & 0x40 ) >> 6 ;
if ( V_69 [ 0 ] & 0x02 )
V_136 |= ~ 0x0f ;
V_136 = V_136 + V_136 / 2 ;
V_137 = ( V_69 [ 2 ] & 0x08 ) | ( V_69 [ 2 ] & 0x10 ) >> 2 |
( V_69 [ 2 ] & 0x20 ) >> 4 | ( V_69 [ 2 ] & 0x40 ) >> 6 ;
if ( V_69 [ 0 ] & 0x01 )
V_137 |= ~ 0x0f ;
V_137 = V_137 + V_137 / 2 ;
V_138 = 2 ;
} else if ( V_2 -> V_64 == 0xffdc && ( V_69 [ 0 ] == 0x68 ) ) {
V_138 = 2 ;
} else if ( V_2 -> V_143 == V_144 && ( V_69 [ 2 ] & 0x40 ) != 0x40 ) {
V_140 = 1 ;
} else if ( V_2 -> V_143 == V_145 && ( V_69 [ 2 ] & 0x40 ) != 0x40 ) {
V_140 = - 1 ;
} else
V_139 = false ;
F_59 ( & V_2 -> V_142 , V_141 ) ;
if ( V_139 ) {
F_4 ( V_2 -> V_4 , L_36 ) ;
if ( V_140 ) {
F_60 ( V_2 -> V_146 , V_147 , V_140 ) ;
} else if ( V_136 || V_137 ) {
F_60 ( V_2 -> V_146 , V_148 , V_136 ) ;
F_60 ( V_2 -> V_146 , V_149 , V_137 ) ;
} else {
F_43 ( V_2 -> V_146 , V_150 , V_69 [ 1 ] & 0x1 ) ;
F_43 ( V_2 -> V_146 , V_151 ,
V_69 [ 1 ] >> V_138 & 0x1 ) ;
}
F_44 ( V_2 -> V_146 ) ;
F_58 ( & V_2 -> V_142 , V_141 ) ;
V_2 -> V_152 = V_2 -> V_143 ;
F_59 ( & V_2 -> V_142 , V_141 ) ;
}
return V_139 ;
}
static void F_61 ( struct V_1 * V_2 , unsigned char * V_69 )
{
F_62 ( & V_2 -> V_153 , V_154 + V_155 ) ;
V_2 -> V_88 = ( V_69 [ 0 ] << 4 ) | ( V_69 [ 1 ] >> 4 ) ;
V_2 -> V_90 = 0xfff - ( ( V_69 [ 2 ] << 4 ) | ( V_69 [ 1 ] & 0xf ) ) ;
F_42 ( V_2 -> V_86 , V_87 , V_2 -> V_88 ) ;
F_42 ( V_2 -> V_86 , V_89 , V_2 -> V_90 ) ;
F_43 ( V_2 -> V_86 , V_91 , 0x01 ) ;
F_44 ( V_2 -> V_86 ) ;
}
static void F_63 ( struct V_1 * V_2 , unsigned char * V_69 )
{
int V_140 = 0 ;
signed char V_136 = 0x00 , V_137 = 0x00 ;
T_6 V_25 , V_111 ;
T_7 V_122 = V_129 ;
unsigned long V_141 ;
if ( V_2 -> V_64 != 0xffdc ) {
V_69 [ 5 ] = V_69 [ 6 ] = V_69 [ 7 ] = 0 ;
V_25 = 500 ;
V_111 = V_156 ? V_156 : 28 ;
V_136 = V_69 [ 2 ] ;
V_137 = V_69 [ 3 ] ;
if ( V_2 -> V_94 == V_100 && V_101 ) {
if ( ( V_69 [ 1 ] == 0 ) && ( ( V_136 != 0 ) || ( V_137 != 0 ) ) ) {
V_140 = F_49 ( ( int ) V_136 , ( int ) V_137 ,
V_25 , V_111 ) ;
if ( ! V_140 ) {
F_58 ( & V_2 -> V_142 ,
V_141 ) ;
V_2 -> V_143 = V_157 ;
F_59 ( & V_2 -> V_142 ,
V_141 ) ;
return;
}
V_69 [ 2 ] = V_140 & 0xFF ;
V_69 [ 3 ] = ( V_140 >> 8 ) & 0xFF ;
V_122 = F_64 ( * ( ( V_158 * ) V_69 ) ) ;
}
} else {
if ( abs ( V_137 ) > abs ( V_136 ) ) {
V_69 [ 2 ] = ( V_137 > 0 ) ? 0x7F : 0x80 ;
V_69 [ 3 ] = 0 ;
if ( V_137 > 0 )
V_122 = 0x01007f00 ;
else
V_122 = 0x01008000 ;
} else {
V_69 [ 2 ] = 0 ;
V_69 [ 3 ] = ( V_136 > 0 ) ? 0x7F : 0x80 ;
if ( V_136 > 0 )
V_122 = 0x0100007f ;
else
V_122 = 0x01000080 ;
}
}
} else {
V_25 = 10 ;
V_111 = V_156 ? V_156 : 15 ;
V_136 = ( V_69 [ 1 ] & 0x08 ) | ( V_69 [ 1 ] & 0x10 ) >> 2 |
( V_69 [ 1 ] & 0x20 ) >> 4 | ( V_69 [ 1 ] & 0x40 ) >> 6 ;
if ( V_69 [ 0 ] & 0x02 )
V_136 |= ~ 0x10 + 1 ;
V_137 = ( V_69 [ 2 ] & 0x08 ) | ( V_69 [ 2 ] & 0x10 ) >> 2 |
( V_69 [ 2 ] & 0x20 ) >> 4 | ( V_69 [ 2 ] & 0x40 ) >> 6 ;
if ( V_69 [ 0 ] & 0x01 )
V_137 |= ~ 0x10 + 1 ;
V_69 [ 0 ] = 0x01 ;
V_69 [ 1 ] = V_69 [ 4 ] = V_69 [ 5 ] = V_69 [ 6 ] = V_69 [ 7 ] = 0 ;
if ( V_2 -> V_94 == V_100 && V_101 ) {
V_140 = F_49 ( ( int ) V_136 , ( int ) V_137 ,
V_25 , V_111 ) ;
if ( ! V_140 ) {
F_58 ( & V_2 -> V_142 , V_141 ) ;
V_2 -> V_143 = V_157 ;
F_59 ( & V_2 -> V_142 , V_141 ) ;
return;
}
V_69 [ 2 ] = V_140 & 0xFF ;
V_69 [ 3 ] = ( V_140 >> 8 ) & 0xFF ;
V_122 = F_64 ( * ( ( V_158 * ) V_69 ) ) ;
} else {
if ( abs ( V_137 ) > abs ( V_136 ) ) {
V_69 [ 2 ] = ( V_137 > 0 ) ? 0x7F : 0x80 ;
V_69 [ 3 ] = 0 ;
if ( V_137 > 0 )
V_122 = 0x01007f00 ;
else
V_122 = 0x01008000 ;
} else {
V_69 [ 2 ] = 0 ;
V_69 [ 3 ] = ( V_136 > 0 ) ? 0x7F : 0x80 ;
if ( V_136 > 0 )
V_122 = 0x0100007f ;
else
V_122 = 0x01000080 ;
}
}
}
if ( V_122 ) {
F_58 ( & V_2 -> V_142 , V_141 ) ;
V_2 -> V_143 = F_51 ( V_2 , V_122 ) ;
F_59 ( & V_2 -> V_142 , V_141 ) ;
}
}
static int F_65 ( struct V_1 * V_2 ,
unsigned char * V_69 , T_8 V_159 )
{
int V_160 = 0 ;
unsigned long V_141 ;
F_58 ( & V_2 -> V_142 , V_141 ) ;
if ( V_2 -> V_143 == V_129 && V_69 [ 0 ] == 0x02 && V_69 [ 3 ] == 0x00 )
V_2 -> V_143 = V_2 -> V_152 ;
else if ( V_2 -> V_143 == V_129 && V_69 [ 0 ] == 0x68 && V_69 [ 1 ] == 0x82 &&
V_69 [ 2 ] == 0x81 && V_69 [ 3 ] == 0xb7 )
V_2 -> V_143 = V_2 -> V_152 ;
else if ( V_2 -> V_143 == V_129 && V_69 [ 0 ] == 0x01 && V_69 [ 1 ] == 0x00 &&
V_69 [ 2 ] == 0x81 && V_69 [ 3 ] == 0xb7 )
V_2 -> V_143 = V_2 -> V_152 ;
else if ( V_159 == V_161 ) {
V_2 -> V_127 = V_69 [ 2 ] ;
V_160 = 1 ;
} else if ( V_2 -> V_143 == V_129 )
V_160 = - V_74 ;
else if ( V_2 -> V_130 )
V_160 = 0 ;
else
V_160 = 1 ;
F_59 ( & V_2 -> V_142 , V_141 ) ;
return V_160 ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_82 * V_82 , int V_162 )
{
int V_72 = V_82 -> V_36 ;
unsigned char * V_69 = V_82 -> V_163 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_141 ;
T_7 V_143 ;
T_5 V_122 ;
int V_160 = 0 ;
int V_120 ;
struct V_104 V_164 ;
static struct V_104 V_113 = { 0 , 0 } ;
T_8 V_159 ;
if ( ( V_69 [ 0 ] == 0xff ) && ( V_69 [ 1 ] == 0xff ) && ( V_69 [ 2 ] == 0xff ) )
return;
if ( V_72 == 8 && V_69 [ 7 ] == 0xee ) {
V_122 = F_67 ( * ( ( V_165 * ) V_69 ) ) ;
V_159 = V_166 ;
V_143 = F_56 ( V_2 , V_122 ) ;
V_2 -> V_130 = false ;
} else {
V_122 = F_64 ( * ( ( V_158 * ) V_69 ) ) ;
if ( V_2 -> V_94 == V_99 ) {
V_159 = V_167 ;
if ( V_69 [ 0 ] == 0x80 )
V_159 = V_161 ;
V_143 = F_53 ( V_2 , V_122 ) ;
} else {
V_159 = V_167 ;
V_143 = F_51 ( V_2 , V_122 ) ;
}
}
F_58 ( & V_2 -> V_142 , V_141 ) ;
if ( V_143 == V_168 && ! V_2 -> V_130 ) {
V_2 -> V_152 = V_143 ;
if ( ! V_169 ) {
V_2 -> V_103 = ~ ( V_2 -> V_103 ) & 0x1 ;
F_4 ( V_4 , L_37 ,
V_2 -> V_103 ? L_38 : L_39 ) ;
F_59 ( & V_2 -> V_142 , V_141 ) ;
return;
} else {
V_2 -> V_103 = false ;
F_4 ( V_4 , L_40 ) ;
}
}
V_2 -> V_143 = V_143 ;
F_59 ( & V_2 -> V_142 , V_141 ) ;
if ( V_2 -> V_62 == V_85 && V_72 == 8 &&
V_69 [ 7 ] == 0x86 ) {
F_61 ( V_2 , V_69 ) ;
return;
} else if ( V_2 -> V_103 ) {
if ( F_57 ( V_2 , V_69 , V_72 ) )
return;
}
if ( ( ( V_72 == 5 ) && ( V_69 [ 0 ] == 0x01 ) && ( V_69 [ 4 ] == 0x00 ) ) ||
( ( V_72 == 8 ) && ( V_69 [ 0 ] & 0x40 ) &&
! ( V_69 [ 1 ] & 0x1 || V_69 [ 1 ] >> 2 & 0x1 ) ) ) {
V_72 = 8 ;
F_63 ( V_2 , V_69 ) ;
}
if ( V_170 ) {
F_68 ( V_171 L_41 ,
V_162 , V_72 , V_69 ) ;
}
V_160 = F_65 ( V_2 , V_69 , V_159 ) ;
if ( V_160 < 0 )
goto V_172;
if ( V_159 != V_166 ) {
if ( V_160 == 0 )
F_69 ( V_2 -> V_126 ) ;
else {
if ( V_2 -> V_94 == V_99 ||
V_2 -> V_94 == V_100 )
F_70 ( V_2 -> V_126 ,
V_2 -> V_94 == V_99 ? V_173 : V_174 ,
V_2 -> V_128 , V_2 -> V_127 ) ;
F_58 ( & V_2 -> V_142 , V_141 ) ;
V_2 -> V_152 = V_2 -> V_143 ;
F_59 ( & V_2 -> V_142 , V_141 ) ;
}
return;
}
F_58 ( & V_2 -> V_142 , V_141 ) ;
F_50 ( & V_164 ) ;
if ( V_2 -> V_143 == V_175 && V_2 -> V_143 == V_2 -> V_152 ) {
V_120 = F_48 ( & V_164 , & V_113 ) ;
if ( V_120 < V_2 -> V_146 -> V_176 [ V_177 ] ) {
F_59 ( & V_2 -> V_142 , V_141 ) ;
return;
}
}
V_113 = V_164 ;
V_143 = V_2 -> V_143 ;
F_59 ( & V_2 -> V_142 , V_141 ) ;
F_43 ( V_2 -> V_146 , V_143 , V_160 ) ;
F_44 ( V_2 -> V_146 ) ;
F_43 ( V_2 -> V_146 , V_143 , 0 ) ;
F_44 ( V_2 -> V_146 ) ;
F_58 ( & V_2 -> V_142 , V_141 ) ;
V_2 -> V_152 = V_143 ;
F_59 ( & V_2 -> V_142 , V_141 ) ;
return;
V_172:
if ( V_72 != 8 ) {
F_46 ( V_4 , L_42 ,
V_8 , V_72 , V_162 ) ;
return;
}
if ( V_69 [ 0 ] == 0x00 &&
V_69 [ 2 ] == 0xFF &&
V_69 [ 3 ] == 0xFF &&
V_69 [ 4 ] == 0xFF &&
V_69 [ 5 ] == 0xFF &&
( ( V_69 [ 6 ] == 0x4E && V_69 [ 7 ] == 0xDF ) ||
( V_69 [ 6 ] == 0x5E && V_69 [ 7 ] == 0xDF ) ) ) {
F_46 ( V_4 , L_43 ,
V_8 , V_69 [ 1 ] ) ;
V_2 -> V_70 = false ;
}
}
static void F_71 ( struct V_82 * V_82 )
{
struct V_1 * V_2 ;
int V_178 = 0 ;
if ( ! V_82 )
return;
V_2 = (struct V_1 * ) V_82 -> V_83 ;
if ( ! V_2 )
return;
if ( ! V_2 -> V_51 )
goto V_102;
switch ( V_82 -> V_47 ) {
case - V_179 :
return;
case - V_180 :
break;
case 0 :
F_66 ( V_2 , V_82 , V_178 ) ;
break;
default:
F_46 ( V_2 -> V_4 , L_44 ,
V_8 , V_82 -> V_47 ) ;
break;
}
V_102:
F_22 ( V_2 -> V_6 , V_181 ) ;
}
static void F_72 ( struct V_82 * V_82 )
{
struct V_1 * V_2 ;
int V_178 = 1 ;
if ( ! V_82 )
return;
V_2 = (struct V_1 * ) V_82 -> V_83 ;
if ( ! V_2 )
return;
if ( ! V_2 -> V_182 )
goto V_102;
switch ( V_82 -> V_47 ) {
case - V_179 :
return;
case - V_180 :
break;
case 0 :
F_66 ( V_2 , V_82 , V_178 ) ;
break;
default:
F_46 ( V_2 -> V_4 , L_44 ,
V_8 , V_82 -> V_47 ) ;
break;
}
V_102:
F_22 ( V_2 -> V_7 , V_181 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
T_8 V_183 = V_2 -> V_184 [ 6 ] ;
T_8 V_185 = V_186 ;
T_5 V_187 = V_100 ;
switch ( V_183 ) {
case 0x21 :
F_33 ( V_2 -> V_4 , L_45 ) ;
V_2 -> V_19 = false ;
break;
case 0x4e :
F_33 ( V_2 -> V_4 , L_46 ) ;
V_2 -> V_19 = false ;
V_2 -> V_188 = true ;
break;
case 0x35 :
F_33 ( V_2 -> V_4 , L_47 ) ;
V_185 = V_65 ;
break;
case 0x24 :
case 0x85 :
F_33 ( V_2 -> V_4 , L_48 ) ;
V_185 = V_65 ;
break;
case 0x46 :
case 0x7e :
case 0x9e :
F_33 ( V_2 -> V_4 , L_49 ) ;
V_185 = V_65 ;
V_187 = V_99 ;
break;
case 0x9f :
F_33 ( V_2 -> V_4 , L_50 ) ;
V_185 = V_63 ;
V_187 = V_99 ;
break;
default:
F_33 ( V_2 -> V_4 , L_51 ) ;
V_185 = V_65 ;
V_187 |= V_99 ;
break;
}
F_68 ( V_189 L_52 , V_183 ) ;
V_2 -> V_62 = V_185 ;
V_2 -> V_94 = V_187 ;
}
static void F_74 ( struct V_1 * V_2 )
{
T_8 V_190 = V_65 ;
if ( V_62 == V_191 ) {
switch ( V_2 -> V_64 ) {
case 0xffdc :
V_190 = V_2 -> V_62 ;
break;
case 0x0034 :
case 0x0035 :
V_190 = V_85 ;
break;
case 0x0038 :
case 0x0039 :
case 0x0045 :
V_190 = V_63 ;
break;
case 0x003c :
case 0x0041 :
case 0x0042 :
case 0x0043 :
V_190 = V_186 ;
V_2 -> V_19 = false ;
break;
case 0x0036 :
case 0x0044 :
default:
V_190 = V_65 ;
break;
}
} else {
V_190 = V_62 ;
if ( V_62 == V_186 )
V_2 -> V_19 = false ;
else
V_2 -> V_19 = true ;
F_33 ( V_2 -> V_4 , L_53 ,
V_8 , V_62 ) ;
}
V_2 -> V_62 = V_190 ;
}
static struct V_92 * F_75 ( struct V_1 * V_2 )
{
struct V_92 * V_126 ;
int V_192 ;
const unsigned char V_193 [] = { 0x40 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x88 } ;
V_126 = F_76 () ;
if ( ! V_126 ) {
F_77 ( V_2 -> V_4 , L_54 ) ;
goto V_102;
}
snprintf ( V_2 -> V_194 , sizeof( V_2 -> V_194 ) ,
L_55 , V_2 -> V_195 , V_2 -> V_64 ) ;
F_78 ( V_2 -> V_30 , V_2 -> V_196 ,
sizeof( V_2 -> V_196 ) ) ;
F_79 ( V_2 -> V_196 , L_56 , sizeof( V_2 -> V_196 ) ) ;
V_126 -> V_197 = V_2 -> V_194 ;
V_126 -> V_198 = V_2 -> V_196 ;
F_80 ( V_2 -> V_30 , & V_126 -> V_199 ) ;
V_126 -> V_4 . V_200 = V_2 -> V_4 ;
V_126 -> V_95 = V_2 ;
V_126 -> V_201 = V_202 ;
V_126 -> V_98 = V_100 | V_99 ;
V_126 -> V_203 = F_45 ;
V_126 -> V_204 = V_205 ;
memcpy ( V_2 -> V_34 , & V_193 , sizeof( V_193 ) ) ;
V_192 = F_13 ( V_2 ) ;
if ( V_192 )
F_33 ( V_2 -> V_4 , L_57 ) ;
if ( V_2 -> V_64 == 0xffdc ) {
F_73 ( V_2 ) ;
V_126 -> V_98 = V_2 -> V_94 ;
}
F_74 ( V_2 ) ;
if ( V_2 -> V_94 == V_99 )
V_126 -> V_206 = V_207 ;
else
V_126 -> V_206 = V_208 ;
V_192 = F_81 ( V_126 ) ;
if ( V_192 < 0 ) {
F_77 ( V_2 -> V_4 , L_58 ) ;
goto V_102;
}
return V_126 ;
V_102:
F_82 ( V_126 ) ;
return NULL ;
}
static struct V_209 * F_83 ( struct V_1 * V_2 )
{
struct V_132 * V_133 = V_2 -> V_134 -> V_133 ;
struct V_209 * V_146 ;
int V_192 , V_61 ;
V_146 = F_84 () ;
if ( ! V_146 )
goto V_102;
snprintf ( V_2 -> V_210 , sizeof( V_2 -> V_210 ) ,
L_59 ,
V_2 -> V_195 , V_2 -> V_64 ) ;
V_146 -> V_211 = V_2 -> V_210 ;
F_78 ( V_2 -> V_30 , V_2 -> V_212 ,
sizeof( V_2 -> V_212 ) ) ;
F_79 ( V_2 -> V_212 , L_60 , sizeof( V_2 -> V_212 ) ) ;
V_146 -> V_213 = V_2 -> V_212 ;
V_146 -> V_214 [ 0 ] = F_85 ( V_215 ) | F_85 ( V_216 ) | F_85 ( V_217 ) ;
V_146 -> V_218 [ F_86 ( V_219 ) ] =
F_85 ( V_150 ) | F_85 ( V_151 ) ;
V_146 -> V_220 [ 0 ] = F_85 ( V_148 ) | F_85 ( V_149 ) |
F_85 ( V_147 ) ;
for ( V_61 = 0 ; V_133 [ V_61 ] . V_135 != 0 ; V_61 ++ ) {
T_7 V_143 = V_133 [ V_61 ] . V_123 ;
F_87 ( V_143 , V_146 -> V_218 ) ;
}
F_80 ( V_2 -> V_30 , & V_146 -> V_221 ) ;
V_146 -> V_4 . V_200 = V_2 -> V_4 ;
F_88 ( V_146 , V_2 ) ;
V_192 = F_89 ( V_146 ) ;
if ( V_192 < 0 ) {
F_77 ( V_2 -> V_4 , L_61 ) ;
goto V_102;
}
return V_146 ;
V_102:
F_90 ( V_146 ) ;
return NULL ;
}
static struct V_209 * F_91 ( struct V_1 * V_2 )
{
struct V_209 * V_86 ;
int V_192 ;
V_86 = F_84 () ;
if ( ! V_86 )
goto V_222;
snprintf ( V_2 -> V_223 , sizeof( V_2 -> V_223 ) ,
L_62 ,
V_2 -> V_195 , V_2 -> V_64 ) ;
V_86 -> V_211 = V_2 -> V_223 ;
F_78 ( V_2 -> V_224 , V_2 -> V_225 ,
sizeof( V_2 -> V_225 ) ) ;
F_79 ( V_2 -> V_225 , L_63 , sizeof( V_2 -> V_225 ) ) ;
V_86 -> V_213 = V_2 -> V_225 ;
V_86 -> V_214 [ 0 ] =
F_85 ( V_215 ) | F_85 ( V_226 ) ;
V_86 -> V_218 [ F_86 ( V_91 ) ] =
F_85 ( V_91 ) ;
F_92 ( V_86 , V_87 ,
0x00 , 0xfff , 0 , 0 ) ;
F_92 ( V_86 , V_89 ,
0x00 , 0xfff , 0 , 0 ) ;
F_88 ( V_86 , V_2 ) ;
F_80 ( V_2 -> V_224 , & V_86 -> V_221 ) ;
V_86 -> V_4 . V_200 = V_2 -> V_4 ;
V_192 = F_89 ( V_86 ) ;
if ( V_192 < 0 ) {
F_33 ( V_2 -> V_4 , L_64 ) ;
goto V_227;
}
return V_86 ;
V_227:
F_90 ( V_86 ) ;
V_222:
return NULL ;
}
static bool F_93 ( struct V_1 * V_2 ,
struct V_228 * V_229 )
{
struct V_230 * V_231 ;
struct V_230 * V_232 = NULL ;
struct V_230 * V_31 = NULL ;
int V_233 = V_229 -> V_234 . V_235 ;
int V_236 = V_229 -> V_234 . V_237 ;
int V_61 , V_238 , V_239 ;
bool V_240 = false ;
bool V_241 = false ;
bool V_29 = false ;
for ( V_61 = 0 ; V_61 < V_236 && ! ( V_240 && V_241 ) ; ++ V_61 ) {
V_231 = & V_229 -> V_242 [ V_61 ] . V_234 ;
V_238 = V_231 -> V_32 & V_243 ;
V_239 = F_94 ( V_231 ) ;
if ( ! V_240 && V_238 == V_244 &&
V_239 == V_245 ) {
V_232 = V_231 ;
V_240 = true ;
F_4 ( V_2 -> V_4 , L_65 , V_8 ) ;
} else if ( ! V_241 && V_238 == V_246 &&
V_239 == V_245 ) {
V_31 = V_231 ;
V_241 = true ;
F_4 ( V_2 -> V_4 , L_66 , V_8 ) ;
}
}
if ( V_233 == 0 ) {
V_2 -> V_247 = V_232 ;
V_2 -> V_31 = V_31 ;
} else {
V_2 -> V_248 = V_232 ;
}
if ( ! V_241 ) {
V_29 = true ;
V_241 = true ;
F_4 ( V_2 -> V_4 , L_67 ,
V_8 ) ;
}
if ( V_2 -> V_62 == V_186 ) {
V_241 = false ;
F_4 ( V_2 -> V_4 , L_68 , V_8 ) ;
}
if ( V_2 -> V_62 == V_85 ) {
V_241 = false ;
F_4 ( V_2 -> V_4 , L_69 , V_8 ) ;
}
if ( ! V_240 )
F_9 ( L_70 ) ;
V_2 -> V_29 = V_29 ;
if ( V_241 )
V_2 -> V_19 = true ;
return V_240 ;
}
static struct V_1 * F_95 ( struct V_11 * V_162 ,
const struct V_249 * V_221 )
{
struct V_1 * V_2 ;
struct V_82 * V_250 ;
struct V_82 * V_5 ;
struct V_3 * V_4 = & V_162 -> V_4 ;
struct V_228 * V_229 ;
int V_192 = - V_38 ;
V_2 = F_96 ( sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_2 ) {
F_77 ( V_4 , L_71 , V_8 ) ;
goto exit;
}
V_250 = F_97 ( 0 , V_37 ) ;
if ( ! V_250 )
goto V_251;
V_5 = F_97 ( 0 , V_37 ) ;
if ( ! V_5 )
goto V_252;
F_98 ( & V_2 -> V_18 ) ;
F_99 ( & V_2 -> V_142 ) ;
F_6 ( & V_2 -> V_18 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_30 = F_100 ( F_101 ( V_162 ) ) ;
V_2 -> V_6 = V_250 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_188 = false ;
F_102 ( & V_2 -> V_44 . V_45 ) ;
V_2 -> V_195 = F_103 ( V_2 -> V_30 -> V_253 . V_254 ) ;
V_2 -> V_64 = F_103 ( V_2 -> V_30 -> V_253 . V_255 ) ;
V_2 -> V_134 = (struct V_256 * ) V_221 -> V_257 ;
V_2 -> V_48 = V_2 -> V_134 -> V_141 &
V_258 ? 20 : 5 ;
V_192 = - V_17 ;
V_229 = V_162 -> V_259 ;
if ( ! F_93 ( V_2 , V_229 ) ) {
goto V_260;
}
F_15 ( V_2 -> V_6 , V_2 -> V_30 ,
F_104 ( V_2 -> V_30 ,
V_2 -> V_247 -> V_32 ) ,
V_2 -> V_184 , sizeof( V_2 -> V_184 ) ,
F_71 , V_2 ,
V_2 -> V_247 -> V_33 ) ;
V_192 = F_22 ( V_2 -> V_6 , V_37 ) ;
if ( V_192 ) {
F_9 ( L_72 , V_192 ) ;
goto V_261;
}
V_2 -> V_146 = F_83 ( V_2 ) ;
if ( ! V_2 -> V_146 ) {
F_77 ( V_4 , L_73 , V_8 ) ;
goto V_262;
}
V_2 -> V_126 = F_75 ( V_2 ) ;
if ( ! V_2 -> V_126 ) {
F_77 ( V_4 , L_74 , V_8 ) ;
goto V_263;
}
V_2 -> V_51 = true ;
F_11 ( & V_2 -> V_18 ) ;
return V_2 ;
V_263:
F_105 ( V_2 -> V_146 ) ;
V_262:
F_25 ( V_2 -> V_6 ) ;
V_261:
V_260:
F_106 ( V_2 -> V_30 ) ;
F_11 ( & V_2 -> V_18 ) ;
F_2 ( V_5 ) ;
V_252:
F_2 ( V_250 ) ;
V_251:
F_3 ( V_2 ) ;
exit:
F_77 ( V_4 , L_75 , V_192 ) ;
return NULL ;
}
static struct V_1 * F_107 ( struct V_11 * V_162 ,
struct V_1 * V_2 )
{
struct V_82 * V_250 ;
struct V_228 * V_229 ;
int V_192 = - V_38 ;
V_250 = F_97 ( 0 , V_37 ) ;
if ( ! V_250 )
goto V_251;
F_6 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_62 == V_85 ) {
F_108 ( & V_2 -> V_153 ) ;
V_2 -> V_153 . V_84 = ( unsigned long ) V_2 ;
V_2 -> V_153 . V_264 = F_41 ;
}
V_2 -> V_224 = F_100 ( F_101 ( V_162 ) ) ;
V_2 -> V_7 = V_250 ;
V_192 = - V_17 ;
V_229 = V_162 -> V_259 ;
if ( ! F_93 ( V_2 , V_229 ) )
goto V_260;
if ( V_2 -> V_62 == V_85 ) {
V_2 -> V_86 = F_91 ( V_2 ) ;
if ( ! V_2 -> V_86 )
goto V_265;
} else
V_2 -> V_86 = NULL ;
F_15 ( V_2 -> V_7 , V_2 -> V_224 ,
F_104 ( V_2 -> V_224 ,
V_2 -> V_248 -> V_32 ) ,
V_2 -> V_184 , sizeof( V_2 -> V_184 ) ,
F_72 , V_2 ,
V_2 -> V_248 -> V_33 ) ;
V_192 = F_22 ( V_2 -> V_7 , V_37 ) ;
if ( V_192 ) {
F_9 ( L_76 , V_192 ) ;
goto V_261;
}
V_2 -> V_182 = true ;
F_11 ( & V_2 -> V_18 ) ;
return V_2 ;
V_261:
if ( V_2 -> V_86 )
F_105 ( V_2 -> V_86 ) ;
V_265:
V_260:
F_106 ( V_2 -> V_224 ) ;
F_11 ( & V_2 -> V_18 ) ;
F_2 ( V_250 ) ;
V_251:
F_77 ( V_2 -> V_4 , L_77 , V_192 ) ;
return NULL ;
}
static void F_109 ( struct V_1 * V_2 ,
struct V_11 * V_162 )
{
int V_192 ;
F_4 ( V_2 -> V_4 , L_78 ) ;
V_192 = F_110 ( & V_162 -> V_4 . V_266 , & V_267 ) ;
if ( V_192 )
F_77 ( V_2 -> V_4 , L_79 ,
V_192 ) ;
if ( V_2 -> V_62 == V_63 )
V_192 = F_111 ( V_162 , & V_268 ) ;
else
V_192 = F_111 ( V_162 , & V_269 ) ;
if ( V_192 )
F_33 ( V_2 -> V_4 , L_80 ) ;
}
static int F_112 ( struct V_11 * V_12 ,
const struct V_249 * V_221 )
{
struct V_270 * V_271 = NULL ;
struct V_228 * V_229 = NULL ;
struct V_11 * V_272 ;
struct V_3 * V_4 = & V_12 -> V_4 ;
int V_233 , V_273 ;
int V_192 = 0 ;
struct V_1 * V_2 = NULL ;
struct V_1 * V_274 = NULL ;
T_6 V_195 , V_64 ;
V_271 = F_100 ( F_101 ( V_12 ) ) ;
V_229 = V_12 -> V_259 ;
V_233 = V_229 -> V_234 . V_235 ;
V_195 = F_103 ( V_271 -> V_253 . V_254 ) ;
V_64 = F_103 ( V_271 -> V_253 . V_255 ) ;
F_4 ( V_4 , L_81 ,
V_8 , V_195 , V_64 , V_233 ) ;
F_6 ( & V_15 ) ;
V_272 = F_113 ( V_271 , 0 ) ;
V_274 = F_10 ( V_272 ) ;
if ( V_233 == 0 ) {
V_2 = F_95 ( V_12 , V_221 ) ;
if ( ! V_2 ) {
F_9 ( L_82 ) ;
V_192 = - V_17 ;
goto V_275;
}
} else {
if ( ! V_274 ) {
V_192 = - V_17 ;
goto V_275;
}
V_2 = F_107 ( V_12 , V_274 ) ;
if ( ! V_2 ) {
F_9 ( L_83 ) ;
V_192 = - V_17 ;
goto V_275;
}
}
F_114 ( V_12 , V_2 ) ;
if ( V_233 == 0 ) {
F_6 ( & V_2 -> V_18 ) ;
if ( V_64 == 0xffdc && V_2 -> V_188 ) {
V_273 = F_110 ( & V_12 -> V_4 . V_266 ,
& V_276 ) ;
if ( V_273 )
F_9 ( L_84 ,
V_273 ) ;
}
if ( V_2 -> V_19 )
F_109 ( V_2 , V_12 ) ;
F_11 ( & V_2 -> V_18 ) ;
}
F_33 ( V_4 , L_85 ,
V_195 , V_64 , V_233 ,
V_271 -> V_277 -> V_278 , V_271 -> V_279 ) ;
F_11 ( & V_15 ) ;
F_106 ( V_271 ) ;
return 0 ;
V_275:
F_11 ( & V_15 ) ;
F_106 ( V_271 ) ;
F_77 ( V_4 , L_86 , V_192 ) ;
return V_192 ;
}
static void F_115 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_233 ;
F_6 ( & V_15 ) ;
V_2 = F_10 ( V_12 ) ;
V_4 = V_2 -> V_4 ;
V_233 = V_12 -> V_259 -> V_234 . V_235 ;
F_116 ( & V_12 -> V_4 . V_266 , & V_267 ) ;
F_116 ( & V_12 -> V_4 . V_266 , & V_276 ) ;
F_114 ( V_12 , NULL ) ;
if ( V_2 -> V_44 . V_46 ) {
F_25 ( V_2 -> V_5 ) ;
F_40 ( & V_2 -> V_44 . V_45 ) ;
}
if ( V_233 == 0 ) {
V_2 -> V_51 = false ;
F_25 ( V_2 -> V_6 ) ;
F_106 ( V_2 -> V_30 ) ;
F_105 ( V_2 -> V_146 ) ;
F_117 ( V_2 -> V_126 ) ;
if ( V_2 -> V_19 ) {
if ( V_2 -> V_62 == V_63 )
F_118 ( V_12 , & V_268 ) ;
else if ( V_2 -> V_62 == V_65 )
F_118 ( V_12 , & V_269 ) ;
}
} else {
V_2 -> V_182 = false ;
F_25 ( V_2 -> V_7 ) ;
F_106 ( V_2 -> V_224 ) ;
if ( V_2 -> V_62 == V_85 ) {
F_105 ( V_2 -> V_86 ) ;
F_119 ( & V_2 -> V_153 ) ;
}
}
if ( ! V_2 -> V_51 && ! V_2 -> V_182 )
F_1 ( V_2 ) ;
F_11 ( & V_15 ) ;
F_4 ( V_4 , L_87 ,
V_8 , V_233 ) ;
}
static int F_120 ( struct V_11 * V_162 , T_9 V_280 )
{
struct V_1 * V_2 = F_10 ( V_162 ) ;
int V_233 = V_162 -> V_259 -> V_234 . V_235 ;
if ( V_233 == 0 )
F_25 ( V_2 -> V_6 ) ;
else
F_25 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_121 ( struct V_11 * V_162 )
{
int V_93 = 0 ;
struct V_1 * V_2 = F_10 ( V_162 ) ;
int V_233 = V_162 -> V_259 -> V_234 . V_235 ;
if ( V_233 == 0 ) {
F_15 ( V_2 -> V_6 , V_2 -> V_30 ,
F_104 ( V_2 -> V_30 ,
V_2 -> V_247 -> V_32 ) ,
V_2 -> V_184 , sizeof( V_2 -> V_184 ) ,
F_71 , V_2 ,
V_2 -> V_247 -> V_33 ) ;
V_93 = F_22 ( V_2 -> V_6 , V_181 ) ;
} else {
F_15 ( V_2 -> V_7 , V_2 -> V_224 ,
F_104 ( V_2 -> V_224 ,
V_2 -> V_248 -> V_32 ) ,
V_2 -> V_184 , sizeof( V_2 -> V_184 ) ,
F_72 , V_2 ,
V_2 -> V_248 -> V_33 ) ;
V_93 = F_22 ( V_2 -> V_7 , V_181 ) ;
}
return V_93 ;
}
