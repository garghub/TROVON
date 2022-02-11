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
struct V_66 V_72 = {
. V_68 = V_14 -> V_40 -> V_35 ,
. V_69 = 0 ,
. V_73 = V_74 ,
} ;
if ( ! F_14 ( V_70 ,
& V_14 -> V_2 , V_14 -> V_40 -> V_41 , & V_72 ) )
goto V_42;
V_32 = 0 ;
break;
}
case V_75 :
{
struct V_76 V_45 = {
. V_36 = V_14 -> V_36 ,
. V_77 = V_78 ,
} ;
if ( ! F_14 ( V_79 , & V_14 -> V_2 , V_14 -> V_40 -> V_35 ,
V_14 -> V_40 -> V_41 , & V_45 ) )
goto V_42;
V_32 = 0 ;
break;
}
case V_80 :
{
struct V_81 V_82 = {
. V_68 = V_14 -> V_40 -> V_35 ,
. V_83 = 0 ,
. V_84 = 0 ,
. V_85 = 0 ,
. V_69 = 0
} ;
if ( ! F_14 ( V_86 ,
& V_14 -> V_2 , V_14 -> V_40 -> V_41 , & V_82 ) )
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
if ( ( NULL == V_6 -> V_87 ) &&
( V_13 -> V_16 ) ) {
V_14 -> V_88 = V_13 -> V_89 . V_88 ;
V_14 -> V_2 . V_15 = V_14 ;
memcpy ( V_6 , & V_90 ,
sizeof( struct V_30 ) ) ;
} else {
V_14 -> V_88 = V_6 -> V_89 . V_88 ;
}
F_13 ( L_5 , V_14 -> V_88 ) ;
V_14 -> V_50 = V_24 ;
if ( V_32 ) {
if ( V_91 == V_14 -> V_92 )
F_17 ( V_23 , V_14 -> V_93 ) ;
else
F_18 ( V_23 , V_14 -> V_94 ) ;
}
F_13 ( L_6 ,
V_23 -> V_41 -> V_88 , V_23 -> V_95 -> V_95 . V_88 , V_23 -> V_35 << 1 , type ,
V_14 -> V_50 ) ;
return;
V_42:
F_13 ( L_7 , V_14 -> type ) ;
V_14 -> type = V_34 ;
return;
}
static int F_19 ( struct V_8 * V_9 ,
struct V_96 * V_97 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_22 * V_23 = F_20 ( V_9 ) ;
F_13 ( L_8 ,
V_97 -> type ,
V_97 -> V_35 ,
V_97 -> V_50 ,
V_97 -> V_36 ) ;
if ( ( V_14 -> type == V_33 && ( ( V_97 -> V_35 == V_98 ) &&
( V_14 -> V_50 & V_97 -> V_50 ) ) ) ||
( V_97 -> V_35 == V_23 -> V_35 ) ) {
F_10 ( V_23 , V_97 -> type , V_97 -> V_50 ,
V_97 -> V_36 , V_97 -> F_11 ) ;
} else
F_13 ( L_9
L_10 ,
V_14 -> type , V_14 -> V_50 ,
V_97 -> V_35 , V_97 -> V_50 ) ;
return 0 ;
}
static int F_21 ( struct V_8 * V_9 ,
const struct V_99 * V_45 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_14 -> type != V_45 -> V_7 )
return 0 ;
if ( V_6 -> V_21 ) {
V_6 -> V_21 ( & V_14 -> V_2 , V_45 -> V_100 ) ;
return 0 ;
}
F_13 ( L_2 ) ;
return 0 ;
}
static void F_22 ( struct V_101 * V_102 ,
struct V_7 * * V_103 , struct V_7 * * V_104 )
{
struct V_7 * V_105 ;
* V_103 = NULL ;
* V_104 = NULL ;
F_23 (pos, &tuner_list, list) {
int V_50 ;
if ( V_105 -> V_40 -> V_41 != V_102 ||
strcmp ( V_105 -> V_40 -> V_95 -> V_95 . V_88 , L_11 ) )
continue;
V_50 = V_105 -> V_50 ;
if ( * V_103 == NULL && V_50 == V_51 )
* V_103 = V_105 ;
else if ( * V_104 == NULL && V_105 -> type != V_63 &&
( V_105 -> V_50 & V_106 ) )
* V_104 = V_105 ;
}
}
static int F_24 ( struct V_22 * V_107 ,
const struct V_108 * V_109 )
{
struct V_7 * V_14 ;
struct V_7 * V_103 ;
struct V_7 * V_104 ;
V_14 = F_25 ( sizeof( struct V_7 ) , V_110 ) ;
if ( NULL == V_14 )
return - V_111 ;
F_26 ( & V_14 -> V_9 , V_107 , & V_4 ) ;
V_14 -> V_40 = V_107 ;
V_14 -> V_88 = L_12 ;
V_14 -> type = V_33 ;
V_14 -> V_112 = V_113 ;
V_14 -> V_114 = 1 ;
V_14 -> V_93 = 87.5 * 16000 ;
V_14 -> V_94 = 400 * 16 ;
if ( V_115 ) {
unsigned char V_31 [ 16 ] ;
int V_116 , V_117 ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
V_117 = F_27 ( V_107 , V_31 , sizeof( V_31 ) ) ;
F_28 ( L_13 ) ;
for ( V_116 = 0 ; V_116 < V_117 ; V_116 ++ )
F_29 ( V_118 L_14 , V_31 [ V_116 ] ) ;
F_29 ( L_15 ) ;
}
if ( ! V_119 ) {
switch ( V_107 -> V_35 ) {
case 0x10 :
if ( F_30 ( V_120 ,
V_14 -> V_40 -> V_41 ,
V_14 -> V_40 -> V_35 ) >= 0 ) {
V_14 -> type = V_52 ;
V_14 -> V_50 = V_51 ;
F_22 ( V_14 -> V_40 -> V_41 , & V_103 , & V_104 ) ;
if ( V_104 )
V_104 -> V_50 &= ~ V_51 ;
goto V_121;
}
F_31 ( V_14 ) ;
return - V_122 ;
case 0x42 :
case 0x43 :
case 0x4a :
case 0x4b :
if ( F_30 ( V_123 , V_14 -> V_40 -> V_41 ,
V_14 -> V_40 -> V_35 ) >= 0 ) {
F_13 ( L_16 ) ;
} else {
V_14 -> type = V_63 ;
V_14 -> V_50 = V_51 | V_106 ;
goto V_121;
}
break;
case 0x60 :
if ( F_30 ( V_124 ,
V_14 -> V_40 -> V_41 , V_14 -> V_40 -> V_35 )
>= 0 ) {
V_14 -> type = V_48 ;
V_14 -> V_50 = V_51 ;
F_22 ( V_14 -> V_40 -> V_41 , & V_103 , & V_104 ) ;
if ( V_104 )
V_104 -> V_50 &= ~ V_51 ;
goto V_121;
}
break;
}
}
F_22 ( V_14 -> V_40 -> V_41 , & V_103 , & V_104 ) ;
if ( V_104 == NULL ) {
V_14 -> V_50 = V_106 ;
if ( V_103 == NULL )
V_14 -> V_50 |= V_51 ;
F_13 ( L_17 , V_14 -> V_50 ) ;
}
V_121:
if ( V_14 -> V_50 & V_106 )
V_14 -> V_92 = V_125 ;
else
V_14 -> V_92 = V_91 ;
F_10 ( V_107 , V_14 -> type , V_14 -> V_50 , V_14 -> V_36 , V_14 -> V_2 . V_37 ) ;
F_32 ( & V_14 -> V_126 , & V_127 ) ;
F_28 ( L_18 ,
V_14 -> type ,
V_14 -> V_50 & V_51 ? L_19 : L_20 ,
V_14 -> V_50 & V_106 ? L_21 : L_20 ) ;
return 0 ;
}
static int F_33 ( struct V_22 * V_107 )
{
struct V_7 * V_14 = F_3 ( F_12 ( V_107 ) ) ;
F_34 ( & V_14 -> V_9 ) ;
F_1 ( & V_14 -> V_2 ) ;
V_14 -> V_2 . V_15 = NULL ;
F_35 ( & V_14 -> V_126 ) ;
F_31 ( V_14 ) ;
return 0 ;
}
static inline int F_36 ( struct V_7 * V_14 , enum V_128 V_92 )
{
int V_129 ;
if ( V_92 == V_91 )
V_129 = V_51 ;
else
V_129 = V_106 ;
if ( ( V_129 & V_14 -> V_50 ) == 0 )
return - V_130 ;
return 0 ;
}
static int F_37 ( struct V_7 * V_14 , enum V_128 V_92 )
{
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_92 != V_14 -> V_92 ) {
if ( F_36 ( V_14 , V_92 ) == - V_130 ) {
F_13 ( L_22
L_23 , V_92 ) ;
V_14 -> V_114 = true ;
if ( V_6 -> V_114 )
V_6 -> V_114 ( & V_14 -> V_2 ) ;
return - V_130 ;
}
V_14 -> V_92 = V_92 ;
F_13 ( L_24 , V_92 ) ;
}
return 0 ;
}
static void F_38 ( struct V_7 * V_14 , unsigned int V_131 )
{
struct V_22 * V_107 = F_20 ( & V_14 -> V_9 ) ;
if ( V_14 -> V_92 == V_91 ) {
if ( ! V_131 )
V_131 = V_14 -> V_93 ;
F_17 ( V_107 , V_131 ) ;
} else {
if ( ! V_131 )
V_131 = V_14 -> V_94 ;
F_18 ( V_107 , V_131 ) ;
}
}
static void F_18 ( struct V_22 * V_23 , unsigned int V_131 )
{
struct V_7 * V_14 = F_3 ( F_12 ( V_23 ) ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_10 V_11 = {
. V_92 = V_14 -> V_92 ,
. V_112 = V_14 -> V_112 ,
. V_132 = V_14 -> V_132
} ;
if ( V_14 -> type == V_33 ) {
F_6 ( L_25 ) ;
return;
}
if ( NULL == V_6 -> V_87 ) {
F_6 ( L_26 ) ;
return;
}
if ( V_131 < V_133 [ 0 ] * 16 || V_131 > V_133 [ 1 ] * 16 ) {
F_13 ( L_27 ,
V_131 / 16 , V_131 % 16 * 100 / 16 , V_133 [ 0 ] ,
V_133 [ 1 ] ) ;
if ( V_131 < V_133 [ 0 ] * 16 )
V_131 = V_133 [ 0 ] * 16 ;
else
V_131 = V_133 [ 1 ] * 16 ;
}
V_11 . V_134 = V_131 ;
F_13 ( L_28 ,
V_131 / 16 , V_131 % 16 * 100 / 16 ) ;
V_14 -> V_94 = V_131 ;
V_14 -> V_114 = false ;
V_6 -> V_87 ( & V_14 -> V_2 , & V_11 ) ;
}
static T_2 F_39 ( struct V_7 * V_14 , T_2 V_132 )
{
if ( V_135 [ 0 ] != '-' && ( V_132 & V_136 ) == V_136 ) {
switch ( V_135 [ 0 ] ) {
case '6' :
return V_137 ;
case 'b' :
case 'B' :
case 'g' :
case 'G' :
return V_138 ;
case 'i' :
case 'I' :
return V_139 ;
case 'd' :
case 'D' :
case 'k' :
case 'K' :
return V_140 ;
case 'M' :
case 'm' :
return V_141 ;
case 'N' :
case 'n' :
if ( V_135 [ 1 ] == 'c' || V_135 [ 1 ] == 'C' )
return V_142 ;
return V_143 ;
default:
F_6 ( L_29 ) ;
break;
}
}
if ( V_144 [ 0 ] != '-' && ( V_132 & V_145 ) == V_145 ) {
switch ( V_144 [ 0 ] ) {
case 'b' :
case 'B' :
case 'g' :
case 'G' :
case 'h' :
case 'H' :
return V_146 |
V_147 |
V_148 ;
case 'd' :
case 'D' :
case 'k' :
case 'K' :
return V_149 ;
case 'l' :
case 'L' :
if ( ( V_144 [ 1 ] == 'C' ) || ( V_144 [ 1 ] == 'c' ) )
return V_150 ;
return V_151 ;
default:
F_6 ( L_30 ) ;
break;
}
}
if ( V_152 [ 0 ] != '-' && ( V_132 & V_153 ) == V_153 ) {
switch ( V_152 [ 0 ] ) {
case 'm' :
case 'M' :
return V_154 ;
case 'j' :
case 'J' :
return V_155 ;
case 'k' :
case 'K' :
return V_156 ;
default:
F_28 ( L_31 ) ;
break;
}
}
return V_132 ;
}
static void F_17 ( struct V_22 * V_23 , unsigned int V_131 )
{
struct V_7 * V_14 = F_3 ( F_12 ( V_23 ) ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_10 V_11 = {
. V_92 = V_14 -> V_92 ,
. V_112 = V_14 -> V_112 ,
. V_132 = V_14 -> V_132
} ;
if ( V_14 -> type == V_33 ) {
F_6 ( L_25 ) ;
return;
}
if ( NULL == V_6 -> V_87 ) {
F_6 ( L_32 ) ;
return;
}
if ( V_131 < V_157 [ 0 ] * 16000 || V_131 > V_157 [ 1 ] * 16000 ) {
F_13 ( L_33 ,
V_131 / 16000 , V_131 % 16000 * 100 / 16000 ,
V_157 [ 0 ] , V_157 [ 1 ] ) ;
if ( V_131 < V_157 [ 0 ] * 16000 )
V_131 = V_157 [ 0 ] * 16000 ;
else
V_131 = V_157 [ 1 ] * 16000 ;
}
V_11 . V_134 = V_131 ;
F_13 ( L_34 ,
V_131 / 16000 , V_131 % 16000 * 100 / 16000 ) ;
V_14 -> V_93 = V_131 ;
V_14 -> V_114 = false ;
V_6 -> V_87 ( & V_14 -> V_2 , & V_11 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_7 * V_14 = V_2 -> V_15 ;
unsigned long V_131 , V_158 ;
struct V_12 * V_13 = & V_2 -> V_3 . V_4 ;
struct V_30 * V_6 = & V_2 -> V_3 . V_6 ;
const char * V_159 ;
switch ( V_14 -> V_92 ) {
case V_91 :
V_159 = L_35 ;
break;
case V_160 :
V_159 = L_36 ;
break;
case V_125 :
default:
V_159 = L_37 ;
break;
}
if ( V_14 -> V_92 == V_91 ) {
V_131 = V_14 -> V_93 / 16000 ;
V_158 = ( V_14 -> V_93 % 16000 ) * 100 / 16000 ;
} else {
V_131 = V_14 -> V_94 / 16 ;
V_158 = ( V_14 -> V_94 % 16 ) * 100 / 16 ;
}
F_28 ( L_38 , V_159 ,
V_14 -> V_114 ? L_39 : L_20 ) ;
F_28 ( L_40 , V_131 , V_158 ) ;
F_28 ( L_41 , ( unsigned long ) V_14 -> V_132 ) ;
if ( V_14 -> V_92 != V_91 )
return;
if ( V_13 -> V_161 ) {
T_3 F_40 ;
V_13 -> V_161 ( & V_14 -> V_2 , & F_40 ) ;
if ( F_40 & V_162 )
F_28 ( L_42 ) ;
if ( F_40 & V_163 )
F_28 ( L_43 ) ;
}
if ( V_6 -> V_164 )
F_28 ( L_44 ,
V_6 -> V_164 ( V_2 ) ) ;
}
static int F_41 ( struct V_8 * V_9 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_37 ( V_14 , V_91 ) == 0 )
F_38 ( V_14 , 0 ) ;
return 0 ;
}
static int F_42 ( struct V_8 * V_9 , int V_165 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_165 ) {
if ( V_14 -> V_114 && F_37 ( V_14 , V_14 -> V_92 ) == 0 ) {
F_13 ( L_45 ) ;
F_38 ( V_14 , 0 ) ;
}
return 0 ;
}
F_13 ( L_23 ) ;
V_14 -> V_114 = true ;
if ( V_6 -> V_114 )
V_6 -> V_114 ( & V_14 -> V_2 ) ;
return 0 ;
}
static int F_43 ( struct V_8 * V_9 , T_2 V_132 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_37 ( V_14 , V_125 ) )
return 0 ;
V_14 -> V_132 = F_39 ( V_14 , V_132 ) ;
if ( V_14 -> V_132 != V_132 )
F_13 ( L_46 , V_132 , V_14 -> V_132 ) ;
F_38 ( V_14 , 0 ) ;
return 0 ;
}
static int F_44 ( struct V_8 * V_9 , struct V_166 * V_167 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_37 ( V_14 , V_167 -> type ) == 0 )
F_38 ( V_14 , V_167 -> V_134 ) ;
return 0 ;
}
static int F_45 ( struct V_8 * V_9 , struct V_166 * V_167 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_12 * V_13 = & V_14 -> V_2 . V_3 . V_4 ;
if ( F_36 ( V_14 , V_167 -> type ) == - V_130 )
return 0 ;
if ( V_167 -> type == V_14 -> V_92 && V_13 -> V_168 && ! V_14 -> V_114 ) {
T_3 V_169 ;
V_13 -> V_168 ( & V_14 -> V_2 , & V_169 ) ;
V_167 -> V_134 = ( V_91 == V_14 -> V_92 ) ?
F_46 ( V_169 * 2 , 125 ) :
F_46 ( V_169 , 62500 ) ;
} else {
V_167 -> V_134 = ( V_91 == V_167 -> type ) ?
V_14 -> V_93 : V_14 -> V_94 ;
}
return 0 ;
}
static int F_47 ( struct V_8 * V_9 , struct V_170 * V_171 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_12 * V_13 = & V_14 -> V_2 . V_3 . V_4 ;
if ( F_36 ( V_14 , V_171 -> type ) == - V_130 )
return 0 ;
if ( V_171 -> type == V_14 -> V_92 && V_6 -> V_172 )
V_171 -> V_173 = V_6 -> V_172 ( & V_14 -> V_2 ) ;
if ( V_14 -> V_92 != V_91 ) {
V_171 -> V_174 |= V_175 ;
V_171 -> V_176 = V_133 [ 0 ] * 16 ;
V_171 -> V_177 = V_133 [ 1 ] * 16 ;
return 0 ;
}
if ( V_171 -> type == V_14 -> V_92 ) {
V_171 -> V_178 = V_179 | V_180 ;
if ( V_13 -> V_161 ) {
T_3 F_40 ;
V_13 -> V_161 ( & V_14 -> V_2 , & F_40 ) ;
V_171 -> V_178 =
( F_40 & V_163 ) ?
V_180 :
V_179 ;
}
if ( V_6 -> V_164 )
V_171 -> signal = V_6 -> V_164 ( & V_14 -> V_2 ) ;
V_171 -> V_112 = V_14 -> V_112 ;
}
V_171 -> V_174 |= V_181 | V_182 ;
V_171 -> V_176 = V_157 [ 0 ] * 16000 ;
V_171 -> V_177 = V_157 [ 1 ] * 16000 ;
return 0 ;
}
static int F_48 ( struct V_8 * V_9 , struct V_170 * V_171 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_37 ( V_14 , V_171 -> type ) )
return 0 ;
if ( V_14 -> V_92 == V_91 )
V_14 -> V_112 = V_171 -> V_112 ;
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
static int F_50 ( struct V_22 * V_23 , T_4 V_183 )
{
struct V_7 * V_14 = F_3 ( F_12 ( V_23 ) ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
F_13 ( L_47 ) ;
if ( ! V_14 -> V_114 && V_6 -> V_114 )
V_6 -> V_114 ( & V_14 -> V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_22 * V_23 )
{
struct V_7 * V_14 = F_3 ( F_12 ( V_23 ) ) ;
F_13 ( L_48 ) ;
if ( ! V_14 -> V_114 )
if ( F_37 ( V_14 , V_14 -> V_92 ) == 0 )
F_38 ( V_14 , 0 ) ;
return 0 ;
}
static int F_52 ( struct V_22 * V_107 , unsigned V_28 , void * V_29 )
{
struct V_8 * V_9 = F_12 ( V_107 ) ;
switch ( V_28 ) {
case V_184 :
return F_21 ( V_9 , V_29 ) ;
}
return - V_185 ;
}
