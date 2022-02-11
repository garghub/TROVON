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
if ( V_14 )
F_23 ( L_11 ) ;
F_6 ( & V_2 -> V_18 ) ;
V_14 = V_2 -> V_44 . V_47 ;
if ( V_14 )
F_23 ( L_12 , V_14 ) ;
}
F_3 ( V_28 ) ;
V_25 = F_25 ( 5 ) ;
F_26 ( V_48 ) ;
F_27 ( V_25 ) ;
return V_14 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_14 ;
const unsigned char V_49 [ 8 ] = { 0x01 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x20 } ;
if ( ! V_2 ) {
F_9 ( L_7 ) ;
return - V_17 ;
}
if ( ! V_2 -> V_50 ) {
F_9 ( L_13 ) ;
return - V_17 ;
}
memcpy ( V_2 -> V_34 , V_49 , sizeof( V_49 ) ) ;
V_14 = F_13 ( V_2 ) ;
return V_14 ;
}
static int F_29 ( struct V_1 * V_2 ,
unsigned int V_51 , unsigned int V_52 ,
unsigned int V_53 , unsigned int V_54 ,
unsigned int V_55 , unsigned int V_56 ,
unsigned int V_57 )
{
unsigned char V_58 [ V_59 ] [ 8 ] ;
int V_14 = 0 ;
int V_60 ;
if ( ! V_2 ) {
F_9 ( L_7 ) ;
return - V_17 ;
}
switch ( V_2 -> V_61 ) {
case V_62 :
V_58 [ 0 ] [ 0 ] = 0x80 ;
V_58 [ 0 ] [ 1 ] = V_51 ;
V_58 [ 0 ] [ 2 ] = V_52 - 1 ;
V_58 [ 0 ] [ 3 ] = V_53 ;
V_58 [ 0 ] [ 4 ] = V_55 ;
V_58 [ 0 ] [ 5 ] = V_56 ;
V_58 [ 0 ] [ 6 ] = V_57 ;
V_58 [ 1 ] [ 0 ] = 0x80 ;
V_58 [ 1 ] [ 1 ] = 0 ;
V_58 [ 1 ] [ 2 ] = 0 ;
V_58 [ 1 ] [ 3 ] = 0 ;
V_58 [ 1 ] [ 4 ] = 0 ;
V_58 [ 1 ] [ 5 ] = 0 ;
V_58 [ 1 ] [ 6 ] = 0 ;
if ( V_2 -> V_63 == 0xffdc ) {
V_58 [ 0 ] [ 7 ] = 0x50 ;
V_58 [ 1 ] [ 7 ] = 0x51 ;
} else {
V_58 [ 0 ] [ 7 ] = 0x88 ;
V_58 [ 1 ] [ 7 ] = 0x8a ;
}
break;
case V_64 :
V_58 [ 0 ] [ 0 ] = V_51 ;
V_58 [ 0 ] [ 1 ] = V_52 - 1 ;
V_58 [ 0 ] [ 2 ] = V_53 ;
V_58 [ 0 ] [ 3 ] = V_54 ;
V_58 [ 0 ] [ 4 ] = V_55 ;
V_58 [ 0 ] [ 5 ] = V_56 ;
V_58 [ 0 ] [ 6 ] = V_57 ;
V_58 [ 0 ] [ 7 ] = 0x40 ;
V_58 [ 1 ] [ 0 ] = 0 ;
V_58 [ 1 ] [ 1 ] = 0 ;
V_58 [ 1 ] [ 2 ] = 1 ;
V_58 [ 1 ] [ 3 ] = 0 ;
V_58 [ 1 ] [ 4 ] = 0 ;
V_58 [ 1 ] [ 5 ] = 0 ;
V_58 [ 1 ] [ 6 ] = 0 ;
V_58 [ 1 ] [ 7 ] = 0x42 ;
break;
default:
return - V_17 ;
}
for ( V_60 = 0 ; V_60 < V_59 ; V_60 ++ ) {
memcpy ( V_2 -> V_34 , V_58 [ V_60 ] , 8 ) ;
V_14 = F_13 ( V_2 ) ;
if ( V_14 ) {
F_9 ( L_14 , V_60 ) ;
break;
}
}
return V_14 ;
}
static T_1 F_30 ( struct V_3 * V_65 ,
struct V_66 * V_67 ,
char * V_68 )
{
struct V_1 * V_2 = F_31 ( V_65 ) ;
if ( ! V_2 )
return - V_17 ;
F_6 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_69 )
strcpy ( V_68 , L_15 ) ;
else
strcpy ( V_68 , L_16 ) ;
F_32 ( V_65 , L_17
L_18
L_19 ) ;
F_11 ( & V_2 -> V_18 ) ;
return strlen ( V_68 ) ;
}
static T_1 F_33 ( struct V_3 * V_65 ,
struct V_66 * V_67 ,
const char * V_68 , T_2 V_70 )
{
struct V_1 * V_2 ;
V_2 = F_31 ( V_65 ) ;
if ( ! V_2 )
return - V_17 ;
F_6 ( & V_2 -> V_18 ) ;
V_2 -> V_69 = true ;
F_28 ( V_2 ) ;
F_11 ( & V_2 -> V_18 ) ;
return V_70 ;
}
static T_1 F_34 ( struct V_3 * V_65 ,
struct V_66 * V_67 , char * V_68 )
{
struct V_1 * V_2 = F_31 ( V_65 ) ;
T_2 V_71 ;
if ( ! V_2 )
return - V_17 ;
F_6 ( & V_2 -> V_18 ) ;
if ( ! V_2 -> V_19 ) {
V_71 = snprintf ( V_68 , V_72 , L_20 ) ;
} else {
V_71 = snprintf ( V_68 , V_72 ,
L_21
L_22
L_23 , V_2 -> V_20 ?
L_24 : L_25 ) ;
}
F_11 ( & V_2 -> V_18 ) ;
return V_71 ;
}
static T_1 F_35 ( struct V_3 * V_65 ,
struct V_66 * V_67 ,
const char * V_68 , T_2 V_70 )
{
struct V_1 * V_2 = F_31 ( V_65 ) ;
T_1 V_14 ;
unsigned int V_51 , V_52 , V_53 , V_54 , V_55 , V_56 , V_57 ;
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
if ( sscanf ( V_68 , L_26 , & V_51 , & V_52 , & V_53 , & V_54 ,
& V_55 , & V_56 , & V_57 ) != 7 ) {
V_14 = - V_73 ;
goto exit;
}
if ( ( V_52 < 1 || V_52 > 12 ) ||
( V_53 < 1 || V_53 > 31 ) || ( V_54 > 6 ) ||
( V_55 > 23 ) || ( V_56 > 59 ) || ( V_57 > 59 ) ) {
V_14 = - V_73 ;
goto exit;
}
V_14 = F_29 ( V_2 , V_51 , V_52 , V_53 , V_54 ,
V_55 , V_56 , V_57 ) ;
if ( V_14 )
goto exit;
V_14 = V_70 ;
exit:
F_11 ( & V_2 -> V_18 ) ;
return V_14 ;
}
static T_1 F_36 ( struct V_10 * V_10 , const char * V_68 ,
T_2 V_74 , T_3 * V_75 )
{
int V_60 ;
int V_76 ;
int V_77 ;
int V_14 = 0 ;
struct V_1 * V_2 ;
const unsigned char V_78 [] = {
0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0xFF , 0xFF } ;
V_2 = V_10 -> V_22 ;
if ( ! V_2 ) {
F_23 ( L_7 ) ;
return - V_17 ;
}
F_6 ( & V_2 -> V_18 ) ;
if ( ! V_2 -> V_50 ) {
F_23 ( L_13 ) ;
V_14 = - V_17 ;
goto exit;
}
if ( V_74 <= 0 || V_74 > 32 ) {
F_23 ( L_27 ) ;
V_14 = - V_73 ;
goto exit;
}
if ( F_37 ( V_2 -> V_44 . V_79 , V_68 , V_74 ) ) {
V_14 = - V_80 ;
goto exit;
}
for ( V_60 = V_74 ; V_60 < 32 ; ++ V_60 )
V_2 -> V_44 . V_79 [ V_60 ] = ' ' ;
for ( V_60 = 32 ; V_60 < 35 ; ++ V_60 )
V_2 -> V_44 . V_79 [ V_60 ] = 0xFF ;
V_76 = 0 ;
V_77 = 0 ;
do {
memcpy ( V_2 -> V_34 , V_2 -> V_44 . V_79 + V_76 , 7 ) ;
V_2 -> V_34 [ 7 ] = ( unsigned char ) V_77 ;
V_14 = F_13 ( V_2 ) ;
if ( V_14 ) {
F_23 ( L_28 , V_77 / 2 ) ;
goto exit;
} else {
V_77 += 2 ;
V_76 += 7 ;
}
} while ( V_76 < 35 );
memcpy ( V_2 -> V_34 , & V_78 , sizeof( V_78 ) ) ;
V_2 -> V_34 [ 7 ] = ( unsigned char ) V_77 ;
V_14 = F_13 ( V_2 ) ;
if ( V_14 )
F_23 ( L_28 , V_77 / 2 ) ;
exit:
F_11 ( & V_2 -> V_18 ) ;
return ( ! V_14 ) ? V_74 : V_14 ;
}
static T_1 F_38 ( struct V_10 * V_10 , const char * V_68 ,
T_2 V_74 , T_3 * V_75 )
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
F_23 ( L_29 ) ;
V_14 = - V_17 ;
goto exit;
}
if ( V_74 != 8 ) {
F_23 ( L_30 ,
( int ) V_74 ) ;
V_14 = - V_73 ;
goto exit;
}
if ( F_37 ( V_2 -> V_34 , V_68 , 8 ) ) {
V_14 = - V_80 ;
goto exit;
}
V_14 = F_13 ( V_2 ) ;
if ( V_14 ) {
F_23 ( L_31 ) ;
goto exit;
} else {
F_4 ( V_2 -> V_4 , L_32 ,
V_8 , ( int ) V_74 ) ;
}
exit:
F_11 ( & V_2 -> V_18 ) ;
return ( ! V_14 ) ? V_74 : V_14 ;
}
static void V_35 ( struct V_81 * V_81 )
{
struct V_1 * V_2 ;
if ( ! V_81 )
return;
V_2 = (struct V_1 * ) V_81 -> V_82 ;
if ( ! V_2 )
return;
V_2 -> V_44 . V_47 = V_81 -> V_47 ;
V_2 -> V_44 . V_46 = false ;
F_21 () ;
F_39 ( & V_2 -> V_44 . V_45 ) ;
}
static void F_40 ( unsigned long V_83 )
{
struct V_1 * V_2 = (struct V_1 * ) V_83 ;
if ( V_2 -> V_61 != V_84 )
return;
F_41 ( V_2 -> V_85 , V_86 , V_2 -> V_87 ) ;
F_41 ( V_2 -> V_85 , V_88 , V_2 -> V_89 ) ;
F_42 ( V_2 -> V_85 , V_90 , 0x00 ) ;
F_43 ( V_2 -> V_85 ) ;
}
static int F_44 ( struct V_91 * V_92 , T_4 * V_93 )
{
int V_14 ;
struct V_1 * V_2 = V_92 -> V_94 ;
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_95 = false ;
unsigned char V_96 [] = {
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x86 } ;
if ( * V_93 && ! ( * V_93 & V_92 -> V_97 ) )
F_45 ( V_4 , L_33
L_34 ) ;
if ( * V_93 & V_98 ) {
F_4 ( V_4 , L_35 ) ;
V_96 [ 0 ] = 0x01 ;
* V_93 = V_98 ;
} else if ( * V_93 & V_99 ) {
F_4 ( V_4 , L_36 ) ;
if ( ! V_100 )
F_4 ( V_4 , L_37 ) ;
* V_93 = V_99 ;
} else {
F_45 ( V_4 , L_38
L_39 ) ;
if ( ! V_100 )
F_4 ( V_4 , L_37 ) ;
* V_93 = V_99 ;
}
memcpy ( V_2 -> V_34 , & V_96 , sizeof( V_96 ) ) ;
if ( ! F_46 ( & V_2 -> V_18 ) ) {
V_95 = true ;
F_6 ( & V_2 -> V_18 ) ;
}
V_14 = F_13 ( V_2 ) ;
if ( V_14 )
goto V_101;
V_2 -> V_93 = * V_93 ;
V_2 -> V_102 = false ;
V_101:
if ( V_95 )
F_11 ( & V_2 -> V_18 ) ;
return V_14 ;
}
static inline int F_47 ( const struct V_103 * V_104 , const struct V_103 * V_105 )
{
int V_106 = 0 ;
int V_107 = 0 ;
if ( V_105 -> V_108 > V_104 -> V_108 ) {
V_106 = 1000000 ;
V_107 -- ;
}
V_106 += V_104 -> V_108 - V_105 -> V_108 ;
V_107 += V_104 -> V_109 - V_105 -> V_109 ;
V_107 *= 1000 ;
V_106 /= 1000 ;
V_107 += V_106 ;
if ( V_107 < 0 )
V_107 = 1000 ;
return V_107 ;
}
static int F_48 ( int V_104 , int V_105 , T_5 V_25 , T_5 V_110 )
{
struct V_103 V_111 ;
static struct V_103 V_112 = { 0 , 0 } ;
static struct V_103 V_113 = { 0 , 0 } ;
static int V_114 , V_115 , V_116 , V_117 ;
int V_118 = 0 ;
int V_119 , V_120 ;
F_49 ( & V_111 ) ;
V_119 = F_47 ( & V_111 , & V_112 ) ;
V_120 = F_47 ( & V_111 , & V_113 ) ;
if ( V_119 > 100 ) {
V_114 = 0 ;
V_115 = 0 ;
V_117 = 0 ;
}
V_114 += V_104 ;
V_115 += V_105 ;
V_112 = V_111 ;
if ( abs ( V_114 ) > V_110 || abs ( V_115 ) > V_110 ) {
if ( abs ( V_115 ) > abs ( V_114 ) )
V_118 = ( V_115 > 0 ) ? 0x7F : 0x80 ;
else
V_118 = ( V_114 > 0 ) ? 0x7F00 : 0x8000 ;
V_114 = 0 ;
V_115 = 0 ;
if ( V_118 == V_116 ) {
V_117 ++ ;
if ( V_117 > 3 ) {
switch ( V_118 ) {
case 0x7F :
V_115 = 17 * V_110 / 30 ;
break;
case 0x80 :
V_115 -= 17 * V_110 / 30 ;
break;
case 0x7F00 :
V_114 = 17 * V_110 / 30 ;
break;
case 0x8000 :
V_114 -= 17 * V_110 / 30 ;
break;
}
}
if ( V_117 == 2 && V_120 < V_25 ) {
V_118 = 0 ;
V_117 = 1 ;
}
} else {
V_116 = V_118 ;
V_117 = 1 ;
V_113 = V_111 ;
}
}
return V_118 ;
}
static T_6 F_50 ( struct V_1 * V_2 , T_6 V_121 )
{
T_6 V_122 ;
T_6 V_123 ;
bool V_124 = false ;
V_122 = F_51 ( V_2 -> V_125 , V_121 ) ;
V_2 -> V_126 = 0x0 ;
V_2 -> V_127 = V_121 ;
if ( V_122 == V_128 ) {
V_123 = V_121 & ~ 0x4000 ;
V_122 = F_51 ( V_2 -> V_125 , V_123 ) ;
if ( V_122 != V_128 )
V_124 = true ;
}
V_2 -> V_129 = V_124 ;
return V_122 ;
}
static T_6 F_52 ( struct V_1 * V_2 , T_6 V_121 )
{
T_6 V_122 ;
#define F_53 0x7000
#define F_54 0x8000
if ( V_121 & 0x80000000 )
V_121 = V_121 | F_53 | F_54 ;
V_2 -> V_127 = V_121 ;
V_122 = F_51 ( V_2 -> V_125 , V_121 ) ;
V_2 -> V_129 = false ;
return V_122 ;
}
static T_6 F_55 ( T_4 V_130 )
{
int V_60 ;
T_6 V_122 = V_128 ;
for ( V_60 = 0 ; V_60 < F_56 ( V_131 ) ; V_60 ++ ) {
if ( V_131 [ V_60 ] . V_132 == ( V_130 | 0xffee ) ) {
V_122 = V_131 [ V_60 ] . V_122 ;
break;
}
}
return V_122 ;
}
static bool F_57 ( struct V_1 * V_2 ,
unsigned char * V_68 , int V_71 )
{
signed char V_133 = 0x00 , V_134 = 0x00 ;
T_7 V_135 = 1 ;
bool V_136 = true ;
int V_137 = 0 ;
unsigned long V_138 ;
F_58 ( & V_2 -> V_139 , V_138 ) ;
if ( V_2 -> V_63 != 0xffdc && ( V_68 [ 0 ] & 0x01 ) && V_71 == 5 ) {
V_133 = V_68 [ 2 ] ;
V_134 = V_68 [ 3 ] ;
V_135 = 1 ;
} else if ( V_2 -> V_63 == 0xffdc && ( V_68 [ 0 ] & 0x40 ) &&
! ( ( V_68 [ 1 ] & 0x01 ) || ( ( V_68 [ 1 ] >> 2 ) & 0x01 ) ) ) {
V_133 = ( V_68 [ 1 ] & 0x08 ) | ( V_68 [ 1 ] & 0x10 ) >> 2 |
( V_68 [ 1 ] & 0x20 ) >> 4 | ( V_68 [ 1 ] & 0x40 ) >> 6 ;
if ( V_68 [ 0 ] & 0x02 )
V_133 |= ~ 0x0f ;
V_133 = V_133 + V_133 / 2 ;
V_134 = ( V_68 [ 2 ] & 0x08 ) | ( V_68 [ 2 ] & 0x10 ) >> 2 |
( V_68 [ 2 ] & 0x20 ) >> 4 | ( V_68 [ 2 ] & 0x40 ) >> 6 ;
if ( V_68 [ 0 ] & 0x01 )
V_134 |= ~ 0x0f ;
V_134 = V_134 + V_134 / 2 ;
V_135 = 2 ;
} else if ( V_2 -> V_63 == 0xffdc && ( V_68 [ 0 ] == 0x68 ) ) {
V_135 = 2 ;
} else if ( V_2 -> V_140 == V_141 && ( V_68 [ 2 ] & 0x40 ) != 0x40 ) {
V_137 = 1 ;
} else if ( V_2 -> V_140 == V_142 && ( V_68 [ 2 ] & 0x40 ) != 0x40 ) {
V_137 = - 1 ;
} else
V_136 = false ;
F_59 ( & V_2 -> V_139 , V_138 ) ;
if ( V_136 ) {
F_4 ( V_2 -> V_4 , L_40 ) ;
if ( V_137 ) {
F_60 ( V_2 -> V_143 , V_144 , V_137 ) ;
} else if ( V_133 || V_134 ) {
F_60 ( V_2 -> V_143 , V_145 , V_133 ) ;
F_60 ( V_2 -> V_143 , V_146 , V_134 ) ;
} else {
F_42 ( V_2 -> V_143 , V_147 , V_68 [ 1 ] & 0x1 ) ;
F_42 ( V_2 -> V_143 , V_148 ,
V_68 [ 1 ] >> V_135 & 0x1 ) ;
}
F_43 ( V_2 -> V_143 ) ;
F_58 ( & V_2 -> V_139 , V_138 ) ;
V_2 -> V_149 = V_2 -> V_140 ;
F_59 ( & V_2 -> V_139 , V_138 ) ;
}
return V_136 ;
}
static void F_61 ( struct V_1 * V_2 , unsigned char * V_68 )
{
F_62 ( & V_2 -> V_150 , V_151 + V_152 ) ;
V_2 -> V_87 = ( V_68 [ 0 ] << 4 ) | ( V_68 [ 1 ] >> 4 ) ;
V_2 -> V_89 = 0xfff - ( ( V_68 [ 2 ] << 4 ) | ( V_68 [ 1 ] & 0xf ) ) ;
F_41 ( V_2 -> V_85 , V_86 , V_2 -> V_87 ) ;
F_41 ( V_2 -> V_85 , V_88 , V_2 -> V_89 ) ;
F_42 ( V_2 -> V_85 , V_90 , 0x01 ) ;
F_43 ( V_2 -> V_85 ) ;
}
static void F_63 ( struct V_1 * V_2 , unsigned char * V_68 )
{
int V_137 = 0 ;
signed char V_133 = 0x00 , V_134 = 0x00 ;
T_5 V_25 , V_110 ;
T_6 V_121 = V_128 ;
unsigned long V_138 ;
if ( V_2 -> V_63 != 0xffdc ) {
V_68 [ 5 ] = V_68 [ 6 ] = V_68 [ 7 ] = 0 ;
V_25 = 500 ;
V_110 = V_153 ? V_153 : 28 ;
V_133 = V_68 [ 2 ] ;
V_134 = V_68 [ 3 ] ;
if ( V_2 -> V_93 == V_99 && V_100 ) {
if ( ( V_68 [ 1 ] == 0 ) && ( ( V_133 != 0 ) || ( V_134 != 0 ) ) ) {
V_137 = F_48 ( ( int ) V_133 , ( int ) V_134 ,
V_25 , V_110 ) ;
if ( ! V_137 ) {
F_58 ( & V_2 -> V_139 ,
V_138 ) ;
V_2 -> V_140 = V_154 ;
F_59 ( & V_2 -> V_139 ,
V_138 ) ;
return;
}
V_68 [ 2 ] = V_137 & 0xFF ;
V_68 [ 3 ] = ( V_137 >> 8 ) & 0xFF ;
V_121 = F_64 ( * ( ( T_6 * ) V_68 ) ) ;
}
} else {
if ( abs ( V_134 ) > abs ( V_133 ) ) {
V_68 [ 2 ] = ( V_134 > 0 ) ? 0x7F : 0x80 ;
V_68 [ 3 ] = 0 ;
if ( V_134 > 0 )
V_121 = 0x01007f00 ;
else
V_121 = 0x01008000 ;
} else {
V_68 [ 2 ] = 0 ;
V_68 [ 3 ] = ( V_133 > 0 ) ? 0x7F : 0x80 ;
if ( V_133 > 0 )
V_121 = 0x0100007f ;
else
V_121 = 0x01000080 ;
}
}
} else {
V_25 = 10 ;
V_110 = V_153 ? V_153 : 15 ;
V_133 = ( V_68 [ 1 ] & 0x08 ) | ( V_68 [ 1 ] & 0x10 ) >> 2 |
( V_68 [ 1 ] & 0x20 ) >> 4 | ( V_68 [ 1 ] & 0x40 ) >> 6 ;
if ( V_68 [ 0 ] & 0x02 )
V_133 |= ~ 0x10 + 1 ;
V_134 = ( V_68 [ 2 ] & 0x08 ) | ( V_68 [ 2 ] & 0x10 ) >> 2 |
( V_68 [ 2 ] & 0x20 ) >> 4 | ( V_68 [ 2 ] & 0x40 ) >> 6 ;
if ( V_68 [ 0 ] & 0x01 )
V_134 |= ~ 0x10 + 1 ;
V_68 [ 0 ] = 0x01 ;
V_68 [ 1 ] = V_68 [ 4 ] = V_68 [ 5 ] = V_68 [ 6 ] = V_68 [ 7 ] = 0 ;
if ( V_2 -> V_93 == V_99 && V_100 ) {
V_137 = F_48 ( ( int ) V_133 , ( int ) V_134 ,
V_25 , V_110 ) ;
if ( ! V_137 ) {
F_58 ( & V_2 -> V_139 , V_138 ) ;
V_2 -> V_140 = V_154 ;
F_59 ( & V_2 -> V_139 , V_138 ) ;
return;
}
V_68 [ 2 ] = V_137 & 0xFF ;
V_68 [ 3 ] = ( V_137 >> 8 ) & 0xFF ;
V_121 = F_64 ( * ( ( T_6 * ) V_68 ) ) ;
} else {
if ( abs ( V_134 ) > abs ( V_133 ) ) {
V_68 [ 2 ] = ( V_134 > 0 ) ? 0x7F : 0x80 ;
V_68 [ 3 ] = 0 ;
if ( V_134 > 0 )
V_121 = 0x01007f00 ;
else
V_121 = 0x01008000 ;
} else {
V_68 [ 2 ] = 0 ;
V_68 [ 3 ] = ( V_133 > 0 ) ? 0x7F : 0x80 ;
if ( V_133 > 0 )
V_121 = 0x0100007f ;
else
V_121 = 0x01000080 ;
}
}
}
if ( V_121 ) {
F_58 ( & V_2 -> V_139 , V_138 ) ;
V_2 -> V_140 = F_50 ( V_2 , V_121 ) ;
F_59 ( & V_2 -> V_139 , V_138 ) ;
}
}
static int F_65 ( struct V_1 * V_2 ,
unsigned char * V_68 , T_7 V_155 )
{
int V_156 = 0 ;
unsigned long V_138 ;
F_58 ( & V_2 -> V_139 , V_138 ) ;
if ( V_2 -> V_140 == V_128 && V_68 [ 0 ] == 0x02 && V_68 [ 3 ] == 0x00 )
V_2 -> V_140 = V_2 -> V_149 ;
else if ( V_2 -> V_140 == V_128 && V_68 [ 0 ] == 0x68 && V_68 [ 1 ] == 0x82 &&
V_68 [ 2 ] == 0x81 && V_68 [ 3 ] == 0xb7 )
V_2 -> V_140 = V_2 -> V_149 ;
else if ( V_2 -> V_140 == V_128 && V_68 [ 0 ] == 0x01 && V_68 [ 1 ] == 0x00 &&
V_68 [ 2 ] == 0x81 && V_68 [ 3 ] == 0xb7 )
V_2 -> V_140 = V_2 -> V_149 ;
else if ( V_155 == V_157 ) {
V_2 -> V_126 = V_68 [ 2 ] ;
V_156 = 1 ;
} else if ( V_2 -> V_140 == V_128 )
V_156 = - V_73 ;
else if ( V_2 -> V_129 )
V_156 = 0 ;
else
V_156 = 1 ;
F_59 ( & V_2 -> V_139 , V_138 ) ;
return V_156 ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_81 * V_81 , int V_158 )
{
int V_71 = V_81 -> V_36 ;
unsigned char * V_68 = V_81 -> V_159 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_138 ;
T_6 V_140 ;
int V_60 ;
T_4 V_121 ;
int V_156 = 0 ;
int V_119 ;
struct V_103 V_160 ;
static struct V_103 V_112 = { 0 , 0 } ;
T_7 V_155 ;
if ( ( V_68 [ 0 ] == 0xff ) && ( V_68 [ 1 ] == 0xff ) && ( V_68 [ 2 ] == 0xff ) )
return;
if ( V_71 == 8 && V_68 [ 7 ] == 0xee ) {
V_121 = F_67 ( * ( ( T_4 * ) V_68 ) ) ;
V_155 = V_161 ;
V_140 = F_55 ( V_121 ) ;
} else {
V_121 = F_64 ( * ( ( T_6 * ) V_68 ) ) ;
if ( V_2 -> V_93 == V_98 ) {
V_155 = V_162 ;
if ( V_68 [ 0 ] == 0x80 )
V_155 = V_157 ;
V_140 = F_52 ( V_2 , V_121 ) ;
} else {
V_155 = V_162 ;
V_140 = F_50 ( V_2 , V_121 ) ;
}
}
F_58 ( & V_2 -> V_139 , V_138 ) ;
if ( V_140 == V_163 && ! V_2 -> V_129 ) {
V_2 -> V_149 = V_140 ;
if ( ! V_164 ) {
V_2 -> V_102 = ~ ( V_2 -> V_102 ) & 0x1 ;
F_4 ( V_4 , L_41 ,
V_2 -> V_102 ? L_42 : L_43 ) ;
F_59 ( & V_2 -> V_139 , V_138 ) ;
return;
} else {
V_2 -> V_102 = false ;
F_4 ( V_4 , L_44 ) ;
}
}
V_2 -> V_140 = V_140 ;
F_59 ( & V_2 -> V_139 , V_138 ) ;
if ( V_2 -> V_61 == V_84 && V_71 == 8 &&
V_68 [ 7 ] == 0x86 ) {
F_61 ( V_2 , V_68 ) ;
return;
} else if ( V_2 -> V_102 ) {
if ( F_57 ( V_2 , V_68 , V_71 ) )
return;
}
if ( ( ( V_71 == 5 ) && ( V_68 [ 0 ] == 0x01 ) && ( V_68 [ 4 ] == 0x00 ) ) ||
( ( V_71 == 8 ) && ( V_68 [ 0 ] & 0x40 ) &&
! ( V_68 [ 1 ] & 0x1 || V_68 [ 1 ] >> 2 & 0x1 ) ) ) {
V_71 = 8 ;
F_63 ( V_2 , V_68 ) ;
}
if ( V_165 ) {
F_68 ( V_166 L_45 , V_158 ) ;
for ( V_60 = 0 ; V_60 < V_71 ; ++ V_60 )
F_68 ( L_46 , V_68 [ V_60 ] ) ;
F_68 ( L_47 ) ;
}
V_156 = F_65 ( V_2 , V_68 , V_155 ) ;
if ( V_156 < 0 )
goto V_167;
F_58 ( & V_2 -> V_139 , V_138 ) ;
if ( V_2 -> V_140 == V_154 )
goto V_168;
F_59 ( & V_2 -> V_139 , V_138 ) ;
if ( V_155 != V_161 ) {
if ( V_156 == 0 )
F_69 ( V_2 -> V_125 ) ;
else {
F_70 ( V_2 -> V_125 , V_2 -> V_127 , V_2 -> V_126 ) ;
F_58 ( & V_2 -> V_139 , V_138 ) ;
V_2 -> V_149 = V_2 -> V_140 ;
F_59 ( & V_2 -> V_139 , V_138 ) ;
}
return;
}
F_58 ( & V_2 -> V_139 , V_138 ) ;
F_49 ( & V_160 ) ;
if ( V_2 -> V_140 == V_169 && V_2 -> V_140 == V_2 -> V_149 ) {
V_119 = F_47 ( & V_160 , & V_112 ) ;
if ( V_119 < V_2 -> V_143 -> V_170 [ V_171 ] ) {
F_59 ( & V_2 -> V_139 , V_138 ) ;
return;
}
}
V_112 = V_160 ;
V_140 = V_2 -> V_140 ;
F_59 ( & V_2 -> V_139 , V_138 ) ;
F_42 ( V_2 -> V_143 , V_140 , V_156 ) ;
F_43 ( V_2 -> V_143 ) ;
F_42 ( V_2 -> V_143 , V_140 , 0 ) ;
F_43 ( V_2 -> V_143 ) ;
F_58 ( & V_2 -> V_139 , V_138 ) ;
V_2 -> V_149 = V_140 ;
F_59 ( & V_2 -> V_139 , V_138 ) ;
return;
V_168:
F_59 ( & V_2 -> V_139 , V_138 ) ;
F_32 ( V_4 , L_48 , V_8 ,
( long long ) V_121 ) ;
return;
V_167:
if ( V_71 != 8 ) {
F_45 ( V_4 , L_49
L_50 , V_8 , V_71 , V_158 ) ;
return;
}
if ( V_68 [ 0 ] == 0x00 &&
V_68 [ 2 ] == 0xFF &&
V_68 [ 3 ] == 0xFF &&
V_68 [ 4 ] == 0xFF &&
V_68 [ 5 ] == 0xFF &&
( ( V_68 [ 6 ] == 0x4E && V_68 [ 7 ] == 0xDF ) ||
( V_68 [ 6 ] == 0x5E && V_68 [ 7 ] == 0xDF ) ) ) {
F_45 ( V_4 , L_51 ,
V_8 , V_68 [ 1 ] ) ;
V_2 -> V_69 = false ;
}
}
static void F_71 ( struct V_81 * V_81 )
{
struct V_1 * V_2 ;
int V_172 = 0 ;
if ( ! V_81 )
return;
V_2 = (struct V_1 * ) V_81 -> V_82 ;
if ( ! V_2 )
return;
if ( ! V_2 -> V_50 )
goto V_101;
switch ( V_81 -> V_47 ) {
case - V_173 :
return;
case - V_174 :
break;
case 0 :
F_66 ( V_2 , V_81 , V_172 ) ;
break;
default:
F_45 ( V_2 -> V_4 , L_52 ,
V_8 , V_81 -> V_47 ) ;
break;
}
V_101:
F_22 ( V_2 -> V_6 , V_175 ) ;
}
static void F_72 ( struct V_81 * V_81 )
{
struct V_1 * V_2 ;
int V_172 = 1 ;
if ( ! V_81 )
return;
V_2 = (struct V_1 * ) V_81 -> V_82 ;
if ( ! V_2 )
return;
if ( ! V_2 -> V_176 )
goto V_101;
switch ( V_81 -> V_47 ) {
case - V_173 :
return;
case - V_174 :
break;
case 0 :
F_66 ( V_2 , V_81 , V_172 ) ;
break;
default:
F_45 ( V_2 -> V_4 , L_52 ,
V_8 , V_81 -> V_47 ) ;
break;
}
V_101:
F_22 ( V_2 -> V_7 , V_175 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
T_7 V_177 = V_2 -> V_178 [ 6 ] ;
T_7 V_179 = V_180 ;
T_4 V_97 = V_99 ;
switch ( V_177 ) {
case 0x21 :
F_32 ( V_2 -> V_4 , L_53 ) ;
V_2 -> V_19 = false ;
break;
case 0x4e :
F_32 ( V_2 -> V_4 , L_54 ) ;
V_2 -> V_19 = false ;
V_2 -> V_181 = true ;
break;
case 0x35 :
F_32 ( V_2 -> V_4 , L_55 ) ;
V_179 = V_64 ;
break;
case 0x24 :
case 0x85 :
F_32 ( V_2 -> V_4 , L_56 ) ;
V_179 = V_64 ;
break;
case 0x46 :
case 0x7e :
case 0x9e :
F_32 ( V_2 -> V_4 , L_57 ) ;
V_179 = V_64 ;
V_97 = V_98 ;
break;
case 0x9f :
F_32 ( V_2 -> V_4 , L_58 ) ;
V_179 = V_62 ;
V_97 = V_98 ;
break;
default:
F_32 ( V_2 -> V_4 , L_59
L_60 ) ;
V_179 = V_64 ;
V_97 |= V_98 ;
break;
}
F_68 ( V_182 L_61 , V_177 ) ;
V_2 -> V_61 = V_179 ;
V_2 -> V_93 = V_97 ;
}
static void F_74 ( struct V_1 * V_2 )
{
T_7 V_183 = V_64 ;
if ( V_61 == V_184 ) {
switch ( V_2 -> V_63 ) {
case 0xffdc :
V_183 = V_2 -> V_61 ;
break;
case 0x0034 :
case 0x0035 :
V_183 = V_84 ;
break;
case 0x0038 :
case 0x0039 :
case 0x0045 :
V_183 = V_62 ;
break;
case 0x003c :
case 0x0041 :
case 0x0042 :
case 0x0043 :
V_183 = V_180 ;
V_2 -> V_19 = false ;
break;
case 0x0036 :
case 0x0044 :
default:
V_183 = V_64 ;
break;
}
} else {
V_183 = V_61 ;
if ( V_61 == V_180 )
V_2 -> V_19 = false ;
else
V_2 -> V_19 = true ;
F_32 ( V_2 -> V_4 , L_62
L_63 , V_8 , V_61 ) ;
}
V_2 -> V_61 = V_183 ;
}
static struct V_91 * F_75 ( struct V_1 * V_2 )
{
struct V_91 * V_125 ;
int V_185 ;
const unsigned char V_186 [] = { 0x40 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x88 } ;
V_125 = F_76 () ;
if ( ! V_125 ) {
F_77 ( V_2 -> V_4 , L_64 ) ;
goto V_101;
}
snprintf ( V_2 -> V_187 , sizeof( V_2 -> V_187 ) ,
L_65 , V_2 -> V_188 , V_2 -> V_63 ) ;
F_78 ( V_2 -> V_30 , V_2 -> V_189 ,
sizeof( V_2 -> V_189 ) ) ;
F_79 ( V_2 -> V_189 , L_66 , sizeof( V_2 -> V_189 ) ) ;
V_125 -> V_190 = V_2 -> V_187 ;
V_125 -> V_191 = V_2 -> V_189 ;
F_80 ( V_2 -> V_30 , & V_125 -> V_192 ) ;
V_125 -> V_4 . V_193 = V_2 -> V_4 ;
V_125 -> V_94 = V_2 ;
V_125 -> V_194 = V_195 ;
V_125 -> V_97 = V_99 | V_98 ;
V_125 -> V_196 = F_44 ;
V_125 -> V_197 = V_198 ;
memcpy ( V_2 -> V_34 , & V_186 , sizeof( V_186 ) ) ;
V_185 = F_13 ( V_2 ) ;
if ( V_185 )
F_32 ( V_2 -> V_4 , L_67 ) ;
if ( V_2 -> V_63 == 0xffdc ) {
F_73 ( V_2 ) ;
V_125 -> V_97 = V_2 -> V_93 ;
}
F_74 ( V_2 ) ;
if ( V_2 -> V_93 == V_98 )
V_125 -> V_199 = V_200 ;
else
V_125 -> V_199 = V_201 ;
V_185 = F_81 ( V_125 ) ;
if ( V_185 < 0 ) {
F_77 ( V_2 -> V_4 , L_68 ) ;
goto V_101;
}
return V_125 ;
V_101:
F_82 ( V_125 ) ;
return NULL ;
}
static struct V_202 * F_83 ( struct V_1 * V_2 )
{
struct V_202 * V_143 ;
int V_185 , V_60 ;
V_143 = F_84 () ;
if ( ! V_143 ) {
F_77 ( V_2 -> V_4 , L_69 ) ;
goto V_101;
}
snprintf ( V_2 -> V_203 , sizeof( V_2 -> V_203 ) ,
L_70 ,
V_2 -> V_188 , V_2 -> V_63 ) ;
V_143 -> V_204 = V_2 -> V_203 ;
F_78 ( V_2 -> V_30 , V_2 -> V_205 ,
sizeof( V_2 -> V_205 ) ) ;
F_79 ( V_2 -> V_205 , L_71 , sizeof( V_2 -> V_205 ) ) ;
V_143 -> V_206 = V_2 -> V_205 ;
V_143 -> V_207 [ 0 ] = F_85 ( V_208 ) | F_85 ( V_209 ) | F_85 ( V_210 ) ;
V_143 -> V_211 [ F_86 ( V_212 ) ] =
F_85 ( V_147 ) | F_85 ( V_148 ) ;
V_143 -> V_213 [ 0 ] = F_85 ( V_145 ) | F_85 ( V_146 ) |
F_85 ( V_144 ) ;
for ( V_60 = 0 ; V_60 < F_56 ( V_131 ) ; V_60 ++ ) {
T_6 V_140 = V_131 [ V_60 ] . V_122 ;
F_87 ( V_140 , V_143 -> V_211 ) ;
}
F_80 ( V_2 -> V_30 , & V_143 -> V_214 ) ;
V_143 -> V_4 . V_193 = V_2 -> V_4 ;
F_88 ( V_143 , V_2 ) ;
V_185 = F_89 ( V_143 ) ;
if ( V_185 < 0 ) {
F_77 ( V_2 -> V_4 , L_72 ) ;
goto V_101;
}
return V_143 ;
V_101:
F_90 ( V_143 ) ;
return NULL ;
}
static struct V_202 * F_91 ( struct V_1 * V_2 )
{
struct V_202 * V_85 ;
int V_185 ;
V_85 = F_84 () ;
if ( ! V_85 ) {
F_77 ( V_2 -> V_4 , L_73 ) ;
goto V_215;
}
snprintf ( V_2 -> V_216 , sizeof( V_2 -> V_216 ) ,
L_74 ,
V_2 -> V_188 , V_2 -> V_63 ) ;
V_85 -> V_204 = V_2 -> V_216 ;
F_78 ( V_2 -> V_217 , V_2 -> V_218 ,
sizeof( V_2 -> V_218 ) ) ;
F_79 ( V_2 -> V_218 , L_75 , sizeof( V_2 -> V_218 ) ) ;
V_85 -> V_206 = V_2 -> V_218 ;
V_85 -> V_207 [ 0 ] =
F_85 ( V_208 ) | F_85 ( V_219 ) ;
V_85 -> V_211 [ F_86 ( V_90 ) ] =
F_85 ( V_90 ) ;
F_92 ( V_85 , V_86 ,
0x00 , 0xfff , 0 , 0 ) ;
F_92 ( V_85 , V_88 ,
0x00 , 0xfff , 0 , 0 ) ;
F_88 ( V_85 , V_2 ) ;
F_80 ( V_2 -> V_217 , & V_85 -> V_214 ) ;
V_85 -> V_4 . V_193 = V_2 -> V_4 ;
V_185 = F_89 ( V_85 ) ;
if ( V_185 < 0 ) {
F_32 ( V_2 -> V_4 , L_76 ) ;
goto V_220;
}
return V_85 ;
V_220:
F_90 ( V_85 ) ;
V_215:
return NULL ;
}
static bool F_93 ( struct V_1 * V_2 ,
struct V_221 * V_222 )
{
struct V_223 * V_224 ;
struct V_223 * V_225 = NULL ;
struct V_223 * V_31 = NULL ;
int V_226 = V_222 -> V_227 . V_228 ;
int V_229 = V_222 -> V_227 . V_230 ;
int V_60 , V_231 , V_232 ;
bool V_233 = false ;
bool V_234 = false ;
bool V_29 = false ;
for ( V_60 = 0 ; V_60 < V_229 && ! ( V_233 && V_234 ) ; ++ V_60 ) {
V_224 = & V_222 -> V_235 [ V_60 ] . V_227 ;
V_231 = V_224 -> V_32 & V_236 ;
V_232 = V_224 -> V_237 & V_238 ;
if ( ! V_233 && V_231 == V_239 &&
V_232 == V_240 ) {
V_225 = V_224 ;
V_233 = true ;
F_4 ( V_2 -> V_4 , L_77 , V_8 ) ;
} else if ( ! V_234 && V_231 == V_241 &&
V_232 == V_240 ) {
V_31 = V_224 ;
V_234 = true ;
F_4 ( V_2 -> V_4 , L_78 , V_8 ) ;
}
}
if ( V_226 == 0 ) {
V_2 -> V_242 = V_225 ;
V_2 -> V_31 = V_31 ;
} else {
V_2 -> V_243 = V_225 ;
}
if ( ! V_234 ) {
V_29 = true ;
V_234 = true ;
F_4 ( V_2 -> V_4 , L_79
L_80 , V_8 ) ;
}
if ( V_2 -> V_61 == V_180 ) {
V_234 = false ;
F_4 ( V_2 -> V_4 , L_81 , V_8 ) ;
}
if ( V_2 -> V_61 == V_84 ) {
V_234 = false ;
F_4 ( V_2 -> V_4 , L_82 , V_8 ) ;
}
if ( ! V_233 )
F_9 ( L_83 ) ;
V_2 -> V_29 = V_29 ;
if ( V_234 )
V_2 -> V_19 = true ;
return V_233 ;
}
static struct V_1 * F_94 ( struct V_11 * V_158 )
{
struct V_1 * V_2 ;
struct V_81 * V_244 ;
struct V_81 * V_5 ;
struct V_3 * V_4 = & V_158 -> V_4 ;
struct V_221 * V_222 ;
int V_185 = - V_38 ;
V_2 = F_95 ( sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_2 ) {
F_77 ( V_4 , L_84 , V_8 ) ;
goto exit;
}
V_244 = F_96 ( 0 , V_37 ) ;
if ( ! V_244 ) {
F_77 ( V_4 , L_85 , V_8 ) ;
goto V_245;
}
V_5 = F_96 ( 0 , V_37 ) ;
if ( ! V_5 ) {
F_77 ( V_4 , L_86 ,
V_8 ) ;
goto V_246;
}
F_97 ( & V_2 -> V_18 ) ;
F_98 ( & V_2 -> V_139 ) ;
F_6 ( & V_2 -> V_18 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_30 = F_99 ( F_100 ( V_158 ) ) ;
V_2 -> V_6 = V_244 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_181 = false ;
V_2 -> V_188 = F_101 ( V_2 -> V_30 -> V_247 . V_248 ) ;
V_2 -> V_63 = F_101 ( V_2 -> V_30 -> V_247 . V_249 ) ;
V_185 = - V_17 ;
V_222 = V_158 -> V_250 ;
if ( ! F_93 ( V_2 , V_222 ) ) {
goto V_251;
}
F_15 ( V_2 -> V_6 , V_2 -> V_30 ,
F_102 ( V_2 -> V_30 ,
V_2 -> V_242 -> V_32 ) ,
V_2 -> V_178 , sizeof( V_2 -> V_178 ) ,
F_71 , V_2 ,
V_2 -> V_242 -> V_33 ) ;
V_185 = F_22 ( V_2 -> V_6 , V_37 ) ;
if ( V_185 ) {
F_9 ( L_87 , V_185 ) ;
goto V_252;
}
V_2 -> V_143 = F_83 ( V_2 ) ;
if ( ! V_2 -> V_143 ) {
F_77 ( V_4 , L_88 , V_8 ) ;
goto V_253;
}
V_2 -> V_125 = F_75 ( V_2 ) ;
if ( ! V_2 -> V_125 ) {
F_77 ( V_4 , L_89 , V_8 ) ;
goto V_254;
}
V_2 -> V_50 = true ;
F_11 ( & V_2 -> V_18 ) ;
return V_2 ;
V_254:
F_103 ( V_2 -> V_143 ) ;
V_253:
F_104 ( V_2 -> V_6 ) ;
V_252:
V_251:
F_11 ( & V_2 -> V_18 ) ;
F_2 ( V_5 ) ;
V_246:
F_2 ( V_244 ) ;
V_245:
F_3 ( V_2 ) ;
exit:
F_77 ( V_4 , L_90 , V_185 ) ;
return NULL ;
}
static struct V_1 * F_105 ( struct V_11 * V_158 ,
struct V_1 * V_2 )
{
struct V_81 * V_244 ;
struct V_221 * V_222 ;
int V_185 = - V_38 ;
V_244 = F_96 ( 0 , V_37 ) ;
if ( ! V_244 ) {
F_9 ( L_91 ) ;
goto V_245;
}
F_6 ( & V_2 -> V_18 ) ;
if ( V_2 -> V_61 == V_84 ) {
F_106 ( & V_2 -> V_150 ) ;
V_2 -> V_150 . V_83 = ( unsigned long ) V_2 ;
V_2 -> V_150 . V_255 = F_40 ;
}
V_2 -> V_217 = F_99 ( F_100 ( V_158 ) ) ;
V_2 -> V_7 = V_244 ;
V_185 = - V_17 ;
V_222 = V_158 -> V_250 ;
if ( ! F_93 ( V_2 , V_222 ) )
goto V_251;
if ( V_2 -> V_61 == V_84 ) {
V_2 -> V_85 = F_91 ( V_2 ) ;
if ( ! V_2 -> V_85 )
goto V_256;
} else
V_2 -> V_85 = NULL ;
F_15 ( V_2 -> V_7 , V_2 -> V_217 ,
F_102 ( V_2 -> V_217 ,
V_2 -> V_243 -> V_32 ) ,
V_2 -> V_178 , sizeof( V_2 -> V_178 ) ,
F_72 , V_2 ,
V_2 -> V_243 -> V_33 ) ;
V_185 = F_22 ( V_2 -> V_7 , V_37 ) ;
if ( V_185 ) {
F_9 ( L_92 , V_185 ) ;
goto V_252;
}
V_2 -> V_176 = true ;
F_11 ( & V_2 -> V_18 ) ;
return V_2 ;
V_252:
if ( V_2 -> V_85 )
F_103 ( V_2 -> V_85 ) ;
V_256:
V_251:
F_11 ( & V_2 -> V_18 ) ;
F_2 ( V_244 ) ;
V_245:
F_77 ( V_2 -> V_4 , L_93 , V_185 ) ;
return NULL ;
}
static void F_107 ( struct V_1 * V_2 ,
struct V_11 * V_158 )
{
int V_185 ;
F_4 ( V_2 -> V_4 , L_94 ) ;
V_185 = F_108 ( & V_158 -> V_4 . V_257 , & V_258 ) ;
if ( V_185 )
F_77 ( V_2 -> V_4 , L_95
L_96 , V_185 ) ;
if ( V_2 -> V_61 == V_62 )
V_185 = F_109 ( V_158 , & V_259 ) ;
else
V_185 = F_109 ( V_158 , & V_260 ) ;
if ( V_185 )
F_32 ( V_2 -> V_4 , L_97
L_98 ) ;
}
static int F_110 ( struct V_11 * V_12 ,
const struct V_261 * V_214 )
{
struct V_262 * V_263 = NULL ;
struct V_221 * V_222 = NULL ;
struct V_11 * V_264 ;
struct V_3 * V_4 = & V_12 -> V_4 ;
int V_226 , V_265 ;
int V_185 = 0 ;
struct V_1 * V_2 = NULL ;
struct V_1 * V_266 = NULL ;
T_5 V_188 , V_63 ;
V_263 = F_99 ( F_100 ( V_12 ) ) ;
V_222 = V_12 -> V_250 ;
V_226 = V_222 -> V_227 . V_228 ;
V_188 = F_101 ( V_263 -> V_247 . V_248 ) ;
V_63 = F_101 ( V_263 -> V_247 . V_249 ) ;
F_4 ( V_4 , L_99 ,
V_8 , V_188 , V_63 , V_226 ) ;
F_6 ( & V_15 ) ;
V_264 = F_111 ( V_263 , 0 ) ;
V_266 = F_10 ( V_264 ) ;
if ( V_226 == 0 ) {
V_2 = F_94 ( V_12 ) ;
if ( ! V_2 ) {
F_9 ( L_100 ) ;
V_185 = - V_17 ;
goto V_267;
}
} else {
V_2 = F_105 ( V_12 , V_266 ) ;
if ( ! V_2 ) {
F_9 ( L_101 ) ;
V_185 = - V_17 ;
goto V_267;
}
}
F_112 ( V_12 , V_2 ) ;
if ( V_226 == 0 ) {
F_6 ( & V_2 -> V_18 ) ;
if ( V_63 == 0xffdc && V_2 -> V_181 ) {
V_265 = F_108 ( & V_12 -> V_4 . V_257 ,
& V_268 ) ;
if ( V_265 )
F_9 ( L_102 ,
V_265 ) ;
}
if ( V_2 -> V_19 )
F_107 ( V_2 , V_12 ) ;
F_11 ( & V_2 -> V_18 ) ;
}
F_32 ( V_4 , L_103
L_104 , V_188 , V_63 , V_226 ,
V_263 -> V_269 -> V_270 , V_263 -> V_271 ) ;
F_11 ( & V_15 ) ;
return 0 ;
V_267:
F_11 ( & V_15 ) ;
F_77 ( V_4 , L_105 , V_185 ) ;
return V_185 ;
}
static void F_113 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_226 ;
F_6 ( & V_15 ) ;
V_2 = F_10 ( V_12 ) ;
V_4 = V_2 -> V_4 ;
V_226 = V_12 -> V_250 -> V_227 . V_228 ;
F_114 ( & V_12 -> V_4 . V_257 , & V_258 ) ;
F_114 ( & V_12 -> V_4 . V_257 , & V_268 ) ;
F_112 ( V_12 , NULL ) ;
if ( V_2 -> V_44 . V_46 ) {
F_104 ( V_2 -> V_5 ) ;
F_115 ( & V_2 -> V_44 . V_45 ) ;
}
if ( V_226 == 0 ) {
V_2 -> V_50 = false ;
F_104 ( V_2 -> V_6 ) ;
F_103 ( V_2 -> V_143 ) ;
F_116 ( V_2 -> V_125 ) ;
if ( V_2 -> V_19 ) {
if ( V_2 -> V_61 == V_62 )
F_117 ( V_12 , & V_259 ) ;
else if ( V_2 -> V_61 == V_64 )
F_117 ( V_12 , & V_260 ) ;
}
} else {
V_2 -> V_176 = false ;
F_104 ( V_2 -> V_7 ) ;
if ( V_2 -> V_61 == V_84 ) {
F_103 ( V_2 -> V_85 ) ;
F_118 ( & V_2 -> V_150 ) ;
}
}
if ( ! V_2 -> V_50 && ! V_2 -> V_176 )
F_1 ( V_2 ) ;
F_11 ( & V_15 ) ;
F_4 ( V_4 , L_106 ,
V_8 , V_226 ) ;
}
static int F_119 ( struct V_11 * V_158 , T_8 V_272 )
{
struct V_1 * V_2 = F_10 ( V_158 ) ;
int V_226 = V_158 -> V_250 -> V_227 . V_228 ;
if ( V_226 == 0 )
F_104 ( V_2 -> V_6 ) ;
else
F_104 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_120 ( struct V_11 * V_158 )
{
int V_92 = 0 ;
struct V_1 * V_2 = F_10 ( V_158 ) ;
int V_226 = V_158 -> V_250 -> V_227 . V_228 ;
if ( V_226 == 0 ) {
F_15 ( V_2 -> V_6 , V_2 -> V_30 ,
F_102 ( V_2 -> V_30 ,
V_2 -> V_242 -> V_32 ) ,
V_2 -> V_178 , sizeof( V_2 -> V_178 ) ,
F_71 , V_2 ,
V_2 -> V_242 -> V_33 ) ;
V_92 = F_22 ( V_2 -> V_6 , V_175 ) ;
} else {
F_15 ( V_2 -> V_7 , V_2 -> V_217 ,
F_102 ( V_2 -> V_217 ,
V_2 -> V_243 -> V_32 ) ,
V_2 -> V_178 , sizeof( V_2 -> V_178 ) ,
F_72 , V_2 ,
V_2 -> V_243 -> V_33 ) ;
V_92 = F_22 ( V_2 -> V_7 , V_175 ) ;
}
return V_92 ;
}
