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
V_31 [ 0 ] = 0x0b ;
V_31 [ 1 ] = 0xdc ;
V_31 [ 2 ] = 0x9c ;
V_31 [ 3 ] = 0x60 ;
F_15 ( V_23 , V_31 , 4 ) ;
F_16 ( 1 ) ;
V_31 [ 2 ] = 0x86 ;
V_31 [ 3 ] = 0x54 ;
F_15 ( V_23 , V_31 , 4 ) ;
if ( ! F_14 ( V_55 , & V_14 -> V_2 ,
V_14 -> V_40 -> V_41 , V_14 -> V_40 -> V_35 , V_14 -> type ) )
goto V_42;
break;
case V_56 :
V_31 [ 0 ] = 0x0b ;
V_31 [ 1 ] = 0xdc ;
V_31 [ 2 ] = 0x86 ;
V_31 [ 3 ] = 0xa4 ;
F_15 ( V_23 , V_31 , 4 ) ;
if ( ! F_14 ( V_55 , & V_14 -> V_2 ,
V_14 -> V_40 -> V_41 , V_14 -> V_40 -> V_35 , V_14 -> type ) )
goto V_42;
break;
case V_57 :
{
struct V_58 V_45 = {
. V_59 = V_14 -> V_40 -> V_41 ,
. V_60 = V_14 -> V_40 -> V_35 ,
} ;
if ( ! F_14 ( V_61 , & V_14 -> V_2 , & V_45 ) )
goto V_42;
V_32 = 0 ;
break;
}
case V_62 :
if ( ! F_14 ( V_63 ,
& V_14 -> V_2 , V_14 -> V_40 -> V_41 , V_14 -> V_40 -> V_35 ) )
goto V_42;
break;
case V_64 :
{
struct V_65 V_66 = {
. V_67 = V_14 -> V_40 -> V_35 ,
. V_68 = 0 ,
} ;
if ( ! F_14 ( V_69 ,
& V_14 -> V_2 , V_14 -> V_40 -> V_41 , & V_66 ) )
goto V_42;
V_32 = 0 ;
break;
}
case V_70 :
{
struct V_71 V_45 = {
. V_36 = V_14 -> V_36 ,
. V_72 = V_73 ,
} ;
if ( ! F_14 ( V_74 , & V_14 -> V_2 , V_14 -> V_40 -> V_35 ,
V_14 -> V_40 -> V_41 , & V_45 ) )
goto V_42;
V_32 = 0 ;
break;
}
case V_75 :
{
struct V_76 V_77 = {
. V_67 = V_14 -> V_40 -> V_35 ,
. V_78 = 0 ,
. V_79 = 0 ,
. V_80 = 0 ,
. V_68 = 0
} ;
if ( ! F_14 ( V_81 ,
& V_14 -> V_2 , V_14 -> V_40 -> V_41 , & V_77 ) )
goto V_42;
V_32 = 0 ;
break;
}
default:
if ( ! F_14 ( V_55 , & V_14 -> V_2 ,
V_14 -> V_40 -> V_41 , V_14 -> V_40 -> V_35 , V_14 -> type ) )
goto V_42;
break;
}
if ( ( NULL == V_6 -> V_82 ) &&
( V_13 -> V_16 ) ) {
V_14 -> V_83 = V_13 -> V_84 . V_83 ;
V_14 -> V_2 . V_15 = V_14 ;
memcpy ( V_6 , & V_85 ,
sizeof( struct V_30 ) ) ;
} else {
V_14 -> V_83 = V_6 -> V_84 . V_83 ;
}
F_13 ( L_5 , V_14 -> V_83 ) ;
V_14 -> V_50 = V_24 ;
if ( V_32 ) {
if ( V_86 == V_14 -> V_87 )
F_17 ( V_23 , V_14 -> V_88 ) ;
else
F_18 ( V_23 , V_14 -> V_89 ) ;
}
F_13 ( L_6 ,
V_23 -> V_41 -> V_83 , V_23 -> V_90 -> V_90 . V_83 , V_23 -> V_35 << 1 , type ,
V_14 -> V_50 ) ;
return;
V_42:
F_13 ( L_7 , V_14 -> type ) ;
V_14 -> type = V_34 ;
return;
}
static int F_19 ( struct V_8 * V_9 ,
struct V_91 * V_92 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_22 * V_23 = F_20 ( V_9 ) ;
F_13 ( L_8 ,
V_92 -> type ,
V_92 -> V_35 ,
V_92 -> V_50 ,
V_92 -> V_36 ) ;
if ( ( V_14 -> type == V_33 && ( ( V_92 -> V_35 == V_93 ) &&
( V_14 -> V_50 & V_92 -> V_50 ) ) ) ||
( V_92 -> V_35 == V_23 -> V_35 ) ) {
F_10 ( V_23 , V_92 -> type , V_92 -> V_50 ,
V_92 -> V_36 , V_92 -> F_11 ) ;
} else
F_13 ( L_9
L_10 ,
V_14 -> type , V_14 -> V_50 ,
V_92 -> V_35 , V_92 -> V_50 ) ;
return 0 ;
}
static int F_21 ( struct V_8 * V_9 ,
const struct V_94 * V_45 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_14 -> type != V_45 -> V_7 )
return 0 ;
if ( V_6 -> V_21 ) {
V_6 -> V_21 ( & V_14 -> V_2 , V_45 -> V_95 ) ;
return 0 ;
}
F_13 ( L_2 ) ;
return 0 ;
}
static void F_22 ( struct V_96 * V_97 ,
struct V_7 * * V_98 , struct V_7 * * V_99 )
{
struct V_7 * V_100 ;
* V_98 = NULL ;
* V_99 = NULL ;
F_23 (pos, &tuner_list, list) {
int V_50 ;
if ( V_100 -> V_40 -> V_41 != V_97 ||
strcmp ( V_100 -> V_40 -> V_90 -> V_90 . V_83 , L_11 ) )
continue;
V_50 = V_100 -> V_50 ;
if ( * V_98 == NULL && V_50 == V_51 )
* V_98 = V_100 ;
else if ( * V_99 == NULL && V_100 -> type != V_62 &&
( V_100 -> V_50 & V_101 ) )
* V_99 = V_100 ;
}
}
static int F_24 ( struct V_22 * V_102 ,
const struct V_103 * V_104 )
{
struct V_7 * V_14 ;
struct V_7 * V_98 ;
struct V_7 * V_99 ;
V_14 = F_25 ( sizeof( struct V_7 ) , V_105 ) ;
if ( NULL == V_14 )
return - V_106 ;
F_26 ( & V_14 -> V_9 , V_102 , & V_4 ) ;
V_14 -> V_40 = V_102 ;
V_14 -> V_83 = L_12 ;
V_14 -> type = V_33 ;
V_14 -> V_107 = V_108 ;
V_14 -> V_109 = 1 ;
V_14 -> V_88 = 87.5 * 16000 ;
V_14 -> V_89 = 400 * 16 ;
if ( V_110 ) {
unsigned char V_31 [ 16 ] ;
int V_111 , V_112 ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
V_112 = F_27 ( V_102 , V_31 , sizeof( V_31 ) ) ;
F_28 ( L_13 ) ;
for ( V_111 = 0 ; V_111 < V_112 ; V_111 ++ )
F_29 ( V_113 L_14 , V_31 [ V_111 ] ) ;
F_29 ( L_15 ) ;
}
if ( ! V_114 ) {
switch ( V_102 -> V_35 ) {
case 0x10 :
if ( F_30 ( V_115 ,
V_14 -> V_40 -> V_41 ,
V_14 -> V_40 -> V_35 ) >= 0 ) {
V_14 -> type = V_52 ;
V_14 -> V_50 = V_51 ;
F_22 ( V_14 -> V_40 -> V_41 , & V_98 , & V_99 ) ;
if ( V_99 )
V_99 -> V_50 &= ~ V_51 ;
goto V_116;
}
F_31 ( V_14 ) ;
return - V_117 ;
case 0x42 :
case 0x43 :
case 0x4a :
case 0x4b :
if ( F_30 ( V_118 , V_14 -> V_40 -> V_41 ,
V_14 -> V_40 -> V_35 ) >= 0 ) {
F_13 ( L_16 ) ;
} else {
V_14 -> type = V_62 ;
V_14 -> V_50 = V_51 | V_101 ;
goto V_116;
}
break;
case 0x60 :
if ( F_30 ( V_119 ,
V_14 -> V_40 -> V_41 , V_14 -> V_40 -> V_35 )
>= 0 ) {
V_14 -> type = V_48 ;
V_14 -> V_50 = V_51 ;
F_22 ( V_14 -> V_40 -> V_41 , & V_98 , & V_99 ) ;
if ( V_99 )
V_99 -> V_50 &= ~ V_51 ;
goto V_116;
}
break;
}
}
F_22 ( V_14 -> V_40 -> V_41 , & V_98 , & V_99 ) ;
if ( V_99 == NULL ) {
V_14 -> V_50 = V_101 ;
if ( V_98 == NULL )
V_14 -> V_50 |= V_51 ;
F_13 ( L_17 , V_14 -> V_50 ) ;
}
V_116:
if ( V_14 -> V_50 & V_101 )
V_14 -> V_87 = V_120 ;
else
V_14 -> V_87 = V_86 ;
F_10 ( V_102 , V_14 -> type , V_14 -> V_50 , V_14 -> V_36 , V_14 -> V_2 . V_37 ) ;
F_32 ( & V_14 -> V_121 , & V_122 ) ;
F_28 ( L_18 ,
V_14 -> type ,
V_14 -> V_50 & V_51 ? L_19 : L_20 ,
V_14 -> V_50 & V_101 ? L_21 : L_20 ) ;
return 0 ;
}
static int F_33 ( struct V_22 * V_102 )
{
struct V_7 * V_14 = F_3 ( F_12 ( V_102 ) ) ;
F_34 ( & V_14 -> V_9 ) ;
F_1 ( & V_14 -> V_2 ) ;
V_14 -> V_2 . V_15 = NULL ;
F_35 ( & V_14 -> V_121 ) ;
F_31 ( V_14 ) ;
return 0 ;
}
static inline int F_36 ( struct V_7 * V_14 , enum V_123 V_87 )
{
int V_124 ;
if ( V_87 == V_86 )
V_124 = V_51 ;
else
V_124 = V_101 ;
if ( ( V_124 & V_14 -> V_50 ) == 0 )
return - V_125 ;
return 0 ;
}
static int F_37 ( struct V_7 * V_14 , enum V_123 V_87 )
{
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_87 != V_14 -> V_87 ) {
if ( F_36 ( V_14 , V_87 ) == - V_125 ) {
F_13 ( L_22
L_23 , V_87 ) ;
V_14 -> V_109 = true ;
if ( V_6 -> V_109 )
V_6 -> V_109 ( & V_14 -> V_2 ) ;
return - V_125 ;
}
V_14 -> V_87 = V_87 ;
F_13 ( L_24 , V_87 ) ;
}
return 0 ;
}
static void F_38 ( struct V_7 * V_14 , unsigned int V_126 )
{
struct V_22 * V_102 = F_20 ( & V_14 -> V_9 ) ;
if ( V_14 -> V_87 == V_86 ) {
if ( ! V_126 )
V_126 = V_14 -> V_88 ;
F_17 ( V_102 , V_126 ) ;
} else {
if ( ! V_126 )
V_126 = V_14 -> V_89 ;
F_18 ( V_102 , V_126 ) ;
}
}
static void F_18 ( struct V_22 * V_23 , unsigned int V_126 )
{
struct V_7 * V_14 = F_3 ( F_12 ( V_23 ) ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_10 V_11 = {
. V_87 = V_14 -> V_87 ,
. V_107 = V_14 -> V_107 ,
. V_127 = V_14 -> V_127
} ;
if ( V_14 -> type == V_33 ) {
F_6 ( L_25 ) ;
return;
}
if ( NULL == V_6 -> V_82 ) {
F_6 ( L_26 ) ;
return;
}
if ( V_126 < V_128 [ 0 ] * 16 || V_126 > V_128 [ 1 ] * 16 ) {
F_13 ( L_27 ,
V_126 / 16 , V_126 % 16 * 100 / 16 , V_128 [ 0 ] ,
V_128 [ 1 ] ) ;
if ( V_126 < V_128 [ 0 ] * 16 )
V_126 = V_128 [ 0 ] * 16 ;
else
V_126 = V_128 [ 1 ] * 16 ;
}
V_11 . V_129 = V_126 ;
F_13 ( L_28 ,
V_126 / 16 , V_126 % 16 * 100 / 16 ) ;
V_14 -> V_89 = V_126 ;
V_14 -> V_109 = false ;
V_6 -> V_82 ( & V_14 -> V_2 , & V_11 ) ;
}
static T_2 F_39 ( struct V_7 * V_14 , T_2 V_127 )
{
if ( V_130 [ 0 ] != '-' && ( V_127 & V_131 ) == V_131 ) {
switch ( V_130 [ 0 ] ) {
case '6' :
return V_132 ;
case 'b' :
case 'B' :
case 'g' :
case 'G' :
return V_133 ;
case 'i' :
case 'I' :
return V_134 ;
case 'd' :
case 'D' :
case 'k' :
case 'K' :
return V_135 ;
case 'M' :
case 'm' :
return V_136 ;
case 'N' :
case 'n' :
if ( V_130 [ 1 ] == 'c' || V_130 [ 1 ] == 'C' )
return V_137 ;
return V_138 ;
default:
F_6 ( L_29 ) ;
break;
}
}
if ( V_139 [ 0 ] != '-' && ( V_127 & V_140 ) == V_140 ) {
switch ( V_139 [ 0 ] ) {
case 'b' :
case 'B' :
case 'g' :
case 'G' :
case 'h' :
case 'H' :
return V_141 |
V_142 |
V_143 ;
case 'd' :
case 'D' :
case 'k' :
case 'K' :
return V_144 ;
case 'l' :
case 'L' :
if ( ( V_139 [ 1 ] == 'C' ) || ( V_139 [ 1 ] == 'c' ) )
return V_145 ;
return V_146 ;
default:
F_6 ( L_30 ) ;
break;
}
}
if ( V_147 [ 0 ] != '-' && ( V_127 & V_148 ) == V_148 ) {
switch ( V_147 [ 0 ] ) {
case 'm' :
case 'M' :
return V_149 ;
case 'j' :
case 'J' :
return V_150 ;
case 'k' :
case 'K' :
return V_151 ;
default:
F_28 ( L_31 ) ;
break;
}
}
return V_127 ;
}
static void F_17 ( struct V_22 * V_23 , unsigned int V_126 )
{
struct V_7 * V_14 = F_3 ( F_12 ( V_23 ) ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_10 V_11 = {
. V_87 = V_14 -> V_87 ,
. V_107 = V_14 -> V_107 ,
. V_127 = V_14 -> V_127
} ;
if ( V_14 -> type == V_33 ) {
F_6 ( L_25 ) ;
return;
}
if ( NULL == V_6 -> V_82 ) {
F_6 ( L_32 ) ;
return;
}
if ( V_126 < V_152 [ 0 ] * 16000 || V_126 > V_152 [ 1 ] * 16000 ) {
F_13 ( L_33 ,
V_126 / 16000 , V_126 % 16000 * 100 / 16000 ,
V_152 [ 0 ] , V_152 [ 1 ] ) ;
if ( V_126 < V_152 [ 0 ] * 16000 )
V_126 = V_152 [ 0 ] * 16000 ;
else
V_126 = V_152 [ 1 ] * 16000 ;
}
V_11 . V_129 = V_126 ;
F_13 ( L_34 ,
V_126 / 16000 , V_126 % 16000 * 100 / 16000 ) ;
V_14 -> V_88 = V_126 ;
V_14 -> V_109 = false ;
V_6 -> V_82 ( & V_14 -> V_2 , & V_11 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_7 * V_14 = V_2 -> V_15 ;
unsigned long V_126 , V_153 ;
struct V_12 * V_13 = & V_2 -> V_3 . V_4 ;
struct V_30 * V_6 = & V_2 -> V_3 . V_6 ;
const char * V_154 ;
switch ( V_14 -> V_87 ) {
case V_86 :
V_154 = L_35 ;
break;
case V_155 :
V_154 = L_36 ;
break;
case V_120 :
default:
V_154 = L_37 ;
break;
}
if ( V_14 -> V_87 == V_86 ) {
V_126 = V_14 -> V_88 / 16000 ;
V_153 = ( V_14 -> V_88 % 16000 ) * 100 / 16000 ;
} else {
V_126 = V_14 -> V_89 / 16 ;
V_153 = ( V_14 -> V_89 % 16 ) * 100 / 16 ;
}
F_28 ( L_38 , V_154 ,
V_14 -> V_109 ? L_39 : L_20 ) ;
F_28 ( L_40 , V_126 , V_153 ) ;
F_28 ( L_41 , ( unsigned long ) V_14 -> V_127 ) ;
if ( V_14 -> V_87 != V_86 )
return;
if ( V_13 -> V_156 ) {
T_3 F_40 ;
V_13 -> V_156 ( & V_14 -> V_2 , & F_40 ) ;
if ( F_40 & V_157 )
F_28 ( L_42 ) ;
if ( F_40 & V_158 )
F_28 ( L_43 ) ;
}
if ( V_6 -> V_159 )
F_28 ( L_44 ,
V_6 -> V_159 ( V_2 ) ) ;
}
static int F_41 ( struct V_8 * V_9 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_37 ( V_14 , V_86 ) == 0 )
F_38 ( V_14 , 0 ) ;
return 0 ;
}
static int F_42 ( struct V_8 * V_9 , int V_160 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_160 ) {
if ( V_14 -> V_109 && F_37 ( V_14 , V_14 -> V_87 ) == 0 ) {
F_13 ( L_45 ) ;
F_38 ( V_14 , 0 ) ;
}
return 0 ;
}
F_13 ( L_23 ) ;
V_14 -> V_109 = true ;
if ( V_6 -> V_109 )
V_6 -> V_109 ( & V_14 -> V_2 ) ;
return 0 ;
}
static int F_43 ( struct V_8 * V_9 , T_2 V_127 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_37 ( V_14 , V_120 ) )
return 0 ;
V_14 -> V_127 = F_39 ( V_14 , V_127 ) ;
if ( V_14 -> V_127 != V_127 )
F_13 ( L_46 , V_127 , V_14 -> V_127 ) ;
F_38 ( V_14 , 0 ) ;
return 0 ;
}
static int F_44 ( struct V_8 * V_9 , struct V_161 * V_162 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_37 ( V_14 , V_162 -> type ) == 0 )
F_38 ( V_14 , V_162 -> V_129 ) ;
return 0 ;
}
static int F_45 ( struct V_8 * V_9 , struct V_161 * V_162 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_12 * V_13 = & V_14 -> V_2 . V_3 . V_4 ;
if ( F_36 ( V_14 , V_162 -> type ) == - V_125 )
return 0 ;
if ( V_162 -> type == V_14 -> V_87 && V_13 -> V_163 && ! V_14 -> V_109 ) {
T_3 V_164 ;
V_13 -> V_163 ( & V_14 -> V_2 , & V_164 ) ;
V_162 -> V_129 = ( V_86 == V_14 -> V_87 ) ?
F_46 ( V_164 * 2 , 125 ) :
F_46 ( V_164 , 62500 ) ;
} else {
V_162 -> V_129 = ( V_86 == V_162 -> type ) ?
V_14 -> V_88 : V_14 -> V_89 ;
}
return 0 ;
}
static int F_47 ( struct V_8 * V_9 , struct V_165 * V_166 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_12 * V_13 = & V_14 -> V_2 . V_3 . V_4 ;
if ( F_36 ( V_14 , V_166 -> type ) == - V_125 )
return 0 ;
if ( V_166 -> type == V_14 -> V_87 && V_6 -> V_167 )
V_166 -> V_168 = V_6 -> V_167 ( & V_14 -> V_2 ) ;
if ( V_14 -> V_87 != V_86 ) {
V_166 -> V_169 |= V_170 ;
V_166 -> V_171 = V_128 [ 0 ] * 16 ;
V_166 -> V_172 = V_128 [ 1 ] * 16 ;
return 0 ;
}
if ( V_166 -> type == V_14 -> V_87 ) {
V_166 -> V_173 = V_174 | V_175 ;
if ( V_13 -> V_156 ) {
T_3 F_40 ;
V_13 -> V_156 ( & V_14 -> V_2 , & F_40 ) ;
V_166 -> V_173 =
( F_40 & V_158 ) ?
V_175 :
V_174 ;
}
if ( V_6 -> V_159 )
V_166 -> signal = V_6 -> V_159 ( & V_14 -> V_2 ) ;
V_166 -> V_107 = V_14 -> V_107 ;
}
V_166 -> V_169 |= V_176 | V_177 ;
V_166 -> V_171 = V_152 [ 0 ] * 16000 ;
V_166 -> V_172 = V_152 [ 1 ] * 16000 ;
return 0 ;
}
static int F_48 ( struct V_8 * V_9 , struct V_165 * V_166 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_37 ( V_14 , V_166 -> type ) )
return 0 ;
if ( V_14 -> V_87 == V_86 )
V_14 -> V_107 = V_166 -> V_107 ;
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
static int F_50 ( struct V_22 * V_23 , T_4 V_178 )
{
struct V_7 * V_14 = F_3 ( F_12 ( V_23 ) ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
F_13 ( L_47 ) ;
if ( ! V_14 -> V_109 && V_6 -> V_109 )
V_6 -> V_109 ( & V_14 -> V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_22 * V_23 )
{
struct V_7 * V_14 = F_3 ( F_12 ( V_23 ) ) ;
F_13 ( L_48 ) ;
if ( ! V_14 -> V_109 )
if ( F_37 ( V_14 , V_14 -> V_87 ) == 0 )
F_38 ( V_14 , 0 ) ;
return 0 ;
}
static int F_52 ( struct V_22 * V_102 , unsigned V_28 , void * V_29 )
{
struct V_8 * V_9 = F_12 ( V_102 ) ;
switch ( V_28 ) {
case V_179 :
return F_21 ( V_9 , V_29 ) ;
}
return - V_180 ;
}
static T_5 int F_53 ( void )
{
return F_54 ( & V_181 ) ;
}
static T_6 void F_55 ( void )
{
F_56 ( & V_181 ) ;
}
