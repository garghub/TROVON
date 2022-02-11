static int F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 * V_4 , T_2 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_7 [ V_5 ] ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_10 ;
T_2 V_11 ;
T_2 V_12 ;
T_2 V_13 ;
V_3 = F_2 ( V_3 , V_14 ) ;
V_7 -> V_15 = V_3 ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 ++ ) {
V_7 -> V_16 [ V_10 ] = V_4 [ V_10 ] ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_15 ; V_10 ++ ) {
V_12 = ( V_7 -> V_16 [ V_10 ] >> 5 ) & 0x7F ;
V_11 = V_7 -> V_16 [ V_10 ] & 0x1F ;
V_13 = F_3 ( V_9 , F_4 ( V_12 ) ) ;
V_13 |= ( 1 << V_11 ) ;
F_5 ( V_9 , F_4 ( V_12 ) , V_13 ) ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
F_7 (pos, &adapter->vf_mvs.l) {
V_20 = F_8 ( V_18 , struct V_19 , V_21 ) ;
if ( V_20 -> free == false )
V_9 -> V_22 . V_23 . V_24 ( V_9 , V_20 -> V_25 ,
V_20 -> V_26 ,
V_20 -> V_5 , V_27 ) ;
}
}
void F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_6 * V_7 ;
int V_10 , V_28 ;
T_2 V_11 ;
T_2 V_12 ;
T_2 V_13 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_29 ; V_10 ++ ) {
V_7 = & V_2 -> V_7 [ V_10 ] ;
for ( V_28 = 0 ; V_28 < V_7 -> V_15 ; V_28 ++ ) {
V_9 -> V_30 . V_31 ++ ;
V_12 = ( V_7 -> V_16 [ V_28 ] >> 5 ) & 0x7F ;
V_11 = V_7 -> V_16 [ V_28 ] & 0x1F ;
V_13 = F_3 ( V_9 , F_4 ( V_12 ) ) ;
V_13 |= ( 1 << V_11 ) ;
F_5 ( V_9 , F_4 ( V_12 ) , V_13 ) ;
}
}
F_6 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_32 , int V_33 ,
T_2 V_5 )
{
return V_2 -> V_9 . V_22 . V_23 . V_34 ( & V_2 -> V_9 , V_33 , V_5 , ( bool ) V_32 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_2 * V_35 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_36 = V_35 [ 1 ] ;
T_2 V_37 ;
int V_38 = V_36 + V_39 + V_40 ;
if ( V_2 -> V_9 . V_22 . type != V_41 )
return;
if ( ( V_36 < 68 ) || ( V_38 > V_42 ) ) {
F_12 ( V_43 , L_1 , V_36 ) ;
return;
}
V_37 = ( F_3 ( V_9 , V_44 ) &
V_45 ) >> V_46 ;
if ( V_37 < V_36 ) {
V_37 = V_36 << V_46 ;
F_5 ( V_9 , V_44 , V_37 ) ;
}
F_13 ( V_9 , L_2 , V_36 ) ;
}
static void F_14 ( struct V_8 * V_9 , T_2 V_5 , bool V_47 )
{
T_2 V_48 = F_3 ( V_9 , F_15 ( V_5 ) ) ;
V_48 |= ( V_49 |
V_50 ) ;
if ( V_47 )
V_48 |= V_51 ;
else
V_48 &= ~ V_51 ;
F_5 ( V_9 , F_15 ( V_5 ) , V_48 ) ;
}
static void F_16 ( struct V_1 * V_2 , T_2 V_33 , T_2 V_5 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
if ( V_33 )
F_5 ( V_9 , F_17 ( V_5 ) ,
( V_33 | V_52 ) ) ;
else
F_5 ( V_9 , F_17 ( V_5 ) , 0 ) ;
}
static inline void F_18 ( struct V_1 * V_2 , T_2 V_5 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_25 = V_9 -> V_22 . V_53 - ( V_5 + 1 ) ;
if ( V_2 -> V_7 [ V_5 ] . V_54 ) {
F_10 ( V_2 , true ,
V_2 -> V_7 [ V_5 ] . V_54 , V_5 ) ;
F_16 ( V_2 ,
( V_2 -> V_7 [ V_5 ] . V_54 |
( V_2 -> V_7 [ V_5 ] . V_55 <<
V_56 ) ) , V_5 ) ;
F_14 ( V_9 , V_5 , false ) ;
} else {
F_16 ( V_2 , 0 , V_5 ) ;
F_14 ( V_9 , V_5 , true ) ;
}
V_2 -> V_7 [ V_5 ] . V_15 = 0 ;
F_19 ( V_2 -> V_57 ) ;
V_9 -> V_22 . V_23 . V_58 ( V_9 , V_25 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
int V_5 , unsigned char * V_59 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_25 = V_9 -> V_22 . V_53 - ( V_5 + 1 ) ;
memcpy ( V_2 -> V_7 [ V_5 ] . V_60 , V_59 , 6 ) ;
V_9 -> V_22 . V_23 . V_24 ( V_9 , V_25 , V_59 , V_5 , V_27 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
int V_5 , int V_61 , unsigned char * V_59 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
if ( V_61 <= 1 ) {
F_7 (pos, &adapter->vf_mvs.l) {
V_20 = F_8 ( V_18 , struct V_19 , V_21 ) ;
if ( V_20 -> V_5 == V_5 ) {
V_20 -> V_5 = - 1 ;
V_20 -> free = true ;
V_20 -> V_62 = false ;
V_9 -> V_22 . V_23 . V_58 ( V_9 , V_20 -> V_25 ) ;
}
}
}
if ( ! V_61 )
return 0 ;
V_20 = NULL ;
F_7 (pos, &adapter->vf_mvs.l) {
V_20 = F_8 ( V_18 , struct V_19 , V_21 ) ;
if ( V_20 -> free )
break;
}
if ( ! V_20 || ! V_20 -> free )
return - V_63 ;
V_20 -> free = false ;
V_20 -> V_62 = true ;
V_20 -> V_5 = V_5 ;
memcpy ( V_20 -> V_26 , V_59 , V_64 ) ;
V_9 -> V_22 . V_23 . V_24 ( V_9 , V_20 -> V_25 , V_59 , V_5 , V_27 ) ;
return 0 ;
}
int F_22 ( struct V_65 * V_66 , unsigned int V_67 )
{
unsigned char V_68 [ 6 ] ;
struct V_1 * V_2 = F_23 ( V_66 ) ;
unsigned int V_69 = ( V_67 & 0x3f ) ;
bool V_70 = ( ( V_67 & 0x10000000U ) != 0 ) ;
if ( V_70 ) {
F_24 ( V_68 ) ;
F_13 ( V_71 , L_3 ,
V_69 , V_68 ) ;
memcpy ( V_2 -> V_7 [ V_69 ] . V_60 , V_68 , 6 ) ;
}
return 0 ;
}
static inline void F_25 ( struct V_1 * V_2 , T_2 V_5 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_2 V_72 ;
T_2 V_73 , V_74 ;
V_74 = V_5 % 32 ;
V_73 = V_5 / 32 ;
V_72 = F_3 ( V_9 , F_26 ( V_73 ) ) ;
V_72 |= ( V_72 | ( 1 << V_74 ) ) ;
F_5 ( V_9 , F_26 ( V_73 ) , V_72 ) ;
V_72 = F_3 ( V_9 , F_27 ( V_73 ) ) ;
V_72 |= ( V_72 | ( 1 << V_74 ) ) ;
F_5 ( V_9 , F_27 ( V_73 ) , V_72 ) ;
V_72 = F_3 ( V_9 , F_28 ( V_73 ) ) ;
V_72 |= ( 1 << V_74 ) ;
F_5 ( V_9 , F_28 ( V_73 ) , V_72 ) ;
F_18 ( V_2 , V_5 ) ;
}
static int F_29 ( struct V_1 * V_2 , T_2 V_5 )
{
T_2 V_75 = V_76 ;
T_2 V_35 [ V_76 ] ;
struct V_8 * V_9 = & V_2 -> V_9 ;
T_3 V_77 ;
int V_3 ;
T_1 * V_4 ;
int V_32 , V_33 , V_61 ;
T_4 * V_78 ;
V_77 = F_30 ( V_9 , V_35 , V_75 , V_5 ) ;
if ( V_77 )
F_31 ( L_4 ) ;
if ( V_35 [ 0 ] & ( V_79 | V_80 ) )
return V_77 ;
if ( V_35 [ 0 ] == V_81 ) {
unsigned char * V_82 = V_2 -> V_7 [ V_5 ] . V_60 ;
V_78 = ( T_4 * ) ( & V_35 [ 1 ] ) ;
F_13 ( V_71 , L_5 , V_5 ) ;
V_2 -> V_7 [ V_5 ] . V_83 = false ;
F_25 ( V_2 , V_5 ) ;
V_2 -> V_7 [ V_5 ] . V_83 = true ;
if ( F_32 ( V_78 ) &&
! V_2 -> V_7 [ V_5 ] . V_84 )
F_20 ( V_2 , V_5 , V_82 ) ;
else
F_20 ( V_2 ,
V_5 , V_2 -> V_7 [ V_5 ] . V_60 ) ;
V_35 [ 0 ] = V_81 | V_79 ;
memcpy ( V_78 , V_82 , V_85 ) ;
V_35 [ 3 ] = V_9 -> V_22 . V_86 ;
F_33 ( V_9 , V_35 , V_87 , V_5 ) ;
return V_77 ;
}
if ( ! V_2 -> V_7 [ V_5 ] . V_83 ) {
V_35 [ 0 ] |= V_80 ;
F_33 ( V_9 , V_35 , 1 , V_5 ) ;
return V_77 ;
}
switch ( ( V_35 [ 0 ] & 0xFFFF ) ) {
case V_88 :
V_78 = ( ( T_4 * ) ( & V_35 [ 1 ] ) ) ;
if ( F_32 ( V_78 ) &&
! V_2 -> V_7 [ V_5 ] . V_84 ) {
F_20 ( V_2 , V_5 , V_78 ) ;
} else if ( memcmp ( V_2 -> V_7 [ V_5 ] . V_60 ,
V_78 , V_64 ) ) {
F_34 ( V_43 , L_6
L_7
L_8 , V_5 ) ;
V_77 = - 1 ;
}
break;
case V_89 :
V_3 = ( V_35 [ 0 ] & V_90 )
>> V_91 ;
V_4 = ( T_1 * ) & V_35 [ 1 ] ;
V_77 = F_1 ( V_2 , V_3 ,
V_4 , V_5 ) ;
break;
case V_92 :
F_11 ( V_2 , V_35 ) ;
break;
case V_93 :
V_32 = ( V_35 [ 0 ] & V_90 )
>> V_91 ;
V_33 = ( V_35 [ 1 ] & V_94 ) ;
if ( V_2 -> V_7 [ V_5 ] . V_54 ) {
F_34 ( V_43 , L_6
L_9
L_10 ,
V_5 ) ;
V_77 = - 1 ;
} else {
V_77 = F_10 ( V_2 , V_32 , V_33 , V_5 ) ;
}
break;
case V_95 :
V_61 = ( V_35 [ 0 ] & V_90 ) >>
V_91 ;
if ( V_61 > 0 && V_2 -> V_96 ) {
V_9 -> V_22 . V_23 . V_97 ( V_9 , false ,
V_2 -> V_29 ) ;
V_9 -> V_22 . V_23 . V_98 ( V_9 , false , V_5 ) ;
V_2 -> V_96 = false ;
}
V_77 = F_21 ( V_2 , V_5 , V_61 ,
( unsigned char * ) ( & V_35 [ 1 ] ) ) ;
break;
default:
F_12 ( V_43 , L_11 , V_35 [ 0 ] ) ;
V_77 = V_99 ;
break;
}
if ( V_77 )
V_35 [ 0 ] |= V_80 ;
else
V_35 [ 0 ] |= V_79 ;
V_35 [ 0 ] |= V_100 ;
F_33 ( V_9 , V_35 , 1 , V_5 ) ;
return V_77 ;
}
static void F_35 ( struct V_1 * V_2 , T_2 V_5 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_2 V_101 = V_80 ;
if ( ! V_2 -> V_7 [ V_5 ] . V_83 )
F_33 ( V_9 , & V_101 , 1 , V_5 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_2 V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_29 ; V_5 ++ ) {
if ( ! F_37 ( V_9 , V_5 ) )
F_18 ( V_2 , V_5 ) ;
if ( ! F_38 ( V_9 , V_5 ) )
F_29 ( V_2 , V_5 ) ;
if ( ! F_39 ( V_9 , V_5 ) )
F_35 ( V_2 , V_5 ) ;
}
}
void F_40 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
F_5 ( V_9 , F_26 ( 0 ) , 0 ) ;
F_5 ( V_9 , F_26 ( 1 ) , 0 ) ;
F_5 ( V_9 , F_27 ( 0 ) , 0 ) ;
F_5 ( V_9 , F_27 ( 1 ) , 0 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
T_2 V_102 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_29 ; V_10 ++ ) {
V_102 = V_103 ;
if ( V_2 -> V_7 [ V_10 ] . V_83 )
V_102 |= V_100 ;
F_33 ( V_9 , & V_102 , 1 , V_10 ) ;
}
}
int F_42 ( struct V_104 * V_57 , int V_5 , T_4 * V_22 )
{
struct V_1 * V_2 = F_43 ( V_57 ) ;
if ( ! F_32 ( V_22 ) || ( V_5 >= V_2 -> V_29 ) )
return - V_105 ;
V_2 -> V_7 [ V_5 ] . V_84 = true ;
F_44 ( & V_2 -> V_66 -> V_106 , L_12 , V_22 , V_5 ) ;
F_44 ( & V_2 -> V_66 -> V_106 , L_13
L_14 ) ;
if ( F_45 ( V_107 , & V_2 -> V_108 ) ) {
F_46 ( & V_2 -> V_66 -> V_106 , L_15
L_16 ) ;
F_46 ( & V_2 -> V_66 -> V_106 , L_17
L_18 ) ;
}
return F_20 ( V_2 , V_5 , V_22 ) ;
}
int F_47 ( struct V_104 * V_57 , int V_5 , T_1 V_109 , T_4 V_110 )
{
int V_111 = 0 ;
struct V_1 * V_2 = F_43 ( V_57 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
if ( ( V_5 >= V_2 -> V_29 ) || ( V_109 > 4095 ) || ( V_110 > 7 ) )
return - V_105 ;
if ( V_109 || V_110 ) {
V_111 = F_10 ( V_2 , true , V_109 , V_5 ) ;
if ( V_111 )
goto V_112;
F_16 ( V_2 , V_109 | ( V_110 << V_56 ) , V_5 ) ;
F_14 ( V_9 , V_5 , false ) ;
if ( V_2 -> V_96 )
V_9 -> V_22 . V_23 . V_98 ( V_9 , true , V_5 ) ;
V_2 -> V_7 [ V_5 ] . V_54 = V_109 ;
V_2 -> V_7 [ V_5 ] . V_55 = V_110 ;
F_44 ( & V_2 -> V_66 -> V_106 ,
L_19 , V_109 , V_110 , V_5 ) ;
if ( F_45 ( V_107 , & V_2 -> V_108 ) ) {
F_46 ( & V_2 -> V_66 -> V_106 ,
L_20
L_16 ) ;
F_46 ( & V_2 -> V_66 -> V_106 ,
L_17
L_18 ) ;
}
} else {
V_111 = F_10 ( V_2 , false ,
V_2 -> V_7 [ V_5 ] . V_54 , V_5 ) ;
F_16 ( V_2 , V_109 , V_5 ) ;
F_14 ( V_9 , V_5 , true ) ;
V_9 -> V_22 . V_23 . V_98 ( V_9 , false , V_5 ) ;
V_2 -> V_7 [ V_5 ] . V_54 = 0 ;
V_2 -> V_7 [ V_5 ] . V_55 = 0 ;
}
V_112:
return V_111 ;
}
static int F_48 ( int V_113 )
{
switch ( V_113 ) {
case V_114 :
return 100 ;
case V_115 :
return 1000 ;
case V_116 :
return 10000 ;
default:
return 0 ;
}
}
static void F_49 ( struct V_8 * V_9 , int V_5 , int V_117 ,
int V_118 )
{
int V_119 , V_120 ;
T_2 V_121 ;
if ( V_117 != 0 ) {
V_120 = V_118 / V_117 ;
V_119 = ( V_118 - ( V_120 * V_117 ) ) ;
V_119 = ( V_119 * ( 1 << V_122 ) ) / V_117 ;
V_121 = V_123 ;
V_121 |= ( ( V_120 << V_122 ) &
V_124 ) ;
V_121 |= ( V_119 & V_125 ) ;
} else {
V_121 = 0 ;
}
F_5 ( V_9 , V_126 , 2 * V_5 ) ;
switch ( V_9 -> V_22 . type ) {
case V_127 :
F_5 ( V_9 , V_128 , 0x4 ) ;
break;
case V_41 :
F_5 ( V_9 , V_128 , 0x14 ) ;
break;
default:
break;
}
F_5 ( V_9 , V_129 , V_121 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
int V_130 , V_10 ;
bool V_131 = false ;
if ( V_2 -> V_132 == 0 )
return;
V_130 = F_48 ( V_2 -> V_118 ) ;
if ( V_130 != V_2 -> V_132 ) {
V_131 = true ;
V_2 -> V_132 = 0 ;
F_44 ( & V_2 -> V_66 -> V_106 ,
L_21
L_22 ) ;
}
for ( V_10 = 0 ; V_10 < V_2 -> V_29 ; V_10 ++ ) {
if ( V_131 )
V_2 -> V_7 [ V_10 ] . V_117 = 0 ;
F_49 ( & V_2 -> V_9 , V_10 ,
V_2 -> V_7 [ V_10 ] . V_117 ,
V_130 ) ;
}
}
int F_51 ( struct V_104 * V_57 , int V_5 , int V_117 )
{
struct V_1 * V_2 = F_43 ( V_57 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_130 ;
V_130 = F_48 ( V_2 -> V_118 ) ;
if ( ( V_5 >= V_2 -> V_29 ) || ( ! V_2 -> V_133 ) ||
( V_117 > V_130 ) || ( V_130 != 10000 ) ||
( ( V_117 != 0 ) && ( V_117 <= 10 ) ) )
return - V_105 ;
V_2 -> V_132 = V_130 ;
V_2 -> V_7 [ V_5 ] . V_117 = ( T_1 ) V_117 ;
F_49 ( V_9 , V_5 , V_117 , V_130 ) ;
return 0 ;
}
int F_52 ( struct V_104 * V_57 ,
int V_5 , struct V_134 * V_135 )
{
struct V_1 * V_2 = F_43 ( V_57 ) ;
if ( V_5 >= V_2 -> V_29 )
return - V_105 ;
V_135 -> V_5 = V_5 ;
memcpy ( & V_135 -> V_22 , V_2 -> V_7 [ V_5 ] . V_60 , V_64 ) ;
V_135 -> V_117 = V_2 -> V_7 [ V_5 ] . V_117 ;
V_135 -> V_109 = V_2 -> V_7 [ V_5 ] . V_54 ;
V_135 -> V_110 = V_2 -> V_7 [ V_5 ] . V_55 ;
return 0 ;
}
