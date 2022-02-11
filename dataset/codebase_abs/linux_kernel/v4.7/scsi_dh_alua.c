static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( V_1 , struct V_2 , V_1 ) ;
if ( V_3 -> V_4 )
F_3 ( & V_3 -> V_5 ) ;
F_4 ( & V_6 ) ;
F_5 ( & V_3 -> V_7 ) ;
F_6 ( & V_6 ) ;
F_7 ( V_3 , V_8 ) ;
}
static int F_8 ( struct V_9 * V_10 , unsigned char * V_11 ,
int V_12 , struct V_13 * V_14 , int V_15 )
{
T_1 V_16 [ F_9 ( V_17 ) ] ;
int V_18 = V_19 | V_20 |
V_21 ;
memset ( V_16 , 0x0 , F_9 ( V_17 ) ) ;
V_16 [ 0 ] = V_17 ;
if ( ! ( V_15 & V_22 ) )
V_16 [ 1 ] = V_23 | V_24 ;
else
V_16 [ 1 ] = V_23 ;
F_10 ( V_12 , & V_16 [ 6 ] ) ;
return F_11 ( V_10 , V_16 , V_25 ,
V_11 , V_12 , V_14 ,
V_26 * V_27 ,
V_28 , NULL , V_18 ) ;
}
static int F_12 ( struct V_9 * V_10 , int V_29 ,
struct V_13 * V_14 )
{
T_1 V_16 [ F_9 ( V_30 ) ] ;
unsigned char V_31 [ 8 ] ;
int V_32 = 8 ;
int V_18 = V_19 | V_20 |
V_21 ;
memset ( V_31 , 0 , V_32 ) ;
V_31 [ 4 ] = V_33 ;
F_13 ( V_29 , & V_31 [ 6 ] ) ;
memset ( V_16 , 0x0 , F_9 ( V_30 ) ) ;
V_16 [ 0 ] = V_30 ;
V_16 [ 1 ] = V_34 ;
F_10 ( V_32 , & V_16 [ 6 ] ) ;
return F_11 ( V_10 , V_16 , V_35 ,
V_31 , V_32 ,
V_14 , V_26 * V_27 ,
V_28 , NULL , V_18 ) ;
}
static struct V_2 * F_14 ( char * V_36 , T_2 V_37 ,
int V_29 )
{
struct V_2 * V_3 ;
if ( ! V_36 || ! V_37 || ! strlen ( V_36 ) )
return NULL ;
F_15 (pg, &port_group_list, node) {
if ( V_3 -> V_29 != V_29 )
continue;
if ( ! V_3 -> V_38 || V_3 -> V_38 != V_37 )
continue;
if ( strncmp ( V_3 -> V_39 , V_36 , V_37 ) )
continue;
if ( ! F_16 ( & V_3 -> V_1 ) )
continue;
return V_3 ;
}
return NULL ;
}
static struct V_2 * F_17 ( struct V_9 * V_10 ,
int V_29 , int V_40 )
{
struct V_2 * V_3 , * V_41 ;
V_3 = F_18 ( sizeof( struct V_2 ) , V_42 ) ;
if ( ! V_3 )
return F_19 ( - V_43 ) ;
V_3 -> V_38 = F_20 ( V_10 , V_3 -> V_39 ,
sizeof( V_3 -> V_39 ) ) ;
if ( V_3 -> V_38 <= 0 ) {
F_21 ( V_44 , V_10 ,
L_1 ,
V_45 ) ;
V_3 -> V_39 [ 0 ] = '\0' ;
V_3 -> V_38 = 0 ;
}
V_3 -> V_29 = V_29 ;
V_3 -> V_40 = V_40 ;
V_3 -> V_46 = V_33 ;
if ( V_47 )
V_3 -> V_15 |= V_48 ;
F_22 ( & V_3 -> V_1 ) ;
F_23 ( & V_3 -> V_5 , V_49 ) ;
F_24 ( & V_3 -> V_50 ) ;
F_24 ( & V_3 -> V_7 ) ;
F_24 ( & V_3 -> V_51 ) ;
F_25 ( & V_3 -> V_52 ) ;
F_4 ( & V_6 ) ;
V_41 = F_14 ( V_3 -> V_39 , V_3 -> V_38 ,
V_29 ) ;
if ( V_41 ) {
F_6 ( & V_6 ) ;
F_26 ( V_3 ) ;
return V_41 ;
}
F_27 ( & V_3 -> V_7 , & V_53 ) ;
F_6 ( & V_6 ) ;
return V_3 ;
}
static int F_28 ( struct V_9 * V_10 )
{
int V_40 = V_54 ;
if ( V_10 -> type != V_55 ) {
F_21 ( V_44 , V_10 ,
L_2 ,
V_45 ) ;
return V_40 ;
}
V_40 = F_29 ( V_10 ) ;
switch ( V_40 ) {
case V_56 | V_57 :
F_21 ( V_44 , V_10 ,
L_3 ,
V_45 ) ;
break;
case V_56 :
F_21 ( V_44 , V_10 , L_4 ,
V_45 ) ;
break;
case V_57 :
F_21 ( V_44 , V_10 , L_5 ,
V_45 ) ;
break;
case V_54 :
F_21 ( V_44 , V_10 , L_6 ,
V_45 ) ;
break;
default:
F_21 ( V_44 , V_10 ,
L_7 ,
V_45 , V_40 ) ;
V_40 = V_54 ;
break;
}
return V_40 ;
}
static int F_30 ( struct V_9 * V_10 , struct V_58 * V_59 ,
int V_40 )
{
int V_60 = - 1 , V_29 ;
struct V_2 * V_3 , * V_61 = NULL ;
bool V_62 = false ;
unsigned long V_15 ;
V_29 = F_31 ( V_10 , & V_60 ) ;
if ( V_29 < 0 ) {
F_21 ( V_44 , V_10 ,
L_8 ,
V_45 ) ;
return V_63 ;
}
V_3 = F_17 ( V_10 , V_29 , V_40 ) ;
if ( F_32 ( V_3 ) ) {
if ( F_33 ( V_3 ) == - V_43 )
return V_64 ;
return V_63 ;
}
if ( V_3 -> V_38 )
F_21 ( V_44 , V_10 ,
L_9 ,
V_45 , V_3 -> V_39 ,
V_29 , V_60 ) ;
else
F_21 ( V_44 , V_10 ,
L_10 ,
V_45 , V_29 , V_60 ) ;
F_4 ( & V_59 -> V_65 ) ;
V_61 = V_59 -> V_3 ;
if ( V_61 != V_3 ) {
if ( V_59 -> V_3 ) {
F_34 ( & V_61 -> V_52 , V_15 ) ;
F_35 ( & V_59 -> V_7 ) ;
F_36 ( & V_61 -> V_52 , V_15 ) ;
}
F_37 ( V_59 -> V_3 , V_3 ) ;
V_62 = true ;
}
F_34 ( & V_3 -> V_52 , V_15 ) ;
if ( V_10 -> V_66 )
V_3 -> V_15 |= V_67 ;
if ( V_62 )
F_38 ( & V_59 -> V_7 , & V_3 -> V_51 ) ;
F_36 ( & V_3 -> V_52 , V_15 ) ;
F_39 ( V_59 -> V_3 , V_10 , NULL , true ) ;
F_6 ( & V_59 -> V_65 ) ;
if ( V_61 )
F_40 ( & V_61 -> V_1 , F_1 ) ;
return V_68 ;
}
static char F_41 ( unsigned char V_46 )
{
switch ( V_46 ) {
case V_33 :
return 'A' ;
case V_69 :
return 'N' ;
case V_70 :
return 'S' ;
case V_71 :
return 'U' ;
case V_72 :
return 'L' ;
case V_73 :
return 'O' ;
case V_74 :
return 'T' ;
default:
return 'X' ;
}
}
static int F_42 ( struct V_9 * V_10 ,
struct V_13 * V_75 )
{
switch ( V_75 -> V_76 ) {
case V_77 :
if ( V_75 -> V_78 == 0x04 && V_75 -> V_79 == 0x0a ) {
F_43 ( V_10 , false ) ;
return V_80 ;
}
break;
case V_81 :
if ( V_75 -> V_78 == 0x29 && V_75 -> V_79 == 0x00 ) {
F_43 ( V_10 , true ) ;
return V_82 ;
}
if ( V_75 -> V_78 == 0x29 && V_75 -> V_79 == 0x04 )
return V_82 ;
if ( V_75 -> V_78 == 0x2a && V_75 -> V_79 == 0x01 )
return V_82 ;
if ( V_75 -> V_78 == 0x2a && V_75 -> V_79 == 0x06 ) {
F_43 ( V_10 , true ) ;
return V_82 ;
}
if ( V_75 -> V_78 == 0x2a && V_75 -> V_79 == 0x07 ) {
F_43 ( V_10 , true ) ;
return V_82 ;
}
if ( V_75 -> V_78 == 0x3f && V_75 -> V_79 == 0x03 )
return V_82 ;
if ( V_75 -> V_78 == 0x3f && V_75 -> V_79 == 0x0e )
return V_82 ;
break;
}
return V_83 ;
}
static int F_44 ( struct V_9 * V_10 )
{
struct V_13 V_75 ;
int V_84 ;
V_84 = F_45 ( V_10 , V_26 * V_27 ,
V_28 , & V_75 ) ;
if ( V_75 . V_76 == V_77 &&
V_75 . V_78 == 0x04 && V_75 . V_79 == 0x0a )
return V_85 ;
else if ( V_84 )
return V_86 ;
else
return V_68 ;
}
static int F_46 ( struct V_9 * V_10 , struct V_2 * V_3 )
{
struct V_13 V_75 ;
struct V_2 * V_41 ;
int V_87 , V_88 , V_89 , V_90 = 0 , V_12 = V_91 ;
unsigned char * V_92 , * V_11 ;
unsigned V_93 , V_84 ;
unsigned int V_94 ;
unsigned char V_95 ;
unsigned long V_15 ;
if ( ! V_3 -> V_96 ) {
unsigned long V_97 = V_26 * V_27 ;
if ( V_3 -> V_97 )
V_97 = V_3 -> V_97 * V_27 ;
V_3 -> V_96 = F_47 ( V_98 + V_97 ) ;
}
V_11 = F_18 ( V_12 , V_42 ) ;
if ( ! V_11 )
return V_99 ;
V_100:
V_93 = 0 ;
V_84 = F_8 ( V_10 , V_11 , V_12 , & V_75 , V_3 -> V_15 ) ;
if ( V_84 ) {
if ( ! F_48 ( & V_75 ) ) {
F_21 ( V_44 , V_10 ,
L_11 ,
V_45 , V_84 ) ;
F_26 ( V_11 ) ;
if ( F_49 ( V_84 ) == V_101 )
return V_99 ;
return V_86 ;
}
if ( ! ( V_3 -> V_15 & V_22 ) &&
V_75 . V_76 == V_102 &&
V_75 . V_78 == 0x24 && V_75 . V_79 == 0 ) {
V_3 -> V_15 |= V_22 ;
goto V_100;
}
if ( V_75 . V_76 == V_77 &&
V_75 . V_78 == 0x04 && V_75 . V_79 == 0x0a )
V_93 = V_85 ;
else if ( V_75 . V_76 == V_81 )
V_93 = V_85 ;
if ( V_93 == V_85 &&
V_3 -> V_96 != 0 && F_50 ( V_98 , V_3 -> V_96 ) ) {
F_21 ( V_103 , V_10 , L_12 ,
V_45 ) ;
F_51 ( V_10 , V_45 , & V_75 ) ;
return V_93 ;
}
F_21 ( V_103 , V_10 , L_13 ,
V_45 ) ;
F_51 ( V_10 , V_45 , & V_75 ) ;
F_26 ( V_11 ) ;
V_3 -> V_96 = 0 ;
return V_86 ;
}
V_87 = F_52 ( & V_11 [ 0 ] ) + 4 ;
if ( V_87 > V_12 ) {
F_26 ( V_11 ) ;
V_12 = V_87 ;
V_11 = F_53 ( V_12 , V_42 ) ;
if ( ! V_11 ) {
F_21 ( V_104 , V_10 ,
L_14 , V_105 ) ;
V_3 -> V_96 = 0 ;
return V_99 ;
}
goto V_100;
}
V_95 = V_3 -> V_97 ;
if ( ( V_11 [ 4 ] & V_106 ) == V_107 && V_11 [ 5 ] != 0 )
V_3 -> V_97 = V_11 [ 5 ] ;
else
V_3 -> V_97 = V_26 ;
if ( V_95 != V_3 -> V_97 ) {
F_21 ( V_44 , V_10 ,
L_15 ,
V_45 , V_3 -> V_97 ) ;
V_3 -> V_96 = V_98 + V_3 -> V_97 * V_27 ;
}
if ( ( V_11 [ 4 ] & V_106 ) == V_107 )
V_94 = 8 ;
else
V_94 = 4 ;
for ( V_88 = V_94 , V_92 = V_11 + V_94 ;
V_88 < V_87 ;
V_88 += V_89 , V_92 += V_89 ) {
T_3 V_29 = F_54 ( & V_92 [ 2 ] ) ;
F_34 ( & V_6 , V_15 ) ;
V_41 = F_14 ( V_3 -> V_39 , V_3 -> V_38 ,
V_29 ) ;
F_36 ( & V_6 , V_15 ) ;
if ( V_41 ) {
if ( F_55 ( & V_41 -> V_52 , V_15 ) ) {
if ( ( V_41 == V_3 ) ||
! ( V_41 -> V_15 & V_108 ) ) {
struct V_58 * V_59 ;
V_41 -> V_46 = V_92 [ 0 ] & 0x0f ;
V_41 -> V_109 = V_92 [ 0 ] >> 7 ;
F_56 () ;
F_57 (h,
&tmp_pg->dh_list, node) {
F_58 ( ! V_59 -> V_10 ) ;
V_59 -> V_10 -> V_110 = V_92 [ 0 ] ;
}
F_59 () ;
}
if ( V_41 == V_3 )
V_90 = V_92 [ 1 ] ;
F_36 ( & V_41 -> V_52 , V_15 ) ;
}
F_40 ( & V_41 -> V_1 , F_1 ) ;
}
V_89 = 8 + ( V_92 [ 7 ] * 4 ) ;
}
F_34 ( & V_3 -> V_52 , V_15 ) ;
F_21 ( V_44 , V_10 ,
L_16 ,
V_45 , V_3 -> V_29 , F_41 ( V_3 -> V_46 ) ,
V_3 -> V_109 ? L_17 : L_18 ,
V_90 & V_111 ? 'T' : 't' ,
V_90 & V_112 ? 'O' : 'o' ,
V_90 & V_113 ? 'L' : 'l' ,
V_90 & V_114 ? 'U' : 'u' ,
V_90 & V_115 ? 'S' : 's' ,
V_90 & V_116 ? 'N' : 'n' ,
V_90 & V_117 ? 'A' : 'a' ) ;
switch ( V_3 -> V_46 ) {
case V_74 :
if ( F_50 ( V_98 , V_3 -> V_96 ) ) {
V_3 -> V_118 = 2 ;
V_93 = V_85 ;
} else {
struct V_58 * V_59 ;
V_93 = V_86 ;
V_3 -> V_46 = V_70 ;
V_3 -> V_96 = 0 ;
F_56 () ;
F_57 (h, &pg->dh_list, node) {
F_58 ( ! V_59 -> V_10 ) ;
V_59 -> V_10 -> V_110 =
( V_3 -> V_46 & V_119 ) ;
if ( V_3 -> V_109 )
V_59 -> V_10 -> V_110 |=
V_120 ;
}
F_59 () ;
}
break;
case V_73 :
V_93 = V_121 ;
V_3 -> V_96 = 0 ;
break;
default:
V_93 = V_68 ;
V_3 -> V_96 = 0 ;
break;
}
F_36 ( & V_3 -> V_52 , V_15 ) ;
F_26 ( V_11 ) ;
return V_93 ;
}
static unsigned F_60 ( struct V_9 * V_10 , struct V_2 * V_3 )
{
int V_84 ;
struct V_13 V_75 ;
if ( ! ( V_3 -> V_40 & V_56 ) ) {
return V_85 ;
}
switch ( V_3 -> V_46 ) {
case V_33 :
return V_68 ;
case V_69 :
if ( ( V_3 -> V_15 & V_48 ) &&
! V_3 -> V_109 &&
( V_3 -> V_40 & V_57 ) )
return V_68 ;
break;
case V_70 :
case V_71 :
break;
case V_73 :
return V_86 ;
case V_74 :
break;
default:
F_21 ( V_44 , V_10 ,
L_19 ,
V_45 , V_3 -> V_46 ) ;
return V_122 ;
}
V_84 = F_12 ( V_10 , V_3 -> V_29 , & V_75 ) ;
if ( V_84 ) {
if ( ! F_48 ( & V_75 ) ) {
F_21 ( V_44 , V_10 ,
L_20 ,
V_45 , V_84 ) ;
if ( F_49 ( V_84 ) == V_101 )
return V_99 ;
} else {
F_21 ( V_44 , V_10 , L_21 ,
V_45 ) ;
F_51 ( V_10 , V_45 , & V_75 ) ;
}
}
return V_85 ;
}
static void V_49 ( struct V_123 * V_124 )
{
struct V_2 * V_3 =
F_2 ( V_124 , struct V_2 , V_5 . V_124 ) ;
struct V_9 * V_10 ;
F_61 ( V_125 ) ;
int V_93 = V_68 ;
struct V_126 * V_127 , * V_128 ;
unsigned long V_15 ;
struct V_129 * V_130 = V_131 ;
F_34 ( & V_3 -> V_52 , V_15 ) ;
V_10 = V_3 -> V_4 ;
if ( ! V_10 ) {
F_62 ( V_3 -> V_15 & V_132 ) ;
F_62 ( V_3 -> V_15 & V_133 ) ;
F_36 ( & V_3 -> V_52 , V_15 ) ;
return;
}
if ( V_3 -> V_15 & V_67 )
V_130 = V_134 ;
V_3 -> V_15 |= V_108 ;
if ( V_3 -> V_15 & V_132 ) {
int V_46 = V_3 -> V_46 ;
V_3 -> V_15 &= ~ V_132 ;
F_36 ( & V_3 -> V_52 , V_15 ) ;
if ( V_46 == V_74 ) {
if ( F_44 ( V_10 ) == V_85 ) {
F_34 ( & V_3 -> V_52 , V_15 ) ;
V_3 -> V_15 &= ~ V_108 ;
V_3 -> V_15 |= V_132 ;
F_36 ( & V_3 -> V_52 , V_15 ) ;
F_63 ( V_130 , & V_3 -> V_5 ,
V_3 -> V_118 * V_27 ) ;
return;
}
}
V_93 = F_46 ( V_10 , V_3 ) ;
F_34 ( & V_3 -> V_52 , V_15 ) ;
if ( V_93 == V_85 || V_3 -> V_15 & V_132 ) {
V_3 -> V_15 &= ~ V_108 ;
V_3 -> V_15 |= V_132 ;
F_36 ( & V_3 -> V_52 , V_15 ) ;
F_63 ( V_130 , & V_3 -> V_5 ,
V_3 -> V_118 * V_27 ) ;
return;
}
if ( V_93 != V_68 )
V_3 -> V_15 &= ~ V_133 ;
}
if ( V_3 -> V_15 & V_133 ) {
V_3 -> V_15 &= ~ V_133 ;
F_36 ( & V_3 -> V_52 , V_15 ) ;
V_93 = F_60 ( V_10 , V_3 ) ;
F_34 ( & V_3 -> V_52 , V_15 ) ;
if ( V_93 == V_85 || V_3 -> V_15 & V_132 ) {
V_3 -> V_15 |= V_132 ;
V_3 -> V_118 = 0 ;
V_3 -> V_15 &= ~ V_108 ;
F_36 ( & V_3 -> V_52 , V_15 ) ;
F_63 ( V_130 , & V_3 -> V_5 ,
V_3 -> V_118 * V_27 ) ;
return;
}
}
F_64 ( & V_3 -> V_50 , & V_125 ) ;
V_3 -> V_4 = NULL ;
F_36 ( & V_3 -> V_52 , V_15 ) ;
F_65 (qdata, tmp, &qdata_list, entry) {
F_5 ( & V_127 -> V_135 ) ;
if ( V_127 -> V_136 )
V_127 -> V_136 ( V_127 -> V_137 , V_93 ) ;
F_26 ( V_127 ) ;
}
F_34 ( & V_3 -> V_52 , V_15 ) ;
V_3 -> V_15 &= ~ V_108 ;
F_36 ( & V_3 -> V_52 , V_15 ) ;
F_66 ( V_10 ) ;
F_40 ( & V_3 -> V_1 , F_1 ) ;
}
static void F_39 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
struct V_126 * V_127 , bool V_138 )
{
int V_139 = 0 ;
unsigned long V_15 ;
struct V_129 * V_130 = V_131 ;
if ( ! V_3 )
return;
F_34 ( & V_3 -> V_52 , V_15 ) ;
if ( V_127 ) {
F_67 ( & V_127 -> V_135 , & V_3 -> V_50 ) ;
V_3 -> V_15 |= V_133 ;
V_138 = true ;
}
if ( V_3 -> V_4 == NULL ) {
V_3 -> V_118 = 0 ;
V_3 -> V_15 |= V_132 ;
F_68 ( & V_3 -> V_1 ) ;
V_3 -> V_4 = V_10 ;
F_69 ( V_10 ) ;
V_139 = 1 ;
} else if ( ! ( V_3 -> V_15 & V_132 ) && V_138 ) {
V_3 -> V_15 |= V_132 ;
if ( ! ( V_3 -> V_15 & V_108 ) ) {
F_68 ( & V_3 -> V_1 ) ;
V_139 = 1 ;
}
}
if ( V_3 -> V_15 & V_67 )
V_130 = V_134 ;
F_36 ( & V_3 -> V_52 , V_15 ) ;
if ( V_139 &&
! F_63 ( V_130 , & V_3 -> V_5 ,
F_70 ( V_140 ) ) ) {
F_66 ( V_10 ) ;
F_40 ( & V_3 -> V_1 , F_1 ) ;
}
}
static int F_71 ( struct V_9 * V_10 , struct V_58 * V_59 )
{
int V_93 = V_63 , V_40 ;
F_72 ( & V_59 -> V_141 ) ;
V_40 = F_28 ( V_10 ) ;
if ( V_40 != V_54 )
V_93 = F_30 ( V_10 , V_59 , V_40 ) ;
V_59 -> V_142 = V_93 ;
F_73 ( & V_59 -> V_141 ) ;
return V_93 ;
}
static int F_74 ( struct V_9 * V_10 , const char * V_143 )
{
struct V_58 * V_59 = V_10 -> V_144 ;
struct V_2 T_4 * V_3 = NULL ;
unsigned int V_145 = 0 , V_146 ;
const char * V_147 = V_143 ;
int V_148 = V_68 ;
unsigned long V_15 ;
if ( ( sscanf ( V_143 , L_22 , & V_146 ) != 1 ) || ( V_146 != 1 ) )
return - V_149 ;
while ( * V_147 ++ )
;
if ( ( sscanf ( V_147 , L_22 , & V_145 ) != 1 ) || ( V_145 > 1 ) )
return - V_149 ;
F_56 () ;
V_3 = F_75 ( V_59 -> V_3 ) ;
if ( ! V_3 ) {
F_59 () ;
return - V_150 ;
}
F_34 ( & V_3 -> V_52 , V_15 ) ;
if ( V_145 )
V_3 -> V_15 |= V_48 ;
else
V_3 -> V_15 &= ~ V_48 ;
F_36 ( & V_3 -> V_52 , V_15 ) ;
F_59 () ;
return V_148 ;
}
static int F_76 ( struct V_9 * V_10 ,
T_5 V_151 , void * V_152 )
{
struct V_58 * V_59 = V_10 -> V_144 ;
int V_93 = V_68 ;
struct V_126 * V_127 ;
struct V_2 T_4 * V_3 ;
V_127 = F_18 ( sizeof( * V_127 ) , V_42 ) ;
if ( ! V_127 ) {
V_93 = V_153 ;
goto V_154;
}
V_127 -> V_136 = V_151 ;
V_127 -> V_137 = V_152 ;
F_72 ( & V_59 -> V_141 ) ;
F_56 () ;
V_3 = F_75 ( V_59 -> V_3 ) ;
if ( ! V_3 || ! F_16 ( & V_3 -> V_1 ) ) {
F_59 () ;
F_26 ( V_127 ) ;
V_93 = V_59 -> V_142 ;
F_73 ( & V_59 -> V_141 ) ;
goto V_154;
}
V_151 = NULL ;
F_59 () ;
F_73 ( & V_59 -> V_141 ) ;
F_39 ( V_3 , V_10 , V_127 , true ) ;
F_40 ( & V_3 -> V_1 , F_1 ) ;
V_154:
if ( V_151 )
V_151 ( V_152 , V_93 ) ;
return 0 ;
}
static void F_43 ( struct V_9 * V_10 , bool V_138 )
{
struct V_58 * V_59 = V_10 -> V_144 ;
struct V_2 * V_3 ;
F_56 () ;
V_3 = F_75 ( V_59 -> V_3 ) ;
if ( ! V_3 || ! F_16 ( & V_3 -> V_1 ) ) {
F_59 () ;
return;
}
F_59 () ;
F_39 ( V_3 , V_10 , NULL , V_138 ) ;
F_40 ( & V_3 -> V_1 , F_1 ) ;
}
static int F_77 ( struct V_9 * V_10 , struct V_155 * V_156 )
{
struct V_58 * V_59 = V_10 -> V_144 ;
struct V_2 T_4 * V_3 ;
unsigned char V_46 = V_33 ;
int V_157 = V_158 ;
F_56 () ;
V_3 = F_75 ( V_59 -> V_3 ) ;
if ( V_3 )
V_46 = V_3 -> V_46 ;
F_59 () ;
if ( V_46 == V_74 )
V_157 = V_159 ;
else if ( V_46 != V_33 &&
V_46 != V_69 &&
V_46 != V_72 ) {
V_157 = V_160 ;
V_156 -> V_161 |= V_162 ;
}
return V_157 ;
}
static void F_78 ( struct V_9 * V_10 )
{
struct V_58 * V_59 = V_10 -> V_144 ;
F_71 ( V_10 , V_59 ) ;
}
static int F_79 ( struct V_9 * V_10 )
{
struct V_58 * V_59 ;
int V_93 , V_157 = - V_149 ;
V_59 = F_18 ( sizeof( * V_59 ) , V_42 ) ;
if ( ! V_59 )
return - V_43 ;
F_25 ( & V_59 -> V_65 ) ;
F_37 ( V_59 -> V_3 , NULL ) ;
V_59 -> V_142 = V_68 ;
V_59 -> V_10 = V_10 ;
F_24 ( & V_59 -> V_7 ) ;
F_80 ( & V_59 -> V_141 ) ;
V_93 = F_71 ( V_10 , V_59 ) ;
if ( V_93 == V_64 )
V_157 = - V_43 ;
if ( V_93 != V_68 && V_93 != V_121 )
goto V_163;
V_10 -> V_144 = V_59 ;
return 0 ;
V_163:
F_26 ( V_59 ) ;
return V_157 ;
}
static void F_81 ( struct V_9 * V_10 )
{
struct V_58 * V_59 = V_10 -> V_144 ;
struct V_2 * V_3 ;
F_4 ( & V_59 -> V_65 ) ;
V_3 = V_59 -> V_3 ;
F_37 ( V_59 -> V_3 , NULL ) ;
V_59 -> V_10 = NULL ;
F_6 ( & V_59 -> V_65 ) ;
if ( V_3 ) {
F_82 ( & V_3 -> V_52 ) ;
F_35 ( & V_59 -> V_7 ) ;
F_83 ( & V_3 -> V_52 ) ;
F_40 ( & V_3 -> V_1 , F_1 ) ;
}
V_10 -> V_144 = NULL ;
F_26 ( V_59 ) ;
}
static int T_6 F_84 ( void )
{
int V_164 ;
V_131 = F_85 ( L_23 , V_165 , 0 ) ;
if ( ! V_131 ) {
return V_99 ;
}
V_134 = F_86 ( L_24 ) ;
if ( ! V_134 ) {
F_87 ( V_131 ) ;
return V_99 ;
}
V_164 = F_88 ( & V_166 ) ;
if ( V_164 != 0 ) {
F_89 ( V_103 L_25 ,
V_45 ) ;
F_87 ( V_134 ) ;
F_87 ( V_131 ) ;
}
return V_164 ;
}
static void T_7 F_90 ( void )
{
F_91 ( & V_166 ) ;
F_87 ( V_134 ) ;
F_87 ( V_131 ) ;
}
