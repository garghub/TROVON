static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 . V_5 ) {
V_2 -> V_3 . V_4 . V_5 ( V_2 ) ;
F_2 ( V_2 -> V_3 . V_4 . V_5 ) ;
}
if ( V_2 -> V_3 . V_6 . V_5 ) {
V_2 -> V_3 . V_6 . V_5 ( V_2 ) ;
F_2 ( V_2 -> V_3 . V_6 . V_5 ) ;
}
}
static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 . V_5 )
V_2 -> V_3 . V_4 . V_5 ( V_2 ) ;
if ( V_2 -> V_3 . V_6 . V_5 )
V_2 -> V_3 . V_6 . V_5 ( V_2 ) ;
}
static inline struct V_7 * F_3 ( struct V_8 * V_9 )
{
return F_4 ( V_9 , struct V_7 , V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = & V_2 -> V_3 . V_4 ;
struct V_7 * V_14 = V_2 -> V_15 ;
if ( NULL == V_13 -> V_16 ) {
F_6 ( L_1 ) ;
return;
}
V_13 -> V_16 ( V_2 , V_11 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = & V_2 -> V_3 . V_4 ;
if ( V_13 -> V_17 )
V_13 -> V_17 ( V_2 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
T_1 V_18 = 0 ;
if ( V_2 -> V_3 . V_4 . V_19 )
V_2 -> V_3 . V_4 . V_19 ( V_2 , & V_18 ) ;
return V_18 ;
}
static int F_9 ( struct V_1 * V_2 , void * V_20 )
{
struct V_12 * V_13 = & V_2 -> V_3 . V_4 ;
struct V_7 * V_14 = V_2 -> V_15 ;
if ( V_13 -> V_21 )
return V_13 -> V_21 ( V_2 , V_20 ) ;
F_6 ( L_2 ) ;
return 0 ;
}
static void F_10 ( struct V_22 * V_23 , unsigned int type ,
unsigned int V_24 , unsigned int V_25 ,
int (* F_11) ( void * V_26 , int V_27 , int V_28 , int V_29 ) )
{
struct V_7 * V_14 = F_3 ( F_12 ( V_23 ) ) ;
struct V_12 * V_13 = & V_14 -> V_2 . V_3 . V_4 ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
unsigned char V_31 [ 4 ] ;
int V_32 = 1 ;
if ( type == V_33 || type == V_34 ) {
F_13 ( L_3 , V_23 -> V_35 ) ;
return;
}
V_14 -> type = type ;
V_14 -> V_36 = V_25 < 256 ? V_25 : 0 ;
if ( F_11 != NULL ) {
F_13 ( L_4 ) ;
V_14 -> V_2 . V_37 = F_11 ;
}
F_1 ( & V_14 -> V_2 ) ;
V_14 -> V_2 . V_15 = NULL ;
switch ( V_14 -> type ) {
case V_38 :
if ( ! F_14 ( V_39 ,
& V_14 -> V_2 , V_14 -> V_40 -> V_41 , V_14 -> V_40 -> V_35 ) )
goto V_42;
break;
case V_43 :
{
struct V_44 V_45 = {
. V_46 = V_14 -> V_36 ,
} ;
if ( ! F_14 ( V_47 , & V_14 -> V_2 , V_14 -> V_40 -> V_41 ,
V_14 -> V_40 -> V_35 , & V_45 ) )
goto V_42;
break;
}
case V_48 :
if ( ! F_14 ( V_49 , & V_14 -> V_2 ,
V_14 -> V_40 -> V_41 , V_14 -> V_40 -> V_35 ) )
goto V_42;
V_14 -> V_50 = V_51 ;
break;
case V_52 :
if ( ! F_14 ( V_53 , & V_14 -> V_2 ,
V_14 -> V_40 -> V_41 , V_14 -> V_40 -> V_35 ) )
goto V_42;
V_14 -> V_50 = V_51 ;
break;
case V_54 :
case V_55 :
V_31 [ 0 ] = 0x0b ;
V_31 [ 1 ] = 0xdc ;
V_31 [ 2 ] = 0x9c ;
V_31 [ 3 ] = 0x60 ;
F_15 ( V_23 , V_31 , 4 ) ;
F_16 ( 1 ) ;
V_31 [ 2 ] = 0x86 ;
V_31 [ 3 ] = 0x54 ;
F_15 ( V_23 , V_31 , 4 ) ;
if ( ! F_14 ( V_56 , & V_14 -> V_2 ,
V_14 -> V_40 -> V_41 , V_14 -> V_40 -> V_35 , V_14 -> type ) )
goto V_42;
break;
case V_57 :
V_31 [ 0 ] = 0x0b ;
V_31 [ 1 ] = 0xdc ;
V_31 [ 2 ] = 0x86 ;
V_31 [ 3 ] = 0xa4 ;
F_15 ( V_23 , V_31 , 4 ) ;
if ( ! F_14 ( V_56 , & V_14 -> V_2 ,
V_14 -> V_40 -> V_41 , V_14 -> V_40 -> V_35 , V_14 -> type ) )
goto V_42;
break;
case V_58 :
{
struct V_59 V_45 = {
. V_60 = V_14 -> V_40 -> V_41 ,
. V_61 = V_14 -> V_40 -> V_35 ,
} ;
if ( ! F_14 ( V_62 , & V_14 -> V_2 , & V_45 ) )
goto V_42;
V_32 = 0 ;
break;
}
case V_63 :
if ( ! F_14 ( V_64 ,
& V_14 -> V_2 , V_14 -> V_40 -> V_41 , V_14 -> V_40 -> V_35 ) )
goto V_42;
break;
case V_65 :
{
struct V_66 V_67 = {
. V_68 = V_14 -> V_40 -> V_35 ,
. V_69 = 0 ,
} ;
if ( ! F_14 ( V_70 ,
& V_14 -> V_2 , V_14 -> V_40 -> V_41 , & V_67 ) )
goto V_42;
V_32 = 0 ;
break;
}
case V_71 :
{
struct V_72 V_45 = {
. V_36 = V_14 -> V_36 ,
. V_73 = V_74 ,
} ;
if ( ! F_14 ( V_75 , & V_14 -> V_2 , V_14 -> V_40 -> V_35 ,
V_14 -> V_40 -> V_41 , & V_45 ) )
goto V_42;
V_32 = 0 ;
break;
}
case V_76 :
{
struct V_77 V_78 = {
. V_68 = V_14 -> V_40 -> V_35 ,
. V_79 = 0 ,
. V_80 = 0 ,
. V_81 = 0 ,
. V_69 = 0
} ;
if ( ! F_14 ( V_82 ,
& V_14 -> V_2 , V_14 -> V_40 -> V_41 , & V_78 ) )
goto V_42;
V_32 = 0 ;
break;
}
default:
if ( ! F_14 ( V_56 , & V_14 -> V_2 ,
V_14 -> V_40 -> V_41 , V_14 -> V_40 -> V_35 , V_14 -> type ) )
goto V_42;
break;
}
if ( ( NULL == V_6 -> V_83 ) &&
( V_13 -> V_16 ) ) {
V_14 -> V_84 = V_13 -> V_85 . V_84 ;
V_14 -> V_2 . V_15 = V_14 ;
memcpy ( V_6 , & V_86 ,
sizeof( struct V_30 ) ) ;
} else {
V_14 -> V_84 = V_6 -> V_85 . V_84 ;
}
F_13 ( L_5 , V_14 -> V_84 ) ;
V_14 -> V_50 = V_24 ;
if ( V_32 ) {
if ( V_87 == V_14 -> V_88 )
F_17 ( V_23 , V_14 -> V_89 ) ;
else
F_18 ( V_23 , V_14 -> V_90 ) ;
}
F_13 ( L_6 ,
V_23 -> V_41 -> V_84 , V_23 -> V_91 -> V_91 . V_84 , V_23 -> V_35 << 1 , type ,
V_14 -> V_50 ) ;
return;
V_42:
F_13 ( L_7 , V_14 -> type ) ;
V_14 -> type = V_34 ;
return;
}
static int F_19 ( struct V_8 * V_9 ,
struct V_92 * V_93 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_22 * V_23 = F_20 ( V_9 ) ;
F_13 ( L_8 ,
V_93 -> type ,
V_93 -> V_35 ,
V_93 -> V_50 ,
V_93 -> V_36 ) ;
if ( ( V_14 -> type == V_33 && ( ( V_93 -> V_35 == V_94 ) &&
( V_14 -> V_50 & V_93 -> V_50 ) ) ) ||
( V_93 -> V_35 == V_23 -> V_35 ) ) {
F_10 ( V_23 , V_93 -> type , V_93 -> V_50 ,
V_93 -> V_36 , V_93 -> F_11 ) ;
} else
F_13 ( L_9
L_10 ,
V_14 -> type , V_14 -> V_50 ,
V_93 -> V_35 , V_93 -> V_50 ) ;
return 0 ;
}
static int F_21 ( struct V_8 * V_9 ,
const struct V_95 * V_45 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_14 -> type != V_45 -> V_7 )
return 0 ;
if ( V_6 -> V_21 ) {
V_6 -> V_21 ( & V_14 -> V_2 , V_45 -> V_96 ) ;
return 0 ;
}
F_13 ( L_2 ) ;
return 0 ;
}
static void F_22 ( struct V_97 * V_98 ,
struct V_7 * * V_99 , struct V_7 * * V_100 )
{
struct V_7 * V_101 ;
* V_99 = NULL ;
* V_100 = NULL ;
F_23 (pos, &tuner_list, list) {
int V_50 ;
if ( V_101 -> V_40 -> V_41 != V_98 ||
strcmp ( V_101 -> V_40 -> V_91 -> V_91 . V_84 , L_11 ) )
continue;
V_50 = V_101 -> V_50 ;
if ( * V_99 == NULL && V_50 == V_51 )
* V_99 = V_101 ;
else if ( * V_100 == NULL && V_101 -> type != V_63 &&
( V_101 -> V_50 & V_102 ) )
* V_100 = V_101 ;
}
}
static int F_24 ( struct V_22 * V_103 ,
const struct V_104 * V_105 )
{
struct V_7 * V_14 ;
struct V_7 * V_99 ;
struct V_7 * V_100 ;
V_14 = F_25 ( sizeof( struct V_7 ) , V_106 ) ;
if ( NULL == V_14 )
return - V_107 ;
F_26 ( & V_14 -> V_9 , V_103 , & V_4 ) ;
V_14 -> V_40 = V_103 ;
V_14 -> V_84 = L_12 ;
V_14 -> type = V_33 ;
V_14 -> V_108 = V_109 ;
V_14 -> V_110 = 1 ;
V_14 -> V_89 = 87.5 * 16000 ;
V_14 -> V_90 = 400 * 16 ;
if ( V_111 ) {
unsigned char V_31 [ 16 ] ;
int V_112 , V_113 ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
V_113 = F_27 ( V_103 , V_31 , sizeof( V_31 ) ) ;
F_28 ( L_13 ) ;
for ( V_112 = 0 ; V_112 < V_113 ; V_112 ++ )
F_29 ( V_114 L_14 , V_31 [ V_112 ] ) ;
F_29 ( L_15 ) ;
}
if ( ! V_115 ) {
switch ( V_103 -> V_35 ) {
case 0x10 :
if ( F_30 ( V_116 ,
V_14 -> V_40 -> V_41 ,
V_14 -> V_40 -> V_35 ) >= 0 ) {
V_14 -> type = V_52 ;
V_14 -> V_50 = V_51 ;
F_22 ( V_14 -> V_40 -> V_41 , & V_99 , & V_100 ) ;
if ( V_100 )
V_100 -> V_50 &= ~ V_51 ;
goto V_117;
}
F_31 ( V_14 ) ;
return - V_118 ;
case 0x42 :
case 0x43 :
case 0x4a :
case 0x4b :
if ( F_30 ( V_119 , V_14 -> V_40 -> V_41 ,
V_14 -> V_40 -> V_35 ) >= 0 ) {
F_13 ( L_16 ) ;
} else {
V_14 -> type = V_63 ;
V_14 -> V_50 = V_51 | V_102 ;
goto V_117;
}
break;
case 0x60 :
if ( F_30 ( V_120 ,
V_14 -> V_40 -> V_41 , V_14 -> V_40 -> V_35 )
>= 0 ) {
V_14 -> type = V_48 ;
V_14 -> V_50 = V_51 ;
F_22 ( V_14 -> V_40 -> V_41 , & V_99 , & V_100 ) ;
if ( V_100 )
V_100 -> V_50 &= ~ V_51 ;
goto V_117;
}
break;
}
}
F_22 ( V_14 -> V_40 -> V_41 , & V_99 , & V_100 ) ;
if ( V_100 == NULL ) {
V_14 -> V_50 = V_102 ;
if ( V_99 == NULL )
V_14 -> V_50 |= V_51 ;
F_13 ( L_17 , V_14 -> V_50 ) ;
}
V_117:
if ( V_14 -> V_50 & V_102 )
V_14 -> V_88 = V_121 ;
else
V_14 -> V_88 = V_87 ;
F_10 ( V_103 , V_14 -> type , V_14 -> V_50 , V_14 -> V_36 , V_14 -> V_2 . V_37 ) ;
F_32 ( & V_14 -> V_122 , & V_123 ) ;
F_28 ( L_18 ,
V_14 -> type ,
V_14 -> V_50 & V_51 ? L_19 : L_20 ,
V_14 -> V_50 & V_102 ? L_21 : L_20 ) ;
return 0 ;
}
static int F_33 ( struct V_22 * V_103 )
{
struct V_7 * V_14 = F_3 ( F_12 ( V_103 ) ) ;
F_34 ( & V_14 -> V_9 ) ;
F_1 ( & V_14 -> V_2 ) ;
V_14 -> V_2 . V_15 = NULL ;
F_35 ( & V_14 -> V_122 ) ;
F_31 ( V_14 ) ;
return 0 ;
}
static inline int F_36 ( struct V_7 * V_14 , enum V_124 V_88 )
{
int V_125 ;
if ( V_88 == V_87 )
V_125 = V_51 ;
else
V_125 = V_102 ;
if ( ( V_125 & V_14 -> V_50 ) == 0 )
return - V_126 ;
return 0 ;
}
static int F_37 ( struct V_7 * V_14 , enum V_124 V_88 )
{
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_88 != V_14 -> V_88 ) {
if ( F_36 ( V_14 , V_88 ) == - V_126 ) {
F_13 ( L_22
L_23 , V_88 ) ;
V_14 -> V_110 = true ;
if ( V_6 -> V_110 )
V_6 -> V_110 ( & V_14 -> V_2 ) ;
return - V_126 ;
}
V_14 -> V_88 = V_88 ;
F_13 ( L_24 , V_88 ) ;
}
return 0 ;
}
static void F_38 ( struct V_7 * V_14 , unsigned int V_127 )
{
struct V_22 * V_103 = F_20 ( & V_14 -> V_9 ) ;
if ( V_14 -> V_88 == V_87 ) {
if ( ! V_127 )
V_127 = V_14 -> V_89 ;
F_17 ( V_103 , V_127 ) ;
} else {
if ( ! V_127 )
V_127 = V_14 -> V_90 ;
F_18 ( V_103 , V_127 ) ;
}
}
static void F_18 ( struct V_22 * V_23 , unsigned int V_127 )
{
struct V_7 * V_14 = F_3 ( F_12 ( V_23 ) ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_10 V_11 = {
. V_88 = V_14 -> V_88 ,
. V_108 = V_14 -> V_108 ,
. V_128 = V_14 -> V_128
} ;
if ( V_14 -> type == V_33 ) {
F_6 ( L_25 ) ;
return;
}
if ( NULL == V_6 -> V_83 ) {
F_6 ( L_26 ) ;
return;
}
if ( V_127 < V_129 [ 0 ] * 16 || V_127 > V_129 [ 1 ] * 16 ) {
F_13 ( L_27 ,
V_127 / 16 , V_127 % 16 * 100 / 16 , V_129 [ 0 ] ,
V_129 [ 1 ] ) ;
if ( V_127 < V_129 [ 0 ] * 16 )
V_127 = V_129 [ 0 ] * 16 ;
else
V_127 = V_129 [ 1 ] * 16 ;
}
V_11 . V_130 = V_127 ;
F_13 ( L_28 ,
V_127 / 16 , V_127 % 16 * 100 / 16 ) ;
V_14 -> V_90 = V_127 ;
V_14 -> V_110 = false ;
V_6 -> V_83 ( & V_14 -> V_2 , & V_11 ) ;
}
static T_2 F_39 ( struct V_7 * V_14 , T_2 V_128 )
{
if ( V_131 [ 0 ] != '-' && ( V_128 & V_132 ) == V_132 ) {
switch ( V_131 [ 0 ] ) {
case '6' :
return V_133 ;
case 'b' :
case 'B' :
case 'g' :
case 'G' :
return V_134 ;
case 'i' :
case 'I' :
return V_135 ;
case 'd' :
case 'D' :
case 'k' :
case 'K' :
return V_136 ;
case 'M' :
case 'm' :
return V_137 ;
case 'N' :
case 'n' :
if ( V_131 [ 1 ] == 'c' || V_131 [ 1 ] == 'C' )
return V_138 ;
return V_139 ;
default:
F_6 ( L_29 ) ;
break;
}
}
if ( V_140 [ 0 ] != '-' && ( V_128 & V_141 ) == V_141 ) {
switch ( V_140 [ 0 ] ) {
case 'b' :
case 'B' :
case 'g' :
case 'G' :
case 'h' :
case 'H' :
return V_142 |
V_143 |
V_144 ;
case 'd' :
case 'D' :
case 'k' :
case 'K' :
return V_145 ;
case 'l' :
case 'L' :
if ( ( V_140 [ 1 ] == 'C' ) || ( V_140 [ 1 ] == 'c' ) )
return V_146 ;
return V_147 ;
default:
F_6 ( L_30 ) ;
break;
}
}
if ( V_148 [ 0 ] != '-' && ( V_128 & V_149 ) == V_149 ) {
switch ( V_148 [ 0 ] ) {
case 'm' :
case 'M' :
return V_150 ;
case 'j' :
case 'J' :
return V_151 ;
case 'k' :
case 'K' :
return V_152 ;
default:
F_28 ( L_31 ) ;
break;
}
}
return V_128 ;
}
static void F_17 ( struct V_22 * V_23 , unsigned int V_127 )
{
struct V_7 * V_14 = F_3 ( F_12 ( V_23 ) ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_10 V_11 = {
. V_88 = V_14 -> V_88 ,
. V_108 = V_14 -> V_108 ,
. V_128 = V_14 -> V_128
} ;
if ( V_14 -> type == V_33 ) {
F_6 ( L_25 ) ;
return;
}
if ( NULL == V_6 -> V_83 ) {
F_6 ( L_32 ) ;
return;
}
if ( V_127 < V_153 [ 0 ] * 16000 || V_127 > V_153 [ 1 ] * 16000 ) {
F_13 ( L_33 ,
V_127 / 16000 , V_127 % 16000 * 100 / 16000 ,
V_153 [ 0 ] , V_153 [ 1 ] ) ;
if ( V_127 < V_153 [ 0 ] * 16000 )
V_127 = V_153 [ 0 ] * 16000 ;
else
V_127 = V_153 [ 1 ] * 16000 ;
}
V_11 . V_130 = V_127 ;
F_13 ( L_34 ,
V_127 / 16000 , V_127 % 16000 * 100 / 16000 ) ;
V_14 -> V_89 = V_127 ;
V_14 -> V_110 = false ;
V_6 -> V_83 ( & V_14 -> V_2 , & V_11 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_7 * V_14 = V_2 -> V_15 ;
unsigned long V_127 , V_154 ;
struct V_12 * V_13 = & V_2 -> V_3 . V_4 ;
struct V_30 * V_6 = & V_2 -> V_3 . V_6 ;
const char * V_155 ;
switch ( V_14 -> V_88 ) {
case V_87 :
V_155 = L_35 ;
break;
case V_156 :
V_155 = L_36 ;
break;
case V_121 :
default:
V_155 = L_37 ;
break;
}
if ( V_14 -> V_88 == V_87 ) {
V_127 = V_14 -> V_89 / 16000 ;
V_154 = ( V_14 -> V_89 % 16000 ) * 100 / 16000 ;
} else {
V_127 = V_14 -> V_90 / 16 ;
V_154 = ( V_14 -> V_90 % 16 ) * 100 / 16 ;
}
F_28 ( L_38 , V_155 ,
V_14 -> V_110 ? L_39 : L_20 ) ;
F_28 ( L_40 , V_127 , V_154 ) ;
F_28 ( L_41 , ( unsigned long ) V_14 -> V_128 ) ;
if ( V_14 -> V_88 != V_87 )
return;
if ( V_13 -> V_157 ) {
T_3 F_40 ;
V_13 -> V_157 ( & V_14 -> V_2 , & F_40 ) ;
if ( F_40 & V_158 )
F_28 ( L_42 ) ;
if ( F_40 & V_159 )
F_28 ( L_43 ) ;
}
if ( V_6 -> V_160 )
F_28 ( L_44 ,
V_6 -> V_160 ( V_2 ) ) ;
}
static int F_41 ( struct V_8 * V_9 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_37 ( V_14 , V_87 ) == 0 )
F_38 ( V_14 , 0 ) ;
return 0 ;
}
static int F_42 ( struct V_8 * V_9 , int V_161 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_161 ) {
if ( V_14 -> V_110 && F_37 ( V_14 , V_14 -> V_88 ) == 0 ) {
F_13 ( L_45 ) ;
F_38 ( V_14 , 0 ) ;
}
return 0 ;
}
F_13 ( L_23 ) ;
V_14 -> V_110 = true ;
if ( V_6 -> V_110 )
V_6 -> V_110 ( & V_14 -> V_2 ) ;
return 0 ;
}
static int F_43 ( struct V_8 * V_9 , T_2 V_128 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_37 ( V_14 , V_121 ) )
return 0 ;
V_14 -> V_128 = F_39 ( V_14 , V_128 ) ;
if ( V_14 -> V_128 != V_128 )
F_13 ( L_46 , V_128 , V_14 -> V_128 ) ;
F_38 ( V_14 , 0 ) ;
return 0 ;
}
static int F_44 ( struct V_8 * V_9 , struct V_162 * V_163 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_37 ( V_14 , V_163 -> type ) == 0 )
F_38 ( V_14 , V_163 -> V_130 ) ;
return 0 ;
}
static int F_45 ( struct V_8 * V_9 , struct V_162 * V_163 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_12 * V_13 = & V_14 -> V_2 . V_3 . V_4 ;
if ( F_36 ( V_14 , V_163 -> type ) == - V_126 )
return 0 ;
if ( V_163 -> type == V_14 -> V_88 && V_13 -> V_164 && ! V_14 -> V_110 ) {
T_3 V_165 ;
V_13 -> V_164 ( & V_14 -> V_2 , & V_165 ) ;
V_163 -> V_130 = ( V_87 == V_14 -> V_88 ) ?
F_46 ( V_165 * 2 , 125 ) :
F_46 ( V_165 , 62500 ) ;
} else {
V_163 -> V_130 = ( V_87 == V_163 -> type ) ?
V_14 -> V_89 : V_14 -> V_90 ;
}
return 0 ;
}
static int F_47 ( struct V_8 * V_9 , struct V_166 * V_167 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_12 * V_13 = & V_14 -> V_2 . V_3 . V_4 ;
if ( F_36 ( V_14 , V_167 -> type ) == - V_126 )
return 0 ;
if ( V_167 -> type == V_14 -> V_88 && V_6 -> V_168 )
V_167 -> V_169 = V_6 -> V_168 ( & V_14 -> V_2 ) ;
if ( V_14 -> V_88 != V_87 ) {
V_167 -> V_170 |= V_171 ;
V_167 -> V_172 = V_129 [ 0 ] * 16 ;
V_167 -> V_173 = V_129 [ 1 ] * 16 ;
return 0 ;
}
if ( V_167 -> type == V_14 -> V_88 ) {
V_167 -> V_174 = V_175 | V_176 ;
if ( V_13 -> V_157 ) {
T_3 F_40 ;
V_13 -> V_157 ( & V_14 -> V_2 , & F_40 ) ;
V_167 -> V_174 =
( F_40 & V_159 ) ?
V_176 :
V_175 ;
}
if ( V_6 -> V_160 )
V_167 -> signal = V_6 -> V_160 ( & V_14 -> V_2 ) ;
V_167 -> V_108 = V_14 -> V_108 ;
}
V_167 -> V_170 |= V_177 | V_178 ;
V_167 -> V_172 = V_153 [ 0 ] * 16000 ;
V_167 -> V_173 = V_153 [ 1 ] * 16000 ;
return 0 ;
}
static int F_48 ( struct V_8 * V_9 , struct V_166 * V_167 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_37 ( V_14 , V_167 -> type ) )
return 0 ;
if ( V_14 -> V_88 == V_87 )
V_14 -> V_108 = V_167 -> V_108 ;
F_38 ( V_14 , 0 ) ;
return 0 ;
}
static int F_49 ( struct V_8 * V_9 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_6 -> F_40 )
V_6 -> F_40 ( & V_14 -> V_2 ) ;
return 0 ;
}
static int F_50 ( struct V_22 * V_23 , T_4 V_179 )
{
struct V_7 * V_14 = F_3 ( F_12 ( V_23 ) ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
F_13 ( L_47 ) ;
if ( ! V_14 -> V_110 && V_6 -> V_110 )
V_6 -> V_110 ( & V_14 -> V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_22 * V_23 )
{
struct V_7 * V_14 = F_3 ( F_12 ( V_23 ) ) ;
F_13 ( L_48 ) ;
if ( ! V_14 -> V_110 )
if ( F_37 ( V_14 , V_14 -> V_88 ) == 0 )
F_38 ( V_14 , 0 ) ;
return 0 ;
}
static int F_52 ( struct V_22 * V_103 , unsigned V_28 , void * V_29 )
{
struct V_8 * V_9 = F_12 ( V_103 ) ;
switch ( V_28 ) {
case V_180 :
return F_21 ( V_9 , V_29 ) ;
}
return - V_181 ;
}
static T_5 int F_53 ( void )
{
return F_54 ( & V_182 ) ;
}
static T_6 void F_55 ( void )
{
F_56 ( & V_182 ) ;
}
