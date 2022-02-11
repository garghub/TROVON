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
static int F_8 ( struct V_1 * V_2 , void * V_18 )
{
struct V_12 * V_13 = & V_2 -> V_3 . V_4 ;
struct V_7 * V_14 = V_2 -> V_15 ;
if ( V_13 -> V_19 )
return V_13 -> V_19 ( V_2 , V_18 ) ;
F_6 ( L_2 ) ;
return 0 ;
}
static void F_9 ( struct V_20 * V_21 , unsigned int type ,
unsigned int V_22 , void * V_23 ,
int (* F_10) ( void * V_24 , int V_25 , int V_26 , int V_27 ) )
{
struct V_7 * V_14 = F_3 ( F_11 ( V_21 ) ) ;
struct V_12 * V_13 = & V_14 -> V_2 . V_3 . V_4 ;
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
unsigned char V_29 [ 4 ] ;
int V_30 = 1 ;
if ( type == V_31 || type == V_32 ) {
F_12 ( L_3 , V_21 -> V_33 ) ;
return;
}
V_14 -> type = type ;
V_14 -> V_34 = V_23 ;
if ( F_10 != NULL ) {
F_12 ( L_4 ) ;
V_14 -> V_2 . V_35 = F_10 ;
}
F_1 ( & V_14 -> V_2 ) ;
V_14 -> V_2 . V_15 = NULL ;
switch ( V_14 -> type ) {
case V_36 :
if ( ! F_13 ( V_37 ,
& V_14 -> V_2 , V_14 -> V_38 -> V_39 , V_14 -> V_38 -> V_33 ) )
goto V_40;
break;
case V_41 :
{
if ( ! F_13 ( V_42 , & V_14 -> V_2 , V_14 -> V_38 -> V_39 ,
V_14 -> V_38 -> V_33 , V_14 -> V_34 ) )
goto V_40;
break;
}
case V_43 :
if ( ! F_13 ( V_44 , & V_14 -> V_2 ,
V_14 -> V_38 -> V_39 , V_14 -> V_38 -> V_33 ) )
goto V_40;
V_14 -> V_45 = V_46 ;
break;
case V_47 :
if ( ! F_13 ( V_48 , & V_14 -> V_2 ,
V_14 -> V_38 -> V_39 , V_14 -> V_38 -> V_33 ) )
goto V_40;
V_14 -> V_45 = V_46 ;
break;
case V_49 :
case V_50 :
V_29 [ 0 ] = 0x0b ;
V_29 [ 1 ] = 0xdc ;
V_29 [ 2 ] = 0x9c ;
V_29 [ 3 ] = 0x60 ;
F_14 ( V_21 , V_29 , 4 ) ;
F_15 ( 1 ) ;
V_29 [ 2 ] = 0x86 ;
V_29 [ 3 ] = 0x54 ;
F_14 ( V_21 , V_29 , 4 ) ;
if ( ! F_13 ( V_51 , & V_14 -> V_2 ,
V_14 -> V_38 -> V_39 , V_14 -> V_38 -> V_33 , V_14 -> type ) )
goto V_40;
break;
case V_52 :
V_29 [ 0 ] = 0x0b ;
V_29 [ 1 ] = 0xdc ;
V_29 [ 2 ] = 0x86 ;
V_29 [ 3 ] = 0xa4 ;
F_14 ( V_21 , V_29 , 4 ) ;
if ( ! F_13 ( V_51 , & V_14 -> V_2 ,
V_14 -> V_38 -> V_39 , V_14 -> V_38 -> V_33 , V_14 -> type ) )
goto V_40;
break;
case V_53 :
{
struct V_54 V_55 = {
. V_56 = V_14 -> V_38 -> V_39 ,
. V_57 = V_14 -> V_38 -> V_33 ,
} ;
if ( ! F_13 ( V_58 , & V_14 -> V_2 , & V_55 ) )
goto V_40;
V_30 = 0 ;
break;
}
case V_59 :
if ( ! F_13 ( V_60 ,
& V_14 -> V_2 , V_14 -> V_38 -> V_39 , V_14 -> V_38 -> V_33 ) )
goto V_40;
break;
case V_61 :
{
struct V_62 V_63 = {
. V_64 = V_14 -> V_38 -> V_33 ,
. V_65 = 0 ,
} ;
if ( ! F_13 ( V_66 ,
& V_14 -> V_2 , V_14 -> V_38 -> V_39 , & V_63 ) )
goto V_40;
V_30 = 0 ;
break;
}
case V_67 :
{
struct V_62 V_68 = {
. V_64 = V_14 -> V_38 -> V_33 ,
. V_65 = 0 ,
. V_69 = V_70 ,
} ;
if ( ! F_13 ( V_66 ,
& V_14 -> V_2 , V_14 -> V_38 -> V_39 , & V_68 ) )
goto V_40;
V_30 = 0 ;
break;
}
case V_71 :
{
struct V_72 V_55 = {
. V_73 = V_74 ,
} ;
if ( ! F_13 ( V_75 , & V_14 -> V_2 , V_14 -> V_38 -> V_33 ,
V_14 -> V_38 -> V_39 , & V_55 ) )
goto V_40;
V_30 = 0 ;
break;
}
case V_76 :
{
struct V_77 V_78 = {
. V_64 = V_14 -> V_38 -> V_33 ,
. V_79 = 0 ,
. V_80 = 0 ,
. V_81 = 0 ,
. V_65 = 0
} ;
if ( ! F_13 ( V_82 ,
& V_14 -> V_2 , V_14 -> V_38 -> V_39 , & V_78 ) )
goto V_40;
V_30 = 0 ;
break;
}
default:
if ( ! F_13 ( V_51 , & V_14 -> V_2 ,
V_14 -> V_38 -> V_39 , V_14 -> V_38 -> V_33 , V_14 -> type ) )
goto V_40;
break;
}
if ( ( NULL == V_6 -> V_83 ) &&
( V_13 -> V_16 ) ) {
V_14 -> V_84 = V_13 -> V_85 . V_84 ;
V_14 -> V_2 . V_15 = V_14 ;
memcpy ( V_6 , & V_86 ,
sizeof( struct V_28 ) ) ;
if ( V_13 -> V_87 )
V_6 -> V_88 = V_13 -> V_87 ;
if ( V_13 -> V_89 )
V_6 -> V_89 = V_13 -> V_89 ;
} else {
V_14 -> V_84 = V_6 -> V_85 . V_84 ;
}
F_12 ( L_5 , V_14 -> V_84 ) ;
V_14 -> V_45 = V_22 ;
if ( V_30 ) {
if ( V_90 == V_14 -> V_91 )
F_16 ( V_21 , V_14 -> V_92 ) ;
else
F_17 ( V_21 , V_14 -> V_93 ) ;
}
F_12 ( L_6 ,
V_21 -> V_39 -> V_84 , V_21 -> V_94 -> V_94 . V_84 , V_21 -> V_33 << 1 , type ,
V_14 -> V_45 ) ;
return;
V_40:
F_12 ( L_7 , V_14 -> type ) ;
V_14 -> type = V_32 ;
return;
}
static int F_18 ( struct V_8 * V_9 ,
struct V_95 * V_96 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_20 * V_21 = F_19 ( V_9 ) ;
F_12 ( L_8 ,
V_96 -> type ,
V_96 -> V_33 ,
V_96 -> V_45 ,
V_96 -> V_34 ) ;
if ( ( V_14 -> type == V_31 && ( ( V_96 -> V_33 == V_97 ) &&
( V_14 -> V_45 & V_96 -> V_45 ) ) ) ||
( V_96 -> V_33 == V_21 -> V_33 ) ) {
F_9 ( V_21 , V_96 -> type , V_96 -> V_45 ,
V_96 -> V_34 , V_96 -> F_10 ) ;
} else
F_12 ( L_9
L_10 ,
V_14 -> type , V_14 -> V_45 ,
V_96 -> V_33 , V_96 -> V_45 ) ;
return 0 ;
}
static int F_20 ( struct V_8 * V_9 ,
const struct V_98 * V_55 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_14 -> type != V_55 -> V_7 )
return 0 ;
if ( V_6 -> V_19 ) {
V_6 -> V_19 ( & V_14 -> V_2 , V_55 -> V_99 ) ;
return 0 ;
}
F_12 ( L_2 ) ;
return 0 ;
}
static void F_21 ( struct V_100 * V_101 ,
struct V_7 * * V_102 , struct V_7 * * V_103 )
{
struct V_7 * V_104 ;
* V_102 = NULL ;
* V_103 = NULL ;
F_22 (pos, &tuner_list, list) {
int V_45 ;
if ( V_104 -> V_38 -> V_39 != V_101 ||
strcmp ( V_104 -> V_38 -> V_94 -> V_94 . V_84 , L_11 ) )
continue;
V_45 = V_104 -> V_45 ;
if ( * V_102 == NULL && V_45 == V_46 )
* V_102 = V_104 ;
else if ( * V_103 == NULL && V_104 -> type != V_59 &&
( V_104 -> V_45 & V_105 ) )
* V_103 = V_104 ;
}
}
static int F_23 ( struct V_20 * V_106 ,
const struct V_107 * V_108 )
{
struct V_7 * V_14 ;
struct V_7 * V_102 ;
struct V_7 * V_103 ;
V_14 = F_24 ( sizeof( struct V_7 ) , V_109 ) ;
if ( NULL == V_14 )
return - V_110 ;
F_25 ( & V_14 -> V_9 , V_106 , & V_4 ) ;
V_14 -> V_38 = V_106 ;
V_14 -> V_84 = L_12 ;
V_14 -> type = V_31 ;
V_14 -> V_111 = V_112 ;
V_14 -> V_113 = 1 ;
V_14 -> V_92 = 87.5 * 16000 ;
V_14 -> V_93 = 400 * 16 ;
if ( V_114 ) {
unsigned char V_29 [ 16 ] ;
int V_115 , V_116 ;
memset ( V_29 , 0 , sizeof( V_29 ) ) ;
V_116 = F_26 ( V_106 , V_29 , sizeof( V_29 ) ) ;
F_27 ( L_13 ) ;
for ( V_115 = 0 ; V_115 < V_116 ; V_115 ++ )
F_28 ( V_117 L_14 , V_29 [ V_115 ] ) ;
F_28 ( L_15 ) ;
}
if ( ! V_118 ) {
switch ( V_106 -> V_33 ) {
case 0x10 :
if ( F_29 ( V_119 ,
V_14 -> V_38 -> V_39 ,
V_14 -> V_38 -> V_33 ) >= 0 ) {
V_14 -> type = V_47 ;
V_14 -> V_45 = V_46 ;
F_21 ( V_14 -> V_38 -> V_39 , & V_102 , & V_103 ) ;
if ( V_103 )
V_103 -> V_45 &= ~ V_46 ;
goto V_120;
}
F_30 ( V_14 ) ;
return - V_121 ;
case 0x42 :
case 0x43 :
case 0x4a :
case 0x4b :
if ( F_29 ( V_122 , V_14 -> V_38 -> V_39 ,
V_14 -> V_38 -> V_33 ) >= 0 ) {
F_12 ( L_16 ) ;
} else {
V_14 -> type = V_59 ;
V_14 -> V_45 = V_46 | V_105 ;
goto V_120;
}
break;
case 0x60 :
if ( F_29 ( V_123 ,
V_14 -> V_38 -> V_39 , V_14 -> V_38 -> V_33 )
>= 0 ) {
V_14 -> type = V_43 ;
V_14 -> V_45 = V_46 ;
F_21 ( V_14 -> V_38 -> V_39 , & V_102 , & V_103 ) ;
if ( V_103 )
V_103 -> V_45 &= ~ V_46 ;
goto V_120;
}
break;
}
}
F_21 ( V_14 -> V_38 -> V_39 , & V_102 , & V_103 ) ;
if ( V_103 == NULL ) {
V_14 -> V_45 = V_105 ;
if ( V_102 == NULL )
V_14 -> V_45 |= V_46 ;
F_12 ( L_17 , V_14 -> V_45 ) ;
}
V_120:
if ( V_14 -> V_45 & V_105 )
V_14 -> V_91 = V_124 ;
else
V_14 -> V_91 = V_90 ;
F_9 ( V_106 , V_14 -> type , V_14 -> V_45 , V_14 -> V_34 , V_14 -> V_2 . V_35 ) ;
F_31 ( & V_14 -> V_125 , & V_126 ) ;
F_27 ( L_18 ,
V_14 -> type ,
V_14 -> V_45 & V_46 ? L_19 : L_20 ,
V_14 -> V_45 & V_105 ? L_21 : L_20 ) ;
return 0 ;
}
static int F_32 ( struct V_20 * V_106 )
{
struct V_7 * V_14 = F_3 ( F_11 ( V_106 ) ) ;
F_33 ( & V_14 -> V_9 ) ;
F_1 ( & V_14 -> V_2 ) ;
V_14 -> V_2 . V_15 = NULL ;
F_34 ( & V_14 -> V_125 ) ;
F_30 ( V_14 ) ;
return 0 ;
}
static inline int F_35 ( struct V_7 * V_14 , enum V_127 V_91 )
{
int V_128 ;
if ( V_91 == V_90 )
V_128 = V_46 ;
else
V_128 = V_105 ;
if ( ( V_128 & V_14 -> V_45 ) == 0 )
return - V_129 ;
return 0 ;
}
static int F_36 ( struct V_7 * V_14 , enum V_127 V_91 )
{
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_91 != V_14 -> V_91 ) {
if ( F_35 ( V_14 , V_91 ) == - V_129 ) {
F_12 ( L_22
L_23 , V_91 ) ;
V_14 -> V_113 = true ;
if ( V_6 -> V_113 )
V_6 -> V_113 ( & V_14 -> V_2 ) ;
return - V_129 ;
}
V_14 -> V_91 = V_91 ;
F_12 ( L_24 , V_91 ) ;
}
return 0 ;
}
static void F_37 ( struct V_7 * V_14 , unsigned int V_130 )
{
struct V_20 * V_106 = F_19 ( & V_14 -> V_9 ) ;
if ( V_14 -> V_91 == V_90 ) {
if ( ! V_130 )
V_130 = V_14 -> V_92 ;
F_16 ( V_106 , V_130 ) ;
} else {
if ( ! V_130 )
V_130 = V_14 -> V_93 ;
F_17 ( V_106 , V_130 ) ;
}
}
static void F_17 ( struct V_20 * V_21 , unsigned int V_130 )
{
struct V_7 * V_14 = F_3 ( F_11 ( V_21 ) ) ;
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_10 V_11 = {
. V_91 = V_14 -> V_91 ,
. V_111 = V_14 -> V_111 ,
. V_131 = V_14 -> V_131
} ;
if ( V_14 -> type == V_31 ) {
F_6 ( L_25 ) ;
return;
}
if ( NULL == V_6 -> V_83 ) {
F_6 ( L_26 ) ;
return;
}
if ( V_130 < V_132 [ 0 ] * 16 || V_130 > V_132 [ 1 ] * 16 ) {
F_12 ( L_27 ,
V_130 / 16 , V_130 % 16 * 100 / 16 , V_132 [ 0 ] ,
V_132 [ 1 ] ) ;
if ( V_130 < V_132 [ 0 ] * 16 )
V_130 = V_132 [ 0 ] * 16 ;
else
V_130 = V_132 [ 1 ] * 16 ;
}
V_11 . V_133 = V_130 ;
F_12 ( L_28 ,
V_130 / 16 , V_130 % 16 * 100 / 16 ) ;
V_14 -> V_93 = V_130 ;
V_14 -> V_113 = false ;
V_6 -> V_83 ( & V_14 -> V_2 , & V_11 ) ;
}
static T_1 F_38 ( struct V_7 * V_14 , T_1 V_131 )
{
if ( V_134 [ 0 ] != '-' && ( V_131 & V_135 ) == V_135 ) {
switch ( V_134 [ 0 ] ) {
case '6' :
return V_136 ;
case 'b' :
case 'B' :
case 'g' :
case 'G' :
return V_137 ;
case 'i' :
case 'I' :
return V_138 ;
case 'd' :
case 'D' :
case 'k' :
case 'K' :
return V_139 ;
case 'M' :
case 'm' :
return V_140 ;
case 'N' :
case 'n' :
if ( V_134 [ 1 ] == 'c' || V_134 [ 1 ] == 'C' )
return V_141 ;
return V_142 ;
default:
F_6 ( L_29 ) ;
break;
}
}
if ( V_143 [ 0 ] != '-' && ( V_131 & V_144 ) == V_144 ) {
switch ( V_143 [ 0 ] ) {
case 'b' :
case 'B' :
case 'g' :
case 'G' :
case 'h' :
case 'H' :
return V_145 |
V_146 |
V_147 ;
case 'd' :
case 'D' :
case 'k' :
case 'K' :
return V_148 ;
case 'l' :
case 'L' :
if ( ( V_143 [ 1 ] == 'C' ) || ( V_143 [ 1 ] == 'c' ) )
return V_149 ;
return V_150 ;
default:
F_6 ( L_30 ) ;
break;
}
}
if ( V_151 [ 0 ] != '-' && ( V_131 & V_152 ) == V_152 ) {
switch ( V_151 [ 0 ] ) {
case 'm' :
case 'M' :
return V_153 ;
case 'j' :
case 'J' :
return V_154 ;
case 'k' :
case 'K' :
return V_155 ;
default:
F_27 ( L_31 ) ;
break;
}
}
return V_131 ;
}
static void F_16 ( struct V_20 * V_21 , unsigned int V_130 )
{
struct V_7 * V_14 = F_3 ( F_11 ( V_21 ) ) ;
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_10 V_11 = {
. V_91 = V_14 -> V_91 ,
. V_111 = V_14 -> V_111 ,
. V_131 = V_14 -> V_131
} ;
if ( V_14 -> type == V_31 ) {
F_6 ( L_25 ) ;
return;
}
if ( NULL == V_6 -> V_83 ) {
F_6 ( L_32 ) ;
return;
}
if ( V_130 < V_156 [ 0 ] * 16000 || V_130 > V_156 [ 1 ] * 16000 ) {
F_12 ( L_33 ,
V_130 / 16000 , V_130 % 16000 * 100 / 16000 ,
V_156 [ 0 ] , V_156 [ 1 ] ) ;
if ( V_130 < V_156 [ 0 ] * 16000 )
V_130 = V_156 [ 0 ] * 16000 ;
else
V_130 = V_156 [ 1 ] * 16000 ;
}
V_11 . V_133 = V_130 ;
F_12 ( L_34 ,
V_130 / 16000 , V_130 % 16000 * 100 / 16000 ) ;
V_14 -> V_92 = V_130 ;
V_14 -> V_113 = false ;
V_6 -> V_83 ( & V_14 -> V_2 , & V_11 ) ;
V_14 -> V_111 = V_11 . V_111 ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_7 * V_14 = V_2 -> V_15 ;
unsigned long V_130 , V_157 ;
struct V_12 * V_13 = & V_2 -> V_3 . V_4 ;
struct V_28 * V_6 = & V_2 -> V_3 . V_6 ;
const char * V_158 ;
switch ( V_14 -> V_91 ) {
case V_90 :
V_158 = L_35 ;
break;
case V_159 :
V_158 = L_36 ;
break;
case V_124 :
default:
V_158 = L_37 ;
break;
}
if ( V_14 -> V_91 == V_90 ) {
V_130 = V_14 -> V_92 / 16000 ;
V_157 = ( V_14 -> V_92 % 16000 ) * 100 / 16000 ;
} else {
V_130 = V_14 -> V_93 / 16 ;
V_157 = ( V_14 -> V_93 % 16 ) * 100 / 16 ;
}
F_27 ( L_38 , V_158 ,
V_14 -> V_113 ? L_39 : L_20 ) ;
F_27 ( L_40 , V_130 , V_157 ) ;
F_27 ( L_41 , ( unsigned long ) V_14 -> V_131 ) ;
if ( V_14 -> V_91 != V_90 )
return;
if ( V_13 -> V_160 ) {
T_2 F_39 ;
V_13 -> V_160 ( & V_14 -> V_2 , & F_39 ) ;
if ( F_39 & V_161 )
F_27 ( L_42 ) ;
if ( F_39 & V_162 )
F_27 ( L_43 ) ;
}
if ( V_6 -> V_88 ) {
T_3 signal ;
if ( ! V_6 -> V_88 ( V_2 , & signal ) )
F_27 ( L_44 , signal ) ;
}
}
static int F_40 ( struct V_8 * V_9 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_36 ( V_14 , V_90 ) == 0 )
F_37 ( V_14 , 0 ) ;
return 0 ;
}
static int F_41 ( struct V_8 * V_9 , int V_163 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_163 ) {
if ( V_14 -> V_113 && F_36 ( V_14 , V_14 -> V_91 ) == 0 ) {
F_12 ( L_45 ) ;
F_37 ( V_14 , 0 ) ;
}
return 0 ;
}
F_12 ( L_23 ) ;
V_14 -> V_113 = true ;
if ( V_6 -> V_113 )
V_6 -> V_113 ( & V_14 -> V_2 ) ;
return 0 ;
}
static int F_42 ( struct V_8 * V_9 , T_1 V_131 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_36 ( V_14 , V_124 ) )
return 0 ;
V_14 -> V_131 = F_38 ( V_14 , V_131 ) ;
if ( V_14 -> V_131 != V_131 )
F_12 ( L_46 , V_131 , V_14 -> V_131 ) ;
F_37 ( V_14 , 0 ) ;
return 0 ;
}
static int F_43 ( struct V_8 * V_9 , const struct V_164 * V_165 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_36 ( V_14 , V_165 -> type ) == 0 )
F_37 ( V_14 , V_165 -> V_133 ) ;
return 0 ;
}
static int F_44 ( struct V_8 * V_9 , struct V_164 * V_165 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_12 * V_13 = & V_14 -> V_2 . V_3 . V_4 ;
if ( F_35 ( V_14 , V_165 -> type ) == - V_129 )
return 0 ;
if ( V_165 -> type == V_14 -> V_91 && V_13 -> V_166 && ! V_14 -> V_113 ) {
T_2 V_167 ;
V_13 -> V_166 ( & V_14 -> V_2 , & V_167 ) ;
V_165 -> V_133 = ( V_90 == V_14 -> V_91 ) ?
F_45 ( V_167 * 2 , 125 ) :
F_45 ( V_167 , 62500 ) ;
} else {
V_165 -> V_133 = ( V_90 == V_165 -> type ) ?
V_14 -> V_92 : V_14 -> V_93 ;
}
return 0 ;
}
static int F_46 ( struct V_8 * V_9 , struct V_168 * V_169 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_12 * V_13 = & V_14 -> V_2 . V_3 . V_4 ;
if ( F_35 ( V_14 , V_169 -> type ) == - V_129 )
return 0 ;
if ( V_169 -> type == V_14 -> V_91 && V_6 -> V_89 )
V_6 -> V_89 ( & V_14 -> V_2 , & V_169 -> V_170 ) ;
if ( V_169 -> type == V_14 -> V_91 && V_6 -> V_88 ) {
T_3 signal = ( T_3 ) V_169 -> signal ;
if ( ! V_6 -> V_88 ( & V_14 -> V_2 , & signal ) )
V_169 -> signal = signal ;
}
if ( V_169 -> type != V_90 ) {
V_169 -> V_171 |= V_172 ;
V_169 -> V_173 = V_132 [ 0 ] * 16 ;
V_169 -> V_174 = V_132 [ 1 ] * 16 ;
return 0 ;
}
if ( V_169 -> type == V_14 -> V_91 ) {
V_169 -> V_175 = V_176 | V_177 ;
if ( V_13 -> V_160 ) {
T_2 F_39 ;
V_13 -> V_160 ( & V_14 -> V_2 , & F_39 ) ;
V_169 -> V_175 =
( F_39 & V_162 ) ?
V_177 :
V_176 ;
}
V_169 -> V_111 = V_14 -> V_111 ;
}
V_169 -> V_171 |= V_178 | V_179 ;
V_169 -> V_173 = V_156 [ 0 ] * 16000 ;
V_169 -> V_174 = V_156 [ 1 ] * 16000 ;
return 0 ;
}
static int F_47 ( struct V_8 * V_9 , const struct V_168 * V_169 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_36 ( V_14 , V_169 -> type ) )
return 0 ;
if ( V_14 -> V_91 == V_90 ) {
V_14 -> V_111 = V_169 -> V_111 ;
if ( V_14 -> V_111 != V_180 &&
V_14 -> V_111 != V_112 )
V_14 -> V_111 = V_112 ;
}
F_37 ( V_14 , 0 ) ;
return 0 ;
}
static int F_48 ( struct V_8 * V_9 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_6 -> F_39 )
V_6 -> F_39 ( & V_14 -> V_2 ) ;
return 0 ;
}
static int F_49 ( struct V_181 * V_24 )
{
struct V_20 * V_21 = F_50 ( V_24 ) ;
struct V_7 * V_14 = F_3 ( F_11 ( V_21 ) ) ;
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
F_12 ( L_47 ) ;
if ( ! V_14 -> V_113 && V_6 -> V_113 )
V_6 -> V_113 ( & V_14 -> V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_181 * V_24 )
{
struct V_20 * V_21 = F_50 ( V_24 ) ;
struct V_7 * V_14 = F_3 ( F_11 ( V_21 ) ) ;
F_12 ( L_48 ) ;
if ( ! V_14 -> V_113 )
if ( F_36 ( V_14 , V_14 -> V_91 ) == 0 )
F_37 ( V_14 , 0 ) ;
return 0 ;
}
static int F_52 ( struct V_20 * V_106 , unsigned V_26 , void * V_27 )
{
struct V_8 * V_9 = F_11 ( V_106 ) ;
switch ( V_26 ) {
case V_182 :
return F_20 ( V_9 , V_27 ) ;
}
return - V_183 ;
}
