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
static int F_9 ( struct V_1 * V_2 )
{
T_2 V_20 = 0 ;
if ( V_2 -> V_3 . V_4 . V_21 )
V_2 -> V_3 . V_4 . V_21 ( V_2 , & V_20 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , void * V_22 )
{
struct V_12 * V_13 = & V_2 -> V_3 . V_4 ;
struct V_7 * V_14 = V_2 -> V_15 ;
if ( V_13 -> V_23 )
return V_13 -> V_23 ( V_2 , V_22 ) ;
F_6 ( L_2 ) ;
return 0 ;
}
static void F_11 ( struct V_24 * V_25 , unsigned int type ,
unsigned int V_26 , unsigned int V_27 ,
int (* F_12) ( void * V_28 , int V_29 , int V_30 , int V_31 ) )
{
struct V_7 * V_14 = F_3 ( F_13 ( V_25 ) ) ;
struct V_12 * V_13 = & V_14 -> V_2 . V_3 . V_4 ;
struct V_32 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
unsigned char V_33 [ 4 ] ;
int V_34 = 1 ;
if ( type == V_35 || type == V_36 ) {
F_14 ( L_3 , V_25 -> V_37 ) ;
return;
}
V_14 -> type = type ;
V_14 -> V_38 = V_27 < 256 ? V_27 : 0 ;
if ( F_12 != NULL ) {
F_14 ( L_4 ) ;
V_14 -> V_2 . V_39 = F_12 ;
}
F_1 ( & V_14 -> V_2 ) ;
V_14 -> V_2 . V_15 = NULL ;
switch ( V_14 -> type ) {
case V_40 :
if ( ! F_15 ( V_41 ,
& V_14 -> V_2 , V_14 -> V_42 -> V_43 , V_14 -> V_42 -> V_37 ) )
goto V_44;
break;
case V_45 :
{
struct V_46 V_47 = {
. V_48 = V_14 -> V_38 ,
} ;
if ( ! F_15 ( V_49 , & V_14 -> V_2 , V_14 -> V_42 -> V_43 ,
V_14 -> V_42 -> V_37 , & V_47 ) )
goto V_44;
break;
}
case V_50 :
if ( ! F_15 ( V_51 , & V_14 -> V_2 ,
V_14 -> V_42 -> V_43 , V_14 -> V_42 -> V_37 ) )
goto V_44;
V_14 -> V_52 = V_53 ;
break;
case V_54 :
if ( ! F_15 ( V_55 , & V_14 -> V_2 ,
V_14 -> V_42 -> V_43 , V_14 -> V_42 -> V_37 ) )
goto V_44;
V_14 -> V_52 = V_53 ;
break;
case V_56 :
case V_57 :
V_33 [ 0 ] = 0x0b ;
V_33 [ 1 ] = 0xdc ;
V_33 [ 2 ] = 0x9c ;
V_33 [ 3 ] = 0x60 ;
F_16 ( V_25 , V_33 , 4 ) ;
F_17 ( 1 ) ;
V_33 [ 2 ] = 0x86 ;
V_33 [ 3 ] = 0x54 ;
F_16 ( V_25 , V_33 , 4 ) ;
if ( ! F_15 ( V_58 , & V_14 -> V_2 ,
V_14 -> V_42 -> V_43 , V_14 -> V_42 -> V_37 , V_14 -> type ) )
goto V_44;
break;
case V_59 :
V_33 [ 0 ] = 0x0b ;
V_33 [ 1 ] = 0xdc ;
V_33 [ 2 ] = 0x86 ;
V_33 [ 3 ] = 0xa4 ;
F_16 ( V_25 , V_33 , 4 ) ;
if ( ! F_15 ( V_58 , & V_14 -> V_2 ,
V_14 -> V_42 -> V_43 , V_14 -> V_42 -> V_37 , V_14 -> type ) )
goto V_44;
break;
case V_60 :
{
struct V_61 V_47 = {
. V_62 = V_14 -> V_42 -> V_43 ,
. V_63 = V_14 -> V_42 -> V_37 ,
} ;
if ( ! F_15 ( V_64 , & V_14 -> V_2 , & V_47 ) )
goto V_44;
V_34 = 0 ;
break;
}
case V_65 :
if ( ! F_15 ( V_66 ,
& V_14 -> V_2 , V_14 -> V_42 -> V_43 , V_14 -> V_42 -> V_37 ) )
goto V_44;
break;
case V_67 :
{
struct V_68 V_69 = {
. V_70 = V_14 -> V_42 -> V_37 ,
. V_71 = 0 ,
} ;
if ( ! F_15 ( V_72 ,
& V_14 -> V_2 , V_14 -> V_42 -> V_43 , & V_69 ) )
goto V_44;
V_34 = 0 ;
break;
}
case V_73 :
{
struct V_68 V_74 = {
. V_70 = V_14 -> V_42 -> V_37 ,
. V_71 = 0 ,
. V_75 = V_76 ,
} ;
if ( ! F_15 ( V_72 ,
& V_14 -> V_2 , V_14 -> V_42 -> V_43 , & V_74 ) )
goto V_44;
V_34 = 0 ;
break;
}
case V_77 :
{
struct V_78 V_47 = {
. V_38 = V_14 -> V_38 ,
. V_79 = V_80 ,
} ;
if ( ! F_15 ( V_81 , & V_14 -> V_2 , V_14 -> V_42 -> V_37 ,
V_14 -> V_42 -> V_43 , & V_47 ) )
goto V_44;
V_34 = 0 ;
break;
}
case V_82 :
{
struct V_83 V_84 = {
. V_70 = V_14 -> V_42 -> V_37 ,
. V_85 = 0 ,
. V_86 = 0 ,
. V_87 = 0 ,
. V_71 = 0
} ;
if ( ! F_15 ( V_88 ,
& V_14 -> V_2 , V_14 -> V_42 -> V_43 , & V_84 ) )
goto V_44;
V_34 = 0 ;
break;
}
default:
if ( ! F_15 ( V_58 , & V_14 -> V_2 ,
V_14 -> V_42 -> V_43 , V_14 -> V_42 -> V_37 , V_14 -> type ) )
goto V_44;
break;
}
if ( ( NULL == V_6 -> V_89 ) &&
( V_13 -> V_16 ) ) {
V_14 -> V_90 = V_13 -> V_91 . V_90 ;
V_14 -> V_2 . V_15 = V_14 ;
memcpy ( V_6 , & V_92 ,
sizeof( struct V_32 ) ) ;
} else {
V_14 -> V_90 = V_6 -> V_91 . V_90 ;
}
F_14 ( L_5 , V_14 -> V_90 ) ;
V_14 -> V_52 = V_26 ;
if ( V_34 ) {
if ( V_93 == V_14 -> V_94 )
F_18 ( V_25 , V_14 -> V_95 ) ;
else
F_19 ( V_25 , V_14 -> V_96 ) ;
}
F_14 ( L_6 ,
V_25 -> V_43 -> V_90 , V_25 -> V_97 -> V_97 . V_90 , V_25 -> V_37 << 1 , type ,
V_14 -> V_52 ) ;
return;
V_44:
F_14 ( L_7 , V_14 -> type ) ;
V_14 -> type = V_36 ;
return;
}
static int F_20 ( struct V_8 * V_9 ,
struct V_98 * V_99 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_24 * V_25 = F_21 ( V_9 ) ;
F_14 ( L_8 ,
V_99 -> type ,
V_99 -> V_37 ,
V_99 -> V_52 ,
V_99 -> V_38 ) ;
if ( ( V_14 -> type == V_35 && ( ( V_99 -> V_37 == V_100 ) &&
( V_14 -> V_52 & V_99 -> V_52 ) ) ) ||
( V_99 -> V_37 == V_25 -> V_37 ) ) {
F_11 ( V_25 , V_99 -> type , V_99 -> V_52 ,
V_99 -> V_38 , V_99 -> F_12 ) ;
} else
F_14 ( L_9
L_10 ,
V_14 -> type , V_14 -> V_52 ,
V_99 -> V_37 , V_99 -> V_52 ) ;
return 0 ;
}
static int F_22 ( struct V_8 * V_9 ,
const struct V_101 * V_47 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_32 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_14 -> type != V_47 -> V_7 )
return 0 ;
if ( V_6 -> V_23 ) {
V_6 -> V_23 ( & V_14 -> V_2 , V_47 -> V_102 ) ;
return 0 ;
}
F_14 ( L_2 ) ;
return 0 ;
}
static void F_23 ( struct V_103 * V_104 ,
struct V_7 * * V_105 , struct V_7 * * V_106 )
{
struct V_7 * V_107 ;
* V_105 = NULL ;
* V_106 = NULL ;
F_24 (pos, &tuner_list, list) {
int V_52 ;
if ( V_107 -> V_42 -> V_43 != V_104 ||
strcmp ( V_107 -> V_42 -> V_97 -> V_97 . V_90 , L_11 ) )
continue;
V_52 = V_107 -> V_52 ;
if ( * V_105 == NULL && V_52 == V_53 )
* V_105 = V_107 ;
else if ( * V_106 == NULL && V_107 -> type != V_65 &&
( V_107 -> V_52 & V_108 ) )
* V_106 = V_107 ;
}
}
static int F_25 ( struct V_24 * V_109 ,
const struct V_110 * V_111 )
{
struct V_7 * V_14 ;
struct V_7 * V_105 ;
struct V_7 * V_106 ;
V_14 = F_26 ( sizeof( struct V_7 ) , V_112 ) ;
if ( NULL == V_14 )
return - V_113 ;
F_27 ( & V_14 -> V_9 , V_109 , & V_4 ) ;
V_14 -> V_42 = V_109 ;
V_14 -> V_90 = L_12 ;
V_14 -> type = V_35 ;
V_14 -> V_114 = V_115 ;
V_14 -> V_116 = 1 ;
V_14 -> V_95 = 87.5 * 16000 ;
V_14 -> V_96 = 400 * 16 ;
if ( V_117 ) {
unsigned char V_33 [ 16 ] ;
int V_118 , V_119 ;
memset ( V_33 , 0 , sizeof( V_33 ) ) ;
V_119 = F_28 ( V_109 , V_33 , sizeof( V_33 ) ) ;
F_29 ( L_13 ) ;
for ( V_118 = 0 ; V_118 < V_119 ; V_118 ++ )
F_30 ( V_120 L_14 , V_33 [ V_118 ] ) ;
F_30 ( L_15 ) ;
}
if ( ! V_121 ) {
switch ( V_109 -> V_37 ) {
case 0x10 :
if ( F_31 ( V_122 ,
V_14 -> V_42 -> V_43 ,
V_14 -> V_42 -> V_37 ) >= 0 ) {
V_14 -> type = V_54 ;
V_14 -> V_52 = V_53 ;
F_23 ( V_14 -> V_42 -> V_43 , & V_105 , & V_106 ) ;
if ( V_106 )
V_106 -> V_52 &= ~ V_53 ;
goto V_123;
}
F_32 ( V_14 ) ;
return - V_124 ;
case 0x42 :
case 0x43 :
case 0x4a :
case 0x4b :
if ( F_31 ( V_125 , V_14 -> V_42 -> V_43 ,
V_14 -> V_42 -> V_37 ) >= 0 ) {
F_14 ( L_16 ) ;
} else {
V_14 -> type = V_65 ;
V_14 -> V_52 = V_53 | V_108 ;
goto V_123;
}
break;
case 0x60 :
if ( F_31 ( V_126 ,
V_14 -> V_42 -> V_43 , V_14 -> V_42 -> V_37 )
>= 0 ) {
V_14 -> type = V_50 ;
V_14 -> V_52 = V_53 ;
F_23 ( V_14 -> V_42 -> V_43 , & V_105 , & V_106 ) ;
if ( V_106 )
V_106 -> V_52 &= ~ V_53 ;
goto V_123;
}
break;
}
}
F_23 ( V_14 -> V_42 -> V_43 , & V_105 , & V_106 ) ;
if ( V_106 == NULL ) {
V_14 -> V_52 = V_108 ;
if ( V_105 == NULL )
V_14 -> V_52 |= V_53 ;
F_14 ( L_17 , V_14 -> V_52 ) ;
}
V_123:
if ( V_14 -> V_52 & V_108 )
V_14 -> V_94 = V_127 ;
else
V_14 -> V_94 = V_93 ;
F_11 ( V_109 , V_14 -> type , V_14 -> V_52 , V_14 -> V_38 , V_14 -> V_2 . V_39 ) ;
F_33 ( & V_14 -> V_128 , & V_129 ) ;
F_29 ( L_18 ,
V_14 -> type ,
V_14 -> V_52 & V_53 ? L_19 : L_20 ,
V_14 -> V_52 & V_108 ? L_21 : L_20 ) ;
return 0 ;
}
static int F_34 ( struct V_24 * V_109 )
{
struct V_7 * V_14 = F_3 ( F_13 ( V_109 ) ) ;
F_35 ( & V_14 -> V_9 ) ;
F_1 ( & V_14 -> V_2 ) ;
V_14 -> V_2 . V_15 = NULL ;
F_36 ( & V_14 -> V_128 ) ;
F_32 ( V_14 ) ;
return 0 ;
}
static inline int F_37 ( struct V_7 * V_14 , enum V_130 V_94 )
{
int V_131 ;
if ( V_94 == V_93 )
V_131 = V_53 ;
else
V_131 = V_108 ;
if ( ( V_131 & V_14 -> V_52 ) == 0 )
return - V_132 ;
return 0 ;
}
static int F_38 ( struct V_7 * V_14 , enum V_130 V_94 )
{
struct V_32 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_94 != V_14 -> V_94 ) {
if ( F_37 ( V_14 , V_94 ) == - V_132 ) {
F_14 ( L_22
L_23 , V_94 ) ;
V_14 -> V_116 = true ;
if ( V_6 -> V_116 )
V_6 -> V_116 ( & V_14 -> V_2 ) ;
return - V_132 ;
}
V_14 -> V_94 = V_94 ;
F_14 ( L_24 , V_94 ) ;
}
return 0 ;
}
static void F_39 ( struct V_7 * V_14 , unsigned int V_133 )
{
struct V_24 * V_109 = F_21 ( & V_14 -> V_9 ) ;
if ( V_14 -> V_94 == V_93 ) {
if ( ! V_133 )
V_133 = V_14 -> V_95 ;
F_18 ( V_109 , V_133 ) ;
} else {
if ( ! V_133 )
V_133 = V_14 -> V_96 ;
F_19 ( V_109 , V_133 ) ;
}
}
static void F_19 ( struct V_24 * V_25 , unsigned int V_133 )
{
struct V_7 * V_14 = F_3 ( F_13 ( V_25 ) ) ;
struct V_32 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_10 V_11 = {
. V_94 = V_14 -> V_94 ,
. V_114 = V_14 -> V_114 ,
. V_134 = V_14 -> V_134
} ;
if ( V_14 -> type == V_35 ) {
F_6 ( L_25 ) ;
return;
}
if ( NULL == V_6 -> V_89 ) {
F_6 ( L_26 ) ;
return;
}
if ( V_133 < V_135 [ 0 ] * 16 || V_133 > V_135 [ 1 ] * 16 ) {
F_14 ( L_27 ,
V_133 / 16 , V_133 % 16 * 100 / 16 , V_135 [ 0 ] ,
V_135 [ 1 ] ) ;
if ( V_133 < V_135 [ 0 ] * 16 )
V_133 = V_135 [ 0 ] * 16 ;
else
V_133 = V_135 [ 1 ] * 16 ;
}
V_11 . V_136 = V_133 ;
F_14 ( L_28 ,
V_133 / 16 , V_133 % 16 * 100 / 16 ) ;
V_14 -> V_96 = V_133 ;
V_14 -> V_116 = false ;
V_6 -> V_89 ( & V_14 -> V_2 , & V_11 ) ;
}
static T_3 F_40 ( struct V_7 * V_14 , T_3 V_134 )
{
if ( V_137 [ 0 ] != '-' && ( V_134 & V_138 ) == V_138 ) {
switch ( V_137 [ 0 ] ) {
case '6' :
return V_139 ;
case 'b' :
case 'B' :
case 'g' :
case 'G' :
return V_140 ;
case 'i' :
case 'I' :
return V_141 ;
case 'd' :
case 'D' :
case 'k' :
case 'K' :
return V_142 ;
case 'M' :
case 'm' :
return V_143 ;
case 'N' :
case 'n' :
if ( V_137 [ 1 ] == 'c' || V_137 [ 1 ] == 'C' )
return V_144 ;
return V_145 ;
default:
F_6 ( L_29 ) ;
break;
}
}
if ( V_146 [ 0 ] != '-' && ( V_134 & V_147 ) == V_147 ) {
switch ( V_146 [ 0 ] ) {
case 'b' :
case 'B' :
case 'g' :
case 'G' :
case 'h' :
case 'H' :
return V_148 |
V_149 |
V_150 ;
case 'd' :
case 'D' :
case 'k' :
case 'K' :
return V_151 ;
case 'l' :
case 'L' :
if ( ( V_146 [ 1 ] == 'C' ) || ( V_146 [ 1 ] == 'c' ) )
return V_152 ;
return V_153 ;
default:
F_6 ( L_30 ) ;
break;
}
}
if ( V_154 [ 0 ] != '-' && ( V_134 & V_155 ) == V_155 ) {
switch ( V_154 [ 0 ] ) {
case 'm' :
case 'M' :
return V_156 ;
case 'j' :
case 'J' :
return V_157 ;
case 'k' :
case 'K' :
return V_158 ;
default:
F_29 ( L_31 ) ;
break;
}
}
return V_134 ;
}
static void F_18 ( struct V_24 * V_25 , unsigned int V_133 )
{
struct V_7 * V_14 = F_3 ( F_13 ( V_25 ) ) ;
struct V_32 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_10 V_11 = {
. V_94 = V_14 -> V_94 ,
. V_114 = V_14 -> V_114 ,
. V_134 = V_14 -> V_134
} ;
if ( V_14 -> type == V_35 ) {
F_6 ( L_25 ) ;
return;
}
if ( NULL == V_6 -> V_89 ) {
F_6 ( L_32 ) ;
return;
}
if ( V_133 < V_159 [ 0 ] * 16000 || V_133 > V_159 [ 1 ] * 16000 ) {
F_14 ( L_33 ,
V_133 / 16000 , V_133 % 16000 * 100 / 16000 ,
V_159 [ 0 ] , V_159 [ 1 ] ) ;
if ( V_133 < V_159 [ 0 ] * 16000 )
V_133 = V_159 [ 0 ] * 16000 ;
else
V_133 = V_159 [ 1 ] * 16000 ;
}
V_11 . V_136 = V_133 ;
F_14 ( L_34 ,
V_133 / 16000 , V_133 % 16000 * 100 / 16000 ) ;
V_14 -> V_95 = V_133 ;
V_14 -> V_116 = false ;
V_6 -> V_89 ( & V_14 -> V_2 , & V_11 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_7 * V_14 = V_2 -> V_15 ;
unsigned long V_133 , V_160 ;
struct V_12 * V_13 = & V_2 -> V_3 . V_4 ;
struct V_32 * V_6 = & V_2 -> V_3 . V_6 ;
const char * V_161 ;
switch ( V_14 -> V_94 ) {
case V_93 :
V_161 = L_35 ;
break;
case V_162 :
V_161 = L_36 ;
break;
case V_127 :
default:
V_161 = L_37 ;
break;
}
if ( V_14 -> V_94 == V_93 ) {
V_133 = V_14 -> V_95 / 16000 ;
V_160 = ( V_14 -> V_95 % 16000 ) * 100 / 16000 ;
} else {
V_133 = V_14 -> V_96 / 16 ;
V_160 = ( V_14 -> V_96 % 16 ) * 100 / 16 ;
}
F_29 ( L_38 , V_161 ,
V_14 -> V_116 ? L_39 : L_20 ) ;
F_29 ( L_40 , V_133 , V_160 ) ;
F_29 ( L_41 , ( unsigned long ) V_14 -> V_134 ) ;
if ( V_14 -> V_94 != V_93 )
return;
if ( V_13 -> V_163 ) {
T_4 F_41 ;
V_13 -> V_163 ( & V_14 -> V_2 , & F_41 ) ;
if ( F_41 & V_164 )
F_29 ( L_42 ) ;
if ( F_41 & V_165 )
F_29 ( L_43 ) ;
}
if ( V_6 -> V_166 )
F_29 ( L_44 ,
V_6 -> V_166 ( V_2 ) ) ;
}
static int F_42 ( struct V_8 * V_9 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_38 ( V_14 , V_93 ) == 0 )
F_39 ( V_14 , 0 ) ;
return 0 ;
}
static int F_43 ( struct V_8 * V_9 , int V_167 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_32 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_167 ) {
if ( V_14 -> V_116 && F_38 ( V_14 , V_14 -> V_94 ) == 0 ) {
F_14 ( L_45 ) ;
F_39 ( V_14 , 0 ) ;
}
return 0 ;
}
F_14 ( L_23 ) ;
V_14 -> V_116 = true ;
if ( V_6 -> V_116 )
V_6 -> V_116 ( & V_14 -> V_2 ) ;
return 0 ;
}
static int F_44 ( struct V_8 * V_9 , T_3 V_134 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_38 ( V_14 , V_127 ) )
return 0 ;
V_14 -> V_134 = F_40 ( V_14 , V_134 ) ;
if ( V_14 -> V_134 != V_134 )
F_14 ( L_46 , V_134 , V_14 -> V_134 ) ;
F_39 ( V_14 , 0 ) ;
return 0 ;
}
static int F_45 ( struct V_8 * V_9 , struct V_168 * V_169 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_38 ( V_14 , V_169 -> type ) == 0 )
F_39 ( V_14 , V_169 -> V_136 ) ;
return 0 ;
}
static int F_46 ( struct V_8 * V_9 , struct V_168 * V_169 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_12 * V_13 = & V_14 -> V_2 . V_3 . V_4 ;
if ( F_37 ( V_14 , V_169 -> type ) == - V_132 )
return 0 ;
if ( V_169 -> type == V_14 -> V_94 && V_13 -> V_170 && ! V_14 -> V_116 ) {
T_4 V_171 ;
V_13 -> V_170 ( & V_14 -> V_2 , & V_171 ) ;
V_169 -> V_136 = ( V_93 == V_14 -> V_94 ) ?
F_47 ( V_171 * 2 , 125 ) :
F_47 ( V_171 , 62500 ) ;
} else {
V_169 -> V_136 = ( V_93 == V_169 -> type ) ?
V_14 -> V_95 : V_14 -> V_96 ;
}
return 0 ;
}
static int F_48 ( struct V_8 * V_9 , struct V_172 * V_173 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_32 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_12 * V_13 = & V_14 -> V_2 . V_3 . V_4 ;
if ( F_37 ( V_14 , V_173 -> type ) == - V_132 )
return 0 ;
if ( V_173 -> type == V_14 -> V_94 && V_6 -> V_21 )
V_173 -> V_20 = V_6 -> V_21 ( & V_14 -> V_2 ) ;
if ( V_6 -> V_166 )
V_173 -> signal = V_6 -> V_166 ( & V_14 -> V_2 ) ;
if ( V_173 -> type != V_93 ) {
V_173 -> V_174 |= V_175 ;
V_173 -> V_176 = V_135 [ 0 ] * 16 ;
V_173 -> V_177 = V_135 [ 1 ] * 16 ;
return 0 ;
}
if ( V_173 -> type == V_14 -> V_94 ) {
V_173 -> V_178 = V_179 | V_180 ;
if ( V_13 -> V_163 ) {
T_4 F_41 ;
V_13 -> V_163 ( & V_14 -> V_2 , & F_41 ) ;
V_173 -> V_178 =
( F_41 & V_165 ) ?
V_180 :
V_179 ;
}
V_173 -> V_114 = V_14 -> V_114 ;
}
V_173 -> V_174 |= V_181 | V_182 ;
V_173 -> V_176 = V_159 [ 0 ] * 16000 ;
V_173 -> V_177 = V_159 [ 1 ] * 16000 ;
return 0 ;
}
static int F_49 ( struct V_8 * V_9 , struct V_172 * V_173 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_38 ( V_14 , V_173 -> type ) )
return 0 ;
if ( V_14 -> V_94 == V_93 )
V_14 -> V_114 = V_173 -> V_114 ;
F_39 ( V_14 , 0 ) ;
return 0 ;
}
static int F_50 ( struct V_8 * V_9 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_32 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_6 -> F_41 )
V_6 -> F_41 ( & V_14 -> V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_183 * V_28 )
{
struct V_24 * V_25 = F_52 ( V_28 ) ;
struct V_7 * V_14 = F_3 ( F_13 ( V_25 ) ) ;
struct V_32 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
F_14 ( L_47 ) ;
if ( ! V_14 -> V_116 && V_6 -> V_116 )
V_6 -> V_116 ( & V_14 -> V_2 ) ;
return 0 ;
}
static int F_53 ( struct V_183 * V_28 )
{
struct V_24 * V_25 = F_52 ( V_28 ) ;
struct V_7 * V_14 = F_3 ( F_13 ( V_25 ) ) ;
F_14 ( L_48 ) ;
if ( ! V_14 -> V_116 )
if ( F_38 ( V_14 , V_14 -> V_94 ) == 0 )
F_39 ( V_14 , 0 ) ;
return 0 ;
}
static int F_54 ( struct V_24 * V_109 , unsigned V_30 , void * V_31 )
{
struct V_8 * V_9 = F_13 ( V_109 ) ;
switch ( V_30 ) {
case V_184 :
return F_22 ( V_9 , V_31 ) ;
}
return - V_185 ;
}
