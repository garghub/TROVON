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
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_11 ;
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
struct V_4 * V_5 = (struct V_4 * ) V_64 -> V_86 -> V_11 ;
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
struct V_4 * V_5 = (struct V_4 * ) V_64 -> V_86 -> V_11 ;
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
struct V_4 * V_5 = (struct V_4 * ) V_64 -> V_86 -> V_11 ;
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
struct V_63 * V_64 = (struct V_63 * ) V_96 ;
struct V_23 * V_24 ;
struct V_25 * V_65 ;
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_11 ;
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
return (struct V_23 * ) V_21 ;
}
}
} else {
if ( V_5 -> V_9 == V_10 ) {
F_3 ( L_39
L_40 ) ;
return F_39 ( - V_105 ) ;
}
}
F_43 ( V_21 -> V_87 ) ;
F_44 (sd, &sh->__devices, siblings) {
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
static void F_45 ( void * V_96 )
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
static inline struct V_114 * F_46 ( struct V_115 * V_116 )
{
return F_47 ( V_116 , struct V_114 , V_117 ) ;
}
static int F_48 ( struct V_115 * V_116 )
{
struct V_63 * V_64 = V_116 -> V_62 -> V_118 ;
struct V_25 * V_65 = V_64 -> V_83 ;
int V_119 ;
struct V_114 * V_120 = F_46 ( V_116 ) ;
unsigned char * V_27 = & V_120 -> V_121 [ 0 ] ;
V_119 = V_120 -> V_122 ;
if ( ( ( V_27 [ 0 ] == V_31 ) || ( V_27 [ 0 ] == V_123 ) ) &&
( F_49 ( V_119 ) << 1 ) == V_124 ) {
if ( ! V_116 -> V_125 -> V_126 )
goto V_127;
if ( V_116 -> V_125 -> V_126 -> V_128 &
V_129 ) {
unsigned char * V_29 = F_50 ( V_116 -> V_125 ) ;
if ( V_27 [ 0 ] == V_123 ) {
if ( ! ( V_29 [ 3 ] & 0x80 ) )
V_29 [ 3 ] |= 0x80 ;
} else {
if ( ! ( V_29 [ 2 ] & 0x80 ) )
V_29 [ 2 ] |= 0x80 ;
}
F_51 ( V_116 -> V_125 ) ;
}
}
V_127:
if ( V_65 -> type != V_85 )
goto V_130;
if ( ( ( V_27 [ 0 ] == V_131 ) || ( V_27 [ 0 ] == V_132 ) ) &&
( F_49 ( V_119 ) << 1 ) == V_124 ) {
unsigned char * V_29 ;
struct V_133 * V_134 = V_116 -> V_135 ;
T_2 V_136 ;
T_1 V_137 ;
V_29 = F_52 ( & V_134 [ 0 ] ) ;
if ( ! V_29 ) {
F_3 ( L_42 ) ;
goto V_130;
}
if ( V_27 [ 0 ] == V_131 )
V_136 = ( V_29 [ 3 ] ) ;
else
V_136 = ( V_29 [ 6 ] << 8 ) | ( V_29 [ 7 ] ) ;
if ( ! V_136 )
goto V_130;
if ( V_27 [ 0 ] == V_131 )
V_137 = ( V_29 [ 9 ] << 16 ) | ( V_29 [ 10 ] << 8 ) |
( V_29 [ 11 ] ) ;
else
V_137 = ( V_29 [ 13 ] << 16 ) | ( V_29 [ 14 ] << 8 ) |
( V_29 [ 15 ] ) ;
V_65 -> V_35 = V_137 ;
}
V_130:
if ( F_49 ( V_119 ) & V_138 )
return 1 ;
return 0 ;
}
static struct V_115 *
F_53 ( unsigned char * V_27 )
{
struct V_114 * V_120 ;
V_120 = F_2 ( sizeof( * V_120 ) + F_54 ( V_27 ) , V_6 ) ;
if ( ! V_120 ) {
F_3 ( L_43 ) ;
return NULL ;
}
return & V_120 -> V_117 ;
}
static inline void F_55 (
struct V_115 * V_116 ,
struct V_114 * V_120 ,
struct V_139 * V_140 ,
int V_141 )
{
V_140 -> V_142 = V_143 ;
if ( V_141 )
return;
V_140 -> V_144 = V_145 ;
V_140 -> V_146 = V_116 ;
V_140 -> V_147 = F_54 ( V_120 -> V_121 ) ;
V_140 -> V_148 = & V_120 -> V_121 [ 0 ] ;
V_140 -> V_149 = & V_120 -> V_150 [ 0 ] ;
V_140 -> V_151 = 0 ;
}
static int F_56 ( struct V_115 * V_116 )
{
struct V_114 * V_120 = F_46 ( V_116 ) ;
struct V_63 * V_64 = V_116 -> V_62 -> V_118 ;
V_120 -> V_152 = F_57 ( V_64 -> V_83 -> V_69 ,
( V_116 -> V_153 == V_154 ) ,
V_6 ) ;
if ( ! V_120 -> V_152 || F_10 ( V_120 -> V_152 ) ) {
F_3 ( L_44 ,
F_10 ( V_120 -> V_152 ) ) ;
return V_155 ;
}
F_55 ( V_116 , V_120 , V_120 -> V_152 , 0 ) ;
return 0 ;
}
static int F_58 ( struct V_115 * V_116 )
{
struct V_114 * V_120 = F_46 ( V_116 ) ;
struct V_63 * V_64 = V_116 -> V_62 -> V_118 ;
if ( V_64 -> V_83 -> type == V_112 )
V_120 -> V_152 -> V_156 = V_157 ;
else
V_120 -> V_152 -> V_156 = V_158 ;
V_120 -> V_152 -> V_159 = V_160 ;
F_59 ( V_64 -> V_83 -> V_69 , NULL , V_120 -> V_152 ,
( V_116 -> V_125 -> V_161 == V_162 ) ,
V_145 ) ;
return V_163 ;
}
static void F_60 ( struct V_115 * V_116 )
{
struct V_114 * V_120 = F_46 ( V_116 ) ;
F_7 ( V_120 ) ;
}
static T_3 F_61 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
const char * V_164 ,
T_3 V_165 )
{
struct V_63 * V_64 = V_62 -> V_166 ;
struct V_4 * V_5 = V_2 -> V_11 ;
char * V_167 , * V_168 , * V_169 ;
T_4 args [ V_170 ] ;
int V_30 = 0 , V_171 , V_172 ;
V_169 = F_62 ( V_164 , V_6 ) ;
if ( ! V_169 )
return - V_7 ;
V_167 = V_169 ;
while ( ( V_168 = F_63 ( & V_169 , L_45 ) ) != NULL ) {
if ( ! * V_168 )
continue;
V_172 = F_64 ( V_168 , V_173 , args ) ;
switch ( V_172 ) {
case V_174 :
if ( V_5 -> V_9 == V_22 ) {
F_3 ( L_46
L_47
L_48 ,
V_5 -> V_8 ) ;
V_30 = - V_98 ;
goto V_58;
}
F_65 ( args , & V_171 ) ;
V_64 -> V_108 = V_171 ;
F_4 ( L_49
L_50 , V_5 -> V_8 , V_64 -> V_108 ) ;
V_64 -> V_101 |= V_102 ;
break;
case V_175 :
F_65 ( args , & V_171 ) ;
V_64 -> V_109 = V_171 ;
F_4 ( L_51
L_52 , V_5 -> V_8 ,
V_64 -> V_109 ) ;
V_64 -> V_101 |= V_176 ;
break;
case V_177 :
F_65 ( args , & V_171 ) ;
V_64 -> V_110 = V_171 ;
F_4 ( L_53
L_52 , V_5 -> V_8 ,
V_64 -> V_110 ) ;
V_64 -> V_101 |= V_178 ;
break;
case V_179 :
F_65 ( args , & V_171 ) ;
V_64 -> V_111 = V_171 ;
F_4 ( L_54
L_50 , V_5 -> V_8 , V_64 -> V_111 ) ;
V_64 -> V_101 |= V_180 ;
break;
default:
break;
}
}
V_58:
F_7 ( V_167 ) ;
return ( ! V_30 ) ? V_165 : V_30 ;
}
static T_3 F_66 (
struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_63 * V_64 = V_62 -> V_166 ;
if ( ! ( V_64 -> V_101 & V_176 ) ||
! ( V_64 -> V_101 & V_178 ) ||
! ( V_64 -> V_101 & V_180 ) ) {
F_3 ( L_55
L_56 ) ;
return - V_98 ;
}
return 0 ;
}
static T_3 F_67 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
char * V_181 )
{
struct V_4 * V_5 = V_2 -> V_11 ;
struct V_63 * V_64 = V_62 -> V_166 ;
struct V_25 * V_65 = V_64 -> V_83 ;
unsigned char V_3 [ 16 ] ;
T_3 V_182 ;
int V_183 ;
if ( V_5 -> V_9 == V_10 )
snprintf ( V_3 , 16 , L_57 , V_64 -> V_108 ) ;
else
snprintf ( V_3 , 16 , L_58 ) ;
V_182 = sprintf ( V_181 , L_59
L_60 ,
V_64 -> V_109 , V_64 -> V_110 , V_64 -> V_111 ,
V_3 ) ;
if ( V_65 ) {
V_182 += sprintf ( V_181 + V_182 , L_61 ) ;
V_182 += sprintf ( V_181 + V_182 , L_62 ) ;
for ( V_183 = 0 ; V_183 < 8 ; V_183 ++ ) {
if ( ISPRINT ( V_65 -> V_41 [ V_183 ] ) )
V_182 += sprintf ( V_181 + V_182 , L_63 , V_65 -> V_41 [ V_183 ] ) ;
else
V_182 += sprintf ( V_181 + V_182 , L_64 ) ;
}
V_182 += sprintf ( V_181 + V_182 , L_65 ) ;
for ( V_183 = 0 ; V_183 < 16 ; V_183 ++ ) {
if ( ISPRINT ( V_65 -> V_42 [ V_183 ] ) )
V_182 += sprintf ( V_181 + V_182 , L_63 , V_65 -> V_42 [ V_183 ] ) ;
else
V_182 += sprintf ( V_181 + V_182 , L_64 ) ;
}
V_182 += sprintf ( V_181 + V_182 , L_66 ) ;
for ( V_183 = 0 ; V_183 < 4 ; V_183 ++ ) {
if ( ISPRINT ( V_65 -> V_184 [ V_183 ] ) )
V_182 += sprintf ( V_181 + V_182 , L_63 , V_65 -> V_184 [ V_183 ] ) ;
else
V_182 += sprintf ( V_181 + V_182 , L_64 ) ;
}
V_182 += sprintf ( V_181 + V_182 , L_67 ) ;
}
return V_182 ;
}
static void F_68 ( struct V_185 * V_185 , int error )
{
F_69 ( V_185 ) ;
}
static inline struct V_185 * F_70 ( int V_186 )
{
struct V_185 * V_185 ;
V_185 = F_71 ( V_6 , V_186 ) ;
if ( ! V_185 ) {
F_3 ( L_68 ) ;
return NULL ;
}
V_185 -> V_187 = F_68 ;
return V_185 ;
}
static int F_72 (
struct V_115 * V_116 ,
struct V_133 * V_135 ,
T_1 V_188 ,
int V_141 )
{
struct V_114 * V_120 = F_46 ( V_116 ) ;
struct V_63 * V_64 = V_116 -> V_62 -> V_118 ;
struct V_185 * V_185 = NULL , * V_189 = NULL , * V_190 = NULL ;
struct V_164 * V_164 ;
struct V_133 * V_134 ;
T_1 V_191 = V_116 -> V_192 , V_183 , V_193 , V_194 , V_54 ;
int V_195 = ( V_116 -> V_192 + V_135 [ 0 ] . V_196 +
V_197 - 1 ) >> V_198 ;
int V_199 = 0 , V_200 , V_30 = V_201 ;
int V_202 = ( V_116 -> V_153 == V_154 ) ;
if ( ! V_116 -> V_192 )
return 0 ;
F_4 ( L_69 , V_195 ) ;
F_73 (task_sg, sg, task_sg_num, i) {
V_164 = F_74 ( V_134 ) ;
V_54 = V_134 -> V_196 ;
V_193 = V_134 -> V_203 ;
F_4 ( L_70 , V_183 ,
V_164 , V_193 , V_54 ) ;
while ( V_193 > 0 && V_191 > 0 ) {
V_194 = F_24 (unsigned int, len, PAGE_SIZE - off) ;
V_194 = F_75 ( V_194 , V_191 ) ;
if ( ! V_185 ) {
V_199 = F_24 ( int , V_204 , V_195 ) ;
V_195 -= V_199 ;
V_185 = F_70 ( V_199 ) ;
if ( ! V_185 )
goto V_205;
if ( V_202 )
V_185 -> V_206 |= V_207 ;
F_4 ( L_71
L_72 , V_185 ,
( V_202 ) ? L_73 : L_74 , V_199 ) ;
if ( ! V_189 )
V_189 = V_190 = V_185 ;
else
V_190 = V_190 -> V_208 = V_185 ;
}
F_4 ( L_75
L_76 , V_183 , V_185 ,
V_164 , V_193 , V_54 ) ;
V_200 = F_76 ( V_64 -> V_83 -> V_69 ,
V_185 , V_164 , V_194 , V_54 ) ;
if ( V_200 != V_194 )
goto V_205;
F_4 ( L_77 ,
V_185 -> V_209 , V_199 ) ;
if ( V_185 -> V_209 > V_199 ) {
F_4 ( L_78
L_79
L_80 , V_185 -> V_209 , V_183 , V_185 ) ;
V_185 = NULL ;
}
V_164 ++ ;
V_193 -= V_194 ;
V_191 -= V_194 ;
V_54 = 0 ;
}
}
if ( ! V_141 ) {
V_120 -> V_152 = F_77 ( V_64 -> V_83 -> V_69 ,
V_189 , V_6 ) ;
if ( ! V_120 -> V_152 ) {
F_3 ( L_81 ) ;
goto V_205;
}
F_55 ( V_116 , V_120 , V_120 -> V_152 , 0 ) ;
return V_116 -> V_210 ;
}
V_120 -> V_152 -> V_211 = F_77 ( V_64 -> V_83 -> V_69 ,
V_189 , V_6 ) ;
if ( ! V_120 -> V_152 -> V_211 ) {
F_3 ( L_82 ) ;
goto V_205;
}
F_55 ( V_116 , V_120 , V_120 -> V_152 -> V_211 , 1 ) ;
return V_116 -> V_210 ;
V_205:
while ( V_189 ) {
V_185 = V_189 ;
V_189 = V_189 -> V_208 ;
V_185 -> V_208 = NULL ;
F_78 ( V_185 , 0 ) ;
}
return V_30 ;
}
static int F_79 ( struct V_115 * V_116 )
{
int V_30 ;
V_30 = F_72 ( V_116 , V_116 -> V_135 , V_116 -> V_210 , 0 ) ;
if ( V_30 >= 0 && V_116 -> V_212 ) {
V_30 = F_72 ( V_116 , V_116 -> V_212 ,
V_116 -> V_210 , 1 ) ;
}
if ( V_30 < 0 )
return V_155 ;
return 0 ;
}
static int F_80 ( struct V_115 * V_116 )
{
return F_56 ( V_116 ) ;
}
static unsigned char * F_81 ( struct V_115 * V_116 )
{
struct V_114 * V_120 = F_46 ( V_116 ) ;
return V_120 -> V_121 ;
}
static unsigned char * F_82 ( struct V_115 * V_116 )
{
struct V_114 * V_120 = F_46 ( V_116 ) ;
return ( unsigned char * ) & V_120 -> V_150 [ 0 ] ;
}
static T_1 F_83 ( struct V_23 * V_24 )
{
struct V_63 * V_64 = V_24 -> V_118 ;
struct V_25 * V_65 = V_64 -> V_83 ;
return ( V_65 -> V_213 - 1 ) ? V_65 -> V_213 - 1 : 1 ;
}
static T_1 F_84 ( struct V_23 * V_24 )
{
struct V_63 * V_64 = V_24 -> V_118 ;
struct V_25 * V_65 = V_64 -> V_83 ;
return V_65 -> type ;
}
static T_5 F_85 ( struct V_23 * V_24 )
{
struct V_63 * V_64 = V_24 -> V_118 ;
if ( V_64 -> V_95 && V_64 -> V_95 -> V_214 )
return V_64 -> V_95 -> V_214 -> V_215 ;
F_86 () ;
return 0 ;
}
static inline void F_87 (
struct V_115 * V_116 ,
struct V_114 * V_120 )
{
V_116 -> V_216 = F_49 ( V_120 -> V_122 ) ;
if ( V_116 -> V_216 ) {
V_116 -> V_216 <<= 1 ;
F_4 ( L_83
L_84 , V_116 , V_120 -> V_121 [ 0 ] ,
V_120 -> V_122 ) ;
}
switch ( F_88 ( V_120 -> V_122 ) ) {
case V_217 :
F_89 ( V_116 , ( ! V_116 -> V_216 ) ) ;
break;
default:
F_4 ( L_85
L_84 , V_116 , V_120 -> V_121 [ 0 ] ,
V_120 -> V_122 ) ;
V_116 -> V_216 = V_218 ;
V_116 -> V_219 = V_220 ;
V_116 -> V_125 -> V_221 =
V_220 ;
F_89 ( V_116 , 0 ) ;
break;
}
}
static void V_145 ( struct V_139 * V_140 , int V_222 )
{
struct V_115 * V_116 = V_140 -> V_146 ;
struct V_114 * V_120 = F_46 ( V_116 ) ;
V_120 -> V_122 = V_140 -> V_223 ;
V_120 -> V_224 = V_140 -> V_225 ;
F_87 ( V_116 , V_120 ) ;
if ( V_140 -> V_211 != NULL )
F_90 ( V_140 -> V_70 , V_140 -> V_211 ) ;
F_90 ( V_140 -> V_70 , V_140 ) ;
V_120 -> V_152 = NULL ;
}
static int T_6 F_91 ( void )
{
return F_92 ( & V_84 ) ;
}
static void F_93 ( void )
{
F_94 ( & V_84 ) ;
}
