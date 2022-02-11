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
struct V_2 * F_14 ( char * V_36 , T_2 V_37 ,
int V_29 )
{
struct V_2 * V_3 ;
F_15 (pg, &port_group_list, node) {
if ( V_3 -> V_29 != V_29 )
continue;
if ( V_3 -> V_38 != V_37 )
continue;
if ( strncmp ( V_3 -> V_39 , V_36 , V_37 ) )
continue;
if ( ! F_16 ( & V_3 -> V_1 ) )
continue;
return V_3 ;
}
return NULL ;
}
struct V_2 * F_17 ( struct V_9 * V_10 ,
int V_29 , int V_40 )
{
struct V_2 * V_3 , * V_41 ;
V_3 = F_18 ( sizeof( struct V_2 ) , V_42 ) ;
if ( ! V_3 )
return F_19 ( - V_43 ) ;
V_3 -> V_38 = F_20 ( V_10 , V_3 -> V_39 ,
sizeof( V_3 -> V_39 ) ) ;
if ( V_3 -> V_38 <= 0 ) {
F_21 ( V_3 ) ;
F_22 ( V_44 , V_10 ,
L_1 ,
V_45 ) ;
return F_19 ( - V_46 ) ;
}
V_3 -> V_29 = V_29 ;
V_3 -> V_40 = V_40 ;
V_3 -> V_47 = V_33 ;
if ( V_48 )
V_3 -> V_15 |= V_49 ;
F_23 ( & V_3 -> V_1 ) ;
F_24 ( & V_3 -> V_5 , V_50 ) ;
F_25 ( & V_3 -> V_51 ) ;
F_25 ( & V_3 -> V_7 ) ;
F_25 ( & V_3 -> V_52 ) ;
F_26 ( & V_3 -> V_53 ) ;
F_4 ( & V_6 ) ;
V_41 = F_14 ( V_3 -> V_39 , V_3 -> V_38 ,
V_29 ) ;
if ( V_41 ) {
F_6 ( & V_6 ) ;
F_21 ( V_3 ) ;
return V_41 ;
}
F_27 ( & V_3 -> V_7 , & V_54 ) ;
F_6 ( & V_6 ) ;
return V_3 ;
}
static int F_28 ( struct V_9 * V_10 )
{
int V_40 = V_55 ;
if ( V_10 -> type != V_56 ) {
F_22 ( V_44 , V_10 ,
L_2 ,
V_45 ) ;
return V_40 ;
}
V_40 = F_29 ( V_10 ) ;
switch ( V_40 ) {
case V_57 | V_58 :
F_22 ( V_44 , V_10 ,
L_3 ,
V_45 ) ;
break;
case V_57 :
F_22 ( V_44 , V_10 , L_4 ,
V_45 ) ;
break;
case V_58 :
F_22 ( V_44 , V_10 , L_5 ,
V_45 ) ;
break;
case V_55 :
F_22 ( V_44 , V_10 , L_6 ,
V_45 ) ;
break;
default:
F_22 ( V_44 , V_10 ,
L_7 ,
V_45 , V_40 ) ;
V_40 = V_55 ;
break;
}
return V_40 ;
}
static int F_30 ( struct V_9 * V_10 , struct V_59 * V_60 ,
int V_40 )
{
int V_61 = - 1 , V_29 ;
struct V_2 * V_3 , * V_62 = NULL ;
bool V_63 = false ;
unsigned long V_15 ;
V_29 = F_31 ( V_10 , & V_61 ) ;
if ( V_29 < 0 ) {
F_22 ( V_44 , V_10 ,
L_8 ,
V_45 ) ;
return V_64 ;
}
V_3 = F_17 ( V_10 , V_29 , V_40 ) ;
if ( F_32 ( V_3 ) ) {
if ( F_33 ( V_3 ) == - V_43 )
return V_65 ;
return V_64 ;
}
F_22 ( V_44 , V_10 ,
L_9 ,
V_45 , V_3 -> V_39 , V_29 , V_61 ) ;
F_4 ( & V_60 -> V_66 ) ;
V_62 = V_60 -> V_3 ;
if ( V_62 != V_3 ) {
if ( V_60 -> V_3 ) {
F_34 ( & V_62 -> V_53 , V_15 ) ;
F_35 ( & V_60 -> V_7 ) ;
F_36 ( & V_62 -> V_53 , V_15 ) ;
}
F_37 ( V_60 -> V_3 , V_3 ) ;
V_63 = true ;
}
F_34 ( & V_3 -> V_53 , V_15 ) ;
if ( V_10 -> V_67 )
V_3 -> V_15 |= V_68 ;
if ( V_63 )
F_38 ( & V_60 -> V_7 , & V_3 -> V_52 ) ;
F_36 ( & V_3 -> V_53 , V_15 ) ;
F_39 ( V_60 -> V_3 , V_10 , NULL , true ) ;
F_6 ( & V_60 -> V_66 ) ;
if ( V_62 )
F_40 ( & V_62 -> V_1 , F_1 ) ;
return V_69 ;
}
static char F_41 ( unsigned char V_47 )
{
switch ( V_47 ) {
case V_33 :
return 'A' ;
case V_70 :
return 'N' ;
case V_71 :
return 'S' ;
case V_72 :
return 'U' ;
case V_73 :
return 'L' ;
case V_74 :
return 'O' ;
case V_75 :
return 'T' ;
default:
return 'X' ;
}
}
static int F_42 ( struct V_9 * V_10 ,
struct V_13 * V_76 )
{
switch ( V_76 -> V_77 ) {
case V_78 :
if ( V_76 -> V_79 == 0x04 && V_76 -> V_80 == 0x0a ) {
F_43 ( V_10 , false ) ;
return V_81 ;
}
break;
case V_82 :
if ( V_76 -> V_79 == 0x29 && V_76 -> V_80 == 0x00 ) {
F_43 ( V_10 , true ) ;
return V_83 ;
}
if ( V_76 -> V_79 == 0x29 && V_76 -> V_80 == 0x04 )
return V_83 ;
if ( V_76 -> V_79 == 0x2a && V_76 -> V_80 == 0x01 )
return V_83 ;
if ( V_76 -> V_79 == 0x2a && V_76 -> V_80 == 0x06 ) {
F_43 ( V_10 , true ) ;
return V_83 ;
}
if ( V_76 -> V_79 == 0x2a && V_76 -> V_80 == 0x07 ) {
F_43 ( V_10 , true ) ;
return V_83 ;
}
if ( V_76 -> V_79 == 0x3f && V_76 -> V_80 == 0x03 )
return V_83 ;
if ( V_76 -> V_79 == 0x3f && V_76 -> V_80 == 0x0e )
return V_83 ;
break;
}
return V_84 ;
}
static int F_44 ( struct V_9 * V_10 )
{
struct V_13 V_76 ;
int V_85 ;
V_85 = F_45 ( V_10 , V_26 * V_27 ,
V_28 , & V_76 ) ;
if ( V_76 . V_77 == V_78 &&
V_76 . V_79 == 0x04 && V_76 . V_80 == 0x0a )
return V_86 ;
else if ( V_85 )
return V_87 ;
else
return V_69 ;
}
static int F_46 ( struct V_9 * V_10 , struct V_2 * V_3 )
{
struct V_13 V_76 ;
struct V_2 * V_41 ;
int V_88 , V_89 , V_90 , V_91 = 0 , V_12 = V_92 ;
unsigned char * V_93 , * V_11 ;
unsigned V_94 , V_85 ;
unsigned int V_95 ;
unsigned char V_96 ;
unsigned long V_15 ;
if ( ! V_3 -> V_97 ) {
unsigned long V_98 = V_26 * V_27 ;
if ( V_3 -> V_98 )
V_98 = V_3 -> V_98 * V_27 ;
V_3 -> V_97 = F_47 ( V_99 + V_98 ) ;
}
V_11 = F_18 ( V_12 , V_42 ) ;
if ( ! V_11 )
return V_100 ;
V_101:
V_94 = 0 ;
V_85 = F_8 ( V_10 , V_11 , V_12 , & V_76 , V_3 -> V_15 ) ;
if ( V_85 ) {
if ( ! F_48 ( & V_76 ) ) {
F_22 ( V_44 , V_10 ,
L_10 ,
V_45 , V_85 ) ;
F_21 ( V_11 ) ;
if ( F_49 ( V_85 ) == V_102 )
return V_100 ;
return V_87 ;
}
if ( ! ( V_3 -> V_15 & V_22 ) &&
V_76 . V_77 == V_103 &&
V_76 . V_79 == 0x24 && V_76 . V_80 == 0 ) {
V_3 -> V_15 |= V_22 ;
goto V_101;
}
if ( V_76 . V_77 == V_78 &&
V_76 . V_79 == 0x04 && V_76 . V_80 == 0x0a )
V_94 = V_86 ;
else if ( V_76 . V_77 == V_82 )
V_94 = V_86 ;
if ( V_94 == V_86 &&
V_3 -> V_97 != 0 && F_50 ( V_99 , V_3 -> V_97 ) ) {
F_22 ( V_104 , V_10 , L_11 ,
V_45 ) ;
F_51 ( V_10 , V_45 , & V_76 ) ;
return V_94 ;
}
F_22 ( V_104 , V_10 , L_12 ,
V_45 ) ;
F_51 ( V_10 , V_45 , & V_76 ) ;
F_21 ( V_11 ) ;
V_3 -> V_97 = 0 ;
return V_87 ;
}
V_88 = F_52 ( & V_11 [ 0 ] ) + 4 ;
if ( V_88 > V_12 ) {
F_21 ( V_11 ) ;
V_12 = V_88 ;
V_11 = F_53 ( V_12 , V_42 ) ;
if ( ! V_11 ) {
F_22 ( V_105 , V_10 ,
L_13 , V_106 ) ;
V_3 -> V_97 = 0 ;
return V_100 ;
}
goto V_101;
}
V_96 = V_3 -> V_98 ;
if ( ( V_11 [ 4 ] & V_107 ) == V_108 && V_11 [ 5 ] != 0 )
V_3 -> V_98 = V_11 [ 5 ] ;
else
V_3 -> V_98 = V_26 ;
if ( V_96 != V_3 -> V_98 ) {
F_22 ( V_44 , V_10 ,
L_14 ,
V_45 , V_3 -> V_98 ) ;
V_3 -> V_97 = V_99 + V_3 -> V_98 * V_27 ;
}
if ( ( V_11 [ 4 ] & V_107 ) == V_108 )
V_95 = 8 ;
else
V_95 = 4 ;
for ( V_89 = V_95 , V_93 = V_11 + V_95 ;
V_89 < V_88 ;
V_89 += V_90 , V_93 += V_90 ) {
T_3 V_29 = F_54 ( & V_93 [ 2 ] ) ;
F_34 ( & V_6 , V_15 ) ;
V_41 = F_14 ( V_3 -> V_39 , V_3 -> V_38 ,
V_29 ) ;
F_36 ( & V_6 , V_15 ) ;
if ( V_41 ) {
if ( F_55 ( & V_41 -> V_53 , V_15 ) ) {
if ( ( V_41 == V_3 ) ||
! ( V_41 -> V_15 & V_109 ) ) {
struct V_59 * V_60 ;
V_41 -> V_47 = V_93 [ 0 ] & 0x0f ;
V_41 -> V_110 = V_93 [ 0 ] >> 7 ;
F_56 () ;
F_57 (h,
&tmp_pg->dh_list, node) {
F_58 ( ! V_60 -> V_10 ) ;
V_60 -> V_10 -> V_111 = V_93 [ 0 ] ;
}
F_59 () ;
}
if ( V_41 == V_3 )
V_91 = V_93 [ 1 ] ;
F_36 ( & V_41 -> V_53 , V_15 ) ;
}
F_40 ( & V_41 -> V_1 , F_1 ) ;
}
V_90 = 8 + ( V_93 [ 7 ] * 4 ) ;
}
F_34 ( & V_3 -> V_53 , V_15 ) ;
F_22 ( V_44 , V_10 ,
L_15 ,
V_45 , V_3 -> V_29 , F_41 ( V_3 -> V_47 ) ,
V_3 -> V_110 ? L_16 : L_17 ,
V_91 & V_112 ? 'T' : 't' ,
V_91 & V_113 ? 'O' : 'o' ,
V_91 & V_114 ? 'L' : 'l' ,
V_91 & V_115 ? 'U' : 'u' ,
V_91 & V_116 ? 'S' : 's' ,
V_91 & V_117 ? 'N' : 'n' ,
V_91 & V_118 ? 'A' : 'a' ) ;
switch ( V_3 -> V_47 ) {
case V_75 :
if ( F_50 ( V_99 , V_3 -> V_97 ) ) {
V_3 -> V_119 = 2 ;
V_94 = V_86 ;
} else {
struct V_59 * V_60 ;
V_94 = V_87 ;
V_3 -> V_47 = V_71 ;
V_3 -> V_97 = 0 ;
F_56 () ;
F_57 (h, &pg->dh_list, node) {
F_58 ( ! V_60 -> V_10 ) ;
V_60 -> V_10 -> V_111 =
( V_3 -> V_47 & V_120 ) ;
if ( V_3 -> V_110 )
V_60 -> V_10 -> V_111 |=
V_121 ;
}
F_59 () ;
}
break;
case V_74 :
V_94 = V_122 ;
V_3 -> V_97 = 0 ;
break;
default:
V_94 = V_69 ;
V_3 -> V_97 = 0 ;
break;
}
F_36 ( & V_3 -> V_53 , V_15 ) ;
F_21 ( V_11 ) ;
return V_94 ;
}
static unsigned F_60 ( struct V_9 * V_10 , struct V_2 * V_3 )
{
int V_85 ;
struct V_13 V_76 ;
if ( ! ( V_3 -> V_40 & V_57 ) ) {
return V_86 ;
}
switch ( V_3 -> V_47 ) {
case V_33 :
return V_69 ;
case V_70 :
if ( ( V_3 -> V_15 & V_49 ) &&
! V_3 -> V_110 &&
( V_3 -> V_40 & V_58 ) )
return V_69 ;
break;
case V_71 :
case V_72 :
break;
case V_74 :
return V_87 ;
case V_75 :
break;
default:
F_22 ( V_44 , V_10 ,
L_18 ,
V_45 , V_3 -> V_47 ) ;
return V_123 ;
}
V_85 = F_12 ( V_10 , V_3 -> V_29 , & V_76 ) ;
if ( V_85 ) {
if ( ! F_48 ( & V_76 ) ) {
F_22 ( V_44 , V_10 ,
L_19 ,
V_45 , V_85 ) ;
if ( F_49 ( V_85 ) == V_102 )
return V_100 ;
} else {
F_22 ( V_44 , V_10 , L_20 ,
V_45 ) ;
F_51 ( V_10 , V_45 , & V_76 ) ;
}
}
return V_86 ;
}
static void V_50 ( struct V_124 * V_125 )
{
struct V_2 * V_3 =
F_2 ( V_125 , struct V_2 , V_5 . V_125 ) ;
struct V_9 * V_10 ;
F_61 ( V_126 ) ;
int V_94 = V_69 ;
struct V_127 * V_128 , * V_129 ;
unsigned long V_15 ;
struct V_130 * V_131 = V_132 ;
F_34 ( & V_3 -> V_53 , V_15 ) ;
V_10 = V_3 -> V_4 ;
if ( ! V_10 ) {
F_62 ( V_3 -> V_15 & V_133 ) ;
F_62 ( V_3 -> V_15 & V_134 ) ;
F_36 ( & V_3 -> V_53 , V_15 ) ;
return;
}
if ( V_3 -> V_15 & V_68 )
V_131 = V_135 ;
V_3 -> V_15 |= V_109 ;
if ( V_3 -> V_15 & V_133 ) {
int V_47 = V_3 -> V_47 ;
V_3 -> V_15 &= ~ V_133 ;
F_36 ( & V_3 -> V_53 , V_15 ) ;
if ( V_47 == V_75 ) {
if ( F_44 ( V_10 ) == V_86 ) {
F_34 ( & V_3 -> V_53 , V_15 ) ;
V_3 -> V_15 &= ~ V_109 ;
V_3 -> V_15 |= V_133 ;
F_36 ( & V_3 -> V_53 , V_15 ) ;
F_63 ( V_131 , & V_3 -> V_5 ,
V_3 -> V_119 * V_27 ) ;
return;
}
}
V_94 = F_46 ( V_10 , V_3 ) ;
F_34 ( & V_3 -> V_53 , V_15 ) ;
if ( V_94 == V_86 || V_3 -> V_15 & V_133 ) {
V_3 -> V_15 &= ~ V_109 ;
V_3 -> V_15 |= V_133 ;
F_36 ( & V_3 -> V_53 , V_15 ) ;
F_63 ( V_131 , & V_3 -> V_5 ,
V_3 -> V_119 * V_27 ) ;
return;
}
if ( V_94 != V_69 )
V_3 -> V_15 &= ~ V_134 ;
}
if ( V_3 -> V_15 & V_134 ) {
V_3 -> V_15 &= ~ V_134 ;
F_36 ( & V_3 -> V_53 , V_15 ) ;
V_94 = F_60 ( V_10 , V_3 ) ;
F_34 ( & V_3 -> V_53 , V_15 ) ;
if ( V_94 == V_86 || V_3 -> V_15 & V_133 ) {
V_3 -> V_15 |= V_133 ;
V_3 -> V_119 = 0 ;
V_3 -> V_15 &= ~ V_109 ;
F_36 ( & V_3 -> V_53 , V_15 ) ;
F_63 ( V_131 , & V_3 -> V_5 ,
V_3 -> V_119 * V_27 ) ;
return;
}
}
F_64 ( & V_3 -> V_51 , & V_126 ) ;
V_3 -> V_4 = NULL ;
F_36 ( & V_3 -> V_53 , V_15 ) ;
F_65 (qdata, tmp, &qdata_list, entry) {
F_5 ( & V_128 -> V_136 ) ;
if ( V_128 -> V_137 )
V_128 -> V_137 ( V_128 -> V_138 , V_94 ) ;
F_21 ( V_128 ) ;
}
F_34 ( & V_3 -> V_53 , V_15 ) ;
V_3 -> V_15 &= ~ V_109 ;
F_36 ( & V_3 -> V_53 , V_15 ) ;
F_66 ( V_10 ) ;
F_40 ( & V_3 -> V_1 , F_1 ) ;
}
static void F_39 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
struct V_127 * V_128 , bool V_139 )
{
int V_140 = 0 ;
unsigned long V_15 ;
struct V_130 * V_131 = V_132 ;
if ( ! V_3 )
return;
F_34 ( & V_3 -> V_53 , V_15 ) ;
if ( V_128 ) {
F_67 ( & V_128 -> V_136 , & V_3 -> V_51 ) ;
V_3 -> V_15 |= V_134 ;
V_139 = true ;
}
if ( V_3 -> V_4 == NULL ) {
V_3 -> V_119 = 0 ;
V_3 -> V_15 |= V_133 ;
F_68 ( & V_3 -> V_1 ) ;
V_3 -> V_4 = V_10 ;
F_69 ( V_10 ) ;
V_140 = 1 ;
} else if ( ! ( V_3 -> V_15 & V_133 ) && V_139 ) {
V_3 -> V_15 |= V_133 ;
if ( ! ( V_3 -> V_15 & V_109 ) ) {
F_68 ( & V_3 -> V_1 ) ;
V_140 = 1 ;
}
}
if ( V_3 -> V_15 & V_68 )
V_131 = V_135 ;
F_36 ( & V_3 -> V_53 , V_15 ) ;
if ( V_140 &&
! F_63 ( V_131 , & V_3 -> V_5 ,
F_70 ( V_141 ) ) ) {
F_66 ( V_10 ) ;
F_40 ( & V_3 -> V_1 , F_1 ) ;
}
}
static int F_71 ( struct V_9 * V_10 , struct V_59 * V_60 )
{
int V_94 = V_64 , V_40 ;
F_72 ( & V_60 -> V_142 ) ;
V_40 = F_28 ( V_10 ) ;
if ( V_40 != V_55 )
V_94 = F_30 ( V_10 , V_60 , V_40 ) ;
V_60 -> V_143 = V_94 ;
F_73 ( & V_60 -> V_142 ) ;
return V_94 ;
}
static int F_74 ( struct V_9 * V_10 , const char * V_144 )
{
struct V_59 * V_60 = V_10 -> V_145 ;
struct V_2 T_4 * V_3 = NULL ;
unsigned int V_146 = 0 , V_147 ;
const char * V_148 = V_144 ;
int V_149 = V_69 ;
unsigned long V_15 ;
if ( ( sscanf ( V_144 , L_21 , & V_147 ) != 1 ) || ( V_147 != 1 ) )
return - V_150 ;
while ( * V_148 ++ )
;
if ( ( sscanf ( V_148 , L_21 , & V_146 ) != 1 ) || ( V_146 > 1 ) )
return - V_150 ;
F_56 () ;
V_3 = F_75 ( V_60 -> V_3 ) ;
if ( ! V_3 ) {
F_59 () ;
return - V_46 ;
}
F_34 ( & V_3 -> V_53 , V_15 ) ;
if ( V_146 )
V_3 -> V_15 |= V_49 ;
else
V_3 -> V_15 &= ~ V_49 ;
F_36 ( & V_3 -> V_53 , V_15 ) ;
F_59 () ;
return V_149 ;
}
static int F_76 ( struct V_9 * V_10 ,
T_5 V_151 , void * V_152 )
{
struct V_59 * V_60 = V_10 -> V_145 ;
int V_94 = V_69 ;
struct V_127 * V_128 ;
struct V_2 T_4 * V_3 ;
V_128 = F_18 ( sizeof( * V_128 ) , V_42 ) ;
if ( ! V_128 ) {
V_94 = V_153 ;
goto V_154;
}
V_128 -> V_137 = V_151 ;
V_128 -> V_138 = V_152 ;
F_72 ( & V_60 -> V_142 ) ;
F_56 () ;
V_3 = F_75 ( V_60 -> V_3 ) ;
if ( ! V_3 || ! F_16 ( & V_3 -> V_1 ) ) {
F_59 () ;
F_21 ( V_128 ) ;
V_94 = V_60 -> V_143 ;
F_73 ( & V_60 -> V_142 ) ;
goto V_154;
}
V_151 = NULL ;
F_59 () ;
F_73 ( & V_60 -> V_142 ) ;
F_39 ( V_3 , V_10 , V_128 , true ) ;
F_40 ( & V_3 -> V_1 , F_1 ) ;
V_154:
if ( V_151 )
V_151 ( V_152 , V_94 ) ;
return 0 ;
}
static void F_43 ( struct V_9 * V_10 , bool V_139 )
{
struct V_59 * V_60 = V_10 -> V_145 ;
struct V_2 * V_3 ;
F_56 () ;
V_3 = F_75 ( V_60 -> V_3 ) ;
if ( ! V_3 || ! F_16 ( & V_3 -> V_1 ) ) {
F_59 () ;
return;
}
F_59 () ;
F_39 ( V_3 , V_10 , NULL , V_139 ) ;
F_40 ( & V_3 -> V_1 , F_1 ) ;
}
static int F_77 ( struct V_9 * V_10 , struct V_155 * V_156 )
{
struct V_59 * V_60 = V_10 -> V_145 ;
struct V_2 T_4 * V_3 ;
unsigned char V_47 = V_33 ;
int V_157 = V_158 ;
F_56 () ;
V_3 = F_75 ( V_60 -> V_3 ) ;
if ( V_3 )
V_47 = V_3 -> V_47 ;
F_59 () ;
if ( V_47 == V_75 )
V_157 = V_159 ;
else if ( V_47 != V_33 &&
V_47 != V_70 &&
V_47 != V_73 ) {
V_157 = V_160 ;
V_156 -> V_161 |= V_162 ;
}
return V_157 ;
}
static void F_78 ( struct V_9 * V_10 )
{
struct V_59 * V_60 = V_10 -> V_145 ;
F_71 ( V_10 , V_60 ) ;
}
static int F_79 ( struct V_9 * V_10 )
{
struct V_59 * V_60 ;
int V_94 , V_157 = - V_150 ;
V_60 = F_18 ( sizeof( * V_60 ) , V_42 ) ;
if ( ! V_60 )
return - V_43 ;
F_26 ( & V_60 -> V_66 ) ;
F_37 ( V_60 -> V_3 , NULL ) ;
V_60 -> V_143 = V_69 ;
V_60 -> V_10 = V_10 ;
F_25 ( & V_60 -> V_7 ) ;
F_80 ( & V_60 -> V_142 ) ;
V_94 = F_71 ( V_10 , V_60 ) ;
if ( V_94 == V_65 )
V_157 = - V_43 ;
if ( V_94 != V_69 && V_94 != V_122 )
goto V_163;
V_10 -> V_145 = V_60 ;
return 0 ;
V_163:
F_21 ( V_60 ) ;
return V_157 ;
}
static void F_81 ( struct V_9 * V_10 )
{
struct V_59 * V_60 = V_10 -> V_145 ;
struct V_2 * V_3 ;
F_4 ( & V_60 -> V_66 ) ;
V_3 = V_60 -> V_3 ;
F_37 ( V_60 -> V_3 , NULL ) ;
V_60 -> V_10 = NULL ;
F_6 ( & V_60 -> V_66 ) ;
if ( V_3 ) {
F_82 ( & V_3 -> V_53 ) ;
F_35 ( & V_60 -> V_7 ) ;
F_83 ( & V_3 -> V_53 ) ;
F_40 ( & V_3 -> V_1 , F_1 ) ;
}
V_10 -> V_145 = NULL ;
F_21 ( V_60 ) ;
}
static int T_6 F_84 ( void )
{
int V_164 ;
V_132 = F_85 ( L_22 , V_165 , 0 ) ;
if ( ! V_132 ) {
return V_100 ;
}
V_135 = F_86 ( L_23 ) ;
if ( ! V_135 ) {
F_87 ( V_132 ) ;
return V_100 ;
}
V_164 = F_88 ( & V_166 ) ;
if ( V_164 != 0 ) {
F_89 ( V_104 L_24 ,
V_45 ) ;
F_87 ( V_135 ) ;
F_87 ( V_132 ) ;
}
return V_164 ;
}
static void T_7 F_90 ( void )
{
F_91 ( & V_166 ) ;
F_87 ( V_135 ) ;
F_87 ( V_132 ) ;
}
