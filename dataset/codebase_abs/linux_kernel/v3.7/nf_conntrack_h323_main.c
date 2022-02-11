static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 , enum V_6 V_7 ,
unsigned char * * V_8 , int * V_9 , int * V_10 )
{
struct V_11 * V_12 = F_2 ( V_5 ) ;
int V_13 = F_3 ( V_7 ) ;
const struct V_14 * V_15 ;
struct V_14 V_16 ;
int V_17 ;
int V_18 ;
unsigned char * V_19 ;
int V_20 ;
int V_21 ;
V_15 = F_4 ( V_2 , V_3 , sizeof( V_16 ) , & V_16 ) ;
if ( V_15 == NULL )
return 0 ;
V_18 = V_3 + V_15 -> V_22 * 4 ;
V_17 = V_2 -> V_23 - V_18 ;
if ( V_17 <= 0 )
goto V_24;
if ( * V_8 == NULL ) {
V_19 = F_4 ( V_2 , V_18 , V_17 ,
V_25 ) ;
F_5 ( V_19 == NULL ) ;
if ( V_17 < 4 || V_19 [ 0 ] != 0x03 || V_19 [ 1 ] != 0 ) {
if ( V_12 -> V_26 [ V_13 ] > 0 ) {
F_6 ( L_1
L_2
L_3 , V_12 -> V_26 [ V_13 ] ) ;
if ( V_12 -> V_26 [ V_13 ] <= V_17 ) {
* V_8 = V_19 ;
* V_9 = V_12 -> V_26 [ V_13 ] ;
* V_10 = 0 ;
goto V_27;
}
F_6 ( L_4 ) ;
goto V_24;
}
return 0 ;
}
V_21 = 0 ;
} else {
V_21 = * V_10 + * V_9 ;
V_17 -= V_21 ;
if ( V_17 <= 4 )
goto V_24;
V_19 = * V_8 + * V_9 ;
if ( V_19 [ 0 ] != 0x03 || V_19 [ 1 ] != 0 )
goto V_24;
}
V_20 = V_19 [ 2 ] * 256 + V_19 [ 3 ] ;
if ( V_20 < 4 )
goto V_24;
if ( V_20 > V_17 ) {
if ( V_17 == 4 ) {
F_6 ( L_5
L_6 ,
V_20 - 4 ) ;
V_12 -> V_26 [ V_13 ] = V_20 - 4 ;
return 0 ;
}
F_6 ( L_7 ) ;
goto V_24;
}
* V_8 = V_19 + 4 ;
* V_9 = V_20 - 4 ;
* V_10 = V_21 + 4 ;
V_27:
V_12 -> V_26 [ V_13 ] = 0 ;
return 1 ;
V_24:
V_12 -> V_26 [ V_13 ] = 0 ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 , const unsigned char * V_8 ,
T_1 * V_28 ,
union V_29 * V_30 , T_2 * V_31 )
{
const unsigned char * V_32 ;
int V_23 ;
if ( V_28 -> V_33 != V_34 )
return 0 ;
switch ( V_28 -> V_35 . V_33 ) {
case V_36 :
if ( F_8 ( V_5 ) != V_37 )
return 0 ;
V_32 = V_8 + V_28 -> V_35 . V_38 . V_39 ;
V_23 = 4 ;
break;
case V_40 :
if ( F_8 ( V_5 ) != V_41 )
return 0 ;
V_32 = V_8 + V_28 -> V_35 . V_42 . V_39 ;
V_23 = 16 ;
break;
default:
return 0 ;
}
memcpy ( V_30 , V_32 , V_23 ) ;
memset ( ( void * ) V_30 + V_23 , 0 , sizeof( * V_30 ) - V_23 ) ;
memcpy ( V_31 , V_32 + V_23 , sizeof( T_2 ) ) ;
return 1 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , int V_10 ,
T_1 * V_28 )
{
int V_13 = F_3 ( V_7 ) ;
int V_43 = 0 ;
T_2 V_31 ;
T_2 V_44 , V_45 ;
union V_29 V_30 ;
struct V_46 * V_47 ;
struct V_46 * V_48 ;
F_10 (nat_rtp_rtcp_hook) V_49 ;
if ( ! F_7 ( V_5 , * V_8 , V_28 , & V_30 , & V_31 ) ||
memcmp ( & V_30 , & V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_53 , sizeof( V_30 ) ) ||
V_31 == 0 )
return 0 ;
V_44 = V_31 & ~ F_11 ( 1 ) ;
V_45 = V_31 | F_11 ( 1 ) ;
if ( ( V_47 = F_12 ( V_5 ) ) == NULL )
return - 1 ;
F_13 ( V_47 , V_54 , F_8 ( V_5 ) ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_53 ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_53 ,
V_56 , NULL , & V_44 ) ;
if ( ( V_48 = F_12 ( V_5 ) ) == NULL ) {
F_14 ( V_47 ) ;
return - 1 ;
}
F_13 ( V_48 , V_54 , F_8 ( V_5 ) ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_53 ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_53 ,
V_56 , NULL , & V_45 ) ;
if ( memcmp ( & V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_53 ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_53 ,
sizeof( V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_53 ) ) &&
( V_49 = F_15 ( V_57 ) ) &&
F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 ) {
V_43 = V_49 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
V_28 , V_31 , V_44 , V_47 , V_48 ) ;
} else {
if ( F_16 ( V_47 ) == 0 ) {
if ( F_16 ( V_48 ) == 0 ) {
F_6 ( L_8 ) ;
F_17 ( & V_47 -> V_51 ) ;
F_6 ( L_9 ) ;
F_17 ( & V_48 -> V_51 ) ;
} else {
F_18 ( V_47 ) ;
V_43 = - 1 ;
}
} else
V_43 = - 1 ;
}
F_14 ( V_47 ) ;
F_14 ( V_48 ) ;
return V_43 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , int V_10 ,
T_1 * V_28 )
{
int V_13 = F_3 ( V_7 ) ;
int V_43 = 0 ;
T_2 V_31 ;
union V_29 V_30 ;
struct V_46 * exp ;
F_10 (nat_t120_hook) V_61 ;
if ( ! F_7 ( V_5 , * V_8 , V_28 , & V_30 , & V_31 ) ||
memcmp ( & V_30 , & V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_53 , sizeof( V_30 ) ) ||
V_31 == 0 )
return 0 ;
if ( ( exp = F_12 ( V_5 ) ) == NULL )
return - 1 ;
F_13 ( exp , V_54 , F_8 ( V_5 ) ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_53 ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_53 ,
V_62 , NULL , & V_31 ) ;
exp -> V_63 = V_64 ;
if ( memcmp ( & V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_53 ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_53 ,
sizeof( V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_53 ) ) &&
( V_61 = F_15 ( V_65 ) ) &&
F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 ) {
V_43 = V_61 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 , V_28 ,
V_31 , exp ) ;
} else {
if ( F_16 ( exp ) == 0 ) {
F_6 ( L_10 ) ;
F_17 ( & exp -> V_51 ) ;
} else
V_43 = - 1 ;
}
F_14 ( exp ) ;
return V_43 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , int V_10 ,
T_3 * V_66 )
{
int V_43 ;
if ( V_66 -> V_67 & V_68 ) {
V_43 = F_9 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_66 -> V_69 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( V_66 ->
V_67 & V_70 ) {
V_43 = F_9 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_66 -> V_71 ) ;
if ( V_43 < 0 )
return - 1 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , int V_10 ,
T_4 * V_72 )
{
int V_43 ;
F_6 ( L_11 ) ;
if ( V_72 -> V_73 . V_74 . V_33 ==
V_75 )
{
V_43 = F_20 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_72 ->
V_73 .
V_74 .
V_76 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( ( V_72 -> V_67 &
V_77 ) &&
( V_72 -> V_78 . V_67 &
V_79 )
&& ( V_72 -> V_78 . V_74 .
V_33 ==
V_80 ) )
{
V_43 =
F_20 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_72 ->
V_78 .
V_74 .
V_76 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( ( V_72 -> V_67 & V_81 ) &&
V_72 -> V_73 . V_82 . V_33 ==
V_83 &&
V_72 -> V_73 . V_82 . V_8 . V_84 .
V_33 == V_85 &&
V_72 -> V_73 . V_82 . V_8 . V_84 .
V_86 . V_33 == V_87 &&
V_72 -> V_88 . V_89 . V_33 ==
V_90 ) {
V_43 = F_19 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_72 -> V_88 . V_89 .
V_91 ) ;
if ( V_43 < 0 )
return - 1 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 , unsigned char * * V_8 , int V_10 ,
T_5 * V_92 )
{
T_6 * V_93 ;
int V_43 ;
F_6 ( L_12 ) ;
if ( ( V_92 -> V_67 &
V_94 ) &&
( V_92 -> V_78 . V_67 &
V_95 )
&& ( V_92 -> V_78 . V_74 .
V_33 ==
V_96 ) )
{
V_43 = F_20 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_92 ->
V_78 .
V_74 .
V_76 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( ( V_92 -> V_67 &
V_97 ) &&
( V_92 -> V_98 . V_33 ==
V_99 ) )
{
V_93 = & V_92 -> V_98 .
V_100 ;
if ( V_93 -> V_67 &
V_101 ) {
V_43 = F_9 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_93 -> V_69 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( V_93 -> V_67 &
V_102 ) {
V_43 = F_9 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_93 -> V_71 ) ;
if ( V_43 < 0 )
return - 1 ;
}
}
if ( ( V_92 -> V_67 & V_103 ) &&
V_92 -> V_88 . V_89 . V_33 ==
V_90 ) {
V_43 = F_19 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_92 -> V_88 . V_89 .
V_91 ) ;
if ( V_43 < 0 )
return - 1 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 , unsigned char * * V_8 , int V_10 ,
T_7 * V_104 )
{
switch ( V_104 -> V_33 ) {
case V_105 :
if ( V_104 -> V_106 . V_33 ==
V_107 ) {
return F_21 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_104 -> V_106 . V_108 ) ;
}
F_6 ( L_13 ,
V_104 -> V_106 . V_33 ) ;
break;
case V_109 :
if ( V_104 -> V_110 . V_33 ==
V_111 ) {
return F_22 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_104 -> V_110 .
V_112 ) ;
}
F_6 ( L_14 ,
V_104 -> V_110 . V_33 ) ;
break;
default:
F_6 ( L_15 , V_104 -> V_33 ) ;
break;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 , enum V_6 V_7 )
{
static T_7 V_104 ;
unsigned char * V_8 = NULL ;
int V_9 ;
int V_10 ;
int V_43 ;
if ( V_7 != V_113 && V_7 != V_114 )
return V_115 ;
F_6 ( L_16 , V_2 -> V_23 ) ;
F_25 ( & V_116 ) ;
while ( F_1 ( V_2 , V_3 , V_5 , V_7 ,
& V_8 , & V_9 , & V_10 ) ) {
F_6 ( L_17 , V_9 ) ;
F_17 ( & V_5 -> V_50 [ F_3 ( V_7 ) ] . V_51 ) ;
V_43 = F_26 ( V_8 , V_9 ,
& V_104 ) ;
if ( V_43 < 0 ) {
F_6 ( L_18 ,
V_43 == V_117 ?
L_19 : L_20 ) ;
break;
}
if ( F_23 ( V_2 , V_5 , V_7 , V_3 ,
& V_8 , V_10 , & V_104 ) < 0 )
goto V_118;
}
F_27 ( & V_116 ) ;
return V_115 ;
V_118:
F_27 ( & V_116 ) ;
F_28 ( L_21 ) ;
return V_119 ;
}
int F_29 ( struct V_4 * V_5 , unsigned char * V_8 ,
T_8 * V_28 ,
union V_29 * V_30 , T_2 * V_31 )
{
const unsigned char * V_32 ;
int V_23 ;
switch ( V_28 -> V_33 ) {
case V_120 :
if ( F_8 ( V_5 ) != V_37 )
return 0 ;
V_32 = V_8 + V_28 -> V_121 . V_122 ;
V_23 = 4 ;
break;
case V_123 :
if ( F_8 ( V_5 ) != V_41 )
return 0 ;
V_32 = V_8 + V_28 -> V_124 . V_122 ;
V_23 = 16 ;
break;
default:
return 0 ;
}
memcpy ( V_30 , V_32 , V_23 ) ;
memset ( ( void * ) V_30 + V_23 , 0 , sizeof( * V_30 ) - V_23 ) ;
memcpy ( V_31 , V_32 + V_23 , sizeof( T_2 ) ) ;
return 1 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 , unsigned char * * V_8 , int V_10 ,
T_8 * V_28 )
{
int V_13 = F_3 ( V_7 ) ;
int V_43 = 0 ;
T_2 V_31 ;
union V_29 V_30 ;
struct V_46 * exp ;
F_10 (nat_h245_hook) V_125 ;
if ( ! F_29 ( V_5 , * V_8 , V_28 , & V_30 , & V_31 ) ||
memcmp ( & V_30 , & V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_53 , sizeof( V_30 ) ) ||
V_31 == 0 )
return 0 ;
if ( ( exp = F_12 ( V_5 ) ) == NULL )
return - 1 ;
F_13 ( exp , V_54 , F_8 ( V_5 ) ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_53 ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_53 ,
V_62 , NULL , & V_31 ) ;
exp -> V_126 = & V_127 ;
if ( memcmp ( & V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_53 ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_53 ,
sizeof( V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_53 ) ) &&
( V_125 = F_15 ( V_128 ) ) &&
F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 ) {
V_43 = V_125 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 , V_28 ,
V_31 , exp ) ;
} else {
if ( F_16 ( exp ) == 0 ) {
F_6 ( L_22 ) ;
F_17 ( & exp -> V_51 ) ;
} else
V_43 = - 1 ;
}
F_14 ( exp ) ;
return V_43 ;
}
static int F_31 ( const union V_29 * V_52 ,
const union V_29 * V_55 ,
T_9 V_129 )
{
const struct V_130 * V_131 ;
int V_43 = 0 ;
V_131 = F_32 ( V_129 ) ;
if ( ! V_131 )
return 0 ;
switch ( V_129 ) {
case V_37 : {
struct V_132 V_133 , V_134 ;
struct V_135 * V_136 , * V_137 ;
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
V_133 . V_138 = V_52 -> V_122 ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
V_134 . V_138 = V_55 -> V_122 ;
if ( ! V_131 -> V_139 ( & V_140 , (struct V_141 * * ) & V_136 ,
F_33 ( & V_133 ) , false ) ) {
if ( ! V_131 -> V_139 ( & V_140 , (struct V_141 * * ) & V_137 ,
F_33 ( & V_134 ) , false ) ) {
if ( F_34 ( V_136 , V_133 . V_138 ) ==
F_34 ( V_137 , V_134 . V_138 ) &&
V_136 -> V_55 . V_142 == V_137 -> V_55 . V_142 )
V_43 = 1 ;
F_35 ( & V_137 -> V_55 ) ;
}
F_35 ( & V_136 -> V_55 ) ;
}
break;
}
#if F_36 ( V_143 )
case V_41 : {
struct V_144 V_133 , V_134 ;
struct V_145 * V_136 , * V_137 ;
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
V_133 . V_138 = V_52 -> V_146 ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
V_134 . V_138 = V_55 -> V_146 ;
if ( ! V_131 -> V_139 ( & V_140 , (struct V_141 * * ) & V_136 ,
F_37 ( & V_133 ) , false ) ) {
if ( ! V_131 -> V_139 ( & V_140 , (struct V_141 * * ) & V_137 ,
F_37 ( & V_134 ) , false ) ) {
if ( ! memcmp ( & V_136 -> V_147 , & V_137 -> V_147 ,
sizeof( V_136 -> V_147 ) ) &&
V_136 -> V_55 . V_142 == V_137 -> V_55 . V_142 )
V_43 = 1 ;
F_35 ( & V_137 -> V_55 ) ;
}
F_35 ( & V_136 -> V_55 ) ;
}
break;
}
#endif
}
return V_43 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , int V_10 ,
T_8 * V_28 )
{
int V_13 = F_3 ( V_7 ) ;
int V_43 = 0 ;
T_2 V_31 ;
union V_29 V_30 ;
struct V_46 * exp ;
F_10 (nat_callforwarding_hook) V_148 ;
if ( ! F_29 ( V_5 , * V_8 , V_28 , & V_30 , & V_31 ) || V_31 == 0 )
return 0 ;
if ( V_149 &&
F_31 ( & V_30 , & V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_53 ,
F_8 ( V_5 ) ) ) {
F_6 ( L_23 ) ;
return 0 ;
}
if ( ( exp = F_12 ( V_5 ) ) == NULL )
return - 1 ;
F_13 ( exp , V_54 , F_8 ( V_5 ) ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_53 , & V_30 ,
V_62 , NULL , & V_31 ) ;
exp -> V_126 = V_150 ;
if ( memcmp ( & V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_53 ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_53 ,
sizeof( V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_53 ) ) &&
( V_148 = F_15 ( V_151 ) ) &&
F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 ) {
V_43 = V_148 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
V_28 , V_31 , exp ) ;
} else {
if ( F_16 ( exp ) == 0 ) {
F_6 ( L_24 ) ;
F_17 ( & exp -> V_51 ) ;
} else
V_43 = - 1 ;
}
F_14 ( exp ) ;
return V_43 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , int V_10 ,
T_10 * V_152 )
{
int V_13 = F_3 ( V_7 ) ;
int V_43 ;
int V_153 ;
T_2 V_31 ;
union V_29 V_30 ;
F_10 (set_h225_addr_hook) V_154 ;
F_6 ( L_25 ) ;
if ( V_152 -> V_67 & V_155 ) {
V_43 = F_30 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_152 -> V_156 ) ;
if ( V_43 < 0 )
return - 1 ;
}
V_154 = F_15 ( V_157 ) ;
if ( ( V_152 -> V_67 & V_158 ) &&
( V_154 ) && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 &&
F_29 ( V_5 , * V_8 , & V_152 -> V_159 ,
& V_30 , & V_31 ) &&
memcmp ( & V_30 , & V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_53 , sizeof( V_30 ) ) ) {
F_6 ( L_26 ,
& V_30 , F_40 ( V_31 ) , & V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_53 ,
F_40 ( V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_160 . V_161 . V_31 ) ) ;
V_43 = V_154 ( V_2 , V_3 , V_8 , V_10 ,
& V_152 -> V_159 ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_53 ,
V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_160 . V_161 . V_31 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( ( V_152 -> V_67 & V_162 ) &&
( V_154 ) && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 &&
F_29 ( V_5 , * V_8 , & V_152 -> V_163 ,
& V_30 , & V_31 ) &&
memcmp ( & V_30 , & V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_53 , sizeof( V_30 ) ) ) {
F_6 ( L_27 ,
& V_30 , F_40 ( V_31 ) , & V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_53 ,
F_40 ( V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_160 . V_161 . V_31 ) ) ;
V_43 = V_154 ( V_2 , V_3 , V_8 , V_10 ,
& V_152 -> V_163 ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_53 ,
V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_160 . V_161 . V_31 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( V_152 -> V_67 & V_164 ) {
for ( V_153 = 0 ; V_153 < V_152 -> V_165 . V_166 ; V_153 ++ ) {
V_43 = F_21 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_152 -> V_165 . V_167 [ V_153 ] ) ;
if ( V_43 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , int V_10 ,
T_11 * V_168 )
{
int V_43 ;
int V_153 ;
F_6 ( L_28 ) ;
if ( V_168 -> V_67 & V_169 ) {
V_43 = F_30 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_168 -> V_156 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( V_168 -> V_67 & V_170 ) {
for ( V_153 = 0 ; V_153 < V_168 -> V_165 . V_166 ; V_153 ++ ) {
V_43 = F_21 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_168 -> V_165 . V_167 [ V_153 ] ) ;
if ( V_43 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , int V_10 ,
T_12 * V_171 )
{
int V_43 ;
int V_153 ;
F_6 ( L_29 ) ;
if ( V_171 -> V_67 & V_172 ) {
V_43 = F_30 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_171 -> V_156 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( V_171 -> V_67 & V_173 ) {
for ( V_153 = 0 ; V_153 < V_171 -> V_165 . V_166 ; V_153 ++ ) {
V_43 = F_21 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_171 -> V_165 . V_167 [ V_153 ] ) ;
if ( V_43 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , int V_10 ,
T_13 * V_174 )
{
int V_43 ;
int V_153 ;
F_6 ( L_30 ) ;
if ( V_174 -> V_67 & V_175 ) {
V_43 = F_30 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_174 -> V_156 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( V_174 -> V_67 & V_176 ) {
for ( V_153 = 0 ; V_153 < V_174 -> V_165 . V_166 ; V_153 ++ ) {
V_43 = F_21 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_174 -> V_165 . V_167 [ V_153 ] ) ;
if ( V_43 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , int V_10 ,
T_14 * V_177 )
{
int V_43 ;
int V_153 ;
F_6 ( L_31 ) ;
if ( V_177 -> V_178 . V_33 == V_179 ) {
if ( V_177 -> V_67 & V_180 )
return F_38 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_177 ->
V_181 ) ;
return 0 ;
}
if ( V_177 -> V_67 & V_182 ) {
V_43 = F_30 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_177 -> V_156 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( V_177 -> V_67 & V_183 ) {
for ( V_153 = 0 ; V_153 < V_177 -> V_165 . V_166 ; V_153 ++ ) {
V_43 = F_21 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_177 -> V_165 . V_167 [ V_153 ] ) ;
if ( V_43 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , int V_10 ,
T_15 * V_184 )
{
int V_43 ;
int V_153 ;
F_6 ( L_32 ) ;
if ( V_184 -> V_67 & V_185 ) {
V_43 = F_30 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_184 -> V_156 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( V_184 -> V_67 & V_186 ) {
for ( V_153 = 0 ; V_153 < V_184 -> V_165 . V_166 ; V_153 ++ ) {
V_43 = F_21 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_184 -> V_165 . V_167 [ V_153 ] ) ;
if ( V_43 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 , unsigned char * * V_8 , int V_10 ,
T_16 * V_187 )
{
T_17 * V_188 = & V_187 -> V_189 . V_190 ;
int V_153 ;
int V_43 = 0 ;
switch ( V_188 -> V_191 . V_33 ) {
case V_192 :
V_43 = F_39 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_188 -> V_191 . V_152 ) ;
break;
case V_193 :
V_43 = F_41 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_188 -> V_191 .
V_194 ) ;
break;
case V_195 :
V_43 = F_42 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_188 -> V_191 . V_171 ) ;
break;
case V_196 :
V_43 = F_43 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_188 -> V_191 . V_197 ) ;
break;
case V_198 :
V_43 = F_44 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_188 -> V_191 . V_177 ) ;
break;
case V_199 :
V_43 = F_45 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_188 -> V_191 . V_184 ) ;
break;
default:
F_6 ( L_33 ,
V_188 -> V_191 . V_33 ) ;
break;
}
if ( V_43 < 0 )
return - 1 ;
if ( V_188 -> V_67 & V_200 ) {
for ( V_153 = 0 ; V_153 < V_188 -> V_201 . V_166 ; V_153 ++ ) {
V_43 = F_23 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_188 -> V_201 . V_167 [ V_153 ] ) ;
if ( V_43 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 , enum V_6 V_7 )
{
static T_16 V_187 ;
unsigned char * V_8 = NULL ;
int V_9 ;
int V_10 ;
int V_43 ;
if ( V_7 != V_113 && V_7 != V_114 )
return V_115 ;
F_6 ( L_34 , V_2 -> V_23 ) ;
F_25 ( & V_116 ) ;
while ( F_1 ( V_2 , V_3 , V_5 , V_7 ,
& V_8 , & V_9 , & V_10 ) ) {
F_6 ( L_35 , V_9 ) ;
F_17 ( & V_5 -> V_50 [ F_3 ( V_7 ) ] . V_51 ) ;
V_43 = F_48 ( V_8 , V_9 , & V_187 ) ;
if ( V_43 < 0 ) {
F_6 ( L_36 ,
V_43 == V_117 ?
L_19 : L_20 ) ;
break;
}
if ( F_46 ( V_2 , V_5 , V_7 , V_3 ,
& V_8 , V_10 , & V_187 ) < 0 )
goto V_118;
}
F_27 ( & V_116 ) ;
return V_115 ;
V_118:
F_27 ( & V_116 ) ;
F_28 ( L_37 ) ;
return V_119 ;
}
static unsigned char * F_49 ( struct V_1 * V_2 , unsigned int V_3 ,
int * V_9 )
{
const struct V_202 * V_203 ;
struct V_202 V_204 ;
int V_10 ;
V_203 = F_4 ( V_2 , V_3 , sizeof( V_204 ) , & V_204 ) ;
if ( V_203 == NULL )
return NULL ;
V_10 = V_3 + sizeof( V_204 ) ;
if ( V_10 >= V_2 -> V_23 )
return NULL ;
* V_9 = V_2 -> V_23 - V_10 ;
return F_4 ( V_2 , V_10 , * V_9 , V_25 ) ;
}
static struct V_46 * F_50 ( struct V_4 * V_5 ,
union V_29 * V_30 ,
T_2 V_31 )
{
struct V_205 * V_205 = F_51 ( V_5 ) ;
struct V_46 * exp ;
struct V_206 V_51 ;
memset ( & V_51 . V_52 . V_53 , 0 , sizeof( V_51 . V_52 . V_53 ) ) ;
V_51 . V_52 . V_160 . V_161 . V_31 = 0 ;
memcpy ( & V_51 . V_55 . V_53 , V_30 , sizeof( V_51 . V_55 . V_53 ) ) ;
V_51 . V_55 . V_160 . V_161 . V_31 = V_31 ;
V_51 . V_55 . V_207 = V_62 ;
exp = F_52 ( V_205 , F_53 ( V_5 ) , & V_51 ) ;
if ( exp && exp -> V_208 == V_5 )
return exp ;
return NULL ;
}
static int F_54 ( struct V_46 * exp ,
unsigned int V_209 )
{
if ( ! exp || ! F_55 ( & exp -> V_209 ) )
return 0 ;
exp -> V_209 . V_210 = V_211 + V_209 * V_212 ;
F_56 ( & exp -> V_209 ) ;
return 1 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 , unsigned char * * V_8 ,
T_8 * V_28 , int V_166 )
{
struct V_11 * V_12 = F_2 ( V_5 ) ;
int V_13 = F_3 ( V_7 ) ;
int V_43 = 0 ;
int V_153 ;
T_2 V_31 ;
union V_29 V_30 ;
struct V_46 * exp ;
F_10 (nat_q931_hook) V_213 ;
for ( V_153 = 0 ; V_153 < V_166 ; V_153 ++ ) {
if ( F_29 ( V_5 , * V_8 , & V_28 [ V_153 ] , & V_30 , & V_31 ) &&
memcmp ( & V_30 , & V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_53 ,
sizeof( V_30 ) ) == 0 && V_31 != 0 )
break;
}
if ( V_153 >= V_166 )
return 0 ;
if ( ( exp = F_12 ( V_5 ) ) == NULL )
return - 1 ;
F_13 ( exp , V_54 , F_8 ( V_5 ) ,
V_214 ?
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_53 : NULL ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_53 ,
V_62 , NULL , & V_31 ) ;
exp -> V_126 = V_150 ;
exp -> V_63 = V_64 ;
V_213 = F_15 ( V_215 ) ;
if ( V_213 && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 ) {
V_43 = V_213 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
V_28 , V_153 , V_31 , exp ) ;
} else {
if ( F_16 ( exp ) == 0 ) {
F_6 ( L_38 ) ;
F_17 ( & exp -> V_51 ) ;
V_12 -> V_216 [ V_13 ] = V_31 ;
} else
V_43 = - 1 ;
}
F_14 ( exp ) ;
return V_43 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , T_18 * V_217 )
{
F_10 (set_ras_addr_hook) V_218 ;
F_6 ( L_39 ) ;
V_218 = F_15 ( V_219 ) ;
if ( V_218 && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 )
return V_218 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_217 -> V_220 , 1 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , T_19 * V_221 )
{
int V_13 = F_3 ( V_7 ) ;
int V_43 = 0 ;
T_2 V_31 ;
union V_29 V_30 ;
struct V_46 * exp ;
F_6 ( L_40 ) ;
if ( ! F_29 ( V_5 , * V_8 , & V_221 -> V_220 , & V_30 , & V_31 ) )
return 0 ;
if ( ! memcmp ( & V_30 , & V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_53 , sizeof( V_30 ) ) &&
V_31 == V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_160 . V_222 . V_31 )
return 0 ;
if ( F_60 ( V_223 , & V_5 -> V_59 ) )
return 0 ;
if ( ( exp = F_12 ( V_5 ) ) == NULL )
return - 1 ;
F_13 ( exp , V_54 , F_8 ( V_5 ) ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_53 , & V_30 ,
V_56 , NULL , & V_31 ) ;
exp -> V_126 = V_224 ;
if ( F_16 ( exp ) == 0 ) {
F_6 ( L_41 ) ;
F_17 ( & exp -> V_51 ) ;
} else
V_43 = - 1 ;
F_14 ( exp ) ;
return V_43 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , T_20 * V_225 )
{
struct V_11 * V_12 = F_2 ( V_5 ) ;
int V_43 ;
F_10 (set_ras_addr_hook) V_218 ;
F_6 ( L_42 ) ;
V_43 = F_57 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
V_225 -> V_226 . V_167 ,
V_225 -> V_226 . V_166 ) ;
if ( V_43 < 0 )
return - 1 ;
V_218 = F_15 ( V_219 ) ;
if ( V_218 && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 ) {
V_43 = V_218 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
V_225 -> V_220 . V_167 ,
V_225 -> V_220 . V_166 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( V_225 -> V_67 & V_227 ) {
F_6 ( L_43 , V_225 -> V_228 ) ;
V_12 -> V_209 = V_225 -> V_228 ;
} else
V_12 -> V_209 = V_229 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , T_21 * V_230 )
{
struct V_11 * V_12 = F_2 ( V_5 ) ;
int V_13 = F_3 ( V_7 ) ;
int V_43 ;
struct V_46 * exp ;
F_10 (set_sig_addr_hook) V_231 ;
F_6 ( L_44 ) ;
V_231 = F_15 ( V_232 ) ;
if ( V_231 && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 ) {
V_43 = V_231 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
V_230 -> V_226 . V_167 ,
V_230 -> V_226 . V_166 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( V_230 -> V_67 & V_233 ) {
F_6 ( L_45 , V_230 -> V_228 ) ;
V_12 -> V_209 = V_230 -> V_228 ;
}
if ( V_12 -> V_209 > 0 ) {
F_6 ( L_46
L_47 , V_12 -> V_209 ) ;
F_63 ( V_5 , V_2 , V_12 -> V_209 * V_212 ) ;
F_25 ( & V_234 ) ;
exp = F_50 ( V_5 , & V_5 -> V_50 [ V_13 ] . V_51 . V_55 . V_53 ,
V_12 -> V_216 [ ! V_13 ] ) ;
if ( exp ) {
F_6 ( L_48
L_49 ,
V_12 -> V_209 ) ;
F_17 ( & exp -> V_51 ) ;
F_54 ( exp , V_12 -> V_209 ) ;
}
F_27 ( & V_234 ) ;
}
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , T_22 * V_235 )
{
struct V_11 * V_12 = F_2 ( V_5 ) ;
int V_13 = F_3 ( V_7 ) ;
int V_43 ;
F_10 (set_sig_addr_hook) V_231 ;
F_6 ( L_50 ) ;
V_231 = F_15 ( V_232 ) ;
if ( V_231 && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 ) {
V_43 = V_231 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
V_235 -> V_226 . V_167 ,
V_235 -> V_226 . V_166 ) ;
if ( V_43 < 0 )
return - 1 ;
}
F_65 ( V_5 ) ;
V_12 -> V_216 [ V_13 ] = 0 ;
V_12 -> V_216 [ ! V_13 ] = 0 ;
F_63 ( V_5 , V_2 , 30 * V_212 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , T_23 * V_236 )
{
const struct V_11 * V_12 = F_2 ( V_5 ) ;
int V_13 = F_3 ( V_7 ) ;
T_2 V_31 ;
union V_29 V_30 ;
F_10 (set_h225_addr_hook) V_154 ;
F_6 ( L_51 ) ;
V_154 = F_15 ( V_157 ) ;
if ( ( V_236 -> V_67 & V_237 ) &&
F_29 ( V_5 , * V_8 , & V_236 -> V_159 ,
& V_30 , & V_31 ) &&
! memcmp ( & V_30 , & V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_53 , sizeof( V_30 ) ) &&
V_31 == V_12 -> V_216 [ V_13 ] &&
F_8 ( V_5 ) == V_58 &&
V_154 && V_5 -> V_59 & V_60 ) {
return V_154 ( V_2 , V_3 , V_8 , 0 ,
& V_236 -> V_159 ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_53 ,
V_12 -> V_216 [ ! V_13 ] ) ;
}
if ( ( V_236 -> V_67 & V_238 ) &&
F_29 ( V_5 , * V_8 , & V_236 -> V_239 ,
& V_30 , & V_31 ) &&
! memcmp ( & V_30 , & V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_53 , sizeof( V_30 ) ) &&
V_154 && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 ) {
return V_154 ( V_2 , V_3 , V_8 , 0 ,
& V_236 -> V_239 ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_53 ,
V_31 ) ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , T_24 * V_240 )
{
int V_13 = F_3 ( V_7 ) ;
int V_43 = 0 ;
T_2 V_31 ;
union V_29 V_30 ;
struct V_46 * exp ;
F_10 (set_sig_addr_hook) V_231 ;
F_6 ( L_52 ) ;
if ( ! F_29 ( V_5 , * V_8 , & V_240 -> V_159 ,
& V_30 , & V_31 ) )
return 0 ;
if ( ! memcmp ( & V_30 , & V_5 -> V_50 [ V_13 ] . V_51 . V_55 . V_53 , sizeof( V_30 ) ) ) {
V_231 = F_15 ( V_232 ) ;
if ( V_231 && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 )
return V_231 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_240 -> V_159 , 1 ) ;
return 0 ;
}
if ( ( exp = F_12 ( V_5 ) ) == NULL )
return - 1 ;
F_13 ( exp , V_54 , F_8 ( V_5 ) ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_53 , & V_30 ,
V_62 , NULL , & V_31 ) ;
exp -> V_63 = V_64 ;
exp -> V_126 = V_150 ;
if ( F_16 ( exp ) == 0 ) {
F_6 ( L_38 ) ;
F_17 ( & exp -> V_51 ) ;
} else
V_43 = - 1 ;
F_14 ( exp ) ;
return V_43 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , T_25 * V_241 )
{
F_10 (set_ras_addr_hook) V_218 ;
F_6 ( L_53 ) ;
V_218 = F_15 ( V_219 ) ;
if ( V_218 && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 )
return V_218 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_241 -> V_242 , 1 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , T_26 * V_243 )
{
int V_13 = F_3 ( V_7 ) ;
int V_43 = 0 ;
T_2 V_31 ;
union V_29 V_30 ;
struct V_46 * exp ;
F_6 ( L_54 ) ;
if ( ! F_29 ( V_5 , * V_8 , & V_243 -> V_226 ,
& V_30 , & V_31 ) )
return 0 ;
if ( ( exp = F_12 ( V_5 ) ) == NULL )
return - 1 ;
F_13 ( exp , V_54 , F_8 ( V_5 ) ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_53 , & V_30 ,
V_62 , NULL , & V_31 ) ;
exp -> V_63 = V_64 ;
exp -> V_126 = V_150 ;
if ( F_16 ( exp ) == 0 ) {
F_6 ( L_38 ) ;
F_17 ( & exp -> V_51 ) ;
} else
V_43 = - 1 ;
F_14 ( exp ) ;
return V_43 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , T_27 * V_244 )
{
int V_43 ;
F_10 (set_ras_addr_hook) V_218 ;
F_10 (set_sig_addr_hook) V_231 ;
F_6 ( L_55 ) ;
V_218 = F_15 ( V_219 ) ;
if ( V_218 && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 ) {
V_43 = V_218 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_244 -> V_220 , 1 ) ;
if ( V_43 < 0 )
return - 1 ;
}
V_231 = F_15 ( V_232 ) ;
if ( V_231 && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 ) {
V_43 = V_231 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
V_244 -> V_226 . V_167 ,
V_244 -> V_226 . V_166 ) ;
if ( V_43 < 0 )
return - 1 ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , T_28 * V_245 )
{
switch ( V_245 -> V_33 ) {
case V_246 :
return F_58 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_245 -> V_247 ) ;
case V_248 :
return F_59 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_245 -> V_249 ) ;
case V_250 :
return F_61 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_245 -> V_251 ) ;
case V_252 :
return F_62 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_245 -> V_253 ) ;
case V_254 :
return F_64 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_245 -> V_255 ) ;
case V_256 :
return F_66 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_245 -> V_257 ) ;
case V_258 :
return F_67 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_245 -> V_259 ) ;
case V_260 :
return F_68 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_245 -> V_261 ) ;
case V_262 :
return F_69 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_245 -> V_263 ) ;
case V_264 :
return F_70 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_245 -> V_265 ) ;
default:
F_6 ( L_56 , V_245 -> V_33 ) ;
break;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 , enum V_6 V_7 )
{
static T_28 V_245 ;
unsigned char * V_8 ;
int V_9 = 0 ;
int V_43 ;
F_6 ( L_57 , V_2 -> V_23 ) ;
F_25 ( & V_116 ) ;
V_8 = F_49 ( V_2 , V_3 , & V_9 ) ;
if ( V_8 == NULL )
goto V_266;
F_6 ( L_58 , V_9 ) ;
F_17 ( & V_5 -> V_50 [ F_3 ( V_7 ) ] . V_51 ) ;
V_43 = F_73 ( V_8 , V_9 , & V_245 ) ;
if ( V_43 < 0 ) {
F_6 ( L_59 ,
V_43 == V_117 ?
L_19 : L_20 ) ;
goto V_266;
}
if ( F_71 ( V_2 , V_5 , V_7 , V_3 , & V_8 , & V_245 ) < 0 )
goto V_118;
V_266:
F_27 ( & V_116 ) ;
return V_115 ;
V_118:
F_27 ( & V_116 ) ;
F_28 ( L_60 ) ;
return V_119 ;
}
static void T_29 F_74 ( void )
{
F_75 ( & V_224 [ 1 ] ) ;
F_75 ( & V_224 [ 0 ] ) ;
F_75 ( & V_150 [ 1 ] ) ;
F_75 ( & V_150 [ 0 ] ) ;
F_75 ( & V_127 ) ;
F_76 ( V_25 ) ;
F_6 ( L_61 ) ;
}
static int T_30 F_77 ( void )
{
int V_43 ;
V_25 = F_78 ( 65536 , V_267 ) ;
if ( ! V_25 )
return - V_268 ;
V_43 = F_79 ( & V_127 ) ;
if ( V_43 < 0 )
goto V_269;
V_43 = F_79 ( & V_150 [ 0 ] ) ;
if ( V_43 < 0 )
goto V_270;
V_43 = F_79 ( & V_150 [ 1 ] ) ;
if ( V_43 < 0 )
goto V_271;
V_43 = F_79 ( & V_224 [ 0 ] ) ;
if ( V_43 < 0 )
goto V_272;
V_43 = F_79 ( & V_224 [ 1 ] ) ;
if ( V_43 < 0 )
goto V_273;
F_6 ( L_62 ) ;
return 0 ;
V_273:
F_75 ( & V_224 [ 0 ] ) ;
V_272:
F_75 ( & V_150 [ 1 ] ) ;
V_271:
F_75 ( & V_150 [ 0 ] ) ;
V_270:
F_75 ( & V_127 ) ;
V_269:
F_76 ( V_25 ) ;
return V_43 ;
}
