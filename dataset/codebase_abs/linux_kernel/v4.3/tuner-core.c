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
#ifdef F_16
V_14 -> V_9 . V_90 . V_84 = V_14 -> V_84 ;
#endif
F_12 ( L_5 , V_14 -> V_84 ) ;
V_14 -> V_45 = V_22 ;
if ( V_30 ) {
if ( V_91 == V_14 -> V_92 )
F_17 ( V_21 , V_14 -> V_93 ) ;
else
F_18 ( V_21 , V_14 -> V_94 ) ;
}
F_12 ( L_6 ,
V_21 -> V_39 -> V_84 , V_21 -> V_24 . V_95 -> V_84 , V_21 -> V_33 << 1 , type ,
V_14 -> V_45 ) ;
return;
V_40:
F_12 ( L_7 , V_14 -> type ) ;
V_14 -> type = V_32 ;
return;
}
static int F_19 ( struct V_8 * V_9 ,
struct V_96 * V_97 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_20 * V_21 = F_20 ( V_9 ) ;
F_12 ( L_8 ,
V_97 -> type ,
V_97 -> V_33 ,
V_97 -> V_45 ,
V_97 -> V_34 ) ;
if ( ( V_14 -> type == V_31 && ( ( V_97 -> V_33 == V_98 ) &&
( V_14 -> V_45 & V_97 -> V_45 ) ) ) ||
( V_97 -> V_33 == V_21 -> V_33 ) ) {
F_9 ( V_21 , V_97 -> type , V_97 -> V_45 ,
V_97 -> V_34 , V_97 -> F_10 ) ;
} else
F_12 ( L_9
L_10 ,
V_14 -> type , V_14 -> V_45 ,
V_97 -> V_33 , V_97 -> V_45 ) ;
return 0 ;
}
static int F_21 ( struct V_8 * V_9 ,
const struct V_99 * V_55 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_14 -> type != V_55 -> V_7 )
return 0 ;
if ( V_6 -> V_19 ) {
V_6 -> V_19 ( & V_14 -> V_2 , V_55 -> V_100 ) ;
return 0 ;
}
F_12 ( L_2 ) ;
return 0 ;
}
static void F_22 ( struct V_101 * V_102 ,
struct V_7 * * V_103 , struct V_7 * * V_104 )
{
struct V_7 * V_105 ;
* V_103 = NULL ;
* V_104 = NULL ;
F_23 (pos, &tuner_list, list) {
int V_45 ;
if ( V_105 -> V_38 -> V_39 != V_102 ||
strcmp ( V_105 -> V_38 -> V_24 . V_95 -> V_84 , L_11 ) )
continue;
V_45 = V_105 -> V_45 ;
if ( * V_103 == NULL && V_45 == V_46 )
* V_103 = V_105 ;
else if ( * V_104 == NULL && V_105 -> type != V_59 &&
( V_105 -> V_45 & V_106 ) )
* V_104 = V_105 ;
}
}
static int F_24 ( struct V_20 * V_107 ,
const struct V_108 * V_109 )
{
struct V_7 * V_14 ;
struct V_7 * V_103 ;
struct V_7 * V_104 ;
#ifdef F_16
int V_110 ;
#endif
V_14 = F_25 ( sizeof( struct V_7 ) , V_111 ) ;
if ( NULL == V_14 )
return - V_112 ;
F_26 ( & V_14 -> V_9 , V_107 , & V_4 ) ;
V_14 -> V_38 = V_107 ;
V_14 -> V_84 = L_12 ;
V_14 -> type = V_31 ;
V_14 -> V_113 = V_114 ;
V_14 -> V_115 = true ;
V_14 -> V_93 = 87.5 * 16000 ;
V_14 -> V_94 = 400 * 16 ;
if ( V_116 ) {
unsigned char V_29 [ 16 ] ;
int V_117 , V_118 ;
memset ( V_29 , 0 , sizeof( V_29 ) ) ;
V_118 = F_27 ( V_107 , V_29 , sizeof( V_29 ) ) ;
F_28 ( L_13 ) ;
for ( V_117 = 0 ; V_117 < V_118 ; V_117 ++ )
F_29 ( V_119 L_14 , V_29 [ V_117 ] ) ;
F_29 ( L_15 ) ;
}
if ( ! V_120 ) {
switch ( V_107 -> V_33 ) {
case 0x10 :
if ( F_30 ( V_121 ,
V_14 -> V_38 -> V_39 ,
V_14 -> V_38 -> V_33 ) >= 0 ) {
V_14 -> type = V_47 ;
V_14 -> V_45 = V_46 ;
F_22 ( V_14 -> V_38 -> V_39 , & V_103 , & V_104 ) ;
if ( V_104 )
V_104 -> V_45 &= ~ V_46 ;
goto V_122;
}
F_31 ( V_14 ) ;
return - V_123 ;
case 0x42 :
case 0x43 :
case 0x4a :
case 0x4b :
if ( F_30 ( V_124 , V_14 -> V_38 -> V_39 ,
V_14 -> V_38 -> V_33 ) >= 0 ) {
F_12 ( L_16 ) ;
} else {
V_14 -> type = V_59 ;
V_14 -> V_45 = V_46 | V_106 ;
goto V_122;
}
break;
case 0x60 :
if ( F_30 ( V_125 ,
V_14 -> V_38 -> V_39 , V_14 -> V_38 -> V_33 )
>= 0 ) {
V_14 -> type = V_43 ;
V_14 -> V_45 = V_46 ;
F_22 ( V_14 -> V_38 -> V_39 , & V_103 , & V_104 ) ;
if ( V_104 )
V_104 -> V_45 &= ~ V_46 ;
goto V_122;
}
break;
}
}
F_22 ( V_14 -> V_38 -> V_39 , & V_103 , & V_104 ) ;
if ( V_104 == NULL ) {
V_14 -> V_45 = V_106 ;
if ( V_103 == NULL )
V_14 -> V_45 |= V_46 ;
F_12 ( L_17 , V_14 -> V_45 ) ;
}
V_122:
#if F_32 ( F_16 )
V_14 -> V_126 . V_127 = V_128 ;
V_14 -> V_9 . V_90 . type = V_129 ;
V_14 -> V_9 . V_90 . V_84 = V_14 -> V_84 ;
V_110 = F_33 ( & V_14 -> V_9 . V_90 , 1 , & V_14 -> V_126 , 0 ) ;
if ( V_110 < 0 ) {
F_34 ( L_18 ) ;
F_31 ( V_14 ) ;
return - V_123 ;
}
#endif
if ( V_14 -> V_45 & V_106 )
V_14 -> V_92 = V_130 ;
else
V_14 -> V_92 = V_91 ;
F_9 ( V_107 , V_14 -> type , V_14 -> V_45 , V_14 -> V_34 , V_14 -> V_2 . V_35 ) ;
F_35 ( & V_14 -> V_131 , & V_132 ) ;
F_28 ( L_19 ,
V_14 -> type ,
V_14 -> V_45 & V_46 ? L_20 : L_21 ,
V_14 -> V_45 & V_106 ? L_22 : L_21 ) ;
return 0 ;
}
static int F_36 ( struct V_20 * V_107 )
{
struct V_7 * V_14 = F_3 ( F_11 ( V_107 ) ) ;
F_37 ( & V_14 -> V_9 ) ;
F_1 ( & V_14 -> V_2 ) ;
V_14 -> V_2 . V_15 = NULL ;
F_38 ( & V_14 -> V_131 ) ;
F_31 ( V_14 ) ;
return 0 ;
}
static inline int F_39 ( struct V_7 * V_14 , enum V_133 V_92 )
{
int V_134 ;
if ( V_92 == V_91 )
V_134 = V_46 ;
else
V_134 = V_106 ;
if ( ( V_134 & V_14 -> V_45 ) == 0 )
return - V_135 ;
return 0 ;
}
static int F_40 ( struct V_7 * V_14 , enum V_133 V_92 )
{
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_92 != V_14 -> V_92 ) {
if ( F_39 ( V_14 , V_92 ) == - V_135 ) {
F_12 ( L_23
L_24 , V_92 ) ;
V_14 -> V_115 = true ;
if ( V_6 -> V_115 )
V_6 -> V_115 ( & V_14 -> V_2 ) ;
return - V_135 ;
}
V_14 -> V_92 = V_92 ;
F_12 ( L_25 , V_92 ) ;
}
return 0 ;
}
static void F_41 ( struct V_7 * V_14 , unsigned int V_136 )
{
struct V_20 * V_107 = F_20 ( & V_14 -> V_9 ) ;
if ( V_14 -> V_92 == V_91 ) {
if ( ! V_136 )
V_136 = V_14 -> V_93 ;
F_17 ( V_107 , V_136 ) ;
} else {
if ( ! V_136 )
V_136 = V_14 -> V_94 ;
F_18 ( V_107 , V_136 ) ;
}
}
static void F_18 ( struct V_20 * V_21 , unsigned int V_136 )
{
struct V_7 * V_14 = F_3 ( F_11 ( V_21 ) ) ;
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_10 V_11 = {
. V_92 = V_14 -> V_92 ,
. V_113 = V_14 -> V_113 ,
. V_137 = V_14 -> V_137
} ;
if ( V_14 -> type == V_31 ) {
F_6 ( L_26 ) ;
return;
}
if ( NULL == V_6 -> V_83 ) {
F_6 ( L_27 ) ;
return;
}
if ( V_136 < V_138 [ 0 ] * 16 || V_136 > V_138 [ 1 ] * 16 ) {
F_12 ( L_28 ,
V_136 / 16 , V_136 % 16 * 100 / 16 , V_138 [ 0 ] ,
V_138 [ 1 ] ) ;
if ( V_136 < V_138 [ 0 ] * 16 )
V_136 = V_138 [ 0 ] * 16 ;
else
V_136 = V_138 [ 1 ] * 16 ;
}
V_11 . V_139 = V_136 ;
F_12 ( L_29 ,
V_136 / 16 , V_136 % 16 * 100 / 16 ) ;
V_14 -> V_94 = V_136 ;
V_14 -> V_115 = false ;
V_6 -> V_83 ( & V_14 -> V_2 , & V_11 ) ;
}
static T_1 F_42 ( struct V_7 * V_14 , T_1 V_137 )
{
if ( V_140 [ 0 ] != '-' && ( V_137 & V_141 ) == V_141 ) {
switch ( V_140 [ 0 ] ) {
case '6' :
return V_142 ;
case 'b' :
case 'B' :
case 'g' :
case 'G' :
return V_143 ;
case 'i' :
case 'I' :
return V_144 ;
case 'd' :
case 'D' :
case 'k' :
case 'K' :
return V_145 ;
case 'M' :
case 'm' :
return V_146 ;
case 'N' :
case 'n' :
if ( V_140 [ 1 ] == 'c' || V_140 [ 1 ] == 'C' )
return V_147 ;
return V_148 ;
default:
F_6 ( L_30 ) ;
break;
}
}
if ( V_149 [ 0 ] != '-' && ( V_137 & V_150 ) == V_150 ) {
switch ( V_149 [ 0 ] ) {
case 'b' :
case 'B' :
case 'g' :
case 'G' :
case 'h' :
case 'H' :
return V_151 |
V_152 |
V_153 ;
case 'd' :
case 'D' :
case 'k' :
case 'K' :
return V_154 ;
case 'l' :
case 'L' :
if ( ( V_149 [ 1 ] == 'C' ) || ( V_149 [ 1 ] == 'c' ) )
return V_155 ;
return V_156 ;
default:
F_6 ( L_31 ) ;
break;
}
}
if ( V_157 [ 0 ] != '-' && ( V_137 & V_158 ) == V_158 ) {
switch ( V_157 [ 0 ] ) {
case 'm' :
case 'M' :
return V_159 ;
case 'j' :
case 'J' :
return V_160 ;
case 'k' :
case 'K' :
return V_161 ;
default:
F_28 ( L_32 ) ;
break;
}
}
return V_137 ;
}
static void F_17 ( struct V_20 * V_21 , unsigned int V_136 )
{
struct V_7 * V_14 = F_3 ( F_11 ( V_21 ) ) ;
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_10 V_11 = {
. V_92 = V_14 -> V_92 ,
. V_113 = V_14 -> V_113 ,
. V_137 = V_14 -> V_137
} ;
if ( V_14 -> type == V_31 ) {
F_6 ( L_26 ) ;
return;
}
if ( NULL == V_6 -> V_83 ) {
F_6 ( L_33 ) ;
return;
}
if ( V_136 < V_162 [ 0 ] * 16000 || V_136 > V_162 [ 1 ] * 16000 ) {
F_12 ( L_34 ,
V_136 / 16000 , V_136 % 16000 * 100 / 16000 ,
V_162 [ 0 ] , V_162 [ 1 ] ) ;
if ( V_136 < V_162 [ 0 ] * 16000 )
V_136 = V_162 [ 0 ] * 16000 ;
else
V_136 = V_162 [ 1 ] * 16000 ;
}
V_11 . V_139 = V_136 ;
F_12 ( L_35 ,
V_136 / 16000 , V_136 % 16000 * 100 / 16000 ) ;
V_14 -> V_93 = V_136 ;
V_14 -> V_115 = false ;
V_6 -> V_83 ( & V_14 -> V_2 , & V_11 ) ;
V_14 -> V_113 = V_11 . V_113 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_7 * V_14 = V_2 -> V_15 ;
unsigned long V_136 , V_163 ;
struct V_12 * V_13 = & V_2 -> V_3 . V_4 ;
struct V_28 * V_6 = & V_2 -> V_3 . V_6 ;
const char * V_164 ;
switch ( V_14 -> V_92 ) {
case V_91 :
V_164 = L_36 ;
break;
case V_165 :
V_164 = L_37 ;
break;
case V_130 :
default:
V_164 = L_38 ;
break;
}
if ( V_14 -> V_92 == V_91 ) {
V_136 = V_14 -> V_93 / 16000 ;
V_163 = ( V_14 -> V_93 % 16000 ) * 100 / 16000 ;
} else {
V_136 = V_14 -> V_94 / 16 ;
V_163 = ( V_14 -> V_94 % 16 ) * 100 / 16 ;
}
F_28 ( L_39 , V_164 ,
V_14 -> V_115 ? L_40 : L_21 ) ;
F_28 ( L_41 , V_136 , V_163 ) ;
F_28 ( L_42 , ( unsigned long ) V_14 -> V_137 ) ;
if ( V_14 -> V_92 != V_91 )
return;
if ( V_13 -> V_166 ) {
T_2 F_43 ;
V_13 -> V_166 ( & V_14 -> V_2 , & F_43 ) ;
if ( F_43 & V_167 )
F_28 ( L_43 ) ;
if ( F_43 & V_168 )
F_28 ( L_44 ) ;
}
if ( V_6 -> V_88 ) {
T_3 signal ;
if ( ! V_6 -> V_88 ( V_2 , & signal ) )
F_28 ( L_45 , signal ) ;
}
}
static int F_44 ( struct V_8 * V_9 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_40 ( V_14 , V_91 ) == 0 )
F_41 ( V_14 , 0 ) ;
return 0 ;
}
static int F_45 ( struct V_8 * V_9 , int V_169 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_169 ) {
if ( V_14 -> V_115 && F_40 ( V_14 , V_14 -> V_92 ) == 0 ) {
F_12 ( L_46 ) ;
F_41 ( V_14 , 0 ) ;
}
return 0 ;
}
F_12 ( L_24 ) ;
V_14 -> V_115 = true ;
if ( V_6 -> V_115 )
V_6 -> V_115 ( & V_14 -> V_2 ) ;
return 0 ;
}
static int F_46 ( struct V_8 * V_9 , T_1 V_137 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_40 ( V_14 , V_130 ) )
return 0 ;
V_14 -> V_137 = F_42 ( V_14 , V_137 ) ;
if ( V_14 -> V_137 != V_137 )
F_12 ( L_47 , V_137 , V_14 -> V_137 ) ;
F_41 ( V_14 , 0 ) ;
return 0 ;
}
static int F_47 ( struct V_8 * V_9 , const struct V_170 * V_171 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_40 ( V_14 , V_171 -> type ) == 0 )
F_41 ( V_14 , V_171 -> V_139 ) ;
return 0 ;
}
static int F_48 ( struct V_8 * V_9 , struct V_170 * V_171 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_12 * V_13 = & V_14 -> V_2 . V_3 . V_4 ;
if ( F_39 ( V_14 , V_171 -> type ) == - V_135 )
return 0 ;
if ( V_171 -> type == V_14 -> V_92 && V_13 -> V_172 && ! V_14 -> V_115 ) {
T_2 V_173 ;
V_13 -> V_172 ( & V_14 -> V_2 , & V_173 ) ;
V_171 -> V_139 = ( V_91 == V_14 -> V_92 ) ?
F_49 ( V_173 * 2 , 125 ) :
F_49 ( V_173 , 62500 ) ;
} else {
V_171 -> V_139 = ( V_91 == V_171 -> type ) ?
V_14 -> V_93 : V_14 -> V_94 ;
}
return 0 ;
}
static int F_50 ( struct V_8 * V_9 , struct V_174 * V_175 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_12 * V_13 = & V_14 -> V_2 . V_3 . V_4 ;
if ( F_39 ( V_14 , V_175 -> type ) == - V_135 )
return 0 ;
if ( V_175 -> type == V_14 -> V_92 && V_6 -> V_89 )
V_6 -> V_89 ( & V_14 -> V_2 , & V_175 -> V_176 ) ;
if ( V_175 -> type == V_14 -> V_92 && V_6 -> V_88 ) {
T_3 signal = ( T_3 ) V_175 -> signal ;
if ( ! V_6 -> V_88 ( & V_14 -> V_2 , & signal ) )
V_175 -> signal = signal ;
}
if ( V_175 -> type != V_91 ) {
V_175 -> V_177 |= V_178 ;
V_175 -> V_179 = V_138 [ 0 ] * 16 ;
V_175 -> V_180 = V_138 [ 1 ] * 16 ;
return 0 ;
}
if ( V_175 -> type == V_14 -> V_92 ) {
V_175 -> V_181 = V_182 | V_183 ;
if ( V_13 -> V_166 ) {
T_2 F_43 ;
V_13 -> V_166 ( & V_14 -> V_2 , & F_43 ) ;
V_175 -> V_181 =
( F_43 & V_168 ) ?
V_183 :
V_182 ;
}
V_175 -> V_113 = V_14 -> V_113 ;
}
V_175 -> V_177 |= V_184 | V_185 ;
V_175 -> V_179 = V_162 [ 0 ] * 16000 ;
V_175 -> V_180 = V_162 [ 1 ] * 16000 ;
return 0 ;
}
static int F_51 ( struct V_8 * V_9 , const struct V_174 * V_175 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_40 ( V_14 , V_175 -> type ) )
return 0 ;
if ( V_14 -> V_92 == V_91 ) {
V_14 -> V_113 = V_175 -> V_113 ;
if ( V_14 -> V_113 != V_186 &&
V_14 -> V_113 != V_114 )
V_14 -> V_113 = V_114 ;
}
F_41 ( V_14 , 0 ) ;
return 0 ;
}
static int F_52 ( struct V_8 * V_9 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_6 -> F_43 )
V_6 -> F_43 ( & V_14 -> V_2 ) ;
return 0 ;
}
static int F_53 ( struct V_187 * V_24 )
{
struct V_20 * V_21 = F_54 ( V_24 ) ;
struct V_7 * V_14 = F_3 ( F_11 ( V_21 ) ) ;
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
F_12 ( L_48 ) ;
if ( V_14 -> V_2 . V_3 . V_4 . V_188 )
V_14 -> V_2 . V_3 . V_4 . V_188 ( & V_14 -> V_2 ) ;
else if ( ! V_14 -> V_115 && V_6 -> V_115 )
V_6 -> V_115 ( & V_14 -> V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_187 * V_24 )
{
struct V_20 * V_21 = F_54 ( V_24 ) ;
struct V_7 * V_14 = F_3 ( F_11 ( V_21 ) ) ;
F_12 ( L_49 ) ;
if ( V_14 -> V_2 . V_3 . V_4 . V_189 )
V_14 -> V_2 . V_3 . V_4 . V_189 ( & V_14 -> V_2 ) ;
else if ( ! V_14 -> V_115 )
if ( F_40 ( V_14 , V_14 -> V_92 ) == 0 )
F_41 ( V_14 , 0 ) ;
return 0 ;
}
static int F_56 ( struct V_20 * V_107 , unsigned V_26 , void * V_27 )
{
struct V_8 * V_9 = F_11 ( V_107 ) ;
switch ( V_26 ) {
case V_190 :
return F_21 ( V_9 , V_27 ) ;
}
return - V_191 ;
}
