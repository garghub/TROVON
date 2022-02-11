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
if ( F_12 ( V_24 ) ) {
F_5 ( L_12
L_13 , V_8 -> V_11 ) ;
return F_13 ( V_24 ) ;
}
V_8 -> V_20 = V_24 ;
V_8 -> V_12 = V_25 ;
F_6 ( L_14 ,
V_5 -> V_15 , ( V_24 -> V_21 -> V_22 ) ? ( V_24 -> V_21 -> V_22 ) : L_7 ) ;
return 1 ;
}
static void F_14 ( struct V_2 * V_3 ,
struct V_26 * V_27 )
{
unsigned char V_28 [ V_29 ] , * V_30 ;
int V_31 ;
V_30 = F_4 ( 12 , V_9 ) ;
if ( ! V_30 )
return;
memset ( V_28 , 0 , V_29 ) ;
V_28 [ 0 ] = V_32 ;
V_28 [ 4 ] = 0x0c ;
V_31 = F_15 ( V_27 , V_28 , V_33 , V_30 , 12 , NULL ,
V_34 , 1 , NULL ) ;
if ( V_31 )
goto V_35;
V_27 -> V_36 = ( V_30 [ 9 ] << 16 ) | ( V_30 [ 10 ] << 8 ) | ( V_30 [ 11 ] ) ;
if ( ! V_27 -> V_36 )
V_27 -> V_36 = 1024 ;
V_35:
F_9 ( V_30 ) ;
}
static void
F_16 ( struct V_26 * V_27 , struct V_37 * V_38 )
{
unsigned char * V_30 ;
if ( V_27 -> V_39 < V_40 )
return;
V_30 = V_27 -> V_41 ;
if ( ! V_30 )
return;
memcpy ( & V_38 -> V_42 [ 0 ] , & V_30 [ 8 ] , sizeof( V_38 -> V_42 ) ) ;
memcpy ( & V_38 -> V_43 [ 0 ] , & V_30 [ 16 ] , sizeof( V_38 -> V_43 ) ) ;
memcpy ( & V_38 -> V_44 [ 0 ] , & V_30 [ 32 ] , sizeof( V_38 -> V_44 ) ) ;
}
static int
F_17 ( struct V_26 * V_27 , struct V_37 * V_38 )
{
unsigned char V_28 [ V_29 ] , * V_30 ;
int V_31 ;
V_30 = F_4 ( V_45 , V_9 ) ;
if ( ! V_30 )
return - V_10 ;
memset ( V_28 , 0 , V_29 ) ;
V_28 [ 0 ] = V_46 ;
V_28 [ 1 ] = 0x01 ;
V_28 [ 2 ] = 0x80 ;
V_28 [ 3 ] = ( V_45 >> 8 ) & 0xff ;
V_28 [ 4 ] = ( V_45 & 0xff ) ;
V_31 = F_15 ( V_27 , V_28 , V_33 , V_30 ,
V_45 , NULL , V_34 , 1 , NULL ) ;
if ( V_31 )
goto V_35;
snprintf ( & V_38 -> V_47 [ 0 ] , V_45 , L_15 , & V_30 [ 4 ] ) ;
V_38 -> V_48 -> V_49 |= V_50 ;
F_9 ( V_30 ) ;
return 0 ;
V_35:
F_9 ( V_30 ) ;
return - V_51 ;
}
static void
F_18 ( struct V_26 * V_27 ,
struct V_37 * V_38 )
{
unsigned char V_28 [ V_29 ] , * V_30 , * V_52 ;
int V_53 , V_54 , V_55 = 4 , V_31 ;
struct V_56 * V_57 ;
V_30 = F_4 ( V_45 , V_9 ) ;
if ( ! V_30 )
return;
memset ( V_28 , 0 , V_29 ) ;
V_28 [ 0 ] = V_46 ;
V_28 [ 1 ] = 0x01 ;
V_28 [ 2 ] = 0x83 ;
V_28 [ 3 ] = ( V_58 >> 8 ) & 0xff ;
V_28 [ 4 ] = ( V_58 & 0xff ) ;
V_31 = F_15 ( V_27 , V_28 , V_33 , V_30 ,
V_58 ,
NULL , V_34 , 1 , NULL ) ;
if ( V_31 )
goto V_59;
V_54 = ( V_30 [ 2 ] << 8 ) | V_30 [ 3 ] ;
while ( V_54 > 0 ) {
V_52 = & V_30 [ V_55 ] ;
V_53 = V_52 [ 3 ] ;
if ( ! V_53 ) {
F_5 ( L_16
L_17 ) ;
break;
}
F_6 ( L_18 , V_53 ) ;
V_57 = F_4 ( sizeof( struct V_56 ) , V_9 ) ;
if ( ! V_57 ) {
F_5 ( L_19
L_20 ) ;
goto V_59;
}
F_19 ( & V_57 -> V_60 ) ;
F_20 ( V_57 , V_52 ) ;
F_21 ( V_57 , V_52 ) ;
if ( F_22 ( V_57 , V_52 ) < 0 ) {
V_55 += ( V_53 + 4 ) ;
V_54 -= ( V_53 + 4 ) ;
F_9 ( V_57 ) ;
continue;
}
if ( F_23 ( V_57 , V_52 ) < 0 ) {
V_55 += ( V_53 + 4 ) ;
V_54 -= ( V_53 + 4 ) ;
F_9 ( V_57 ) ;
continue;
}
F_24 ( & V_57 -> V_60 , & V_38 -> V_61 ) ;
V_55 += ( V_53 + 4 ) ;
V_54 -= ( V_53 + 4 ) ;
}
V_59:
F_9 ( V_30 ) ;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_26 * V_62 )
{
struct V_1 * V_63 = F_1 ( V_3 ) ;
struct V_64 * V_65 = V_62 -> V_64 ;
V_63 -> V_66 = V_62 ;
if ( ! V_62 -> V_67 ) {
V_62 -> V_67 = V_68 ;
F_5 ( L_21
L_22 , V_62 -> V_69 , V_62 -> V_70 ,
V_62 -> V_71 , V_62 -> V_67 ) ;
}
V_3 -> V_72 . V_73 = V_62 -> V_36 ;
V_3 -> V_72 . V_74 =
F_26 ( int , V_62 -> V_75 -> V_76 , F_27 ( V_65 ) ) ;
V_3 -> V_72 . V_77 = V_62 -> V_67 ;
F_16 ( V_62 , & V_3 -> V_37 ) ;
if ( ! F_17 ( V_62 , & V_3 -> V_37 ) ) {
F_18 ( V_62 , & V_3 -> V_37 ) ;
}
if ( V_62 -> type == V_78 )
F_14 ( V_3 , V_62 ) ;
return 0 ;
}
static struct V_2 * F_28 ( struct V_4 * V_5 ,
const char * V_22 )
{
struct V_1 * V_63 ;
V_63 = F_4 ( sizeof( struct V_1 ) , V_9 ) ;
if ( ! V_63 ) {
F_5 ( L_23 ) ;
return NULL ;
}
F_6 ( L_24 , V_63 , V_22 ) ;
return & V_63 -> V_3 ;
}
static int F_29 ( struct V_2 * V_3 , struct V_26 * V_62 )
__releases( V_24 -> V_79 )
{
struct V_7 * V_8 = V_3 -> V_4 -> V_14 ;
struct V_1 * V_63 = F_1 ( V_3 ) ;
struct V_18 * V_24 = V_62 -> V_75 ;
struct V_80 * V_81 ;
int V_31 ;
if ( F_30 ( V_62 ) ) {
F_5 ( L_25 ,
V_24 -> V_82 , V_62 -> V_69 , V_62 -> V_70 , V_62 -> V_71 ) ;
F_31 ( V_24 -> V_79 ) ;
return - V_83 ;
}
F_31 ( V_24 -> V_79 ) ;
V_81 = F_32 ( V_3 -> V_84 ,
V_85 | V_86 | V_87 , V_63 ) ;
if ( F_12 ( V_81 ) ) {
F_5 ( L_26 ) ;
F_33 ( V_62 ) ;
return F_13 ( V_81 ) ;
}
V_63 -> V_88 = V_81 ;
V_31 = F_25 ( V_3 , V_62 ) ;
if ( V_31 ) {
F_34 ( V_63 -> V_88 , V_85 | V_86 | V_87 ) ;
F_33 ( V_62 ) ;
return V_31 ;
}
F_6 ( L_27 ,
V_8 -> V_11 , V_24 -> V_82 , V_62 -> V_69 , V_62 -> V_70 , V_62 -> V_71 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , struct V_26 * V_62 )
__releases( V_24 -> V_79 )
{
struct V_7 * V_8 = V_3 -> V_4 -> V_14 ;
struct V_18 * V_24 = V_62 -> V_75 ;
int V_31 ;
if ( F_30 ( V_62 ) ) {
F_5 ( L_25 ,
V_24 -> V_82 , V_62 -> V_69 , V_62 -> V_70 , V_62 -> V_71 ) ;
F_31 ( V_24 -> V_79 ) ;
return - V_83 ;
}
F_31 ( V_24 -> V_79 ) ;
V_31 = F_25 ( V_3 , V_62 ) ;
if ( V_31 ) {
F_33 ( V_62 ) ;
return V_31 ;
}
F_6 ( L_28 ,
V_8 -> V_11 , F_36 ( V_62 -> type ) , V_24 -> V_82 ,
V_62 -> V_69 , V_62 -> V_70 , V_62 -> V_71 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 ,
struct V_26 * V_62 )
__releases( V_24 -> V_79 )
{
struct V_7 * V_8 = V_3 -> V_4 -> V_14 ;
struct V_18 * V_24 = V_62 -> V_75 ;
int V_31 ;
F_31 ( V_24 -> V_79 ) ;
V_31 = F_25 ( V_3 , V_62 ) ;
if ( V_31 )
return V_31 ;
F_6 ( L_28 ,
V_8 -> V_11 , F_36 ( V_62 -> type ) , V_24 -> V_82 ,
V_62 -> V_69 , V_62 -> V_70 , V_62 -> V_71 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_4 ;
struct V_1 * V_63 = F_1 ( V_3 ) ;
struct V_26 * V_62 ;
struct V_7 * V_8 = V_3 -> V_4 -> V_14 ;
struct V_18 * V_24 = V_8 -> V_20 ;
int V_89 = 0 ;
int V_31 ;
if ( ! ( V_63 -> V_90 & V_91 ) ||
! ( V_63 -> V_90 & V_92 ) ||
! ( V_63 -> V_90 & V_93 ) ) {
F_5 ( L_29
L_30 ) ;
return - V_94 ;
}
if ( ! V_24 ) {
if ( V_8 -> V_12 == V_25 ) {
F_5 ( L_31
L_32 ) ;
return - V_95 ;
}
if ( ! ( V_3 -> V_49 & V_96 ) ) {
F_5 ( L_33
L_34 ) ;
return - V_94 ;
}
if ( ! ( V_63 -> V_90 & V_97 ) ) {
if ( V_5 -> V_98 ) {
F_5 ( L_35
L_36 ) ;
return - V_99 ;
}
if ( F_10 ( V_5 , 1 ) != 1 )
return - V_95 ;
V_89 = 1 ;
V_5 -> V_100 |= V_101 ;
V_24 = V_8 -> V_20 ;
} else {
V_24 = F_11 ( V_63 -> V_102 ) ;
if ( F_12 ( V_24 ) ) {
F_5 ( L_37
L_38 , V_63 -> V_102 ) ;
return F_13 ( V_24 ) ;
}
}
} else {
if ( V_8 -> V_12 == V_13 ) {
F_5 ( L_39
L_40 ) ;
return - V_99 ;
}
}
F_39 ( V_24 -> V_79 ) ;
F_40 (sd, &sh->__devices, siblings) {
if ( ( V_63 -> V_103 != V_62 -> V_69 ) ||
( V_63 -> V_104 != V_62 -> V_70 ) ||
( V_63 -> V_105 != V_62 -> V_71 ) )
continue;
switch ( V_62 -> type ) {
case V_106 :
V_31 = F_29 ( V_3 , V_62 ) ;
break;
case V_107 :
V_31 = F_35 ( V_3 , V_62 ) ;
break;
default:
V_31 = F_37 ( V_3 , V_62 ) ;
break;
}
if ( V_31 ) {
if ( V_8 -> V_12 == V_13 )
F_8 ( V_24 ) ;
else if ( V_89 ) {
F_10 ( V_5 , 0 ) ;
V_5 -> V_100 &= ~ V_101 ;
}
V_63 -> V_66 = NULL ;
return V_31 ;
}
return 0 ;
}
F_31 ( V_24 -> V_79 ) ;
F_5 ( L_41 , V_24 -> V_82 ,
V_63 -> V_103 , V_63 -> V_104 , V_63 -> V_105 ) ;
if ( V_8 -> V_12 == V_13 )
F_8 ( V_24 ) ;
else if ( V_89 ) {
F_10 ( V_5 , 0 ) ;
V_5 -> V_100 &= ~ V_101 ;
}
return - V_95 ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_1 * V_63 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_4 -> V_14 ;
struct V_26 * V_62 = V_63 -> V_66 ;
if ( V_62 ) {
if ( ( V_62 -> type == V_106 ) && V_63 -> V_88 ) {
F_34 ( V_63 -> V_88 ,
V_85 | V_86 | V_87 ) ;
V_63 -> V_88 = NULL ;
}
if ( ( V_8 -> V_12 == V_25 ) &&
( V_8 -> V_20 != NULL ) )
F_8 ( V_8 -> V_20 ) ;
if ( ( V_62 -> type == V_106 ) || ( V_62 -> type == V_107 ) )
F_33 ( V_62 ) ;
V_63 -> V_66 = NULL ;
}
F_9 ( V_63 ) ;
}
static void F_42 ( struct V_108 * V_109 , struct V_110 * V_111 ,
unsigned char * V_112 )
{
struct V_1 * V_63 = F_1 ( V_109 -> V_113 ) ;
struct V_26 * V_62 = V_63 -> V_66 ;
int V_114 ;
struct V_115 * V_116 = V_109 -> V_117 ;
unsigned char * V_28 ;
if ( ! V_116 )
return;
V_28 = & V_116 -> V_118 [ 0 ] ;
V_114 = V_116 -> V_119 ;
if ( ! V_109 -> V_120 || ! V_109 -> V_121 )
goto V_122;
if ( ( ( V_28 [ 0 ] == V_32 ) || ( V_28 [ 0 ] == V_123 ) ) &&
( F_43 ( V_114 ) << 1 ) == V_124 ) {
if ( V_109 -> V_120 -> V_125 & V_126 ) {
unsigned char * V_30 ;
V_30 = F_44 ( V_109 ) ;
if ( ! V_30 )
;
if ( V_28 [ 0 ] == V_123 ) {
if ( ! ( V_30 [ 3 ] & 0x80 ) )
V_30 [ 3 ] |= 0x80 ;
} else {
if ( ! ( V_30 [ 2 ] & 0x80 ) )
V_30 [ 2 ] |= 0x80 ;
}
F_45 ( V_109 ) ;
}
}
V_122:
if ( V_62 -> type != V_78 || ! V_109 -> V_121 )
goto V_127;
if ( ( ( V_28 [ 0 ] == V_128 ) || ( V_28 [ 0 ] == V_129 ) ) &&
( F_43 ( V_114 ) << 1 ) == V_124 ) {
unsigned char * V_30 ;
T_2 V_130 ;
T_1 V_131 ;
V_30 = F_46 ( & V_111 [ 0 ] ) ;
if ( ! V_30 ) {
F_5 ( L_42 ) ;
goto V_127;
}
if ( V_28 [ 0 ] == V_128 )
V_130 = ( V_30 [ 3 ] ) ;
else
V_130 = ( V_30 [ 6 ] << 8 ) | ( V_30 [ 7 ] ) ;
if ( ! V_130 )
goto V_127;
if ( V_28 [ 0 ] == V_128 )
V_131 = ( V_30 [ 9 ] << 16 ) | ( V_30 [ 10 ] << 8 ) |
( V_30 [ 11 ] ) ;
else
V_131 = ( V_30 [ 13 ] << 16 ) | ( V_30 [ 14 ] << 8 ) |
( V_30 [ 15 ] ) ;
V_62 -> V_36 = V_131 ;
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
struct V_1 * V_63 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_4 -> V_14 ;
char * V_139 , * V_140 , * V_141 ;
T_4 args [ V_142 ] ;
int V_31 = 0 , V_143 , V_144 ;
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
if ( V_8 -> V_12 == V_25 ) {
F_5 ( L_44
L_45
L_46 ,
V_8 -> V_11 ) ;
V_31 = - V_94 ;
goto V_59;
}
F_51 ( args , & V_143 ) ;
V_63 -> V_102 = V_143 ;
F_6 ( L_47
L_48 , V_8 -> V_11 , V_63 -> V_102 ) ;
V_63 -> V_90 |= V_97 ;
break;
case V_147 :
F_51 ( args , & V_143 ) ;
V_63 -> V_103 = V_143 ;
F_6 ( L_49
L_50 , V_8 -> V_11 ,
V_63 -> V_103 ) ;
V_63 -> V_90 |= V_91 ;
break;
case V_148 :
F_51 ( args , & V_143 ) ;
V_63 -> V_104 = V_143 ;
F_6 ( L_51
L_50 , V_8 -> V_11 ,
V_63 -> V_104 ) ;
V_63 -> V_90 |= V_92 ;
break;
case V_149 :
F_51 ( args , & V_143 ) ;
V_63 -> V_105 = V_143 ;
F_6 ( L_52
L_48 , V_8 -> V_11 , V_63 -> V_105 ) ;
V_63 -> V_90 |= V_93 ;
break;
default:
break;
}
}
V_59:
F_9 ( V_139 ) ;
return ( ! V_31 ) ? V_138 : V_31 ;
}
static T_3 F_52 ( struct V_2 * V_3 , char * V_150 )
{
struct V_7 * V_8 = V_3 -> V_4 -> V_14 ;
struct V_1 * V_63 = F_1 ( V_3 ) ;
struct V_26 * V_62 = V_63 -> V_66 ;
unsigned char V_6 [ 16 ] ;
T_3 V_151 ;
int V_152 ;
if ( V_8 -> V_12 == V_13 )
snprintf ( V_6 , 16 , L_53 , V_63 -> V_102 ) ;
else
snprintf ( V_6 , 16 , L_54 ) ;
V_151 = sprintf ( V_150 , L_55
L_56 ,
V_63 -> V_103 , V_63 -> V_104 , V_63 -> V_105 ,
V_6 ) ;
if ( V_62 ) {
V_151 += sprintf ( V_150 + V_151 , L_57 ) ;
V_151 += sprintf ( V_150 + V_151 , L_58 ) ;
for ( V_152 = 0 ; V_152 < 8 ; V_152 ++ ) {
if ( ISPRINT ( V_62 -> V_42 [ V_152 ] ) )
V_151 += sprintf ( V_150 + V_151 , L_59 , V_62 -> V_42 [ V_152 ] ) ;
else
V_151 += sprintf ( V_150 + V_151 , L_60 ) ;
}
V_151 += sprintf ( V_150 + V_151 , L_61 ) ;
for ( V_152 = 0 ; V_152 < 16 ; V_152 ++ ) {
if ( ISPRINT ( V_62 -> V_43 [ V_152 ] ) )
V_151 += sprintf ( V_150 + V_151 , L_59 , V_62 -> V_43 [ V_152 ] ) ;
else
V_151 += sprintf ( V_150 + V_151 , L_60 ) ;
}
V_151 += sprintf ( V_150 + V_151 , L_62 ) ;
for ( V_152 = 0 ; V_152 < 4 ; V_152 ++ ) {
if ( ISPRINT ( V_62 -> V_153 [ V_152 ] ) )
V_151 += sprintf ( V_150 + V_151 , L_59 , V_62 -> V_153 [ V_152 ] ) ;
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
struct V_1 * V_63 = F_1 ( V_109 -> V_113 ) ;
struct V_154 * V_154 = NULL , * V_162 = NULL ;
struct V_137 * V_137 ;
struct V_110 * V_111 ;
T_1 V_163 = V_109 -> V_121 , V_152 , V_164 , V_165 , V_55 ;
int V_166 = ( V_109 -> V_121 + V_157 [ 0 ] . V_167 +
V_168 - 1 ) >> V_169 ;
int V_170 = 0 , V_171 ;
int V_172 = ( V_160 == V_173 ) ;
* V_161 = NULL ;
F_6 ( L_65 , V_166 ) ;
F_58 (sgl, sg, sgl_nents, i) {
V_137 = F_59 ( V_111 ) ;
V_55 = V_111 -> V_167 ;
V_164 = V_111 -> V_174 ;
F_6 ( L_66 , V_152 ,
V_137 , V_164 , V_55 ) ;
while ( V_164 > 0 && V_163 > 0 ) {
V_165 = F_26 (unsigned int, len, PAGE_SIZE - off) ;
V_165 = F_60 ( V_165 , V_163 ) ;
if ( ! V_154 ) {
V_170 = F_26 ( int , V_175 , V_166 ) ;
V_166 -= V_170 ;
V_154 = F_55 ( V_170 ) ;
if ( ! V_154 )
goto V_176;
if ( V_172 )
V_154 -> V_177 |= V_178 ;
F_6 ( L_67
L_68 , V_154 ,
( V_172 ) ? L_69 : L_70 , V_170 ) ;
if ( ! * V_161 )
* V_161 = V_162 = V_154 ;
else
V_162 = V_162 -> V_179 = V_154 ;
}
F_6 ( L_71
L_72 , V_152 , V_154 ,
V_137 , V_164 , V_55 ) ;
V_171 = F_61 ( V_63 -> V_66 -> V_64 ,
V_154 , V_137 , V_165 , V_55 ) ;
if ( V_171 != V_165 )
goto V_176;
F_6 ( L_73 ,
V_154 -> V_180 , V_170 ) ;
if ( V_154 -> V_180 > V_170 ) {
F_6 ( L_74
L_75
L_76 , V_154 -> V_180 , V_152 , V_154 ) ;
V_154 = NULL ;
}
V_137 ++ ;
V_164 -= V_165 ;
V_163 -= V_165 ;
V_55 = 0 ;
}
}
return 0 ;
V_176:
while ( * V_161 ) {
V_154 = * V_161 ;
* V_161 = ( * V_161 ) -> V_179 ;
V_154 -> V_179 = NULL ;
F_62 ( V_154 , 0 ) ;
}
return V_181 ;
}
static inline void F_63 ( unsigned char * V_28 )
{
switch ( V_28 [ 0 ] ) {
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
break;
default:
V_28 [ 1 ] &= 0x1f ;
break;
}
}
static T_5
F_64 ( struct V_108 * V_109 )
{
unsigned char * V_28 = V_109 -> V_191 ;
if ( V_109 -> V_135 & V_192 )
return V_193 ;
F_63 ( V_28 ) ;
switch ( V_28 [ 0 ] ) {
case V_194 :
V_109 -> V_195 = V_196 ;
return 0 ;
case V_197 :
case V_182 :
case V_183 :
case V_184 :
case V_198 :
case V_199 :
case V_200 :
case V_201 :
case V_188 :
V_109 -> V_135 |= V_202 ;
default:
V_109 -> V_195 = V_203 ;
return 0 ;
}
}
static T_5
V_203 ( struct V_108 * V_109 )
{
struct V_110 * V_157 = V_109 -> V_204 ;
T_1 V_158 = V_109 -> V_205 ;
enum V_159 V_160 = V_109 -> V_160 ;
struct V_1 * V_63 = F_1 ( V_109 -> V_113 ) ;
struct V_115 * V_116 ;
struct V_206 * V_207 ;
struct V_154 * V_161 ;
T_5 V_31 ;
V_116 = F_4 ( sizeof( * V_116 ) + F_65 ( V_109 -> V_191 ) , V_9 ) ;
if ( ! V_116 ) {
return V_181 ;
}
V_109 -> V_117 = V_116 ;
memcpy ( V_116 -> V_118 , V_109 -> V_191 ,
F_65 ( V_109 -> V_191 ) ) ;
if ( ! V_157 ) {
V_207 = F_66 ( V_63 -> V_66 -> V_64 ,
( V_160 == V_173 ) ,
V_9 ) ;
if ( ! V_207 || F_12 ( V_207 ) ) {
F_5 ( L_77 ,
V_207 ? F_12 ( V_207 ) : - V_10 ) ;
V_31 = V_181 ;
goto V_176;
}
} else {
F_67 ( ! V_109 -> V_121 ) ;
V_31 = F_57 ( V_109 , V_157 , V_158 , V_160 , & V_161 ) ;
if ( V_31 )
goto V_176;
V_207 = F_68 ( V_63 -> V_66 -> V_64 , V_161 ,
V_9 ) ;
if ( F_12 ( V_207 ) ) {
F_5 ( L_78 ) ;
V_31 = V_181 ;
goto V_208;
}
}
V_207 -> V_209 = V_210 ;
V_207 -> V_211 = V_212 ;
V_207 -> V_213 = V_109 ;
V_207 -> V_214 = F_65 ( V_116 -> V_118 ) ;
V_207 -> V_109 = & V_116 -> V_118 [ 0 ] ;
V_207 -> V_215 = & V_116 -> V_133 [ 0 ] ;
V_207 -> V_216 = 0 ;
if ( V_63 -> V_66 -> type == V_106 )
V_207 -> V_217 = V_218 ;
else
V_207 -> V_217 = V_219 ;
V_207 -> V_220 = V_221 ;
F_69 ( V_63 -> V_66 -> V_64 , NULL , V_207 ,
( V_109 -> V_222 == V_223 ) ,
V_212 ) ;
return 0 ;
V_208:
while ( V_161 ) {
struct V_154 * V_154 = V_161 ;
V_161 = V_161 -> V_179 ;
V_154 -> V_179 = NULL ;
F_62 ( V_154 , 0 ) ;
}
V_31 = V_181 ;
V_176:
F_9 ( V_116 ) ;
return V_31 ;
}
static T_1 F_70 ( struct V_2 * V_3 )
{
struct V_1 * V_63 = F_1 ( V_3 ) ;
struct V_26 * V_62 = V_63 -> V_66 ;
return V_62 -> type ;
}
static T_6 F_71 ( struct V_2 * V_3 )
{
struct V_1 * V_63 = F_1 ( V_3 ) ;
if ( V_63 -> V_88 && V_63 -> V_88 -> V_224 )
return V_63 -> V_88 -> V_224 -> V_225 ;
F_72 () ;
return 0 ;
}
static void V_212 ( struct V_206 * V_207 , int V_226 )
{
struct V_108 * V_109 = V_207 -> V_213 ;
struct V_115 * V_116 = V_109 -> V_117 ;
V_116 -> V_119 = V_207 -> V_227 ;
V_116 -> V_228 = V_207 -> V_229 ;
V_109 -> V_230 = F_43 ( V_116 -> V_119 ) << 1 ;
if ( V_109 -> V_230 ) {
F_6 ( L_79
L_80 , V_109 , V_116 -> V_118 [ 0 ] ,
V_116 -> V_119 ) ;
}
switch ( F_73 ( V_116 -> V_119 ) ) {
case V_231 :
F_74 ( V_109 , V_109 -> V_230 ) ;
break;
default:
F_6 ( L_81
L_80 , V_109 , V_116 -> V_118 [ 0 ] ,
V_116 -> V_119 ) ;
F_74 ( V_109 , V_232 ) ;
break;
}
F_75 ( V_207 -> V_65 , V_207 ) ;
F_9 ( V_116 ) ;
}
static int T_7 F_76 ( void )
{
return F_77 ( & V_233 ) ;
}
static void F_78 ( void )
{
F_79 ( & V_233 ) ;
}
