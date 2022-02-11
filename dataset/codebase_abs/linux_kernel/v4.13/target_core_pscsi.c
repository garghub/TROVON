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
goto V_33;
memset ( V_29 , 0 , V_30 ) ;
V_29 [ 0 ] = V_34 ;
V_29 [ 4 ] = 0x0c ;
V_32 = F_13 ( V_28 , V_29 , V_35 , V_31 , 12 , NULL ,
V_36 , 1 , NULL ) ;
if ( V_32 )
goto V_33;
V_28 -> V_37 = F_14 ( & V_31 [ 9 ] ) ;
V_33:
if ( ! V_28 -> V_37 )
V_28 -> V_37 = 1024 ;
F_9 ( V_31 ) ;
}
static void
F_15 ( struct V_27 * V_28 , struct V_38 * V_39 )
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
F_16 ( struct V_27 * V_28 , struct V_38 * V_39 )
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
F_17 ( V_46 , & V_29 [ 3 ] ) ;
V_32 = F_13 ( V_28 , V_29 , V_35 , V_31 ,
V_46 , NULL , V_36 , 1 , NULL ) ;
if ( V_32 )
goto V_33;
snprintf ( & V_39 -> V_48 [ 0 ] , V_46 , L_15 , & V_31 [ 4 ] ) ;
V_39 -> V_49 -> V_50 |= V_51 ;
F_9 ( V_31 ) ;
return 0 ;
V_33:
F_9 ( V_31 ) ;
return - V_52 ;
}
static void
F_18 ( struct V_27 * V_28 ,
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
F_17 ( V_59 , & V_29 [ 3 ] ) ;
V_32 = F_13 ( V_28 , V_29 , V_35 , V_31 ,
V_59 ,
NULL , V_36 , 1 , NULL ) ;
if ( V_32 )
goto V_60;
V_55 = F_19 ( & V_31 [ 2 ] ) ;
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
F_20 ( & V_58 -> V_61 ) ;
F_21 ( V_58 , V_53 ) ;
F_22 ( V_58 , V_53 ) ;
if ( F_23 ( V_58 , V_53 ) < 0 ) {
V_56 += ( V_54 + 4 ) ;
V_55 -= ( V_54 + 4 ) ;
F_9 ( V_58 ) ;
continue;
}
if ( F_24 ( V_58 , V_53 ) < 0 ) {
V_56 += ( V_54 + 4 ) ;
V_55 -= ( V_54 + 4 ) ;
F_9 ( V_58 ) ;
continue;
}
F_25 ( & V_58 -> V_61 , & V_39 -> V_62 ) ;
V_56 += ( V_54 + 4 ) ;
V_55 -= ( V_54 + 4 ) ;
}
V_60:
F_9 ( V_31 ) ;
}
static int F_26 ( struct V_2 * V_3 ,
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
V_3 -> V_73 . V_74 =
F_27 ( ( int ) V_63 -> V_37 , 512 ) ;
V_3 -> V_73 . V_75 =
F_27 ( V_63 -> V_76 -> V_77 , F_28 ( V_66 ) ) ;
V_3 -> V_73 . V_78 = V_63 -> V_68 ;
F_15 ( V_63 , & V_3 -> V_38 ) ;
if ( ! F_16 ( V_63 , & V_3 -> V_38 ) ) {
F_18 ( V_63 , & V_3 -> V_38 ) ;
}
if ( V_63 -> type == V_79 ) {
F_12 ( V_3 , V_63 ) ;
V_3 -> V_73 . V_74 = V_63 -> V_37 ;
}
return 0 ;
}
static struct V_2 * F_29 ( struct V_4 * V_5 ,
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
static int F_30 ( struct V_2 * V_3 , struct V_27 * V_63 )
__releases( V_24 -> V_80 )
{
struct V_7 * V_8 = V_3 -> V_4 -> V_14 ;
struct V_1 * V_64 = F_1 ( V_3 ) ;
struct V_18 * V_24 = V_63 -> V_76 ;
struct V_81 * V_82 ;
int V_32 ;
if ( F_31 ( V_63 ) ) {
F_5 ( L_25 ,
V_24 -> V_83 , V_63 -> V_70 , V_63 -> V_71 , V_63 -> V_72 ) ;
F_32 ( V_24 -> V_80 ) ;
return - V_84 ;
}
F_32 ( V_24 -> V_80 ) ;
V_82 = F_33 ( V_3 -> V_85 ,
V_86 | V_87 | V_88 , V_64 ) ;
if ( F_34 ( V_82 ) ) {
F_5 ( L_26 ) ;
F_35 ( V_63 ) ;
return F_36 ( V_82 ) ;
}
V_64 -> V_89 = V_82 ;
V_32 = F_26 ( V_3 , V_63 ) ;
if ( V_32 ) {
F_37 ( V_64 -> V_89 , V_86 | V_87 | V_88 ) ;
F_35 ( V_63 ) ;
return V_32 ;
}
F_6 ( L_27 ,
V_8 -> V_11 , V_63 -> type == V_90 ? L_28 : L_29 ,
V_24 -> V_83 , V_63 -> V_70 , V_63 -> V_71 , V_63 -> V_72 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 , struct V_27 * V_63 )
__releases( V_24 -> V_80 )
{
struct V_7 * V_8 = V_3 -> V_4 -> V_14 ;
struct V_18 * V_24 = V_63 -> V_76 ;
int V_32 ;
if ( F_31 ( V_63 ) ) {
F_5 ( L_25 ,
V_24 -> V_83 , V_63 -> V_70 , V_63 -> V_71 , V_63 -> V_72 ) ;
F_32 ( V_24 -> V_80 ) ;
return - V_84 ;
}
F_32 ( V_24 -> V_80 ) ;
V_32 = F_26 ( V_3 , V_63 ) ;
if ( V_32 ) {
F_35 ( V_63 ) ;
return V_32 ;
}
F_6 ( L_30 ,
V_8 -> V_11 , F_39 ( V_63 -> type ) , V_24 -> V_83 ,
V_63 -> V_70 , V_63 -> V_71 , V_63 -> V_72 ) ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_4 ;
struct V_1 * V_64 = F_1 ( V_3 ) ;
struct V_27 * V_63 ;
struct V_7 * V_8 = V_3 -> V_4 -> V_14 ;
struct V_18 * V_24 = V_8 -> V_20 ;
int V_91 = 0 ;
int V_32 ;
if ( ! ( V_64 -> V_92 & V_93 ) ||
! ( V_64 -> V_92 & V_94 ) ||
! ( V_64 -> V_92 & V_95 ) ) {
F_5 ( L_31
L_32 ) ;
return - V_25 ;
}
if ( ! V_24 ) {
if ( V_8 -> V_12 == V_26 ) {
F_5 ( L_33
L_34 ) ;
return - V_96 ;
}
if ( ! ( V_3 -> V_50 & V_97 ) ) {
F_5 ( L_35
L_36 ) ;
return - V_25 ;
}
if ( ! ( V_64 -> V_92 & V_98 ) ) {
if ( V_5 -> V_99 ) {
F_5 ( L_37
L_38 ) ;
return - V_100 ;
}
if ( F_10 ( V_5 , 1 ) != 1 )
return - V_96 ;
V_91 = 1 ;
V_5 -> V_101 |= V_102 ;
V_24 = V_8 -> V_20 ;
} else {
V_24 = F_11 ( V_64 -> V_103 ) ;
if ( ! V_24 ) {
F_5 ( L_39
L_40 , V_64 -> V_103 ) ;
return - V_25 ;
}
V_64 -> V_104 = V_24 ;
}
} else {
if ( V_8 -> V_12 == V_13 ) {
F_5 ( L_41
L_42 ) ;
return - V_100 ;
}
}
F_41 ( V_24 -> V_80 ) ;
F_42 (sd, &sh->__devices, siblings) {
if ( ( V_64 -> V_105 != V_63 -> V_70 ) ||
( V_64 -> V_106 != V_63 -> V_71 ) ||
( V_64 -> V_107 != V_63 -> V_72 ) )
continue;
switch ( V_63 -> type ) {
case V_90 :
case V_108 :
V_32 = F_30 ( V_3 , V_63 ) ;
break;
default:
V_32 = F_38 ( V_3 , V_63 ) ;
break;
}
if ( V_32 ) {
if ( V_8 -> V_12 == V_13 )
F_8 ( V_24 ) ;
else if ( V_91 ) {
F_10 ( V_5 , 0 ) ;
V_5 -> V_101 &= ~ V_102 ;
}
V_64 -> V_67 = NULL ;
return V_32 ;
}
return 0 ;
}
F_32 ( V_24 -> V_80 ) ;
F_5 ( L_43 , V_24 -> V_83 ,
V_64 -> V_105 , V_64 -> V_106 , V_64 -> V_107 ) ;
if ( V_8 -> V_12 == V_13 )
F_8 ( V_24 ) ;
else if ( V_91 ) {
F_10 ( V_5 , 0 ) ;
V_5 -> V_101 &= ~ V_102 ;
}
return - V_96 ;
}
static void F_43 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = F_2 ( V_110 , struct V_2 , V_109 ) ;
struct V_1 * V_64 = F_1 ( V_3 ) ;
F_9 ( V_64 ) ;
}
static void F_44 ( struct V_2 * V_3 )
{
F_45 ( & V_3 -> V_109 , F_43 ) ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_1 * V_64 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_4 -> V_14 ;
struct V_27 * V_63 = V_64 -> V_67 ;
if ( V_63 ) {
if ( ( V_63 -> type == V_90 || V_63 -> type == V_108 ) &&
V_64 -> V_89 ) {
F_37 ( V_64 -> V_89 ,
V_86 | V_87 | V_88 ) ;
V_64 -> V_89 = NULL ;
}
if ( ( V_8 -> V_12 == V_26 ) &&
( V_8 -> V_20 != NULL ) )
F_8 ( V_8 -> V_20 ) ;
else if ( V_64 -> V_104 )
F_8 ( V_64 -> V_104 ) ;
F_35 ( V_63 ) ;
V_64 -> V_67 = NULL ;
}
}
static void F_47 ( struct V_111 * V_112 , T_2 V_113 ,
unsigned char * V_114 )
{
struct V_1 * V_64 = F_1 ( V_112 -> V_115 ) ;
struct V_27 * V_63 = V_64 -> V_67 ;
struct V_116 * V_117 = V_112 -> V_118 ;
unsigned char * V_29 ;
if ( ! V_117 )
return;
V_29 = & V_117 -> V_119 [ 0 ] ;
if ( ! V_112 -> V_120 )
goto V_121;
if ( ( ( V_29 [ 0 ] == V_34 ) || ( V_29 [ 0 ] == V_122 ) ) &&
V_113 == V_123 ) {
bool V_124 = F_48 ( V_112 ) ;
if ( V_124 ) {
unsigned char * V_31 ;
V_31 = F_49 ( V_112 ) ;
if ( ! V_31 )
;
if ( V_29 [ 0 ] == V_122 ) {
if ( ! ( V_31 [ 3 ] & 0x80 ) )
V_31 [ 3 ] |= 0x80 ;
} else {
if ( ! ( V_31 [ 2 ] & 0x80 ) )
V_31 [ 2 ] |= 0x80 ;
}
F_50 ( V_112 ) ;
}
}
V_121:
if ( V_63 -> type != V_79 || ! V_112 -> V_120 )
goto V_125;
if ( ( ( V_29 [ 0 ] == V_126 ) || ( V_29 [ 0 ] == V_127 ) ) &&
V_113 == V_123 ) {
unsigned char * V_31 ;
T_3 V_128 ;
T_1 V_129 ;
V_31 = F_51 ( & V_112 -> V_130 [ 0 ] ) ;
if ( ! V_31 ) {
F_5 ( L_44 ) ;
goto V_125;
}
if ( V_29 [ 0 ] == V_126 )
V_128 = V_31 [ 3 ] ;
else
V_128 = F_19 ( & V_31 [ 6 ] ) ;
if ( ! V_128 )
goto V_125;
if ( V_29 [ 0 ] == V_126 )
V_129 = F_14 ( & V_31 [ 9 ] ) ;
else
V_129 = F_14 ( & V_31 [ 13 ] ) ;
V_63 -> V_37 = V_129 ;
}
V_125:
if ( V_113 == V_131 )
F_52 ( V_112 , V_114 ) ;
}
static T_4 F_53 ( struct V_2 * V_3 ,
const char * V_132 , T_4 V_133 )
{
struct V_1 * V_64 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_4 -> V_14 ;
char * V_134 , * V_135 , * V_136 ;
T_5 args [ V_137 ] ;
int V_32 = 0 , V_138 , V_139 ;
V_136 = F_54 ( V_132 , V_9 ) ;
if ( ! V_136 )
return - V_10 ;
V_134 = V_136 ;
while ( ( V_135 = F_55 ( & V_136 , L_45 ) ) != NULL ) {
if ( ! * V_135 )
continue;
V_139 = F_56 ( V_135 , V_140 , args ) ;
switch ( V_139 ) {
case V_141 :
if ( V_8 -> V_12 == V_26 ) {
F_5 ( L_46
L_47
L_48 ,
V_8 -> V_11 ) ;
V_32 = - V_25 ;
goto V_60;
}
V_32 = F_57 ( args , & V_138 ) ;
if ( V_32 )
goto V_60;
V_64 -> V_103 = V_138 ;
F_6 ( L_49
L_50 , V_8 -> V_11 , V_64 -> V_103 ) ;
V_64 -> V_92 |= V_98 ;
break;
case V_142 :
V_32 = F_57 ( args , & V_138 ) ;
if ( V_32 )
goto V_60;
V_64 -> V_105 = V_138 ;
F_6 ( L_51
L_52 , V_8 -> V_11 ,
V_64 -> V_105 ) ;
V_64 -> V_92 |= V_93 ;
break;
case V_143 :
V_32 = F_57 ( args , & V_138 ) ;
if ( V_32 )
goto V_60;
V_64 -> V_106 = V_138 ;
F_6 ( L_53
L_52 , V_8 -> V_11 ,
V_64 -> V_106 ) ;
V_64 -> V_92 |= V_94 ;
break;
case V_144 :
V_32 = F_57 ( args , & V_138 ) ;
if ( V_32 )
goto V_60;
V_64 -> V_107 = V_138 ;
F_6 ( L_54
L_50 , V_8 -> V_11 , V_64 -> V_107 ) ;
V_64 -> V_92 |= V_95 ;
break;
default:
break;
}
}
V_60:
F_9 ( V_134 ) ;
return ( ! V_32 ) ? V_133 : V_32 ;
}
static T_4 F_58 ( struct V_2 * V_3 , char * V_145 )
{
struct V_7 * V_8 = V_3 -> V_4 -> V_14 ;
struct V_1 * V_64 = F_1 ( V_3 ) ;
struct V_27 * V_63 = V_64 -> V_67 ;
unsigned char V_6 [ 16 ] ;
T_4 V_146 ;
int V_147 ;
if ( V_8 -> V_12 == V_13 )
snprintf ( V_6 , 16 , L_55 , V_64 -> V_103 ) ;
else
snprintf ( V_6 , 16 , L_56 ) ;
V_146 = sprintf ( V_145 , L_57
L_58 ,
V_64 -> V_105 , V_64 -> V_106 , V_64 -> V_107 ,
V_6 ) ;
if ( V_63 ) {
V_146 += sprintf ( V_145 + V_146 , L_59 ) ;
V_146 += sprintf ( V_145 + V_146 , L_60 ) ;
for ( V_147 = 0 ; V_147 < 8 ; V_147 ++ ) {
if ( ISPRINT ( V_63 -> V_43 [ V_147 ] ) )
V_146 += sprintf ( V_145 + V_146 , L_61 , V_63 -> V_43 [ V_147 ] ) ;
else
V_146 += sprintf ( V_145 + V_146 , L_62 ) ;
}
V_146 += sprintf ( V_145 + V_146 , L_63 ) ;
for ( V_147 = 0 ; V_147 < 16 ; V_147 ++ ) {
if ( ISPRINT ( V_63 -> V_44 [ V_147 ] ) )
V_146 += sprintf ( V_145 + V_146 , L_61 , V_63 -> V_44 [ V_147 ] ) ;
else
V_146 += sprintf ( V_145 + V_146 , L_62 ) ;
}
V_146 += sprintf ( V_145 + V_146 , L_64 ) ;
for ( V_147 = 0 ; V_147 < 4 ; V_147 ++ ) {
if ( ISPRINT ( V_63 -> V_148 [ V_147 ] ) )
V_146 += sprintf ( V_145 + V_146 , L_61 , V_63 -> V_148 [ V_147 ] ) ;
else
V_146 += sprintf ( V_145 + V_146 , L_62 ) ;
}
V_146 += sprintf ( V_145 + V_146 , L_65 ) ;
}
return V_146 ;
}
static void F_59 ( struct V_149 * V_149 )
{
F_60 ( V_149 ) ;
}
static inline struct V_149 * F_61 ( int V_150 )
{
struct V_149 * V_149 ;
V_149 = F_62 ( V_9 , V_150 ) ;
if ( ! V_149 ) {
F_5 ( L_66 ) ;
return NULL ;
}
V_149 -> V_151 = F_59 ;
return V_149 ;
}
static T_6
F_63 ( struct V_111 * V_112 , struct V_152 * V_153 , T_1 V_154 ,
struct V_155 * V_156 )
{
struct V_1 * V_64 = F_1 ( V_112 -> V_115 ) ;
struct V_149 * V_149 = NULL ;
struct V_132 * V_132 ;
struct V_152 * V_157 ;
T_1 V_158 = V_112 -> V_120 , V_147 , V_159 , V_160 , V_56 ;
int V_161 = ( V_112 -> V_120 + V_153 [ 0 ] . V_162 +
V_163 - 1 ) >> V_164 ;
int V_150 = 0 , V_165 ;
int V_166 = ( V_112 -> V_167 == V_168 ) ;
F_64 ( ! V_112 -> V_120 ) ;
F_6 ( L_67 , V_161 ) ;
F_65 (sgl, sg, sgl_nents, i) {
V_132 = F_66 ( V_157 ) ;
V_56 = V_157 -> V_162 ;
V_159 = V_157 -> V_169 ;
F_6 ( L_68 , V_147 ,
V_132 , V_159 , V_56 ) ;
if ( V_56 + V_159 > V_163 )
goto V_170;
if ( V_159 > 0 && V_158 > 0 ) {
V_160 = F_67 (unsigned int, len, PAGE_SIZE - off) ;
V_160 = F_68 ( V_160 , V_158 ) ;
if ( ! V_149 ) {
V_150 = F_67 ( int , V_171 , V_161 ) ;
V_161 -= V_150 ;
V_149 = F_61 ( V_150 ) ;
if ( ! V_149 )
goto V_170;
if ( V_166 )
F_69 ( V_149 , V_172 , 0 ) ;
F_6 ( L_69
L_70 , V_149 ,
( V_166 ) ? L_71 : L_72 , V_150 ) ;
}
F_6 ( L_73
L_74 , V_147 , V_149 ,
V_132 , V_159 , V_56 ) ;
V_165 = F_70 ( V_64 -> V_67 -> V_65 ,
V_149 , V_132 , V_160 , V_56 ) ;
F_6 ( L_75 ,
F_71 ( V_149 ) , V_150 ) ;
if ( V_165 != V_160 ) {
F_6 ( L_76
L_77
L_78 , V_149 -> V_173 , V_147 , V_149 ) ;
V_165 = F_72 ( V_156 , V_149 ) ;
if ( V_165 ) {
F_5 ( L_79 ) ;
goto V_170;
}
V_149 = NULL ;
}
V_158 -= V_160 ;
}
}
if ( V_149 ) {
V_165 = F_72 ( V_156 , V_149 ) ;
if ( V_165 ) {
F_5 ( L_79 ) ;
goto V_170;
}
}
return 0 ;
V_170:
return V_174 ;
}
static T_6
F_73 ( struct V_111 * V_112 )
{
if ( V_112 -> V_175 & V_176 )
return V_177 ;
return F_74 ( V_112 , V_178 ) ;
}
static T_6
V_178 ( struct V_111 * V_112 )
{
struct V_152 * V_153 = V_112 -> V_130 ;
T_1 V_154 = V_112 -> V_179 ;
struct V_1 * V_64 = F_1 ( V_112 -> V_115 ) ;
struct V_116 * V_117 ;
struct V_155 * V_156 ;
T_6 V_32 ;
V_117 = F_4 ( sizeof( * V_117 ) + F_75 ( V_112 -> V_180 ) , V_9 ) ;
if ( ! V_117 ) {
return V_174 ;
}
V_112 -> V_118 = V_117 ;
memcpy ( V_117 -> V_119 , V_112 -> V_180 ,
F_75 ( V_112 -> V_180 ) ) ;
V_156 = F_76 ( V_64 -> V_67 -> V_65 ,
V_112 -> V_167 == V_168 ?
V_181 : V_182 ,
V_9 ) ;
if ( F_34 ( V_156 ) ) {
F_5 ( L_80 ) ;
V_32 = V_174 ;
goto V_170;
}
if ( V_153 ) {
V_32 = F_63 ( V_112 , V_153 , V_154 , V_156 ) ;
if ( V_32 )
goto V_183;
}
V_156 -> V_184 = V_185 ;
V_156 -> V_186 = V_112 ;
F_77 ( V_156 ) -> V_187 = F_75 ( V_117 -> V_119 ) ;
F_77 ( V_156 ) -> V_112 = & V_117 -> V_119 [ 0 ] ;
if ( V_64 -> V_67 -> type == V_90 ||
V_64 -> V_67 -> type == V_108 )
V_156 -> V_188 = V_189 ;
else
V_156 -> V_188 = V_190 ;
F_77 ( V_156 ) -> V_191 = V_192 ;
F_78 ( V_64 -> V_67 -> V_65 , NULL , V_156 ,
( V_112 -> V_193 == V_194 ) ,
V_185 ) ;
return 0 ;
V_183:
F_79 ( V_156 ) ;
V_170:
F_9 ( V_117 ) ;
return V_32 ;
}
static T_1 F_80 ( struct V_2 * V_3 )
{
struct V_1 * V_64 = F_1 ( V_3 ) ;
struct V_27 * V_63 = V_64 -> V_67 ;
return ( V_63 ) ? V_63 -> type : V_195 ;
}
static T_7 F_81 ( struct V_2 * V_3 )
{
struct V_1 * V_64 = F_1 ( V_3 ) ;
if ( V_64 -> V_89 && V_64 -> V_89 -> V_196 )
return V_64 -> V_89 -> V_196 -> V_197 ;
return 0 ;
}
static void V_185 ( struct V_155 * V_156 , T_8 V_198 )
{
struct V_111 * V_112 = V_156 -> V_186 ;
struct V_116 * V_117 = V_112 -> V_118 ;
int V_199 = F_77 ( V_156 ) -> V_199 ;
T_2 V_113 = F_82 ( V_199 ) << 1 ;
if ( V_113 ) {
F_6 ( L_81
L_82 , V_112 , V_117 -> V_119 [ 0 ] ,
V_199 ) ;
}
F_47 ( V_112 , V_113 , F_77 ( V_156 ) -> V_200 ) ;
switch ( F_83 ( V_199 ) ) {
case V_201 :
F_84 ( V_112 , V_113 ) ;
break;
default:
F_6 ( L_83
L_82 , V_112 , V_117 -> V_119 [ 0 ] ,
V_199 ) ;
F_84 ( V_112 , V_131 ) ;
break;
}
F_85 ( V_156 -> V_66 , V_156 ) ;
F_9 ( V_117 ) ;
}
static int T_9 F_86 ( void )
{
return F_87 ( & V_202 ) ;
}
static void T_10 F_88 ( void )
{
F_89 ( & V_202 ) ;
}
