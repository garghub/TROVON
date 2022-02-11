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
int V_55 = 0 , V_56 ;
V_56 = F_16 ( V_14 -> V_52 -> V_37 ) ;
if ( V_56 < 0 )
return - V_57 ;
F_17 ( & V_37 -> V_58 ) ;
while ( V_54 -- > 0 ) {
if ( V_37 -> V_59 )
break;
V_55 = F_18 ( V_37 ) | ( V_14 -> V_8 << 8 ) ;
if ( F_19 ( V_37 -> V_38 , F_20 ( V_37 -> V_38 , 0 ) , V_48 ,
V_60 | V_61 | V_62 ,
V_49 , V_55 , V_9 , V_53 ) >= V_53 ) {
* V_50 = F_11 ( V_14 , F_21 ( V_9 , V_53 ) ) ;
V_56 = 0 ;
goto V_63;
}
}
F_22 ( V_64 L_1 ,
V_48 , V_49 , V_55 , V_14 -> V_40 ) ;
V_56 = - V_65 ;
V_63:
F_23 ( & V_37 -> V_58 ) ;
F_24 ( V_14 -> V_52 -> V_37 ) ;
return V_56 ;
}
static int F_25 ( struct V_13 * V_14 , int V_48 , int V_49 , int * V_50 )
{
struct V_51 * V_37 = V_14 -> V_52 -> V_37 ;
unsigned char V_9 [ 2 + 3 * sizeof( V_66 ) ] ;
unsigned char * V_39 ;
int V_55 = 0 , V_67 , V_68 ;
T_1 V_69 ;
if ( V_48 == V_70 ) {
V_69 = V_71 ;
V_68 = sizeof( V_66 ) ;
} else {
V_69 = V_72 ;
V_68 = sizeof( V_9 ) ;
}
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
V_67 = F_16 ( V_37 ) ? - V_57 : 0 ;
if ( V_67 )
goto error;
F_17 ( & V_37 -> V_58 ) ;
if ( V_37 -> V_59 )
V_67 = - V_73 ;
else {
V_55 = F_18 ( V_37 ) | ( V_14 -> V_8 << 8 ) ;
V_67 = F_19 ( V_37 -> V_38 , F_20 ( V_37 -> V_38 , 0 ) , V_69 ,
V_60 | V_61 | V_62 ,
V_49 , V_55 , V_9 , V_68 ) ;
}
F_23 ( & V_37 -> V_58 ) ;
F_24 ( V_37 ) ;
if ( V_67 < 0 ) {
error:
F_26 ( V_64 L_1 ,
V_48 , V_49 , V_55 , V_14 -> V_40 ) ;
return V_67 ;
}
switch ( V_48 ) {
case V_70 :
V_39 = V_9 ;
break;
case V_74 :
V_39 = V_9 + sizeof( V_66 ) ;
break;
case V_75 :
V_39 = V_9 + sizeof( V_66 ) * 2 ;
break;
case V_76 :
V_39 = V_9 + sizeof( V_66 ) * 3 ;
break;
default:
return - V_65 ;
}
* V_50 = F_11 ( V_14 , F_21 ( V_39 , sizeof( V_66 ) ) ) ;
return 0 ;
}
static int F_27 ( struct V_13 * V_14 , int V_48 , int V_49 , int * V_50 )
{
V_49 += V_14 -> V_77 ;
return ( V_14 -> V_52 -> V_78 == V_79 ) ?
F_15 ( V_14 , V_48 , V_49 , V_50 ) :
F_25 ( V_14 , V_48 , V_49 , V_50 ) ;
}
static int F_28 ( struct V_13 * V_14 , int V_49 , int * V_80 )
{
return F_27 ( V_14 , V_70 , V_49 , V_80 ) ;
}
static inline int F_29 ( struct V_13 * V_14 ,
int V_81 , int * V_80 )
{
return F_27 ( V_14 , V_70 , ( V_14 -> V_5 << 8 ) | V_81 , V_80 ) ;
}
static int F_30 ( struct V_13 * V_14 ,
int V_81 , int V_20 , int * V_80 )
{
int V_56 ;
if ( V_14 -> V_82 & ( 1 << V_81 ) ) {
* V_80 = V_14 -> V_83 [ V_20 ] ;
return 0 ;
}
V_56 = F_29 ( V_14 , V_81 , V_80 ) ;
if ( V_56 < 0 ) {
if ( ! V_14 -> V_52 -> V_84 )
F_31 ( V_64 L_2 ,
V_14 -> V_5 , V_81 , V_56 ) ;
return V_56 ;
}
V_14 -> V_82 |= 1 << V_81 ;
V_14 -> V_83 [ V_20 ] = * V_80 ;
return 0 ;
}
int F_32 ( struct V_13 * V_14 ,
int V_48 , int V_49 , int V_85 )
{
struct V_51 * V_37 = V_14 -> V_52 -> V_37 ;
unsigned char V_9 [ 2 ] ;
int V_55 = 0 , V_53 , V_56 , V_54 = 10 ;
V_49 += V_14 -> V_77 ;
if ( V_14 -> V_52 -> V_78 == V_79 ) {
V_53 = V_14 -> V_40 >= V_46 ? 2 : 1 ;
} else {
V_53 = sizeof( V_66 ) ;
if ( V_48 != V_86 ) {
F_22 ( V_87 L_3 ) ;
return - V_65 ;
}
V_48 = V_71 ;
}
V_85 = F_12 ( V_14 , V_85 ) ;
V_9 [ 0 ] = V_85 & 0xff ;
V_9 [ 1 ] = ( V_85 >> 8 ) & 0xff ;
V_56 = F_16 ( V_37 ) ;
if ( V_56 < 0 )
return - V_57 ;
F_17 ( & V_37 -> V_58 ) ;
while ( V_54 -- > 0 ) {
if ( V_37 -> V_59 )
break;
V_55 = F_18 ( V_37 ) | ( V_14 -> V_8 << 8 ) ;
if ( F_19 ( V_37 -> V_38 ,
F_33 ( V_37 -> V_38 , 0 ) , V_48 ,
V_60 | V_61 | V_88 ,
V_49 , V_55 , V_9 , V_53 ) >= 0 ) {
V_56 = 0 ;
goto V_63;
}
}
F_22 ( V_64 L_4 ,
V_48 , V_49 , V_55 , V_14 -> V_40 , V_9 [ 0 ] , V_9 [ 1 ] ) ;
V_56 = - V_65 ;
V_63:
F_23 ( & V_37 -> V_58 ) ;
F_24 ( V_37 ) ;
return V_56 ;
}
static int F_34 ( struct V_13 * V_14 , int V_49 , int V_80 )
{
return F_32 ( V_14 , V_86 , V_49 , V_80 ) ;
}
static int F_35 ( struct V_13 * V_14 , int V_81 ,
int V_20 , int V_80 )
{
int V_56 ;
unsigned int V_89 = ( V_81 == 0 ) ?
V_14 -> V_90 :
V_14 -> V_91 & ( 1 << ( V_81 - 1 ) ) ;
if ( V_89 ) {
F_22 ( V_92 L_5 ,
V_93 , V_81 , V_14 -> V_5 ) ;
return 0 ;
}
V_56 = F_32 ( V_14 , V_86 , ( V_14 -> V_5 << 8 ) | V_81 ,
V_80 ) ;
if ( V_56 < 0 )
return V_56 ;
V_14 -> V_82 |= 1 << V_81 ;
V_14 -> V_83 [ V_20 ] = V_80 ;
return 0 ;
}
int F_36 ( struct V_94 * V_95 , int V_96 ,
unsigned int V_68 , unsigned int T_2 * V_97 )
{
struct V_13 * V_14 = V_95 -> V_98 ;
F_37 ( V_99 , 0 , 0 ) ;
if ( V_68 < sizeof( V_99 ) )
return - V_100 ;
V_99 [ 2 ] = V_14 -> V_15 ;
V_99 [ 3 ] = V_14 -> V_17 ;
if ( F_38 ( V_97 , V_99 , sizeof( V_99 ) ) )
return - V_101 ;
return 0 ;
}
static int F_39 ( unsigned char * V_102 , int V_103 , int V_104 , int V_105 )
{
int V_55 = V_103 * V_105 + V_104 ;
return V_102 [ V_55 >> 3 ] & ( 0x80 >> ( V_55 & 7 ) ) ;
}
int F_40 ( struct V_106 * V_52 ,
struct V_94 * V_107 )
{
struct V_13 * V_14 = V_107 -> V_98 ;
int V_56 ;
while ( F_41 ( V_52 -> V_37 -> V_108 , & V_107 -> V_8 ) )
V_107 -> V_8 . V_20 ++ ;
if ( ( V_56 = F_42 ( V_52 -> V_37 -> V_108 , V_107 ) ) < 0 ) {
F_31 ( V_64 L_6 , V_56 ) ;
return V_56 ;
}
V_14 -> V_109 = & V_107 -> V_8 ;
V_14 -> V_110 = V_52 -> V_111 [ V_14 -> V_8 ] ;
V_52 -> V_111 [ V_14 -> V_8 ] = V_14 ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 , struct V_112 * V_113 ,
unsigned char * V_11 , int V_35 , int V_114 )
{
struct V_115 * V_24 ;
if ( V_113 -> V_11 )
return F_9 ( V_3 , V_113 -> V_11 , V_11 , V_35 ) ;
if ( V_113 -> type >> 16 ) {
if ( V_114 )
return 0 ;
switch ( V_113 -> type >> 16 ) {
case V_116 :
strcpy ( V_11 , L_7 ) ; return 8 ;
case V_117 :
strcpy ( V_11 , L_8 ) ; return 12 ;
case V_118 :
strcpy ( V_11 , L_9 ) ; return 8 ;
case V_119 :
strcpy ( V_11 , L_10 ) ; return 5 ;
default:
return sprintf ( V_11 , L_11 , V_113 -> V_8 ) ;
}
}
switch ( V_113 -> type & 0xff00 ) {
case 0x0100 :
strcpy ( V_11 , L_12 ) ; return 3 ;
case 0x0200 :
strcpy ( V_11 , L_13 ) ; return 3 ;
case 0x0400 :
strcpy ( V_11 , L_14 ) ; return 7 ;
case 0x0500 :
strcpy ( V_11 , L_15 ) ; return 5 ;
}
for ( V_24 = V_120 ; V_24 -> type ; V_24 ++ )
if ( V_24 -> type == V_113 -> type ) {
strcpy ( V_11 , V_24 -> V_11 ) ;
return strlen ( V_24 -> V_11 ) ;
}
return 0 ;
}
static int F_44 ( struct V_2 * V_3 , int V_8 , struct V_112 * V_121 )
{
int V_56 ;
void * V_122 ;
memset ( V_121 , 0 , sizeof( * V_121 ) ) ;
while ( ( V_122 = F_7 ( V_3 , V_8 ) ) != NULL ) {
unsigned char * V_27 = V_122 ;
V_121 -> V_8 = V_8 ;
switch ( V_27 [ 2 ] ) {
case V_32 :
if ( V_3 -> V_52 -> V_78 == V_79 ) {
struct V_123 * V_124 = V_122 ;
V_121 -> type = F_45 ( V_124 -> V_125 ) ;
V_121 -> V_126 = V_124 -> V_127 ;
V_121 -> V_128 = F_45 ( V_124 -> V_129 ) ;
V_121 -> V_11 = V_124 -> V_130 ;
} else {
struct V_131 * V_124 = V_122 ;
V_121 -> type = F_45 ( V_124 -> V_125 ) ;
V_121 -> V_126 = V_124 -> V_127 ;
V_121 -> V_128 = F_46 ( V_124 -> V_132 ) ;
V_121 -> V_11 = V_124 -> V_130 ;
V_56 = F_44 ( V_3 , V_124 -> V_133 , V_121 ) ;
if ( V_56 < 0 )
return V_56 ;
}
return 0 ;
case V_134 : {
struct V_26 * V_124 = V_122 ;
V_8 = V_124 -> V_135 ;
break;
}
case V_119 : {
struct V_136 * V_124 = V_122 ;
V_121 -> type = V_124 -> V_31 << 16 ;
V_121 -> V_126 = F_47 ( V_124 ) ;
V_121 -> V_128 = F_48 ( V_124 , V_3 -> V_52 -> V_78 ) ;
V_121 -> V_11 = F_49 ( V_124 ) ;
return 0 ;
}
case V_116 :
case V_137 : {
struct V_138 * V_124 = V_122 ;
if ( F_44 ( V_3 , V_124 -> V_139 [ 0 ] , V_121 ) < 0 )
return - V_73 ;
V_121 -> type = V_124 -> V_31 << 16 ;
V_121 -> V_8 = V_8 ;
V_121 -> V_11 = F_50 ( V_124 ) ;
return 0 ;
}
case V_117 :
case V_118 :
{
struct V_140 * V_124 = V_122 ;
if ( V_3 -> V_52 -> V_78 == V_141 &&
V_27 [ 2 ] == V_142 ) {
return 0 ;
}
if ( V_124 -> V_143 ) {
V_8 = V_124 -> V_139 [ 0 ] ;
break;
}
V_121 -> type = V_124 -> V_31 << 16 ;
V_121 -> V_126 = F_51 ( V_124 ) ;
V_121 -> V_128 = F_52 ( V_124 , V_3 -> V_52 -> V_78 ) ;
V_121 -> V_11 = F_53 ( V_124 , V_3 -> V_52 -> V_78 ) ;
return 0 ;
}
case V_144 : {
struct V_145 * V_124 = V_122 ;
V_121 -> type = V_124 -> V_31 << 16 ;
V_121 -> V_8 = V_8 ;
V_121 -> V_11 = V_124 -> V_146 ;
return 0 ;
}
default:
return - V_73 ;
}
}
return - V_73 ;
}
static void F_54 ( struct V_94 * V_107 )
{
F_55 ( V_107 -> V_98 ) ;
V_107 -> V_98 = NULL ;
}
static void F_56 ( struct V_13 * V_14 ,
struct V_94 * V_107 )
{
switch ( V_14 -> V_52 -> V_37 -> V_147 ) {
case F_57 ( 0x0763 , 0x2030 ) :
if ( strcmp ( V_107 -> V_8 . V_11 , L_16 ) == 0 ) {
V_14 -> V_16 = 0x0000 ;
V_14 -> V_18 = 0xffff ;
V_14 -> V_47 = 0x00e6 ;
break;
}
if ( strcmp ( V_107 -> V_8 . V_11 , L_17 ) == 0 ||
strcmp ( V_107 -> V_8 . V_11 , L_18 ) == 0 ) {
V_14 -> V_16 = 0x00 ;
V_14 -> V_18 = 0xff ;
break;
}
if ( strstr ( V_107 -> V_8 . V_11 , L_19 ) != NULL ) {
V_14 -> V_16 = 0xb706 ;
V_14 -> V_18 = 0xff7b ;
V_14 -> V_47 = 0x0073 ;
break;
}
if ( ( strstr ( V_107 -> V_8 . V_11 , L_20 ) != NULL ) ||
( strstr ( V_107 -> V_8 . V_11 , L_21 ) != NULL ) ) {
V_14 -> V_16 = 0xb5fb ;
V_14 -> V_18 = 0xfcfe ;
V_14 -> V_47 = 0x0073 ;
}
break;
case F_57 ( 0x0763 , 0x2081 ) :
case F_57 ( 0x0763 , 0x2080 ) :
if ( strcmp ( V_107 -> V_8 . V_11 , L_16 ) == 0 ) {
F_26 ( V_92
L_22 ) ;
V_14 -> V_16 = 0x0000 ;
V_14 -> V_18 = 0x7f00 ;
V_14 -> V_47 = 0x0100 ;
break;
}
if ( strcmp ( V_107 -> V_8 . V_11 , L_17 ) == 0 ||
strcmp ( V_107 -> V_8 . V_11 , L_18 ) == 0 ) {
F_26 ( V_92
L_23 ) ;
V_14 -> V_16 = 0x00 ;
V_14 -> V_18 = 0x7f ;
break;
}
break;
case F_57 ( 0x0471 , 0x0101 ) :
case F_57 ( 0x0471 , 0x0104 ) :
case F_57 ( 0x0471 , 0x0105 ) :
case F_57 ( 0x0672 , 0x1041 ) :
if ( ! strcmp ( V_107 -> V_8 . V_11 , L_24 ) &&
V_14 -> V_16 == - 15616 ) {
F_26 ( V_92
L_25 ) ;
V_14 -> V_18 = - 256 ;
}
break;
case F_57 ( 0x046d , 0x09a4 ) :
if ( ! strcmp ( V_107 -> V_8 . V_11 , L_26 ) ) {
F_26 ( V_92
L_27 ) ;
V_14 -> V_16 = 6080 ;
V_14 -> V_18 = 8768 ;
V_14 -> V_47 = 192 ;
}
break;
case F_57 ( 0x046d , 0x0808 ) :
case F_57 ( 0x046d , 0x0809 ) :
case F_57 ( 0x046d , 0x081d ) :
case F_57 ( 0x046d , 0x0991 ) :
if ( ! strcmp ( V_107 -> V_8 . V_11 , L_26 ) ) {
F_26 ( V_92
L_28 ) ;
V_14 -> V_47 = 384 ;
}
break;
}
}
static int F_58 ( struct V_13 * V_14 ,
int V_148 , struct V_94 * V_107 )
{
V_14 -> V_16 = V_148 ;
V_14 -> V_18 = V_14 -> V_16 + 1 ;
V_14 -> V_47 = 1 ;
V_14 -> V_15 = V_14 -> V_17 = 0 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 ) {
V_14 -> V_19 = 1 ;
} else {
int V_149 = 0 ;
if ( V_14 -> V_150 ) {
int V_151 ;
for ( V_151 = 0 ; V_151 < V_152 ; V_151 ++ )
if ( V_14 -> V_150 & ( 1 << V_151 ) ) {
V_149 = V_151 + 1 ;
break;
}
}
if ( F_27 ( V_14 , V_75 , ( V_14 -> V_5 << 8 ) | V_149 , & V_14 -> V_18 ) < 0 ||
F_27 ( V_14 , V_74 , ( V_14 -> V_5 << 8 ) | V_149 , & V_14 -> V_16 ) < 0 ) {
F_31 ( V_64 L_29 ,
V_14 -> V_8 , F_18 ( V_14 -> V_52 -> V_37 ) , V_14 -> V_5 , V_14 -> V_8 ) ;
return - V_65 ;
}
if ( F_27 ( V_14 , V_76 , ( V_14 -> V_5 << 8 ) | V_149 , & V_14 -> V_47 ) < 0 ) {
V_14 -> V_47 = 1 ;
} else {
int V_153 = V_14 -> V_47 ;
while ( V_14 -> V_47 > 1 ) {
if ( F_32 ( V_14 , V_154 ,
( V_14 -> V_5 << 8 ) | V_149 , V_14 -> V_47 / 2 ) < 0 )
break;
V_14 -> V_47 /= 2 ;
}
if ( F_27 ( V_14 , V_76 , ( V_14 -> V_5 << 8 ) | V_149 , & V_14 -> V_47 ) < 0 )
V_14 -> V_47 = V_153 ;
}
if ( V_14 -> V_47 == 0 )
V_14 -> V_47 = 1 ;
if ( V_14 -> V_16 + V_14 -> V_47 < V_14 -> V_18 ) {
int V_153 = V_14 -> V_47 ;
int V_155 , V_156 , V_157 ;
F_29 ( V_14 , V_149 , & V_155 ) ;
for (; ; ) {
V_156 = V_155 ;
if ( V_156 < V_14 -> V_18 )
V_156 += V_14 -> V_47 ;
else
V_156 -= V_14 -> V_47 ;
if ( V_156 < V_14 -> V_16 || V_156 > V_14 -> V_18 ||
F_35 ( V_14 , V_149 , 0 , V_156 ) ||
F_29 ( V_14 , V_149 , & V_157 ) ) {
V_14 -> V_47 = V_153 ;
break;
}
if ( V_156 == V_157 )
break;
V_14 -> V_47 *= 2 ;
}
F_35 ( V_14 , V_149 , 0 , V_155 ) ;
}
V_14 -> V_19 = 1 ;
}
if ( V_107 )
F_56 ( V_14 , V_107 ) ;
V_14 -> V_15 = ( F_11 ( V_14 , V_14 -> V_16 ) * 100 ) / 256 ;
V_14 -> V_17 = ( F_11 ( V_14 , V_14 -> V_18 ) * 100 ) / 256 ;
if ( V_14 -> V_15 > V_14 -> V_17 ) {
if ( V_14 -> V_15 < 0 )
V_14 -> V_17 = 0 ;
else if ( V_14 -> V_15 > 0 )
V_14 -> V_15 = 0 ;
if ( V_14 -> V_15 > V_14 -> V_17 ) {
return - V_65 ;
}
}
return 0 ;
}
static int F_59 ( struct V_94 * V_95 , struct V_158 * V_159 )
{
struct V_13 * V_14 = V_95 -> V_98 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 )
V_159 -> type = V_160 ;
else
V_159 -> type = V_161 ;
V_159 -> V_23 = V_14 -> V_126 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 ) {
V_159 -> V_80 . integer . V_16 = 0 ;
V_159 -> V_80 . integer . V_18 = 1 ;
} else {
if ( ! V_14 -> V_19 ) {
F_58 ( V_14 , 0 , V_95 ) ;
if ( V_14 -> V_19 && V_14 -> V_15 >= V_14 -> V_17 ) {
V_95 -> V_162 [ 0 ] . V_163 &=
~ ( V_164 |
V_165 ) ;
F_60 ( V_14 -> V_52 -> V_37 -> V_108 ,
V_166 ,
& V_95 -> V_8 ) ;
}
}
V_159 -> V_80 . integer . V_16 = 0 ;
V_159 -> V_80 . integer . V_18 =
( V_14 -> V_18 - V_14 -> V_16 + V_14 -> V_47 - 1 ) / V_14 -> V_47 ;
}
return 0 ;
}
static int F_61 ( struct V_94 * V_95 , struct V_167 * V_168 )
{
struct V_13 * V_14 = V_95 -> V_98 ;
int V_169 , V_170 , V_39 , V_56 ;
V_168 -> V_80 . integer . V_80 [ 0 ] = V_14 -> V_16 ;
if ( V_14 -> V_150 ) {
V_170 = 0 ;
for ( V_169 = 0 ; V_169 < V_152 ; V_169 ++ ) {
if ( ! ( V_14 -> V_150 & ( 1 << V_169 ) ) )
continue;
V_56 = F_30 ( V_14 , V_169 + 1 , V_170 , & V_39 ) ;
if ( V_56 < 0 )
return V_14 -> V_52 -> V_84 ? 0 : V_56 ;
V_39 = F_13 ( V_14 , V_39 ) ;
V_168 -> V_80 . integer . V_80 [ V_170 ] = V_39 ;
V_170 ++ ;
}
return 0 ;
} else {
V_56 = F_30 ( V_14 , 0 , 0 , & V_39 ) ;
if ( V_56 < 0 )
return V_14 -> V_52 -> V_84 ? 0 : V_56 ;
V_39 = F_13 ( V_14 , V_39 ) ;
V_168 -> V_80 . integer . V_80 [ 0 ] = V_39 ;
}
return 0 ;
}
static int F_62 ( struct V_94 * V_95 , struct V_167 * V_168 )
{
struct V_13 * V_14 = V_95 -> V_98 ;
int V_169 , V_170 , V_39 , V_171 , V_56 ;
int V_172 = 0 ;
if ( V_14 -> V_150 ) {
V_170 = 0 ;
for ( V_169 = 0 ; V_169 < V_152 ; V_169 ++ ) {
if ( ! ( V_14 -> V_150 & ( 1 << V_169 ) ) )
continue;
V_56 = F_30 ( V_14 , V_169 + 1 , V_170 , & V_171 ) ;
if ( V_56 < 0 )
return V_14 -> V_52 -> V_84 ? 0 : V_56 ;
V_39 = V_168 -> V_80 . integer . V_80 [ V_170 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_171 != V_39 ) {
F_35 ( V_14 , V_169 + 1 , V_170 , V_39 ) ;
V_172 = 1 ;
}
V_170 ++ ;
}
} else {
V_56 = F_30 ( V_14 , 0 , 0 , & V_171 ) ;
if ( V_56 < 0 )
return V_14 -> V_52 -> V_84 ? 0 : V_56 ;
V_39 = V_168 -> V_80 . integer . V_80 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_171 ) {
F_35 ( V_14 , 0 , 0 , V_39 ) ;
V_172 = 1 ;
}
}
return V_172 ;
}
static T_3 F_63 ( struct V_94 * V_107 , const char * V_173 )
{
return F_64 ( V_107 -> V_8 . V_11 , V_173 , sizeof( V_107 -> V_8 . V_11 ) ) ;
}
static void F_65 ( struct V_94 * V_107 ,
struct V_174 * V_108 )
{
const char * V_175 [] = {
L_14 , L_30 , L_31 , L_32 , NULL } ;
const char * * V_176 ;
bool V_177 = 0 ;
if ( strcmp ( L_33 , V_107 -> V_8 . V_11 ) )
return;
for ( V_176 = V_175 ; * V_176 ; V_176 ++ )
if ( strstr ( V_108 -> V_178 , * V_176 ) ) {
V_177 = 1 ;
break;
}
if ( ! V_177 )
return;
F_3 ( V_107 -> V_8 . V_11 , L_31 , sizeof( V_107 -> V_8 . V_11 ) ) ;
}
static void F_66 ( struct V_2 * V_3 , void * V_179 ,
unsigned int V_180 , int V_5 ,
struct V_112 * V_113 , int V_4 ,
int V_181 )
{
struct V_26 * V_182 = V_179 ;
unsigned int V_36 = 0 ;
int V_183 = 0 ;
int V_184 = F_67 ( V_182 ) ;
struct V_94 * V_107 ;
struct V_13 * V_14 ;
const struct V_1 * V_7 ;
unsigned int V_185 ;
V_5 ++ ;
if ( V_5 == V_186 ) {
return;
}
V_7 = F_1 ( V_3 , V_4 , V_5 ) ;
if ( F_4 ( V_7 ) )
return;
V_14 = F_68 ( sizeof( * V_14 ) , V_187 ) ;
if ( ! V_14 ) {
F_26 ( V_64 L_34 ) ;
return;
}
V_14 -> V_52 = V_3 -> V_52 ;
V_14 -> V_8 = V_4 ;
V_14 -> V_5 = V_5 ;
V_14 -> V_150 = V_180 ;
V_14 -> V_40 = V_188 [ V_5 - 1 ] . type ;
if ( V_180 == 0 ) {
V_14 -> V_126 = 1 ;
V_14 -> V_90 = V_181 ;
} else {
int V_151 , V_169 = 0 ;
for ( V_151 = 0 ; V_151 < 16 ; V_151 ++ )
if ( V_180 & ( 1 << V_151 ) )
V_169 ++ ;
V_14 -> V_126 = V_169 ;
V_14 -> V_91 = V_181 ;
}
if ( V_14 -> V_126 == V_181 )
V_107 = F_69 ( & V_189 , V_14 ) ;
else
V_107 = F_69 ( & V_190 , V_14 ) ;
if ( ! V_107 ) {
F_26 ( V_64 L_34 ) ;
F_55 ( V_14 ) ;
return;
}
V_107 -> V_191 = F_54 ;
V_36 = F_2 ( V_7 , V_107 -> V_8 . V_11 , sizeof( V_107 -> V_8 . V_11 ) ) ;
V_183 = V_36 != 0 ;
if ( ! V_36 && V_184 )
V_36 = F_9 ( V_3 , V_184 ,
V_107 -> V_8 . V_11 , sizeof( V_107 -> V_8 . V_11 ) ) ;
switch ( V_5 ) {
case V_192 :
case V_193 :
if ( ! V_36 ) {
V_36 = F_43 ( V_3 , V_113 , V_107 -> V_8 . V_11 , sizeof( V_107 -> V_8 . V_11 ) , 1 ) ;
if ( ! V_36 )
V_36 = F_43 ( V_3 , & V_3 -> V_194 , V_107 -> V_8 . V_11 , sizeof( V_107 -> V_8 . V_11 ) , 1 ) ;
if ( ! V_36 )
V_36 = snprintf ( V_107 -> V_8 . V_11 , sizeof( V_107 -> V_8 . V_11 ) ,
L_35 , V_4 ) ;
}
if ( ! V_183 )
F_65 ( V_107 , V_3 -> V_52 -> V_37 -> V_108 ) ;
if ( ! V_183 && ! ( V_3 -> V_194 . type >> 16 ) ) {
if ( ( V_3 -> V_194 . type & 0xff00 ) == 0x0100 ) {
V_36 = F_63 ( V_107 , L_36 ) ;
} else {
V_36 = F_63 ( V_107 , L_37 ) ;
}
}
F_63 ( V_107 , V_5 == V_192 ?
L_38 : L_39 ) ;
break;
default:
if ( ! V_36 )
F_3 ( V_107 -> V_8 . V_11 , V_188 [ V_5 - 1 ] . V_11 ,
sizeof( V_107 -> V_8 . V_11 ) ) ;
break;
}
F_58 ( V_14 , 0 , V_107 ) ;
if ( V_5 == V_193 ) {
F_5 ( V_7 , V_14 ) ;
if ( V_14 -> V_15 < V_14 -> V_17 || ! V_14 -> V_19 ) {
V_107 -> V_195 . V_169 = F_36 ;
V_107 -> V_162 [ 0 ] . V_163 |=
V_164 |
V_165 ;
}
}
V_185 = ( V_14 -> V_18 - V_14 -> V_16 ) / V_14 -> V_47 ;
if ( V_185 > 384 ) {
F_26 ( V_87 L_40
L_41 ,
V_185 ) ;
F_26 ( V_87 L_42
L_43 , V_14 -> V_8 ,
V_107 -> V_8 . V_11 , V_14 -> V_126 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_47 ) ;
}
F_22 ( V_92 L_44 ,
V_14 -> V_8 , V_107 -> V_8 . V_11 , V_14 -> V_126 , V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_47 ) ;
F_40 ( V_3 -> V_52 , V_107 ) ;
}
static int F_70 ( struct V_2 * V_3 , int V_4 , void * V_196 )
{
int V_126 , V_151 , V_197 ;
struct V_112 V_113 ;
unsigned int V_198 , V_199 ;
int V_56 , V_200 ;
struct V_26 * V_27 = V_196 ;
T_1 * V_201 ;
if ( V_3 -> V_52 -> V_78 == V_79 ) {
V_200 = V_27 -> V_202 ;
if ( ! V_200 ) {
F_22 ( V_64 L_45
L_46 , V_4 ) ;
return - V_65 ;
}
V_126 = ( V_27 -> V_30 - 7 ) / V_200 - 1 ;
V_201 = V_27 -> V_201 ;
if ( V_27 -> V_30 < 7 + V_200 ) {
F_26 ( V_64 L_45
L_47 ,
V_4 ) ;
return - V_65 ;
}
} else {
struct V_203 * V_204 = V_196 ;
V_200 = 4 ;
V_126 = ( V_27 -> V_30 - 6 ) / 4 - 1 ;
V_201 = V_204 -> V_201 ;
if ( V_27 -> V_30 < 6 + V_200 ) {
F_26 ( V_64 L_45
L_47 ,
V_4 ) ;
return - V_65 ;
}
}
if ( ( V_56 = F_71 ( V_3 , V_27 -> V_135 ) ) < 0 )
return V_56 ;
if ( F_44 ( V_3 , V_27 -> V_135 , & V_113 ) < 0 )
return - V_65 ;
V_198 = F_21 ( V_201 , V_200 ) ;
switch ( V_3 -> V_37 -> V_147 ) {
case F_57 ( 0x08bb , 0x2702 ) :
F_26 ( V_92
L_48 ) ;
V_198 &= ~ F_72 ( V_193 ) ;
break;
case F_57 ( 0x1130 , 0xf211 ) :
F_26 ( V_92
L_49 ) ;
V_126 = 0 ;
break;
}
if ( V_126 > 0 )
V_199 = F_21 ( V_201 + V_200 , V_200 ) ;
else
V_199 = 0 ;
if ( V_3 -> V_52 -> V_78 == V_79 ) {
for ( V_151 = 0 ; V_151 < 10 ; V_151 ++ ) {
unsigned int V_205 = 0 ;
for ( V_197 = 0 ; V_197 < V_126 ; V_197 ++ ) {
unsigned int V_206 = F_21 ( V_201 + V_200 * ( V_197 + 1 ) , V_200 ) ;
if ( V_206 & ( 1 << V_151 ) )
V_205 |= ( 1 << V_197 ) ;
}
if ( V_205 & 1 )
F_66 ( V_3 , V_196 , V_205 , V_151 , & V_113 , V_4 , 0 ) ;
if ( V_198 & ( 1 << V_151 ) )
F_66 ( V_3 , V_196 , 0 , V_151 , & V_113 , V_4 , 0 ) ;
}
} else {
for ( V_151 = 0 ; V_151 < F_73 ( V_188 ) ; V_151 ++ ) {
unsigned int V_205 = 0 ;
unsigned int V_207 = 0 ;
for ( V_197 = 0 ; V_197 < V_126 ; V_197 ++ ) {
unsigned int V_206 = F_21 ( V_201 + V_200 * ( V_197 + 1 ) , V_200 ) ;
if ( F_74 ( V_206 , V_151 ) ) {
V_205 |= ( 1 << V_197 ) ;
if ( ! F_75 ( V_206 , V_151 ) )
V_207 |= ( 1 << V_197 ) ;
}
}
if ( V_205 & 1 )
F_66 ( V_3 , V_196 , V_205 , V_151 , & V_113 , V_4 , V_207 ) ;
if ( F_74 ( V_198 , V_151 ) )
F_66 ( V_3 , V_196 , 0 , V_151 , & V_113 , V_4 ,
! F_75 ( V_198 , V_151 ) ) ;
}
}
return 0 ;
}
static void F_76 ( struct V_2 * V_3 ,
struct V_136 * V_182 ,
int V_208 , int V_209 , int V_4 ,
struct V_112 * V_113 )
{
struct V_13 * V_14 ;
unsigned int V_105 = F_47 ( V_182 ) ;
unsigned int V_151 , V_36 ;
struct V_94 * V_107 ;
const struct V_1 * V_7 ;
V_7 = F_1 ( V_3 , V_4 , 0 ) ;
if ( F_4 ( V_7 ) )
return;
V_14 = F_68 ( sizeof( * V_14 ) , V_187 ) ;
if ( ! V_14 )
return;
V_14 -> V_52 = V_3 -> V_52 ;
V_14 -> V_8 = V_4 ;
V_14 -> V_5 = V_209 + 1 ;
V_14 -> V_40 = V_46 ;
for ( V_151 = 0 ; V_151 < V_105 ; V_151 ++ ) {
if ( F_39 ( F_77 ( V_182 , V_3 -> V_52 -> V_78 ) , V_209 , V_151 , V_105 ) ) {
V_14 -> V_150 |= ( 1 << V_151 ) ;
V_14 -> V_126 ++ ;
}
}
F_78 ( V_14 , 0 ) ;
V_107 = F_69 ( & V_190 , V_14 ) ;
if ( ! V_107 ) {
F_26 ( V_64 L_34 ) ;
F_55 ( V_14 ) ;
return;
}
V_107 -> V_191 = F_54 ;
V_36 = F_2 ( V_7 , V_107 -> V_8 . V_11 , sizeof( V_107 -> V_8 . V_11 ) ) ;
if ( ! V_36 )
V_36 = F_43 ( V_3 , V_113 , V_107 -> V_8 . V_11 , sizeof( V_107 -> V_8 . V_11 ) , 0 ) ;
if ( ! V_36 )
V_36 = sprintf ( V_107 -> V_8 . V_11 , L_50 , V_209 + 1 ) ;
F_63 ( V_107 , L_39 ) ;
F_22 ( V_92 L_51 ,
V_14 -> V_8 , V_107 -> V_8 . V_11 , V_14 -> V_126 , V_14 -> V_16 , V_14 -> V_18 ) ;
F_40 ( V_3 -> V_52 , V_107 ) ;
}
static int F_79 ( struct V_2 * V_3 , int V_4 , void * V_179 )
{
struct V_136 * V_182 = V_179 ;
struct V_112 V_113 ;
int V_210 , V_211 , V_105 ;
int V_212 , V_103 , V_56 ;
if ( V_182 -> V_30 < 11 || ! ( V_210 = V_182 -> V_143 ) || ! ( V_105 = F_47 ( V_182 ) ) ) {
F_26 ( V_64 L_52 , V_4 ) ;
return - V_65 ;
}
if ( V_182 -> V_30 <= 10 + V_210 ) {
F_22 ( V_92 L_53 , V_4 ) ;
return 0 ;
}
V_211 = 0 ;
V_103 = 0 ;
for ( V_212 = 0 ; V_212 < V_210 ; V_212 ++ ) {
V_56 = F_71 ( V_3 , V_182 -> V_139 [ V_212 ] ) ;
if ( V_56 < 0 )
continue;
V_56 = F_44 ( V_3 , V_182 -> V_139 [ V_212 ] , & V_113 ) ;
if ( V_56 < 0 )
return V_56 ;
V_211 += V_113 . V_126 ;
for (; V_103 < V_211 ; ++ V_103 ) {
int V_104 , V_213 = 0 ;
for ( V_104 = 0 ; V_104 < V_105 ; ++ V_104 ) {
if ( F_39 ( F_77 ( V_182 , V_3 -> V_52 -> V_78 ) ,
V_103 , V_104 , V_105 ) ) {
V_213 = 1 ;
break;
}
}
if ( V_213 )
F_76 ( V_3 , V_182 , V_212 , V_103 ,
V_4 , & V_113 ) ;
}
}
return 0 ;
}
static int F_80 ( struct V_94 * V_95 , struct V_167 * V_168 )
{
struct V_13 * V_14 = V_95 -> V_98 ;
int V_56 , V_39 ;
V_56 = F_28 ( V_14 , V_14 -> V_5 << 8 , & V_39 ) ;
if ( V_56 < 0 && V_14 -> V_52 -> V_84 ) {
V_168 -> V_80 . integer . V_80 [ 0 ] = V_14 -> V_16 ;
return 0 ;
}
if ( V_56 < 0 )
return V_56 ;
V_39 = F_13 ( V_14 , V_39 ) ;
V_168 -> V_80 . integer . V_80 [ 0 ] = V_39 ;
return 0 ;
}
static int F_81 ( struct V_94 * V_95 , struct V_167 * V_168 )
{
struct V_13 * V_14 = V_95 -> V_98 ;
int V_39 , V_171 , V_56 ;
V_56 = F_28 ( V_14 , V_14 -> V_5 << 8 , & V_171 ) ;
if ( V_56 < 0 ) {
if ( V_14 -> V_52 -> V_84 )
return 0 ;
return V_56 ;
}
V_39 = V_168 -> V_80 . integer . V_80 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_171 ) {
F_34 ( V_14 , V_14 -> V_5 << 8 , V_39 ) ;
return 1 ;
}
return 0 ;
}
static int F_82 ( struct V_2 * V_3 , int V_4 , void * V_179 , struct V_214 * V_215 , char * V_11 )
{
struct V_140 * V_182 = V_179 ;
int V_211 = V_182 -> V_143 ;
struct V_13 * V_14 ;
struct V_94 * V_107 ;
int V_151 , V_56 , V_184 , type , V_36 ;
struct V_214 * V_216 ;
struct V_217 * V_218 ;
const struct V_1 * V_7 ;
static struct V_217 V_219 [] = {
{ 0x01 , L_54 , V_41 } ,
{ 0 }
} ;
static struct V_214 V_220 = {
0 , NULL , V_219
} ;
if ( V_182 -> V_30 < 13 || V_182 -> V_30 < 13 + V_211 ||
V_182 -> V_30 < V_211 + F_83 ( V_182 , V_3 -> V_52 -> V_78 ) ) {
F_26 ( V_64 L_55 , V_11 , V_4 ) ;
return - V_65 ;
}
for ( V_151 = 0 ; V_151 < V_211 ; V_151 ++ ) {
if ( ( V_56 = F_71 ( V_3 , V_182 -> V_139 [ V_151 ] ) ) < 0 )
return V_56 ;
}
type = F_45 ( V_182 -> V_221 ) ;
for ( V_216 = V_215 ; V_216 && V_216 -> type ; V_216 ++ )
if ( V_216 -> type == type )
break;
if ( ! V_216 || ! V_216 -> type )
V_216 = & V_220 ;
for ( V_218 = V_216 -> V_222 ; V_218 -> V_5 ; V_218 ++ ) {
T_1 * V_223 = F_84 ( V_182 , V_3 -> V_52 -> V_78 ) ;
if ( ! ( V_223 [ V_218 -> V_5 / 8 ] & ( 1 << ( ( V_218 -> V_5 % 8 ) - 1 ) ) ) )
continue;
V_7 = F_1 ( V_3 , V_4 , V_218 -> V_5 ) ;
if ( F_4 ( V_7 ) )
continue;
V_14 = F_68 ( sizeof( * V_14 ) , V_187 ) ;
if ( ! V_14 ) {
F_26 ( V_64 L_34 ) ;
return - V_100 ;
}
V_14 -> V_52 = V_3 -> V_52 ;
V_14 -> V_8 = V_4 ;
V_14 -> V_5 = V_218 -> V_5 ;
V_14 -> V_40 = V_218 -> V_40 ;
V_14 -> V_126 = 1 ;
if ( type == V_224 && V_14 -> V_5 == V_225 ) {
T_1 * V_226 = F_85 ( V_182 , V_3 -> V_52 -> V_78 ) ;
V_14 -> V_16 = 1 ;
V_14 -> V_18 = V_226 [ 0 ] ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
} else {
if ( type == V_227 ) {
V_14 -> V_16 = 0 ;
V_14 -> V_18 = 5 ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
} else
F_78 ( V_14 , V_218 -> V_228 ) ;
}
V_107 = F_69 ( & V_229 , V_14 ) ;
if ( ! V_107 ) {
F_26 ( V_64 L_34 ) ;
F_55 ( V_14 ) ;
return - V_100 ;
}
V_107 -> V_191 = F_54 ;
if ( F_2 ( V_7 , V_107 -> V_8 . V_11 ,
sizeof( V_107 -> V_8 . V_11 ) ) )
;
else if ( V_216 -> V_11 )
F_3 ( V_107 -> V_8 . V_11 , V_216 -> V_11 , sizeof( V_107 -> V_8 . V_11 ) ) ;
else {
V_184 = F_53 ( V_182 , V_3 -> V_52 -> V_78 ) ;
V_36 = 0 ;
if ( V_184 )
V_36 = F_9 ( V_3 , V_184 , V_107 -> V_8 . V_11 , sizeof( V_107 -> V_8 . V_11 ) ) ;
if ( ! V_36 )
F_3 ( V_107 -> V_8 . V_11 , V_11 , sizeof( V_107 -> V_8 . V_11 ) ) ;
}
F_63 ( V_107 , L_56 ) ;
F_63 ( V_107 , V_218 -> V_230 ) ;
F_22 ( V_92 L_57 ,
V_14 -> V_8 , V_107 -> V_8 . V_11 , V_14 -> V_126 , V_14 -> V_16 , V_14 -> V_18 ) ;
if ( ( V_56 = F_40 ( V_3 -> V_52 , V_107 ) ) < 0 )
return V_56 ;
}
return 0 ;
}
static int F_86 ( struct V_2 * V_3 , int V_4 , void * V_179 )
{
return F_82 ( V_3 , V_4 , V_179 , V_231 , L_58 ) ;
}
static int F_87 ( struct V_2 * V_3 , int V_4 , void * V_179 )
{
return F_82 ( V_3 , V_4 , V_179 , V_232 , L_59 ) ;
}
static int F_88 ( struct V_94 * V_95 , struct V_158 * V_159 )
{
struct V_13 * V_14 = V_95 -> V_98 ;
const char * * V_233 = ( const char * * ) V_95 -> V_234 ;
if ( F_89 ( ! V_233 ) )
return - V_65 ;
return F_90 ( V_159 , 1 , V_14 -> V_18 , V_233 ) ;
}
static int F_91 ( struct V_94 * V_95 , struct V_167 * V_168 )
{
struct V_13 * V_14 = V_95 -> V_98 ;
int V_39 , V_56 ;
V_56 = F_28 ( V_14 , V_14 -> V_5 << 8 , & V_39 ) ;
if ( V_56 < 0 ) {
if ( V_14 -> V_52 -> V_84 ) {
V_168 -> V_80 . V_235 . V_236 [ 0 ] = 0 ;
return 0 ;
}
return V_56 ;
}
V_39 = F_13 ( V_14 , V_39 ) ;
V_168 -> V_80 . V_235 . V_236 [ 0 ] = V_39 ;
return 0 ;
}
static int F_92 ( struct V_94 * V_95 , struct V_167 * V_168 )
{
struct V_13 * V_14 = V_95 -> V_98 ;
int V_39 , V_171 , V_56 ;
V_56 = F_28 ( V_14 , V_14 -> V_5 << 8 , & V_171 ) ;
if ( V_56 < 0 ) {
if ( V_14 -> V_52 -> V_84 )
return 0 ;
return V_56 ;
}
V_39 = V_168 -> V_80 . V_235 . V_236 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_171 ) {
F_34 ( V_14 , V_14 -> V_5 << 8 , V_39 ) ;
return 1 ;
}
return 0 ;
}
static void F_93 ( struct V_94 * V_107 )
{
int V_151 , V_211 = 0 ;
if ( V_107 -> V_98 ) {
struct V_13 * V_14 = V_107 -> V_98 ;
V_211 = V_14 -> V_18 ;
F_55 ( V_14 ) ;
V_107 -> V_98 = NULL ;
}
if ( V_107 -> V_234 ) {
char * * V_233 = ( char * * ) V_107 -> V_234 ;
for ( V_151 = 0 ; V_151 < V_211 ; V_151 ++ )
F_55 ( V_233 [ V_151 ] ) ;
F_55 ( V_233 ) ;
V_107 -> V_234 = 0 ;
}
}
static int F_94 ( struct V_2 * V_3 , int V_4 , void * V_179 )
{
struct V_138 * V_182 = V_179 ;
unsigned int V_151 , V_184 , V_36 ;
int V_56 ;
struct V_13 * V_14 ;
struct V_94 * V_107 ;
const struct V_1 * V_7 ;
char * * V_237 ;
if ( ! V_182 -> V_143 || V_182 -> V_30 < 5 + V_182 -> V_143 ) {
F_26 ( V_64 L_60 , V_4 ) ;
return - V_65 ;
}
for ( V_151 = 0 ; V_151 < V_182 -> V_143 ; V_151 ++ ) {
if ( ( V_56 = F_71 ( V_3 , V_182 -> V_139 [ V_151 ] ) ) < 0 )
return V_56 ;
}
if ( V_182 -> V_143 == 1 )
return 0 ;
V_7 = F_1 ( V_3 , V_4 , 0 ) ;
if ( F_4 ( V_7 ) )
return 0 ;
V_14 = F_68 ( sizeof( * V_14 ) , V_187 ) ;
if ( ! V_14 ) {
F_26 ( V_64 L_34 ) ;
return - V_100 ;
}
V_14 -> V_52 = V_3 -> V_52 ;
V_14 -> V_8 = V_4 ;
V_14 -> V_40 = V_43 ;
V_14 -> V_126 = 1 ;
V_14 -> V_16 = 1 ;
V_14 -> V_18 = V_182 -> V_143 ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
if ( V_182 -> V_31 == V_137 )
V_14 -> V_5 = V_238 ;
else
V_14 -> V_5 = 0 ;
V_237 = F_95 ( sizeof( char * ) * V_182 -> V_143 , V_187 ) ;
if ( ! V_237 ) {
F_26 ( V_64 L_61 ) ;
F_55 ( V_14 ) ;
return - V_100 ;
}
#define F_96 64
for ( V_151 = 0 ; V_151 < V_182 -> V_143 ; V_151 ++ ) {
struct V_112 V_113 ;
V_36 = 0 ;
V_237 [ V_151 ] = F_95 ( F_96 , V_187 ) ;
if ( ! V_237 [ V_151 ] ) {
F_26 ( V_64 L_61 ) ;
while ( V_151 -- )
F_55 ( V_237 [ V_151 ] ) ;
F_55 ( V_237 ) ;
F_55 ( V_14 ) ;
return - V_100 ;
}
V_36 = F_6 ( V_3 , V_4 , V_151 , V_237 [ V_151 ] ,
F_96 ) ;
if ( ! V_36 && F_44 ( V_3 , V_182 -> V_139 [ V_151 ] , & V_113 ) >= 0 )
V_36 = F_43 ( V_3 , & V_113 , V_237 [ V_151 ] , F_96 , 0 ) ;
if ( ! V_36 )
sprintf ( V_237 [ V_151 ] , L_62 , V_151 ) ;
}
V_107 = F_69 ( & V_239 , V_14 ) ;
if ( ! V_107 ) {
F_26 ( V_64 L_34 ) ;
F_55 ( V_237 ) ;
F_55 ( V_14 ) ;
return - V_100 ;
}
V_107 -> V_234 = ( unsigned long ) V_237 ;
V_107 -> V_191 = F_93 ;
V_184 = F_50 ( V_182 ) ;
V_36 = F_2 ( V_7 , V_107 -> V_8 . V_11 , sizeof( V_107 -> V_8 . V_11 ) ) ;
if ( V_36 )
;
else if ( V_184 )
F_9 ( V_3 , V_184 , V_107 -> V_8 . V_11 , sizeof( V_107 -> V_8 . V_11 ) ) ;
else {
V_36 = F_43 ( V_3 , & V_3 -> V_194 ,
V_107 -> V_8 . V_11 , sizeof( V_107 -> V_8 . V_11 ) , 0 ) ;
if ( ! V_36 )
F_3 ( V_107 -> V_8 . V_11 , L_63 , sizeof( V_107 -> V_8 . V_11 ) ) ;
if ( V_182 -> V_31 == V_137 )
F_63 ( V_107 , L_64 ) ;
else if ( ( V_3 -> V_194 . type & 0xff00 ) == 0x0100 )
F_63 ( V_107 , L_65 ) ;
else
F_63 ( V_107 , L_66 ) ;
}
F_22 ( V_92 L_67 ,
V_14 -> V_8 , V_107 -> V_8 . V_11 , V_182 -> V_143 ) ;
if ( ( V_56 = F_40 ( V_3 -> V_52 , V_107 ) ) < 0 )
return V_56 ;
return 0 ;
}
static int F_71 ( struct V_2 * V_3 , int V_4 )
{
unsigned char * V_122 ;
if ( F_97 ( V_4 , V_3 -> V_240 ) )
return 0 ;
V_122 = F_7 ( V_3 , V_4 ) ;
if ( ! V_122 ) {
F_26 ( V_64 L_68 , V_4 ) ;
return - V_65 ;
}
switch ( V_122 [ 2 ] ) {
case V_32 :
case V_144 :
return 0 ;
case V_119 :
return F_79 ( V_3 , V_4 , V_122 ) ;
case V_116 :
case V_137 :
return F_94 ( V_3 , V_4 , V_122 ) ;
case V_134 :
return F_70 ( V_3 , V_4 , V_122 ) ;
case V_117 :
if ( V_3 -> V_52 -> V_78 == V_79 )
return F_86 ( V_3 , V_4 , V_122 ) ;
else
return 0 ;
case V_118 :
if ( V_3 -> V_52 -> V_78 == V_79 )
return F_87 ( V_3 , V_4 , V_122 ) ;
else
return F_86 ( V_3 , V_4 , V_122 ) ;
default:
F_26 ( V_64 L_69 , V_4 , V_122 [ 2 ] ) ;
return - V_65 ;
}
}
static void F_98 ( struct V_106 * V_52 )
{
F_55 ( V_52 -> V_111 ) ;
if ( V_52 -> V_241 ) {
F_55 ( V_52 -> V_241 -> V_242 ) ;
F_99 ( V_52 -> V_241 ) ;
}
F_99 ( V_52 -> V_243 ) ;
F_55 ( V_52 -> V_244 ) ;
F_55 ( V_52 ) ;
}
static int F_100 ( struct V_245 * V_246 )
{
struct V_106 * V_52 = V_246 -> V_247 ;
F_98 ( V_52 ) ;
return 0 ;
}
static int F_101 ( struct V_106 * V_52 )
{
struct V_2 V_3 ;
int V_56 ;
const struct V_248 * V_7 ;
void * V_6 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_37 = V_52 -> V_37 ;
V_3 . V_52 = V_52 ;
V_3 . V_28 = V_52 -> V_249 -> V_250 ;
V_3 . V_10 = V_52 -> V_249 -> V_251 ;
for ( V_7 = V_252 ; V_7 -> V_8 ; V_7 ++ ) {
if ( V_7 -> V_8 == V_3 . V_37 -> V_147 ) {
V_3 . V_7 = V_7 -> V_7 ;
V_3 . V_22 = V_7 -> V_22 ;
V_52 -> V_84 = V_7 -> V_84 ;
break;
}
}
V_6 = NULL ;
while ( ( V_6 = F_102 ( V_52 -> V_249 -> V_250 , V_52 -> V_249 -> V_251 ,
V_6 , V_253 ) ) != NULL ) {
if ( V_52 -> V_78 == V_79 ) {
struct V_254 * V_182 = V_6 ;
if ( V_182 -> V_30 < sizeof( * V_182 ) )
continue;
F_103 ( V_182 -> V_255 , V_3 . V_240 ) ;
V_3 . V_194 . V_8 = V_182 -> V_255 ;
V_3 . V_194 . type = F_45 ( V_182 -> V_125 ) ;
V_3 . V_194 . V_11 = V_182 -> V_130 ;
V_56 = F_71 ( & V_3 , V_182 -> V_135 ) ;
if ( V_56 < 0 )
return V_56 ;
} else {
struct V_256 * V_182 = V_6 ;
if ( V_182 -> V_30 < sizeof( * V_182 ) )
continue;
F_103 ( V_182 -> V_255 , V_3 . V_240 ) ;
V_3 . V_194 . V_8 = V_182 -> V_255 ;
V_3 . V_194 . type = F_45 ( V_182 -> V_125 ) ;
V_3 . V_194 . V_11 = V_182 -> V_130 ;
V_56 = F_71 ( & V_3 , V_182 -> V_135 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_71 ( & V_3 , V_182 -> V_133 ) ;
if ( V_56 < 0 )
return V_56 ;
}
}
return 0 ;
}
void F_104 ( struct V_106 * V_52 , int V_4 )
{
struct V_13 * V_216 ;
for ( V_216 = V_52 -> V_111 [ V_4 ] ; V_216 ; V_216 = V_216 -> V_110 )
F_60 ( V_52 -> V_37 -> V_108 , V_257 ,
V_216 -> V_109 ) ;
}
static void F_105 ( struct V_258 * V_28 ,
int V_4 ,
struct V_13 * V_14 )
{
static char * V_259 [] = { L_70 , L_71 ,
L_72 , L_73 , L_74 , L_75 } ;
F_106 ( V_28 , L_76 , V_4 ) ;
if ( V_14 -> V_109 )
F_106 ( V_28 , L_77 ,
V_14 -> V_109 -> V_11 , V_14 -> V_109 -> V_20 ) ;
F_106 ( V_28 , L_78
L_79 , V_14 -> V_8 ,
V_14 -> V_5 , V_14 -> V_150 , V_14 -> V_126 ,
V_259 [ V_14 -> V_40 ] ) ;
F_106 ( V_28 , L_80 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_15 , V_14 -> V_17 ) ;
}
static void F_107 ( struct V_260 * V_261 ,
struct V_258 * V_28 )
{
struct V_51 * V_37 = V_261 -> V_98 ;
struct V_106 * V_52 ;
struct V_13 * V_14 ;
int V_4 ;
F_108 (mixer, &chip->mixer_list, list) {
F_106 ( V_28 ,
L_81 ,
V_37 -> V_147 , F_18 ( V_37 ) ,
V_52 -> V_84 ) ;
F_106 ( V_28 , L_82 , V_37 -> V_108 -> V_262 ) ;
for ( V_4 = 0 ; V_4 < V_263 ; V_4 ++ ) {
for ( V_14 = V_52 -> V_111 [ V_4 ] ; V_14 ;
V_14 = V_14 -> V_110 )
F_105 ( V_28 , V_4 , V_14 ) ;
}
}
}
static void F_109 ( struct V_106 * V_52 ,
int V_264 , int V_80 , int V_20 )
{
struct V_13 * V_216 ;
T_1 V_4 = ( V_20 >> 8 ) & 0xff ;
T_1 V_5 = ( V_80 >> 8 ) & 0xff ;
T_1 V_81 = V_80 & 0xff ;
if ( V_81 >= V_152 ) {
F_26 ( V_265 L_83 ,
V_93 , V_81 ) ;
return;
}
for ( V_216 = V_52 -> V_111 [ V_4 ] ; V_216 ; V_216 = V_216 -> V_110 ) {
if ( V_216 -> V_5 != V_5 )
continue;
switch ( V_264 ) {
case V_71 :
if ( V_81 )
V_216 -> V_82 &= ~ ( 1 << V_81 ) ;
else
V_216 -> V_82 = 0 ;
F_60 ( V_52 -> V_37 -> V_108 , V_257 ,
V_216 -> V_109 ) ;
break;
case V_72 :
break;
case V_266 :
break;
default:
F_26 ( V_265 L_84 ,
V_264 ) ;
break;
}
}
}
static void F_110 ( struct V_241 * V_241 )
{
struct V_106 * V_52 = V_241 -> V_267 ;
int V_36 = V_241 -> V_268 ;
int V_269 = V_241 -> V_270 ;
if ( V_269 != 0 )
goto V_271;
if ( V_52 -> V_78 == V_79 ) {
struct V_272 * V_270 ;
for ( V_270 = V_241 -> V_242 ;
V_36 >= sizeof( * V_270 ) ;
V_36 -= sizeof( * V_270 ) , V_270 ++ ) {
F_31 ( V_265 L_85 ,
V_270 -> V_273 ,
V_270 -> V_274 ) ;
if ( ( V_270 -> V_273 & V_275 ) !=
V_276 )
continue;
if ( V_270 -> V_273 & V_277 )
F_111 ( V_52 , V_270 -> V_274 ) ;
else
F_104 ( V_52 , V_270 -> V_274 ) ;
}
} else {
struct V_278 * V_279 ;
for ( V_279 = V_241 -> V_242 ;
V_36 >= sizeof( * V_279 ) ;
V_36 -= sizeof( * V_279 ) , V_279 ++ ) {
if ( ( V_279 -> V_280 & V_281 ) ||
( V_279 -> V_280 & V_282 ) )
continue;
F_109 ( V_52 , V_279 -> V_283 ,
F_45 ( V_279 -> V_284 ) ,
F_45 ( V_279 -> V_285 ) ) ;
}
}
V_271:
if ( V_269 != - V_286 && V_269 != - V_287 && V_269 != - V_288 ) {
V_241 -> V_38 = V_52 -> V_37 -> V_38 ;
F_112 ( V_241 , V_289 ) ;
}
}
void F_113 ( struct V_106 * V_52 )
{
F_114 ( V_52 -> V_241 ) ;
F_114 ( V_52 -> V_243 ) ;
}
int F_115 ( struct V_106 * V_52 )
{
int V_56 ;
if ( V_52 -> V_241 ) {
V_56 = F_112 ( V_52 -> V_241 , V_290 ) ;
if ( V_56 < 0 )
return V_56 ;
}
return 0 ;
}
static int F_116 ( struct V_106 * V_52 )
{
struct V_291 * V_292 ;
void * V_242 ;
int V_293 ;
unsigned int V_294 ;
if ( F_117 ( V_52 -> V_249 ) -> V_295 < 1 )
return 0 ;
V_292 = F_118 ( V_52 -> V_249 , 0 ) ;
if ( ! F_119 ( V_292 ) || ! F_120 ( V_292 ) )
return 0 ;
V_294 = F_121 ( V_292 ) ;
V_293 = F_45 ( V_292 -> V_296 ) ;
V_242 = F_95 ( V_293 , V_187 ) ;
if ( ! V_242 )
return - V_100 ;
V_52 -> V_241 = F_122 ( 0 , V_187 ) ;
if ( ! V_52 -> V_241 ) {
F_55 ( V_242 ) ;
return - V_100 ;
}
F_123 ( V_52 -> V_241 , V_52 -> V_37 -> V_38 ,
F_124 ( V_52 -> V_37 -> V_38 , V_294 ) ,
V_242 , V_293 ,
F_110 , V_52 , V_292 -> V_297 ) ;
F_112 ( V_52 -> V_241 , V_187 ) ;
return 0 ;
}
int F_125 ( struct V_51 * V_37 , int V_298 ,
int V_299 )
{
static struct V_300 V_301 = {
. V_302 = F_100
} ;
struct V_106 * V_52 ;
struct V_260 * V_261 ;
int V_56 ;
strcpy ( V_37 -> V_108 -> V_303 , L_86 ) ;
V_52 = F_68 ( sizeof( * V_52 ) , V_187 ) ;
if ( ! V_52 )
return - V_100 ;
V_52 -> V_37 = V_37 ;
V_52 -> V_84 = V_299 ;
V_52 -> V_111 = F_126 ( V_263 , sizeof( * V_52 -> V_111 ) ,
V_187 ) ;
if ( ! V_52 -> V_111 ) {
F_55 ( V_52 ) ;
return - V_100 ;
}
V_52 -> V_249 = & F_127 ( V_37 -> V_38 , V_298 ) -> V_304 [ 0 ] ;
switch ( F_117 ( V_52 -> V_249 ) -> V_305 ) {
case V_79 :
default:
V_52 -> V_78 = V_79 ;
break;
case V_141 :
V_52 -> V_78 = V_141 ;
break;
}
if ( ( V_56 = F_101 ( V_52 ) ) < 0 ||
( V_56 = F_116 ( V_52 ) ) < 0 )
goto V_306;
F_128 ( V_52 ) ;
V_56 = F_129 ( V_37 -> V_108 , V_307 , V_52 , & V_301 ) ;
if ( V_56 < 0 )
goto V_306;
if ( F_130 ( & V_37 -> V_308 ) &&
! F_131 ( V_37 -> V_108 , L_87 , & V_261 ) )
F_132 ( V_261 , V_37 , F_107 ) ;
F_133 ( & V_52 -> V_215 , & V_37 -> V_308 ) ;
return 0 ;
V_306:
F_98 ( V_52 ) ;
return V_56 ;
}
void F_134 ( struct V_309 * V_6 )
{
struct V_106 * V_52 ;
V_52 = F_135 ( V_6 , struct V_106 , V_215 ) ;
F_114 ( V_52 -> V_241 ) ;
F_114 ( V_52 -> V_243 ) ;
}
