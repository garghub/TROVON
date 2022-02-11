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
return F_11 ( V_10 , V_16 , V_25 , V_11 , V_12 , NULL ,
V_14 , V_26 * V_27 ,
V_28 , V_18 , 0 , NULL ) ;
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
return F_11 ( V_10 , V_16 , V_35 , V_31 , V_32 , NULL ,
V_14 , V_26 * V_27 ,
V_28 , V_18 , 0 , NULL ) ;
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
V_61 = F_34 ( V_59 -> V_3 , F_35 ( & V_59 -> V_65 ) ) ;
if ( V_61 != V_3 ) {
if ( V_59 -> V_3 ) {
F_36 ( & V_61 -> V_52 , V_15 ) ;
F_37 ( & V_59 -> V_7 ) ;
F_38 ( & V_61 -> V_52 , V_15 ) ;
}
F_39 ( V_59 -> V_3 , V_3 ) ;
V_62 = true ;
}
F_36 ( & V_3 -> V_52 , V_15 ) ;
if ( V_62 )
F_40 ( & V_59 -> V_7 , & V_3 -> V_51 ) ;
F_38 ( & V_3 -> V_52 , V_15 ) ;
F_41 ( F_34 ( V_59 -> V_3 ,
F_35 ( & V_59 -> V_65 ) ) ,
V_10 , NULL , true ) ;
F_6 ( & V_59 -> V_65 ) ;
if ( V_61 )
F_42 ( & V_61 -> V_1 , F_1 ) ;
return V_66 ;
}
static char F_43 ( unsigned char V_46 )
{
switch ( V_46 ) {
case V_33 :
return 'A' ;
case V_67 :
return 'N' ;
case V_68 :
return 'S' ;
case V_69 :
return 'U' ;
case V_70 :
return 'L' ;
case V_71 :
return 'O' ;
case V_72 :
return 'T' ;
default:
return 'X' ;
}
}
static int F_44 ( struct V_9 * V_10 ,
struct V_13 * V_73 )
{
switch ( V_73 -> V_74 ) {
case V_75 :
if ( V_73 -> V_76 == 0x04 && V_73 -> V_77 == 0x0a ) {
F_45 ( V_10 , false ) ;
return V_78 ;
}
break;
case V_79 :
if ( V_73 -> V_76 == 0x29 && V_73 -> V_77 == 0x00 ) {
F_45 ( V_10 , true ) ;
return V_80 ;
}
if ( V_73 -> V_76 == 0x29 && V_73 -> V_77 == 0x04 )
return V_80 ;
if ( V_73 -> V_76 == 0x2a && V_73 -> V_77 == 0x01 )
return V_80 ;
if ( V_73 -> V_76 == 0x2a && V_73 -> V_77 == 0x06 ) {
F_45 ( V_10 , true ) ;
return V_80 ;
}
if ( V_73 -> V_76 == 0x2a && V_73 -> V_77 == 0x07 ) {
F_45 ( V_10 , true ) ;
return V_80 ;
}
if ( V_73 -> V_76 == 0x3f && V_73 -> V_77 == 0x03 )
return V_80 ;
if ( V_73 -> V_76 == 0x3f && V_73 -> V_77 == 0x0e )
return V_80 ;
break;
}
return V_81 ;
}
static int F_46 ( struct V_9 * V_10 )
{
struct V_13 V_73 ;
int V_82 ;
V_82 = F_47 ( V_10 , V_26 * V_27 ,
V_28 , & V_73 ) ;
if ( V_73 . V_74 == V_75 &&
V_73 . V_76 == 0x04 && V_73 . V_77 == 0x0a )
return V_83 ;
else if ( V_82 )
return V_84 ;
else
return V_66 ;
}
static int F_48 ( struct V_9 * V_10 , struct V_2 * V_3 )
{
struct V_13 V_73 ;
struct V_2 * V_41 ;
int V_85 , V_86 , V_87 , V_88 = 0 , V_12 = V_89 ;
unsigned char * V_90 , * V_11 ;
unsigned V_91 , V_82 ;
unsigned int V_92 ;
unsigned char V_93 ;
unsigned long V_15 ;
if ( ! V_3 -> V_94 ) {
unsigned long V_95 = V_26 * V_27 ;
if ( V_3 -> V_95 )
V_95 = V_3 -> V_95 * V_27 ;
V_3 -> V_94 = F_49 ( V_96 + V_95 ) ;
}
V_11 = F_18 ( V_12 , V_42 ) ;
if ( ! V_11 )
return V_97 ;
V_98:
V_91 = 0 ;
V_82 = F_8 ( V_10 , V_11 , V_12 , & V_73 , V_3 -> V_15 ) ;
if ( V_82 ) {
if ( ! F_50 ( & V_73 ) ) {
F_21 ( V_44 , V_10 ,
L_11 ,
V_45 , V_82 ) ;
F_26 ( V_11 ) ;
if ( F_51 ( V_82 ) == V_99 )
return V_97 ;
return V_84 ;
}
if ( ! ( V_3 -> V_15 & V_22 ) &&
V_73 . V_74 == V_100 &&
V_73 . V_76 == 0x24 && V_73 . V_77 == 0 ) {
V_3 -> V_15 |= V_22 ;
goto V_98;
}
if ( V_73 . V_74 == V_75 &&
V_73 . V_76 == 0x04 && V_73 . V_77 == 0x0a )
V_91 = V_83 ;
else if ( V_73 . V_74 == V_79 )
V_91 = V_83 ;
if ( V_91 == V_83 &&
V_3 -> V_94 != 0 && F_52 ( V_96 , V_3 -> V_94 ) ) {
F_21 ( V_101 , V_10 , L_12 ,
V_45 ) ;
F_53 ( V_10 , V_45 , & V_73 ) ;
F_26 ( V_11 ) ;
return V_91 ;
}
F_21 ( V_101 , V_10 , L_13 ,
V_45 ) ;
F_53 ( V_10 , V_45 , & V_73 ) ;
F_26 ( V_11 ) ;
V_3 -> V_94 = 0 ;
return V_84 ;
}
V_85 = F_54 ( & V_11 [ 0 ] ) + 4 ;
if ( V_85 > V_12 ) {
F_26 ( V_11 ) ;
V_12 = V_85 ;
V_11 = F_55 ( V_12 , V_42 ) ;
if ( ! V_11 ) {
F_21 ( V_102 , V_10 ,
L_14 , V_103 ) ;
V_3 -> V_94 = 0 ;
return V_97 ;
}
goto V_98;
}
V_93 = V_3 -> V_95 ;
if ( ( V_11 [ 4 ] & V_104 ) == V_105 && V_11 [ 5 ] != 0 )
V_3 -> V_95 = V_11 [ 5 ] ;
else
V_3 -> V_95 = V_26 ;
if ( V_93 != V_3 -> V_95 ) {
F_21 ( V_44 , V_10 ,
L_15 ,
V_45 , V_3 -> V_95 ) ;
V_3 -> V_94 = V_96 + V_3 -> V_95 * V_27 ;
}
if ( ( V_11 [ 4 ] & V_104 ) == V_105 )
V_92 = 8 ;
else
V_92 = 4 ;
for ( V_86 = V_92 , V_90 = V_11 + V_92 ;
V_86 < V_85 ;
V_86 += V_87 , V_90 += V_87 ) {
T_3 V_29 = F_56 ( & V_90 [ 2 ] ) ;
F_36 ( & V_6 , V_15 ) ;
V_41 = F_14 ( V_3 -> V_39 , V_3 -> V_38 ,
V_29 ) ;
F_38 ( & V_6 , V_15 ) ;
if ( V_41 ) {
if ( F_57 ( & V_41 -> V_52 , V_15 ) ) {
if ( ( V_41 == V_3 ) ||
! ( V_41 -> V_15 & V_106 ) ) {
struct V_58 * V_59 ;
V_41 -> V_46 = V_90 [ 0 ] & 0x0f ;
V_41 -> V_107 = V_90 [ 0 ] >> 7 ;
F_58 () ;
F_59 (h,
&tmp_pg->dh_list, node) {
F_60 ( ! V_59 -> V_10 ) ;
V_59 -> V_10 -> V_108 = V_90 [ 0 ] ;
}
F_61 () ;
}
if ( V_41 == V_3 )
V_88 = V_90 [ 1 ] ;
F_38 ( & V_41 -> V_52 , V_15 ) ;
}
F_42 ( & V_41 -> V_1 , F_1 ) ;
}
V_87 = 8 + ( V_90 [ 7 ] * 4 ) ;
}
F_36 ( & V_3 -> V_52 , V_15 ) ;
F_21 ( V_44 , V_10 ,
L_16 ,
V_45 , V_3 -> V_29 , F_43 ( V_3 -> V_46 ) ,
V_3 -> V_107 ? L_17 : L_18 ,
V_88 & V_109 ? 'T' : 't' ,
V_88 & V_110 ? 'O' : 'o' ,
V_88 & V_111 ? 'L' : 'l' ,
V_88 & V_112 ? 'U' : 'u' ,
V_88 & V_113 ? 'S' : 's' ,
V_88 & V_114 ? 'N' : 'n' ,
V_88 & V_115 ? 'A' : 'a' ) ;
switch ( V_3 -> V_46 ) {
case V_72 :
if ( F_52 ( V_96 , V_3 -> V_94 ) ) {
V_3 -> V_116 = 2 ;
V_91 = V_83 ;
} else {
struct V_58 * V_59 ;
V_91 = V_84 ;
V_3 -> V_46 = V_68 ;
V_3 -> V_94 = 0 ;
F_58 () ;
F_59 (h, &pg->dh_list, node) {
F_60 ( ! V_59 -> V_10 ) ;
V_59 -> V_10 -> V_108 =
( V_3 -> V_46 & V_117 ) ;
if ( V_3 -> V_107 )
V_59 -> V_10 -> V_108 |=
V_118 ;
}
F_61 () ;
}
break;
case V_71 :
V_91 = V_119 ;
V_3 -> V_94 = 0 ;
break;
default:
V_91 = V_66 ;
V_3 -> V_94 = 0 ;
break;
}
F_38 ( & V_3 -> V_52 , V_15 ) ;
F_26 ( V_11 ) ;
return V_91 ;
}
static unsigned F_62 ( struct V_9 * V_10 , struct V_2 * V_3 )
{
int V_82 ;
struct V_13 V_73 ;
if ( ! ( V_3 -> V_40 & V_56 ) ) {
return V_83 ;
}
switch ( V_3 -> V_46 ) {
case V_33 :
return V_66 ;
case V_67 :
if ( ( V_3 -> V_15 & V_48 ) &&
! V_3 -> V_107 &&
( V_3 -> V_40 & V_57 ) )
return V_66 ;
break;
case V_68 :
case V_69 :
break;
case V_71 :
return V_84 ;
case V_72 :
break;
default:
F_21 ( V_44 , V_10 ,
L_19 ,
V_45 , V_3 -> V_46 ) ;
return V_120 ;
}
V_82 = F_12 ( V_10 , V_3 -> V_29 , & V_73 ) ;
if ( V_82 ) {
if ( ! F_50 ( & V_73 ) ) {
F_21 ( V_44 , V_10 ,
L_20 ,
V_45 , V_82 ) ;
if ( F_51 ( V_82 ) == V_99 )
return V_97 ;
} else {
F_21 ( V_44 , V_10 , L_21 ,
V_45 ) ;
F_53 ( V_10 , V_45 , & V_73 ) ;
}
}
return V_83 ;
}
static void V_49 ( struct V_121 * V_122 )
{
struct V_2 * V_3 =
F_2 ( V_122 , struct V_2 , V_5 . V_122 ) ;
struct V_9 * V_10 ;
F_63 ( V_123 ) ;
int V_91 = V_66 ;
struct V_124 * V_125 , * V_126 ;
unsigned long V_15 ;
F_36 ( & V_3 -> V_52 , V_15 ) ;
V_10 = V_3 -> V_4 ;
if ( ! V_10 ) {
F_64 ( V_3 -> V_15 & V_127 ) ;
F_64 ( V_3 -> V_15 & V_128 ) ;
F_38 ( & V_3 -> V_52 , V_15 ) ;
F_42 ( & V_3 -> V_1 , F_1 ) ;
return;
}
V_3 -> V_15 |= V_106 ;
if ( V_3 -> V_15 & V_127 ) {
int V_46 = V_3 -> V_46 ;
V_3 -> V_15 &= ~ V_127 ;
F_38 ( & V_3 -> V_52 , V_15 ) ;
if ( V_46 == V_72 ) {
if ( F_46 ( V_10 ) == V_83 ) {
F_36 ( & V_3 -> V_52 , V_15 ) ;
V_3 -> V_15 &= ~ V_106 ;
V_3 -> V_15 |= V_127 ;
F_38 ( & V_3 -> V_52 , V_15 ) ;
F_65 ( V_129 , & V_3 -> V_5 ,
V_3 -> V_116 * V_27 ) ;
return;
}
}
V_91 = F_48 ( V_10 , V_3 ) ;
F_36 ( & V_3 -> V_52 , V_15 ) ;
if ( V_91 == V_83 || V_3 -> V_15 & V_127 ) {
V_3 -> V_15 &= ~ V_106 ;
V_3 -> V_15 |= V_127 ;
F_38 ( & V_3 -> V_52 , V_15 ) ;
F_65 ( V_129 , & V_3 -> V_5 ,
V_3 -> V_116 * V_27 ) ;
return;
}
if ( V_91 != V_66 )
V_3 -> V_15 &= ~ V_128 ;
}
if ( V_3 -> V_15 & V_128 ) {
V_3 -> V_15 &= ~ V_128 ;
F_38 ( & V_3 -> V_52 , V_15 ) ;
V_91 = F_62 ( V_10 , V_3 ) ;
F_36 ( & V_3 -> V_52 , V_15 ) ;
if ( V_91 == V_83 || V_3 -> V_15 & V_127 ) {
V_3 -> V_15 |= V_127 ;
V_3 -> V_116 = 0 ;
V_3 -> V_15 &= ~ V_106 ;
F_38 ( & V_3 -> V_52 , V_15 ) ;
F_65 ( V_129 , & V_3 -> V_5 ,
V_3 -> V_116 * V_27 ) ;
return;
}
}
F_66 ( & V_3 -> V_50 , & V_123 ) ;
V_3 -> V_4 = NULL ;
F_38 ( & V_3 -> V_52 , V_15 ) ;
F_67 (qdata, tmp, &qdata_list, entry) {
F_5 ( & V_125 -> V_130 ) ;
if ( V_125 -> V_131 )
V_125 -> V_131 ( V_125 -> V_132 , V_91 ) ;
F_26 ( V_125 ) ;
}
F_36 ( & V_3 -> V_52 , V_15 ) ;
V_3 -> V_15 &= ~ V_106 ;
F_38 ( & V_3 -> V_52 , V_15 ) ;
F_68 ( V_10 ) ;
F_42 ( & V_3 -> V_1 , F_1 ) ;
}
static bool F_41 ( struct V_2 * V_3 ,
struct V_9 * V_10 ,
struct V_124 * V_125 , bool V_133 )
{
int V_134 = 0 ;
unsigned long V_15 ;
if ( F_69 ( ! V_3 ) || F_70 ( V_10 ) )
return false ;
F_36 ( & V_3 -> V_52 , V_15 ) ;
if ( V_125 ) {
F_71 ( & V_125 -> V_130 , & V_3 -> V_50 ) ;
V_3 -> V_15 |= V_128 ;
V_133 = true ;
}
if ( V_3 -> V_4 == NULL ) {
V_3 -> V_116 = 0 ;
V_3 -> V_15 |= V_127 ;
F_72 ( & V_3 -> V_1 ) ;
V_3 -> V_4 = V_10 ;
V_134 = 1 ;
} else if ( ! ( V_3 -> V_15 & V_127 ) && V_133 ) {
V_3 -> V_15 |= V_127 ;
if ( ! ( V_3 -> V_15 & V_106 ) ) {
F_72 ( & V_3 -> V_1 ) ;
V_134 = 1 ;
}
}
F_38 ( & V_3 -> V_52 , V_15 ) ;
if ( V_134 ) {
if ( F_65 ( V_129 , & V_3 -> V_5 ,
F_73 ( V_135 ) ) )
V_10 = NULL ;
else
F_42 ( & V_3 -> V_1 , F_1 ) ;
}
if ( V_10 )
F_68 ( V_10 ) ;
return true ;
}
static int F_74 ( struct V_9 * V_10 , struct V_58 * V_59 )
{
int V_91 = V_63 , V_40 ;
F_75 ( & V_59 -> V_136 ) ;
V_40 = F_28 ( V_10 ) ;
if ( V_40 != V_54 )
V_91 = F_30 ( V_10 , V_59 , V_40 ) ;
V_59 -> V_137 = V_91 ;
F_76 ( & V_59 -> V_136 ) ;
return V_91 ;
}
static int F_77 ( struct V_9 * V_10 , const char * V_138 )
{
struct V_58 * V_59 = V_10 -> V_139 ;
struct V_2 * V_3 = NULL ;
unsigned int V_140 = 0 , V_141 ;
const char * V_142 = V_138 ;
int V_143 = V_66 ;
unsigned long V_15 ;
if ( ( sscanf ( V_138 , L_22 , & V_141 ) != 1 ) || ( V_141 != 1 ) )
return - V_144 ;
while ( * V_142 ++ )
;
if ( ( sscanf ( V_142 , L_22 , & V_140 ) != 1 ) || ( V_140 > 1 ) )
return - V_144 ;
F_58 () ;
V_3 = F_78 ( V_59 -> V_3 ) ;
if ( ! V_3 ) {
F_61 () ;
return - V_145 ;
}
F_36 ( & V_3 -> V_52 , V_15 ) ;
if ( V_140 )
V_3 -> V_15 |= V_48 ;
else
V_3 -> V_15 &= ~ V_48 ;
F_38 ( & V_3 -> V_52 , V_15 ) ;
F_61 () ;
return V_143 ;
}
static int F_79 ( struct V_9 * V_10 ,
T_4 V_146 , void * V_147 )
{
struct V_58 * V_59 = V_10 -> V_139 ;
int V_91 = V_66 ;
struct V_124 * V_125 ;
struct V_2 * V_3 ;
V_125 = F_18 ( sizeof( * V_125 ) , V_42 ) ;
if ( ! V_125 ) {
V_91 = V_148 ;
goto V_149;
}
V_125 -> V_131 = V_146 ;
V_125 -> V_132 = V_147 ;
F_75 ( & V_59 -> V_136 ) ;
F_58 () ;
V_3 = F_78 ( V_59 -> V_3 ) ;
if ( ! V_3 || ! F_16 ( & V_3 -> V_1 ) ) {
F_61 () ;
F_26 ( V_125 ) ;
V_91 = V_59 -> V_137 ;
F_76 ( & V_59 -> V_136 ) ;
goto V_149;
}
F_61 () ;
F_76 ( & V_59 -> V_136 ) ;
if ( F_41 ( V_3 , V_10 , V_125 , true ) )
V_146 = NULL ;
else
V_91 = V_119 ;
F_42 ( & V_3 -> V_1 , F_1 ) ;
V_149:
if ( V_146 )
V_146 ( V_147 , V_91 ) ;
return 0 ;
}
static void F_45 ( struct V_9 * V_10 , bool V_133 )
{
struct V_58 * V_59 = V_10 -> V_139 ;
struct V_2 * V_3 ;
F_58 () ;
V_3 = F_78 ( V_59 -> V_3 ) ;
if ( ! V_3 || ! F_16 ( & V_3 -> V_1 ) ) {
F_61 () ;
return;
}
F_61 () ;
F_41 ( V_3 , V_10 , NULL , V_133 ) ;
F_42 ( & V_3 -> V_1 , F_1 ) ;
}
static int F_80 ( struct V_9 * V_10 , struct V_150 * V_151 )
{
struct V_58 * V_59 = V_10 -> V_139 ;
struct V_2 * V_3 ;
unsigned char V_46 = V_33 ;
int V_152 = V_153 ;
F_58 () ;
V_3 = F_78 ( V_59 -> V_3 ) ;
if ( V_3 )
V_46 = V_3 -> V_46 ;
F_61 () ;
if ( V_46 == V_72 )
V_152 = V_154 ;
else if ( V_46 != V_33 &&
V_46 != V_67 &&
V_46 != V_70 ) {
V_152 = V_155 ;
V_151 -> V_156 |= V_157 ;
}
return V_152 ;
}
static void F_81 ( struct V_9 * V_10 )
{
struct V_58 * V_59 = V_10 -> V_139 ;
F_74 ( V_10 , V_59 ) ;
}
static int F_82 ( struct V_9 * V_10 )
{
struct V_58 * V_59 ;
int V_91 , V_152 = - V_144 ;
V_59 = F_18 ( sizeof( * V_59 ) , V_42 ) ;
if ( ! V_59 )
return - V_43 ;
F_25 ( & V_59 -> V_65 ) ;
F_39 ( V_59 -> V_3 , NULL ) ;
V_59 -> V_137 = V_66 ;
V_59 -> V_10 = V_10 ;
F_24 ( & V_59 -> V_7 ) ;
F_83 ( & V_59 -> V_136 ) ;
V_91 = F_74 ( V_10 , V_59 ) ;
if ( V_91 == V_64 )
V_152 = - V_43 ;
if ( V_91 != V_66 && V_91 != V_119 )
goto V_158;
V_10 -> V_139 = V_59 ;
return 0 ;
V_158:
F_26 ( V_59 ) ;
return V_152 ;
}
static void F_84 ( struct V_9 * V_10 )
{
struct V_58 * V_59 = V_10 -> V_139 ;
struct V_2 * V_3 ;
F_4 ( & V_59 -> V_65 ) ;
V_3 = F_34 ( V_59 -> V_3 , F_35 ( & V_59 -> V_65 ) ) ;
F_39 ( V_59 -> V_3 , NULL ) ;
V_59 -> V_10 = NULL ;
F_6 ( & V_59 -> V_65 ) ;
if ( V_3 ) {
F_85 ( & V_3 -> V_52 ) ;
F_37 ( & V_59 -> V_7 ) ;
F_86 ( & V_3 -> V_52 ) ;
F_42 ( & V_3 -> V_1 , F_1 ) ;
}
V_10 -> V_139 = NULL ;
F_26 ( V_59 ) ;
}
static int T_5 F_87 ( void )
{
int V_159 ;
V_129 = F_88 ( L_23 , V_160 , 0 ) ;
if ( ! V_129 ) {
return V_97 ;
}
V_159 = F_89 ( & V_161 ) ;
if ( V_159 != 0 ) {
F_90 ( V_101 L_24 ,
V_45 ) ;
F_91 ( V_129 ) ;
}
return V_159 ;
}
static void T_6 F_92 ( void )
{
F_93 ( & V_161 ) ;
F_91 ( V_129 ) ;
}
