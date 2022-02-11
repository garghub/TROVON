static const struct V_1 *
F_1 ( struct V_2 * V_3 , int V_4 , int V_5 )
{
const struct V_1 * V_6 = V_3 -> V_7 ;
if ( ! V_6 )
return NULL ;
for ( V_6 = V_3 -> V_7 ; V_6 -> V_8 ; V_6 ++ ) {
if ( V_6 -> V_8 == V_4 &&
( ! V_5 || ! V_6 -> V_5 || V_5 == V_6 -> V_5 ) )
return V_6 ;
}
return NULL ;
}
static int
F_2 ( const struct V_1 * V_6 , char * V_9 , int V_10 )
{
if ( ! V_6 || ! V_6 -> V_11 )
return 0 ;
V_10 -- ;
return F_3 ( V_9 , V_6 -> V_11 , V_10 ) ;
}
static inline int
F_4 ( const struct V_1 * V_6 )
{
if ( ! V_6 || V_6 -> V_11 || V_6 -> V_12 )
return 0 ;
return 1 ;
}
static inline void F_5 ( const struct V_1 * V_6 ,
struct V_13 * V_14 )
{
if ( V_6 && V_6 -> V_12 ) {
V_14 -> V_15 = V_6 -> V_12 -> V_16 ;
V_14 -> V_17 = V_6 -> V_12 -> V_18 ;
V_14 -> V_19 = 1 ;
}
}
static int F_6 ( struct V_2 * V_3 , int V_4 ,
int V_20 , char * V_9 , int V_10 )
{
const struct V_21 * V_6 ;
if ( ! V_3 -> V_22 )
return 0 ;
for ( V_6 = V_3 -> V_22 ; V_6 -> V_8 ; V_6 ++ ) {
if ( V_6 -> V_8 == V_4 && V_20 < V_6 -> V_23 )
return F_3 ( V_9 , V_6 -> V_24 [ V_20 ] , V_10 ) ;
}
return 0 ;
}
static void * F_7 ( struct V_2 * V_3 , unsigned char V_25 )
{
struct V_26 * V_27 = NULL ;
while ( ( V_27 = F_8 ( V_3 -> V_28 , V_3 -> V_10 , V_27 ,
V_29 ) ) != NULL ) {
if ( V_27 -> V_30 >= 4 &&
V_27 -> V_31 >= V_32 &&
V_27 -> V_31 <= V_33 &&
V_27 -> V_34 == V_25 )
return V_27 ;
}
return NULL ;
}
static int F_9 ( struct V_2 * V_3 , int V_20 , char * V_9 , int V_35 )
{
int V_36 = F_10 ( V_3 -> V_37 -> V_38 , V_20 , V_9 , V_35 - 1 ) ;
V_9 [ V_36 ] = 0 ;
return V_36 ;
}
static int F_11 ( struct V_13 * V_14 , int V_39 )
{
switch ( V_14 -> V_40 ) {
case V_41 :
return ! ! V_39 ;
case V_42 :
return ! V_39 ;
case V_43 :
V_39 &= 0xff ;
break;
case V_44 :
V_39 &= 0xff ;
if ( V_39 >= 0x80 )
V_39 -= 0x100 ;
break;
case V_45 :
V_39 &= 0xffff ;
break;
case V_46 :
V_39 &= 0xffff ;
if ( V_39 >= 0x8000 )
V_39 -= 0x10000 ;
break;
}
return V_39 ;
}
static int F_12 ( struct V_13 * V_14 , int V_39 )
{
switch ( V_14 -> V_40 ) {
case V_41 :
return ! ! V_39 ;
case V_42 :
return ! V_39 ;
case V_44 :
case V_43 :
return V_39 & 0xff ;
case V_46 :
case V_45 :
return V_39 & 0xffff ;
}
return 0 ;
}
static int F_13 ( struct V_13 * V_14 , int V_39 )
{
if ( ! V_14 -> V_47 )
V_14 -> V_47 = 1 ;
if ( V_39 < V_14 -> V_16 )
return 0 ;
else if ( V_39 >= V_14 -> V_18 )
return ( V_14 -> V_18 - V_14 -> V_16 + V_14 -> V_47 - 1 ) / V_14 -> V_47 ;
else
return ( V_39 - V_14 -> V_16 ) / V_14 -> V_47 ;
}
static int F_14 ( struct V_13 * V_14 , int V_39 )
{
if ( V_39 < 0 )
return V_14 -> V_16 ;
if ( ! V_14 -> V_47 )
V_14 -> V_47 = 1 ;
V_39 *= V_14 -> V_47 ;
V_39 += V_14 -> V_16 ;
if ( V_39 > V_14 -> V_18 )
return V_14 -> V_18 ;
return V_39 ;
}
static int F_15 ( struct V_13 * V_14 , int V_48 , int V_49 , int * V_50 )
{
struct V_51 * V_37 = V_14 -> V_52 -> V_37 ;
unsigned char V_9 [ 2 ] ;
int V_53 = V_14 -> V_40 >= V_46 ? 2 : 1 ;
int V_54 = 10 ;
int V_55 ;
V_55 = F_16 ( V_14 -> V_52 -> V_37 ) ;
if ( V_55 < 0 )
return - V_56 ;
while ( V_54 -- > 0 ) {
if ( F_17 ( V_37 -> V_38 , F_18 ( V_37 -> V_38 , 0 ) , V_48 ,
V_57 | V_58 | V_59 ,
V_49 , F_19 ( V_37 ) | ( V_14 -> V_8 << 8 ) ,
V_9 , V_53 ) >= V_53 ) {
* V_50 = F_11 ( V_14 , F_20 ( V_9 , V_53 ) ) ;
F_21 ( V_14 -> V_52 -> V_37 ) ;
return 0 ;
}
}
F_21 ( V_14 -> V_52 -> V_37 ) ;
F_22 ( V_60 L_1 ,
V_48 , V_49 , F_19 ( V_37 ) | ( V_14 -> V_8 << 8 ) , V_14 -> V_40 ) ;
return - V_61 ;
}
static int F_23 ( struct V_13 * V_14 , int V_48 , int V_49 , int * V_50 )
{
struct V_51 * V_37 = V_14 -> V_52 -> V_37 ;
unsigned char V_9 [ 2 + 3 * sizeof( V_62 ) ] ;
unsigned char * V_39 ;
int V_63 , V_64 ;
T_1 V_65 ;
if ( V_48 == V_66 ) {
V_65 = V_67 ;
V_64 = sizeof( V_62 ) ;
} else {
V_65 = V_68 ;
V_64 = sizeof( V_9 ) ;
}
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
V_63 = F_16 ( V_37 ) ? - V_56 : 0 ;
if ( V_63 )
goto error;
V_63 = F_17 ( V_37 -> V_38 , F_18 ( V_37 -> V_38 , 0 ) , V_65 ,
V_57 | V_58 | V_59 ,
V_49 , F_19 ( V_37 ) | ( V_14 -> V_8 << 8 ) ,
V_9 , V_64 ) ;
F_21 ( V_37 ) ;
if ( V_63 < 0 ) {
error:
F_24 ( V_60 L_1 ,
V_48 , V_49 , F_19 ( V_37 ) | ( V_14 -> V_8 << 8 ) , V_14 -> V_40 ) ;
return V_63 ;
}
switch ( V_48 ) {
case V_66 :
V_39 = V_9 ;
break;
case V_69 :
V_39 = V_9 + sizeof( V_62 ) ;
break;
case V_70 :
V_39 = V_9 + sizeof( V_62 ) * 2 ;
break;
case V_71 :
V_39 = V_9 + sizeof( V_62 ) * 3 ;
break;
default:
return - V_61 ;
}
* V_50 = F_11 ( V_14 , F_20 ( V_39 , sizeof( V_62 ) ) ) ;
return 0 ;
}
static int F_25 ( struct V_13 * V_14 , int V_48 , int V_49 , int * V_50 )
{
return ( V_14 -> V_52 -> V_72 == V_73 ) ?
F_15 ( V_14 , V_48 , V_49 , V_50 ) :
F_23 ( V_14 , V_48 , V_49 , V_50 ) ;
}
static int F_26 ( struct V_13 * V_14 , int V_49 , int * V_74 )
{
return F_25 ( V_14 , V_66 , V_49 , V_74 ) ;
}
static inline int F_27 ( struct V_13 * V_14 ,
int V_75 , int * V_74 )
{
return F_25 ( V_14 , V_66 , ( V_14 -> V_5 << 8 ) | V_75 , V_74 ) ;
}
static int F_28 ( struct V_13 * V_14 ,
int V_75 , int V_20 , int * V_74 )
{
int V_55 ;
if ( V_14 -> V_76 & ( 1 << V_75 ) ) {
* V_74 = V_14 -> V_77 [ V_20 ] ;
return 0 ;
}
V_55 = F_27 ( V_14 , V_75 , V_74 ) ;
if ( V_55 < 0 ) {
if ( ! V_14 -> V_52 -> V_78 )
F_29 ( V_60 L_2 ,
V_14 -> V_5 , V_75 , V_55 ) ;
return V_55 ;
}
V_14 -> V_76 |= 1 << V_75 ;
V_14 -> V_77 [ V_20 ] = * V_74 ;
return 0 ;
}
int F_30 ( struct V_13 * V_14 ,
int V_48 , int V_49 , int V_79 )
{
struct V_51 * V_37 = V_14 -> V_52 -> V_37 ;
unsigned char V_9 [ 2 ] ;
int V_53 , V_55 , V_54 = 10 ;
if ( V_14 -> V_52 -> V_72 == V_73 ) {
V_53 = V_14 -> V_40 >= V_46 ? 2 : 1 ;
} else {
V_53 = sizeof( V_62 ) ;
if ( V_48 != V_80 ) {
F_22 ( V_81 L_3 ) ;
return - V_61 ;
}
V_48 = V_67 ;
}
V_79 = F_12 ( V_14 , V_79 ) ;
V_9 [ 0 ] = V_79 & 0xff ;
V_9 [ 1 ] = ( V_79 >> 8 ) & 0xff ;
V_55 = F_16 ( V_37 ) ;
if ( V_55 < 0 )
return - V_56 ;
while ( V_54 -- > 0 )
if ( F_17 ( V_37 -> V_38 ,
F_31 ( V_37 -> V_38 , 0 ) , V_48 ,
V_57 | V_58 | V_82 ,
V_49 , F_19 ( V_37 ) | ( V_14 -> V_8 << 8 ) ,
V_9 , V_53 ) >= 0 ) {
F_21 ( V_37 ) ;
return 0 ;
}
F_21 ( V_37 ) ;
F_22 ( V_60 L_4 ,
V_48 , V_49 , F_19 ( V_37 ) | ( V_14 -> V_8 << 8 ) , V_14 -> V_40 , V_9 [ 0 ] , V_9 [ 1 ] ) ;
return - V_61 ;
}
static int F_32 ( struct V_13 * V_14 , int V_49 , int V_74 )
{
return F_30 ( V_14 , V_80 , V_49 , V_74 ) ;
}
static int F_33 ( struct V_13 * V_14 , int V_75 ,
int V_20 , int V_74 )
{
int V_55 ;
unsigned int V_83 = ( V_75 == 0 ) ?
V_14 -> V_84 :
V_14 -> V_85 & ( 1 << ( V_75 - 1 ) ) ;
if ( V_83 ) {
F_22 ( V_86 L_5 ,
V_87 , V_75 , V_14 -> V_5 ) ;
return 0 ;
}
V_55 = F_30 ( V_14 , V_80 , ( V_14 -> V_5 << 8 ) | V_75 ,
V_74 ) ;
if ( V_55 < 0 )
return V_55 ;
V_14 -> V_76 |= 1 << V_75 ;
V_14 -> V_77 [ V_20 ] = V_74 ;
return 0 ;
}
int F_34 ( struct V_88 * V_89 , int V_90 ,
unsigned int V_64 , unsigned int T_2 * V_91 )
{
struct V_13 * V_14 = V_89 -> V_92 ;
F_35 ( V_93 , 0 , 0 ) ;
if ( V_64 < sizeof( V_93 ) )
return - V_94 ;
V_93 [ 2 ] = V_14 -> V_15 ;
V_93 [ 3 ] = V_14 -> V_17 ;
if ( F_36 ( V_91 , V_93 , sizeof( V_93 ) ) )
return - V_95 ;
return 0 ;
}
static int F_37 ( unsigned char * V_96 , int V_97 , int V_98 , int V_99 )
{
int V_100 = V_97 * V_99 + V_98 ;
return V_96 [ V_100 >> 3 ] & ( 0x80 >> ( V_100 & 7 ) ) ;
}
int F_38 ( struct V_101 * V_52 ,
struct V_88 * V_102 )
{
struct V_13 * V_14 = V_102 -> V_92 ;
int V_55 ;
while ( F_39 ( V_52 -> V_37 -> V_103 , & V_102 -> V_8 ) )
V_102 -> V_8 . V_20 ++ ;
if ( ( V_55 = F_40 ( V_52 -> V_37 -> V_103 , V_102 ) ) < 0 ) {
F_29 ( V_60 L_6 , V_55 ) ;
return V_55 ;
}
V_14 -> V_104 = & V_102 -> V_8 ;
V_14 -> V_105 = V_52 -> V_106 [ V_14 -> V_8 ] ;
V_52 -> V_106 [ V_14 -> V_8 ] = V_14 ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , struct V_107 * V_108 ,
unsigned char * V_11 , int V_35 , int V_109 )
{
struct V_110 * V_24 ;
if ( V_108 -> V_11 )
return F_9 ( V_3 , V_108 -> V_11 , V_11 , V_35 ) ;
if ( V_108 -> type >> 16 ) {
if ( V_109 )
return 0 ;
switch ( V_108 -> type >> 16 ) {
case V_111 :
strcpy ( V_11 , L_7 ) ; return 8 ;
case V_112 :
strcpy ( V_11 , L_8 ) ; return 12 ;
case V_113 :
strcpy ( V_11 , L_9 ) ; return 8 ;
case V_114 :
strcpy ( V_11 , L_10 ) ; return 5 ;
default:
return sprintf ( V_11 , L_11 , V_108 -> V_8 ) ;
}
}
switch ( V_108 -> type & 0xff00 ) {
case 0x0100 :
strcpy ( V_11 , L_12 ) ; return 3 ;
case 0x0200 :
strcpy ( V_11 , L_13 ) ; return 3 ;
case 0x0400 :
strcpy ( V_11 , L_14 ) ; return 7 ;
case 0x0500 :
strcpy ( V_11 , L_15 ) ; return 5 ;
}
for ( V_24 = V_115 ; V_24 -> type ; V_24 ++ )
if ( V_24 -> type == V_108 -> type ) {
strcpy ( V_11 , V_24 -> V_11 ) ;
return strlen ( V_24 -> V_11 ) ;
}
return 0 ;
}
static int F_42 ( struct V_2 * V_3 , int V_8 , struct V_107 * V_116 )
{
int V_55 ;
void * V_117 ;
memset ( V_116 , 0 , sizeof( * V_116 ) ) ;
while ( ( V_117 = F_7 ( V_3 , V_8 ) ) != NULL ) {
unsigned char * V_27 = V_117 ;
V_116 -> V_8 = V_8 ;
switch ( V_27 [ 2 ] ) {
case V_32 :
if ( V_3 -> V_52 -> V_72 == V_73 ) {
struct V_118 * V_119 = V_117 ;
V_116 -> type = F_43 ( V_119 -> V_120 ) ;
V_116 -> V_121 = V_119 -> V_122 ;
V_116 -> V_123 = F_43 ( V_119 -> V_124 ) ;
V_116 -> V_11 = V_119 -> V_125 ;
} else {
struct V_126 * V_119 = V_117 ;
V_116 -> type = F_43 ( V_119 -> V_120 ) ;
V_116 -> V_121 = V_119 -> V_122 ;
V_116 -> V_123 = F_44 ( V_119 -> V_127 ) ;
V_116 -> V_11 = V_119 -> V_125 ;
V_55 = F_42 ( V_3 , V_119 -> V_128 , V_116 ) ;
if ( V_55 < 0 )
return V_55 ;
}
return 0 ;
case V_129 : {
struct V_26 * V_119 = V_117 ;
V_8 = V_119 -> V_130 ;
break;
}
case V_114 : {
struct V_131 * V_119 = V_117 ;
V_116 -> type = V_119 -> V_31 << 16 ;
V_116 -> V_121 = F_45 ( V_119 ) ;
V_116 -> V_123 = F_46 ( V_119 , V_3 -> V_52 -> V_72 ) ;
V_116 -> V_11 = F_47 ( V_119 ) ;
return 0 ;
}
case V_111 :
case V_132 : {
struct V_133 * V_119 = V_117 ;
if ( F_42 ( V_3 , V_119 -> V_134 [ 0 ] , V_116 ) < 0 )
return - V_135 ;
V_116 -> type = V_119 -> V_31 << 16 ;
V_116 -> V_8 = V_8 ;
V_116 -> V_11 = F_48 ( V_119 ) ;
return 0 ;
}
case V_112 :
case V_113 : {
struct V_136 * V_119 = V_117 ;
if ( V_119 -> V_137 ) {
V_8 = V_119 -> V_134 [ 0 ] ;
break;
}
V_116 -> type = V_119 -> V_31 << 16 ;
V_116 -> V_121 = F_49 ( V_119 ) ;
V_116 -> V_123 = F_50 ( V_119 , V_3 -> V_52 -> V_72 ) ;
V_116 -> V_11 = F_51 ( V_119 , V_3 -> V_52 -> V_72 ) ;
return 0 ;
}
case V_138 : {
struct V_139 * V_119 = V_117 ;
V_116 -> type = V_119 -> V_31 << 16 ;
V_116 -> V_8 = V_8 ;
V_116 -> V_11 = V_119 -> V_140 ;
return 0 ;
}
default:
return - V_135 ;
}
}
return - V_135 ;
}
static void F_52 ( struct V_88 * V_102 )
{
F_53 ( V_102 -> V_92 ) ;
V_102 -> V_92 = NULL ;
}
static void F_54 ( struct V_13 * V_14 ,
struct V_88 * V_102 )
{
switch ( V_14 -> V_52 -> V_37 -> V_141 ) {
case F_55 ( 0x0763 , 0x2081 ) :
case F_55 ( 0x0763 , 0x2080 ) :
if ( strcmp ( V_102 -> V_8 . V_11 , L_16 ) == 0 ) {
F_24 ( V_86
L_17 ) ;
V_14 -> V_16 = 0x0000 ;
V_14 -> V_18 = 0x7f00 ;
V_14 -> V_47 = 0x0100 ;
break;
}
if ( strcmp ( V_102 -> V_8 . V_11 , L_18 ) == 0 ||
strcmp ( V_102 -> V_8 . V_11 , L_19 ) == 0 ) {
F_24 ( V_86
L_20 ) ;
V_14 -> V_16 = 0x00 ;
V_14 -> V_18 = 0x7f ;
break;
}
break;
case F_55 ( 0x0471 , 0x0101 ) :
case F_55 ( 0x0471 , 0x0104 ) :
case F_55 ( 0x0471 , 0x0105 ) :
case F_55 ( 0x0672 , 0x1041 ) :
if ( ! strcmp ( V_102 -> V_8 . V_11 , L_21 ) &&
V_14 -> V_16 == - 15616 ) {
F_24 ( V_86
L_22 ) ;
V_14 -> V_18 = - 256 ;
}
break;
case F_55 ( 0x046d , 0x09a4 ) :
if ( ! strcmp ( V_102 -> V_8 . V_11 , L_23 ) ) {
F_24 ( V_86
L_24 ) ;
V_14 -> V_16 = 6080 ;
V_14 -> V_18 = 8768 ;
V_14 -> V_47 = 192 ;
}
break;
case F_55 ( 0x046d , 0x0808 ) :
case F_55 ( 0x046d , 0x0809 ) :
case F_55 ( 0x046d , 0x081d ) :
case F_55 ( 0x046d , 0x0991 ) :
if ( ! strcmp ( V_102 -> V_8 . V_11 , L_23 ) ) {
F_24 ( V_86
L_25 ) ;
V_14 -> V_47 = 384 ;
}
break;
}
}
static int F_56 ( struct V_13 * V_14 ,
int V_142 , struct V_88 * V_102 )
{
V_14 -> V_16 = V_142 ;
V_14 -> V_18 = V_14 -> V_16 + 1 ;
V_14 -> V_47 = 1 ;
V_14 -> V_15 = V_14 -> V_17 = 0 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 ) {
V_14 -> V_19 = 1 ;
} else {
int V_143 = 0 ;
if ( V_14 -> V_144 ) {
int V_145 ;
for ( V_145 = 0 ; V_145 < V_146 ; V_145 ++ )
if ( V_14 -> V_144 & ( 1 << V_145 ) ) {
V_143 = V_145 + 1 ;
break;
}
}
if ( F_25 ( V_14 , V_70 , ( V_14 -> V_5 << 8 ) | V_143 , & V_14 -> V_18 ) < 0 ||
F_25 ( V_14 , V_69 , ( V_14 -> V_5 << 8 ) | V_143 , & V_14 -> V_16 ) < 0 ) {
F_29 ( V_60 L_26 ,
V_14 -> V_8 , F_19 ( V_14 -> V_52 -> V_37 ) , V_14 -> V_5 , V_14 -> V_8 ) ;
return - V_61 ;
}
if ( F_25 ( V_14 , V_71 , ( V_14 -> V_5 << 8 ) | V_143 , & V_14 -> V_47 ) < 0 ) {
V_14 -> V_47 = 1 ;
} else {
int V_147 = V_14 -> V_47 ;
while ( V_14 -> V_47 > 1 ) {
if ( F_30 ( V_14 , V_148 ,
( V_14 -> V_5 << 8 ) | V_143 , V_14 -> V_47 / 2 ) < 0 )
break;
V_14 -> V_47 /= 2 ;
}
if ( F_25 ( V_14 , V_71 , ( V_14 -> V_5 << 8 ) | V_143 , & V_14 -> V_47 ) < 0 )
V_14 -> V_47 = V_147 ;
}
if ( V_14 -> V_47 == 0 )
V_14 -> V_47 = 1 ;
if ( V_14 -> V_16 + V_14 -> V_47 < V_14 -> V_18 ) {
int V_147 = V_14 -> V_47 ;
int V_149 , V_150 , V_151 ;
F_27 ( V_14 , V_143 , & V_149 ) ;
for (; ; ) {
V_150 = V_149 ;
if ( V_150 < V_14 -> V_18 )
V_150 += V_14 -> V_47 ;
else
V_150 -= V_14 -> V_47 ;
if ( V_150 < V_14 -> V_16 || V_150 > V_14 -> V_18 ||
F_33 ( V_14 , V_143 , 0 , V_150 ) ||
F_27 ( V_14 , V_143 , & V_151 ) ) {
V_14 -> V_47 = V_147 ;
break;
}
if ( V_150 == V_151 )
break;
V_14 -> V_47 *= 2 ;
}
F_33 ( V_14 , V_143 , 0 , V_149 ) ;
}
V_14 -> V_19 = 1 ;
}
if ( V_102 )
F_54 ( V_14 , V_102 ) ;
V_14 -> V_15 = ( F_11 ( V_14 , V_14 -> V_16 ) * 100 ) / 256 ;
V_14 -> V_17 = ( F_11 ( V_14 , V_14 -> V_18 ) * 100 ) / 256 ;
if ( V_14 -> V_15 > V_14 -> V_17 ) {
if ( V_14 -> V_15 < 0 )
V_14 -> V_17 = 0 ;
else if ( V_14 -> V_15 > 0 )
V_14 -> V_15 = 0 ;
if ( V_14 -> V_15 > V_14 -> V_17 ) {
return - V_61 ;
}
}
return 0 ;
}
static int F_57 ( struct V_88 * V_89 , struct V_152 * V_153 )
{
struct V_13 * V_14 = V_89 -> V_92 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 )
V_153 -> type = V_154 ;
else
V_153 -> type = V_155 ;
V_153 -> V_23 = V_14 -> V_121 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 ) {
V_153 -> V_74 . integer . V_16 = 0 ;
V_153 -> V_74 . integer . V_18 = 1 ;
} else {
if ( ! V_14 -> V_19 ) {
F_56 ( V_14 , 0 , V_89 ) ;
if ( V_14 -> V_19 && V_14 -> V_15 >= V_14 -> V_17 ) {
V_89 -> V_156 [ 0 ] . V_157 &=
~ ( V_158 |
V_159 ) ;
F_58 ( V_14 -> V_52 -> V_37 -> V_103 ,
V_160 ,
& V_89 -> V_8 ) ;
}
}
V_153 -> V_74 . integer . V_16 = 0 ;
V_153 -> V_74 . integer . V_18 =
( V_14 -> V_18 - V_14 -> V_16 + V_14 -> V_47 - 1 ) / V_14 -> V_47 ;
}
return 0 ;
}
static int F_59 ( struct V_88 * V_89 , struct V_161 * V_162 )
{
struct V_13 * V_14 = V_89 -> V_92 ;
int V_163 , V_164 , V_39 , V_55 ;
V_162 -> V_74 . integer . V_74 [ 0 ] = V_14 -> V_16 ;
if ( V_14 -> V_144 ) {
V_164 = 0 ;
for ( V_163 = 0 ; V_163 < V_146 ; V_163 ++ ) {
if ( ! ( V_14 -> V_144 & ( 1 << V_163 ) ) )
continue;
V_55 = F_28 ( V_14 , V_163 + 1 , V_164 , & V_39 ) ;
if ( V_55 < 0 )
return V_14 -> V_52 -> V_78 ? 0 : V_55 ;
V_39 = F_13 ( V_14 , V_39 ) ;
V_162 -> V_74 . integer . V_74 [ V_164 ] = V_39 ;
V_164 ++ ;
}
return 0 ;
} else {
V_55 = F_28 ( V_14 , 0 , 0 , & V_39 ) ;
if ( V_55 < 0 )
return V_14 -> V_52 -> V_78 ? 0 : V_55 ;
V_39 = F_13 ( V_14 , V_39 ) ;
V_162 -> V_74 . integer . V_74 [ 0 ] = V_39 ;
}
return 0 ;
}
static int F_60 ( struct V_88 * V_89 , struct V_161 * V_162 )
{
struct V_13 * V_14 = V_89 -> V_92 ;
int V_163 , V_164 , V_39 , V_165 , V_55 ;
int V_166 = 0 ;
if ( V_14 -> V_144 ) {
V_164 = 0 ;
for ( V_163 = 0 ; V_163 < V_146 ; V_163 ++ ) {
if ( ! ( V_14 -> V_144 & ( 1 << V_163 ) ) )
continue;
V_55 = F_28 ( V_14 , V_163 + 1 , V_164 , & V_165 ) ;
if ( V_55 < 0 )
return V_14 -> V_52 -> V_78 ? 0 : V_55 ;
V_39 = V_162 -> V_74 . integer . V_74 [ V_164 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_165 != V_39 ) {
F_33 ( V_14 , V_163 + 1 , V_164 , V_39 ) ;
V_166 = 1 ;
}
V_164 ++ ;
}
} else {
V_55 = F_28 ( V_14 , 0 , 0 , & V_165 ) ;
if ( V_55 < 0 )
return V_14 -> V_52 -> V_78 ? 0 : V_55 ;
V_39 = V_162 -> V_74 . integer . V_74 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_165 ) {
F_33 ( V_14 , 0 , 0 , V_39 ) ;
V_166 = 1 ;
}
}
return V_166 ;
}
static T_3 F_61 ( struct V_88 * V_102 , const char * V_167 )
{
return F_62 ( V_102 -> V_8 . V_11 , V_167 , sizeof( V_102 -> V_8 . V_11 ) ) ;
}
static void F_63 ( struct V_2 * V_3 , void * V_168 ,
unsigned int V_169 , int V_5 ,
struct V_107 * V_108 , int V_4 ,
int V_170 )
{
struct V_26 * V_171 = V_168 ;
unsigned int V_36 = 0 ;
int V_172 = 0 ;
int V_173 = F_64 ( V_171 ) ;
struct V_88 * V_102 ;
struct V_13 * V_14 ;
const struct V_1 * V_7 ;
unsigned int V_174 ;
V_5 ++ ;
if ( V_5 == V_175 ) {
return;
}
V_7 = F_1 ( V_3 , V_4 , V_5 ) ;
if ( F_4 ( V_7 ) )
return;
V_14 = F_65 ( sizeof( * V_14 ) , V_176 ) ;
if ( ! V_14 ) {
F_24 ( V_60 L_27 ) ;
return;
}
V_14 -> V_52 = V_3 -> V_52 ;
V_14 -> V_8 = V_4 ;
V_14 -> V_5 = V_5 ;
V_14 -> V_144 = V_169 ;
V_14 -> V_40 = V_177 [ V_5 - 1 ] . type ;
if ( V_169 == 0 ) {
V_14 -> V_121 = 1 ;
V_14 -> V_84 = V_170 ;
} else {
int V_145 , V_163 = 0 ;
for ( V_145 = 0 ; V_145 < 16 ; V_145 ++ )
if ( V_169 & ( 1 << V_145 ) )
V_163 ++ ;
V_14 -> V_121 = V_163 ;
V_14 -> V_85 = V_170 ;
}
if ( V_14 -> V_121 == V_170 )
V_102 = F_66 ( & V_178 , V_14 ) ;
else
V_102 = F_66 ( & V_179 , V_14 ) ;
if ( ! V_102 ) {
F_24 ( V_60 L_27 ) ;
F_53 ( V_14 ) ;
return;
}
V_102 -> V_180 = F_52 ;
V_36 = F_2 ( V_7 , V_102 -> V_8 . V_11 , sizeof( V_102 -> V_8 . V_11 ) ) ;
V_172 = V_36 != 0 ;
if ( ! V_36 && V_173 )
V_36 = F_9 ( V_3 , V_173 ,
V_102 -> V_8 . V_11 , sizeof( V_102 -> V_8 . V_11 ) ) ;
switch ( V_5 ) {
case V_181 :
case V_182 :
if ( ! V_36 ) {
V_36 = F_41 ( V_3 , V_108 , V_102 -> V_8 . V_11 , sizeof( V_102 -> V_8 . V_11 ) , 1 ) ;
if ( ! V_36 )
V_36 = F_41 ( V_3 , & V_3 -> V_183 , V_102 -> V_8 . V_11 , sizeof( V_102 -> V_8 . V_11 ) , 1 ) ;
if ( ! V_36 )
V_36 = snprintf ( V_102 -> V_8 . V_11 , sizeof( V_102 -> V_8 . V_11 ) ,
L_28 , V_4 ) ;
}
if ( ! V_172 && ! ( V_3 -> V_183 . type >> 16 ) ) {
if ( ( V_3 -> V_183 . type & 0xff00 ) == 0x0100 ) {
V_36 = F_61 ( V_102 , L_29 ) ;
} else {
V_36 = F_61 ( V_102 , L_30 ) ;
}
}
F_61 ( V_102 , V_5 == V_181 ?
L_31 : L_32 ) ;
break;
default:
if ( ! V_36 )
F_3 ( V_102 -> V_8 . V_11 , V_177 [ V_5 - 1 ] . V_11 ,
sizeof( V_102 -> V_8 . V_11 ) ) ;
break;
}
F_56 ( V_14 , 0 , V_102 ) ;
if ( V_5 == V_182 ) {
F_5 ( V_7 , V_14 ) ;
if ( V_14 -> V_15 < V_14 -> V_17 || ! V_14 -> V_19 ) {
V_102 -> V_184 . V_163 = F_34 ;
V_102 -> V_156 [ 0 ] . V_157 |=
V_158 |
V_159 ;
}
}
V_174 = ( V_14 -> V_18 - V_14 -> V_16 ) / V_14 -> V_47 ;
if ( V_174 > 384 ) {
F_24 ( V_81 L_33
L_34 ,
V_174 ) ;
F_24 ( V_81 L_35
L_36 , V_14 -> V_8 ,
V_102 -> V_8 . V_11 , V_14 -> V_121 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_47 ) ;
}
F_22 ( V_86 L_37 ,
V_14 -> V_8 , V_102 -> V_8 . V_11 , V_14 -> V_121 , V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_47 ) ;
F_38 ( V_3 -> V_52 , V_102 ) ;
}
static int F_67 ( struct V_2 * V_3 , int V_4 , void * V_185 )
{
int V_121 , V_145 , V_186 ;
struct V_107 V_108 ;
unsigned int V_187 , V_188 ;
int V_55 , V_189 ;
struct V_26 * V_27 = V_185 ;
T_1 * V_190 ;
if ( V_3 -> V_52 -> V_72 == V_73 ) {
V_189 = V_27 -> V_191 ;
if ( ! V_189 ) {
F_22 ( V_60 L_38
L_39 , V_4 ) ;
return - V_61 ;
}
V_121 = ( V_27 -> V_30 - 7 ) / V_189 - 1 ;
V_190 = V_27 -> V_190 ;
} else {
struct V_192 * V_193 = V_185 ;
V_189 = 4 ;
V_121 = ( V_27 -> V_30 - 6 ) / 4 - 1 ;
V_190 = V_193 -> V_190 ;
}
if ( V_27 -> V_30 < 7 || ! V_189 || V_27 -> V_30 < 7 + V_189 ) {
F_24 ( V_60 L_40 , V_4 ) ;
return - V_61 ;
}
if ( ( V_55 = F_68 ( V_3 , V_27 -> V_130 ) ) < 0 )
return V_55 ;
if ( F_42 ( V_3 , V_27 -> V_130 , & V_108 ) < 0 )
return - V_61 ;
V_187 = F_20 ( V_190 , V_189 ) ;
switch ( V_3 -> V_37 -> V_141 ) {
case F_55 ( 0x08bb , 0x2702 ) :
F_24 ( V_86
L_41 ) ;
V_187 &= ~ F_69 ( V_182 ) ;
break;
}
if ( V_121 > 0 )
V_188 = F_20 ( V_190 + V_189 , V_189 ) ;
else
V_188 = 0 ;
if ( V_3 -> V_52 -> V_72 == V_73 ) {
for ( V_145 = 0 ; V_145 < 10 ; V_145 ++ ) {
unsigned int V_194 = 0 ;
for ( V_186 = 0 ; V_186 < V_121 ; V_186 ++ ) {
unsigned int V_195 = F_20 ( V_190 + V_189 * ( V_186 + 1 ) , V_189 ) ;
if ( V_195 & ( 1 << V_145 ) )
V_194 |= ( 1 << V_186 ) ;
}
if ( V_194 & 1 )
F_63 ( V_3 , V_185 , V_194 , V_145 , & V_108 , V_4 , 0 ) ;
if ( V_187 & ( 1 << V_145 ) )
F_63 ( V_3 , V_185 , 0 , V_145 , & V_108 , V_4 , 0 ) ;
}
} else {
for ( V_145 = 0 ; V_145 < F_70 ( V_177 ) ; V_145 ++ ) {
unsigned int V_194 = 0 ;
unsigned int V_196 = 0 ;
for ( V_186 = 0 ; V_186 < V_121 ; V_186 ++ ) {
unsigned int V_195 = F_20 ( V_190 + V_189 * ( V_186 + 1 ) , V_189 ) ;
if ( F_71 ( V_195 , V_145 ) ) {
V_194 |= ( 1 << V_186 ) ;
if ( ! F_72 ( V_195 , V_145 ) )
V_196 |= ( 1 << V_186 ) ;
}
}
if ( V_194 & 1 )
F_63 ( V_3 , V_185 , V_194 , V_145 , & V_108 , V_4 , V_196 ) ;
if ( F_71 ( V_187 , V_145 ) )
F_63 ( V_3 , V_185 , 0 , V_145 , & V_108 , V_4 ,
! F_72 ( V_187 , V_145 ) ) ;
}
}
return 0 ;
}
static void F_73 ( struct V_2 * V_3 ,
struct V_131 * V_171 ,
int V_197 , int V_198 , int V_4 ,
struct V_107 * V_108 )
{
struct V_13 * V_14 ;
unsigned int V_99 = F_45 ( V_171 ) ;
unsigned int V_145 , V_36 ;
struct V_88 * V_102 ;
const struct V_1 * V_7 ;
V_7 = F_1 ( V_3 , V_4 , 0 ) ;
if ( F_4 ( V_7 ) )
return;
V_14 = F_65 ( sizeof( * V_14 ) , V_176 ) ;
if ( ! V_14 )
return;
V_14 -> V_52 = V_3 -> V_52 ;
V_14 -> V_8 = V_4 ;
V_14 -> V_5 = V_198 + 1 ;
V_14 -> V_40 = V_46 ;
for ( V_145 = 0 ; V_145 < V_99 ; V_145 ++ ) {
if ( F_37 ( F_74 ( V_171 , V_3 -> V_52 -> V_72 ) , V_198 , V_145 , V_99 ) ) {
V_14 -> V_144 |= ( 1 << V_145 ) ;
V_14 -> V_121 ++ ;
}
}
F_75 ( V_14 , 0 ) ;
V_102 = F_66 ( & V_179 , V_14 ) ;
if ( ! V_102 ) {
F_24 ( V_60 L_27 ) ;
F_53 ( V_14 ) ;
return;
}
V_102 -> V_180 = F_52 ;
V_36 = F_2 ( V_7 , V_102 -> V_8 . V_11 , sizeof( V_102 -> V_8 . V_11 ) ) ;
if ( ! V_36 )
V_36 = F_41 ( V_3 , V_108 , V_102 -> V_8 . V_11 , sizeof( V_102 -> V_8 . V_11 ) , 0 ) ;
if ( ! V_36 )
V_36 = sprintf ( V_102 -> V_8 . V_11 , L_42 , V_198 + 1 ) ;
F_61 ( V_102 , L_32 ) ;
F_22 ( V_86 L_43 ,
V_14 -> V_8 , V_102 -> V_8 . V_11 , V_14 -> V_121 , V_14 -> V_16 , V_14 -> V_18 ) ;
F_38 ( V_3 -> V_52 , V_102 ) ;
}
static int F_76 ( struct V_2 * V_3 , int V_4 , void * V_168 )
{
struct V_131 * V_171 = V_168 ;
struct V_107 V_108 ;
int V_199 , V_200 , V_99 ;
int V_201 , V_97 , V_55 ;
if ( V_171 -> V_30 < 11 || ! ( V_199 = V_171 -> V_137 ) || ! ( V_99 = F_45 ( V_171 ) ) ) {
F_24 ( V_60 L_44 , V_4 ) ;
return - V_61 ;
}
if ( V_171 -> V_30 <= 10 + V_199 ) {
F_22 ( V_86 L_45 , V_4 ) ;
return 0 ;
}
V_200 = 0 ;
V_97 = 0 ;
for ( V_201 = 0 ; V_201 < V_199 ; V_201 ++ ) {
V_55 = F_68 ( V_3 , V_171 -> V_134 [ V_201 ] ) ;
if ( V_55 < 0 )
continue;
V_55 = F_42 ( V_3 , V_171 -> V_134 [ V_201 ] , & V_108 ) ;
if ( V_55 < 0 )
return V_55 ;
V_200 += V_108 . V_121 ;
for (; V_97 < V_200 ; ++ V_97 ) {
int V_98 , V_202 = 0 ;
for ( V_98 = 0 ; V_98 < V_99 ; ++ V_98 ) {
if ( F_37 ( F_74 ( V_171 , V_3 -> V_52 -> V_72 ) ,
V_97 , V_98 , V_99 ) ) {
V_202 = 1 ;
break;
}
}
if ( V_202 )
F_73 ( V_3 , V_171 , V_201 , V_97 ,
V_4 , & V_108 ) ;
}
}
return 0 ;
}
static int F_77 ( struct V_88 * V_89 , struct V_161 * V_162 )
{
struct V_13 * V_14 = V_89 -> V_92 ;
int V_55 , V_39 ;
V_55 = F_26 ( V_14 , V_14 -> V_5 << 8 , & V_39 ) ;
if ( V_55 < 0 && V_14 -> V_52 -> V_78 ) {
V_162 -> V_74 . integer . V_74 [ 0 ] = V_14 -> V_16 ;
return 0 ;
}
if ( V_55 < 0 )
return V_55 ;
V_39 = F_13 ( V_14 , V_39 ) ;
V_162 -> V_74 . integer . V_74 [ 0 ] = V_39 ;
return 0 ;
}
static int F_78 ( struct V_88 * V_89 , struct V_161 * V_162 )
{
struct V_13 * V_14 = V_89 -> V_92 ;
int V_39 , V_165 , V_55 ;
V_55 = F_26 ( V_14 , V_14 -> V_5 << 8 , & V_165 ) ;
if ( V_55 < 0 ) {
if ( V_14 -> V_52 -> V_78 )
return 0 ;
return V_55 ;
}
V_39 = V_162 -> V_74 . integer . V_74 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_165 ) {
F_32 ( V_14 , V_14 -> V_5 << 8 , V_39 ) ;
return 1 ;
}
return 0 ;
}
static int F_79 ( struct V_2 * V_3 , int V_4 , void * V_168 , struct V_203 * V_204 , char * V_11 )
{
struct V_136 * V_171 = V_168 ;
int V_200 = V_171 -> V_137 ;
struct V_13 * V_14 ;
struct V_88 * V_102 ;
int V_145 , V_55 , V_173 , type , V_36 ;
struct V_203 * V_205 ;
struct V_206 * V_207 ;
const struct V_1 * V_7 ;
static struct V_206 V_208 [] = {
{ 0x01 , L_46 , V_41 } ,
{ 0 }
} ;
static struct V_203 V_209 = {
0 , NULL , V_208
} ;
if ( V_171 -> V_30 < 13 || V_171 -> V_30 < 13 + V_200 ||
V_171 -> V_30 < V_200 + F_80 ( V_171 , V_3 -> V_52 -> V_72 ) ) {
F_24 ( V_60 L_47 , V_11 , V_4 ) ;
return - V_61 ;
}
for ( V_145 = 0 ; V_145 < V_200 ; V_145 ++ ) {
if ( ( V_55 = F_68 ( V_3 , V_171 -> V_134 [ V_145 ] ) ) < 0 )
return V_55 ;
}
type = F_43 ( V_171 -> V_210 ) ;
for ( V_205 = V_204 ; V_205 && V_205 -> type ; V_205 ++ )
if ( V_205 -> type == type )
break;
if ( ! V_205 || ! V_205 -> type )
V_205 = & V_209 ;
for ( V_207 = V_205 -> V_211 ; V_207 -> V_5 ; V_207 ++ ) {
T_1 * V_212 = F_81 ( V_171 , V_3 -> V_52 -> V_72 ) ;
if ( ! ( V_212 [ V_207 -> V_5 / 8 ] & ( 1 << ( ( V_207 -> V_5 % 8 ) - 1 ) ) ) )
continue;
V_7 = F_1 ( V_3 , V_4 , V_207 -> V_5 ) ;
if ( F_4 ( V_7 ) )
continue;
V_14 = F_65 ( sizeof( * V_14 ) , V_176 ) ;
if ( ! V_14 ) {
F_24 ( V_60 L_27 ) ;
return - V_94 ;
}
V_14 -> V_52 = V_3 -> V_52 ;
V_14 -> V_8 = V_4 ;
V_14 -> V_5 = V_207 -> V_5 ;
V_14 -> V_40 = V_207 -> V_40 ;
V_14 -> V_121 = 1 ;
if ( type == V_213 && V_14 -> V_5 == V_214 ) {
T_1 * V_215 = F_82 ( V_171 , V_3 -> V_52 -> V_72 ) ;
V_14 -> V_16 = 1 ;
V_14 -> V_18 = V_215 [ 0 ] ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
} else {
if ( type == V_216 ) {
V_14 -> V_16 = 0 ;
V_14 -> V_18 = 5 ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
} else
F_75 ( V_14 , V_207 -> V_217 ) ;
}
V_102 = F_66 ( & V_218 , V_14 ) ;
if ( ! V_102 ) {
F_24 ( V_60 L_27 ) ;
F_53 ( V_14 ) ;
return - V_94 ;
}
V_102 -> V_180 = F_52 ;
if ( F_2 ( V_7 , V_102 -> V_8 . V_11 ,
sizeof( V_102 -> V_8 . V_11 ) ) )
;
else if ( V_205 -> V_11 )
F_3 ( V_102 -> V_8 . V_11 , V_205 -> V_11 , sizeof( V_102 -> V_8 . V_11 ) ) ;
else {
V_173 = F_51 ( V_171 , V_3 -> V_52 -> V_72 ) ;
V_36 = 0 ;
if ( V_173 )
V_36 = F_9 ( V_3 , V_173 , V_102 -> V_8 . V_11 , sizeof( V_102 -> V_8 . V_11 ) ) ;
if ( ! V_36 )
F_3 ( V_102 -> V_8 . V_11 , V_11 , sizeof( V_102 -> V_8 . V_11 ) ) ;
}
F_61 ( V_102 , L_48 ) ;
F_61 ( V_102 , V_207 -> V_219 ) ;
F_22 ( V_86 L_49 ,
V_14 -> V_8 , V_102 -> V_8 . V_11 , V_14 -> V_121 , V_14 -> V_16 , V_14 -> V_18 ) ;
if ( ( V_55 = F_38 ( V_3 -> V_52 , V_102 ) ) < 0 )
return V_55 ;
}
return 0 ;
}
static int F_83 ( struct V_2 * V_3 , int V_4 , void * V_168 )
{
return F_79 ( V_3 , V_4 , V_168 , V_220 , L_50 ) ;
}
static int F_84 ( struct V_2 * V_3 , int V_4 , void * V_168 )
{
return F_79 ( V_3 , V_4 , V_168 , V_221 , L_51 ) ;
}
static int F_85 ( struct V_88 * V_89 , struct V_152 * V_153 )
{
struct V_13 * V_14 = V_89 -> V_92 ;
const char * * V_222 = ( const char * * ) V_89 -> V_223 ;
if ( F_86 ( ! V_222 ) )
return - V_61 ;
return F_87 ( V_153 , 1 , V_14 -> V_18 , V_222 ) ;
}
static int F_88 ( struct V_88 * V_89 , struct V_161 * V_162 )
{
struct V_13 * V_14 = V_89 -> V_92 ;
int V_39 , V_55 ;
V_55 = F_26 ( V_14 , V_14 -> V_5 << 8 , & V_39 ) ;
if ( V_55 < 0 ) {
if ( V_14 -> V_52 -> V_78 ) {
V_162 -> V_74 . V_224 . V_225 [ 0 ] = 0 ;
return 0 ;
}
return V_55 ;
}
V_39 = F_13 ( V_14 , V_39 ) ;
V_162 -> V_74 . V_224 . V_225 [ 0 ] = V_39 ;
return 0 ;
}
static int F_89 ( struct V_88 * V_89 , struct V_161 * V_162 )
{
struct V_13 * V_14 = V_89 -> V_92 ;
int V_39 , V_165 , V_55 ;
V_55 = F_26 ( V_14 , V_14 -> V_5 << 8 , & V_165 ) ;
if ( V_55 < 0 ) {
if ( V_14 -> V_52 -> V_78 )
return 0 ;
return V_55 ;
}
V_39 = V_162 -> V_74 . V_224 . V_225 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_165 ) {
F_32 ( V_14 , V_14 -> V_5 << 8 , V_39 ) ;
return 1 ;
}
return 0 ;
}
static void F_90 ( struct V_88 * V_102 )
{
int V_145 , V_200 = 0 ;
if ( V_102 -> V_92 ) {
struct V_13 * V_14 = V_102 -> V_92 ;
V_200 = V_14 -> V_18 ;
F_53 ( V_14 ) ;
V_102 -> V_92 = NULL ;
}
if ( V_102 -> V_223 ) {
char * * V_222 = ( char * * ) V_102 -> V_223 ;
for ( V_145 = 0 ; V_145 < V_200 ; V_145 ++ )
F_53 ( V_222 [ V_145 ] ) ;
F_53 ( V_222 ) ;
V_102 -> V_223 = 0 ;
}
}
static int F_91 ( struct V_2 * V_3 , int V_4 , void * V_168 )
{
struct V_133 * V_171 = V_168 ;
unsigned int V_145 , V_173 , V_36 ;
int V_55 ;
struct V_13 * V_14 ;
struct V_88 * V_102 ;
const struct V_1 * V_7 ;
char * * V_226 ;
if ( ! V_171 -> V_137 || V_171 -> V_30 < 5 + V_171 -> V_137 ) {
F_24 ( V_60 L_52 , V_4 ) ;
return - V_61 ;
}
for ( V_145 = 0 ; V_145 < V_171 -> V_137 ; V_145 ++ ) {
if ( ( V_55 = F_68 ( V_3 , V_171 -> V_134 [ V_145 ] ) ) < 0 )
return V_55 ;
}
if ( V_171 -> V_137 == 1 )
return 0 ;
V_7 = F_1 ( V_3 , V_4 , 0 ) ;
if ( F_4 ( V_7 ) )
return 0 ;
V_14 = F_65 ( sizeof( * V_14 ) , V_176 ) ;
if ( ! V_14 ) {
F_24 ( V_60 L_27 ) ;
return - V_94 ;
}
V_14 -> V_52 = V_3 -> V_52 ;
V_14 -> V_8 = V_4 ;
V_14 -> V_40 = V_43 ;
V_14 -> V_121 = 1 ;
V_14 -> V_16 = 1 ;
V_14 -> V_18 = V_171 -> V_137 ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
if ( V_171 -> V_31 == V_132 )
V_14 -> V_5 = V_227 ;
else
V_14 -> V_5 = 0 ;
V_226 = F_92 ( sizeof( char * ) * V_171 -> V_137 , V_176 ) ;
if ( ! V_226 ) {
F_24 ( V_60 L_53 ) ;
F_53 ( V_14 ) ;
return - V_94 ;
}
#define F_93 64
for ( V_145 = 0 ; V_145 < V_171 -> V_137 ; V_145 ++ ) {
struct V_107 V_108 ;
V_36 = 0 ;
V_226 [ V_145 ] = F_92 ( F_93 , V_176 ) ;
if ( ! V_226 [ V_145 ] ) {
F_24 ( V_60 L_53 ) ;
while ( V_145 -- )
F_53 ( V_226 [ V_145 ] ) ;
F_53 ( V_226 ) ;
F_53 ( V_14 ) ;
return - V_94 ;
}
V_36 = F_6 ( V_3 , V_4 , V_145 , V_226 [ V_145 ] ,
F_93 ) ;
if ( ! V_36 && F_42 ( V_3 , V_171 -> V_134 [ V_145 ] , & V_108 ) >= 0 )
V_36 = F_41 ( V_3 , & V_108 , V_226 [ V_145 ] , F_93 , 0 ) ;
if ( ! V_36 )
sprintf ( V_226 [ V_145 ] , L_54 , V_145 ) ;
}
V_102 = F_66 ( & V_228 , V_14 ) ;
if ( ! V_102 ) {
F_24 ( V_60 L_27 ) ;
F_53 ( V_226 ) ;
F_53 ( V_14 ) ;
return - V_94 ;
}
V_102 -> V_223 = ( unsigned long ) V_226 ;
V_102 -> V_180 = F_90 ;
V_173 = F_48 ( V_171 ) ;
V_36 = F_2 ( V_7 , V_102 -> V_8 . V_11 , sizeof( V_102 -> V_8 . V_11 ) ) ;
if ( V_36 )
;
else if ( V_173 )
F_9 ( V_3 , V_173 , V_102 -> V_8 . V_11 , sizeof( V_102 -> V_8 . V_11 ) ) ;
else {
V_36 = F_41 ( V_3 , & V_3 -> V_183 ,
V_102 -> V_8 . V_11 , sizeof( V_102 -> V_8 . V_11 ) , 0 ) ;
if ( ! V_36 )
F_3 ( V_102 -> V_8 . V_11 , L_55 , sizeof( V_102 -> V_8 . V_11 ) ) ;
if ( V_171 -> V_31 == V_132 )
F_61 ( V_102 , L_56 ) ;
else if ( ( V_3 -> V_183 . type & 0xff00 ) == 0x0100 )
F_61 ( V_102 , L_57 ) ;
else
F_61 ( V_102 , L_58 ) ;
}
F_22 ( V_86 L_59 ,
V_14 -> V_8 , V_102 -> V_8 . V_11 , V_171 -> V_137 ) ;
if ( ( V_55 = F_38 ( V_3 -> V_52 , V_102 ) ) < 0 )
return V_55 ;
return 0 ;
}
static int F_68 ( struct V_2 * V_3 , int V_4 )
{
unsigned char * V_117 ;
if ( F_94 ( V_4 , V_3 -> V_229 ) )
return 0 ;
V_117 = F_7 ( V_3 , V_4 ) ;
if ( ! V_117 ) {
F_24 ( V_60 L_60 , V_4 ) ;
return - V_61 ;
}
switch ( V_117 [ 2 ] ) {
case V_32 :
case V_138 :
return 0 ;
case V_114 :
return F_76 ( V_3 , V_4 , V_117 ) ;
case V_111 :
case V_132 :
return F_91 ( V_3 , V_4 , V_117 ) ;
case V_129 :
return F_67 ( V_3 , V_4 , V_117 ) ;
case V_112 :
if ( V_3 -> V_52 -> V_72 == V_73 )
return F_83 ( V_3 , V_4 , V_117 ) ;
else
return 0 ;
case V_113 :
if ( V_3 -> V_52 -> V_72 == V_73 )
return F_84 ( V_3 , V_4 , V_117 ) ;
else
return F_83 ( V_3 , V_4 , V_117 ) ;
default:
F_24 ( V_60 L_61 , V_4 , V_117 [ 2 ] ) ;
return - V_61 ;
}
}
static void F_95 ( struct V_101 * V_52 )
{
F_53 ( V_52 -> V_106 ) ;
if ( V_52 -> V_230 ) {
F_53 ( V_52 -> V_230 -> V_231 ) ;
F_96 ( V_52 -> V_230 ) ;
}
F_96 ( V_52 -> V_232 ) ;
F_53 ( V_52 -> V_233 ) ;
F_53 ( V_52 ) ;
}
static int F_97 ( struct V_234 * V_235 )
{
struct V_101 * V_52 = V_235 -> V_236 ;
F_95 ( V_52 ) ;
return 0 ;
}
static int F_98 ( struct V_101 * V_52 )
{
struct V_2 V_3 ;
int V_55 ;
const struct V_237 * V_7 ;
void * V_6 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_37 = V_52 -> V_37 ;
V_3 . V_52 = V_52 ;
V_3 . V_28 = V_52 -> V_238 -> V_239 ;
V_3 . V_10 = V_52 -> V_238 -> V_240 ;
for ( V_7 = V_241 ; V_7 -> V_8 ; V_7 ++ ) {
if ( V_7 -> V_8 == V_3 . V_37 -> V_141 ) {
V_3 . V_7 = V_7 -> V_7 ;
V_3 . V_22 = V_7 -> V_22 ;
V_52 -> V_78 = V_7 -> V_78 ;
break;
}
}
V_6 = NULL ;
while ( ( V_6 = F_99 ( V_52 -> V_238 -> V_239 , V_52 -> V_238 -> V_240 ,
V_6 , V_242 ) ) != NULL ) {
if ( V_52 -> V_72 == V_73 ) {
struct V_243 * V_171 = V_6 ;
if ( V_171 -> V_30 < sizeof( * V_171 ) )
continue;
F_100 ( V_171 -> V_244 , V_3 . V_229 ) ;
V_3 . V_183 . V_8 = V_171 -> V_244 ;
V_3 . V_183 . type = F_43 ( V_171 -> V_120 ) ;
V_3 . V_183 . V_11 = V_171 -> V_125 ;
V_55 = F_68 ( & V_3 , V_171 -> V_130 ) ;
if ( V_55 < 0 )
return V_55 ;
} else {
struct V_245 * V_171 = V_6 ;
if ( V_171 -> V_30 < sizeof( * V_171 ) )
continue;
F_100 ( V_171 -> V_244 , V_3 . V_229 ) ;
V_3 . V_183 . V_8 = V_171 -> V_244 ;
V_3 . V_183 . type = F_43 ( V_171 -> V_120 ) ;
V_3 . V_183 . V_11 = V_171 -> V_125 ;
V_55 = F_68 ( & V_3 , V_171 -> V_130 ) ;
if ( V_55 < 0 )
return V_55 ;
V_55 = F_68 ( & V_3 , V_171 -> V_128 ) ;
if ( V_55 < 0 )
return V_55 ;
}
}
return 0 ;
}
void F_101 ( struct V_101 * V_52 , int V_4 )
{
struct V_13 * V_205 ;
for ( V_205 = V_52 -> V_106 [ V_4 ] ; V_205 ; V_205 = V_205 -> V_105 )
F_58 ( V_52 -> V_37 -> V_103 , V_246 ,
V_205 -> V_104 ) ;
}
static void F_102 ( struct V_247 * V_28 ,
int V_4 ,
struct V_13 * V_14 )
{
static char * V_248 [] = { L_62 , L_63 ,
L_64 , L_65 , L_66 , L_67 } ;
F_103 ( V_28 , L_68 , V_4 ) ;
if ( V_14 -> V_104 )
F_103 ( V_28 , L_69 ,
V_14 -> V_104 -> V_11 , V_14 -> V_104 -> V_20 ) ;
F_103 ( V_28 , L_70
L_71 , V_14 -> V_8 ,
V_14 -> V_5 , V_14 -> V_144 , V_14 -> V_121 ,
V_248 [ V_14 -> V_40 ] ) ;
F_103 ( V_28 , L_72 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_15 , V_14 -> V_17 ) ;
}
static void F_104 ( struct V_249 * V_250 ,
struct V_247 * V_28 )
{
struct V_51 * V_37 = V_250 -> V_92 ;
struct V_101 * V_52 ;
struct V_13 * V_14 ;
int V_4 ;
F_105 (mixer, &chip->mixer_list, list) {
F_103 ( V_28 ,
L_73 ,
V_37 -> V_141 , F_19 ( V_37 ) ,
V_52 -> V_78 ) ;
F_103 ( V_28 , L_74 , V_37 -> V_103 -> V_251 ) ;
for ( V_4 = 0 ; V_4 < V_252 ; V_4 ++ ) {
for ( V_14 = V_52 -> V_106 [ V_4 ] ; V_14 ;
V_14 = V_14 -> V_105 )
F_102 ( V_28 , V_4 , V_14 ) ;
}
}
}
static void F_106 ( struct V_101 * V_52 ,
int V_253 , int V_74 , int V_20 )
{
struct V_13 * V_205 ;
T_1 V_4 = ( V_20 >> 8 ) & 0xff ;
T_1 V_5 = ( V_74 >> 8 ) & 0xff ;
T_1 V_75 = V_74 & 0xff ;
if ( V_75 >= V_146 ) {
F_24 ( V_254 L_75 ,
V_87 , V_75 ) ;
return;
}
for ( V_205 = V_52 -> V_106 [ V_4 ] ; V_205 ; V_205 = V_205 -> V_105 ) {
if ( V_205 -> V_5 != V_5 )
continue;
switch ( V_253 ) {
case V_67 :
if ( V_75 )
V_205 -> V_76 &= ~ ( 1 << V_75 ) ;
else
V_205 -> V_76 = 0 ;
F_58 ( V_52 -> V_37 -> V_103 , V_246 ,
V_205 -> V_104 ) ;
break;
case V_68 :
break;
case V_255 :
break;
default:
F_24 ( V_254 L_76 ,
V_253 ) ;
break;
}
}
}
static void F_107 ( struct V_230 * V_230 )
{
struct V_101 * V_52 = V_230 -> V_256 ;
int V_36 = V_230 -> V_257 ;
int V_258 = V_230 -> V_259 ;
if ( V_258 != 0 )
goto V_260;
if ( V_52 -> V_72 == V_73 ) {
struct V_261 * V_259 ;
for ( V_259 = V_230 -> V_231 ;
V_36 >= sizeof( * V_259 ) ;
V_36 -= sizeof( * V_259 ) , V_259 ++ ) {
F_29 ( V_254 L_77 ,
V_259 -> V_262 ,
V_259 -> V_263 ) ;
if ( ( V_259 -> V_262 & V_264 ) !=
V_265 )
continue;
if ( V_259 -> V_262 & V_266 )
F_108 ( V_52 , V_259 -> V_263 ) ;
else
F_101 ( V_52 , V_259 -> V_263 ) ;
}
} else {
struct V_267 * V_268 ;
for ( V_268 = V_230 -> V_231 ;
V_36 >= sizeof( * V_268 ) ;
V_36 -= sizeof( * V_268 ) , V_268 ++ ) {
if ( ( V_268 -> V_269 & V_270 ) ||
( V_268 -> V_269 & V_271 ) )
continue;
F_106 ( V_52 , V_268 -> V_272 ,
F_43 ( V_268 -> V_273 ) ,
F_43 ( V_268 -> V_274 ) ) ;
}
}
V_260:
if ( V_258 != - V_275 && V_258 != - V_276 && V_258 != - V_277 ) {
V_230 -> V_38 = V_52 -> V_37 -> V_38 ;
F_109 ( V_230 , V_278 ) ;
}
}
void F_110 ( struct V_101 * V_52 )
{
F_111 ( V_52 -> V_230 ) ;
F_111 ( V_52 -> V_232 ) ;
}
int F_112 ( struct V_101 * V_52 )
{
int V_55 ;
if ( V_52 -> V_230 ) {
V_55 = F_109 ( V_52 -> V_230 , V_279 ) ;
if ( V_55 < 0 )
return V_55 ;
}
return 0 ;
}
static int F_113 ( struct V_101 * V_52 )
{
struct V_280 * V_281 ;
void * V_231 ;
int V_282 ;
unsigned int V_283 ;
if ( F_114 ( V_52 -> V_238 ) -> V_284 < 1 )
return 0 ;
V_281 = F_115 ( V_52 -> V_238 , 0 ) ;
if ( ! F_116 ( V_281 ) || ! F_117 ( V_281 ) )
return 0 ;
V_283 = F_118 ( V_281 ) ;
V_282 = F_43 ( V_281 -> V_285 ) ;
V_231 = F_92 ( V_282 , V_176 ) ;
if ( ! V_231 )
return - V_94 ;
V_52 -> V_230 = F_119 ( 0 , V_176 ) ;
if ( ! V_52 -> V_230 ) {
F_53 ( V_231 ) ;
return - V_94 ;
}
F_120 ( V_52 -> V_230 , V_52 -> V_37 -> V_38 ,
F_121 ( V_52 -> V_37 -> V_38 , V_283 ) ,
V_231 , V_282 ,
F_107 , V_52 , V_281 -> V_286 ) ;
F_109 ( V_52 -> V_230 , V_176 ) ;
return 0 ;
}
int F_122 ( struct V_51 * V_37 , int V_287 ,
int V_288 )
{
static struct V_289 V_290 = {
. V_291 = F_97
} ;
struct V_101 * V_52 ;
struct V_249 * V_250 ;
int V_55 ;
strcpy ( V_37 -> V_103 -> V_292 , L_78 ) ;
V_52 = F_65 ( sizeof( * V_52 ) , V_176 ) ;
if ( ! V_52 )
return - V_94 ;
V_52 -> V_37 = V_37 ;
V_52 -> V_78 = V_288 ;
V_52 -> V_106 = F_123 ( V_252 , sizeof( * V_52 -> V_106 ) ,
V_176 ) ;
if ( ! V_52 -> V_106 ) {
F_53 ( V_52 ) ;
return - V_94 ;
}
V_52 -> V_238 = & F_124 ( V_37 -> V_38 , V_287 ) -> V_293 [ 0 ] ;
switch ( F_114 ( V_52 -> V_238 ) -> V_294 ) {
case V_73 :
default:
V_52 -> V_72 = V_73 ;
break;
case V_295 :
V_52 -> V_72 = V_295 ;
break;
}
if ( ( V_55 = F_98 ( V_52 ) ) < 0 ||
( V_55 = F_113 ( V_52 ) ) < 0 )
goto V_296;
F_125 ( V_52 ) ;
V_55 = F_126 ( V_37 -> V_103 , V_297 , V_52 , & V_290 ) ;
if ( V_55 < 0 )
goto V_296;
if ( F_127 ( & V_37 -> V_298 ) &&
! F_128 ( V_37 -> V_103 , L_79 , & V_250 ) )
F_129 ( V_250 , V_37 , F_104 ) ;
F_130 ( & V_52 -> V_204 , & V_37 -> V_298 ) ;
return 0 ;
V_296:
F_95 ( V_52 ) ;
return V_55 ;
}
void F_131 ( struct V_299 * V_6 )
{
struct V_101 * V_52 ;
V_52 = F_132 ( V_6 , struct V_101 , V_204 ) ;
F_111 ( V_52 -> V_230 ) ;
F_111 ( V_52 -> V_232 ) ;
}
