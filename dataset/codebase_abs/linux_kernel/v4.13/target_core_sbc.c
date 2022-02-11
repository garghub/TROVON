static T_1
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_6 = V_2 -> V_7 ;
unsigned long long V_8 = V_4 -> V_9 -> V_10 ( V_4 ) ;
unsigned char * V_11 ;
unsigned char V_12 [ 8 ] ;
T_2 V_13 ;
if ( ! ( V_6 [ 8 ] & 1 ) && ! ! ( V_6 [ 2 ] | V_6 [ 3 ] | V_6 [ 4 ] | V_6 [ 5 ] ) )
return V_14 ;
if ( V_8 >= 0x00000000ffffffff )
V_13 = 0xffffffff ;
else
V_13 = ( T_2 ) V_8 ;
F_2 ( V_13 , & V_12 [ 0 ] ) ;
F_2 ( V_4 -> V_15 . V_16 , & V_12 [ 4 ] ) ;
V_11 = F_3 ( V_2 ) ;
if ( V_11 ) {
memcpy ( V_11 , V_12 , F_4 ( T_2 , sizeof( V_12 ) , V_2 -> V_17 ) ) ;
F_5 ( V_2 ) ;
}
F_6 ( V_2 , V_18 , 8 ) ;
return 0 ;
}
static T_1
F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_19 * V_20 = V_2 -> V_21 ;
int V_22 = V_4 -> V_15 . V_22 ;
unsigned char * V_11 ;
unsigned char V_12 [ 32 ] ;
unsigned long long V_13 = V_4 -> V_9 -> V_10 ( V_4 ) ;
memset ( V_12 , 0 , sizeof( V_12 ) ) ;
F_8 ( V_13 , & V_12 [ 0 ] ) ;
F_2 ( V_4 -> V_15 . V_16 , & V_12 [ 8 ] ) ;
if ( V_20 -> V_23 & ( V_24 | V_25 ) ) {
if ( ! V_22 )
V_22 = V_20 -> V_26 ;
if ( V_22 )
V_12 [ 12 ] = ( V_22 - 1 ) << 1 | 0x1 ;
}
if ( V_4 -> V_9 -> V_27 )
V_12 [ 13 ] = V_4 -> V_9 -> V_27 ( V_4 ) & 0x0f ;
if ( V_4 -> V_9 -> V_28 ) {
T_3 V_29 = V_4 -> V_9 -> V_28 ( V_4 ) ;
F_9 ( V_29 , & V_12 [ 14 ] ) ;
}
if ( V_4 -> V_15 . V_30 || V_4 -> V_15 . V_31 ) {
V_12 [ 14 ] |= 0x80 ;
if ( V_4 -> V_15 . V_32 )
V_12 [ 14 ] |= 0x40 ;
}
V_11 = F_3 ( V_2 ) ;
if ( V_11 ) {
memcpy ( V_11 , V_12 , F_4 ( T_2 , sizeof( V_12 ) , V_2 -> V_17 ) ) ;
F_5 ( V_2 ) ;
}
F_6 ( V_2 , V_18 , 32 ) ;
return 0 ;
}
static T_1
F_10 ( struct V_1 * V_2 )
{
unsigned char * V_6 = V_2 -> V_7 ;
if ( ! ( V_6 [ 1 ] & 1 ) || V_6 [ 2 ] || V_6 [ 3 ] )
return V_14 ;
if ( V_6 [ 4 ] >> 4 & 0xf )
return V_14 ;
if ( ! ( V_6 [ 4 ] & 1 ) || ( V_6 [ 4 ] & 2 ) || ( V_6 [ 4 ] & 4 ) )
return V_14 ;
F_11 ( V_2 , V_33 ) ;
return 0 ;
}
T_4 F_12 ( struct V_1 * V_2 )
{
T_2 V_34 ;
if ( V_2 -> V_7 [ 0 ] == V_35 )
V_34 = F_13 ( & V_2 -> V_7 [ 7 ] ) ;
else if ( V_2 -> V_7 [ 0 ] == V_36 )
V_34 = F_14 ( & V_2 -> V_7 [ 10 ] ) ;
else
V_34 = F_14 ( & V_2 -> V_7 [ 28 ] ) ;
if ( V_34 )
return V_34 ;
return V_2 -> V_5 -> V_9 -> V_10 ( V_2 -> V_5 ) -
V_2 -> V_37 + 1 ;
}
static T_1
F_15 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
T_4 V_41 = F_12 ( V_2 ) ;
T_1 V_42 ;
if ( V_41 ) {
V_42 = V_39 -> V_43 ( V_2 , V_2 -> V_37 , V_41 ) ;
if ( V_42 )
return V_42 ;
}
F_11 ( V_2 , V_18 ) ;
return 0 ;
}
static T_1
F_16 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_18 ) ;
return 0 ;
}
static inline T_2 F_17 ( struct V_1 * V_2 , T_2 V_44 )
{
return V_2 -> V_5 -> V_15 . V_16 * V_44 ;
}
static inline T_2 F_18 ( unsigned char * V_6 )
{
return V_6 [ 4 ] ? : 256 ;
}
static inline T_2 F_19 ( unsigned char * V_6 )
{
return F_13 ( & V_6 [ 7 ] ) ;
}
static inline T_2 F_20 ( unsigned char * V_6 )
{
return F_14 ( & V_6 [ 6 ] ) ;
}
static inline T_2 F_21 ( unsigned char * V_6 )
{
return F_14 ( & V_6 [ 10 ] ) ;
}
static inline T_2 F_22 ( unsigned char * V_6 )
{
return F_14 ( & V_6 [ 28 ] ) ;
}
static inline T_2 F_23 ( unsigned char * V_6 )
{
return F_24 ( & V_6 [ 1 ] ) & 0x1fffff ;
}
static inline T_2 F_25 ( unsigned char * V_6 )
{
return F_14 ( & V_6 [ 2 ] ) ;
}
static inline unsigned long long F_26 ( unsigned char * V_6 )
{
return F_27 ( & V_6 [ 2 ] ) ;
}
static inline unsigned long long F_28 ( unsigned char * V_6 )
{
return F_27 ( & V_6 [ 12 ] ) ;
}
static T_1
F_29 ( struct V_1 * V_2 , unsigned char * V_45 , struct V_38 * V_39 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_4 V_46 = V_4 -> V_9 -> V_10 ( V_4 ) + 1 ;
unsigned int V_44 = F_12 ( V_2 ) ;
T_1 V_42 ;
if ( ( V_45 [ 0 ] & 0x04 ) || ( V_45 [ 0 ] & 0x02 ) ) {
F_30 ( L_1
L_2
L_3 ) ;
return V_47 ;
}
if ( V_44 > V_2 -> V_5 -> V_15 . V_48 ) {
F_31 ( L_4 ,
V_44 , V_2 -> V_5 -> V_15 . V_48 ) ;
return V_14 ;
}
if ( ( ( V_2 -> V_37 + V_44 ) < V_2 -> V_37 ) ||
( ( V_2 -> V_37 + V_44 ) > V_46 ) ) {
F_30 ( L_5 ,
( unsigned long long ) V_46 , V_2 -> V_37 , V_44 ) ;
return V_49 ;
}
if ( V_45 [ 0 ] & 0x10 ) {
F_31 ( L_6 ) ;
return V_14 ;
}
if ( V_45 [ 0 ] & 0x08 ) {
if ( ! V_39 -> V_43 )
return V_47 ;
if ( ! V_4 -> V_15 . V_31 ) {
F_30 ( L_7
L_8 ) ;
return V_47 ;
}
V_2 -> V_50 = F_15 ;
return 0 ;
}
if ( ! V_39 -> V_51 )
return V_47 ;
V_42 = F_32 ( V_4 , V_2 , & V_2 -> V_7 [ 0 ] , V_44 , true ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_50 = V_39 -> V_51 ;
return 0 ;
}
static T_1 F_33 ( struct V_1 * V_2 , bool V_52 ,
int * V_53 )
{
unsigned char * V_12 , * V_54 ;
struct V_55 * V_56 ;
unsigned int V_57 ;
T_1 V_42 = V_58 ;
int V_59 , V_60 ;
V_12 = F_34 ( V_2 -> V_17 , V_61 ) ;
if ( ! V_12 ) {
F_30 ( L_9 ) ;
return V_62 ;
}
F_35 ( V_2 -> V_63 ,
V_2 -> V_64 ,
V_12 ,
V_2 -> V_17 ) ;
V_57 = 0 ;
F_36 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, count) {
V_54 = F_37 ( F_38 ( V_56 ) ) ;
if ( ! V_54 ) {
V_42 = V_62 ;
goto V_65;
}
for ( V_59 = 0 ; V_59 < V_56 -> V_66 ; V_59 ++ )
* ( V_54 + V_56 -> V_57 + V_59 ) ^= * ( V_12 + V_57 + V_59 ) ;
V_57 += V_56 -> V_66 ;
F_39 ( V_54 ) ;
}
V_65:
F_40 ( V_12 ) ;
return V_42 ;
}
static T_1
F_41 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
return V_39 -> V_67 ( V_2 , V_2 -> V_63 , V_2 -> V_64 ,
V_2 -> V_68 ) ;
}
static T_1 F_42 ( struct V_1 * V_2 , bool V_52 ,
int * V_53 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_42 = V_58 ;
F_43 ( & V_2 -> V_69 ) ;
if ( V_2 -> V_70 & V_71 ) {
V_2 -> V_72 |= V_73 ;
* V_53 = 1 ;
if ( V_2 -> V_74 == V_75 )
V_42 = V_76 ;
}
F_44 ( & V_2 -> V_69 ) ;
F_45 ( & V_4 -> V_77 ) ;
return V_42 ;
}
static T_1 F_46 ( struct V_1 * V_2 , bool V_52 ,
int * V_53 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_55 * V_78 = NULL , * V_56 ;
unsigned char * V_12 = NULL , * V_54 ;
struct V_79 V_80 ;
unsigned int V_57 = 0 , V_81 ;
unsigned int V_82 = V_2 -> V_83 ;
unsigned int V_16 = V_4 -> V_15 . V_16 ;
unsigned int V_84 = ( V_82 * V_16 ) ;
T_1 V_42 = V_58 ;
int V_85 , V_59 ;
if ( ! V_52 && ( ! V_2 -> V_63 || ! V_2 -> V_86 ) )
return V_58 ;
if ( ! V_2 -> V_17 )
goto V_65;
if ( V_2 -> V_74 ) {
F_47 ( L_10
L_11 , V_2 -> V_74 ) ;
* V_53 = 1 ;
if ( V_2 -> V_74 == V_75 )
V_42 = V_76 ;
goto V_65;
}
V_12 = F_48 ( V_2 -> V_17 , V_61 ) ;
if ( ! V_12 ) {
F_30 ( L_12 ) ;
V_42 = V_62 ;
goto V_65;
}
V_78 = F_49 ( V_2 -> V_64 , sizeof( * V_78 ) ,
V_61 ) ;
if ( ! V_78 ) {
F_30 ( L_13 ) ;
V_42 = V_62 ;
goto V_65;
}
F_50 ( V_78 , V_2 -> V_64 ) ;
V_85 = F_35 ( V_2 -> V_63 , V_2 -> V_64 , V_12 ,
V_2 -> V_17 ) ;
if ( ! V_85 ) {
F_30 ( L_14 ) ;
V_42 = V_62 ;
goto V_65;
}
F_36 (cmd->t_bidi_data_sg, sg, cmd->t_bidi_data_nents, i) {
V_54 = ( unsigned char * ) F_37 ( F_38 ( V_56 ) ) ;
if ( ! V_54 ) {
V_42 = V_62 ;
goto V_65;
}
V_81 = F_51 ( V_56 -> V_66 , V_84 ) ;
if ( memcmp ( V_54 , V_12 + V_57 , V_81 ) ) {
F_31 ( L_15 ,
V_54 , V_12 + V_57 ) ;
F_39 ( V_54 ) ;
goto V_87;
}
F_39 ( V_54 ) ;
V_57 += V_81 ;
V_84 -= V_81 ;
if ( ! V_84 )
break;
}
V_59 = 0 ;
V_81 = V_2 -> V_83 * V_16 ;
F_52 ( & V_80 , V_2 -> V_63 , V_2 -> V_64 , V_88 ) ;
while ( V_81 ) {
F_53 ( & V_80 ) ;
if ( V_16 < V_89 ) {
F_54 ( & V_78 [ V_59 ] , V_80 . V_90 , V_16 ,
V_80 . V_91 . V_56 -> V_57 + V_16 ) ;
} else {
F_53 ( & V_80 ) ;
F_54 ( & V_78 [ V_59 ] , V_80 . V_90 , V_16 ,
V_80 . V_91 . V_56 -> V_57 ) ;
}
V_81 -= V_16 ;
V_59 ++ ;
}
F_55 ( & V_80 ) ;
V_2 -> V_92 = V_2 -> V_63 ;
V_2 -> V_63 = V_78 ;
V_2 -> V_93 = V_2 -> V_64 ;
V_2 -> V_64 = 1 ;
V_2 -> V_94 = V_95 ;
V_2 -> V_96 = F_42 ;
V_2 -> V_50 = F_41 ;
F_43 ( & V_2 -> V_69 ) ;
V_2 -> V_97 = V_98 ;
V_2 -> V_70 |= V_99 | V_71 ;
F_44 ( & V_2 -> V_69 ) ;
F_56 ( V_2 , false ) ;
F_40 ( V_12 ) ;
return V_42 ;
V_87:
F_31 ( L_16 ,
V_4 -> V_9 -> V_100 ) ;
V_42 = V_101 ;
V_65:
F_45 ( & V_4 -> V_77 ) ;
F_40 ( V_78 ) ;
F_40 ( V_12 ) ;
return V_42 ;
}
static T_1
F_57 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_42 ;
int V_85 ;
V_85 = F_58 ( & V_4 -> V_77 ) ;
if ( V_85 != 0 ) {
V_2 -> V_96 = NULL ;
return V_76 ;
}
V_2 -> V_17 = V_2 -> V_83 * V_4 -> V_15 . V_16 ;
V_42 = V_39 -> V_67 ( V_2 , V_2 -> V_86 , V_2 -> V_102 ,
V_103 ) ;
if ( V_42 ) {
V_2 -> V_96 = NULL ;
F_45 ( & V_4 -> V_77 ) ;
return V_42 ;
}
return V_58 ;
}
static int
F_59 ( T_5 V_104 , bool V_105 , enum V_106 V_107 ,
bool V_108 , struct V_1 * V_2 )
{
if ( V_108 ) {
V_2 -> V_109 = V_105 ? V_110 :
V_104 ? V_25 :
V_111 ;
switch ( V_104 ) {
case 0x0 :
case 0x3 :
V_2 -> V_112 = 0 ;
break;
case 0x1 :
case 0x5 :
V_2 -> V_112 = V_113 ;
if ( V_107 == V_114 )
V_2 -> V_112 |= V_115 ;
break;
case 0x2 :
if ( V_107 == V_114 )
V_2 -> V_112 = V_115 ;
break;
case 0x4 :
V_2 -> V_112 = V_113 ;
break;
default:
F_30 ( L_17 , V_104 ) ;
return - V_116 ;
}
} else {
V_2 -> V_109 = V_105 ? V_117 :
V_104 ? V_24 :
V_118 ;
switch ( V_104 ) {
case 0x0 :
case 0x1 :
case 0x5 :
V_2 -> V_112 = V_113 ;
if ( V_107 == V_114 )
V_2 -> V_112 |= V_115 ;
break;
case 0x2 :
if ( V_107 == V_114 )
V_2 -> V_112 = V_115 ;
break;
case 0x3 :
V_2 -> V_112 = 0 ;
break;
case 0x4 :
V_2 -> V_112 = V_113 ;
break;
default:
F_30 ( L_17 , V_104 ) ;
return - V_116 ;
}
}
return 0 ;
}
static T_1
F_32 ( struct V_3 * V_4 , struct V_1 * V_2 , unsigned char * V_6 ,
T_2 V_44 , bool V_108 )
{
T_5 V_104 = V_6 [ 1 ] >> 5 ;
int V_119 = V_2 -> V_21 -> V_23 ;
int V_22 = V_4 -> V_15 . V_22 ;
bool V_105 = false ;
if ( ! V_2 -> V_120 || ! V_2 -> V_121 ) {
if ( F_60 ( V_104 &&
! V_4 -> V_15 . V_22 && ! V_2 -> V_21 -> V_26 ) ) {
F_30 ( L_18
L_19 ) ;
return V_14 ;
}
if ( V_2 -> V_122 )
return V_58 ;
}
switch ( V_4 -> V_15 . V_22 ) {
case V_123 :
V_2 -> V_124 = 0xffffffff ;
break;
case V_125 :
if ( V_104 )
return V_14 ;
V_2 -> V_124 = V_2 -> V_37 ;
break;
case V_114 :
V_2 -> V_124 = V_2 -> V_37 ;
break;
case V_126 :
V_105 = V_108 ?
! ! ( V_119 & ( V_25 | V_110 ) ) :
! ! ( V_119 & ( V_24 | V_117 ) ) ;
if ( V_105 && V_2 -> V_21 -> V_26 ) {
V_22 = V_2 -> V_21 -> V_26 ;
break;
}
if ( ! V_104 )
return V_58 ;
default:
F_30 ( L_20
L_21 , V_6 [ 0 ] , V_104 ) ;
return V_14 ;
}
if ( F_59 ( V_104 , V_105 , V_22 , V_108 , V_2 ) )
return V_14 ;
V_2 -> V_107 = V_22 ;
V_2 -> V_127 = V_4 -> V_127 * V_44 ;
if ( V_104 )
V_2 -> V_17 = V_44 * V_4 -> V_15 . V_16 ;
F_47 ( L_22
L_23 ,
V_128 , V_2 -> V_107 , V_2 -> V_17 , V_2 -> V_127 ,
V_2 -> V_109 , V_2 -> V_112 ) ;
return V_58 ;
}
static int
F_61 ( struct V_3 * V_4 , struct V_1 * V_2 , unsigned char * V_6 )
{
if ( V_6 [ 1 ] & 0x10 ) {
if ( ! F_62 ( V_4 ) ) {
F_30 ( L_24
L_25 , V_6 [ 0 ] ) ;
return - V_116 ;
}
}
if ( V_6 [ 1 ] & 0x8 ) {
if ( ! F_62 ( V_4 ) ) {
F_30 ( L_26
L_27 ,
V_6 [ 0 ] ) ;
return - V_116 ;
}
V_2 -> V_72 |= V_129 ;
}
return 0 ;
}
T_1
F_63 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_6 = V_2 -> V_7 ;
unsigned int V_130 ;
T_2 V_44 = 0 ;
T_1 V_42 ;
V_2 -> V_40 = V_39 ;
switch ( V_6 [ 0 ] ) {
case V_131 :
V_44 = F_18 ( V_6 ) ;
V_2 -> V_37 = F_23 ( V_6 ) ;
V_2 -> V_72 |= V_132 ;
V_2 -> V_50 = F_41 ;
break;
case V_133 :
V_44 = F_19 ( V_6 ) ;
V_2 -> V_37 = F_25 ( V_6 ) ;
if ( F_61 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_42 = F_32 ( V_4 , V_2 , V_6 , V_44 , false ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_72 |= V_132 ;
V_2 -> V_50 = F_41 ;
break;
case V_134 :
V_44 = F_20 ( V_6 ) ;
V_2 -> V_37 = F_25 ( V_6 ) ;
if ( F_61 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_42 = F_32 ( V_4 , V_2 , V_6 , V_44 , false ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_72 |= V_132 ;
V_2 -> V_50 = F_41 ;
break;
case V_135 :
V_44 = F_21 ( V_6 ) ;
V_2 -> V_37 = F_26 ( V_6 ) ;
if ( F_61 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_42 = F_32 ( V_4 , V_2 , V_6 , V_44 , false ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_72 |= V_132 ;
V_2 -> V_50 = F_41 ;
break;
case V_136 :
V_44 = F_18 ( V_6 ) ;
V_2 -> V_37 = F_23 ( V_6 ) ;
V_2 -> V_72 |= V_132 ;
V_2 -> V_50 = F_41 ;
break;
case V_137 :
case V_138 :
V_44 = F_19 ( V_6 ) ;
V_2 -> V_37 = F_25 ( V_6 ) ;
if ( F_61 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_42 = F_32 ( V_4 , V_2 , V_6 , V_44 , true ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_72 |= V_132 ;
V_2 -> V_50 = F_41 ;
break;
case V_139 :
V_44 = F_20 ( V_6 ) ;
V_2 -> V_37 = F_25 ( V_6 ) ;
if ( F_61 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_42 = F_32 ( V_4 , V_2 , V_6 , V_44 , true ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_72 |= V_132 ;
V_2 -> V_50 = F_41 ;
break;
case V_140 :
case V_141 :
V_44 = F_21 ( V_6 ) ;
V_2 -> V_37 = F_26 ( V_6 ) ;
if ( F_61 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_42 = F_32 ( V_4 , V_2 , V_6 , V_44 , true ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_72 |= V_132 ;
V_2 -> V_50 = F_41 ;
break;
case V_142 :
if ( V_2 -> V_68 != V_143 ||
! ( V_2 -> V_72 & V_144 ) )
return V_14 ;
V_44 = F_19 ( V_6 ) ;
if ( F_61 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_2 -> V_37 = F_25 ( V_6 ) ;
V_2 -> V_72 |= V_132 ;
V_2 -> V_50 = F_41 ;
V_2 -> V_96 = & F_33 ;
break;
case V_145 :
{
T_3 V_146 = F_13 ( & V_6 [ 8 ] ) ;
switch ( V_146 ) {
case V_147 :
V_44 = F_22 ( V_6 ) ;
if ( F_61 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_2 -> V_37 = F_28 ( V_6 ) ;
V_2 -> V_72 |= V_132 ;
V_2 -> V_50 = F_41 ;
V_2 -> V_96 = & F_33 ;
break;
case V_148 :
V_44 = F_22 ( V_6 ) ;
if ( ! V_44 ) {
F_30 ( L_28
L_29 ) ;
return V_14 ;
}
V_130 = F_17 ( V_2 , 1 ) ;
V_2 -> V_37 = F_27 ( & V_6 [ 12 ] ) ;
V_42 = F_29 ( V_2 , & V_6 [ 10 ] , V_39 ) ;
if ( V_42 )
return V_42 ;
break;
default:
F_30 ( L_30
L_31 , V_146 ) ;
return V_47 ;
}
break;
}
case V_149 :
if ( ! V_4 -> V_15 . V_150 ) {
F_64 ( L_32
L_33 , V_4 -> V_151 -> V_152 -> V_39 -> V_100 ,
V_4 -> V_153 . V_154 . V_155 , V_4 -> V_156 . V_157 ) ;
return V_47 ;
}
V_44 = V_6 [ 13 ] ;
if ( V_44 > 1 ) {
F_30 ( L_34
L_35 , V_44 ) ;
return V_14 ;
}
if ( F_61 ( V_4 , V_2 , V_6 ) )
return V_14 ;
V_130 = 2 * F_17 ( V_2 , V_44 ) ;
V_2 -> V_37 = F_27 ( & V_6 [ 2 ] ) ;
V_2 -> V_83 = V_44 ;
V_2 -> V_72 |= V_132 | V_158 ;
V_2 -> V_50 = F_57 ;
V_2 -> V_96 = F_46 ;
break;
case V_159 :
V_130 = V_160 ;
V_2 -> V_50 = F_1 ;
break;
case V_161 :
switch ( V_2 -> V_7 [ 1 ] & 0x1f ) {
case V_162 :
V_2 -> V_50 = F_7 ;
break;
case V_163 :
V_2 -> V_50 = V_164 ;
break;
default:
F_30 ( L_36 ,
V_2 -> V_7 [ 1 ] & 0x1f ) ;
return V_14 ;
}
V_130 = F_14 ( & V_6 [ 10 ] ) ;
break;
case V_165 :
case V_166 :
if ( V_6 [ 0 ] == V_165 ) {
V_44 = F_19 ( V_6 ) ;
V_2 -> V_37 = F_25 ( V_6 ) ;
} else {
V_44 = F_21 ( V_6 ) ;
V_2 -> V_37 = F_26 ( V_6 ) ;
}
if ( V_39 -> V_167 ) {
V_2 -> V_50 = V_39 -> V_167 ;
goto V_168;
}
V_130 = 0 ;
V_2 -> V_50 = F_16 ;
break;
case V_169 :
if ( ! V_39 -> V_43 )
return V_47 ;
if ( ! V_4 -> V_15 . V_30 ) {
F_30 ( L_37
L_38 ) ;
return V_47 ;
}
V_130 = F_13 ( & V_6 [ 7 ] ) ;
V_2 -> V_50 = V_170 ;
break;
case V_36 :
V_44 = F_21 ( V_6 ) ;
if ( ! V_44 ) {
F_30 ( L_39 ) ;
return V_14 ;
}
V_130 = F_17 ( V_2 , 1 ) ;
V_2 -> V_37 = F_27 ( & V_6 [ 2 ] ) ;
V_42 = F_29 ( V_2 , & V_6 [ 1 ] , V_39 ) ;
if ( V_42 )
return V_42 ;
break;
case V_35 :
V_44 = F_19 ( V_6 ) ;
if ( ! V_44 ) {
F_30 ( L_39 ) ;
return V_14 ;
}
V_130 = F_17 ( V_2 , 1 ) ;
V_2 -> V_37 = F_14 ( & V_6 [ 2 ] ) ;
V_42 = F_29 ( V_2 , & V_6 [ 1 ] , V_39 ) ;
if ( V_42 )
return V_42 ;
break;
case V_171 :
case V_172 :
V_130 = 0 ;
if ( V_6 [ 0 ] == V_171 ) {
V_44 = F_19 ( V_6 ) ;
V_2 -> V_37 = F_25 ( V_6 ) ;
} else {
V_44 = F_21 ( V_6 ) ;
V_2 -> V_37 = F_26 ( V_6 ) ;
}
V_2 -> V_50 = F_16 ;
goto V_168;
case V_173 :
case V_174 :
case V_175 :
V_130 = 0 ;
V_2 -> V_50 = F_16 ;
break;
case V_176 :
V_130 = 0 ;
V_2 -> V_50 = F_10 ;
break;
default:
V_42 = F_65 ( V_2 , & V_130 ) ;
if ( V_42 )
return V_42 ;
}
if ( ! V_2 -> V_50 )
return V_47 ;
if ( V_2 -> V_72 & V_132 ) {
unsigned long long V_46 ;
V_168:
V_46 = V_4 -> V_9 -> V_10 ( V_4 ) + 1 ;
if ( ( ( V_2 -> V_37 + V_44 ) < V_2 -> V_37 ) ||
( ( V_2 -> V_37 + V_44 ) > V_46 ) ) {
F_30 ( L_40
L_41 ,
V_46 , V_2 -> V_37 , V_44 ) ;
return V_49 ;
}
if ( ! ( V_2 -> V_72 & V_158 ) )
V_130 = F_17 ( V_2 , V_44 ) ;
}
return F_66 ( V_2 , V_130 ) ;
}
T_2 F_67 ( struct V_3 * V_4 )
{
return V_177 ;
}
static T_1
V_170 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char * V_12 , * V_178 = NULL ;
T_4 V_179 ;
int V_130 ;
T_2 V_180 ;
T_1 V_42 = 0 ;
int V_181 , V_182 ;
if ( V_2 -> V_7 [ 1 ] )
return V_14 ;
if ( V_2 -> V_17 == 0 ) {
F_11 ( V_2 , V_33 ) ;
return 0 ;
}
if ( V_2 -> V_17 < 8 ) {
F_31 ( L_42 ,
V_2 -> V_17 ) ;
return V_183 ;
}
V_12 = F_3 ( V_2 ) ;
if ( ! V_12 )
return V_76 ;
V_181 = F_13 ( & V_12 [ 0 ] ) ;
V_182 = F_13 ( & V_12 [ 2 ] ) ;
V_130 = V_2 -> V_17 - 8 ;
if ( V_182 > V_130 )
F_31 ( L_43 ,
V_2 -> V_17 , V_182 ) ;
else
V_130 = V_182 ;
if ( V_130 / 16 > V_4 -> V_15 . V_184 ) {
V_42 = V_185 ;
goto V_186;
}
V_178 = & V_12 [ 8 ] ;
F_47 ( L_44
L_45 , V_4 -> V_9 -> V_100 , V_181 , V_182 , V_130 , V_178 ) ;
while ( V_130 >= 16 ) {
V_179 = F_27 ( & V_178 [ 0 ] ) ;
V_180 = F_14 ( & V_178 [ 8 ] ) ;
F_47 ( L_46 ,
( unsigned long long ) V_179 , V_180 ) ;
if ( V_180 > V_4 -> V_15 . V_187 ) {
V_42 = V_185 ;
goto V_186;
}
if ( V_179 + V_180 > V_4 -> V_9 -> V_10 ( V_4 ) + 1 ) {
V_42 = V_49 ;
goto V_186;
}
V_42 = V_39 -> V_43 ( V_2 , V_179 , V_180 ) ;
if ( V_42 )
goto V_186;
V_178 += 16 ;
V_130 -= 16 ;
}
V_186:
F_5 ( V_2 ) ;
if ( ! V_42 )
F_11 ( V_2 , V_18 ) ;
return V_42 ;
}
void
F_68 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_188 * V_189 ;
struct V_55 * V_190 = V_2 -> V_63 , * V_191 ;
T_4 V_192 = V_2 -> V_37 ;
void * V_193 , * V_194 ;
int V_59 , V_195 , V_57 = 0 ;
unsigned int V_16 = V_4 -> V_15 . V_16 ;
F_36 (cmd->t_prot_sg, psg, cmd->t_prot_nents, i) {
V_194 = F_37 ( F_38 ( V_191 ) ) + V_191 -> V_57 ;
V_193 = F_37 ( F_38 ( V_190 ) ) + V_190 -> V_57 ;
for ( V_195 = 0 ; V_195 < V_191 -> V_66 ;
V_195 += sizeof( * V_189 ) ) {
T_6 V_196 ;
unsigned int V_197 ;
if ( V_57 >= V_190 -> V_66 ) {
V_57 -= V_190 -> V_66 ;
F_39 ( V_193 - V_190 -> V_57 ) ;
V_190 = F_69 ( V_190 ) ;
if ( ! V_190 ) {
F_39 ( V_194 - V_191 -> V_57 ) ;
return;
}
V_193 = F_37 ( F_38 ( V_190 ) ) + V_190 -> V_57 ;
}
V_189 = V_194 + V_195 ;
V_197 = F_51 ( V_16 , V_190 -> V_66 - V_57 ) ;
V_196 = F_70 ( V_193 + V_57 , V_197 ) ;
if ( V_197 < V_16 ) {
F_39 ( V_193 - V_190 -> V_57 ) ;
V_190 = F_69 ( V_190 ) ;
if ( ! V_190 ) {
F_39 ( V_194 - V_191 -> V_57 ) ;
return;
}
V_193 = F_37 ( F_38 ( V_190 ) ) + V_190 -> V_57 ;
V_57 = V_16 - V_197 ;
V_196 = F_71 ( V_196 , V_193 , V_57 ) ;
} else {
V_57 += V_16 ;
}
V_189 -> V_198 = F_72 ( V_196 ) ;
if ( V_2 -> V_107 == V_114 )
V_189 -> V_199 = F_73 ( V_192 & 0xffffffff ) ;
V_189 -> V_200 = 0 ;
F_47 ( L_47
L_48 ,
( V_2 -> V_68 == V_143 ) ?
L_49 : L_50 , ( unsigned long long ) V_192 ,
V_189 -> V_198 , V_189 -> V_200 ,
F_74 ( V_189 -> V_199 ) ) ;
V_192 ++ ;
}
F_39 ( V_193 - V_190 -> V_57 ) ;
F_39 ( V_194 - V_191 -> V_57 ) ;
}
}
static T_1
F_75 ( struct V_1 * V_2 , struct V_188 * V_189 ,
T_6 V_196 , T_4 V_192 , unsigned int V_201 )
{
T_7 V_202 ;
if ( ! ( V_2 -> V_112 & V_113 ) )
goto V_203;
V_202 = F_72 ( V_196 ) ;
if ( V_189 -> V_198 != V_202 ) {
F_30 ( L_51
L_52 , ( unsigned long long ) V_192 ,
F_76 ( V_189 -> V_198 ) , F_76 ( V_202 ) ) ;
return V_204 ;
}
V_203:
if ( ! ( V_2 -> V_112 & V_115 ) )
return 0 ;
if ( V_2 -> V_107 == V_114 &&
F_74 ( V_189 -> V_199 ) != ( V_192 & 0xffffffff ) ) {
F_30 ( L_53
L_54 , ( unsigned long long ) V_192 ,
F_74 ( V_189 -> V_199 ) , ( T_2 ) ( V_192 & 0xffffffff ) ) ;
return V_205 ;
}
if ( V_2 -> V_107 == V_125 &&
F_74 ( V_189 -> V_199 ) != V_201 ) {
F_30 ( L_55
L_56 , ( unsigned long long ) V_192 ,
F_74 ( V_189 -> V_199 ) , V_201 ) ;
return V_205 ;
}
return 0 ;
}
void F_77 ( struct V_1 * V_2 , unsigned int V_44 , bool V_206 ,
struct V_55 * V_56 , int V_207 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_55 * V_191 ;
void * V_194 , * V_54 ;
unsigned int V_59 , V_81 , V_208 ;
unsigned int V_57 = V_207 ;
if ( ! V_56 )
return;
V_208 = V_44 * V_4 -> V_127 ;
F_36 (cmd->t_prot_sg, psg, cmd->t_prot_nents, i) {
unsigned int V_209 , V_210 = 0 ;
V_194 = F_37 ( F_38 ( V_191 ) ) + V_191 -> V_57 ;
V_209 = F_51 ( V_208 , V_191 -> V_66 ) ;
while ( V_209 ) {
V_81 = F_51 ( V_209 , V_56 -> V_66 - V_57 ) ;
V_54 = F_37 ( F_38 ( V_56 ) ) + V_56 -> V_57 + V_57 ;
if ( V_206 )
memcpy ( V_194 + V_210 , V_54 , V_81 ) ;
else
memcpy ( V_54 , V_194 + V_210 , V_81 ) ;
V_208 -= V_81 ;
V_57 += V_81 ;
V_210 += V_81 ;
V_209 -= V_81 ;
F_39 ( V_54 - V_56 -> V_57 - V_57 ) ;
if ( V_57 >= V_56 -> V_66 ) {
V_56 = F_69 ( V_56 ) ;
V_57 = 0 ;
}
}
F_39 ( V_194 - V_191 -> V_57 ) ;
}
}
T_1
F_78 ( struct V_1 * V_2 , T_4 V_211 , unsigned int V_44 ,
unsigned int V_201 , struct V_55 * V_191 , int V_212 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_188 * V_189 ;
struct V_55 * V_190 = V_2 -> V_63 ;
T_4 V_192 = V_211 ;
void * V_193 , * V_194 ;
int V_59 ;
T_1 V_85 ;
int V_213 = 0 ;
unsigned int V_16 = V_4 -> V_15 . V_16 ;
for (; V_191 && V_192 < V_211 + V_44 ; V_191 = F_69 ( V_191 ) ) {
V_194 = F_37 ( F_38 ( V_191 ) ) + V_191 -> V_57 ;
V_193 = F_37 ( F_38 ( V_190 ) ) + V_190 -> V_57 ;
for ( V_59 = V_212 ; V_59 < V_191 -> V_66 &&
V_192 < V_211 + V_44 ;
V_59 += sizeof( * V_189 ) ) {
T_6 V_196 ;
unsigned int V_197 ;
if ( V_213 >= V_190 -> V_66 ) {
V_213 -= V_190 -> V_66 ;
F_39 ( V_193 - V_190 -> V_57 ) ;
V_190 = F_69 ( V_190 ) ;
if ( ! V_190 ) {
F_39 ( V_194 - V_191 -> V_57 ) ;
return 0 ;
}
V_193 = F_37 ( F_38 ( V_190 ) ) + V_190 -> V_57 ;
}
V_189 = V_194 + V_59 ;
F_47 ( L_57
L_48 ,
( unsigned long long ) V_192 , V_189 -> V_198 ,
V_189 -> V_200 , F_74 ( V_189 -> V_199 ) ) ;
if ( V_189 -> V_200 == V_214 ) {
V_213 += V_16 ;
goto V_215;
}
V_197 = F_51 ( V_16 , V_190 -> V_66 - V_213 ) ;
V_196 = F_70 ( V_193 + V_213 , V_197 ) ;
if ( V_197 < V_16 ) {
F_39 ( V_193 - V_190 -> V_57 ) ;
V_190 = F_69 ( V_190 ) ;
if ( ! V_190 ) {
F_39 ( V_194 - V_191 -> V_57 ) ;
return 0 ;
}
V_193 = F_37 ( F_38 ( V_190 ) ) + V_190 -> V_57 ;
V_213 = V_16 - V_197 ;
V_196 = F_71 ( V_196 , V_193 , V_213 ) ;
} else {
V_213 += V_16 ;
}
V_85 = F_75 ( V_2 , V_189 , V_196 , V_192 , V_201 ) ;
if ( V_85 ) {
F_39 ( V_193 - V_190 -> V_57 ) ;
F_39 ( V_194 - V_191 -> V_57 ) ;
V_2 -> V_216 = V_192 ;
return V_85 ;
}
V_215:
V_192 ++ ;
V_201 ++ ;
}
V_212 = 0 ;
F_39 ( V_193 - V_190 -> V_57 ) ;
F_39 ( V_194 - V_191 -> V_57 ) ;
}
return 0 ;
}
