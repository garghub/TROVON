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
V_14 -> V_126 [ V_127 ] . V_128 = V_129 ;
V_14 -> V_126 [ V_130 ] . V_128 = V_131 ;
V_14 -> V_9 . V_90 . V_132 = V_133 ;
V_14 -> V_9 . V_90 . V_84 = V_14 -> V_84 ;
V_110 = F_33 ( & V_14 -> V_9 . V_90 , V_134 , & V_14 -> V_126 [ 0 ] ) ;
if ( V_110 < 0 ) {
F_34 ( L_18 ) ;
F_31 ( V_14 ) ;
return - V_123 ;
}
#endif
if ( V_14 -> V_45 & V_106 )
V_14 -> V_92 = V_135 ;
else
V_14 -> V_92 = V_91 ;
F_9 ( V_107 , V_14 -> type , V_14 -> V_45 , V_14 -> V_34 , V_14 -> V_2 . V_35 ) ;
F_35 ( & V_14 -> V_136 , & V_137 ) ;
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
F_38 ( & V_14 -> V_136 ) ;
F_31 ( V_14 ) ;
return 0 ;
}
static inline int F_39 ( struct V_7 * V_14 , enum V_138 V_92 )
{
int V_139 ;
if ( V_92 == V_91 )
V_139 = V_46 ;
else
V_139 = V_106 ;
if ( ( V_139 & V_14 -> V_45 ) == 0 )
return - V_140 ;
return 0 ;
}
static int F_40 ( struct V_7 * V_14 , enum V_138 V_92 )
{
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_92 != V_14 -> V_92 ) {
if ( F_39 ( V_14 , V_92 ) == - V_140 ) {
F_12 ( L_23
L_24 , V_92 ) ;
V_14 -> V_115 = true ;
if ( V_6 -> V_115 )
V_6 -> V_115 ( & V_14 -> V_2 ) ;
return - V_140 ;
}
V_14 -> V_92 = V_92 ;
F_12 ( L_25 , V_92 ) ;
}
return 0 ;
}
static void F_41 ( struct V_7 * V_14 , unsigned int V_141 )
{
struct V_20 * V_107 = F_20 ( & V_14 -> V_9 ) ;
if ( V_14 -> V_92 == V_91 ) {
if ( ! V_141 )
V_141 = V_14 -> V_93 ;
F_17 ( V_107 , V_141 ) ;
} else {
if ( ! V_141 )
V_141 = V_14 -> V_94 ;
F_18 ( V_107 , V_141 ) ;
}
}
static void F_18 ( struct V_20 * V_21 , unsigned int V_141 )
{
struct V_7 * V_14 = F_3 ( F_11 ( V_21 ) ) ;
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_10 V_11 = {
. V_92 = V_14 -> V_92 ,
. V_113 = V_14 -> V_113 ,
. V_142 = V_14 -> V_142
} ;
if ( V_14 -> type == V_31 ) {
F_6 ( L_26 ) ;
return;
}
if ( NULL == V_6 -> V_83 ) {
F_6 ( L_27 ) ;
return;
}
if ( V_141 < V_143 [ 0 ] * 16 || V_141 > V_143 [ 1 ] * 16 ) {
F_12 ( L_28 ,
V_141 / 16 , V_141 % 16 * 100 / 16 , V_143 [ 0 ] ,
V_143 [ 1 ] ) ;
if ( V_141 < V_143 [ 0 ] * 16 )
V_141 = V_143 [ 0 ] * 16 ;
else
V_141 = V_143 [ 1 ] * 16 ;
}
V_11 . V_144 = V_141 ;
F_12 ( L_29 ,
V_141 / 16 , V_141 % 16 * 100 / 16 ) ;
V_14 -> V_94 = V_141 ;
V_14 -> V_115 = false ;
V_6 -> V_83 ( & V_14 -> V_2 , & V_11 ) ;
}
static T_1 F_42 ( struct V_7 * V_14 , T_1 V_142 )
{
if ( V_145 [ 0 ] != '-' && ( V_142 & V_146 ) == V_146 ) {
switch ( V_145 [ 0 ] ) {
case '6' :
return V_147 ;
case 'b' :
case 'B' :
case 'g' :
case 'G' :
return V_148 ;
case 'i' :
case 'I' :
return V_149 ;
case 'd' :
case 'D' :
case 'k' :
case 'K' :
return V_150 ;
case 'M' :
case 'm' :
return V_151 ;
case 'N' :
case 'n' :
if ( V_145 [ 1 ] == 'c' || V_145 [ 1 ] == 'C' )
return V_152 ;
return V_153 ;
default:
F_6 ( L_30 ) ;
break;
}
}
if ( V_154 [ 0 ] != '-' && ( V_142 & V_155 ) == V_155 ) {
switch ( V_154 [ 0 ] ) {
case 'b' :
case 'B' :
case 'g' :
case 'G' :
case 'h' :
case 'H' :
return V_156 |
V_157 |
V_158 ;
case 'd' :
case 'D' :
case 'k' :
case 'K' :
return V_159 ;
case 'l' :
case 'L' :
if ( ( V_154 [ 1 ] == 'C' ) || ( V_154 [ 1 ] == 'c' ) )
return V_160 ;
return V_161 ;
default:
F_6 ( L_31 ) ;
break;
}
}
if ( V_162 [ 0 ] != '-' && ( V_142 & V_163 ) == V_163 ) {
switch ( V_162 [ 0 ] ) {
case 'm' :
case 'M' :
return V_164 ;
case 'j' :
case 'J' :
return V_165 ;
case 'k' :
case 'K' :
return V_166 ;
default:
F_28 ( L_32 ) ;
break;
}
}
return V_142 ;
}
static void F_17 ( struct V_20 * V_21 , unsigned int V_141 )
{
struct V_7 * V_14 = F_3 ( F_11 ( V_21 ) ) ;
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_10 V_11 = {
. V_92 = V_14 -> V_92 ,
. V_113 = V_14 -> V_113 ,
. V_142 = V_14 -> V_142
} ;
if ( V_14 -> type == V_31 ) {
F_6 ( L_26 ) ;
return;
}
if ( NULL == V_6 -> V_83 ) {
F_6 ( L_33 ) ;
return;
}
if ( V_141 < V_167 [ 0 ] * 16000 || V_141 > V_167 [ 1 ] * 16000 ) {
F_12 ( L_34 ,
V_141 / 16000 , V_141 % 16000 * 100 / 16000 ,
V_167 [ 0 ] , V_167 [ 1 ] ) ;
if ( V_141 < V_167 [ 0 ] * 16000 )
V_141 = V_167 [ 0 ] * 16000 ;
else
V_141 = V_167 [ 1 ] * 16000 ;
}
V_11 . V_144 = V_141 ;
F_12 ( L_35 ,
V_141 / 16000 , V_141 % 16000 * 100 / 16000 ) ;
V_14 -> V_93 = V_141 ;
V_14 -> V_115 = false ;
V_6 -> V_83 ( & V_14 -> V_2 , & V_11 ) ;
V_14 -> V_113 = V_11 . V_113 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_7 * V_14 = V_2 -> V_15 ;
unsigned long V_141 , V_168 ;
struct V_12 * V_13 = & V_2 -> V_3 . V_4 ;
struct V_28 * V_6 = & V_2 -> V_3 . V_6 ;
const char * V_169 ;
switch ( V_14 -> V_92 ) {
case V_91 :
V_169 = L_36 ;
break;
case V_170 :
V_169 = L_37 ;
break;
case V_135 :
default:
V_169 = L_38 ;
break;
}
if ( V_14 -> V_92 == V_91 ) {
V_141 = V_14 -> V_93 / 16000 ;
V_168 = ( V_14 -> V_93 % 16000 ) * 100 / 16000 ;
} else {
V_141 = V_14 -> V_94 / 16 ;
V_168 = ( V_14 -> V_94 % 16 ) * 100 / 16 ;
}
F_28 ( L_39 , V_169 ,
V_14 -> V_115 ? L_40 : L_21 ) ;
F_28 ( L_41 , V_141 , V_168 ) ;
F_28 ( L_42 , ( unsigned long ) V_14 -> V_142 ) ;
if ( V_14 -> V_92 != V_91 )
return;
if ( V_13 -> V_171 ) {
T_2 F_43 ;
V_13 -> V_171 ( & V_14 -> V_2 , & F_43 ) ;
if ( F_43 & V_172 )
F_28 ( L_43 ) ;
if ( F_43 & V_173 )
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
static int F_45 ( struct V_8 * V_9 , int V_174 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_174 ) {
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
static int F_46 ( struct V_8 * V_9 , T_1 V_142 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_40 ( V_14 , V_135 ) )
return 0 ;
V_14 -> V_142 = F_42 ( V_14 , V_142 ) ;
if ( V_14 -> V_142 != V_142 )
F_12 ( L_47 , V_142 , V_14 -> V_142 ) ;
F_41 ( V_14 , 0 ) ;
return 0 ;
}
static int F_47 ( struct V_8 * V_9 , const struct V_175 * V_176 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_40 ( V_14 , V_176 -> type ) == 0 )
F_41 ( V_14 , V_176 -> V_144 ) ;
return 0 ;
}
static int F_48 ( struct V_8 * V_9 , struct V_175 * V_176 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_12 * V_13 = & V_14 -> V_2 . V_3 . V_4 ;
if ( F_39 ( V_14 , V_176 -> type ) == - V_140 )
return 0 ;
if ( V_176 -> type == V_14 -> V_92 && V_13 -> V_177 && ! V_14 -> V_115 ) {
T_2 V_178 ;
V_13 -> V_177 ( & V_14 -> V_2 , & V_178 ) ;
V_176 -> V_144 = ( V_91 == V_14 -> V_92 ) ?
F_49 ( V_178 * 2 , 125 ) :
F_49 ( V_178 , 62500 ) ;
} else {
V_176 -> V_144 = ( V_91 == V_176 -> type ) ?
V_14 -> V_93 : V_14 -> V_94 ;
}
return 0 ;
}
static int F_50 ( struct V_8 * V_9 , struct V_179 * V_180 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_12 * V_13 = & V_14 -> V_2 . V_3 . V_4 ;
if ( F_39 ( V_14 , V_180 -> type ) == - V_140 )
return 0 ;
if ( V_180 -> type == V_14 -> V_92 && V_6 -> V_89 )
V_6 -> V_89 ( & V_14 -> V_2 , & V_180 -> V_181 ) ;
if ( V_180 -> type == V_14 -> V_92 && V_6 -> V_88 ) {
T_3 signal = ( T_3 ) V_180 -> signal ;
if ( ! V_6 -> V_88 ( & V_14 -> V_2 , & signal ) )
V_180 -> signal = signal ;
}
if ( V_180 -> type != V_91 ) {
V_180 -> V_182 |= V_183 ;
V_180 -> V_184 = V_143 [ 0 ] * 16 ;
V_180 -> V_185 = V_143 [ 1 ] * 16 ;
return 0 ;
}
if ( V_180 -> type == V_14 -> V_92 ) {
V_180 -> V_186 = V_187 | V_188 ;
if ( V_13 -> V_171 ) {
T_2 F_43 ;
V_13 -> V_171 ( & V_14 -> V_2 , & F_43 ) ;
V_180 -> V_186 =
( F_43 & V_173 ) ?
V_188 :
V_187 ;
}
V_180 -> V_113 = V_14 -> V_113 ;
}
V_180 -> V_182 |= V_189 | V_190 ;
V_180 -> V_184 = V_167 [ 0 ] * 16000 ;
V_180 -> V_185 = V_167 [ 1 ] * 16000 ;
return 0 ;
}
static int F_51 ( struct V_8 * V_9 , const struct V_179 * V_180 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_40 ( V_14 , V_180 -> type ) )
return 0 ;
if ( V_14 -> V_92 == V_91 ) {
V_14 -> V_113 = V_180 -> V_113 ;
if ( V_14 -> V_113 != V_191 &&
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
static int F_53 ( struct V_192 * V_24 )
{
struct V_20 * V_21 = F_54 ( V_24 ) ;
struct V_7 * V_14 = F_3 ( F_11 ( V_21 ) ) ;
struct V_28 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
F_12 ( L_48 ) ;
if ( V_14 -> V_2 . V_3 . V_4 . V_193 )
V_14 -> V_2 . V_3 . V_4 . V_193 ( & V_14 -> V_2 ) ;
else if ( ! V_14 -> V_115 && V_6 -> V_115 )
V_6 -> V_115 ( & V_14 -> V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_192 * V_24 )
{
struct V_20 * V_21 = F_54 ( V_24 ) ;
struct V_7 * V_14 = F_3 ( F_11 ( V_21 ) ) ;
F_12 ( L_49 ) ;
if ( V_14 -> V_2 . V_3 . V_4 . V_194 )
V_14 -> V_2 . V_3 . V_4 . V_194 ( & V_14 -> V_2 ) ;
else if ( ! V_14 -> V_115 )
if ( F_40 ( V_14 , V_14 -> V_92 ) == 0 )
F_41 ( V_14 , 0 ) ;
return 0 ;
}
static int F_56 ( struct V_20 * V_107 , unsigned V_26 , void * V_27 )
{
struct V_8 * V_9 = F_11 ( V_107 ) ;
switch ( V_26 ) {
case V_195 :
return F_21 ( V_9 , V_27 ) ;
}
return - V_196 ;
}
