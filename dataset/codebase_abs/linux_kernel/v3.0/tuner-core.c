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
default:
if ( ! F_14 ( V_55 , & V_14 -> V_2 ,
V_14 -> V_40 -> V_41 , V_14 -> V_40 -> V_35 , V_14 -> type ) )
goto V_42;
break;
}
if ( ( NULL == V_6 -> V_75 ) &&
( V_13 -> V_16 ) ) {
V_14 -> V_76 = V_13 -> V_77 . V_76 ;
V_14 -> V_2 . V_15 = V_14 ;
memcpy ( V_6 , & V_78 ,
sizeof( struct V_30 ) ) ;
} else {
V_14 -> V_76 = V_6 -> V_77 . V_76 ;
}
F_13 ( L_5 , V_14 -> V_76 ) ;
V_14 -> V_50 = V_24 ;
if ( V_32 ) {
if ( V_79 == V_14 -> V_80 )
F_17 ( V_23 , V_14 -> V_81 ) ;
else
F_18 ( V_23 , V_14 -> V_82 ) ;
}
F_13 ( L_6 ,
V_23 -> V_41 -> V_76 , V_23 -> V_83 -> V_83 . V_76 , V_23 -> V_35 << 1 , type ,
V_14 -> V_50 ) ;
return;
V_42:
F_13 ( L_7 , V_14 -> type ) ;
V_14 -> type = V_34 ;
return;
}
static int F_19 ( struct V_8 * V_9 ,
struct V_84 * V_85 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_22 * V_23 = F_20 ( V_9 ) ;
F_13 ( L_8 ,
V_85 -> type ,
V_85 -> V_35 ,
V_85 -> V_50 ,
V_85 -> V_36 ) ;
if ( ( V_14 -> type == V_33 && ( ( V_85 -> V_35 == V_86 ) &&
( V_14 -> V_50 & V_85 -> V_50 ) ) ) ||
( V_85 -> V_35 == V_23 -> V_35 ) ) {
F_10 ( V_23 , V_85 -> type , V_85 -> V_50 ,
V_85 -> V_36 , V_85 -> F_11 ) ;
} else
F_13 ( L_9
L_10 ,
V_14 -> type , V_14 -> V_50 ,
V_85 -> V_35 , V_85 -> V_50 ) ;
return 0 ;
}
static int F_21 ( struct V_8 * V_9 ,
const struct V_87 * V_45 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_14 -> type != V_45 -> V_7 )
return 0 ;
if ( V_6 -> V_21 ) {
V_6 -> V_21 ( & V_14 -> V_2 , V_45 -> V_88 ) ;
return 0 ;
}
F_13 ( L_2 ) ;
return 0 ;
}
static void F_22 ( struct V_89 * V_90 ,
struct V_7 * * V_91 , struct V_7 * * V_92 )
{
struct V_7 * V_93 ;
* V_91 = NULL ;
* V_92 = NULL ;
F_23 (pos, &tuner_list, list) {
int V_50 ;
if ( V_93 -> V_40 -> V_41 != V_90 ||
strcmp ( V_93 -> V_40 -> V_83 -> V_83 . V_76 , L_11 ) )
continue;
V_50 = V_93 -> V_50 ;
if ( * V_91 == NULL && V_50 == V_51 )
* V_91 = V_93 ;
else if ( * V_92 == NULL && V_93 -> type != V_62 &&
( V_93 -> V_50 & V_94 ) )
* V_92 = V_93 ;
}
}
static int F_24 ( struct V_22 * V_95 ,
const struct V_96 * V_97 )
{
struct V_7 * V_14 ;
struct V_7 * V_91 ;
struct V_7 * V_92 ;
V_14 = F_25 ( sizeof( struct V_7 ) , V_98 ) ;
if ( NULL == V_14 )
return - V_99 ;
F_26 ( & V_14 -> V_9 , V_95 , & V_4 ) ;
V_14 -> V_40 = V_95 ;
V_14 -> V_76 = L_12 ;
V_14 -> type = V_33 ;
V_14 -> V_100 = V_101 ;
V_14 -> V_102 = 1 ;
V_14 -> V_81 = 87.5 * 16000 ;
V_14 -> V_82 = 400 * 16 ;
if ( V_103 ) {
unsigned char V_31 [ 16 ] ;
int V_104 , V_105 ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
V_105 = F_27 ( V_95 , V_31 , sizeof( V_31 ) ) ;
F_28 ( L_13 ) ;
for ( V_104 = 0 ; V_104 < V_105 ; V_104 ++ )
F_29 ( V_106 L_14 , V_31 [ V_104 ] ) ;
F_29 ( L_15 ) ;
}
if ( ! V_107 ) {
switch ( V_95 -> V_35 ) {
case 0x10 :
if ( F_30 ( V_108 ,
V_14 -> V_40 -> V_41 ,
V_14 -> V_40 -> V_35 ) >= 0 ) {
V_14 -> type = V_52 ;
V_14 -> V_50 = V_51 ;
F_22 ( V_14 -> V_40 -> V_41 , & V_91 , & V_92 ) ;
if ( V_92 )
V_92 -> V_50 &= ~ V_51 ;
goto V_109;
}
F_31 ( V_14 ) ;
return - V_110 ;
case 0x42 :
case 0x43 :
case 0x4a :
case 0x4b :
if ( F_30 ( V_111 , V_14 -> V_40 -> V_41 ,
V_14 -> V_40 -> V_35 ) >= 0 ) {
F_13 ( L_16 ) ;
} else {
V_14 -> type = V_62 ;
V_14 -> V_50 = V_51 | V_94 ;
goto V_109;
}
break;
case 0x60 :
if ( F_30 ( V_112 ,
V_14 -> V_40 -> V_41 , V_14 -> V_40 -> V_35 )
>= 0 ) {
V_14 -> type = V_48 ;
V_14 -> V_50 = V_51 ;
F_22 ( V_14 -> V_40 -> V_41 , & V_91 , & V_92 ) ;
if ( V_92 )
V_92 -> V_50 &= ~ V_51 ;
goto V_109;
}
break;
}
}
F_22 ( V_14 -> V_40 -> V_41 , & V_91 , & V_92 ) ;
if ( V_92 == NULL ) {
V_14 -> V_50 = V_94 ;
if ( V_91 == NULL )
V_14 -> V_50 |= V_51 ;
F_13 ( L_17 , V_14 -> V_50 ) ;
}
V_109:
if ( V_14 -> V_50 & V_94 )
V_14 -> V_80 = V_113 ;
else
V_14 -> V_80 = V_79 ;
F_10 ( V_95 , V_14 -> type , V_14 -> V_50 , V_14 -> V_36 , V_14 -> V_2 . V_37 ) ;
F_32 ( & V_14 -> V_114 , & V_115 ) ;
F_28 ( L_18 ,
V_14 -> type ,
V_14 -> V_50 & V_51 ? L_19 : L_20 ,
V_14 -> V_50 & V_94 ? L_21 : L_20 ) ;
return 0 ;
}
static int F_33 ( struct V_22 * V_95 )
{
struct V_7 * V_14 = F_3 ( F_12 ( V_95 ) ) ;
F_34 ( & V_14 -> V_9 ) ;
F_1 ( & V_14 -> V_2 ) ;
V_14 -> V_2 . V_15 = NULL ;
F_35 ( & V_14 -> V_114 ) ;
F_31 ( V_14 ) ;
return 0 ;
}
static inline int F_36 ( struct V_7 * V_14 , enum V_116 V_80 )
{
int V_117 ;
if ( V_80 == V_79 )
V_117 = V_51 ;
else
V_117 = V_94 ;
if ( ( V_117 & V_14 -> V_50 ) == 0 )
return - V_118 ;
return 0 ;
}
static int F_37 ( struct V_7 * V_14 , enum V_116 V_80 )
{
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_80 != V_14 -> V_80 ) {
if ( F_36 ( V_14 , V_80 ) == - V_118 ) {
F_13 ( L_22
L_23 , V_80 ) ;
V_14 -> V_102 = true ;
if ( V_6 -> V_102 )
V_6 -> V_102 ( & V_14 -> V_2 ) ;
return - V_118 ;
}
V_14 -> V_80 = V_80 ;
F_13 ( L_24 , V_80 ) ;
}
return 0 ;
}
static void F_38 ( struct V_7 * V_14 , unsigned int V_119 )
{
struct V_22 * V_95 = F_20 ( & V_14 -> V_9 ) ;
if ( V_14 -> V_80 == V_79 ) {
if ( ! V_119 )
V_119 = V_14 -> V_81 ;
F_17 ( V_95 , V_119 ) ;
} else {
if ( ! V_119 )
V_119 = V_14 -> V_82 ;
F_18 ( V_95 , V_119 ) ;
}
}
static void F_18 ( struct V_22 * V_23 , unsigned int V_119 )
{
struct V_7 * V_14 = F_3 ( F_12 ( V_23 ) ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_10 V_11 = {
. V_80 = V_14 -> V_80 ,
. V_100 = V_14 -> V_100 ,
. V_120 = V_14 -> V_120
} ;
if ( V_14 -> type == V_33 ) {
F_6 ( L_25 ) ;
return;
}
if ( NULL == V_6 -> V_75 ) {
F_6 ( L_26 ) ;
return;
}
if ( V_119 < V_121 [ 0 ] * 16 || V_119 > V_121 [ 1 ] * 16 ) {
F_13 ( L_27 ,
V_119 / 16 , V_119 % 16 * 100 / 16 , V_121 [ 0 ] ,
V_121 [ 1 ] ) ;
if ( V_119 < V_121 [ 0 ] * 16 )
V_119 = V_121 [ 0 ] * 16 ;
else
V_119 = V_121 [ 1 ] * 16 ;
}
V_11 . V_122 = V_119 ;
F_13 ( L_28 ,
V_119 / 16 , V_119 % 16 * 100 / 16 ) ;
V_14 -> V_82 = V_119 ;
V_14 -> V_102 = false ;
V_6 -> V_75 ( & V_14 -> V_2 , & V_11 ) ;
}
static T_2 F_39 ( struct V_7 * V_14 , T_2 V_120 )
{
if ( V_123 [ 0 ] != '-' && ( V_120 & V_124 ) == V_124 ) {
switch ( V_123 [ 0 ] ) {
case '6' :
return V_125 ;
case 'b' :
case 'B' :
case 'g' :
case 'G' :
return V_126 ;
case 'i' :
case 'I' :
return V_127 ;
case 'd' :
case 'D' :
case 'k' :
case 'K' :
return V_128 ;
case 'M' :
case 'm' :
return V_129 ;
case 'N' :
case 'n' :
if ( V_123 [ 1 ] == 'c' || V_123 [ 1 ] == 'C' )
return V_130 ;
return V_131 ;
default:
F_6 ( L_29 ) ;
break;
}
}
if ( V_132 [ 0 ] != '-' && ( V_120 & V_133 ) == V_133 ) {
switch ( V_132 [ 0 ] ) {
case 'b' :
case 'B' :
case 'g' :
case 'G' :
case 'h' :
case 'H' :
return V_134 |
V_135 |
V_136 ;
case 'd' :
case 'D' :
case 'k' :
case 'K' :
return V_137 ;
case 'l' :
case 'L' :
if ( ( V_132 [ 1 ] == 'C' ) || ( V_132 [ 1 ] == 'c' ) )
return V_138 ;
return V_139 ;
default:
F_6 ( L_30 ) ;
break;
}
}
if ( V_140 [ 0 ] != '-' && ( V_120 & V_141 ) == V_141 ) {
switch ( V_140 [ 0 ] ) {
case 'm' :
case 'M' :
return V_142 ;
case 'j' :
case 'J' :
return V_143 ;
case 'k' :
case 'K' :
return V_144 ;
default:
F_28 ( L_31 ) ;
break;
}
}
return V_120 ;
}
static void F_17 ( struct V_22 * V_23 , unsigned int V_119 )
{
struct V_7 * V_14 = F_3 ( F_12 ( V_23 ) ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_10 V_11 = {
. V_80 = V_14 -> V_80 ,
. V_100 = V_14 -> V_100 ,
. V_120 = V_14 -> V_120
} ;
if ( V_14 -> type == V_33 ) {
F_6 ( L_25 ) ;
return;
}
if ( NULL == V_6 -> V_75 ) {
F_6 ( L_32 ) ;
return;
}
if ( V_119 < V_145 [ 0 ] * 16000 || V_119 > V_145 [ 1 ] * 16000 ) {
F_13 ( L_33 ,
V_119 / 16000 , V_119 % 16000 * 100 / 16000 ,
V_145 [ 0 ] , V_145 [ 1 ] ) ;
if ( V_119 < V_145 [ 0 ] * 16000 )
V_119 = V_145 [ 0 ] * 16000 ;
else
V_119 = V_145 [ 1 ] * 16000 ;
}
V_11 . V_122 = V_119 ;
F_13 ( L_34 ,
V_119 / 16000 , V_119 % 16000 * 100 / 16000 ) ;
V_14 -> V_81 = V_119 ;
V_14 -> V_102 = false ;
V_6 -> V_75 ( & V_14 -> V_2 , & V_11 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_7 * V_14 = V_2 -> V_15 ;
unsigned long V_119 , V_146 ;
struct V_12 * V_13 = & V_2 -> V_3 . V_4 ;
struct V_30 * V_6 = & V_2 -> V_3 . V_6 ;
const char * V_147 ;
switch ( V_14 -> V_80 ) {
case V_79 :
V_147 = L_35 ;
break;
case V_148 :
V_147 = L_36 ;
break;
case V_113 :
default:
V_147 = L_37 ;
break;
}
if ( V_14 -> V_80 == V_79 ) {
V_119 = V_14 -> V_81 / 16000 ;
V_146 = ( V_14 -> V_81 % 16000 ) * 100 / 16000 ;
} else {
V_119 = V_14 -> V_82 / 16 ;
V_146 = ( V_14 -> V_82 % 16 ) * 100 / 16 ;
}
F_28 ( L_38 , V_147 ,
V_14 -> V_102 ? L_39 : L_20 ) ;
F_28 ( L_40 , V_119 , V_146 ) ;
F_28 ( L_41 , ( unsigned long ) V_14 -> V_120 ) ;
if ( V_14 -> V_80 != V_79 )
return;
if ( V_13 -> V_149 ) {
T_3 F_40 ;
V_13 -> V_149 ( & V_14 -> V_2 , & F_40 ) ;
if ( F_40 & V_150 )
F_28 ( L_42 ) ;
if ( F_40 & V_151 )
F_28 ( L_43 ) ;
}
if ( V_6 -> V_152 )
F_28 ( L_44 ,
V_6 -> V_152 ( V_2 ) ) ;
}
static int F_41 ( struct V_8 * V_9 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_37 ( V_14 , V_79 ) == 0 )
F_38 ( V_14 , 0 ) ;
return 0 ;
}
static int F_42 ( struct V_8 * V_9 , int V_153 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
if ( V_153 ) {
if ( V_14 -> V_102 && F_37 ( V_14 , V_14 -> V_80 ) == 0 ) {
F_13 ( L_45 ) ;
F_38 ( V_14 , 0 ) ;
}
return 0 ;
}
F_13 ( L_23 ) ;
V_14 -> V_102 = true ;
if ( V_6 -> V_102 )
V_6 -> V_102 ( & V_14 -> V_2 ) ;
return 0 ;
}
static int F_43 ( struct V_8 * V_9 , T_2 V_120 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_37 ( V_14 , V_113 ) )
return 0 ;
V_14 -> V_120 = F_39 ( V_14 , V_120 ) ;
if ( V_14 -> V_120 != V_120 )
F_13 ( L_46 , V_120 , V_14 -> V_120 ) ;
F_38 ( V_14 , 0 ) ;
return 0 ;
}
static int F_44 ( struct V_8 * V_9 , struct V_154 * V_155 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_37 ( V_14 , V_155 -> type ) == 0 )
F_38 ( V_14 , V_155 -> V_122 ) ;
return 0 ;
}
static int F_45 ( struct V_8 * V_9 , struct V_154 * V_155 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_12 * V_13 = & V_14 -> V_2 . V_3 . V_4 ;
if ( F_36 ( V_14 , V_155 -> type ) == - V_118 )
return 0 ;
if ( V_155 -> type == V_14 -> V_80 && V_13 -> V_156 && ! V_14 -> V_102 ) {
T_3 V_157 ;
V_13 -> V_156 ( & V_14 -> V_2 , & V_157 ) ;
V_155 -> V_122 = ( V_79 == V_14 -> V_80 ) ?
F_46 ( V_157 * 2 , 125 ) :
F_46 ( V_157 , 62500 ) ;
} else {
V_155 -> V_122 = ( V_79 == V_155 -> type ) ?
V_14 -> V_81 : V_14 -> V_82 ;
}
return 0 ;
}
static int F_47 ( struct V_8 * V_9 , struct V_158 * V_159 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
struct V_12 * V_13 = & V_14 -> V_2 . V_3 . V_4 ;
if ( F_36 ( V_14 , V_159 -> type ) == - V_118 )
return 0 ;
if ( V_159 -> type == V_14 -> V_80 && V_6 -> V_160 )
V_159 -> V_161 = V_6 -> V_160 ( & V_14 -> V_2 ) ;
if ( V_14 -> V_80 != V_79 ) {
V_159 -> V_162 |= V_163 ;
V_159 -> V_164 = V_121 [ 0 ] * 16 ;
V_159 -> V_165 = V_121 [ 1 ] * 16 ;
return 0 ;
}
if ( V_159 -> type == V_14 -> V_80 ) {
V_159 -> V_166 = V_167 | V_168 ;
if ( V_13 -> V_149 ) {
T_3 F_40 ;
V_13 -> V_149 ( & V_14 -> V_2 , & F_40 ) ;
V_159 -> V_166 =
( F_40 & V_151 ) ?
V_168 :
V_167 ;
}
if ( V_6 -> V_152 )
V_159 -> signal = V_6 -> V_152 ( & V_14 -> V_2 ) ;
V_159 -> V_100 = V_14 -> V_100 ;
}
V_159 -> V_162 |= V_169 | V_170 ;
V_159 -> V_164 = V_145 [ 0 ] * 16000 ;
V_159 -> V_165 = V_145 [ 1 ] * 16000 ;
return 0 ;
}
static int F_48 ( struct V_8 * V_9 , struct V_158 * V_159 )
{
struct V_7 * V_14 = F_3 ( V_9 ) ;
if ( F_37 ( V_14 , V_159 -> type ) )
return 0 ;
if ( V_14 -> V_80 == V_79 )
V_14 -> V_100 = V_159 -> V_100 ;
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
static int F_50 ( struct V_22 * V_23 , T_4 V_171 )
{
struct V_7 * V_14 = F_3 ( F_12 ( V_23 ) ) ;
struct V_30 * V_6 = & V_14 -> V_2 . V_3 . V_6 ;
F_13 ( L_47 ) ;
if ( ! V_14 -> V_102 && V_6 -> V_102 )
V_6 -> V_102 ( & V_14 -> V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_22 * V_23 )
{
struct V_7 * V_14 = F_3 ( F_12 ( V_23 ) ) ;
F_13 ( L_48 ) ;
if ( ! V_14 -> V_102 )
if ( F_37 ( V_14 , V_14 -> V_80 ) == 0 )
F_38 ( V_14 , 0 ) ;
return 0 ;
}
static int F_52 ( struct V_22 * V_95 , unsigned V_28 , void * V_29 )
{
struct V_8 * V_9 = F_12 ( V_95 ) ;
switch ( V_28 ) {
case V_172 :
return F_21 ( V_9 , V_29 ) ;
}
return - V_173 ;
}
static T_5 int F_53 ( void )
{
return F_54 ( & V_174 ) ;
}
static T_6 void F_55 ( void )
{
F_56 ( & V_174 ) ;
}
