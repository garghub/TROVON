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
}
}
static int F_6 ( struct V_2 * V_3 , int V_4 ,
int V_19 , char * V_9 , int V_10 )
{
const struct V_20 * V_6 ;
if ( ! V_3 -> V_21 )
return 0 ;
for ( V_6 = V_3 -> V_21 ; V_6 -> V_8 ; V_6 ++ ) {
if ( V_6 -> V_8 == V_4 && V_19 < V_6 -> V_22 )
return F_3 ( V_9 , V_6 -> V_23 [ V_19 ] , V_10 ) ;
}
return 0 ;
}
static void * F_7 ( struct V_2 * V_3 , unsigned char V_24 )
{
struct V_25 * V_26 = NULL ;
while ( ( V_26 = F_8 ( V_3 -> V_27 , V_3 -> V_10 , V_26 ,
V_28 ) ) != NULL ) {
if ( V_26 -> V_29 >= 4 &&
V_26 -> V_30 >= V_31 &&
V_26 -> V_30 <= V_32 &&
V_26 -> V_33 == V_24 )
return V_26 ;
}
return NULL ;
}
static int F_9 ( struct V_2 * V_3 , int V_19 , char * V_9 , int V_34 )
{
int V_35 = F_10 ( V_3 -> V_36 -> V_37 , V_19 , V_9 , V_34 - 1 ) ;
V_9 [ V_35 ] = 0 ;
return V_35 ;
}
static int F_11 ( struct V_13 * V_14 , int V_38 )
{
switch ( V_14 -> V_39 ) {
case V_40 :
return ! ! V_38 ;
case V_41 :
return ! V_38 ;
case V_42 :
V_38 &= 0xff ;
break;
case V_43 :
V_38 &= 0xff ;
if ( V_38 >= 0x80 )
V_38 -= 0x100 ;
break;
case V_44 :
V_38 &= 0xffff ;
break;
case V_45 :
V_38 &= 0xffff ;
if ( V_38 >= 0x8000 )
V_38 -= 0x10000 ;
break;
}
return V_38 ;
}
static int F_12 ( struct V_13 * V_14 , int V_38 )
{
switch ( V_14 -> V_39 ) {
case V_40 :
return ! ! V_38 ;
case V_41 :
return ! V_38 ;
case V_43 :
case V_42 :
return V_38 & 0xff ;
case V_45 :
case V_44 :
return V_38 & 0xffff ;
}
return 0 ;
}
static int F_13 ( struct V_13 * V_14 , int V_38 )
{
if ( ! V_14 -> V_46 )
V_14 -> V_46 = 1 ;
if ( V_38 < V_14 -> V_16 )
return 0 ;
else if ( V_38 >= V_14 -> V_18 )
return ( V_14 -> V_18 - V_14 -> V_16 + V_14 -> V_46 - 1 ) / V_14 -> V_46 ;
else
return ( V_38 - V_14 -> V_16 ) / V_14 -> V_46 ;
}
static int F_14 ( struct V_13 * V_14 , int V_38 )
{
if ( V_38 < 0 )
return V_14 -> V_16 ;
if ( ! V_14 -> V_46 )
V_14 -> V_46 = 1 ;
V_38 *= V_14 -> V_46 ;
V_38 += V_14 -> V_16 ;
if ( V_38 > V_14 -> V_18 )
return V_14 -> V_18 ;
return V_38 ;
}
static int F_15 ( struct V_13 * V_14 , int V_47 , int V_48 , int * V_49 )
{
struct V_50 * V_36 = V_14 -> V_51 -> V_36 ;
unsigned char V_9 [ 2 ] ;
int V_52 = V_14 -> V_39 >= V_45 ? 2 : 1 ;
int V_53 = 10 ;
int V_54 ;
V_54 = F_16 ( V_14 -> V_51 -> V_36 ) ;
if ( V_54 < 0 )
return - V_55 ;
while ( V_53 -- > 0 ) {
if ( F_17 ( V_36 -> V_37 , F_18 ( V_36 -> V_37 , 0 ) , V_47 ,
V_56 | V_57 | V_58 ,
V_48 , F_19 ( V_36 ) | ( V_14 -> V_8 << 8 ) ,
V_9 , V_52 , 100 ) >= V_52 ) {
* V_49 = F_11 ( V_14 , F_20 ( V_9 , V_52 ) ) ;
F_21 ( V_14 -> V_51 -> V_36 ) ;
return 0 ;
}
}
F_21 ( V_14 -> V_51 -> V_36 ) ;
F_22 ( V_59 L_1 ,
V_47 , V_48 , F_19 ( V_36 ) | ( V_14 -> V_8 << 8 ) , V_14 -> V_39 ) ;
return - V_60 ;
}
static int F_23 ( struct V_13 * V_14 , int V_47 , int V_48 , int * V_49 )
{
struct V_50 * V_36 = V_14 -> V_51 -> V_36 ;
unsigned char V_9 [ 2 + 3 * sizeof( V_61 ) ] ;
unsigned char * V_38 ;
int V_62 , V_63 ;
T_1 V_64 ;
if ( V_47 == V_65 ) {
V_64 = V_66 ;
V_63 = sizeof( V_61 ) ;
} else {
V_64 = V_67 ;
V_63 = sizeof( V_9 ) ;
}
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
V_62 = F_16 ( V_36 ) ? - V_55 : 0 ;
if ( V_62 )
goto error;
V_62 = F_17 ( V_36 -> V_37 , F_18 ( V_36 -> V_37 , 0 ) , V_64 ,
V_56 | V_57 | V_58 ,
V_48 , F_19 ( V_36 ) | ( V_14 -> V_8 << 8 ) ,
V_9 , V_63 , 1000 ) ;
F_21 ( V_36 ) ;
if ( V_62 < 0 ) {
error:
F_24 ( V_59 L_1 ,
V_47 , V_48 , F_19 ( V_36 ) | ( V_14 -> V_8 << 8 ) , V_14 -> V_39 ) ;
return V_62 ;
}
switch ( V_47 ) {
case V_65 :
V_38 = V_9 ;
break;
case V_68 :
V_38 = V_9 + sizeof( V_61 ) ;
break;
case V_69 :
V_38 = V_9 + sizeof( V_61 ) * 2 ;
break;
case V_70 :
V_38 = V_9 + sizeof( V_61 ) * 3 ;
break;
default:
return - V_60 ;
}
* V_49 = F_11 ( V_14 , F_20 ( V_38 , sizeof( V_61 ) ) ) ;
return 0 ;
}
static int F_25 ( struct V_13 * V_14 , int V_47 , int V_48 , int * V_49 )
{
return ( V_14 -> V_51 -> V_71 == V_72 ) ?
F_15 ( V_14 , V_47 , V_48 , V_49 ) :
F_23 ( V_14 , V_47 , V_48 , V_49 ) ;
}
static int F_26 ( struct V_13 * V_14 , int V_48 , int * V_73 )
{
return F_25 ( V_14 , V_65 , V_48 , V_73 ) ;
}
static inline int F_27 ( struct V_13 * V_14 ,
int V_74 , int * V_73 )
{
return F_25 ( V_14 , V_65 , ( V_14 -> V_5 << 8 ) | V_74 , V_73 ) ;
}
static int F_28 ( struct V_13 * V_14 ,
int V_74 , int V_19 , int * V_73 )
{
int V_54 ;
if ( V_14 -> V_75 & ( 1 << V_74 ) ) {
* V_73 = V_14 -> V_76 [ V_19 ] ;
return 0 ;
}
V_54 = F_27 ( V_14 , V_74 , V_73 ) ;
if ( V_54 < 0 ) {
if ( ! V_14 -> V_51 -> V_77 )
F_29 ( V_59 L_2 ,
V_14 -> V_5 , V_74 , V_54 ) ;
return V_54 ;
}
V_14 -> V_75 |= 1 << V_74 ;
V_14 -> V_76 [ V_19 ] = * V_73 ;
return 0 ;
}
int F_30 ( struct V_13 * V_14 ,
int V_47 , int V_48 , int V_78 )
{
struct V_50 * V_36 = V_14 -> V_51 -> V_36 ;
unsigned char V_9 [ 2 ] ;
int V_52 , V_54 , V_53 = 10 ;
if ( V_14 -> V_51 -> V_71 == V_72 ) {
V_52 = V_14 -> V_39 >= V_45 ? 2 : 1 ;
} else {
V_52 = sizeof( V_61 ) ;
if ( V_47 != V_79 ) {
F_22 ( V_80 L_3 ) ;
return - V_60 ;
}
V_47 = V_66 ;
}
V_78 = F_12 ( V_14 , V_78 ) ;
V_9 [ 0 ] = V_78 & 0xff ;
V_9 [ 1 ] = ( V_78 >> 8 ) & 0xff ;
V_54 = F_16 ( V_36 ) ;
if ( V_54 < 0 )
return - V_55 ;
while ( V_53 -- > 0 )
if ( F_17 ( V_36 -> V_37 ,
F_31 ( V_36 -> V_37 , 0 ) , V_47 ,
V_56 | V_57 | V_81 ,
V_48 , F_19 ( V_36 ) | ( V_14 -> V_8 << 8 ) ,
V_9 , V_52 , 100 ) >= 0 ) {
F_21 ( V_36 ) ;
return 0 ;
}
F_21 ( V_36 ) ;
F_22 ( V_59 L_4 ,
V_47 , V_48 , F_19 ( V_36 ) | ( V_14 -> V_8 << 8 ) , V_14 -> V_39 , V_9 [ 0 ] , V_9 [ 1 ] ) ;
return - V_60 ;
}
static int F_32 ( struct V_13 * V_14 , int V_48 , int V_73 )
{
return F_30 ( V_14 , V_79 , V_48 , V_73 ) ;
}
static int F_33 ( struct V_13 * V_14 , int V_74 ,
int V_19 , int V_73 )
{
int V_54 ;
unsigned int V_82 = ( V_74 == 0 ) ?
V_14 -> V_83 :
V_14 -> V_84 & ( 1 << ( V_74 - 1 ) ) ;
if ( V_82 ) {
F_22 ( V_85 L_5 ,
V_86 , V_74 , V_14 -> V_5 ) ;
return 0 ;
}
V_54 = F_30 ( V_14 , V_79 , ( V_14 -> V_5 << 8 ) | V_74 ,
V_73 ) ;
if ( V_54 < 0 )
return V_54 ;
V_14 -> V_75 |= 1 << V_74 ;
V_14 -> V_76 [ V_19 ] = V_73 ;
return 0 ;
}
static int F_34 ( struct V_87 * V_88 , int V_89 ,
unsigned int V_63 , unsigned int T_2 * V_90 )
{
struct V_13 * V_14 = V_88 -> V_91 ;
F_35 ( V_92 , 0 , 0 ) ;
if ( V_63 < sizeof( V_92 ) )
return - V_93 ;
V_92 [ 2 ] = V_14 -> V_15 ;
V_92 [ 3 ] = V_14 -> V_17 ;
if ( F_36 ( V_90 , V_92 , sizeof( V_92 ) ) )
return - V_94 ;
return 0 ;
}
static int F_37 ( unsigned char * V_95 , int V_96 , int V_97 , int V_98 )
{
int V_99 = V_96 * V_98 + V_97 ;
return V_95 [ V_99 >> 3 ] & ( 0x80 >> ( V_99 & 7 ) ) ;
}
int F_38 ( struct V_100 * V_51 ,
struct V_87 * V_101 )
{
struct V_13 * V_14 = V_101 -> V_91 ;
int V_54 ;
while ( F_39 ( V_51 -> V_36 -> V_102 , & V_101 -> V_8 ) )
V_101 -> V_8 . V_19 ++ ;
if ( ( V_54 = F_40 ( V_51 -> V_36 -> V_102 , V_101 ) ) < 0 ) {
F_29 ( V_59 L_6 , V_54 ) ;
return V_54 ;
}
V_14 -> V_103 = & V_101 -> V_8 ;
V_14 -> V_104 = V_51 -> V_105 [ V_14 -> V_8 ] ;
V_51 -> V_105 [ V_14 -> V_8 ] = V_14 ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , struct V_106 * V_107 ,
unsigned char * V_11 , int V_34 , int V_108 )
{
struct V_109 * V_23 ;
if ( V_107 -> V_11 )
return F_9 ( V_3 , V_107 -> V_11 , V_11 , V_34 ) ;
if ( V_107 -> type >> 16 ) {
if ( V_108 )
return 0 ;
switch ( V_107 -> type >> 16 ) {
case V_110 :
strcpy ( V_11 , L_7 ) ; return 8 ;
case V_111 :
strcpy ( V_11 , L_8 ) ; return 12 ;
case V_112 :
strcpy ( V_11 , L_9 ) ; return 8 ;
case V_113 :
strcpy ( V_11 , L_10 ) ; return 5 ;
default:
return sprintf ( V_11 , L_11 , V_107 -> V_8 ) ;
}
}
switch ( V_107 -> type & 0xff00 ) {
case 0x0100 :
strcpy ( V_11 , L_12 ) ; return 3 ;
case 0x0200 :
strcpy ( V_11 , L_13 ) ; return 3 ;
case 0x0400 :
strcpy ( V_11 , L_14 ) ; return 7 ;
case 0x0500 :
strcpy ( V_11 , L_15 ) ; return 5 ;
}
for ( V_23 = V_114 ; V_23 -> type ; V_23 ++ )
if ( V_23 -> type == V_107 -> type ) {
strcpy ( V_11 , V_23 -> V_11 ) ;
return strlen ( V_23 -> V_11 ) ;
}
return 0 ;
}
static int F_42 ( struct V_2 * V_3 , int V_8 , struct V_106 * V_115 )
{
int V_54 ;
void * V_116 ;
memset ( V_115 , 0 , sizeof( * V_115 ) ) ;
while ( ( V_116 = F_7 ( V_3 , V_8 ) ) != NULL ) {
unsigned char * V_26 = V_116 ;
V_115 -> V_8 = V_8 ;
switch ( V_26 [ 2 ] ) {
case V_31 :
if ( V_3 -> V_51 -> V_71 == V_72 ) {
struct V_117 * V_118 = V_116 ;
V_115 -> type = F_43 ( V_118 -> V_119 ) ;
V_115 -> V_120 = V_118 -> V_121 ;
V_115 -> V_122 = F_43 ( V_118 -> V_123 ) ;
V_115 -> V_11 = V_118 -> V_124 ;
} else {
struct V_125 * V_118 = V_116 ;
V_115 -> type = F_43 ( V_118 -> V_119 ) ;
V_115 -> V_120 = V_118 -> V_121 ;
V_115 -> V_122 = F_44 ( V_118 -> V_126 ) ;
V_115 -> V_11 = V_118 -> V_124 ;
V_54 = F_42 ( V_3 , V_118 -> V_127 , V_115 ) ;
if ( V_54 < 0 )
return V_54 ;
}
return 0 ;
case V_128 : {
struct V_25 * V_118 = V_116 ;
V_8 = V_118 -> V_129 ;
break;
}
case V_113 : {
struct V_130 * V_118 = V_116 ;
V_115 -> type = V_118 -> V_30 << 16 ;
V_115 -> V_120 = F_45 ( V_118 ) ;
V_115 -> V_122 = F_46 ( V_118 , V_3 -> V_51 -> V_71 ) ;
V_115 -> V_11 = F_47 ( V_118 ) ;
return 0 ;
}
case V_110 :
case V_131 : {
struct V_132 * V_118 = V_116 ;
if ( F_42 ( V_3 , V_118 -> V_133 [ 0 ] , V_115 ) < 0 )
return - V_134 ;
V_115 -> type = V_118 -> V_30 << 16 ;
V_115 -> V_8 = V_8 ;
V_115 -> V_11 = F_48 ( V_118 ) ;
return 0 ;
}
case V_111 :
case V_112 : {
struct V_135 * V_118 = V_116 ;
if ( V_118 -> V_136 ) {
V_8 = V_118 -> V_133 [ 0 ] ;
break;
}
V_115 -> type = V_118 -> V_30 << 16 ;
V_115 -> V_120 = F_49 ( V_118 ) ;
V_115 -> V_122 = F_50 ( V_118 , V_3 -> V_51 -> V_71 ) ;
V_115 -> V_11 = F_51 ( V_118 , V_3 -> V_51 -> V_71 ) ;
return 0 ;
}
case V_137 : {
struct V_138 * V_118 = V_116 ;
V_115 -> type = V_118 -> V_30 << 16 ;
V_115 -> V_8 = V_8 ;
V_115 -> V_11 = V_118 -> V_139 ;
return 0 ;
}
default:
return - V_134 ;
}
}
return - V_134 ;
}
static void F_52 ( struct V_87 * V_101 )
{
F_53 ( V_101 -> V_91 ) ;
V_101 -> V_91 = NULL ;
}
static int F_54 ( struct V_13 * V_14 , int V_140 )
{
V_14 -> V_16 = V_140 ;
V_14 -> V_18 = V_14 -> V_16 + 1 ;
V_14 -> V_46 = 1 ;
V_14 -> V_15 = V_14 -> V_17 = 0 ;
if ( V_14 -> V_39 == V_40 ||
V_14 -> V_39 == V_41 ) {
V_14 -> V_141 = 1 ;
} else {
int V_142 = 0 ;
if ( V_14 -> V_143 ) {
int V_144 ;
for ( V_144 = 0 ; V_144 < V_145 ; V_144 ++ )
if ( V_14 -> V_143 & ( 1 << V_144 ) ) {
V_142 = V_144 + 1 ;
break;
}
}
if ( F_25 ( V_14 , V_69 , ( V_14 -> V_5 << 8 ) | V_142 , & V_14 -> V_18 ) < 0 ||
F_25 ( V_14 , V_68 , ( V_14 -> V_5 << 8 ) | V_142 , & V_14 -> V_16 ) < 0 ) {
F_29 ( V_59 L_16 ,
V_14 -> V_8 , F_19 ( V_14 -> V_51 -> V_36 ) , V_14 -> V_5 , V_14 -> V_8 ) ;
return - V_60 ;
}
if ( F_25 ( V_14 , V_70 , ( V_14 -> V_5 << 8 ) | V_142 , & V_14 -> V_46 ) < 0 ) {
V_14 -> V_46 = 1 ;
} else {
int V_146 = V_14 -> V_46 ;
while ( V_14 -> V_46 > 1 ) {
if ( F_30 ( V_14 , V_147 ,
( V_14 -> V_5 << 8 ) | V_142 , V_14 -> V_46 / 2 ) < 0 )
break;
V_14 -> V_46 /= 2 ;
}
if ( F_25 ( V_14 , V_70 , ( V_14 -> V_5 << 8 ) | V_142 , & V_14 -> V_46 ) < 0 )
V_14 -> V_46 = V_146 ;
}
if ( V_14 -> V_46 == 0 )
V_14 -> V_46 = 1 ;
if ( V_14 -> V_16 + V_14 -> V_46 < V_14 -> V_18 ) {
int V_146 = V_14 -> V_46 ;
int V_148 , V_149 , V_150 ;
F_27 ( V_14 , V_142 , & V_148 ) ;
for (; ; ) {
V_149 = V_148 ;
if ( V_149 < V_14 -> V_18 )
V_149 += V_14 -> V_46 ;
else
V_149 -= V_14 -> V_46 ;
if ( V_149 < V_14 -> V_16 || V_149 > V_14 -> V_18 ||
F_33 ( V_14 , V_142 , 0 , V_149 ) ||
F_27 ( V_14 , V_142 , & V_150 ) ) {
V_14 -> V_46 = V_146 ;
break;
}
if ( V_149 == V_150 )
break;
V_14 -> V_46 *= 2 ;
}
F_33 ( V_14 , V_142 , 0 , V_148 ) ;
}
V_14 -> V_141 = 1 ;
}
V_14 -> V_15 = ( F_11 ( V_14 , V_14 -> V_16 ) * 100 ) / 256 ;
V_14 -> V_17 = ( F_11 ( V_14 , V_14 -> V_18 ) * 100 ) / 256 ;
if ( V_14 -> V_15 > V_14 -> V_17 ) {
if ( V_14 -> V_15 < 0 )
V_14 -> V_17 = 0 ;
else if ( V_14 -> V_15 > 0 )
V_14 -> V_15 = 0 ;
if ( V_14 -> V_15 > V_14 -> V_17 ) {
return - V_60 ;
}
}
return 0 ;
}
static int F_55 ( struct V_87 * V_88 , struct V_151 * V_152 )
{
struct V_13 * V_14 = V_88 -> V_91 ;
if ( V_14 -> V_39 == V_40 ||
V_14 -> V_39 == V_41 )
V_152 -> type = V_153 ;
else
V_152 -> type = V_154 ;
V_152 -> V_22 = V_14 -> V_120 ;
if ( V_14 -> V_39 == V_40 ||
V_14 -> V_39 == V_41 ) {
V_152 -> V_73 . integer . V_16 = 0 ;
V_152 -> V_73 . integer . V_18 = 1 ;
} else {
if ( ! V_14 -> V_141 )
F_54 ( V_14 , 0 ) ;
V_152 -> V_73 . integer . V_16 = 0 ;
V_152 -> V_73 . integer . V_18 =
( V_14 -> V_18 - V_14 -> V_16 + V_14 -> V_46 - 1 ) / V_14 -> V_46 ;
}
return 0 ;
}
static int F_56 ( struct V_87 * V_88 , struct V_155 * V_156 )
{
struct V_13 * V_14 = V_88 -> V_91 ;
int V_157 , V_158 , V_38 , V_54 ;
V_156 -> V_73 . integer . V_73 [ 0 ] = V_14 -> V_16 ;
if ( V_14 -> V_143 ) {
V_158 = 0 ;
for ( V_157 = 0 ; V_157 < V_145 ; V_157 ++ ) {
if ( ! ( V_14 -> V_143 & ( 1 << V_157 ) ) )
continue;
V_54 = F_28 ( V_14 , V_157 + 1 , V_158 , & V_38 ) ;
if ( V_54 < 0 )
return V_14 -> V_51 -> V_77 ? 0 : V_54 ;
V_38 = F_13 ( V_14 , V_38 ) ;
V_156 -> V_73 . integer . V_73 [ V_158 ] = V_38 ;
V_158 ++ ;
}
return 0 ;
} else {
V_54 = F_28 ( V_14 , 0 , 0 , & V_38 ) ;
if ( V_54 < 0 )
return V_14 -> V_51 -> V_77 ? 0 : V_54 ;
V_38 = F_13 ( V_14 , V_38 ) ;
V_156 -> V_73 . integer . V_73 [ 0 ] = V_38 ;
}
return 0 ;
}
static int F_57 ( struct V_87 * V_88 , struct V_155 * V_156 )
{
struct V_13 * V_14 = V_88 -> V_91 ;
int V_157 , V_158 , V_38 , V_159 , V_54 ;
int V_160 = 0 ;
if ( V_14 -> V_143 ) {
V_158 = 0 ;
for ( V_157 = 0 ; V_157 < V_145 ; V_157 ++ ) {
if ( ! ( V_14 -> V_143 & ( 1 << V_157 ) ) )
continue;
V_54 = F_28 ( V_14 , V_157 + 1 , V_158 , & V_159 ) ;
if ( V_54 < 0 )
return V_14 -> V_51 -> V_77 ? 0 : V_54 ;
V_38 = V_156 -> V_73 . integer . V_73 [ V_158 ] ;
V_38 = F_14 ( V_14 , V_38 ) ;
if ( V_159 != V_38 ) {
F_33 ( V_14 , V_157 + 1 , V_158 , V_38 ) ;
V_160 = 1 ;
}
V_158 ++ ;
}
} else {
V_54 = F_28 ( V_14 , 0 , 0 , & V_159 ) ;
if ( V_54 < 0 )
return V_14 -> V_51 -> V_77 ? 0 : V_54 ;
V_38 = V_156 -> V_73 . integer . V_73 [ 0 ] ;
V_38 = F_14 ( V_14 , V_38 ) ;
if ( V_38 != V_159 ) {
F_33 ( V_14 , 0 , 0 , V_38 ) ;
V_160 = 1 ;
}
}
return V_160 ;
}
static T_3 F_58 ( struct V_87 * V_101 , const char * V_161 )
{
return F_59 ( V_101 -> V_8 . V_11 , V_161 , sizeof( V_101 -> V_8 . V_11 ) ) ;
}
static void F_60 ( struct V_2 * V_3 , void * V_162 ,
unsigned int V_163 , int V_5 ,
struct V_106 * V_107 , int V_4 ,
int V_164 )
{
struct V_25 * V_165 = V_162 ;
unsigned int V_35 = 0 ;
int V_166 = 0 ;
int V_167 = F_61 ( V_165 ) ;
struct V_87 * V_101 ;
struct V_13 * V_14 ;
const struct V_1 * V_7 ;
unsigned int V_168 ;
V_5 ++ ;
if ( V_5 == V_169 ) {
return;
}
V_7 = F_1 ( V_3 , V_4 , V_5 ) ;
if ( F_4 ( V_7 ) )
return;
V_14 = F_62 ( sizeof( * V_14 ) , V_170 ) ;
if ( ! V_14 ) {
F_24 ( V_59 L_17 ) ;
return;
}
V_14 -> V_51 = V_3 -> V_51 ;
V_14 -> V_8 = V_4 ;
V_14 -> V_5 = V_5 ;
V_14 -> V_143 = V_163 ;
V_14 -> V_39 = V_171 [ V_5 - 1 ] . type ;
if ( V_163 == 0 ) {
V_14 -> V_120 = 1 ;
V_14 -> V_83 = V_164 ;
} else {
int V_144 , V_157 = 0 ;
for ( V_144 = 0 ; V_144 < 16 ; V_144 ++ )
if ( V_163 & ( 1 << V_144 ) )
V_157 ++ ;
V_14 -> V_120 = V_157 ;
V_14 -> V_84 = V_164 ;
}
F_54 ( V_14 , 0 ) ;
if ( V_14 -> V_120 == V_164 )
V_101 = F_63 ( & V_172 , V_14 ) ;
else
V_101 = F_63 ( & V_173 , V_14 ) ;
if ( ! V_101 ) {
F_24 ( V_59 L_17 ) ;
F_53 ( V_14 ) ;
return;
}
V_101 -> V_174 = F_52 ;
V_35 = F_2 ( V_7 , V_101 -> V_8 . V_11 , sizeof( V_101 -> V_8 . V_11 ) ) ;
V_166 = V_35 != 0 ;
if ( ! V_35 && V_167 )
V_35 = F_9 ( V_3 , V_167 ,
V_101 -> V_8 . V_11 , sizeof( V_101 -> V_8 . V_11 ) ) ;
switch ( V_5 ) {
case V_175 :
case V_176 :
if ( ! V_35 ) {
V_35 = F_41 ( V_3 , V_107 , V_101 -> V_8 . V_11 , sizeof( V_101 -> V_8 . V_11 ) , 1 ) ;
if ( ! V_35 )
V_35 = F_41 ( V_3 , & V_3 -> V_177 , V_101 -> V_8 . V_11 , sizeof( V_101 -> V_8 . V_11 ) , 1 ) ;
if ( ! V_35 )
V_35 = snprintf ( V_101 -> V_8 . V_11 , sizeof( V_101 -> V_8 . V_11 ) ,
L_18 , V_4 ) ;
}
if ( ! V_166 && ! ( V_3 -> V_177 . type >> 16 ) ) {
if ( ( V_3 -> V_177 . type & 0xff00 ) == 0x0100 ) {
V_35 = F_58 ( V_101 , L_19 ) ;
} else {
V_35 = F_58 ( V_101 , L_20 ) ;
}
}
F_58 ( V_101 , V_5 == V_175 ?
L_21 : L_22 ) ;
if ( V_5 == V_176 ) {
F_5 ( V_7 , V_14 ) ;
if ( V_14 -> V_15 < V_14 -> V_17 ) {
V_101 -> V_178 . V_157 = F_34 ;
V_101 -> V_179 [ 0 ] . V_180 |=
V_181 |
V_182 ;
}
}
break;
default:
if ( ! V_35 )
F_3 ( V_101 -> V_8 . V_11 , V_171 [ V_5 - 1 ] . V_11 ,
sizeof( V_101 -> V_8 . V_11 ) ) ;
break;
}
switch ( V_3 -> V_36 -> V_183 ) {
case F_64 ( 0x0471 , 0x0101 ) :
case F_64 ( 0x0471 , 0x0104 ) :
case F_64 ( 0x0471 , 0x0105 ) :
case F_64 ( 0x0672 , 0x1041 ) :
if ( ! strcmp ( V_101 -> V_8 . V_11 , L_23 ) &&
V_14 -> V_16 == - 15616 ) {
F_24 ( V_85
L_24 ) ;
V_14 -> V_18 = - 256 ;
}
break;
case F_64 ( 0x046d , 0x09a4 ) :
if ( ! strcmp ( V_101 -> V_8 . V_11 , L_25 ) ) {
F_24 ( V_85
L_26 ) ;
V_14 -> V_16 = 6080 ;
V_14 -> V_18 = 8768 ;
V_14 -> V_46 = 192 ;
}
break;
case F_64 ( 0x046d , 0x0808 ) :
case F_64 ( 0x046d , 0x0809 ) :
case F_64 ( 0x046d , 0x0991 ) :
if ( ! strcmp ( V_101 -> V_8 . V_11 , L_25 ) ) {
F_24 ( V_85
L_27 ) ;
V_14 -> V_46 = 384 ;
}
break;
}
V_168 = ( V_14 -> V_18 - V_14 -> V_16 ) / V_14 -> V_46 ;
if ( V_168 > 384 ) {
F_24 ( V_80 L_28
L_29 ,
V_168 ) ;
F_24 ( V_80 L_30
L_31 , V_14 -> V_8 ,
V_101 -> V_8 . V_11 , V_14 -> V_120 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_46 ) ;
}
F_22 ( V_85 L_32 ,
V_14 -> V_8 , V_101 -> V_8 . V_11 , V_14 -> V_120 , V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_46 ) ;
F_38 ( V_3 -> V_51 , V_101 ) ;
}
static int F_65 ( struct V_2 * V_3 , int V_4 , void * V_184 )
{
int V_120 , V_144 , V_185 ;
struct V_106 V_107 ;
unsigned int V_186 , V_187 ;
int V_54 , V_188 ;
struct V_25 * V_26 = V_184 ;
T_1 * V_189 ;
if ( V_3 -> V_51 -> V_71 == V_72 ) {
V_188 = V_26 -> V_190 ;
V_120 = ( V_26 -> V_29 - 7 ) / V_188 - 1 ;
V_189 = V_26 -> V_189 ;
} else {
struct V_191 * V_192 = V_184 ;
V_188 = 4 ;
V_120 = ( V_26 -> V_29 - 6 ) / 4 - 1 ;
V_189 = V_192 -> V_189 ;
}
if ( V_26 -> V_29 < 7 || ! V_188 || V_26 -> V_29 < 7 + V_188 ) {
F_24 ( V_59 L_33 , V_4 ) ;
return - V_60 ;
}
if ( ( V_54 = F_66 ( V_3 , V_26 -> V_129 ) ) < 0 )
return V_54 ;
if ( F_42 ( V_3 , V_26 -> V_129 , & V_107 ) < 0 )
return - V_60 ;
V_186 = F_20 ( V_189 , V_188 ) ;
switch ( V_3 -> V_36 -> V_183 ) {
case F_64 ( 0x08bb , 0x2702 ) :
F_24 ( V_85
L_34 ) ;
V_186 &= ~ F_67 ( V_176 ) ;
break;
}
if ( V_120 > 0 )
V_187 = F_20 ( V_189 + V_188 , V_188 ) ;
else
V_187 = 0 ;
if ( V_3 -> V_51 -> V_71 == V_72 ) {
for ( V_144 = 0 ; V_144 < 10 ; V_144 ++ ) {
unsigned int V_193 = 0 ;
for ( V_185 = 0 ; V_185 < V_120 ; V_185 ++ ) {
unsigned int V_194 = F_20 ( V_189 + V_188 * ( V_185 + 1 ) , V_188 ) ;
if ( V_194 & ( 1 << V_144 ) )
V_193 |= ( 1 << V_185 ) ;
}
if ( V_193 & 1 )
F_60 ( V_3 , V_184 , V_193 , V_144 , & V_107 , V_4 , 0 ) ;
if ( V_186 & ( 1 << V_144 ) )
F_60 ( V_3 , V_184 , 0 , V_144 , & V_107 , V_4 , 0 ) ;
}
} else {
for ( V_144 = 0 ; V_144 < 30 / 2 ; V_144 ++ ) {
unsigned int V_193 = 0 ;
unsigned int V_195 = 0 ;
for ( V_185 = 0 ; V_185 < V_120 ; V_185 ++ ) {
unsigned int V_194 = F_20 ( V_189 + V_188 * ( V_185 + 1 ) , V_188 ) ;
if ( F_68 ( V_194 , V_144 ) ) {
V_193 |= ( 1 << V_185 ) ;
if ( ! F_69 ( V_194 , V_144 ) )
V_195 |= ( 1 << V_185 ) ;
}
}
if ( V_193 & 1 )
F_60 ( V_3 , V_184 , V_193 , V_144 , & V_107 , V_4 , V_195 ) ;
if ( F_68 ( V_186 , V_144 ) )
F_60 ( V_3 , V_184 , 0 , V_144 , & V_107 , V_4 ,
! F_69 ( V_186 , V_144 ) ) ;
}
}
return 0 ;
}
static void F_70 ( struct V_2 * V_3 ,
struct V_130 * V_165 ,
int V_196 , int V_197 , int V_4 ,
struct V_106 * V_107 )
{
struct V_13 * V_14 ;
unsigned int V_98 = F_45 ( V_165 ) ;
unsigned int V_144 , V_35 ;
struct V_87 * V_101 ;
const struct V_1 * V_7 ;
V_7 = F_1 ( V_3 , V_4 , 0 ) ;
if ( F_4 ( V_7 ) )
return;
V_14 = F_62 ( sizeof( * V_14 ) , V_170 ) ;
if ( ! V_14 )
return;
V_14 -> V_51 = V_3 -> V_51 ;
V_14 -> V_8 = V_4 ;
V_14 -> V_5 = V_197 + 1 ;
V_14 -> V_39 = V_45 ;
for ( V_144 = 0 ; V_144 < V_98 ; V_144 ++ ) {
if ( F_37 ( F_71 ( V_165 , V_3 -> V_51 -> V_71 ) , V_197 , V_144 , V_98 ) ) {
V_14 -> V_143 |= ( 1 << V_144 ) ;
V_14 -> V_120 ++ ;
}
}
F_54 ( V_14 , 0 ) ;
V_101 = F_63 ( & V_173 , V_14 ) ;
if ( ! V_101 ) {
F_24 ( V_59 L_17 ) ;
F_53 ( V_14 ) ;
return;
}
V_101 -> V_174 = F_52 ;
V_35 = F_2 ( V_7 , V_101 -> V_8 . V_11 , sizeof( V_101 -> V_8 . V_11 ) ) ;
if ( ! V_35 )
V_35 = F_41 ( V_3 , V_107 , V_101 -> V_8 . V_11 , sizeof( V_101 -> V_8 . V_11 ) , 0 ) ;
if ( ! V_35 )
V_35 = sprintf ( V_101 -> V_8 . V_11 , L_35 , V_197 + 1 ) ;
F_58 ( V_101 , L_22 ) ;
F_22 ( V_85 L_36 ,
V_14 -> V_8 , V_101 -> V_8 . V_11 , V_14 -> V_120 , V_14 -> V_16 , V_14 -> V_18 ) ;
F_38 ( V_3 -> V_51 , V_101 ) ;
}
static int F_72 ( struct V_2 * V_3 , int V_4 , void * V_162 )
{
struct V_130 * V_165 = V_162 ;
struct V_106 V_107 ;
int V_198 , V_199 , V_98 ;
int V_200 , V_96 , V_54 ;
if ( V_165 -> V_29 < 11 || ! ( V_198 = V_165 -> V_136 ) || ! ( V_98 = F_45 ( V_165 ) ) ) {
F_24 ( V_59 L_37 , V_4 ) ;
return - V_60 ;
}
if ( V_165 -> V_29 <= 10 + V_198 ) {
F_22 ( V_85 L_38 , V_4 ) ;
return 0 ;
}
V_199 = 0 ;
V_96 = 0 ;
for ( V_200 = 0 ; V_200 < V_198 ; V_200 ++ ) {
V_54 = F_66 ( V_3 , V_165 -> V_133 [ V_200 ] ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_42 ( V_3 , V_165 -> V_133 [ V_200 ] , & V_107 ) ;
if ( V_54 < 0 )
return V_54 ;
V_199 += V_107 . V_120 ;
for (; V_96 < V_199 ; ++ V_96 ) {
int V_97 , V_201 = 0 ;
for ( V_97 = 0 ; V_97 < V_98 ; ++ V_97 ) {
if ( F_37 ( F_71 ( V_165 , V_3 -> V_51 -> V_71 ) ,
V_96 , V_97 , V_98 ) ) {
V_201 = 1 ;
break;
}
}
if ( V_201 )
F_70 ( V_3 , V_165 , V_200 , V_96 ,
V_4 , & V_107 ) ;
}
}
return 0 ;
}
static int F_73 ( struct V_87 * V_88 , struct V_155 * V_156 )
{
struct V_13 * V_14 = V_88 -> V_91 ;
int V_54 , V_38 ;
V_54 = F_26 ( V_14 , V_14 -> V_5 << 8 , & V_38 ) ;
if ( V_54 < 0 && V_14 -> V_51 -> V_77 ) {
V_156 -> V_73 . integer . V_73 [ 0 ] = V_14 -> V_16 ;
return 0 ;
}
if ( V_54 < 0 )
return V_54 ;
V_38 = F_13 ( V_14 , V_38 ) ;
V_156 -> V_73 . integer . V_73 [ 0 ] = V_38 ;
return 0 ;
}
static int F_74 ( struct V_87 * V_88 , struct V_155 * V_156 )
{
struct V_13 * V_14 = V_88 -> V_91 ;
int V_38 , V_159 , V_54 ;
V_54 = F_26 ( V_14 , V_14 -> V_5 << 8 , & V_159 ) ;
if ( V_54 < 0 ) {
if ( V_14 -> V_51 -> V_77 )
return 0 ;
return V_54 ;
}
V_38 = V_156 -> V_73 . integer . V_73 [ 0 ] ;
V_38 = F_14 ( V_14 , V_38 ) ;
if ( V_38 != V_159 ) {
F_32 ( V_14 , V_14 -> V_5 << 8 , V_38 ) ;
return 1 ;
}
return 0 ;
}
static int F_75 ( struct V_2 * V_3 , int V_4 , void * V_162 , struct V_202 * V_203 , char * V_11 )
{
struct V_135 * V_165 = V_162 ;
int V_199 = V_165 -> V_136 ;
struct V_13 * V_14 ;
struct V_87 * V_101 ;
int V_144 , V_54 , V_167 , type , V_35 ;
struct V_202 * V_204 ;
struct V_205 * V_206 ;
const struct V_1 * V_7 ;
static struct V_205 V_207 [] = {
{ 0x01 , L_39 , V_40 } ,
{ 0 }
} ;
static struct V_202 V_208 = {
0 , NULL , V_207
} ;
if ( V_165 -> V_29 < 13 || V_165 -> V_29 < 13 + V_199 ||
V_165 -> V_29 < V_199 + F_76 ( V_165 , V_3 -> V_51 -> V_71 ) ) {
F_24 ( V_59 L_40 , V_11 , V_4 ) ;
return - V_60 ;
}
for ( V_144 = 0 ; V_144 < V_199 ; V_144 ++ ) {
if ( ( V_54 = F_66 ( V_3 , V_165 -> V_133 [ V_144 ] ) ) < 0 )
return V_54 ;
}
type = F_43 ( V_165 -> V_209 ) ;
for ( V_204 = V_203 ; V_204 && V_204 -> type ; V_204 ++ )
if ( V_204 -> type == type )
break;
if ( ! V_204 || ! V_204 -> type )
V_204 = & V_208 ;
for ( V_206 = V_204 -> V_210 ; V_206 -> V_5 ; V_206 ++ ) {
T_1 * V_211 = F_77 ( V_165 , V_3 -> V_51 -> V_71 ) ;
if ( ! ( V_211 [ V_206 -> V_5 / 8 ] & ( 1 << ( ( V_206 -> V_5 % 8 ) - 1 ) ) ) )
continue;
V_7 = F_1 ( V_3 , V_4 , V_206 -> V_5 ) ;
if ( F_4 ( V_7 ) )
continue;
V_14 = F_62 ( sizeof( * V_14 ) , V_170 ) ;
if ( ! V_14 ) {
F_24 ( V_59 L_17 ) ;
return - V_93 ;
}
V_14 -> V_51 = V_3 -> V_51 ;
V_14 -> V_8 = V_4 ;
V_14 -> V_5 = V_206 -> V_5 ;
V_14 -> V_39 = V_206 -> V_39 ;
V_14 -> V_120 = 1 ;
if ( type == V_212 && V_14 -> V_5 == V_213 ) {
T_1 * V_214 = F_78 ( V_165 , V_3 -> V_51 -> V_71 ) ;
V_14 -> V_16 = 1 ;
V_14 -> V_18 = V_214 [ 0 ] ;
V_14 -> V_46 = 1 ;
V_14 -> V_141 = 1 ;
} else {
if ( type == V_215 ) {
V_14 -> V_16 = 0 ;
V_14 -> V_18 = 5 ;
V_14 -> V_46 = 1 ;
V_14 -> V_141 = 1 ;
} else
F_54 ( V_14 , V_206 -> V_216 ) ;
}
V_101 = F_63 ( & V_217 , V_14 ) ;
if ( ! V_101 ) {
F_24 ( V_59 L_17 ) ;
F_53 ( V_14 ) ;
return - V_93 ;
}
V_101 -> V_174 = F_52 ;
if ( F_2 ( V_7 , V_101 -> V_8 . V_11 ,
sizeof( V_101 -> V_8 . V_11 ) ) )
;
else if ( V_204 -> V_11 )
F_3 ( V_101 -> V_8 . V_11 , V_204 -> V_11 , sizeof( V_101 -> V_8 . V_11 ) ) ;
else {
V_167 = F_51 ( V_165 , V_3 -> V_51 -> V_71 ) ;
V_35 = 0 ;
if ( V_167 )
V_35 = F_9 ( V_3 , V_167 , V_101 -> V_8 . V_11 , sizeof( V_101 -> V_8 . V_11 ) ) ;
if ( ! V_35 )
F_3 ( V_101 -> V_8 . V_11 , V_11 , sizeof( V_101 -> V_8 . V_11 ) ) ;
}
F_58 ( V_101 , L_41 ) ;
F_58 ( V_101 , V_206 -> V_218 ) ;
F_22 ( V_85 L_42 ,
V_14 -> V_8 , V_101 -> V_8 . V_11 , V_14 -> V_120 , V_14 -> V_16 , V_14 -> V_18 ) ;
if ( ( V_54 = F_38 ( V_3 -> V_51 , V_101 ) ) < 0 )
return V_54 ;
}
return 0 ;
}
static int F_79 ( struct V_2 * V_3 , int V_4 , void * V_162 )
{
return F_75 ( V_3 , V_4 , V_162 , V_219 , L_43 ) ;
}
static int F_80 ( struct V_2 * V_3 , int V_4 , void * V_162 )
{
return F_75 ( V_3 , V_4 , V_162 , V_220 , L_44 ) ;
}
static int F_81 ( struct V_87 * V_88 , struct V_151 * V_152 )
{
struct V_13 * V_14 = V_88 -> V_91 ;
const char * * V_221 = ( const char * * ) V_88 -> V_222 ;
if ( F_82 ( ! V_221 ) )
return - V_60 ;
return F_83 ( V_152 , 1 , V_14 -> V_18 , V_221 ) ;
}
static int F_84 ( struct V_87 * V_88 , struct V_155 * V_156 )
{
struct V_13 * V_14 = V_88 -> V_91 ;
int V_38 , V_54 ;
V_54 = F_26 ( V_14 , V_14 -> V_5 << 8 , & V_38 ) ;
if ( V_54 < 0 ) {
if ( V_14 -> V_51 -> V_77 ) {
V_156 -> V_73 . V_223 . V_224 [ 0 ] = 0 ;
return 0 ;
}
return V_54 ;
}
V_38 = F_13 ( V_14 , V_38 ) ;
V_156 -> V_73 . V_223 . V_224 [ 0 ] = V_38 ;
return 0 ;
}
static int F_85 ( struct V_87 * V_88 , struct V_155 * V_156 )
{
struct V_13 * V_14 = V_88 -> V_91 ;
int V_38 , V_159 , V_54 ;
V_54 = F_26 ( V_14 , V_14 -> V_5 << 8 , & V_159 ) ;
if ( V_54 < 0 ) {
if ( V_14 -> V_51 -> V_77 )
return 0 ;
return V_54 ;
}
V_38 = V_156 -> V_73 . V_223 . V_224 [ 0 ] ;
V_38 = F_14 ( V_14 , V_38 ) ;
if ( V_38 != V_159 ) {
F_32 ( V_14 , V_14 -> V_5 << 8 , V_38 ) ;
return 1 ;
}
return 0 ;
}
static void F_86 ( struct V_87 * V_101 )
{
int V_144 , V_199 = 0 ;
if ( V_101 -> V_91 ) {
struct V_13 * V_14 = V_101 -> V_91 ;
V_199 = V_14 -> V_18 ;
F_53 ( V_14 ) ;
V_101 -> V_91 = NULL ;
}
if ( V_101 -> V_222 ) {
char * * V_221 = ( char * * ) V_101 -> V_222 ;
for ( V_144 = 0 ; V_144 < V_199 ; V_144 ++ )
F_53 ( V_221 [ V_144 ] ) ;
F_53 ( V_221 ) ;
V_101 -> V_222 = 0 ;
}
}
static int F_87 ( struct V_2 * V_3 , int V_4 , void * V_162 )
{
struct V_132 * V_165 = V_162 ;
unsigned int V_144 , V_167 , V_35 ;
int V_54 ;
struct V_13 * V_14 ;
struct V_87 * V_101 ;
const struct V_1 * V_7 ;
char * * V_225 ;
if ( ! V_165 -> V_136 || V_165 -> V_29 < 5 + V_165 -> V_136 ) {
F_24 ( V_59 L_45 , V_4 ) ;
return - V_60 ;
}
for ( V_144 = 0 ; V_144 < V_165 -> V_136 ; V_144 ++ ) {
if ( ( V_54 = F_66 ( V_3 , V_165 -> V_133 [ V_144 ] ) ) < 0 )
return V_54 ;
}
if ( V_165 -> V_136 == 1 )
return 0 ;
V_7 = F_1 ( V_3 , V_4 , 0 ) ;
if ( F_4 ( V_7 ) )
return 0 ;
V_14 = F_62 ( sizeof( * V_14 ) , V_170 ) ;
if ( ! V_14 ) {
F_24 ( V_59 L_17 ) ;
return - V_93 ;
}
V_14 -> V_51 = V_3 -> V_51 ;
V_14 -> V_8 = V_4 ;
V_14 -> V_39 = V_42 ;
V_14 -> V_120 = 1 ;
V_14 -> V_16 = 1 ;
V_14 -> V_18 = V_165 -> V_136 ;
V_14 -> V_46 = 1 ;
V_14 -> V_141 = 1 ;
if ( V_165 -> V_30 == V_131 )
V_14 -> V_5 = V_226 ;
else
V_14 -> V_5 = 0 ;
V_225 = F_88 ( sizeof( char * ) * V_165 -> V_136 , V_170 ) ;
if ( ! V_225 ) {
F_24 ( V_59 L_46 ) ;
F_53 ( V_14 ) ;
return - V_93 ;
}
#define F_89 64
for ( V_144 = 0 ; V_144 < V_165 -> V_136 ; V_144 ++ ) {
struct V_106 V_107 ;
V_35 = 0 ;
V_225 [ V_144 ] = F_88 ( F_89 , V_170 ) ;
if ( ! V_225 [ V_144 ] ) {
F_24 ( V_59 L_46 ) ;
while ( V_144 -- )
F_53 ( V_225 [ V_144 ] ) ;
F_53 ( V_225 ) ;
F_53 ( V_14 ) ;
return - V_93 ;
}
V_35 = F_6 ( V_3 , V_4 , V_144 , V_225 [ V_144 ] ,
F_89 ) ;
if ( ! V_35 && F_42 ( V_3 , V_165 -> V_133 [ V_144 ] , & V_107 ) >= 0 )
V_35 = F_41 ( V_3 , & V_107 , V_225 [ V_144 ] , F_89 , 0 ) ;
if ( ! V_35 )
sprintf ( V_225 [ V_144 ] , L_47 , V_144 ) ;
}
V_101 = F_63 ( & V_227 , V_14 ) ;
if ( ! V_101 ) {
F_24 ( V_59 L_17 ) ;
F_53 ( V_225 ) ;
F_53 ( V_14 ) ;
return - V_93 ;
}
V_101 -> V_222 = ( unsigned long ) V_225 ;
V_101 -> V_174 = F_86 ;
V_167 = F_48 ( V_165 ) ;
V_35 = F_2 ( V_7 , V_101 -> V_8 . V_11 , sizeof( V_101 -> V_8 . V_11 ) ) ;
if ( V_35 )
;
else if ( V_167 )
F_9 ( V_3 , V_167 , V_101 -> V_8 . V_11 , sizeof( V_101 -> V_8 . V_11 ) ) ;
else {
V_35 = F_41 ( V_3 , & V_3 -> V_177 ,
V_101 -> V_8 . V_11 , sizeof( V_101 -> V_8 . V_11 ) , 0 ) ;
if ( ! V_35 )
F_3 ( V_101 -> V_8 . V_11 , L_48 , sizeof( V_101 -> V_8 . V_11 ) ) ;
if ( V_165 -> V_30 == V_131 )
F_58 ( V_101 , L_49 ) ;
else if ( ( V_3 -> V_177 . type & 0xff00 ) == 0x0100 )
F_58 ( V_101 , L_50 ) ;
else
F_58 ( V_101 , L_51 ) ;
}
F_22 ( V_85 L_52 ,
V_14 -> V_8 , V_101 -> V_8 . V_11 , V_165 -> V_136 ) ;
if ( ( V_54 = F_38 ( V_3 -> V_51 , V_101 ) ) < 0 )
return V_54 ;
return 0 ;
}
static int F_66 ( struct V_2 * V_3 , int V_4 )
{
unsigned char * V_116 ;
if ( F_90 ( V_4 , V_3 -> V_228 ) )
return 0 ;
V_116 = F_7 ( V_3 , V_4 ) ;
if ( ! V_116 ) {
F_24 ( V_59 L_53 , V_4 ) ;
return - V_60 ;
}
switch ( V_116 [ 2 ] ) {
case V_31 :
case V_137 :
return 0 ;
case V_113 :
return F_72 ( V_3 , V_4 , V_116 ) ;
case V_110 :
case V_131 :
return F_87 ( V_3 , V_4 , V_116 ) ;
case V_128 :
return F_65 ( V_3 , V_4 , V_116 ) ;
case V_111 :
if ( V_3 -> V_51 -> V_71 == V_72 )
return F_79 ( V_3 , V_4 , V_116 ) ;
else
return 0 ;
case V_112 :
if ( V_3 -> V_51 -> V_71 == V_72 )
return F_80 ( V_3 , V_4 , V_116 ) ;
else
return F_79 ( V_3 , V_4 , V_116 ) ;
default:
F_24 ( V_59 L_54 , V_4 , V_116 [ 2 ] ) ;
return - V_60 ;
}
}
static void F_91 ( struct V_100 * V_51 )
{
F_53 ( V_51 -> V_105 ) ;
if ( V_51 -> V_229 ) {
F_53 ( V_51 -> V_229 -> V_230 ) ;
F_92 ( V_51 -> V_229 ) ;
}
F_92 ( V_51 -> V_231 ) ;
F_53 ( V_51 -> V_232 ) ;
F_53 ( V_51 ) ;
}
static int F_93 ( struct V_233 * V_234 )
{
struct V_100 * V_51 = V_234 -> V_235 ;
F_91 ( V_51 ) ;
return 0 ;
}
static int F_94 ( struct V_100 * V_51 )
{
struct V_2 V_3 ;
int V_54 ;
const struct V_236 * V_7 ;
struct V_237 * V_238 ;
void * V_6 ;
V_238 = V_51 -> V_36 -> V_239 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_36 = V_51 -> V_36 ;
V_3 . V_51 = V_51 ;
V_3 . V_27 = V_238 -> V_240 ;
V_3 . V_10 = V_238 -> V_241 ;
for ( V_7 = V_242 ; V_7 -> V_8 ; V_7 ++ ) {
if ( V_7 -> V_8 == V_3 . V_36 -> V_183 ) {
V_3 . V_7 = V_7 -> V_7 ;
V_3 . V_21 = V_7 -> V_21 ;
V_51 -> V_77 = V_7 -> V_77 ;
break;
}
}
V_6 = NULL ;
while ( ( V_6 = F_95 ( V_238 -> V_240 , V_238 -> V_241 , V_6 , V_243 ) ) != NULL ) {
if ( V_51 -> V_71 == V_72 ) {
struct V_244 * V_165 = V_6 ;
if ( V_165 -> V_29 < sizeof( * V_165 ) )
continue;
F_96 ( V_165 -> V_245 , V_3 . V_228 ) ;
V_3 . V_177 . V_8 = V_165 -> V_245 ;
V_3 . V_177 . type = F_43 ( V_165 -> V_119 ) ;
V_3 . V_177 . V_11 = V_165 -> V_124 ;
V_54 = F_66 ( & V_3 , V_165 -> V_129 ) ;
if ( V_54 < 0 )
return V_54 ;
} else {
struct V_246 * V_165 = V_6 ;
if ( V_165 -> V_29 < sizeof( * V_165 ) )
continue;
F_96 ( V_165 -> V_245 , V_3 . V_228 ) ;
V_3 . V_177 . V_8 = V_165 -> V_245 ;
V_3 . V_177 . type = F_43 ( V_165 -> V_119 ) ;
V_3 . V_177 . V_11 = V_165 -> V_124 ;
V_54 = F_66 ( & V_3 , V_165 -> V_129 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_66 ( & V_3 , V_165 -> V_127 ) ;
if ( V_54 < 0 )
return V_54 ;
}
}
return 0 ;
}
void F_97 ( struct V_100 * V_51 , int V_4 )
{
struct V_13 * V_204 ;
for ( V_204 = V_51 -> V_105 [ V_4 ] ; V_204 ; V_204 = V_204 -> V_104 )
F_98 ( V_51 -> V_36 -> V_102 , V_247 ,
V_204 -> V_103 ) ;
}
static void F_99 ( struct V_248 * V_27 ,
int V_4 ,
struct V_13 * V_14 )
{
static char * V_249 [] = { L_55 , L_56 ,
L_57 , L_58 , L_59 , L_60 } ;
F_100 ( V_27 , L_61 , V_4 ) ;
if ( V_14 -> V_103 )
F_100 ( V_27 , L_62 ,
V_14 -> V_103 -> V_11 , V_14 -> V_103 -> V_19 ) ;
F_100 ( V_27 , L_63
L_64 , V_14 -> V_8 ,
V_14 -> V_5 , V_14 -> V_143 , V_14 -> V_120 ,
V_249 [ V_14 -> V_39 ] ) ;
F_100 ( V_27 , L_65 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_15 , V_14 -> V_17 ) ;
}
static void F_101 ( struct V_250 * V_251 ,
struct V_248 * V_27 )
{
struct V_50 * V_36 = V_251 -> V_91 ;
struct V_100 * V_51 ;
struct V_13 * V_14 ;
int V_4 ;
F_102 (mixer, &chip->mixer_list, list) {
F_100 ( V_27 ,
L_66 ,
V_36 -> V_183 , F_19 ( V_36 ) ,
V_51 -> V_77 ) ;
F_100 ( V_27 , L_67 , V_36 -> V_102 -> V_252 ) ;
for ( V_4 = 0 ; V_4 < V_253 ; V_4 ++ ) {
for ( V_14 = V_51 -> V_105 [ V_4 ] ; V_14 ;
V_14 = V_14 -> V_104 )
F_99 ( V_27 , V_4 , V_14 ) ;
}
}
}
static void F_103 ( struct V_100 * V_51 ,
int V_254 , int V_73 , int V_19 )
{
struct V_13 * V_204 ;
T_1 V_4 = ( V_19 >> 8 ) & 0xff ;
T_1 V_5 = ( V_73 >> 8 ) & 0xff ;
T_1 V_74 = V_73 & 0xff ;
if ( V_74 >= V_145 ) {
F_24 ( V_255 L_68 ,
V_86 , V_74 ) ;
return;
}
for ( V_204 = V_51 -> V_105 [ V_4 ] ; V_204 ; V_204 = V_204 -> V_104 ) {
if ( V_204 -> V_5 != V_5 )
continue;
switch ( V_254 ) {
case V_66 :
if ( V_74 )
V_204 -> V_75 &= ~ ( 1 << V_74 ) ;
else
V_204 -> V_75 = 0 ;
F_98 ( V_51 -> V_36 -> V_102 , V_247 ,
V_204 -> V_103 ) ;
break;
case V_67 :
break;
case V_256 :
break;
default:
F_24 ( V_255 L_69 ,
V_254 ) ;
break;
}
}
}
static void F_104 ( struct V_229 * V_229 )
{
struct V_100 * V_51 = V_229 -> V_257 ;
int V_35 = V_229 -> V_258 ;
int V_259 = V_229 -> V_260 ;
if ( V_259 != 0 )
goto V_261;
if ( V_51 -> V_71 == V_72 ) {
struct V_262 * V_260 ;
for ( V_260 = V_229 -> V_230 ;
V_35 >= sizeof( * V_260 ) ;
V_35 -= sizeof( * V_260 ) , V_260 ++ ) {
F_29 ( V_255 L_70 ,
V_260 -> V_263 ,
V_260 -> V_264 ) ;
if ( ( V_260 -> V_263 & V_265 ) !=
V_266 )
continue;
if ( V_260 -> V_263 & V_267 )
F_105 ( V_51 , V_260 -> V_264 ) ;
else
F_97 ( V_51 , V_260 -> V_264 ) ;
}
} else {
struct V_268 * V_269 ;
for ( V_269 = V_229 -> V_230 ;
V_35 >= sizeof( * V_269 ) ;
V_35 -= sizeof( * V_269 ) , V_269 ++ ) {
if ( ( V_269 -> V_270 & V_271 ) ||
( V_269 -> V_270 & V_272 ) )
continue;
F_103 ( V_51 , V_269 -> V_273 ,
F_43 ( V_269 -> V_274 ) ,
F_43 ( V_269 -> V_275 ) ) ;
}
}
V_261:
if ( V_259 != - V_276 && V_259 != - V_277 && V_259 != - V_278 ) {
V_229 -> V_37 = V_51 -> V_36 -> V_37 ;
F_106 ( V_229 , V_279 ) ;
}
}
void F_107 ( struct V_100 * V_51 )
{
F_108 ( V_51 -> V_229 ) ;
F_108 ( V_51 -> V_231 ) ;
}
int F_109 ( struct V_100 * V_51 )
{
int V_54 ;
if ( V_51 -> V_229 ) {
V_54 = F_106 ( V_51 -> V_229 , V_280 ) ;
if ( V_54 < 0 )
return V_54 ;
}
return 0 ;
}
static int F_110 ( struct V_100 * V_51 )
{
struct V_237 * V_238 ;
struct V_281 * V_282 ;
void * V_230 ;
int V_283 ;
unsigned int V_284 ;
V_238 = V_51 -> V_36 -> V_239 ;
if ( F_111 ( V_238 ) -> V_285 < 1 )
return 0 ;
V_282 = F_112 ( V_238 , 0 ) ;
if ( ! F_113 ( V_282 ) || ! F_114 ( V_282 ) )
return 0 ;
V_284 = F_115 ( V_282 ) ;
V_283 = F_43 ( V_282 -> V_286 ) ;
V_230 = F_88 ( V_283 , V_170 ) ;
if ( ! V_230 )
return - V_93 ;
V_51 -> V_229 = F_116 ( 0 , V_170 ) ;
if ( ! V_51 -> V_229 ) {
F_53 ( V_230 ) ;
return - V_93 ;
}
F_117 ( V_51 -> V_229 , V_51 -> V_36 -> V_37 ,
F_118 ( V_51 -> V_36 -> V_37 , V_284 ) ,
V_230 , V_283 ,
F_104 , V_51 , V_282 -> V_287 ) ;
F_106 ( V_51 -> V_229 , V_170 ) ;
return 0 ;
}
int F_119 ( struct V_50 * V_36 , int V_288 ,
int V_289 )
{
static struct V_290 V_291 = {
. V_292 = F_93
} ;
struct V_100 * V_51 ;
struct V_250 * V_251 ;
struct V_237 * V_293 ;
int V_54 ;
strcpy ( V_36 -> V_102 -> V_294 , L_71 ) ;
V_51 = F_62 ( sizeof( * V_51 ) , V_170 ) ;
if ( ! V_51 )
return - V_93 ;
V_51 -> V_36 = V_36 ;
V_51 -> V_77 = V_289 ;
V_51 -> V_105 = F_120 ( V_253 , sizeof( * V_51 -> V_105 ) ,
V_170 ) ;
if ( ! V_51 -> V_105 ) {
F_53 ( V_51 ) ;
return - V_93 ;
}
V_293 = & F_121 ( V_36 -> V_37 , V_288 ) -> V_295 [ 0 ] ;
switch ( F_111 ( V_293 ) -> V_296 ) {
case V_72 :
default:
V_51 -> V_71 = V_72 ;
break;
case V_297 :
V_51 -> V_71 = V_297 ;
break;
}
if ( ( V_54 = F_94 ( V_51 ) ) < 0 ||
( V_54 = F_110 ( V_51 ) ) < 0 )
goto V_298;
F_122 ( V_51 ) ;
V_54 = F_123 ( V_36 -> V_102 , V_299 , V_51 , & V_291 ) ;
if ( V_54 < 0 )
goto V_298;
if ( F_124 ( & V_36 -> V_300 ) &&
! F_125 ( V_36 -> V_102 , L_72 , & V_251 ) )
F_126 ( V_251 , V_36 , F_101 ) ;
F_127 ( & V_51 -> V_203 , & V_36 -> V_300 ) ;
return 0 ;
V_298:
F_91 ( V_51 ) ;
return V_54 ;
}
void F_128 ( struct V_301 * V_6 )
{
struct V_100 * V_51 ;
V_51 = F_129 ( V_6 , struct V_100 , V_203 ) ;
F_108 ( V_51 -> V_229 ) ;
F_108 ( V_51 -> V_231 ) ;
}
