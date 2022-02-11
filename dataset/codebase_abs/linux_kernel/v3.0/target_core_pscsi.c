static struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 = NULL ;
V_3 = F_2 ( V_2 ) ;
if ( F_3 ( V_3 ) ) {
F_4 ( V_4 L_1
L_2 , V_2 ) ;
return NULL ;
}
return V_3 ;
}
static int F_5 ( struct V_5 * V_6 , T_1 V_7 )
{
int V_8 ;
struct V_9 * V_10 ;
V_10 = F_6 ( sizeof( struct V_9 ) , V_11 ) ;
if ( ! ( V_10 ) ) {
F_4 ( V_4 L_3 ) ;
return - 1 ;
}
V_10 -> V_12 = V_7 ;
V_10 -> V_13 = V_14 ;
V_8 = V_15 ;
F_7 ( & V_6 -> V_16 , V_8 ) ;
F_7 ( & V_6 -> V_17 , V_8 ) ;
V_6 -> V_18 = ( void * ) V_10 ;
F_4 ( V_19 L_4
L_5 , V_6 -> V_20 ,
V_21 , V_22 ) ;
F_4 ( V_19 L_6
L_7 , V_6 -> V_20 ,
F_8 ( & V_6 -> V_17 ) ) ;
return 0 ;
}
static void F_9 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_18 ;
struct V_1 * V_23 = V_10 -> V_24 ;
if ( V_23 ) {
F_10 ( V_23 ) ;
F_4 ( V_19 L_8
L_9 , V_6 -> V_20 ,
( V_23 -> V_25 -> V_26 ) ? ( V_23 -> V_25 -> V_26 ) :
L_10 ) ;
} else
F_4 ( V_19 L_11
L_12 , V_6 -> V_20 ) ;
F_11 ( V_10 ) ;
V_6 -> V_18 = NULL ;
}
static int F_12 ( struct V_5 * V_6 , unsigned long V_27 )
{
struct V_9 * V_10 = (struct V_9 * ) V_6 -> V_18 ;
struct V_1 * V_3 = V_10 -> V_24 ;
int V_8 = V_15 ;
if ( ! ( V_27 ) ) {
if ( ! ( V_3 ) )
return 0 ;
V_10 -> V_24 = NULL ;
V_10 -> V_13 = V_14 ;
F_7 ( & V_6 -> V_16 , V_8 ) ;
F_7 ( & V_6 -> V_17 , V_8 ) ;
F_4 ( V_19 L_13
L_14 , V_6 -> V_20 , ( V_3 -> V_25 -> V_26 ) ?
( V_3 -> V_25 -> V_26 ) : L_10 ) ;
F_10 ( V_3 ) ;
return 0 ;
}
V_3 = F_1 ( V_10 -> V_12 ) ;
if ( ! ( V_3 ) ) {
F_4 ( V_4 L_15
L_16 , V_10 -> V_12 ) ;
return - 1 ;
}
V_8 = ( V_3 -> V_25 -> V_28 > V_3 -> V_28 ) ?
V_3 -> V_25 -> V_28 : V_3 -> V_28 ;
F_7 ( & V_6 -> V_16 , V_8 ) ;
F_7 ( & V_6 -> V_17 , V_8 ) ;
V_10 -> V_24 = V_3 ;
V_10 -> V_13 = V_29 ;
F_4 ( V_19 L_17 ,
V_6 -> V_20 , ( V_3 -> V_25 -> V_26 ) ? ( V_3 -> V_25 -> V_26 ) : L_10 ) ;
return 1 ;
}
static void F_13 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
unsigned char V_34 [ V_35 ] , * V_36 ;
int V_37 ;
V_36 = F_6 ( 12 , V_11 ) ;
if ( ! V_36 )
return;
memset ( V_34 , 0 , V_35 ) ;
V_34 [ 0 ] = V_38 ;
V_34 [ 4 ] = 0x0c ;
V_37 = F_14 ( V_33 , V_34 , V_39 , V_36 , 12 , NULL ,
V_40 , 1 , NULL ) ;
if ( V_37 )
goto V_41;
V_33 -> V_42 = ( V_36 [ 9 ] << 16 ) | ( V_36 [ 10 ] << 8 ) | ( V_36 [ 11 ] ) ;
if ( ! V_33 -> V_42 )
V_33 -> V_42 = 1024 ;
V_41:
F_11 ( V_36 ) ;
}
static void
F_15 ( struct V_32 * V_33 , struct V_43 * V_44 )
{
unsigned char * V_36 ;
if ( V_33 -> V_45 < V_46 )
return;
V_36 = V_33 -> V_47 ;
if ( ! V_36 )
return;
memcpy ( & V_44 -> V_48 [ 0 ] , & V_36 [ 8 ] , sizeof( V_44 -> V_48 ) ) ;
memcpy ( & V_44 -> V_49 [ 0 ] , & V_36 [ 16 ] , sizeof( V_44 -> V_49 ) ) ;
memcpy ( & V_44 -> V_50 [ 0 ] , & V_36 [ 32 ] , sizeof( V_44 -> V_50 ) ) ;
}
static int
F_16 ( struct V_32 * V_33 , struct V_43 * V_44 )
{
unsigned char V_34 [ V_35 ] , * V_36 ;
int V_37 ;
V_36 = F_6 ( V_51 , V_11 ) ;
if ( ! V_36 )
return - 1 ;
memset ( V_34 , 0 , V_35 ) ;
V_34 [ 0 ] = V_52 ;
V_34 [ 1 ] = 0x01 ;
V_34 [ 2 ] = 0x80 ;
V_34 [ 3 ] = ( V_51 >> 8 ) & 0xff ;
V_34 [ 4 ] = ( V_51 & 0xff ) ;
V_37 = F_14 ( V_33 , V_34 , V_39 , V_36 ,
V_51 , NULL , V_40 , 1 , NULL ) ;
if ( V_37 )
goto V_41;
snprintf ( & V_44 -> V_53 [ 0 ] , V_51 , L_18 , & V_36 [ 4 ] ) ;
V_44 -> V_54 -> V_55 |= V_56 ;
F_11 ( V_36 ) ;
return 0 ;
V_41:
F_11 ( V_36 ) ;
return - 1 ;
}
static void
F_17 ( struct V_32 * V_33 ,
struct V_43 * V_44 )
{
unsigned char V_34 [ V_35 ] , * V_36 , * V_57 ;
int V_58 , V_59 , V_60 = 4 , V_37 ;
struct V_61 * V_62 ;
V_36 = F_6 ( V_51 , V_11 ) ;
if ( ! V_36 )
return;
memset ( V_34 , 0 , V_35 ) ;
V_34 [ 0 ] = V_52 ;
V_34 [ 1 ] = 0x01 ;
V_34 [ 2 ] = 0x83 ;
V_34 [ 3 ] = ( V_63 >> 8 ) & 0xff ;
V_34 [ 4 ] = ( V_63 & 0xff ) ;
V_37 = F_14 ( V_33 , V_34 , V_39 , V_36 ,
V_63 ,
NULL , V_40 , 1 , NULL ) ;
if ( V_37 )
goto V_64;
V_59 = ( V_36 [ 2 ] << 8 ) | V_36 [ 3 ] ;
while ( V_59 > 0 ) {
V_57 = & V_36 [ V_60 ] ;
V_58 = V_57 [ 3 ] ;
if ( ! V_58 ) {
F_4 ( V_4 L_19
L_20 ) ;
break;
}
F_4 ( V_19 L_21 , V_58 ) ;
V_62 = F_6 ( sizeof( struct V_61 ) , V_11 ) ;
if ( ! V_62 ) {
F_4 ( V_4 L_22
L_23 ) ;
goto V_64;
}
F_18 ( & V_62 -> V_65 ) ;
F_19 ( V_62 , V_57 ) ;
F_20 ( V_62 , V_57 ) ;
if ( F_21 ( V_62 , V_57 ) < 0 ) {
V_60 += ( V_58 + 4 ) ;
V_59 -= ( V_58 + 4 ) ;
F_11 ( V_62 ) ;
continue;
}
if ( F_22 ( V_62 , V_57 ) < 0 ) {
V_60 += ( V_58 + 4 ) ;
V_59 -= ( V_58 + 4 ) ;
F_11 ( V_62 ) ;
continue;
}
F_23 ( & V_62 -> V_65 , & V_44 -> V_66 ) ;
V_60 += ( V_58 + 4 ) ;
V_59 -= ( V_58 + 4 ) ;
}
V_64:
F_11 ( V_36 ) ;
}
static struct V_30 * F_24 (
struct V_5 * V_6 ,
struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_32 * V_71 ,
int V_72 )
{
struct V_30 * V_31 ;
struct V_73 V_74 ;
struct V_75 * V_76 ;
struct V_77 * V_78 ;
memset ( & V_74 , 0 , sizeof( struct V_73 ) ) ;
if ( ! V_71 -> V_79 ) {
V_71 -> V_79 = V_80 ;
F_4 ( V_4 L_24
L_25 , V_71 -> V_81 , V_71 -> V_82 ,
V_71 -> V_83 , V_71 -> V_79 ) ;
}
V_76 = V_71 -> V_75 ;
V_78 = & V_74 . V_78 ;
V_78 -> V_84 = V_71 -> V_42 ;
V_78 -> V_85 = ( V_71 -> V_86 -> V_87 > F_25 ( V_76 ) ) ?
F_25 ( V_76 ) : V_71 -> V_86 -> V_87 ;
V_78 -> V_87 = ( V_71 -> V_86 -> V_87 > F_26 ( V_76 ) ) ?
F_26 ( V_76 ) : V_71 -> V_86 -> V_87 ;
V_74 . V_88 = V_71 -> V_79 ;
V_74 . V_79 = V_71 -> V_79 ;
F_15 ( V_71 , & V_68 -> V_43 ) ;
V_70 -> V_89 = V_71 ;
V_31 = F_27 ( V_6 , & V_90 ,
V_68 , V_72 , ( void * ) V_70 ,
& V_74 , NULL , NULL ) ;
if ( ! ( V_31 ) ) {
V_70 -> V_89 = NULL ;
return NULL ;
}
if ( ! F_16 ( V_71 , & V_68 -> V_43 ) ) {
F_17 ( V_71 , & V_68 -> V_43 ) ;
}
if ( V_71 -> type == V_91 )
F_13 ( V_31 , V_71 ) ;
return V_31 ;
}
static void * F_28 ( struct V_5 * V_6 , const char * V_26 )
{
struct V_69 * V_70 ;
V_70 = F_6 ( sizeof( struct V_69 ) , V_11 ) ;
if ( ! ( V_70 ) ) {
F_4 ( V_4 L_26 ) ;
return NULL ;
}
V_70 -> V_92 = V_6 ;
F_4 ( V_19 L_27 , V_70 , V_26 ) ;
return ( void * ) V_70 ;
}
static struct V_30 * F_29 (
struct V_32 * V_71 ,
struct V_69 * V_70 ,
struct V_67 * V_68 ,
struct V_5 * V_6 )
__releases( V_3 -> V_93 )
{
struct V_30 * V_31 ;
struct V_9 * V_10 = (struct V_9 * ) V_70 -> V_92 -> V_18 ;
struct V_1 * V_3 = V_71 -> V_86 ;
struct V_94 * V_95 ;
T_1 V_72 = 0 ;
if ( F_30 ( V_71 ) ) {
F_4 ( V_4 L_28 ,
V_3 -> V_2 , V_71 -> V_81 , V_71 -> V_82 , V_71 -> V_83 ) ;
F_31 ( V_3 -> V_93 ) ;
return NULL ;
}
F_31 ( V_3 -> V_93 ) ;
V_95 = F_32 ( V_68 -> V_96 ,
V_97 | V_98 | V_99 , V_70 ) ;
if ( F_3 ( V_95 ) ) {
F_4 ( V_4 L_29 ) ;
F_33 ( V_71 ) ;
return NULL ;
}
V_70 -> V_100 = V_95 ;
V_31 = F_24 ( V_6 , V_68 , V_70 , V_71 , V_72 ) ;
if ( ! ( V_31 ) ) {
F_34 ( V_70 -> V_100 , V_97 | V_98 | V_99 ) ;
F_33 ( V_71 ) ;
return NULL ;
}
F_4 ( V_19 L_30 ,
V_10 -> V_12 , V_3 -> V_2 , V_71 -> V_81 , V_71 -> V_82 , V_71 -> V_83 ) ;
return V_31 ;
}
static struct V_30 * F_35 (
struct V_32 * V_71 ,
struct V_69 * V_70 ,
struct V_67 * V_68 ,
struct V_5 * V_6 )
__releases( V_3 -> V_93 )
{
struct V_30 * V_31 ;
struct V_9 * V_10 = (struct V_9 * ) V_70 -> V_92 -> V_18 ;
struct V_1 * V_3 = V_71 -> V_86 ;
T_1 V_72 = 0 ;
if ( F_30 ( V_71 ) ) {
F_4 ( V_4 L_28 ,
V_3 -> V_2 , V_71 -> V_81 , V_71 -> V_82 , V_71 -> V_83 ) ;
F_31 ( V_3 -> V_93 ) ;
return NULL ;
}
F_31 ( V_3 -> V_93 ) ;
V_31 = F_24 ( V_6 , V_68 , V_70 , V_71 , V_72 ) ;
if ( ! ( V_31 ) ) {
F_33 ( V_71 ) ;
return NULL ;
}
F_4 ( V_19 L_31 ,
V_10 -> V_12 , F_36 ( V_71 -> type ) , V_3 -> V_2 ,
V_71 -> V_81 , V_71 -> V_82 , V_71 -> V_83 ) ;
return V_31 ;
}
static struct V_30 * F_37 (
struct V_32 * V_71 ,
struct V_69 * V_70 ,
struct V_67 * V_68 ,
struct V_5 * V_6 )
__releases( V_3 -> V_93 )
{
struct V_30 * V_31 ;
struct V_9 * V_10 = (struct V_9 * ) V_70 -> V_92 -> V_18 ;
struct V_1 * V_3 = V_71 -> V_86 ;
T_1 V_72 = 0 ;
F_31 ( V_3 -> V_93 ) ;
V_31 = F_24 ( V_6 , V_68 , V_70 , V_71 , V_72 ) ;
if ( ! ( V_31 ) )
return NULL ;
F_4 ( V_19 L_31 ,
V_10 -> V_12 , F_36 ( V_71 -> type ) , V_3 -> V_2 ,
V_71 -> V_81 , V_71 -> V_82 , V_71 -> V_83 ) ;
return V_31 ;
}
static struct V_30 * F_38 (
struct V_5 * V_6 ,
struct V_67 * V_68 ,
void * V_101 )
{
struct V_69 * V_70 = (struct V_69 * ) V_101 ;
struct V_30 * V_31 ;
struct V_32 * V_71 ;
struct V_9 * V_10 = (struct V_9 * ) V_6 -> V_18 ;
struct V_1 * V_3 = V_10 -> V_24 ;
int V_102 = 0 ;
if ( ! ( V_70 ) ) {
F_4 ( V_4 L_32
L_33 ) ;
return F_39 ( - V_103 ) ;
}
if ( ! ( V_3 ) ) {
if ( V_10 -> V_13 == V_29 ) {
F_4 ( V_4 L_34
L_35 ) ;
return F_39 ( - V_104 ) ;
}
if ( ! ( V_68 -> V_55 & V_105 ) ) {
F_4 ( V_4 L_36
L_37 ) ;
return F_39 ( - V_103 ) ;
}
if ( ! ( V_70 -> V_106 & V_107 ) ) {
F_40 ( & V_6 -> V_108 ) ;
if ( ! ( F_41 ( & V_6 -> V_109 ) ) ) {
F_4 ( V_4 L_38
L_39 ) ;
F_42 ( & V_6 -> V_108 ) ;
return F_39 ( - V_110 ) ;
}
F_42 ( & V_6 -> V_108 ) ;
if ( F_12 ( V_6 , 1 ) != 1 )
return F_39 ( - V_104 ) ;
V_102 = 1 ;
V_6 -> V_111 |= V_112 ;
V_3 = V_10 -> V_24 ;
} else {
V_3 = F_1 ( V_70 -> V_113 ) ;
if ( ! ( V_3 ) ) {
F_4 ( V_4 L_40
L_41 , V_70 -> V_113 ) ;
return F_39 ( - V_104 ) ;
}
}
} else {
if ( V_10 -> V_13 == V_14 ) {
F_4 ( V_4 L_42
L_43 ) ;
return F_39 ( - V_110 ) ;
}
}
F_43 ( V_3 -> V_93 ) ;
F_44 (sd, &sh->__devices, siblings) {
if ( ( V_70 -> V_114 != V_71 -> V_81 ) ||
( V_70 -> V_115 != V_71 -> V_82 ) ||
( V_70 -> V_116 != V_71 -> V_83 ) )
continue;
switch ( V_71 -> type ) {
case V_117 :
V_31 = F_29 ( V_71 , V_70 , V_68 , V_6 ) ;
break;
case V_118 :
V_31 = F_35 ( V_71 , V_70 , V_68 , V_6 ) ;
break;
default:
V_31 = F_37 ( V_71 , V_70 , V_68 , V_6 ) ;
break;
}
if ( ! ( V_31 ) ) {
if ( V_10 -> V_13 == V_14 )
F_10 ( V_3 ) ;
else if ( V_102 ) {
F_12 ( V_6 , 0 ) ;
V_6 -> V_111 &= ~ V_112 ;
}
V_70 -> V_89 = NULL ;
return F_39 ( - V_104 ) ;
}
return V_31 ;
}
F_31 ( V_3 -> V_93 ) ;
F_4 ( V_4 L_44 , V_3 -> V_2 ,
V_70 -> V_114 , V_70 -> V_115 , V_70 -> V_116 ) ;
if ( V_10 -> V_13 == V_14 )
F_10 ( V_3 ) ;
else if ( V_102 ) {
F_12 ( V_6 , 0 ) ;
V_6 -> V_111 &= ~ V_112 ;
}
return F_39 ( - V_104 ) ;
}
static void F_45 ( void * V_101 )
{
struct V_69 * V_70 = V_101 ;
struct V_9 * V_10 = V_70 -> V_92 -> V_18 ;
struct V_32 * V_71 = V_70 -> V_89 ;
if ( V_71 ) {
if ( ( V_71 -> type == V_117 ) && V_70 -> V_100 ) {
F_34 ( V_70 -> V_100 ,
V_97 | V_98 | V_99 ) ;
V_70 -> V_100 = NULL ;
}
if ( ( V_10 -> V_13 == V_29 ) &&
( V_10 -> V_24 != NULL ) )
F_10 ( V_10 -> V_24 ) ;
if ( ( V_71 -> type == V_117 ) || ( V_71 -> type == V_118 ) )
F_33 ( V_71 ) ;
V_70 -> V_89 = NULL ;
}
F_11 ( V_70 ) ;
}
static inline struct V_119 * F_46 ( struct V_120 * V_121 )
{
return F_47 ( V_121 , struct V_119 , V_122 ) ;
}
static int F_48 ( struct V_120 * V_121 )
{
struct V_69 * V_70 = V_121 -> V_68 -> V_123 ;
struct V_32 * V_71 = V_70 -> V_89 ;
int V_124 ;
struct V_119 * V_125 = F_46 ( V_121 ) ;
unsigned char * V_34 = & V_125 -> V_126 [ 0 ] ;
V_124 = V_125 -> V_127 ;
if ( ( ( V_34 [ 0 ] == V_38 ) || ( V_34 [ 0 ] == V_128 ) ) &&
( F_49 ( V_124 ) << 1 ) == V_129 ) {
if ( ! F_50 ( V_121 ) -> V_130 )
goto V_131;
if ( F_50 ( V_121 ) -> V_130 -> V_132 &
V_133 ) {
unsigned char * V_36 = ( unsigned char * )
F_51 ( V_121 -> V_134 ) -> V_135 ;
if ( V_34 [ 0 ] == V_128 ) {
if ( ! ( V_36 [ 3 ] & 0x80 ) )
V_36 [ 3 ] |= 0x80 ;
} else {
if ( ! ( V_36 [ 2 ] & 0x80 ) )
V_36 [ 2 ] |= 0x80 ;
}
}
}
V_131:
if ( V_71 -> type != V_91 )
goto V_136;
if ( ( ( V_34 [ 0 ] == V_137 ) || ( V_34 [ 0 ] == V_138 ) ) &&
( F_49 ( V_124 ) << 1 ) == V_129 ) {
unsigned char * V_36 ;
struct V_139 * V_140 = V_121 -> V_141 ;
T_2 V_142 ;
T_1 V_143 ;
V_36 = F_52 ( & V_140 [ 0 ] ) ;
if ( ! ( V_36 ) ) {
F_4 ( V_4 L_45 ) ;
goto V_136;
}
if ( V_34 [ 0 ] == V_137 )
V_142 = ( V_36 [ 3 ] ) ;
else
V_142 = ( V_36 [ 6 ] << 8 ) | ( V_36 [ 7 ] ) ;
if ( ! V_142 )
goto V_136;
if ( V_34 [ 0 ] == V_137 )
V_143 = ( V_36 [ 9 ] << 16 ) | ( V_36 [ 10 ] << 8 ) |
( V_36 [ 11 ] ) ;
else
V_143 = ( V_36 [ 13 ] << 16 ) | ( V_36 [ 14 ] << 8 ) |
( V_36 [ 15 ] ) ;
V_71 -> V_42 = V_143 ;
}
V_136:
if ( F_49 ( V_124 ) & V_144 )
return 1 ;
return 0 ;
}
static struct V_120 *
F_53 ( struct V_145 * V_146 )
{
struct V_119 * V_125 ;
unsigned char * V_34 = F_51 ( V_146 ) -> V_147 ;
V_125 = F_6 ( sizeof( struct V_119 ) , V_11 ) ;
if ( ! V_125 ) {
F_4 ( V_4 L_46 ) ;
return NULL ;
}
if ( F_51 ( V_146 ) -> V_147 != F_51 ( V_146 ) -> V_148 ) {
V_125 -> V_126 = F_6 ( F_54 ( V_34 ) , V_11 ) ;
if ( ! ( V_125 -> V_126 ) ) {
F_4 ( V_4 L_47
L_48 ) ;
F_11 ( V_125 ) ;
return NULL ;
}
} else
V_125 -> V_126 = & V_125 -> V_149 [ 0 ] ;
return & V_125 -> V_122 ;
}
static inline void F_55 (
struct V_120 * V_121 ,
struct V_119 * V_125 ,
struct V_150 * V_151 ,
int V_152 )
{
V_151 -> V_153 = V_154 ;
if ( V_152 )
return;
V_151 -> V_155 = V_156 ;
V_151 -> V_157 = ( void * ) V_121 ;
V_151 -> V_158 = F_54 ( V_125 -> V_126 ) ;
V_151 -> V_146 = & V_125 -> V_126 [ 0 ] ;
V_151 -> V_159 = ( void * ) & V_125 -> V_160 [ 0 ] ;
V_151 -> V_161 = 0 ;
}
static int F_56 ( struct V_120 * V_121 )
{
struct V_119 * V_125 = F_46 ( V_121 ) ;
struct V_69 * V_70 = V_121 -> V_68 -> V_123 ;
V_125 -> V_162 = F_57 ( V_70 -> V_89 -> V_75 ,
( V_121 -> V_163 == V_164 ) ,
V_11 ) ;
if ( ! ( V_125 -> V_162 ) || F_3 ( V_125 -> V_162 ) ) {
F_4 ( V_4 L_49 ,
F_3 ( V_125 -> V_162 ) ) ;
return V_165 ;
}
F_55 ( V_121 , V_125 , V_125 -> V_162 , 0 ) ;
return 0 ;
}
static int F_58 ( struct V_120 * V_121 )
{
struct V_119 * V_125 = F_46 ( V_121 ) ;
struct V_69 * V_70 = V_121 -> V_68 -> V_123 ;
if ( V_70 -> V_89 -> type == V_117 )
V_125 -> V_162 -> V_166 = V_167 ;
else
V_125 -> V_162 -> V_166 = V_168 ;
V_125 -> V_162 -> V_169 = V_170 ;
F_59 ( V_70 -> V_89 -> V_75 , NULL , V_125 -> V_162 ,
( V_121 -> V_134 -> V_171 == V_172 ) ,
V_156 ) ;
return V_173 ;
}
static void F_60 ( struct V_120 * V_121 )
{
struct V_119 * V_125 = F_46 ( V_121 ) ;
struct V_145 * V_146 = V_121 -> V_134 ;
if ( F_51 ( V_146 ) -> V_147 != F_51 ( V_146 ) -> V_148 )
F_11 ( V_125 -> V_126 ) ;
F_11 ( V_125 ) ;
}
static T_3 F_61 ( struct V_5 * V_6 ,
struct V_67 * V_68 ,
const char * V_174 ,
T_3 V_175 )
{
struct V_69 * V_70 = V_68 -> V_176 ;
struct V_9 * V_10 = V_6 -> V_18 ;
char * V_177 , * V_178 , * V_179 ;
T_4 args [ V_180 ] ;
int V_37 = 0 , V_181 , V_182 ;
V_179 = F_62 ( V_174 , V_11 ) ;
if ( ! V_179 )
return - V_183 ;
V_177 = V_179 ;
while ( ( V_178 = F_63 ( & V_179 , L_50 ) ) != NULL ) {
if ( ! * V_178 )
continue;
V_182 = F_64 ( V_178 , V_184 , args ) ;
switch ( V_182 ) {
case V_185 :
if ( V_10 -> V_13 == V_29 ) {
F_4 ( V_4 L_51
L_52
L_53 ,
V_10 -> V_12 ) ;
V_37 = - V_103 ;
goto V_64;
}
F_65 ( args , & V_181 ) ;
V_70 -> V_113 = V_181 ;
F_4 ( V_19 L_54
L_55 , V_10 -> V_12 , V_70 -> V_113 ) ;
V_70 -> V_106 |= V_107 ;
break;
case V_186 :
F_65 ( args , & V_181 ) ;
V_70 -> V_114 = V_181 ;
F_4 ( V_19 L_56
L_57 , V_10 -> V_12 ,
V_70 -> V_114 ) ;
V_70 -> V_106 |= V_187 ;
break;
case V_188 :
F_65 ( args , & V_181 ) ;
V_70 -> V_115 = V_181 ;
F_4 ( V_19 L_58
L_57 , V_10 -> V_12 ,
V_70 -> V_115 ) ;
V_70 -> V_106 |= V_189 ;
break;
case V_190 :
F_65 ( args , & V_181 ) ;
V_70 -> V_116 = V_181 ;
F_4 ( V_19 L_59
L_55 , V_10 -> V_12 , V_70 -> V_116 ) ;
V_70 -> V_106 |= V_191 ;
break;
default:
break;
}
}
V_64:
F_11 ( V_177 ) ;
return ( ! V_37 ) ? V_175 : V_37 ;
}
static T_3 F_66 (
struct V_5 * V_6 ,
struct V_67 * V_68 )
{
struct V_69 * V_70 = V_68 -> V_176 ;
if ( ! ( V_70 -> V_106 & V_187 ) ||
! ( V_70 -> V_106 & V_189 ) ||
! ( V_70 -> V_106 & V_191 ) ) {
F_4 ( V_4 L_60
L_61 ) ;
return - 1 ;
}
return 0 ;
}
static T_3 F_67 ( struct V_5 * V_6 ,
struct V_67 * V_68 ,
char * V_192 )
{
struct V_9 * V_10 = V_6 -> V_18 ;
struct V_69 * V_70 = V_68 -> V_176 ;
struct V_32 * V_71 = V_70 -> V_89 ;
unsigned char V_7 [ 16 ] ;
T_3 V_193 ;
int V_194 ;
if ( V_10 -> V_13 == V_14 )
snprintf ( V_7 , 16 , L_62 , V_70 -> V_113 ) ;
else
snprintf ( V_7 , 16 , L_63 ) ;
V_193 = sprintf ( V_192 , L_64
L_65 ,
V_70 -> V_114 , V_70 -> V_115 , V_70 -> V_116 ,
V_7 ) ;
if ( V_71 ) {
V_193 += sprintf ( V_192 + V_193 , L_66 ) ;
V_193 += sprintf ( V_192 + V_193 , L_67 ) ;
for ( V_194 = 0 ; V_194 < 8 ; V_194 ++ ) {
if ( ISPRINT ( V_71 -> V_48 [ V_194 ] ) )
V_193 += sprintf ( V_192 + V_193 , L_68 , V_71 -> V_48 [ V_194 ] ) ;
else
V_193 += sprintf ( V_192 + V_193 , L_69 ) ;
}
V_193 += sprintf ( V_192 + V_193 , L_70 ) ;
for ( V_194 = 0 ; V_194 < 16 ; V_194 ++ ) {
if ( ISPRINT ( V_71 -> V_49 [ V_194 ] ) )
V_193 += sprintf ( V_192 + V_193 , L_68 , V_71 -> V_49 [ V_194 ] ) ;
else
V_193 += sprintf ( V_192 + V_193 , L_69 ) ;
}
V_193 += sprintf ( V_192 + V_193 , L_71 ) ;
for ( V_194 = 0 ; V_194 < 4 ; V_194 ++ ) {
if ( ISPRINT ( V_71 -> V_195 [ V_194 ] ) )
V_193 += sprintf ( V_192 + V_193 , L_68 , V_71 -> V_195 [ V_194 ] ) ;
else
V_193 += sprintf ( V_192 + V_193 , L_69 ) ;
}
V_193 += sprintf ( V_192 + V_193 , L_72 ) ;
}
return V_193 ;
}
static void F_68 ( struct V_196 * V_196 , int error )
{
F_69 ( V_196 ) ;
}
static inline struct V_196 * F_70 ( struct V_69 * V_70 , int V_197 )
{
struct V_196 * V_196 ;
V_196 = F_71 ( V_11 , V_197 ) ;
if ( ! ( V_196 ) ) {
F_4 ( V_4 L_73 ) ;
return NULL ;
}
V_196 -> V_198 = F_68 ;
return V_196 ;
}
static int F_72 (
struct V_120 * V_121 ,
struct V_139 * V_141 ,
T_1 V_199 ,
int V_152 )
{
struct V_119 * V_125 = F_46 ( V_121 ) ;
struct V_69 * V_70 = V_121 -> V_68 -> V_123 ;
struct V_196 * V_196 = NULL , * V_200 = NULL , * V_201 = NULL ;
struct V_174 * V_174 ;
struct V_139 * V_140 ;
T_1 V_202 = V_121 -> V_203 , V_194 , V_204 , V_205 , V_60 ;
int V_206 = ( V_121 -> V_203 + V_141 [ 0 ] . V_207 +
V_208 - 1 ) >> V_209 ;
int V_210 = 0 , V_211 , V_37 = V_212 ;
int V_213 = ( V_121 -> V_163 == V_164 ) ;
if ( ! V_121 -> V_203 )
return 0 ;
F_73 ( L_74 , V_206 ) ;
F_74 (task_sg, sg, task_sg_num, i) {
V_174 = F_75 ( V_140 ) ;
V_60 = V_140 -> V_207 ;
V_204 = V_140 -> V_214 ;
F_73 ( L_75 , V_194 ,
V_174 , V_204 , V_60 ) ;
while ( V_204 > 0 && V_202 > 0 ) {
V_205 = F_76 (unsigned int, len, PAGE_SIZE - off) ;
V_205 = F_77 ( V_205 , V_202 ) ;
if ( ! ( V_196 ) ) {
V_210 = F_76 ( int , V_215 , V_206 ) ;
V_206 -= V_210 ;
V_196 = F_70 ( V_70 , V_210 ) ;
if ( ! ( V_196 ) )
goto V_216;
if ( V_213 )
V_196 -> V_217 |= V_218 ;
F_73 ( L_76
L_77 , V_196 ,
( V_213 ) ? L_78 : L_79 , V_210 ) ;
if ( ! V_200 )
V_200 = V_201 = V_196 ;
else
V_201 = V_201 -> V_219 = V_196 ;
}
F_73 ( L_80
L_81 , V_194 , V_196 ,
V_174 , V_204 , V_60 ) ;
V_211 = F_78 ( V_70 -> V_89 -> V_75 ,
V_196 , V_174 , V_205 , V_60 ) ;
if ( V_211 != V_205 )
goto V_216;
F_73 ( L_82 ,
V_196 -> V_220 , V_210 ) ;
if ( V_196 -> V_220 > V_210 ) {
F_73 ( L_83
L_84
L_85 , V_196 -> V_220 , V_194 , V_196 ) ;
V_196 = NULL ;
}
V_174 ++ ;
V_204 -= V_205 ;
V_202 -= V_205 ;
V_60 = 0 ;
}
}
if ( ! ( V_152 ) ) {
V_125 -> V_162 = F_79 ( V_70 -> V_89 -> V_75 ,
V_200 , V_11 ) ;
if ( ! ( V_125 -> V_162 ) ) {
F_4 ( V_4 L_86 ) ;
goto V_216;
}
F_55 ( V_121 , V_125 , V_125 -> V_162 , 0 ) ;
return V_121 -> V_199 ;
}
V_125 -> V_162 -> V_221 = F_79 ( V_70 -> V_89 -> V_75 ,
V_200 , V_11 ) ;
if ( ! ( V_125 -> V_162 -> V_221 ) ) {
F_4 ( V_4 L_87 ) ;
goto V_216;
}
F_55 ( V_121 , V_125 , V_125 -> V_162 -> V_221 , 1 ) ;
return V_121 -> V_199 ;
V_216:
while ( V_200 ) {
V_196 = V_200 ;
V_200 = V_200 -> V_219 ;
V_196 -> V_219 = NULL ;
F_80 ( V_196 , 0 ) ;
}
return V_37 ;
}
static int F_81 ( struct V_120 * V_121 )
{
int V_37 ;
V_37 = F_72 ( V_121 , V_121 -> V_141 , V_121 -> V_199 , 0 ) ;
if ( V_37 >= 0 && V_121 -> V_222 ) {
V_37 = F_72 ( V_121 , V_121 -> V_222 ,
V_121 -> V_199 , 1 ) ;
}
if ( V_37 < 0 )
return V_165 ;
return 0 ;
}
static int F_82 ( struct V_120 * V_121 )
{
struct V_145 * V_146 = F_50 ( V_121 ) ;
struct V_119 * V_125 = F_46 ( V_121 ) ;
struct V_69 * V_70 = V_121 -> V_68 -> V_123 ;
int V_37 = 0 ;
if ( F_56 ( V_121 ) < 0 )
return V_165 ;
if ( ! V_121 -> V_203 )
return 0 ;
V_37 = F_83 ( V_70 -> V_89 -> V_75 ,
V_125 -> V_162 , F_51 ( V_146 ) -> V_135 ,
V_121 -> V_203 , V_11 ) ;
if ( V_37 < 0 ) {
F_4 ( V_4 L_88 , V_37 ) ;
return V_165 ;
}
return 0 ;
}
static int F_84 ( struct V_120 * V_121 )
{
return F_56 ( V_121 ) ;
}
static unsigned char * F_85 ( struct V_120 * V_121 )
{
struct V_119 * V_125 = F_46 ( V_121 ) ;
return V_125 -> V_126 ;
}
static unsigned char * F_86 ( struct V_120 * V_121 )
{
struct V_119 * V_125 = F_46 ( V_121 ) ;
return ( unsigned char * ) & V_125 -> V_160 [ 0 ] ;
}
static T_1 F_87 ( struct V_30 * V_31 )
{
struct V_69 * V_70 = V_31 -> V_123 ;
struct V_32 * V_71 = V_70 -> V_89 ;
return ( V_71 -> V_223 - 1 ) ? V_71 -> V_223 - 1 : 1 ;
}
static T_1 F_88 ( struct V_30 * V_31 )
{
struct V_69 * V_70 = V_31 -> V_123 ;
struct V_32 * V_71 = V_70 -> V_89 ;
return V_71 -> type ;
}
static T_5 F_89 ( struct V_30 * V_31 )
{
struct V_69 * V_70 = V_31 -> V_123 ;
if ( V_70 -> V_100 && V_70 -> V_100 -> V_224 )
return V_70 -> V_100 -> V_224 -> V_225 ;
F_90 () ;
return 0 ;
}
static inline void F_91 (
struct V_120 * V_121 ,
struct V_119 * V_125 )
{
V_121 -> V_226 = F_49 ( V_125 -> V_127 ) ;
if ( ( V_121 -> V_226 ) ) {
V_121 -> V_226 <<= 1 ;
F_4 ( V_19 L_89
L_90 , V_121 , V_125 -> V_126 [ 0 ] ,
V_125 -> V_127 ) ;
}
switch ( F_92 ( V_125 -> V_127 ) ) {
case V_227 :
F_93 ( V_121 , ( ! V_121 -> V_226 ) ) ;
break;
default:
F_4 ( V_19 L_91
L_90 , V_121 , V_125 -> V_126 [ 0 ] ,
V_125 -> V_127 ) ;
V_121 -> V_226 = V_228 ;
V_121 -> V_229 = V_230 ;
F_50 ( V_121 ) -> V_231 =
V_230 ;
F_93 ( V_121 , 0 ) ;
break;
}
return;
}
static void V_156 ( struct V_150 * V_151 , int V_232 )
{
struct V_120 * V_121 = V_151 -> V_157 ;
struct V_119 * V_125 = F_46 ( V_121 ) ;
V_125 -> V_127 = V_151 -> V_233 ;
V_125 -> V_234 = V_151 -> V_235 ;
F_91 ( V_121 , V_125 ) ;
if ( V_151 -> V_221 != NULL )
F_94 ( V_151 -> V_76 , V_151 -> V_221 ) ;
F_94 ( V_151 -> V_76 , V_151 ) ;
V_125 -> V_162 = NULL ;
}
static int T_6 F_95 ( void )
{
return F_96 ( & V_90 ) ;
}
static void F_97 ( void )
{
F_98 ( & V_90 ) ;
}
