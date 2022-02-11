static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , T_1 V_6 )
{
struct V_7 * V_8 ;
V_8 = F_4 ( sizeof( struct V_7 ) , V_9 ) ;
if ( ! V_8 ) {
F_5 ( L_1 ) ;
return - V_10 ;
}
V_8 -> V_11 = V_6 ;
V_8 -> V_12 = V_13 ;
V_5 -> V_14 = V_8 ;
F_6 ( L_2
L_3 , V_5 -> V_15 ,
V_16 , V_17 ) ;
F_6 ( L_4 ,
V_5 -> V_15 ) ;
return 0 ;
}
static void F_7 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_14 ;
struct V_18 * V_19 = V_8 -> V_20 ;
if ( V_19 ) {
F_8 ( V_19 ) ;
F_6 ( L_5
L_6 , V_5 -> V_15 ,
( V_19 -> V_21 -> V_22 ) ? ( V_19 -> V_21 -> V_22 ) :
L_7 ) ;
} else
F_6 ( L_8
L_9 , V_5 -> V_15 ) ;
F_9 ( V_8 ) ;
V_5 -> V_14 = NULL ;
}
static int F_10 ( struct V_4 * V_5 , unsigned long V_23 )
{
struct V_7 * V_8 = V_5 -> V_14 ;
struct V_18 * V_24 = V_8 -> V_20 ;
if ( ! V_23 ) {
if ( ! V_24 )
return 0 ;
V_8 -> V_20 = NULL ;
V_8 -> V_12 = V_13 ;
F_6 ( L_10
L_11 , V_5 -> V_15 , ( V_24 -> V_21 -> V_22 ) ?
( V_24 -> V_21 -> V_22 ) : L_7 ) ;
F_8 ( V_24 ) ;
return 0 ;
}
V_24 = F_11 ( V_8 -> V_11 ) ;
if ( ! V_24 ) {
F_5 ( L_12
L_13 , V_8 -> V_11 ) ;
return - V_25 ;
}
V_8 -> V_20 = V_24 ;
V_8 -> V_12 = V_26 ;
F_6 ( L_14 ,
V_5 -> V_15 , ( V_24 -> V_21 -> V_22 ) ? ( V_24 -> V_21 -> V_22 ) : L_7 ) ;
return 1 ;
}
static void F_12 ( struct V_2 * V_3 ,
struct V_27 * V_28 )
{
unsigned char V_29 [ V_30 ] , * V_31 ;
int V_32 ;
V_31 = F_4 ( 12 , V_9 ) ;
if ( ! V_31 )
return;
memset ( V_29 , 0 , V_30 ) ;
V_29 [ 0 ] = V_33 ;
V_29 [ 4 ] = 0x0c ;
V_32 = F_13 ( V_28 , V_29 , V_34 , V_31 , 12 , NULL ,
V_35 , 1 , NULL ) ;
if ( V_32 )
goto V_36;
V_28 -> V_37 = ( V_31 [ 9 ] << 16 ) | ( V_31 [ 10 ] << 8 ) | ( V_31 [ 11 ] ) ;
if ( ! V_28 -> V_37 )
V_28 -> V_37 = 1024 ;
V_36:
F_9 ( V_31 ) ;
}
static void
F_14 ( struct V_27 * V_28 , struct V_38 * V_39 )
{
unsigned char * V_31 ;
if ( V_28 -> V_40 < V_41 )
return;
V_31 = V_28 -> V_42 ;
if ( ! V_31 )
return;
memcpy ( & V_39 -> V_43 [ 0 ] , & V_31 [ 8 ] , sizeof( V_39 -> V_43 ) ) ;
memcpy ( & V_39 -> V_44 [ 0 ] , & V_31 [ 16 ] , sizeof( V_39 -> V_44 ) ) ;
memcpy ( & V_39 -> V_45 [ 0 ] , & V_31 [ 32 ] , sizeof( V_39 -> V_45 ) ) ;
}
static int
F_15 ( struct V_27 * V_28 , struct V_38 * V_39 )
{
unsigned char V_29 [ V_30 ] , * V_31 ;
int V_32 ;
V_31 = F_4 ( V_46 , V_9 ) ;
if ( ! V_31 )
return - V_10 ;
memset ( V_29 , 0 , V_30 ) ;
V_29 [ 0 ] = V_47 ;
V_29 [ 1 ] = 0x01 ;
V_29 [ 2 ] = 0x80 ;
V_29 [ 3 ] = ( V_46 >> 8 ) & 0xff ;
V_29 [ 4 ] = ( V_46 & 0xff ) ;
V_32 = F_13 ( V_28 , V_29 , V_34 , V_31 ,
V_46 , NULL , V_35 , 1 , NULL ) ;
if ( V_32 )
goto V_36;
snprintf ( & V_39 -> V_48 [ 0 ] , V_46 , L_15 , & V_31 [ 4 ] ) ;
V_39 -> V_49 -> V_50 |= V_51 ;
F_9 ( V_31 ) ;
return 0 ;
V_36:
F_9 ( V_31 ) ;
return - V_52 ;
}
static void
F_16 ( struct V_27 * V_28 ,
struct V_38 * V_39 )
{
unsigned char V_29 [ V_30 ] , * V_31 , * V_53 ;
int V_54 , V_55 , V_56 = 4 , V_32 ;
struct V_57 * V_58 ;
V_31 = F_4 ( V_46 , V_9 ) ;
if ( ! V_31 )
return;
memset ( V_29 , 0 , V_30 ) ;
V_29 [ 0 ] = V_47 ;
V_29 [ 1 ] = 0x01 ;
V_29 [ 2 ] = 0x83 ;
V_29 [ 3 ] = ( V_59 >> 8 ) & 0xff ;
V_29 [ 4 ] = ( V_59 & 0xff ) ;
V_32 = F_13 ( V_28 , V_29 , V_34 , V_31 ,
V_59 ,
NULL , V_35 , 1 , NULL ) ;
if ( V_32 )
goto V_60;
V_55 = ( V_31 [ 2 ] << 8 ) | V_31 [ 3 ] ;
while ( V_55 > 0 ) {
V_53 = & V_31 [ V_56 ] ;
V_54 = V_53 [ 3 ] ;
if ( ! V_54 ) {
F_5 ( L_16
L_17 ) ;
break;
}
F_6 ( L_18 , V_54 ) ;
V_58 = F_4 ( sizeof( struct V_57 ) , V_9 ) ;
if ( ! V_58 ) {
F_5 ( L_19
L_20 ) ;
goto V_60;
}
F_17 ( & V_58 -> V_61 ) ;
F_18 ( V_58 , V_53 ) ;
F_19 ( V_58 , V_53 ) ;
if ( F_20 ( V_58 , V_53 ) < 0 ) {
V_56 += ( V_54 + 4 ) ;
V_55 -= ( V_54 + 4 ) ;
F_9 ( V_58 ) ;
continue;
}
if ( F_21 ( V_58 , V_53 ) < 0 ) {
V_56 += ( V_54 + 4 ) ;
V_55 -= ( V_54 + 4 ) ;
F_9 ( V_58 ) ;
continue;
}
F_22 ( & V_58 -> V_61 , & V_39 -> V_62 ) ;
V_56 += ( V_54 + 4 ) ;
V_55 -= ( V_54 + 4 ) ;
}
V_60:
F_9 ( V_31 ) ;
}
static int F_23 ( struct V_2 * V_3 ,
struct V_27 * V_63 )
{
struct V_1 * V_64 = F_1 ( V_3 ) ;
struct V_65 * V_66 = V_63 -> V_65 ;
V_64 -> V_67 = V_63 ;
if ( ! V_63 -> V_68 ) {
V_63 -> V_68 = V_69 ;
F_5 ( L_21
L_22 , V_63 -> V_70 , V_63 -> V_71 ,
V_63 -> V_72 , V_63 -> V_68 ) ;
}
V_3 -> V_73 . V_74 = V_63 -> V_37 ;
V_3 -> V_73 . V_75 =
F_24 ( int , V_63 -> V_76 -> V_77 , F_25 ( V_66 ) ) ;
V_3 -> V_73 . V_78 = V_63 -> V_68 ;
F_14 ( V_63 , & V_3 -> V_38 ) ;
if ( ! F_15 ( V_63 , & V_3 -> V_38 ) ) {
F_16 ( V_63 , & V_3 -> V_38 ) ;
}
if ( V_63 -> type == V_79 )
F_12 ( V_3 , V_63 ) ;
return 0 ;
}
static struct V_2 * F_26 ( struct V_4 * V_5 ,
const char * V_22 )
{
struct V_1 * V_64 ;
V_64 = F_4 ( sizeof( struct V_1 ) , V_9 ) ;
if ( ! V_64 ) {
F_5 ( L_23 ) ;
return NULL ;
}
F_6 ( L_24 , V_64 , V_22 ) ;
return & V_64 -> V_3 ;
}
static int F_27 ( struct V_2 * V_3 , struct V_27 * V_63 )
__releases( V_24 -> V_80 )
{
struct V_7 * V_8 = V_3 -> V_4 -> V_14 ;
struct V_1 * V_64 = F_1 ( V_3 ) ;
struct V_18 * V_24 = V_63 -> V_76 ;
struct V_81 * V_82 ;
int V_32 ;
if ( F_28 ( V_63 ) ) {
F_5 ( L_25 ,
V_24 -> V_83 , V_63 -> V_70 , V_63 -> V_71 , V_63 -> V_72 ) ;
F_29 ( V_24 -> V_80 ) ;
return - V_84 ;
}
F_29 ( V_24 -> V_80 ) ;
V_82 = F_30 ( V_3 -> V_85 ,
V_86 | V_87 | V_88 , V_64 ) ;
if ( F_31 ( V_82 ) ) {
F_5 ( L_26 ) ;
F_32 ( V_63 ) ;
return F_33 ( V_82 ) ;
}
V_64 -> V_89 = V_82 ;
V_32 = F_23 ( V_3 , V_63 ) ;
if ( V_32 ) {
F_34 ( V_64 -> V_89 , V_86 | V_87 | V_88 ) ;
F_32 ( V_63 ) ;
return V_32 ;
}
F_6 ( L_27 ,
V_8 -> V_11 , V_24 -> V_83 , V_63 -> V_70 , V_63 -> V_71 , V_63 -> V_72 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , struct V_27 * V_63 )
__releases( V_24 -> V_80 )
{
struct V_7 * V_8 = V_3 -> V_4 -> V_14 ;
struct V_18 * V_24 = V_63 -> V_76 ;
int V_32 ;
if ( F_28 ( V_63 ) ) {
F_5 ( L_25 ,
V_24 -> V_83 , V_63 -> V_70 , V_63 -> V_71 , V_63 -> V_72 ) ;
F_29 ( V_24 -> V_80 ) ;
return - V_84 ;
}
F_29 ( V_24 -> V_80 ) ;
V_32 = F_23 ( V_3 , V_63 ) ;
if ( V_32 ) {
F_32 ( V_63 ) ;
return V_32 ;
}
F_6 ( L_28 ,
V_8 -> V_11 , F_36 ( V_63 -> type ) , V_24 -> V_83 ,
V_63 -> V_70 , V_63 -> V_71 , V_63 -> V_72 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 ,
struct V_27 * V_63 )
__releases( V_24 -> V_80 )
{
struct V_7 * V_8 = V_3 -> V_4 -> V_14 ;
struct V_18 * V_24 = V_63 -> V_76 ;
int V_32 ;
F_29 ( V_24 -> V_80 ) ;
V_32 = F_23 ( V_3 , V_63 ) ;
if ( V_32 )
return V_32 ;
F_6 ( L_28 ,
V_8 -> V_11 , F_36 ( V_63 -> type ) , V_24 -> V_83 ,
V_63 -> V_70 , V_63 -> V_71 , V_63 -> V_72 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_4 ;
struct V_1 * V_64 = F_1 ( V_3 ) ;
struct V_27 * V_63 ;
struct V_7 * V_8 = V_3 -> V_4 -> V_14 ;
struct V_18 * V_24 = V_8 -> V_20 ;
int V_90 = 0 ;
int V_32 ;
if ( ! ( V_64 -> V_91 & V_92 ) ||
! ( V_64 -> V_91 & V_93 ) ||
! ( V_64 -> V_91 & V_94 ) ) {
F_5 ( L_29
L_30 ) ;
return - V_25 ;
}
if ( ! V_24 ) {
if ( V_8 -> V_12 == V_26 ) {
F_5 ( L_31
L_32 ) ;
return - V_95 ;
}
if ( ! ( V_3 -> V_50 & V_96 ) ) {
F_5 ( L_33
L_34 ) ;
return - V_25 ;
}
if ( ! ( V_64 -> V_91 & V_97 ) ) {
if ( V_5 -> V_98 ) {
F_5 ( L_35
L_36 ) ;
return - V_99 ;
}
if ( F_10 ( V_5 , 1 ) != 1 )
return - V_95 ;
V_90 = 1 ;
V_5 -> V_100 |= V_101 ;
V_24 = V_8 -> V_20 ;
} else {
V_24 = F_11 ( V_64 -> V_102 ) ;
if ( ! V_24 ) {
F_5 ( L_37
L_38 , V_64 -> V_102 ) ;
return - V_25 ;
}
}
} else {
if ( V_8 -> V_12 == V_13 ) {
F_5 ( L_39
L_40 ) ;
return - V_99 ;
}
}
F_39 ( V_24 -> V_80 ) ;
F_40 (sd, &sh->__devices, siblings) {
if ( ( V_64 -> V_103 != V_63 -> V_70 ) ||
( V_64 -> V_104 != V_63 -> V_71 ) ||
( V_64 -> V_105 != V_63 -> V_72 ) )
continue;
switch ( V_63 -> type ) {
case V_106 :
V_32 = F_27 ( V_3 , V_63 ) ;
break;
case V_107 :
V_32 = F_35 ( V_3 , V_63 ) ;
break;
default:
V_32 = F_37 ( V_3 , V_63 ) ;
break;
}
if ( V_32 ) {
if ( V_8 -> V_12 == V_13 )
F_8 ( V_24 ) ;
else if ( V_90 ) {
F_10 ( V_5 , 0 ) ;
V_5 -> V_100 &= ~ V_101 ;
}
V_64 -> V_67 = NULL ;
return V_32 ;
}
return 0 ;
}
F_29 ( V_24 -> V_80 ) ;
F_5 ( L_41 , V_24 -> V_83 ,
V_64 -> V_103 , V_64 -> V_104 , V_64 -> V_105 ) ;
if ( V_8 -> V_12 == V_13 )
F_8 ( V_24 ) ;
else if ( V_90 ) {
F_10 ( V_5 , 0 ) ;
V_5 -> V_100 &= ~ V_101 ;
}
return - V_95 ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_1 * V_64 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_4 -> V_14 ;
struct V_27 * V_63 = V_64 -> V_67 ;
if ( V_63 ) {
if ( ( V_63 -> type == V_106 ) && V_64 -> V_89 ) {
F_34 ( V_64 -> V_89 ,
V_86 | V_87 | V_88 ) ;
V_64 -> V_89 = NULL ;
}
if ( ( V_8 -> V_12 == V_26 ) &&
( V_8 -> V_20 != NULL ) )
F_8 ( V_8 -> V_20 ) ;
if ( ( V_63 -> type == V_106 ) || ( V_63 -> type == V_107 ) )
F_32 ( V_63 ) ;
V_64 -> V_67 = NULL ;
}
F_9 ( V_64 ) ;
}
static void F_42 ( struct V_108 * V_109 , struct V_110 * V_111 ,
unsigned char * V_112 )
{
struct V_1 * V_64 = F_1 ( V_109 -> V_113 ) ;
struct V_27 * V_63 = V_64 -> V_67 ;
int V_114 ;
struct V_115 * V_116 = V_109 -> V_117 ;
unsigned char * V_29 ;
if ( ! V_116 )
return;
V_29 = & V_116 -> V_118 [ 0 ] ;
V_114 = V_116 -> V_119 ;
if ( ! V_109 -> V_120 || ! V_109 -> V_121 )
goto V_122;
if ( ( ( V_29 [ 0 ] == V_33 ) || ( V_29 [ 0 ] == V_123 ) ) &&
( F_43 ( V_114 ) << 1 ) == V_124 ) {
if ( V_109 -> V_120 -> V_125 & V_126 ) {
unsigned char * V_31 ;
V_31 = F_44 ( V_109 ) ;
if ( ! V_31 )
;
if ( V_29 [ 0 ] == V_123 ) {
if ( ! ( V_31 [ 3 ] & 0x80 ) )
V_31 [ 3 ] |= 0x80 ;
} else {
if ( ! ( V_31 [ 2 ] & 0x80 ) )
V_31 [ 2 ] |= 0x80 ;
}
F_45 ( V_109 ) ;
}
}
V_122:
if ( V_63 -> type != V_79 || ! V_109 -> V_121 )
goto V_127;
if ( ( ( V_29 [ 0 ] == V_128 ) || ( V_29 [ 0 ] == V_129 ) ) &&
( F_43 ( V_114 ) << 1 ) == V_124 ) {
unsigned char * V_31 ;
T_2 V_130 ;
T_1 V_131 ;
V_31 = F_46 ( & V_111 [ 0 ] ) ;
if ( ! V_31 ) {
F_5 ( L_42 ) ;
goto V_127;
}
if ( V_29 [ 0 ] == V_128 )
V_130 = ( V_31 [ 3 ] ) ;
else
V_130 = ( V_31 [ 6 ] << 8 ) | ( V_31 [ 7 ] ) ;
if ( ! V_130 )
goto V_127;
if ( V_29 [ 0 ] == V_128 )
V_131 = ( V_31 [ 9 ] << 16 ) | ( V_31 [ 10 ] << 8 ) |
( V_31 [ 11 ] ) ;
else
V_131 = ( V_31 [ 13 ] << 16 ) | ( V_31 [ 14 ] << 8 ) |
( V_31 [ 15 ] ) ;
V_63 -> V_37 = V_131 ;
}
V_127:
if ( V_112 && ( F_43 ( V_114 ) & V_132 ) ) {
memcpy ( V_112 , V_116 -> V_133 , V_134 ) ;
V_109 -> V_135 |= V_136 ;
}
}
static T_3 F_47 ( struct V_2 * V_3 ,
const char * V_137 , T_3 V_138 )
{
struct V_1 * V_64 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_4 -> V_14 ;
char * V_139 , * V_140 , * V_141 ;
T_4 args [ V_142 ] ;
int V_32 = 0 , V_143 , V_144 ;
V_141 = F_48 ( V_137 , V_9 ) ;
if ( ! V_141 )
return - V_10 ;
V_139 = V_141 ;
while ( ( V_140 = F_49 ( & V_141 , L_43 ) ) != NULL ) {
if ( ! * V_140 )
continue;
V_144 = F_50 ( V_140 , V_145 , args ) ;
switch ( V_144 ) {
case V_146 :
if ( V_8 -> V_12 == V_26 ) {
F_5 ( L_44
L_45
L_46 ,
V_8 -> V_11 ) ;
V_32 = - V_25 ;
goto V_60;
}
V_32 = F_51 ( args , & V_143 ) ;
if ( V_32 )
goto V_60;
V_64 -> V_102 = V_143 ;
F_6 ( L_47
L_48 , V_8 -> V_11 , V_64 -> V_102 ) ;
V_64 -> V_91 |= V_97 ;
break;
case V_147 :
V_32 = F_51 ( args , & V_143 ) ;
if ( V_32 )
goto V_60;
V_64 -> V_103 = V_143 ;
F_6 ( L_49
L_50 , V_8 -> V_11 ,
V_64 -> V_103 ) ;
V_64 -> V_91 |= V_92 ;
break;
case V_148 :
V_32 = F_51 ( args , & V_143 ) ;
if ( V_32 )
goto V_60;
V_64 -> V_104 = V_143 ;
F_6 ( L_51
L_50 , V_8 -> V_11 ,
V_64 -> V_104 ) ;
V_64 -> V_91 |= V_93 ;
break;
case V_149 :
V_32 = F_51 ( args , & V_143 ) ;
if ( V_32 )
goto V_60;
V_64 -> V_105 = V_143 ;
F_6 ( L_52
L_48 , V_8 -> V_11 , V_64 -> V_105 ) ;
V_64 -> V_91 |= V_94 ;
break;
default:
break;
}
}
V_60:
F_9 ( V_139 ) ;
return ( ! V_32 ) ? V_138 : V_32 ;
}
static T_3 F_52 ( struct V_2 * V_3 , char * V_150 )
{
struct V_7 * V_8 = V_3 -> V_4 -> V_14 ;
struct V_1 * V_64 = F_1 ( V_3 ) ;
struct V_27 * V_63 = V_64 -> V_67 ;
unsigned char V_6 [ 16 ] ;
T_3 V_151 ;
int V_152 ;
if ( V_8 -> V_12 == V_13 )
snprintf ( V_6 , 16 , L_53 , V_64 -> V_102 ) ;
else
snprintf ( V_6 , 16 , L_54 ) ;
V_151 = sprintf ( V_150 , L_55
L_56 ,
V_64 -> V_103 , V_64 -> V_104 , V_64 -> V_105 ,
V_6 ) ;
if ( V_63 ) {
V_151 += sprintf ( V_150 + V_151 , L_57 ) ;
V_151 += sprintf ( V_150 + V_151 , L_58 ) ;
for ( V_152 = 0 ; V_152 < 8 ; V_152 ++ ) {
if ( ISPRINT ( V_63 -> V_43 [ V_152 ] ) )
V_151 += sprintf ( V_150 + V_151 , L_59 , V_63 -> V_43 [ V_152 ] ) ;
else
V_151 += sprintf ( V_150 + V_151 , L_60 ) ;
}
V_151 += sprintf ( V_150 + V_151 , L_61 ) ;
for ( V_152 = 0 ; V_152 < 16 ; V_152 ++ ) {
if ( ISPRINT ( V_63 -> V_44 [ V_152 ] ) )
V_151 += sprintf ( V_150 + V_151 , L_59 , V_63 -> V_44 [ V_152 ] ) ;
else
V_151 += sprintf ( V_150 + V_151 , L_60 ) ;
}
V_151 += sprintf ( V_150 + V_151 , L_62 ) ;
for ( V_152 = 0 ; V_152 < 4 ; V_152 ++ ) {
if ( ISPRINT ( V_63 -> V_153 [ V_152 ] ) )
V_151 += sprintf ( V_150 + V_151 , L_59 , V_63 -> V_153 [ V_152 ] ) ;
else
V_151 += sprintf ( V_150 + V_151 , L_60 ) ;
}
V_151 += sprintf ( V_150 + V_151 , L_63 ) ;
}
return V_151 ;
}
static void F_53 ( struct V_154 * V_154 , int error )
{
F_54 ( V_154 ) ;
}
static inline struct V_154 * F_55 ( int V_155 )
{
struct V_154 * V_154 ;
V_154 = F_56 ( V_9 , V_155 ) ;
if ( ! V_154 ) {
F_5 ( L_64 ) ;
return NULL ;
}
V_154 -> V_156 = F_53 ;
return V_154 ;
}
static T_5
F_57 ( struct V_108 * V_109 , struct V_110 * V_157 , T_1 V_158 ,
enum V_159 V_160 , struct V_154 * * V_161 )
{
struct V_1 * V_64 = F_1 ( V_109 -> V_113 ) ;
struct V_154 * V_154 = NULL , * V_162 = NULL ;
struct V_137 * V_137 ;
struct V_110 * V_111 ;
T_1 V_163 = V_109 -> V_121 , V_152 , V_164 , V_165 , V_56 ;
int V_166 = ( V_109 -> V_121 + V_157 [ 0 ] . V_167 +
V_168 - 1 ) >> V_169 ;
int V_155 = 0 , V_170 ;
int V_171 = ( V_160 == V_172 ) ;
* V_161 = NULL ;
F_6 ( L_65 , V_166 ) ;
F_58 (sgl, sg, sgl_nents, i) {
V_137 = F_59 ( V_111 ) ;
V_56 = V_111 -> V_167 ;
V_164 = V_111 -> V_173 ;
F_6 ( L_66 , V_152 ,
V_137 , V_164 , V_56 ) ;
if ( V_56 + V_164 > V_168 )
goto V_174;
if ( V_164 > 0 && V_163 > 0 ) {
V_165 = F_24 (unsigned int, len, PAGE_SIZE - off) ;
V_165 = F_60 ( V_165 , V_163 ) ;
if ( ! V_154 ) {
V_155 = F_24 ( int , V_175 , V_166 ) ;
V_166 -= V_155 ;
V_154 = F_55 ( V_155 ) ;
if ( ! V_154 )
goto V_174;
if ( V_171 )
V_154 -> V_176 |= V_177 ;
F_6 ( L_67
L_68 , V_154 ,
( V_171 ) ? L_69 : L_70 , V_155 ) ;
if ( ! * V_161 )
* V_161 = V_162 = V_154 ;
else
V_162 = V_162 -> V_178 = V_154 ;
}
F_6 ( L_71
L_72 , V_152 , V_154 ,
V_137 , V_164 , V_56 ) ;
V_170 = F_61 ( V_64 -> V_67 -> V_65 ,
V_154 , V_137 , V_165 , V_56 ) ;
if ( V_170 != V_165 )
goto V_174;
F_6 ( L_73 ,
V_154 -> V_179 , V_155 ) ;
if ( V_154 -> V_179 > V_155 ) {
F_6 ( L_74
L_75
L_76 , V_154 -> V_179 , V_152 , V_154 ) ;
V_154 = NULL ;
}
V_163 -= V_165 ;
}
}
return 0 ;
V_174:
while ( * V_161 ) {
V_154 = * V_161 ;
* V_161 = ( * V_161 ) -> V_178 ;
F_62 ( V_154 , 0 ) ;
}
return V_180 ;
}
static inline void F_63 ( unsigned char * V_29 )
{
switch ( V_29 [ 0 ] ) {
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
break;
default:
V_29 [ 1 ] &= 0x1f ;
break;
}
}
static T_5
F_64 ( struct V_108 * V_109 )
{
unsigned char * V_29 = V_109 -> V_190 ;
if ( V_109 -> V_135 & V_191 )
return V_192 ;
F_63 ( V_29 ) ;
switch ( V_29 [ 0 ] ) {
case V_193 :
V_109 -> V_194 = V_195 ;
return 0 ;
case V_196 :
case V_181 :
case V_182 :
case V_183 :
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_187 :
V_109 -> V_135 |= V_201 ;
default:
V_109 -> V_194 = V_202 ;
return 0 ;
}
}
static T_5
V_202 ( struct V_108 * V_109 )
{
struct V_110 * V_157 = V_109 -> V_203 ;
T_1 V_158 = V_109 -> V_204 ;
enum V_159 V_160 = V_109 -> V_160 ;
struct V_1 * V_64 = F_1 ( V_109 -> V_113 ) ;
struct V_115 * V_116 ;
struct V_205 * V_206 ;
struct V_154 * V_161 ;
T_5 V_32 ;
V_116 = F_4 ( sizeof( * V_116 ) + F_65 ( V_109 -> V_190 ) , V_9 ) ;
if ( ! V_116 ) {
return V_180 ;
}
V_109 -> V_117 = V_116 ;
memcpy ( V_116 -> V_118 , V_109 -> V_190 ,
F_65 ( V_109 -> V_190 ) ) ;
if ( ! V_157 ) {
V_206 = F_66 ( V_64 -> V_67 -> V_65 ,
( V_160 == V_172 ) ,
V_9 ) ;
if ( F_31 ( V_206 ) ) {
F_5 ( L_77 ) ;
V_32 = V_180 ;
goto V_174;
}
F_67 ( V_206 ) ;
} else {
F_68 ( ! V_109 -> V_121 ) ;
V_32 = F_57 ( V_109 , V_157 , V_158 , V_160 , & V_161 ) ;
if ( V_32 )
goto V_174;
V_206 = F_69 ( V_64 -> V_67 -> V_65 , V_161 ,
V_9 ) ;
if ( F_31 ( V_206 ) ) {
F_5 ( L_78 ) ;
V_32 = V_180 ;
goto V_207;
}
}
V_206 -> V_208 = V_209 ;
V_206 -> V_210 = V_109 ;
V_206 -> V_211 = F_65 ( V_116 -> V_118 ) ;
V_206 -> V_109 = & V_116 -> V_118 [ 0 ] ;
V_206 -> V_212 = & V_116 -> V_133 [ 0 ] ;
V_206 -> V_213 = 0 ;
if ( V_64 -> V_67 -> type == V_106 )
V_206 -> V_214 = V_215 ;
else
V_206 -> V_214 = V_216 ;
V_206 -> V_217 = V_218 ;
F_70 ( V_64 -> V_67 -> V_65 , NULL , V_206 ,
( V_109 -> V_219 == V_220 ) ,
V_209 ) ;
return 0 ;
V_207:
while ( V_161 ) {
struct V_154 * V_154 = V_161 ;
V_161 = V_161 -> V_178 ;
F_62 ( V_154 , 0 ) ;
}
V_32 = V_180 ;
V_174:
F_9 ( V_116 ) ;
return V_32 ;
}
static T_1 F_71 ( struct V_2 * V_3 )
{
struct V_1 * V_64 = F_1 ( V_3 ) ;
struct V_27 * V_63 = V_64 -> V_67 ;
return ( V_63 ) ? V_63 -> type : V_221 ;
}
static T_6 F_72 ( struct V_2 * V_3 )
{
struct V_1 * V_64 = F_1 ( V_3 ) ;
if ( V_64 -> V_89 && V_64 -> V_89 -> V_222 )
return V_64 -> V_89 -> V_222 -> V_223 ;
F_73 () ;
return 0 ;
}
static void V_209 ( struct V_205 * V_206 , int V_224 )
{
struct V_108 * V_109 = V_206 -> V_210 ;
struct V_115 * V_116 = V_109 -> V_117 ;
V_116 -> V_119 = V_206 -> V_225 ;
V_116 -> V_226 = V_206 -> V_227 ;
V_109 -> V_228 = F_43 ( V_116 -> V_119 ) << 1 ;
if ( V_109 -> V_228 ) {
F_6 ( L_79
L_80 , V_109 , V_116 -> V_118 [ 0 ] ,
V_116 -> V_119 ) ;
}
switch ( F_74 ( V_116 -> V_119 ) ) {
case V_229 :
F_75 ( V_109 , V_109 -> V_228 ) ;
break;
default:
F_6 ( L_81
L_80 , V_109 , V_116 -> V_118 [ 0 ] ,
V_116 -> V_119 ) ;
F_75 ( V_109 , V_230 ) ;
break;
}
F_76 ( V_206 -> V_66 , V_206 ) ;
F_9 ( V_116 ) ;
}
static int T_7 F_77 ( void )
{
struct V_231 * V_232 = & V_233 . V_234 ;
F_78 ( & V_233 ) ;
V_232 -> V_235 . V_236 = V_237 ;
return F_79 ( & V_233 ) ;
}
static void T_8 F_80 ( void )
{
F_81 ( & V_233 ) ;
}
