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
return ( V_14 -> V_52 -> V_77 == V_78 ) ?
F_15 ( V_14 , V_48 , V_49 , V_50 ) :
F_25 ( V_14 , V_48 , V_49 , V_50 ) ;
}
static int F_28 ( struct V_13 * V_14 , int V_49 , int * V_79 )
{
return F_27 ( V_14 , V_70 , V_49 , V_79 ) ;
}
static inline int F_29 ( struct V_13 * V_14 ,
int V_80 , int * V_79 )
{
return F_27 ( V_14 , V_70 , ( V_14 -> V_5 << 8 ) | V_80 , V_79 ) ;
}
static int F_30 ( struct V_13 * V_14 ,
int V_80 , int V_20 , int * V_79 )
{
int V_56 ;
if ( V_14 -> V_81 & ( 1 << V_80 ) ) {
* V_79 = V_14 -> V_82 [ V_20 ] ;
return 0 ;
}
V_56 = F_29 ( V_14 , V_80 , V_79 ) ;
if ( V_56 < 0 ) {
if ( ! V_14 -> V_52 -> V_83 )
F_31 ( V_64 L_2 ,
V_14 -> V_5 , V_80 , V_56 ) ;
return V_56 ;
}
V_14 -> V_81 |= 1 << V_80 ;
V_14 -> V_82 [ V_20 ] = * V_79 ;
return 0 ;
}
int F_32 ( struct V_13 * V_14 ,
int V_48 , int V_49 , int V_84 )
{
struct V_51 * V_37 = V_14 -> V_52 -> V_37 ;
unsigned char V_9 [ 2 ] ;
int V_55 = 0 , V_53 , V_56 , V_54 = 10 ;
if ( V_14 -> V_52 -> V_77 == V_78 ) {
V_53 = V_14 -> V_40 >= V_46 ? 2 : 1 ;
} else {
V_53 = sizeof( V_66 ) ;
if ( V_48 != V_85 ) {
F_22 ( V_86 L_3 ) ;
return - V_65 ;
}
V_48 = V_71 ;
}
V_84 = F_12 ( V_14 , V_84 ) ;
V_9 [ 0 ] = V_84 & 0xff ;
V_9 [ 1 ] = ( V_84 >> 8 ) & 0xff ;
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
V_60 | V_61 | V_87 ,
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
static int F_34 ( struct V_13 * V_14 , int V_49 , int V_79 )
{
return F_32 ( V_14 , V_85 , V_49 , V_79 ) ;
}
static int F_35 ( struct V_13 * V_14 , int V_80 ,
int V_20 , int V_79 )
{
int V_56 ;
unsigned int V_88 = ( V_80 == 0 ) ?
V_14 -> V_89 :
V_14 -> V_90 & ( 1 << ( V_80 - 1 ) ) ;
if ( V_88 ) {
F_22 ( V_91 L_5 ,
V_92 , V_80 , V_14 -> V_5 ) ;
return 0 ;
}
V_56 = F_32 ( V_14 , V_85 , ( V_14 -> V_5 << 8 ) | V_80 ,
V_79 ) ;
if ( V_56 < 0 )
return V_56 ;
V_14 -> V_81 |= 1 << V_80 ;
V_14 -> V_82 [ V_20 ] = V_79 ;
return 0 ;
}
int F_36 ( struct V_93 * V_94 , int V_95 ,
unsigned int V_68 , unsigned int T_2 * V_96 )
{
struct V_13 * V_14 = V_94 -> V_97 ;
F_37 ( V_98 , 0 , 0 ) ;
if ( V_68 < sizeof( V_98 ) )
return - V_99 ;
V_98 [ 2 ] = V_14 -> V_15 ;
V_98 [ 3 ] = V_14 -> V_17 ;
if ( F_38 ( V_96 , V_98 , sizeof( V_98 ) ) )
return - V_100 ;
return 0 ;
}
static int F_39 ( unsigned char * V_101 , int V_102 , int V_103 , int V_104 )
{
int V_55 = V_102 * V_104 + V_103 ;
return V_101 [ V_55 >> 3 ] & ( 0x80 >> ( V_55 & 7 ) ) ;
}
int F_40 ( struct V_105 * V_52 ,
struct V_93 * V_106 )
{
struct V_13 * V_14 = V_106 -> V_97 ;
int V_56 ;
while ( F_41 ( V_52 -> V_37 -> V_107 , & V_106 -> V_8 ) )
V_106 -> V_8 . V_20 ++ ;
if ( ( V_56 = F_42 ( V_52 -> V_37 -> V_107 , V_106 ) ) < 0 ) {
F_31 ( V_64 L_6 , V_56 ) ;
return V_56 ;
}
V_14 -> V_108 = & V_106 -> V_8 ;
V_14 -> V_109 = V_52 -> V_110 [ V_14 -> V_8 ] ;
V_52 -> V_110 [ V_14 -> V_8 ] = V_14 ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 , struct V_111 * V_112 ,
unsigned char * V_11 , int V_35 , int V_113 )
{
struct V_114 * V_24 ;
if ( V_112 -> V_11 )
return F_9 ( V_3 , V_112 -> V_11 , V_11 , V_35 ) ;
if ( V_112 -> type >> 16 ) {
if ( V_113 )
return 0 ;
switch ( V_112 -> type >> 16 ) {
case V_115 :
strcpy ( V_11 , L_7 ) ; return 8 ;
case V_116 :
strcpy ( V_11 , L_8 ) ; return 12 ;
case V_117 :
strcpy ( V_11 , L_9 ) ; return 8 ;
case V_118 :
strcpy ( V_11 , L_10 ) ; return 5 ;
default:
return sprintf ( V_11 , L_11 , V_112 -> V_8 ) ;
}
}
switch ( V_112 -> type & 0xff00 ) {
case 0x0100 :
strcpy ( V_11 , L_12 ) ; return 3 ;
case 0x0200 :
strcpy ( V_11 , L_13 ) ; return 3 ;
case 0x0400 :
strcpy ( V_11 , L_14 ) ; return 7 ;
case 0x0500 :
strcpy ( V_11 , L_15 ) ; return 5 ;
}
for ( V_24 = V_119 ; V_24 -> type ; V_24 ++ )
if ( V_24 -> type == V_112 -> type ) {
strcpy ( V_11 , V_24 -> V_11 ) ;
return strlen ( V_24 -> V_11 ) ;
}
return 0 ;
}
static int F_44 ( struct V_2 * V_3 , int V_8 , struct V_111 * V_120 )
{
int V_56 ;
void * V_121 ;
memset ( V_120 , 0 , sizeof( * V_120 ) ) ;
while ( ( V_121 = F_7 ( V_3 , V_8 ) ) != NULL ) {
unsigned char * V_27 = V_121 ;
V_120 -> V_8 = V_8 ;
switch ( V_27 [ 2 ] ) {
case V_32 :
if ( V_3 -> V_52 -> V_77 == V_78 ) {
struct V_122 * V_123 = V_121 ;
V_120 -> type = F_45 ( V_123 -> V_124 ) ;
V_120 -> V_125 = V_123 -> V_126 ;
V_120 -> V_127 = F_45 ( V_123 -> V_128 ) ;
V_120 -> V_11 = V_123 -> V_129 ;
} else {
struct V_130 * V_123 = V_121 ;
V_120 -> type = F_45 ( V_123 -> V_124 ) ;
V_120 -> V_125 = V_123 -> V_126 ;
V_120 -> V_127 = F_46 ( V_123 -> V_131 ) ;
V_120 -> V_11 = V_123 -> V_129 ;
V_56 = F_44 ( V_3 , V_123 -> V_132 , V_120 ) ;
if ( V_56 < 0 )
return V_56 ;
}
return 0 ;
case V_133 : {
struct V_26 * V_123 = V_121 ;
V_8 = V_123 -> V_134 ;
break;
}
case V_118 : {
struct V_135 * V_123 = V_121 ;
V_120 -> type = V_123 -> V_31 << 16 ;
V_120 -> V_125 = F_47 ( V_123 ) ;
V_120 -> V_127 = F_48 ( V_123 , V_3 -> V_52 -> V_77 ) ;
V_120 -> V_11 = F_49 ( V_123 ) ;
return 0 ;
}
case V_115 :
case V_136 : {
struct V_137 * V_123 = V_121 ;
if ( F_44 ( V_3 , V_123 -> V_138 [ 0 ] , V_120 ) < 0 )
return - V_73 ;
V_120 -> type = V_123 -> V_31 << 16 ;
V_120 -> V_8 = V_8 ;
V_120 -> V_11 = F_50 ( V_123 ) ;
return 0 ;
}
case V_116 :
case V_117 : {
struct V_139 * V_123 = V_121 ;
if ( V_123 -> V_140 ) {
V_8 = V_123 -> V_138 [ 0 ] ;
break;
}
V_120 -> type = V_123 -> V_31 << 16 ;
V_120 -> V_125 = F_51 ( V_123 ) ;
V_120 -> V_127 = F_52 ( V_123 , V_3 -> V_52 -> V_77 ) ;
V_120 -> V_11 = F_53 ( V_123 , V_3 -> V_52 -> V_77 ) ;
return 0 ;
}
case V_141 : {
struct V_142 * V_123 = V_121 ;
V_120 -> type = V_123 -> V_31 << 16 ;
V_120 -> V_8 = V_8 ;
V_120 -> V_11 = V_123 -> V_143 ;
return 0 ;
}
default:
return - V_73 ;
}
}
return - V_73 ;
}
static void F_54 ( struct V_93 * V_106 )
{
F_55 ( V_106 -> V_97 ) ;
V_106 -> V_97 = NULL ;
}
static void F_56 ( struct V_13 * V_14 ,
struct V_93 * V_106 )
{
switch ( V_14 -> V_52 -> V_37 -> V_144 ) {
case F_57 ( 0x0763 , 0x2081 ) :
case F_57 ( 0x0763 , 0x2080 ) :
if ( strcmp ( V_106 -> V_8 . V_11 , L_16 ) == 0 ) {
F_26 ( V_91
L_17 ) ;
V_14 -> V_16 = 0x0000 ;
V_14 -> V_18 = 0x7f00 ;
V_14 -> V_47 = 0x0100 ;
break;
}
if ( strcmp ( V_106 -> V_8 . V_11 , L_18 ) == 0 ||
strcmp ( V_106 -> V_8 . V_11 , L_19 ) == 0 ) {
F_26 ( V_91
L_20 ) ;
V_14 -> V_16 = 0x00 ;
V_14 -> V_18 = 0x7f ;
break;
}
break;
case F_57 ( 0x0471 , 0x0101 ) :
case F_57 ( 0x0471 , 0x0104 ) :
case F_57 ( 0x0471 , 0x0105 ) :
case F_57 ( 0x0672 , 0x1041 ) :
if ( ! strcmp ( V_106 -> V_8 . V_11 , L_21 ) &&
V_14 -> V_16 == - 15616 ) {
F_26 ( V_91
L_22 ) ;
V_14 -> V_18 = - 256 ;
}
break;
case F_57 ( 0x046d , 0x09a4 ) :
if ( ! strcmp ( V_106 -> V_8 . V_11 , L_23 ) ) {
F_26 ( V_91
L_24 ) ;
V_14 -> V_16 = 6080 ;
V_14 -> V_18 = 8768 ;
V_14 -> V_47 = 192 ;
}
break;
case F_57 ( 0x046d , 0x0808 ) :
case F_57 ( 0x046d , 0x0809 ) :
case F_57 ( 0x046d , 0x081d ) :
case F_57 ( 0x046d , 0x0991 ) :
if ( ! strcmp ( V_106 -> V_8 . V_11 , L_23 ) ) {
F_26 ( V_91
L_25 ) ;
V_14 -> V_47 = 384 ;
}
break;
}
}
static int F_58 ( struct V_13 * V_14 ,
int V_145 , struct V_93 * V_106 )
{
V_14 -> V_16 = V_145 ;
V_14 -> V_18 = V_14 -> V_16 + 1 ;
V_14 -> V_47 = 1 ;
V_14 -> V_15 = V_14 -> V_17 = 0 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 ) {
V_14 -> V_19 = 1 ;
} else {
int V_146 = 0 ;
if ( V_14 -> V_147 ) {
int V_148 ;
for ( V_148 = 0 ; V_148 < V_149 ; V_148 ++ )
if ( V_14 -> V_147 & ( 1 << V_148 ) ) {
V_146 = V_148 + 1 ;
break;
}
}
if ( F_27 ( V_14 , V_75 , ( V_14 -> V_5 << 8 ) | V_146 , & V_14 -> V_18 ) < 0 ||
F_27 ( V_14 , V_74 , ( V_14 -> V_5 << 8 ) | V_146 , & V_14 -> V_16 ) < 0 ) {
F_31 ( V_64 L_26 ,
V_14 -> V_8 , F_18 ( V_14 -> V_52 -> V_37 ) , V_14 -> V_5 , V_14 -> V_8 ) ;
return - V_65 ;
}
if ( F_27 ( V_14 , V_76 , ( V_14 -> V_5 << 8 ) | V_146 , & V_14 -> V_47 ) < 0 ) {
V_14 -> V_47 = 1 ;
} else {
int V_150 = V_14 -> V_47 ;
while ( V_14 -> V_47 > 1 ) {
if ( F_32 ( V_14 , V_151 ,
( V_14 -> V_5 << 8 ) | V_146 , V_14 -> V_47 / 2 ) < 0 )
break;
V_14 -> V_47 /= 2 ;
}
if ( F_27 ( V_14 , V_76 , ( V_14 -> V_5 << 8 ) | V_146 , & V_14 -> V_47 ) < 0 )
V_14 -> V_47 = V_150 ;
}
if ( V_14 -> V_47 == 0 )
V_14 -> V_47 = 1 ;
if ( V_14 -> V_16 + V_14 -> V_47 < V_14 -> V_18 ) {
int V_150 = V_14 -> V_47 ;
int V_152 , V_153 , V_154 ;
F_29 ( V_14 , V_146 , & V_152 ) ;
for (; ; ) {
V_153 = V_152 ;
if ( V_153 < V_14 -> V_18 )
V_153 += V_14 -> V_47 ;
else
V_153 -= V_14 -> V_47 ;
if ( V_153 < V_14 -> V_16 || V_153 > V_14 -> V_18 ||
F_35 ( V_14 , V_146 , 0 , V_153 ) ||
F_29 ( V_14 , V_146 , & V_154 ) ) {
V_14 -> V_47 = V_150 ;
break;
}
if ( V_153 == V_154 )
break;
V_14 -> V_47 *= 2 ;
}
F_35 ( V_14 , V_146 , 0 , V_152 ) ;
}
V_14 -> V_19 = 1 ;
}
if ( V_106 )
F_56 ( V_14 , V_106 ) ;
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
static int F_59 ( struct V_93 * V_94 , struct V_155 * V_156 )
{
struct V_13 * V_14 = V_94 -> V_97 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 )
V_156 -> type = V_157 ;
else
V_156 -> type = V_158 ;
V_156 -> V_23 = V_14 -> V_125 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 ) {
V_156 -> V_79 . integer . V_16 = 0 ;
V_156 -> V_79 . integer . V_18 = 1 ;
} else {
if ( ! V_14 -> V_19 ) {
F_58 ( V_14 , 0 , V_94 ) ;
if ( V_14 -> V_19 && V_14 -> V_15 >= V_14 -> V_17 ) {
V_94 -> V_159 [ 0 ] . V_160 &=
~ ( V_161 |
V_162 ) ;
F_60 ( V_14 -> V_52 -> V_37 -> V_107 ,
V_163 ,
& V_94 -> V_8 ) ;
}
}
V_156 -> V_79 . integer . V_16 = 0 ;
V_156 -> V_79 . integer . V_18 =
( V_14 -> V_18 - V_14 -> V_16 + V_14 -> V_47 - 1 ) / V_14 -> V_47 ;
}
return 0 ;
}
static int F_61 ( struct V_93 * V_94 , struct V_164 * V_165 )
{
struct V_13 * V_14 = V_94 -> V_97 ;
int V_166 , V_167 , V_39 , V_56 ;
V_165 -> V_79 . integer . V_79 [ 0 ] = V_14 -> V_16 ;
if ( V_14 -> V_147 ) {
V_167 = 0 ;
for ( V_166 = 0 ; V_166 < V_149 ; V_166 ++ ) {
if ( ! ( V_14 -> V_147 & ( 1 << V_166 ) ) )
continue;
V_56 = F_30 ( V_14 , V_166 + 1 , V_167 , & V_39 ) ;
if ( V_56 < 0 )
return V_14 -> V_52 -> V_83 ? 0 : V_56 ;
V_39 = F_13 ( V_14 , V_39 ) ;
V_165 -> V_79 . integer . V_79 [ V_167 ] = V_39 ;
V_167 ++ ;
}
return 0 ;
} else {
V_56 = F_30 ( V_14 , 0 , 0 , & V_39 ) ;
if ( V_56 < 0 )
return V_14 -> V_52 -> V_83 ? 0 : V_56 ;
V_39 = F_13 ( V_14 , V_39 ) ;
V_165 -> V_79 . integer . V_79 [ 0 ] = V_39 ;
}
return 0 ;
}
static int F_62 ( struct V_93 * V_94 , struct V_164 * V_165 )
{
struct V_13 * V_14 = V_94 -> V_97 ;
int V_166 , V_167 , V_39 , V_168 , V_56 ;
int V_169 = 0 ;
if ( V_14 -> V_147 ) {
V_167 = 0 ;
for ( V_166 = 0 ; V_166 < V_149 ; V_166 ++ ) {
if ( ! ( V_14 -> V_147 & ( 1 << V_166 ) ) )
continue;
V_56 = F_30 ( V_14 , V_166 + 1 , V_167 , & V_168 ) ;
if ( V_56 < 0 )
return V_14 -> V_52 -> V_83 ? 0 : V_56 ;
V_39 = V_165 -> V_79 . integer . V_79 [ V_167 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_168 != V_39 ) {
F_35 ( V_14 , V_166 + 1 , V_167 , V_39 ) ;
V_169 = 1 ;
}
V_167 ++ ;
}
} else {
V_56 = F_30 ( V_14 , 0 , 0 , & V_168 ) ;
if ( V_56 < 0 )
return V_14 -> V_52 -> V_83 ? 0 : V_56 ;
V_39 = V_165 -> V_79 . integer . V_79 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_168 ) {
F_35 ( V_14 , 0 , 0 , V_39 ) ;
V_169 = 1 ;
}
}
return V_169 ;
}
static T_3 F_63 ( struct V_93 * V_106 , const char * V_170 )
{
return F_64 ( V_106 -> V_8 . V_11 , V_170 , sizeof( V_106 -> V_8 . V_11 ) ) ;
}
static void F_65 ( struct V_2 * V_3 , void * V_171 ,
unsigned int V_172 , int V_5 ,
struct V_111 * V_112 , int V_4 ,
int V_173 )
{
struct V_26 * V_174 = V_171 ;
unsigned int V_36 = 0 ;
int V_175 = 0 ;
int V_176 = F_66 ( V_174 ) ;
struct V_93 * V_106 ;
struct V_13 * V_14 ;
const struct V_1 * V_7 ;
unsigned int V_177 ;
V_5 ++ ;
if ( V_5 == V_178 ) {
return;
}
V_7 = F_1 ( V_3 , V_4 , V_5 ) ;
if ( F_4 ( V_7 ) )
return;
V_14 = F_67 ( sizeof( * V_14 ) , V_179 ) ;
if ( ! V_14 ) {
F_26 ( V_64 L_27 ) ;
return;
}
V_14 -> V_52 = V_3 -> V_52 ;
V_14 -> V_8 = V_4 ;
V_14 -> V_5 = V_5 ;
V_14 -> V_147 = V_172 ;
V_14 -> V_40 = V_180 [ V_5 - 1 ] . type ;
if ( V_172 == 0 ) {
V_14 -> V_125 = 1 ;
V_14 -> V_89 = V_173 ;
} else {
int V_148 , V_166 = 0 ;
for ( V_148 = 0 ; V_148 < 16 ; V_148 ++ )
if ( V_172 & ( 1 << V_148 ) )
V_166 ++ ;
V_14 -> V_125 = V_166 ;
V_14 -> V_90 = V_173 ;
}
if ( V_14 -> V_125 == V_173 )
V_106 = F_68 ( & V_181 , V_14 ) ;
else
V_106 = F_68 ( & V_182 , V_14 ) ;
if ( ! V_106 ) {
F_26 ( V_64 L_27 ) ;
F_55 ( V_14 ) ;
return;
}
V_106 -> V_183 = F_54 ;
V_36 = F_2 ( V_7 , V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) ) ;
V_175 = V_36 != 0 ;
if ( ! V_36 && V_176 )
V_36 = F_9 ( V_3 , V_176 ,
V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) ) ;
switch ( V_5 ) {
case V_184 :
case V_185 :
if ( ! V_36 ) {
V_36 = F_43 ( V_3 , V_112 , V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) , 1 ) ;
if ( ! V_36 )
V_36 = F_43 ( V_3 , & V_3 -> V_186 , V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) , 1 ) ;
if ( ! V_36 )
V_36 = snprintf ( V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) ,
L_28 , V_4 ) ;
}
if ( ! V_175 && ! ( V_3 -> V_186 . type >> 16 ) ) {
if ( ( V_3 -> V_186 . type & 0xff00 ) == 0x0100 ) {
V_36 = F_63 ( V_106 , L_29 ) ;
} else {
V_36 = F_63 ( V_106 , L_30 ) ;
}
}
F_63 ( V_106 , V_5 == V_184 ?
L_31 : L_32 ) ;
break;
default:
if ( ! V_36 )
F_3 ( V_106 -> V_8 . V_11 , V_180 [ V_5 - 1 ] . V_11 ,
sizeof( V_106 -> V_8 . V_11 ) ) ;
break;
}
F_58 ( V_14 , 0 , V_106 ) ;
if ( V_5 == V_185 ) {
F_5 ( V_7 , V_14 ) ;
if ( V_14 -> V_15 < V_14 -> V_17 || ! V_14 -> V_19 ) {
V_106 -> V_187 . V_166 = F_36 ;
V_106 -> V_159 [ 0 ] . V_160 |=
V_161 |
V_162 ;
}
}
V_177 = ( V_14 -> V_18 - V_14 -> V_16 ) / V_14 -> V_47 ;
if ( V_177 > 384 ) {
F_26 ( V_86 L_33
L_34 ,
V_177 ) ;
F_26 ( V_86 L_35
L_36 , V_14 -> V_8 ,
V_106 -> V_8 . V_11 , V_14 -> V_125 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_47 ) ;
}
F_22 ( V_91 L_37 ,
V_14 -> V_8 , V_106 -> V_8 . V_11 , V_14 -> V_125 , V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_47 ) ;
F_40 ( V_3 -> V_52 , V_106 ) ;
}
static int F_69 ( struct V_2 * V_3 , int V_4 , void * V_188 )
{
int V_125 , V_148 , V_189 ;
struct V_111 V_112 ;
unsigned int V_190 , V_191 ;
int V_56 , V_192 ;
struct V_26 * V_27 = V_188 ;
T_1 * V_193 ;
if ( V_3 -> V_52 -> V_77 == V_78 ) {
V_192 = V_27 -> V_194 ;
if ( ! V_192 ) {
F_22 ( V_64 L_38
L_39 , V_4 ) ;
return - V_65 ;
}
V_125 = ( V_27 -> V_30 - 7 ) / V_192 - 1 ;
V_193 = V_27 -> V_193 ;
} else {
struct V_195 * V_196 = V_188 ;
V_192 = 4 ;
V_125 = ( V_27 -> V_30 - 6 ) / 4 - 1 ;
V_193 = V_196 -> V_193 ;
}
if ( V_27 -> V_30 < 7 || ! V_192 || V_27 -> V_30 < 7 + V_192 ) {
F_26 ( V_64 L_40 , V_4 ) ;
return - V_65 ;
}
if ( ( V_56 = F_70 ( V_3 , V_27 -> V_134 ) ) < 0 )
return V_56 ;
if ( F_44 ( V_3 , V_27 -> V_134 , & V_112 ) < 0 )
return - V_65 ;
V_190 = F_21 ( V_193 , V_192 ) ;
switch ( V_3 -> V_37 -> V_144 ) {
case F_57 ( 0x08bb , 0x2702 ) :
F_26 ( V_91
L_41 ) ;
V_190 &= ~ F_71 ( V_185 ) ;
break;
case F_57 ( 0x1130 , 0xf211 ) :
F_26 ( V_91
L_42 ) ;
V_125 = 0 ;
break;
}
if ( V_125 > 0 )
V_191 = F_21 ( V_193 + V_192 , V_192 ) ;
else
V_191 = 0 ;
if ( V_3 -> V_52 -> V_77 == V_78 ) {
for ( V_148 = 0 ; V_148 < 10 ; V_148 ++ ) {
unsigned int V_197 = 0 ;
for ( V_189 = 0 ; V_189 < V_125 ; V_189 ++ ) {
unsigned int V_198 = F_21 ( V_193 + V_192 * ( V_189 + 1 ) , V_192 ) ;
if ( V_198 & ( 1 << V_148 ) )
V_197 |= ( 1 << V_189 ) ;
}
if ( V_197 & 1 )
F_65 ( V_3 , V_188 , V_197 , V_148 , & V_112 , V_4 , 0 ) ;
if ( V_190 & ( 1 << V_148 ) )
F_65 ( V_3 , V_188 , 0 , V_148 , & V_112 , V_4 , 0 ) ;
}
} else {
for ( V_148 = 0 ; V_148 < F_72 ( V_180 ) ; V_148 ++ ) {
unsigned int V_197 = 0 ;
unsigned int V_199 = 0 ;
for ( V_189 = 0 ; V_189 < V_125 ; V_189 ++ ) {
unsigned int V_198 = F_21 ( V_193 + V_192 * ( V_189 + 1 ) , V_192 ) ;
if ( F_73 ( V_198 , V_148 ) ) {
V_197 |= ( 1 << V_189 ) ;
if ( ! F_74 ( V_198 , V_148 ) )
V_199 |= ( 1 << V_189 ) ;
}
}
if ( V_197 & 1 )
F_65 ( V_3 , V_188 , V_197 , V_148 , & V_112 , V_4 , V_199 ) ;
if ( F_73 ( V_190 , V_148 ) )
F_65 ( V_3 , V_188 , 0 , V_148 , & V_112 , V_4 ,
! F_74 ( V_190 , V_148 ) ) ;
}
}
return 0 ;
}
static void F_75 ( struct V_2 * V_3 ,
struct V_135 * V_174 ,
int V_200 , int V_201 , int V_4 ,
struct V_111 * V_112 )
{
struct V_13 * V_14 ;
unsigned int V_104 = F_47 ( V_174 ) ;
unsigned int V_148 , V_36 ;
struct V_93 * V_106 ;
const struct V_1 * V_7 ;
V_7 = F_1 ( V_3 , V_4 , 0 ) ;
if ( F_4 ( V_7 ) )
return;
V_14 = F_67 ( sizeof( * V_14 ) , V_179 ) ;
if ( ! V_14 )
return;
V_14 -> V_52 = V_3 -> V_52 ;
V_14 -> V_8 = V_4 ;
V_14 -> V_5 = V_201 + 1 ;
V_14 -> V_40 = V_46 ;
for ( V_148 = 0 ; V_148 < V_104 ; V_148 ++ ) {
if ( F_39 ( F_76 ( V_174 , V_3 -> V_52 -> V_77 ) , V_201 , V_148 , V_104 ) ) {
V_14 -> V_147 |= ( 1 << V_148 ) ;
V_14 -> V_125 ++ ;
}
}
F_77 ( V_14 , 0 ) ;
V_106 = F_68 ( & V_182 , V_14 ) ;
if ( ! V_106 ) {
F_26 ( V_64 L_27 ) ;
F_55 ( V_14 ) ;
return;
}
V_106 -> V_183 = F_54 ;
V_36 = F_2 ( V_7 , V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) ) ;
if ( ! V_36 )
V_36 = F_43 ( V_3 , V_112 , V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) , 0 ) ;
if ( ! V_36 )
V_36 = sprintf ( V_106 -> V_8 . V_11 , L_43 , V_201 + 1 ) ;
F_63 ( V_106 , L_32 ) ;
F_22 ( V_91 L_44 ,
V_14 -> V_8 , V_106 -> V_8 . V_11 , V_14 -> V_125 , V_14 -> V_16 , V_14 -> V_18 ) ;
F_40 ( V_3 -> V_52 , V_106 ) ;
}
static int F_78 ( struct V_2 * V_3 , int V_4 , void * V_171 )
{
struct V_135 * V_174 = V_171 ;
struct V_111 V_112 ;
int V_202 , V_203 , V_104 ;
int V_204 , V_102 , V_56 ;
if ( V_174 -> V_30 < 11 || ! ( V_202 = V_174 -> V_140 ) || ! ( V_104 = F_47 ( V_174 ) ) ) {
F_26 ( V_64 L_45 , V_4 ) ;
return - V_65 ;
}
if ( V_174 -> V_30 <= 10 + V_202 ) {
F_22 ( V_91 L_46 , V_4 ) ;
return 0 ;
}
V_203 = 0 ;
V_102 = 0 ;
for ( V_204 = 0 ; V_204 < V_202 ; V_204 ++ ) {
V_56 = F_70 ( V_3 , V_174 -> V_138 [ V_204 ] ) ;
if ( V_56 < 0 )
continue;
V_56 = F_44 ( V_3 , V_174 -> V_138 [ V_204 ] , & V_112 ) ;
if ( V_56 < 0 )
return V_56 ;
V_203 += V_112 . V_125 ;
for (; V_102 < V_203 ; ++ V_102 ) {
int V_103 , V_205 = 0 ;
for ( V_103 = 0 ; V_103 < V_104 ; ++ V_103 ) {
if ( F_39 ( F_76 ( V_174 , V_3 -> V_52 -> V_77 ) ,
V_102 , V_103 , V_104 ) ) {
V_205 = 1 ;
break;
}
}
if ( V_205 )
F_75 ( V_3 , V_174 , V_204 , V_102 ,
V_4 , & V_112 ) ;
}
}
return 0 ;
}
static int F_79 ( struct V_93 * V_94 , struct V_164 * V_165 )
{
struct V_13 * V_14 = V_94 -> V_97 ;
int V_56 , V_39 ;
V_56 = F_28 ( V_14 , V_14 -> V_5 << 8 , & V_39 ) ;
if ( V_56 < 0 && V_14 -> V_52 -> V_83 ) {
V_165 -> V_79 . integer . V_79 [ 0 ] = V_14 -> V_16 ;
return 0 ;
}
if ( V_56 < 0 )
return V_56 ;
V_39 = F_13 ( V_14 , V_39 ) ;
V_165 -> V_79 . integer . V_79 [ 0 ] = V_39 ;
return 0 ;
}
static int F_80 ( struct V_93 * V_94 , struct V_164 * V_165 )
{
struct V_13 * V_14 = V_94 -> V_97 ;
int V_39 , V_168 , V_56 ;
V_56 = F_28 ( V_14 , V_14 -> V_5 << 8 , & V_168 ) ;
if ( V_56 < 0 ) {
if ( V_14 -> V_52 -> V_83 )
return 0 ;
return V_56 ;
}
V_39 = V_165 -> V_79 . integer . V_79 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_168 ) {
F_34 ( V_14 , V_14 -> V_5 << 8 , V_39 ) ;
return 1 ;
}
return 0 ;
}
static int F_81 ( struct V_2 * V_3 , int V_4 , void * V_171 , struct V_206 * V_207 , char * V_11 )
{
struct V_139 * V_174 = V_171 ;
int V_203 = V_174 -> V_140 ;
struct V_13 * V_14 ;
struct V_93 * V_106 ;
int V_148 , V_56 , V_176 , type , V_36 ;
struct V_206 * V_208 ;
struct V_209 * V_210 ;
const struct V_1 * V_7 ;
static struct V_209 V_211 [] = {
{ 0x01 , L_47 , V_41 } ,
{ 0 }
} ;
static struct V_206 V_212 = {
0 , NULL , V_211
} ;
if ( V_174 -> V_30 < 13 || V_174 -> V_30 < 13 + V_203 ||
V_174 -> V_30 < V_203 + F_82 ( V_174 , V_3 -> V_52 -> V_77 ) ) {
F_26 ( V_64 L_48 , V_11 , V_4 ) ;
return - V_65 ;
}
for ( V_148 = 0 ; V_148 < V_203 ; V_148 ++ ) {
if ( ( V_56 = F_70 ( V_3 , V_174 -> V_138 [ V_148 ] ) ) < 0 )
return V_56 ;
}
type = F_45 ( V_174 -> V_213 ) ;
for ( V_208 = V_207 ; V_208 && V_208 -> type ; V_208 ++ )
if ( V_208 -> type == type )
break;
if ( ! V_208 || ! V_208 -> type )
V_208 = & V_212 ;
for ( V_210 = V_208 -> V_214 ; V_210 -> V_5 ; V_210 ++ ) {
T_1 * V_215 = F_83 ( V_174 , V_3 -> V_52 -> V_77 ) ;
if ( ! ( V_215 [ V_210 -> V_5 / 8 ] & ( 1 << ( ( V_210 -> V_5 % 8 ) - 1 ) ) ) )
continue;
V_7 = F_1 ( V_3 , V_4 , V_210 -> V_5 ) ;
if ( F_4 ( V_7 ) )
continue;
V_14 = F_67 ( sizeof( * V_14 ) , V_179 ) ;
if ( ! V_14 ) {
F_26 ( V_64 L_27 ) ;
return - V_99 ;
}
V_14 -> V_52 = V_3 -> V_52 ;
V_14 -> V_8 = V_4 ;
V_14 -> V_5 = V_210 -> V_5 ;
V_14 -> V_40 = V_210 -> V_40 ;
V_14 -> V_125 = 1 ;
if ( type == V_216 && V_14 -> V_5 == V_217 ) {
T_1 * V_218 = F_84 ( V_174 , V_3 -> V_52 -> V_77 ) ;
V_14 -> V_16 = 1 ;
V_14 -> V_18 = V_218 [ 0 ] ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
} else {
if ( type == V_219 ) {
V_14 -> V_16 = 0 ;
V_14 -> V_18 = 5 ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
} else
F_77 ( V_14 , V_210 -> V_220 ) ;
}
V_106 = F_68 ( & V_221 , V_14 ) ;
if ( ! V_106 ) {
F_26 ( V_64 L_27 ) ;
F_55 ( V_14 ) ;
return - V_99 ;
}
V_106 -> V_183 = F_54 ;
if ( F_2 ( V_7 , V_106 -> V_8 . V_11 ,
sizeof( V_106 -> V_8 . V_11 ) ) )
;
else if ( V_208 -> V_11 )
F_3 ( V_106 -> V_8 . V_11 , V_208 -> V_11 , sizeof( V_106 -> V_8 . V_11 ) ) ;
else {
V_176 = F_53 ( V_174 , V_3 -> V_52 -> V_77 ) ;
V_36 = 0 ;
if ( V_176 )
V_36 = F_9 ( V_3 , V_176 , V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) ) ;
if ( ! V_36 )
F_3 ( V_106 -> V_8 . V_11 , V_11 , sizeof( V_106 -> V_8 . V_11 ) ) ;
}
F_63 ( V_106 , L_49 ) ;
F_63 ( V_106 , V_210 -> V_222 ) ;
F_22 ( V_91 L_50 ,
V_14 -> V_8 , V_106 -> V_8 . V_11 , V_14 -> V_125 , V_14 -> V_16 , V_14 -> V_18 ) ;
if ( ( V_56 = F_40 ( V_3 -> V_52 , V_106 ) ) < 0 )
return V_56 ;
}
return 0 ;
}
static int F_85 ( struct V_2 * V_3 , int V_4 , void * V_171 )
{
return F_81 ( V_3 , V_4 , V_171 , V_223 , L_51 ) ;
}
static int F_86 ( struct V_2 * V_3 , int V_4 , void * V_171 )
{
return F_81 ( V_3 , V_4 , V_171 , V_224 , L_52 ) ;
}
static int F_87 ( struct V_93 * V_94 , struct V_155 * V_156 )
{
struct V_13 * V_14 = V_94 -> V_97 ;
const char * * V_225 = ( const char * * ) V_94 -> V_226 ;
if ( F_88 ( ! V_225 ) )
return - V_65 ;
return F_89 ( V_156 , 1 , V_14 -> V_18 , V_225 ) ;
}
static int F_90 ( struct V_93 * V_94 , struct V_164 * V_165 )
{
struct V_13 * V_14 = V_94 -> V_97 ;
int V_39 , V_56 ;
V_56 = F_28 ( V_14 , V_14 -> V_5 << 8 , & V_39 ) ;
if ( V_56 < 0 ) {
if ( V_14 -> V_52 -> V_83 ) {
V_165 -> V_79 . V_227 . V_228 [ 0 ] = 0 ;
return 0 ;
}
return V_56 ;
}
V_39 = F_13 ( V_14 , V_39 ) ;
V_165 -> V_79 . V_227 . V_228 [ 0 ] = V_39 ;
return 0 ;
}
static int F_91 ( struct V_93 * V_94 , struct V_164 * V_165 )
{
struct V_13 * V_14 = V_94 -> V_97 ;
int V_39 , V_168 , V_56 ;
V_56 = F_28 ( V_14 , V_14 -> V_5 << 8 , & V_168 ) ;
if ( V_56 < 0 ) {
if ( V_14 -> V_52 -> V_83 )
return 0 ;
return V_56 ;
}
V_39 = V_165 -> V_79 . V_227 . V_228 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_168 ) {
F_34 ( V_14 , V_14 -> V_5 << 8 , V_39 ) ;
return 1 ;
}
return 0 ;
}
static void F_92 ( struct V_93 * V_106 )
{
int V_148 , V_203 = 0 ;
if ( V_106 -> V_97 ) {
struct V_13 * V_14 = V_106 -> V_97 ;
V_203 = V_14 -> V_18 ;
F_55 ( V_14 ) ;
V_106 -> V_97 = NULL ;
}
if ( V_106 -> V_226 ) {
char * * V_225 = ( char * * ) V_106 -> V_226 ;
for ( V_148 = 0 ; V_148 < V_203 ; V_148 ++ )
F_55 ( V_225 [ V_148 ] ) ;
F_55 ( V_225 ) ;
V_106 -> V_226 = 0 ;
}
}
static int F_93 ( struct V_2 * V_3 , int V_4 , void * V_171 )
{
struct V_137 * V_174 = V_171 ;
unsigned int V_148 , V_176 , V_36 ;
int V_56 ;
struct V_13 * V_14 ;
struct V_93 * V_106 ;
const struct V_1 * V_7 ;
char * * V_229 ;
if ( ! V_174 -> V_140 || V_174 -> V_30 < 5 + V_174 -> V_140 ) {
F_26 ( V_64 L_53 , V_4 ) ;
return - V_65 ;
}
for ( V_148 = 0 ; V_148 < V_174 -> V_140 ; V_148 ++ ) {
if ( ( V_56 = F_70 ( V_3 , V_174 -> V_138 [ V_148 ] ) ) < 0 )
return V_56 ;
}
if ( V_174 -> V_140 == 1 )
return 0 ;
V_7 = F_1 ( V_3 , V_4 , 0 ) ;
if ( F_4 ( V_7 ) )
return 0 ;
V_14 = F_67 ( sizeof( * V_14 ) , V_179 ) ;
if ( ! V_14 ) {
F_26 ( V_64 L_27 ) ;
return - V_99 ;
}
V_14 -> V_52 = V_3 -> V_52 ;
V_14 -> V_8 = V_4 ;
V_14 -> V_40 = V_43 ;
V_14 -> V_125 = 1 ;
V_14 -> V_16 = 1 ;
V_14 -> V_18 = V_174 -> V_140 ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
if ( V_174 -> V_31 == V_136 )
V_14 -> V_5 = V_230 ;
else
V_14 -> V_5 = 0 ;
V_229 = F_94 ( sizeof( char * ) * V_174 -> V_140 , V_179 ) ;
if ( ! V_229 ) {
F_26 ( V_64 L_54 ) ;
F_55 ( V_14 ) ;
return - V_99 ;
}
#define F_95 64
for ( V_148 = 0 ; V_148 < V_174 -> V_140 ; V_148 ++ ) {
struct V_111 V_112 ;
V_36 = 0 ;
V_229 [ V_148 ] = F_94 ( F_95 , V_179 ) ;
if ( ! V_229 [ V_148 ] ) {
F_26 ( V_64 L_54 ) ;
while ( V_148 -- )
F_55 ( V_229 [ V_148 ] ) ;
F_55 ( V_229 ) ;
F_55 ( V_14 ) ;
return - V_99 ;
}
V_36 = F_6 ( V_3 , V_4 , V_148 , V_229 [ V_148 ] ,
F_95 ) ;
if ( ! V_36 && F_44 ( V_3 , V_174 -> V_138 [ V_148 ] , & V_112 ) >= 0 )
V_36 = F_43 ( V_3 , & V_112 , V_229 [ V_148 ] , F_95 , 0 ) ;
if ( ! V_36 )
sprintf ( V_229 [ V_148 ] , L_55 , V_148 ) ;
}
V_106 = F_68 ( & V_231 , V_14 ) ;
if ( ! V_106 ) {
F_26 ( V_64 L_27 ) ;
F_55 ( V_229 ) ;
F_55 ( V_14 ) ;
return - V_99 ;
}
V_106 -> V_226 = ( unsigned long ) V_229 ;
V_106 -> V_183 = F_92 ;
V_176 = F_50 ( V_174 ) ;
V_36 = F_2 ( V_7 , V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) ) ;
if ( V_36 )
;
else if ( V_176 )
F_9 ( V_3 , V_176 , V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) ) ;
else {
V_36 = F_43 ( V_3 , & V_3 -> V_186 ,
V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) , 0 ) ;
if ( ! V_36 )
F_3 ( V_106 -> V_8 . V_11 , L_56 , sizeof( V_106 -> V_8 . V_11 ) ) ;
if ( V_174 -> V_31 == V_136 )
F_63 ( V_106 , L_57 ) ;
else if ( ( V_3 -> V_186 . type & 0xff00 ) == 0x0100 )
F_63 ( V_106 , L_58 ) ;
else
F_63 ( V_106 , L_59 ) ;
}
F_22 ( V_91 L_60 ,
V_14 -> V_8 , V_106 -> V_8 . V_11 , V_174 -> V_140 ) ;
if ( ( V_56 = F_40 ( V_3 -> V_52 , V_106 ) ) < 0 )
return V_56 ;
return 0 ;
}
static int F_70 ( struct V_2 * V_3 , int V_4 )
{
unsigned char * V_121 ;
if ( F_96 ( V_4 , V_3 -> V_232 ) )
return 0 ;
V_121 = F_7 ( V_3 , V_4 ) ;
if ( ! V_121 ) {
F_26 ( V_64 L_61 , V_4 ) ;
return - V_65 ;
}
switch ( V_121 [ 2 ] ) {
case V_32 :
case V_141 :
return 0 ;
case V_118 :
return F_78 ( V_3 , V_4 , V_121 ) ;
case V_115 :
case V_136 :
return F_93 ( V_3 , V_4 , V_121 ) ;
case V_133 :
return F_69 ( V_3 , V_4 , V_121 ) ;
case V_116 :
if ( V_3 -> V_52 -> V_77 == V_78 )
return F_85 ( V_3 , V_4 , V_121 ) ;
else
return 0 ;
case V_117 :
if ( V_3 -> V_52 -> V_77 == V_78 )
return F_86 ( V_3 , V_4 , V_121 ) ;
else
return F_85 ( V_3 , V_4 , V_121 ) ;
default:
F_26 ( V_64 L_62 , V_4 , V_121 [ 2 ] ) ;
return - V_65 ;
}
}
static void F_97 ( struct V_105 * V_52 )
{
F_55 ( V_52 -> V_110 ) ;
if ( V_52 -> V_233 ) {
F_55 ( V_52 -> V_233 -> V_234 ) ;
F_98 ( V_52 -> V_233 ) ;
}
F_98 ( V_52 -> V_235 ) ;
F_55 ( V_52 -> V_236 ) ;
F_55 ( V_52 ) ;
}
static int F_99 ( struct V_237 * V_238 )
{
struct V_105 * V_52 = V_238 -> V_239 ;
F_97 ( V_52 ) ;
return 0 ;
}
static int F_100 ( struct V_105 * V_52 )
{
struct V_2 V_3 ;
int V_56 ;
const struct V_240 * V_7 ;
void * V_6 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_37 = V_52 -> V_37 ;
V_3 . V_52 = V_52 ;
V_3 . V_28 = V_52 -> V_241 -> V_242 ;
V_3 . V_10 = V_52 -> V_241 -> V_243 ;
for ( V_7 = V_244 ; V_7 -> V_8 ; V_7 ++ ) {
if ( V_7 -> V_8 == V_3 . V_37 -> V_144 ) {
V_3 . V_7 = V_7 -> V_7 ;
V_3 . V_22 = V_7 -> V_22 ;
V_52 -> V_83 = V_7 -> V_83 ;
break;
}
}
V_6 = NULL ;
while ( ( V_6 = F_101 ( V_52 -> V_241 -> V_242 , V_52 -> V_241 -> V_243 ,
V_6 , V_245 ) ) != NULL ) {
if ( V_52 -> V_77 == V_78 ) {
struct V_246 * V_174 = V_6 ;
if ( V_174 -> V_30 < sizeof( * V_174 ) )
continue;
F_102 ( V_174 -> V_247 , V_3 . V_232 ) ;
V_3 . V_186 . V_8 = V_174 -> V_247 ;
V_3 . V_186 . type = F_45 ( V_174 -> V_124 ) ;
V_3 . V_186 . V_11 = V_174 -> V_129 ;
V_56 = F_70 ( & V_3 , V_174 -> V_134 ) ;
if ( V_56 < 0 )
return V_56 ;
} else {
struct V_248 * V_174 = V_6 ;
if ( V_174 -> V_30 < sizeof( * V_174 ) )
continue;
F_102 ( V_174 -> V_247 , V_3 . V_232 ) ;
V_3 . V_186 . V_8 = V_174 -> V_247 ;
V_3 . V_186 . type = F_45 ( V_174 -> V_124 ) ;
V_3 . V_186 . V_11 = V_174 -> V_129 ;
V_56 = F_70 ( & V_3 , V_174 -> V_134 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_70 ( & V_3 , V_174 -> V_132 ) ;
if ( V_56 < 0 )
return V_56 ;
}
}
return 0 ;
}
void F_103 ( struct V_105 * V_52 , int V_4 )
{
struct V_13 * V_208 ;
for ( V_208 = V_52 -> V_110 [ V_4 ] ; V_208 ; V_208 = V_208 -> V_109 )
F_60 ( V_52 -> V_37 -> V_107 , V_249 ,
V_208 -> V_108 ) ;
}
static void F_104 ( struct V_250 * V_28 ,
int V_4 ,
struct V_13 * V_14 )
{
static char * V_251 [] = { L_63 , L_64 ,
L_65 , L_66 , L_67 , L_68 } ;
F_105 ( V_28 , L_69 , V_4 ) ;
if ( V_14 -> V_108 )
F_105 ( V_28 , L_70 ,
V_14 -> V_108 -> V_11 , V_14 -> V_108 -> V_20 ) ;
F_105 ( V_28 , L_71
L_72 , V_14 -> V_8 ,
V_14 -> V_5 , V_14 -> V_147 , V_14 -> V_125 ,
V_251 [ V_14 -> V_40 ] ) ;
F_105 ( V_28 , L_73 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_15 , V_14 -> V_17 ) ;
}
static void F_106 ( struct V_252 * V_253 ,
struct V_250 * V_28 )
{
struct V_51 * V_37 = V_253 -> V_97 ;
struct V_105 * V_52 ;
struct V_13 * V_14 ;
int V_4 ;
F_107 (mixer, &chip->mixer_list, list) {
F_105 ( V_28 ,
L_74 ,
V_37 -> V_144 , F_18 ( V_37 ) ,
V_52 -> V_83 ) ;
F_105 ( V_28 , L_75 , V_37 -> V_107 -> V_254 ) ;
for ( V_4 = 0 ; V_4 < V_255 ; V_4 ++ ) {
for ( V_14 = V_52 -> V_110 [ V_4 ] ; V_14 ;
V_14 = V_14 -> V_109 )
F_104 ( V_28 , V_4 , V_14 ) ;
}
}
}
static void F_108 ( struct V_105 * V_52 ,
int V_256 , int V_79 , int V_20 )
{
struct V_13 * V_208 ;
T_1 V_4 = ( V_20 >> 8 ) & 0xff ;
T_1 V_5 = ( V_79 >> 8 ) & 0xff ;
T_1 V_80 = V_79 & 0xff ;
if ( V_80 >= V_149 ) {
F_26 ( V_257 L_76 ,
V_92 , V_80 ) ;
return;
}
for ( V_208 = V_52 -> V_110 [ V_4 ] ; V_208 ; V_208 = V_208 -> V_109 ) {
if ( V_208 -> V_5 != V_5 )
continue;
switch ( V_256 ) {
case V_71 :
if ( V_80 )
V_208 -> V_81 &= ~ ( 1 << V_80 ) ;
else
V_208 -> V_81 = 0 ;
F_60 ( V_52 -> V_37 -> V_107 , V_249 ,
V_208 -> V_108 ) ;
break;
case V_72 :
break;
case V_258 :
break;
default:
F_26 ( V_257 L_77 ,
V_256 ) ;
break;
}
}
}
static void F_109 ( struct V_233 * V_233 )
{
struct V_105 * V_52 = V_233 -> V_259 ;
int V_36 = V_233 -> V_260 ;
int V_261 = V_233 -> V_262 ;
if ( V_261 != 0 )
goto V_263;
if ( V_52 -> V_77 == V_78 ) {
struct V_264 * V_262 ;
for ( V_262 = V_233 -> V_234 ;
V_36 >= sizeof( * V_262 ) ;
V_36 -= sizeof( * V_262 ) , V_262 ++ ) {
F_31 ( V_257 L_78 ,
V_262 -> V_265 ,
V_262 -> V_266 ) ;
if ( ( V_262 -> V_265 & V_267 ) !=
V_268 )
continue;
if ( V_262 -> V_265 & V_269 )
F_110 ( V_52 , V_262 -> V_266 ) ;
else
F_103 ( V_52 , V_262 -> V_266 ) ;
}
} else {
struct V_270 * V_271 ;
for ( V_271 = V_233 -> V_234 ;
V_36 >= sizeof( * V_271 ) ;
V_36 -= sizeof( * V_271 ) , V_271 ++ ) {
if ( ( V_271 -> V_272 & V_273 ) ||
( V_271 -> V_272 & V_274 ) )
continue;
F_108 ( V_52 , V_271 -> V_275 ,
F_45 ( V_271 -> V_276 ) ,
F_45 ( V_271 -> V_277 ) ) ;
}
}
V_263:
if ( V_261 != - V_278 && V_261 != - V_279 && V_261 != - V_280 ) {
V_233 -> V_38 = V_52 -> V_37 -> V_38 ;
F_111 ( V_233 , V_281 ) ;
}
}
void F_112 ( struct V_105 * V_52 )
{
F_113 ( V_52 -> V_233 ) ;
F_113 ( V_52 -> V_235 ) ;
}
int F_114 ( struct V_105 * V_52 )
{
int V_56 ;
if ( V_52 -> V_233 ) {
V_56 = F_111 ( V_52 -> V_233 , V_282 ) ;
if ( V_56 < 0 )
return V_56 ;
}
return 0 ;
}
static int F_115 ( struct V_105 * V_52 )
{
struct V_283 * V_284 ;
void * V_234 ;
int V_285 ;
unsigned int V_286 ;
if ( F_116 ( V_52 -> V_241 ) -> V_287 < 1 )
return 0 ;
V_284 = F_117 ( V_52 -> V_241 , 0 ) ;
if ( ! F_118 ( V_284 ) || ! F_119 ( V_284 ) )
return 0 ;
V_286 = F_120 ( V_284 ) ;
V_285 = F_45 ( V_284 -> V_288 ) ;
V_234 = F_94 ( V_285 , V_179 ) ;
if ( ! V_234 )
return - V_99 ;
V_52 -> V_233 = F_121 ( 0 , V_179 ) ;
if ( ! V_52 -> V_233 ) {
F_55 ( V_234 ) ;
return - V_99 ;
}
F_122 ( V_52 -> V_233 , V_52 -> V_37 -> V_38 ,
F_123 ( V_52 -> V_37 -> V_38 , V_286 ) ,
V_234 , V_285 ,
F_109 , V_52 , V_284 -> V_289 ) ;
F_111 ( V_52 -> V_233 , V_179 ) ;
return 0 ;
}
int F_124 ( struct V_51 * V_37 , int V_290 ,
int V_291 )
{
static struct V_292 V_293 = {
. V_294 = F_99
} ;
struct V_105 * V_52 ;
struct V_252 * V_253 ;
int V_56 ;
strcpy ( V_37 -> V_107 -> V_295 , L_79 ) ;
V_52 = F_67 ( sizeof( * V_52 ) , V_179 ) ;
if ( ! V_52 )
return - V_99 ;
V_52 -> V_37 = V_37 ;
V_52 -> V_83 = V_291 ;
V_52 -> V_110 = F_125 ( V_255 , sizeof( * V_52 -> V_110 ) ,
V_179 ) ;
if ( ! V_52 -> V_110 ) {
F_55 ( V_52 ) ;
return - V_99 ;
}
V_52 -> V_241 = & F_126 ( V_37 -> V_38 , V_290 ) -> V_296 [ 0 ] ;
switch ( F_116 ( V_52 -> V_241 ) -> V_297 ) {
case V_78 :
default:
V_52 -> V_77 = V_78 ;
break;
case V_298 :
V_52 -> V_77 = V_298 ;
break;
}
if ( ( V_56 = F_100 ( V_52 ) ) < 0 ||
( V_56 = F_115 ( V_52 ) ) < 0 )
goto V_299;
F_127 ( V_52 ) ;
V_56 = F_128 ( V_37 -> V_107 , V_300 , V_52 , & V_293 ) ;
if ( V_56 < 0 )
goto V_299;
if ( F_129 ( & V_37 -> V_301 ) &&
! F_130 ( V_37 -> V_107 , L_80 , & V_253 ) )
F_131 ( V_253 , V_37 , F_106 ) ;
F_132 ( & V_52 -> V_207 , & V_37 -> V_301 ) ;
return 0 ;
V_299:
F_97 ( V_52 ) ;
return V_56 ;
}
void F_133 ( struct V_302 * V_6 )
{
struct V_105 * V_52 ;
V_52 = F_134 ( V_6 , struct V_105 , V_207 ) ;
F_113 ( V_52 -> V_233 ) ;
F_113 ( V_52 -> V_235 ) ;
}
