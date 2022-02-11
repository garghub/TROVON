static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( sizeof( struct V_4 ) , V_6 ) ;
if ( ! V_5 ) {
F_3 ( L_1 ) ;
return - V_7 ;
}
V_5 -> V_8 = V_3 ;
V_5 -> V_9 = V_10 ;
V_2 -> V_11 = V_5 ;
F_4 ( L_2
L_3 , V_2 -> V_12 ,
V_13 , V_14 ) ;
F_4 ( L_4 ,
V_2 -> V_12 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_11 ;
struct V_15 * V_16 = V_5 -> V_17 ;
if ( V_16 ) {
F_6 ( V_16 ) ;
F_4 ( L_5
L_6 , V_2 -> V_12 ,
( V_16 -> V_18 -> V_19 ) ? ( V_16 -> V_18 -> V_19 ) :
L_7 ) ;
} else
F_4 ( L_8
L_9 , V_2 -> V_12 ) ;
F_7 ( V_5 ) ;
V_2 -> V_11 = NULL ;
}
static int F_8 ( struct V_1 * V_2 , unsigned long V_20 )
{
struct V_4 * V_5 = V_2 -> V_11 ;
struct V_15 * V_21 = V_5 -> V_17 ;
if ( ! V_20 ) {
if ( ! V_21 )
return 0 ;
V_5 -> V_17 = NULL ;
V_5 -> V_9 = V_10 ;
F_4 ( L_10
L_11 , V_2 -> V_12 , ( V_21 -> V_18 -> V_19 ) ?
( V_21 -> V_18 -> V_19 ) : L_7 ) ;
F_6 ( V_21 ) ;
return 0 ;
}
V_21 = F_9 ( V_5 -> V_8 ) ;
if ( F_10 ( V_21 ) ) {
F_3 ( L_12
L_13 , V_5 -> V_8 ) ;
return F_11 ( V_21 ) ;
}
V_5 -> V_17 = V_21 ;
V_5 -> V_9 = V_22 ;
F_4 ( L_14 ,
V_2 -> V_12 , ( V_21 -> V_18 -> V_19 ) ? ( V_21 -> V_18 -> V_19 ) : L_7 ) ;
return 1 ;
}
static void F_12 ( struct V_23 * V_24 ,
struct V_25 * V_26 )
{
unsigned char V_27 [ V_28 ] , * V_29 ;
int V_30 ;
V_29 = F_2 ( 12 , V_6 ) ;
if ( ! V_29 )
return;
memset ( V_27 , 0 , V_28 ) ;
V_27 [ 0 ] = V_31 ;
V_27 [ 4 ] = 0x0c ;
V_30 = F_13 ( V_26 , V_27 , V_32 , V_29 , 12 , NULL ,
V_33 , 1 , NULL ) ;
if ( V_30 )
goto V_34;
V_26 -> V_35 = ( V_29 [ 9 ] << 16 ) | ( V_29 [ 10 ] << 8 ) | ( V_29 [ 11 ] ) ;
if ( ! V_26 -> V_35 )
V_26 -> V_35 = 1024 ;
V_34:
F_7 ( V_29 ) ;
}
static void
F_14 ( struct V_25 * V_26 , struct V_36 * V_37 )
{
unsigned char * V_29 ;
if ( V_26 -> V_38 < V_39 )
return;
V_29 = V_26 -> V_40 ;
if ( ! V_29 )
return;
memcpy ( & V_37 -> V_41 [ 0 ] , & V_29 [ 8 ] , sizeof( V_37 -> V_41 ) ) ;
memcpy ( & V_37 -> V_42 [ 0 ] , & V_29 [ 16 ] , sizeof( V_37 -> V_42 ) ) ;
memcpy ( & V_37 -> V_43 [ 0 ] , & V_29 [ 32 ] , sizeof( V_37 -> V_43 ) ) ;
}
static int
F_15 ( struct V_25 * V_26 , struct V_36 * V_37 )
{
unsigned char V_27 [ V_28 ] , * V_29 ;
int V_30 ;
V_29 = F_2 ( V_44 , V_6 ) ;
if ( ! V_29 )
return - V_7 ;
memset ( V_27 , 0 , V_28 ) ;
V_27 [ 0 ] = V_45 ;
V_27 [ 1 ] = 0x01 ;
V_27 [ 2 ] = 0x80 ;
V_27 [ 3 ] = ( V_44 >> 8 ) & 0xff ;
V_27 [ 4 ] = ( V_44 & 0xff ) ;
V_30 = F_13 ( V_26 , V_27 , V_32 , V_29 ,
V_44 , NULL , V_33 , 1 , NULL ) ;
if ( V_30 )
goto V_34;
snprintf ( & V_37 -> V_46 [ 0 ] , V_44 , L_15 , & V_29 [ 4 ] ) ;
V_37 -> V_47 -> V_48 |= V_49 ;
F_7 ( V_29 ) ;
return 0 ;
V_34:
F_7 ( V_29 ) ;
return - V_50 ;
}
static void
F_16 ( struct V_25 * V_26 ,
struct V_36 * V_37 )
{
unsigned char V_27 [ V_28 ] , * V_29 , * V_51 ;
int V_52 , V_53 , V_54 = 4 , V_30 ;
struct V_55 * V_56 ;
V_29 = F_2 ( V_44 , V_6 ) ;
if ( ! V_29 )
return;
memset ( V_27 , 0 , V_28 ) ;
V_27 [ 0 ] = V_45 ;
V_27 [ 1 ] = 0x01 ;
V_27 [ 2 ] = 0x83 ;
V_27 [ 3 ] = ( V_57 >> 8 ) & 0xff ;
V_27 [ 4 ] = ( V_57 & 0xff ) ;
V_30 = F_13 ( V_26 , V_27 , V_32 , V_29 ,
V_57 ,
NULL , V_33 , 1 , NULL ) ;
if ( V_30 )
goto V_58;
V_53 = ( V_29 [ 2 ] << 8 ) | V_29 [ 3 ] ;
while ( V_53 > 0 ) {
V_51 = & V_29 [ V_54 ] ;
V_52 = V_51 [ 3 ] ;
if ( ! V_52 ) {
F_3 ( L_16
L_17 ) ;
break;
}
F_4 ( L_18 , V_52 ) ;
V_56 = F_2 ( sizeof( struct V_55 ) , V_6 ) ;
if ( ! V_56 ) {
F_3 ( L_19
L_20 ) ;
goto V_58;
}
F_17 ( & V_56 -> V_59 ) ;
F_18 ( V_56 , V_51 ) ;
F_19 ( V_56 , V_51 ) ;
if ( F_20 ( V_56 , V_51 ) < 0 ) {
V_54 += ( V_52 + 4 ) ;
V_53 -= ( V_52 + 4 ) ;
F_7 ( V_56 ) ;
continue;
}
if ( F_21 ( V_56 , V_51 ) < 0 ) {
V_54 += ( V_52 + 4 ) ;
V_53 -= ( V_52 + 4 ) ;
F_7 ( V_56 ) ;
continue;
}
F_22 ( & V_56 -> V_59 , & V_37 -> V_60 ) ;
V_54 += ( V_52 + 4 ) ;
V_53 -= ( V_52 + 4 ) ;
}
V_58:
F_7 ( V_29 ) ;
}
static struct V_23 * F_23 (
struct V_1 * V_2 ,
struct V_61 * V_62 ,
struct V_63 * V_64 ,
struct V_25 * V_65 ,
int V_66 )
{
struct V_23 * V_24 ;
struct V_67 V_68 ;
struct V_69 * V_70 ;
struct V_71 * V_72 ;
memset ( & V_68 , 0 , sizeof( struct V_67 ) ) ;
if ( ! V_65 -> V_73 ) {
V_65 -> V_73 = V_74 ;
F_3 ( L_21
L_22 , V_65 -> V_75 , V_65 -> V_76 ,
V_65 -> V_77 , V_65 -> V_73 ) ;
}
V_70 = V_65 -> V_69 ;
V_72 = & V_68 . V_72 ;
V_72 -> V_78 = V_65 -> V_35 ;
V_72 -> V_79 = F_24 ( int , V_65 -> V_80 -> V_81 , F_25 ( V_70 ) ) ;
V_72 -> V_81 = F_24 ( int , V_65 -> V_80 -> V_81 , F_26 ( V_70 ) ) ;
V_68 . V_82 = V_65 -> V_73 ;
V_68 . V_73 = V_65 -> V_73 ;
F_14 ( V_65 , & V_62 -> V_36 ) ;
V_64 -> V_83 = V_65 ;
V_24 = F_27 ( V_2 , & V_84 ,
V_62 , V_66 , V_64 ,
& V_68 , NULL , NULL ) ;
if ( ! V_24 ) {
V_64 -> V_83 = NULL ;
return NULL ;
}
if ( ! F_15 ( V_65 , & V_62 -> V_36 ) ) {
F_16 ( V_65 , & V_62 -> V_36 ) ;
}
if ( V_65 -> type == V_85 )
F_12 ( V_24 , V_65 ) ;
return V_24 ;
}
static void * F_28 ( struct V_1 * V_2 , const char * V_19 )
{
struct V_63 * V_64 ;
V_64 = F_2 ( sizeof( struct V_63 ) , V_6 ) ;
if ( ! V_64 ) {
F_3 ( L_23 ) ;
return NULL ;
}
V_64 -> V_86 = V_2 ;
F_4 ( L_24 , V_64 , V_19 ) ;
return V_64 ;
}
static struct V_23 * F_29 (
struct V_25 * V_65 ,
struct V_63 * V_64 ,
struct V_61 * V_62 ,
struct V_1 * V_2 )
__releases( V_21 -> V_87 )
{
struct V_23 * V_24 ;
struct V_4 * V_5 = V_64 -> V_86 -> V_11 ;
struct V_15 * V_21 = V_65 -> V_80 ;
struct V_88 * V_89 ;
T_1 V_66 = 0 ;
if ( F_30 ( V_65 ) ) {
F_3 ( L_25 ,
V_21 -> V_90 , V_65 -> V_75 , V_65 -> V_76 , V_65 -> V_77 ) ;
F_31 ( V_21 -> V_87 ) ;
return NULL ;
}
F_31 ( V_21 -> V_87 ) ;
V_89 = F_32 ( V_62 -> V_91 ,
V_92 | V_93 | V_94 , V_64 ) ;
if ( F_10 ( V_89 ) ) {
F_3 ( L_26 ) ;
F_33 ( V_65 ) ;
return NULL ;
}
V_64 -> V_95 = V_89 ;
V_24 = F_23 ( V_2 , V_62 , V_64 , V_65 , V_66 ) ;
if ( ! V_24 ) {
F_34 ( V_64 -> V_95 , V_92 | V_93 | V_94 ) ;
F_33 ( V_65 ) ;
return NULL ;
}
F_4 ( L_27 ,
V_5 -> V_8 , V_21 -> V_90 , V_65 -> V_75 , V_65 -> V_76 , V_65 -> V_77 ) ;
return V_24 ;
}
static struct V_23 * F_35 (
struct V_25 * V_65 ,
struct V_63 * V_64 ,
struct V_61 * V_62 ,
struct V_1 * V_2 )
__releases( V_21 -> V_87 )
{
struct V_23 * V_24 ;
struct V_4 * V_5 = V_64 -> V_86 -> V_11 ;
struct V_15 * V_21 = V_65 -> V_80 ;
T_1 V_66 = 0 ;
if ( F_30 ( V_65 ) ) {
F_3 ( L_25 ,
V_21 -> V_90 , V_65 -> V_75 , V_65 -> V_76 , V_65 -> V_77 ) ;
F_31 ( V_21 -> V_87 ) ;
return NULL ;
}
F_31 ( V_21 -> V_87 ) ;
V_24 = F_23 ( V_2 , V_62 , V_64 , V_65 , V_66 ) ;
if ( ! V_24 ) {
F_33 ( V_65 ) ;
return NULL ;
}
F_4 ( L_28 ,
V_5 -> V_8 , F_36 ( V_65 -> type ) , V_21 -> V_90 ,
V_65 -> V_75 , V_65 -> V_76 , V_65 -> V_77 ) ;
return V_24 ;
}
static struct V_23 * F_37 (
struct V_25 * V_65 ,
struct V_63 * V_64 ,
struct V_61 * V_62 ,
struct V_1 * V_2 )
__releases( V_21 -> V_87 )
{
struct V_23 * V_24 ;
struct V_4 * V_5 = V_64 -> V_86 -> V_11 ;
struct V_15 * V_21 = V_65 -> V_80 ;
T_1 V_66 = 0 ;
F_31 ( V_21 -> V_87 ) ;
V_24 = F_23 ( V_2 , V_62 , V_64 , V_65 , V_66 ) ;
if ( ! V_24 )
return NULL ;
F_4 ( L_28 ,
V_5 -> V_8 , F_36 ( V_65 -> type ) , V_21 -> V_90 ,
V_65 -> V_75 , V_65 -> V_76 , V_65 -> V_77 ) ;
return V_24 ;
}
static struct V_23 * F_38 (
struct V_1 * V_2 ,
struct V_61 * V_62 ,
void * V_96 )
{
struct V_63 * V_64 = V_96 ;
struct V_23 * V_24 ;
struct V_25 * V_65 ;
struct V_4 * V_5 = V_2 -> V_11 ;
struct V_15 * V_21 = V_5 -> V_17 ;
int V_97 = 0 ;
if ( ! V_64 ) {
F_3 ( L_29
L_30 ) ;
return F_39 ( - V_98 ) ;
}
if ( ! V_21 ) {
if ( V_5 -> V_9 == V_22 ) {
F_3 ( L_31
L_32 ) ;
return F_39 ( - V_99 ) ;
}
if ( ! ( V_62 -> V_48 & V_100 ) ) {
F_3 ( L_33
L_34 ) ;
return F_39 ( - V_98 ) ;
}
if ( ! ( V_64 -> V_101 & V_102 ) ) {
F_40 ( & V_2 -> V_103 ) ;
if ( ! F_41 ( & V_2 -> V_104 ) ) {
F_3 ( L_35
L_36 ) ;
F_42 ( & V_2 -> V_103 ) ;
return F_39 ( - V_105 ) ;
}
F_42 ( & V_2 -> V_103 ) ;
if ( F_8 ( V_2 , 1 ) != 1 )
return F_39 ( - V_99 ) ;
V_97 = 1 ;
V_2 -> V_106 |= V_107 ;
V_21 = V_5 -> V_17 ;
} else {
V_21 = F_9 ( V_64 -> V_108 ) ;
if ( F_10 ( V_21 ) ) {
F_3 ( L_37
L_38 , V_64 -> V_108 ) ;
return F_43 ( V_21 ) ;
}
}
} else {
if ( V_5 -> V_9 == V_10 ) {
F_3 ( L_39
L_40 ) ;
return F_39 ( - V_105 ) ;
}
}
F_44 ( V_21 -> V_87 ) ;
F_45 (sd, &sh->__devices, siblings) {
if ( ( V_64 -> V_109 != V_65 -> V_75 ) ||
( V_64 -> V_110 != V_65 -> V_76 ) ||
( V_64 -> V_111 != V_65 -> V_77 ) )
continue;
switch ( V_65 -> type ) {
case V_112 :
V_24 = F_29 ( V_65 , V_64 , V_62 , V_2 ) ;
break;
case V_113 :
V_24 = F_35 ( V_65 , V_64 , V_62 , V_2 ) ;
break;
default:
V_24 = F_37 ( V_65 , V_64 , V_62 , V_2 ) ;
break;
}
if ( ! V_24 ) {
if ( V_5 -> V_9 == V_10 )
F_6 ( V_21 ) ;
else if ( V_97 ) {
F_8 ( V_2 , 0 ) ;
V_2 -> V_106 &= ~ V_107 ;
}
V_64 -> V_83 = NULL ;
return F_39 ( - V_99 ) ;
}
return V_24 ;
}
F_31 ( V_21 -> V_87 ) ;
F_3 ( L_41 , V_21 -> V_90 ,
V_64 -> V_109 , V_64 -> V_110 , V_64 -> V_111 ) ;
if ( V_5 -> V_9 == V_10 )
F_6 ( V_21 ) ;
else if ( V_97 ) {
F_8 ( V_2 , 0 ) ;
V_2 -> V_106 &= ~ V_107 ;
}
return F_39 ( - V_99 ) ;
}
static void F_46 ( void * V_96 )
{
struct V_63 * V_64 = V_96 ;
struct V_4 * V_5 = V_64 -> V_86 -> V_11 ;
struct V_25 * V_65 = V_64 -> V_83 ;
if ( V_65 ) {
if ( ( V_65 -> type == V_112 ) && V_64 -> V_95 ) {
F_34 ( V_64 -> V_95 ,
V_92 | V_93 | V_94 ) ;
V_64 -> V_95 = NULL ;
}
if ( ( V_5 -> V_9 == V_22 ) &&
( V_5 -> V_17 != NULL ) )
F_6 ( V_5 -> V_17 ) ;
if ( ( V_65 -> type == V_112 ) || ( V_65 -> type == V_113 ) )
F_33 ( V_65 ) ;
V_64 -> V_83 = NULL ;
}
F_7 ( V_64 ) ;
}
static void F_47 ( struct V_114 * V_115 , struct V_116 * V_117 ,
unsigned char * V_118 )
{
struct V_63 * V_64 = V_115 -> V_62 -> V_119 ;
struct V_25 * V_65 = V_64 -> V_83 ;
int V_120 ;
struct V_121 * V_122 = V_115 -> V_123 ;
unsigned char * V_27 ;
if ( ! V_122 )
return;
V_27 = & V_122 -> V_124 [ 0 ] ;
V_120 = V_122 -> V_125 ;
if ( ! V_115 -> V_126 || ! V_115 -> V_127 )
goto V_128;
if ( ( ( V_27 [ 0 ] == V_31 ) || ( V_27 [ 0 ] == V_129 ) ) &&
( F_48 ( V_120 ) << 1 ) == V_130 ) {
if ( V_115 -> V_126 -> V_131 & V_132 ) {
unsigned char * V_29 = F_49 ( V_115 ) ;
if ( V_27 [ 0 ] == V_129 ) {
if ( ! ( V_29 [ 3 ] & 0x80 ) )
V_29 [ 3 ] |= 0x80 ;
} else {
if ( ! ( V_29 [ 2 ] & 0x80 ) )
V_29 [ 2 ] |= 0x80 ;
}
F_50 ( V_115 ) ;
}
}
V_128:
if ( V_65 -> type != V_85 || ! V_115 -> V_127 )
goto V_133;
if ( ( ( V_27 [ 0 ] == V_134 ) || ( V_27 [ 0 ] == V_135 ) ) &&
( F_48 ( V_120 ) << 1 ) == V_130 ) {
unsigned char * V_29 ;
T_2 V_136 ;
T_1 V_137 ;
V_29 = F_51 ( & V_117 [ 0 ] ) ;
if ( ! V_29 ) {
F_3 ( L_42 ) ;
goto V_133;
}
if ( V_27 [ 0 ] == V_134 )
V_136 = ( V_29 [ 3 ] ) ;
else
V_136 = ( V_29 [ 6 ] << 8 ) | ( V_29 [ 7 ] ) ;
if ( ! V_136 )
goto V_133;
if ( V_27 [ 0 ] == V_134 )
V_137 = ( V_29 [ 9 ] << 16 ) | ( V_29 [ 10 ] << 8 ) |
( V_29 [ 11 ] ) ;
else
V_137 = ( V_29 [ 13 ] << 16 ) | ( V_29 [ 14 ] << 8 ) |
( V_29 [ 15 ] ) ;
V_65 -> V_35 = V_137 ;
}
V_133:
if ( V_118 && ( F_48 ( V_120 ) & V_138 ) ) {
memcpy ( V_118 , V_122 -> V_139 , V_140 ) ;
V_115 -> V_141 |= V_142 ;
}
}
static T_3 F_52 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
const char * V_143 ,
T_3 V_144 )
{
struct V_63 * V_64 = V_62 -> V_145 ;
struct V_4 * V_5 = V_2 -> V_11 ;
char * V_146 , * V_147 , * V_148 ;
T_4 args [ V_149 ] ;
int V_30 = 0 , V_150 , V_151 ;
V_148 = F_53 ( V_143 , V_6 ) ;
if ( ! V_148 )
return - V_7 ;
V_146 = V_148 ;
while ( ( V_147 = F_54 ( & V_148 , L_43 ) ) != NULL ) {
if ( ! * V_147 )
continue;
V_151 = F_55 ( V_147 , V_152 , args ) ;
switch ( V_151 ) {
case V_153 :
if ( V_5 -> V_9 == V_22 ) {
F_3 ( L_44
L_45
L_46 ,
V_5 -> V_8 ) ;
V_30 = - V_98 ;
goto V_58;
}
F_56 ( args , & V_150 ) ;
V_64 -> V_108 = V_150 ;
F_4 ( L_47
L_48 , V_5 -> V_8 , V_64 -> V_108 ) ;
V_64 -> V_101 |= V_102 ;
break;
case V_154 :
F_56 ( args , & V_150 ) ;
V_64 -> V_109 = V_150 ;
F_4 ( L_49
L_50 , V_5 -> V_8 ,
V_64 -> V_109 ) ;
V_64 -> V_101 |= V_155 ;
break;
case V_156 :
F_56 ( args , & V_150 ) ;
V_64 -> V_110 = V_150 ;
F_4 ( L_51
L_50 , V_5 -> V_8 ,
V_64 -> V_110 ) ;
V_64 -> V_101 |= V_157 ;
break;
case V_158 :
F_56 ( args , & V_150 ) ;
V_64 -> V_111 = V_150 ;
F_4 ( L_52
L_48 , V_5 -> V_8 , V_64 -> V_111 ) ;
V_64 -> V_101 |= V_159 ;
break;
default:
break;
}
}
V_58:
F_7 ( V_146 ) ;
return ( ! V_30 ) ? V_144 : V_30 ;
}
static T_3 F_57 (
struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_63 * V_64 = V_62 -> V_145 ;
if ( ! ( V_64 -> V_101 & V_155 ) ||
! ( V_64 -> V_101 & V_157 ) ||
! ( V_64 -> V_101 & V_159 ) ) {
F_3 ( L_53
L_54 ) ;
return - V_98 ;
}
return 0 ;
}
static T_3 F_58 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
char * V_160 )
{
struct V_4 * V_5 = V_2 -> V_11 ;
struct V_63 * V_64 = V_62 -> V_145 ;
struct V_25 * V_65 = V_64 -> V_83 ;
unsigned char V_3 [ 16 ] ;
T_3 V_161 ;
int V_162 ;
if ( V_5 -> V_9 == V_10 )
snprintf ( V_3 , 16 , L_55 , V_64 -> V_108 ) ;
else
snprintf ( V_3 , 16 , L_56 ) ;
V_161 = sprintf ( V_160 , L_57
L_58 ,
V_64 -> V_109 , V_64 -> V_110 , V_64 -> V_111 ,
V_3 ) ;
if ( V_65 ) {
V_161 += sprintf ( V_160 + V_161 , L_59 ) ;
V_161 += sprintf ( V_160 + V_161 , L_60 ) ;
for ( V_162 = 0 ; V_162 < 8 ; V_162 ++ ) {
if ( ISPRINT ( V_65 -> V_41 [ V_162 ] ) )
V_161 += sprintf ( V_160 + V_161 , L_61 , V_65 -> V_41 [ V_162 ] ) ;
else
V_161 += sprintf ( V_160 + V_161 , L_62 ) ;
}
V_161 += sprintf ( V_160 + V_161 , L_63 ) ;
for ( V_162 = 0 ; V_162 < 16 ; V_162 ++ ) {
if ( ISPRINT ( V_65 -> V_42 [ V_162 ] ) )
V_161 += sprintf ( V_160 + V_161 , L_61 , V_65 -> V_42 [ V_162 ] ) ;
else
V_161 += sprintf ( V_160 + V_161 , L_62 ) ;
}
V_161 += sprintf ( V_160 + V_161 , L_64 ) ;
for ( V_162 = 0 ; V_162 < 4 ; V_162 ++ ) {
if ( ISPRINT ( V_65 -> V_163 [ V_162 ] ) )
V_161 += sprintf ( V_160 + V_161 , L_61 , V_65 -> V_163 [ V_162 ] ) ;
else
V_161 += sprintf ( V_160 + V_161 , L_62 ) ;
}
V_161 += sprintf ( V_160 + V_161 , L_65 ) ;
}
return V_161 ;
}
static void F_59 ( struct V_164 * V_164 , int error )
{
F_60 ( V_164 ) ;
}
static inline struct V_164 * F_61 ( int V_165 )
{
struct V_164 * V_164 ;
V_164 = F_62 ( V_6 , V_165 ) ;
if ( ! V_164 ) {
F_3 ( L_66 ) ;
return NULL ;
}
V_164 -> V_166 = F_59 ;
return V_164 ;
}
static int F_63 ( struct V_114 * V_115 , struct V_116 * V_167 ,
T_1 V_168 , enum V_169 V_170 ,
struct V_164 * * V_171 )
{
struct V_63 * V_64 = V_115 -> V_62 -> V_119 ;
struct V_164 * V_164 = NULL , * V_172 = NULL ;
struct V_143 * V_143 ;
struct V_116 * V_117 ;
T_1 V_173 = V_115 -> V_127 , V_162 , V_174 , V_175 , V_54 ;
int V_176 = ( V_115 -> V_127 + V_167 [ 0 ] . V_177 +
V_178 - 1 ) >> V_179 ;
int V_180 = 0 , V_181 ;
int V_182 = ( V_170 == V_183 ) ;
* V_171 = NULL ;
F_4 ( L_67 , V_176 ) ;
F_64 (sgl, sg, sgl_nents, i) {
V_143 = F_65 ( V_117 ) ;
V_54 = V_117 -> V_177 ;
V_174 = V_117 -> V_184 ;
F_4 ( L_68 , V_162 ,
V_143 , V_174 , V_54 ) ;
while ( V_174 > 0 && V_173 > 0 ) {
V_175 = F_24 (unsigned int, len, PAGE_SIZE - off) ;
V_175 = F_66 ( V_175 , V_173 ) ;
if ( ! V_164 ) {
V_180 = F_24 ( int , V_185 , V_176 ) ;
V_176 -= V_180 ;
V_164 = F_61 ( V_180 ) ;
if ( ! V_164 )
goto V_186;
if ( V_182 )
V_164 -> V_187 |= V_188 ;
F_4 ( L_69
L_70 , V_164 ,
( V_182 ) ? L_71 : L_72 , V_180 ) ;
if ( ! * V_171 )
* V_171 = V_172 = V_164 ;
else
V_172 = V_172 -> V_189 = V_164 ;
}
F_4 ( L_73
L_74 , V_162 , V_164 ,
V_143 , V_174 , V_54 ) ;
V_181 = F_67 ( V_64 -> V_83 -> V_69 ,
V_164 , V_143 , V_175 , V_54 ) ;
if ( V_181 != V_175 )
goto V_186;
F_4 ( L_75 ,
V_164 -> V_190 , V_180 ) ;
if ( V_164 -> V_190 > V_180 ) {
F_4 ( L_76
L_77
L_78 , V_164 -> V_190 , V_162 , V_164 ) ;
V_164 = NULL ;
}
V_143 ++ ;
V_174 -= V_175 ;
V_173 -= V_175 ;
V_54 = 0 ;
}
}
return V_168 ;
V_186:
while ( * V_171 ) {
V_164 = * V_171 ;
* V_171 = ( * V_171 ) -> V_189 ;
V_164 -> V_189 = NULL ;
F_68 ( V_164 , 0 ) ;
}
V_115 -> V_191 = V_192 ;
return - V_7 ;
}
static inline void F_69 ( unsigned char * V_27 )
{
switch ( V_27 [ 0 ] ) {
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_201 :
break;
default:
V_27 [ 1 ] &= 0x1f ;
break;
}
}
static int F_70 ( struct V_114 * V_115 )
{
unsigned char * V_27 = V_115 -> V_202 ;
unsigned int V_203 ;
int V_30 ;
if ( V_115 -> V_141 & V_204 ) {
V_115 -> V_141 |= V_205 ;
V_115 -> V_191 = V_206 ;
return - V_98 ;
}
F_69 ( V_27 ) ;
switch ( V_27 [ 0 ] ) {
case V_207 :
V_30 = F_71 ( V_115 , & V_203 ) ;
if ( V_30 )
return V_30 ;
break;
case V_208 :
case V_193 :
case V_194 :
case V_195 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_199 :
V_115 -> V_141 |= V_213 ;
default:
V_115 -> V_214 = V_215 ;
break;
}
return 0 ;
}
static int V_215 ( struct V_114 * V_115 )
{
struct V_116 * V_167 = V_115 -> V_216 ;
T_1 V_168 = V_115 -> V_217 ;
enum V_169 V_170 = V_115 -> V_170 ;
struct V_63 * V_64 = V_115 -> V_62 -> V_119 ;
struct V_121 * V_122 ;
struct V_218 * V_219 ;
struct V_164 * V_171 ;
int V_30 ;
V_122 = F_2 ( sizeof( * V_122 ) + F_72 ( V_115 -> V_202 ) , V_6 ) ;
if ( ! V_122 ) {
V_115 -> V_191 = V_192 ;
return - V_7 ;
}
V_115 -> V_123 = V_122 ;
memcpy ( V_122 -> V_124 , V_115 -> V_202 ,
F_72 ( V_115 -> V_202 ) ) ;
if ( ! V_167 ) {
V_219 = F_73 ( V_64 -> V_83 -> V_69 ,
( V_170 == V_183 ) ,
V_6 ) ;
if ( ! V_219 || F_10 ( V_219 ) ) {
F_3 ( L_79 ,
V_219 ? F_10 ( V_219 ) : - V_7 ) ;
V_115 -> V_191 =
V_192 ;
goto V_186;
}
} else {
F_74 ( ! V_115 -> V_127 ) ;
V_30 = F_63 ( V_115 , V_167 , V_168 , V_170 , & V_171 ) ;
if ( V_30 < 0 ) {
V_115 -> V_191 =
V_192 ;
goto V_186;
}
V_219 = F_75 ( V_64 -> V_83 -> V_69 , V_171 ,
V_6 ) ;
if ( F_10 ( V_219 ) ) {
F_3 ( L_80 ) ;
goto V_220;
}
}
V_219 -> V_221 = V_222 ;
V_219 -> V_223 = V_224 ;
V_219 -> V_225 = V_115 ;
V_219 -> V_226 = F_72 ( V_122 -> V_124 ) ;
V_219 -> V_115 = & V_122 -> V_124 [ 0 ] ;
V_219 -> V_227 = & V_122 -> V_139 [ 0 ] ;
V_219 -> V_228 = 0 ;
if ( V_64 -> V_83 -> type == V_112 )
V_219 -> V_229 = V_230 ;
else
V_219 -> V_229 = V_231 ;
V_219 -> V_232 = V_233 ;
F_76 ( V_64 -> V_83 -> V_69 , NULL , V_219 ,
( V_115 -> V_234 == V_235 ) ,
V_224 ) ;
return 0 ;
V_220:
while ( V_171 ) {
struct V_164 * V_164 = V_171 ;
V_171 = V_171 -> V_189 ;
V_164 -> V_189 = NULL ;
F_68 ( V_164 , 0 ) ;
}
V_115 -> V_191 = V_192 ;
V_186:
F_7 ( V_122 ) ;
return - V_7 ;
}
static T_1 F_77 ( struct V_23 * V_24 )
{
struct V_63 * V_64 = V_24 -> V_119 ;
struct V_25 * V_65 = V_64 -> V_83 ;
return ( V_65 -> V_236 - 1 ) ? V_65 -> V_236 - 1 : 1 ;
}
static T_1 F_78 ( struct V_23 * V_24 )
{
struct V_63 * V_64 = V_24 -> V_119 ;
struct V_25 * V_65 = V_64 -> V_83 ;
return V_65 -> type ;
}
static T_5 F_79 ( struct V_23 * V_24 )
{
struct V_63 * V_64 = V_24 -> V_119 ;
if ( V_64 -> V_95 && V_64 -> V_95 -> V_237 )
return V_64 -> V_95 -> V_237 -> V_238 ;
F_80 () ;
return 0 ;
}
static void V_224 ( struct V_218 * V_219 , int V_239 )
{
struct V_114 * V_115 = V_219 -> V_225 ;
struct V_121 * V_122 = V_115 -> V_123 ;
V_122 -> V_125 = V_219 -> V_240 ;
V_122 -> V_241 = V_219 -> V_242 ;
V_115 -> V_243 = F_48 ( V_122 -> V_125 ) << 1 ;
if ( V_115 -> V_243 ) {
F_4 ( L_81
L_82 , V_115 , V_122 -> V_124 [ 0 ] ,
V_122 -> V_125 ) ;
}
switch ( F_81 ( V_122 -> V_125 ) ) {
case V_244 :
F_82 ( V_115 , V_115 -> V_243 ) ;
break;
default:
F_4 ( L_83
L_82 , V_115 , V_122 -> V_124 [ 0 ] ,
V_122 -> V_125 ) ;
V_115 -> V_191 = V_206 ;
F_82 ( V_115 , V_245 ) ;
break;
}
F_83 ( V_219 -> V_70 , V_219 ) ;
F_7 ( V_122 ) ;
}
static int T_6 F_84 ( void )
{
return F_85 ( & V_84 ) ;
}
static void F_86 ( void )
{
F_87 ( & V_84 ) ;
}
