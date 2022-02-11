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
F_28 ( V_2 , V_5 , L_21 ) ;
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
static int F_31 ( struct V_129 * V_129 ,
const union V_29 * V_52 ,
const union V_29 * V_55 ,
T_9 V_130 )
{
const struct V_131 * V_132 ;
int V_43 = 0 ;
V_132 = F_32 ( V_130 ) ;
if ( ! V_132 )
return 0 ;
switch ( V_130 ) {
case V_37 : {
struct V_133 V_134 , V_135 ;
struct V_136 * V_137 , * V_138 ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
V_134 . V_139 = V_52 -> V_122 ;
memset ( & V_135 , 0 , sizeof( V_135 ) ) ;
V_135 . V_139 = V_55 -> V_122 ;
if ( ! V_132 -> V_140 ( V_129 , (struct V_141 * * ) & V_137 ,
F_33 ( & V_134 ) , false ) ) {
if ( ! V_132 -> V_140 ( V_129 , (struct V_141 * * ) & V_138 ,
F_33 ( & V_135 ) , false ) ) {
if ( F_34 ( V_137 , V_134 . V_139 ) ==
F_34 ( V_138 , V_135 . V_139 ) &&
V_137 -> V_55 . V_142 == V_138 -> V_55 . V_142 )
V_43 = 1 ;
F_35 ( & V_138 -> V_55 ) ;
}
F_35 ( & V_137 -> V_55 ) ;
}
break;
}
#if F_36 ( V_143 )
case V_41 : {
struct V_144 V_134 , V_135 ;
struct V_145 * V_137 , * V_138 ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
V_134 . V_139 = V_52 -> V_146 ;
memset ( & V_135 , 0 , sizeof( V_135 ) ) ;
V_135 . V_139 = V_55 -> V_146 ;
if ( ! V_132 -> V_140 ( V_129 , (struct V_141 * * ) & V_137 ,
F_37 ( & V_134 ) , false ) ) {
if ( ! V_132 -> V_140 ( V_129 , (struct V_141 * * ) & V_138 ,
F_37 ( & V_135 ) , false ) ) {
if ( F_38 ( F_39 ( V_137 , & V_134 . V_139 ) ,
F_39 ( V_138 , & V_135 . V_139 ) ) &&
V_137 -> V_55 . V_142 == V_138 -> V_55 . V_142 )
V_43 = 1 ;
F_35 ( & V_138 -> V_55 ) ;
}
F_35 ( & V_137 -> V_55 ) ;
}
break;
}
#endif
}
return V_43 ;
}
static int F_40 ( struct V_1 * V_2 ,
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
struct V_129 * V_129 = F_41 ( V_5 ) ;
F_10 (nat_callforwarding_hook) V_147 ;
if ( ! F_29 ( V_5 , * V_8 , V_28 , & V_30 , & V_31 ) || V_31 == 0 )
return 0 ;
if ( V_148 &&
F_31 ( V_129 , & V_30 , & V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_53 ,
F_8 ( V_5 ) ) ) {
F_6 ( L_23 ) ;
return 0 ;
}
if ( ( exp = F_12 ( V_5 ) ) == NULL )
return - 1 ;
F_13 ( exp , V_54 , F_8 ( V_5 ) ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_53 , & V_30 ,
V_62 , NULL , & V_31 ) ;
exp -> V_126 = V_149 ;
if ( memcmp ( & V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_53 ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_53 ,
sizeof( V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_53 ) ) &&
( V_147 = F_15 ( V_150 ) ) &&
F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 ) {
V_43 = V_147 ( V_2 , V_5 , V_7 ,
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
static int F_42 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , int V_10 ,
T_10 * V_151 )
{
int V_13 = F_3 ( V_7 ) ;
int V_43 ;
int V_152 ;
T_2 V_31 ;
union V_29 V_30 ;
F_10 (set_h225_addr_hook) V_153 ;
F_6 ( L_25 ) ;
if ( V_151 -> V_67 & V_154 ) {
V_43 = F_30 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_151 -> V_155 ) ;
if ( V_43 < 0 )
return - 1 ;
}
V_153 = F_15 ( V_156 ) ;
if ( ( V_151 -> V_67 & V_157 ) &&
( V_153 ) && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 &&
F_29 ( V_5 , * V_8 , & V_151 -> V_158 ,
& V_30 , & V_31 ) &&
memcmp ( & V_30 , & V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_53 , sizeof( V_30 ) ) ) {
F_6 ( L_26 ,
& V_30 , F_43 ( V_31 ) , & V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_53 ,
F_43 ( V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_159 . V_160 . V_31 ) ) ;
V_43 = V_153 ( V_2 , V_3 , V_8 , V_10 ,
& V_151 -> V_158 ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_53 ,
V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_159 . V_160 . V_31 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( ( V_151 -> V_67 & V_161 ) &&
( V_153 ) && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 &&
F_29 ( V_5 , * V_8 , & V_151 -> V_162 ,
& V_30 , & V_31 ) &&
memcmp ( & V_30 , & V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_53 , sizeof( V_30 ) ) ) {
F_6 ( L_27 ,
& V_30 , F_43 ( V_31 ) , & V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_53 ,
F_43 ( V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_159 . V_160 . V_31 ) ) ;
V_43 = V_153 ( V_2 , V_3 , V_8 , V_10 ,
& V_151 -> V_162 ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_53 ,
V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_159 . V_160 . V_31 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( V_151 -> V_67 & V_163 ) {
for ( V_152 = 0 ; V_152 < V_151 -> V_164 . V_165 ; V_152 ++ ) {
V_43 = F_21 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_151 -> V_164 . V_166 [ V_152 ] ) ;
if ( V_43 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , int V_10 ,
T_11 * V_167 )
{
int V_43 ;
int V_152 ;
F_6 ( L_28 ) ;
if ( V_167 -> V_67 & V_168 ) {
V_43 = F_30 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_167 -> V_155 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( V_167 -> V_67 & V_169 ) {
for ( V_152 = 0 ; V_152 < V_167 -> V_164 . V_165 ; V_152 ++ ) {
V_43 = F_21 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_167 -> V_164 . V_166 [ V_152 ] ) ;
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
T_12 * V_170 )
{
int V_43 ;
int V_152 ;
F_6 ( L_29 ) ;
if ( V_170 -> V_67 & V_171 ) {
V_43 = F_30 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_170 -> V_155 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( V_170 -> V_67 & V_172 ) {
for ( V_152 = 0 ; V_152 < V_170 -> V_164 . V_165 ; V_152 ++ ) {
V_43 = F_21 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_170 -> V_164 . V_166 [ V_152 ] ) ;
if ( V_43 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , int V_10 ,
T_13 * V_173 )
{
int V_43 ;
int V_152 ;
F_6 ( L_30 ) ;
if ( V_173 -> V_67 & V_174 ) {
V_43 = F_30 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_173 -> V_155 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( V_173 -> V_67 & V_175 ) {
for ( V_152 = 0 ; V_152 < V_173 -> V_164 . V_165 ; V_152 ++ ) {
V_43 = F_21 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_173 -> V_164 . V_166 [ V_152 ] ) ;
if ( V_43 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , int V_10 ,
T_14 * V_176 )
{
int V_43 ;
int V_152 ;
F_6 ( L_31 ) ;
if ( V_176 -> V_177 . V_33 == V_178 ) {
if ( V_176 -> V_67 & V_179 )
return F_40 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_176 ->
V_180 ) ;
return 0 ;
}
if ( V_176 -> V_67 & V_181 ) {
V_43 = F_30 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_176 -> V_155 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( V_176 -> V_67 & V_182 ) {
for ( V_152 = 0 ; V_152 < V_176 -> V_164 . V_165 ; V_152 ++ ) {
V_43 = F_21 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_176 -> V_164 . V_166 [ V_152 ] ) ;
if ( V_43 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , int V_10 ,
T_15 * V_183 )
{
int V_43 ;
int V_152 ;
F_6 ( L_32 ) ;
if ( V_183 -> V_67 & V_184 ) {
V_43 = F_30 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_183 -> V_155 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( V_183 -> V_67 & V_185 ) {
for ( V_152 = 0 ; V_152 < V_183 -> V_164 . V_165 ; V_152 ++ ) {
V_43 = F_21 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_183 -> V_164 . V_166 [ V_152 ] ) ;
if ( V_43 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 , unsigned char * * V_8 , int V_10 ,
T_16 * V_186 )
{
T_17 * V_187 = & V_186 -> V_188 . V_189 ;
int V_152 ;
int V_43 = 0 ;
switch ( V_187 -> V_190 . V_33 ) {
case V_191 :
V_43 = F_42 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_187 -> V_190 . V_151 ) ;
break;
case V_192 :
V_43 = F_44 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_187 -> V_190 .
V_193 ) ;
break;
case V_194 :
V_43 = F_45 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_187 -> V_190 . V_170 ) ;
break;
case V_195 :
V_43 = F_46 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_187 -> V_190 . V_196 ) ;
break;
case V_197 :
V_43 = F_47 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_187 -> V_190 . V_176 ) ;
break;
case V_198 :
V_43 = F_48 ( V_2 , V_5 , V_7 , V_3 , V_8 , V_10 ,
& V_187 -> V_190 . V_183 ) ;
break;
default:
F_6 ( L_33 ,
V_187 -> V_190 . V_33 ) ;
break;
}
if ( V_43 < 0 )
return - 1 ;
if ( V_187 -> V_67 & V_199 ) {
for ( V_152 = 0 ; V_152 < V_187 -> V_200 . V_165 ; V_152 ++ ) {
V_43 = F_23 ( V_2 , V_5 , V_7 ,
V_3 , V_8 , V_10 ,
& V_187 -> V_200 . V_166 [ V_152 ] ) ;
if ( V_43 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 , enum V_6 V_7 )
{
static T_16 V_186 ;
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
V_43 = F_51 ( V_8 , V_9 , & V_186 ) ;
if ( V_43 < 0 ) {
F_6 ( L_36 ,
V_43 == V_117 ?
L_19 : L_20 ) ;
break;
}
if ( F_49 ( V_2 , V_5 , V_7 , V_3 ,
& V_8 , V_10 , & V_186 ) < 0 )
goto V_118;
}
F_27 ( & V_116 ) ;
return V_115 ;
V_118:
F_27 ( & V_116 ) ;
F_28 ( V_2 , V_5 , L_37 ) ;
return V_119 ;
}
static unsigned char * F_52 ( struct V_1 * V_2 , unsigned int V_3 ,
int * V_9 )
{
const struct V_201 * V_202 ;
struct V_201 V_203 ;
int V_10 ;
V_202 = F_4 ( V_2 , V_3 , sizeof( V_203 ) , & V_203 ) ;
if ( V_202 == NULL )
return NULL ;
V_10 = V_3 + sizeof( V_203 ) ;
if ( V_10 >= V_2 -> V_23 )
return NULL ;
* V_9 = V_2 -> V_23 - V_10 ;
return F_4 ( V_2 , V_10 , * V_9 , V_25 ) ;
}
static struct V_46 * F_53 ( struct V_4 * V_5 ,
union V_29 * V_30 ,
T_2 V_31 )
{
struct V_129 * V_129 = F_41 ( V_5 ) ;
struct V_46 * exp ;
struct V_204 V_51 ;
memset ( & V_51 . V_52 . V_53 , 0 , sizeof( V_51 . V_52 . V_53 ) ) ;
V_51 . V_52 . V_159 . V_160 . V_31 = 0 ;
memcpy ( & V_51 . V_55 . V_53 , V_30 , sizeof( V_51 . V_55 . V_53 ) ) ;
V_51 . V_55 . V_159 . V_160 . V_31 = V_31 ;
V_51 . V_55 . V_205 = V_62 ;
exp = F_54 ( V_129 , F_55 ( V_5 ) , & V_51 ) ;
if ( exp && exp -> V_206 == V_5 )
return exp ;
return NULL ;
}
static int F_56 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 , unsigned char * * V_8 ,
T_8 * V_28 , int V_165 )
{
struct V_11 * V_12 = F_2 ( V_5 ) ;
int V_13 = F_3 ( V_7 ) ;
int V_43 = 0 ;
int V_152 ;
T_2 V_31 ;
union V_29 V_30 ;
struct V_46 * exp ;
F_10 (nat_q931_hook) V_207 ;
for ( V_152 = 0 ; V_152 < V_165 ; V_152 ++ ) {
if ( F_29 ( V_5 , * V_8 , & V_28 [ V_152 ] , & V_30 , & V_31 ) &&
memcmp ( & V_30 , & V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_53 ,
sizeof( V_30 ) ) == 0 && V_31 != 0 )
break;
}
if ( V_152 >= V_165 )
return 0 ;
if ( ( exp = F_12 ( V_5 ) ) == NULL )
return - 1 ;
F_13 ( exp , V_54 , F_8 ( V_5 ) ,
V_208 ?
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_53 : NULL ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_53 ,
V_62 , NULL , & V_31 ) ;
exp -> V_126 = V_149 ;
exp -> V_63 = V_64 ;
V_207 = F_15 ( V_209 ) ;
if ( V_207 && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 ) {
V_43 = V_207 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
V_28 , V_152 , V_31 , exp ) ;
} else {
if ( F_16 ( exp ) == 0 ) {
F_6 ( L_38 ) ;
F_17 ( & exp -> V_51 ) ;
V_12 -> V_210 [ V_13 ] = V_31 ;
} else
V_43 = - 1 ;
}
F_14 ( exp ) ;
return V_43 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , T_18 * V_211 )
{
F_10 (set_ras_addr_hook) V_212 ;
F_6 ( L_39 ) ;
V_212 = F_15 ( V_213 ) ;
if ( V_212 && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 )
return V_212 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_211 -> V_214 , 1 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , T_19 * V_215 )
{
int V_13 = F_3 ( V_7 ) ;
int V_43 = 0 ;
T_2 V_31 ;
union V_29 V_30 ;
struct V_46 * exp ;
F_6 ( L_40 ) ;
if ( ! F_29 ( V_5 , * V_8 , & V_215 -> V_214 , & V_30 , & V_31 ) )
return 0 ;
if ( ! memcmp ( & V_30 , & V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_53 , sizeof( V_30 ) ) &&
V_31 == V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_159 . V_216 . V_31 )
return 0 ;
if ( F_59 ( V_217 , & V_5 -> V_59 ) )
return 0 ;
if ( ( exp = F_12 ( V_5 ) ) == NULL )
return - 1 ;
F_13 ( exp , V_54 , F_8 ( V_5 ) ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_53 , & V_30 ,
V_56 , NULL , & V_31 ) ;
exp -> V_126 = V_218 ;
if ( F_16 ( exp ) == 0 ) {
F_6 ( L_41 ) ;
F_17 ( & exp -> V_51 ) ;
} else
V_43 = - 1 ;
F_14 ( exp ) ;
return V_43 ;
}
static int F_60 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , T_20 * V_219 )
{
struct V_11 * V_12 = F_2 ( V_5 ) ;
int V_43 ;
F_10 (set_ras_addr_hook) V_212 ;
F_6 ( L_42 ) ;
V_43 = F_56 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
V_219 -> V_220 . V_166 ,
V_219 -> V_220 . V_165 ) ;
if ( V_43 < 0 )
return - 1 ;
V_212 = F_15 ( V_213 ) ;
if ( V_212 && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 ) {
V_43 = V_212 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
V_219 -> V_214 . V_166 ,
V_219 -> V_214 . V_165 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( V_219 -> V_67 & V_221 ) {
F_6 ( L_43 , V_219 -> V_222 ) ;
V_12 -> V_223 = V_219 -> V_222 ;
} else
V_12 -> V_223 = V_224 ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , T_21 * V_225 )
{
struct V_11 * V_12 = F_2 ( V_5 ) ;
int V_13 = F_3 ( V_7 ) ;
int V_43 ;
struct V_46 * exp ;
F_10 (set_sig_addr_hook) V_226 ;
F_6 ( L_44 ) ;
V_226 = F_15 ( V_227 ) ;
if ( V_226 && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 ) {
V_43 = V_226 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
V_225 -> V_220 . V_166 ,
V_225 -> V_220 . V_165 ) ;
if ( V_43 < 0 )
return - 1 ;
}
if ( V_225 -> V_67 & V_228 ) {
F_6 ( L_45 , V_225 -> V_222 ) ;
V_12 -> V_223 = V_225 -> V_222 ;
}
if ( V_12 -> V_223 > 0 ) {
F_6 ( L_46
L_47 , V_12 -> V_223 ) ;
F_62 ( V_5 , V_2 , V_12 -> V_223 * V_229 ) ;
F_25 ( & V_230 ) ;
exp = F_53 ( V_5 , & V_5 -> V_50 [ V_13 ] . V_51 . V_55 . V_53 ,
V_12 -> V_210 [ ! V_13 ] ) ;
if ( exp ) {
F_6 ( L_48
L_49 ,
V_12 -> V_223 ) ;
F_17 ( & exp -> V_51 ) ;
F_63 ( & exp -> V_223 ,
V_231 + V_12 -> V_223 * V_229 ) ;
}
F_27 ( & V_230 ) ;
}
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , T_22 * V_232 )
{
struct V_11 * V_12 = F_2 ( V_5 ) ;
int V_13 = F_3 ( V_7 ) ;
int V_43 ;
F_10 (set_sig_addr_hook) V_226 ;
F_6 ( L_50 ) ;
V_226 = F_15 ( V_227 ) ;
if ( V_226 && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 ) {
V_43 = V_226 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
V_232 -> V_220 . V_166 ,
V_232 -> V_220 . V_165 ) ;
if ( V_43 < 0 )
return - 1 ;
}
F_65 ( V_5 ) ;
V_12 -> V_210 [ V_13 ] = 0 ;
V_12 -> V_210 [ ! V_13 ] = 0 ;
F_62 ( V_5 , V_2 , 30 * V_229 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , T_23 * V_233 )
{
const struct V_11 * V_12 = F_2 ( V_5 ) ;
int V_13 = F_3 ( V_7 ) ;
T_2 V_31 ;
union V_29 V_30 ;
F_10 (set_h225_addr_hook) V_153 ;
F_6 ( L_51 ) ;
V_153 = F_15 ( V_156 ) ;
if ( ( V_233 -> V_67 & V_234 ) &&
F_29 ( V_5 , * V_8 , & V_233 -> V_158 ,
& V_30 , & V_31 ) &&
! memcmp ( & V_30 , & V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_53 , sizeof( V_30 ) ) &&
V_31 == V_12 -> V_210 [ V_13 ] &&
F_8 ( V_5 ) == V_58 &&
V_153 && V_5 -> V_59 & V_60 ) {
return V_153 ( V_2 , V_3 , V_8 , 0 ,
& V_233 -> V_158 ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_53 ,
V_12 -> V_210 [ ! V_13 ] ) ;
}
if ( ( V_233 -> V_67 & V_235 ) &&
F_29 ( V_5 , * V_8 , & V_233 -> V_236 ,
& V_30 , & V_31 ) &&
! memcmp ( & V_30 , & V_5 -> V_50 [ V_13 ] . V_51 . V_52 . V_53 , sizeof( V_30 ) ) &&
V_153 && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 ) {
return V_153 ( V_2 , V_3 , V_8 , 0 ,
& V_233 -> V_236 ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_55 . V_53 ,
V_31 ) ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , T_24 * V_237 )
{
int V_13 = F_3 ( V_7 ) ;
int V_43 = 0 ;
T_2 V_31 ;
union V_29 V_30 ;
struct V_46 * exp ;
F_10 (set_sig_addr_hook) V_226 ;
F_6 ( L_52 ) ;
if ( ! F_29 ( V_5 , * V_8 , & V_237 -> V_158 ,
& V_30 , & V_31 ) )
return 0 ;
if ( ! memcmp ( & V_30 , & V_5 -> V_50 [ V_13 ] . V_51 . V_55 . V_53 , sizeof( V_30 ) ) ) {
V_226 = F_15 ( V_227 ) ;
if ( V_226 && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 )
return V_226 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_237 -> V_158 , 1 ) ;
return 0 ;
}
if ( ( exp = F_12 ( V_5 ) ) == NULL )
return - 1 ;
F_13 ( exp , V_54 , F_8 ( V_5 ) ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_53 , & V_30 ,
V_62 , NULL , & V_31 ) ;
exp -> V_63 = V_64 ;
exp -> V_126 = V_149 ;
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
unsigned char * * V_8 , T_25 * V_238 )
{
F_10 (set_ras_addr_hook) V_212 ;
F_6 ( L_53 ) ;
V_212 = F_15 ( V_213 ) ;
if ( V_212 && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 )
return V_212 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_238 -> V_239 , 1 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , T_26 * V_240 )
{
int V_13 = F_3 ( V_7 ) ;
int V_43 = 0 ;
T_2 V_31 ;
union V_29 V_30 ;
struct V_46 * exp ;
F_6 ( L_54 ) ;
if ( ! F_29 ( V_5 , * V_8 , & V_240 -> V_220 ,
& V_30 , & V_31 ) )
return 0 ;
if ( ( exp = F_12 ( V_5 ) ) == NULL )
return - 1 ;
F_13 ( exp , V_54 , F_8 ( V_5 ) ,
& V_5 -> V_50 [ ! V_13 ] . V_51 . V_52 . V_53 , & V_30 ,
V_62 , NULL , & V_31 ) ;
exp -> V_63 = V_64 ;
exp -> V_126 = V_149 ;
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
unsigned char * * V_8 , T_27 * V_241 )
{
int V_43 ;
F_10 (set_ras_addr_hook) V_212 ;
F_10 (set_sig_addr_hook) V_226 ;
F_6 ( L_55 ) ;
V_212 = F_15 ( V_213 ) ;
if ( V_212 && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 ) {
V_43 = V_212 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_241 -> V_214 , 1 ) ;
if ( V_43 < 0 )
return - 1 ;
}
V_226 = F_15 ( V_227 ) ;
if ( V_226 && F_8 ( V_5 ) == V_58 &&
V_5 -> V_59 & V_60 ) {
V_43 = V_226 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
V_241 -> V_220 . V_166 ,
V_241 -> V_220 . V_165 ) ;
if ( V_43 < 0 )
return - 1 ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned int V_3 ,
unsigned char * * V_8 , T_28 * V_242 )
{
switch ( V_242 -> V_33 ) {
case V_243 :
return F_57 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_242 -> V_244 ) ;
case V_245 :
return F_58 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_242 -> V_246 ) ;
case V_247 :
return F_60 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_242 -> V_248 ) ;
case V_249 :
return F_61 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_242 -> V_250 ) ;
case V_251 :
return F_64 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_242 -> V_252 ) ;
case V_253 :
return F_66 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_242 -> V_254 ) ;
case V_255 :
return F_67 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_242 -> V_256 ) ;
case V_257 :
return F_68 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_242 -> V_258 ) ;
case V_259 :
return F_69 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_242 -> V_260 ) ;
case V_261 :
return F_70 ( V_2 , V_5 , V_7 , V_3 , V_8 ,
& V_242 -> V_262 ) ;
default:
F_6 ( L_56 , V_242 -> V_33 ) ;
break;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 , enum V_6 V_7 )
{
static T_28 V_242 ;
unsigned char * V_8 ;
int V_9 = 0 ;
int V_43 ;
F_6 ( L_57 , V_2 -> V_23 ) ;
F_25 ( & V_116 ) ;
V_8 = F_52 ( V_2 , V_3 , & V_9 ) ;
if ( V_8 == NULL )
goto V_263;
F_6 ( L_58 , V_9 ) ;
F_17 ( & V_5 -> V_50 [ F_3 ( V_7 ) ] . V_51 ) ;
V_43 = F_73 ( V_8 , V_9 , & V_242 ) ;
if ( V_43 < 0 ) {
F_6 ( L_59 ,
V_43 == V_117 ?
L_19 : L_20 ) ;
goto V_263;
}
if ( F_71 ( V_2 , V_5 , V_7 , V_3 , & V_8 , & V_242 ) < 0 )
goto V_118;
V_263:
F_27 ( & V_116 ) ;
return V_115 ;
V_118:
F_27 ( & V_116 ) ;
F_28 ( V_2 , V_5 , L_60 ) ;
return V_119 ;
}
static void T_29 F_74 ( void )
{
F_75 ( & V_218 [ 1 ] ) ;
F_75 ( & V_218 [ 0 ] ) ;
F_75 ( & V_149 [ 1 ] ) ;
F_75 ( & V_149 [ 0 ] ) ;
F_75 ( & V_127 ) ;
F_76 ( V_25 ) ;
F_6 ( L_61 ) ;
}
static int T_30 F_77 ( void )
{
int V_43 ;
V_25 = F_78 ( 65536 , V_264 ) ;
if ( ! V_25 )
return - V_265 ;
V_43 = F_79 ( & V_127 ) ;
if ( V_43 < 0 )
goto V_266;
V_43 = F_79 ( & V_149 [ 0 ] ) ;
if ( V_43 < 0 )
goto V_267;
V_43 = F_79 ( & V_149 [ 1 ] ) ;
if ( V_43 < 0 )
goto V_268;
V_43 = F_79 ( & V_218 [ 0 ] ) ;
if ( V_43 < 0 )
goto V_269;
V_43 = F_79 ( & V_218 [ 1 ] ) ;
if ( V_43 < 0 )
goto V_270;
F_6 ( L_62 ) ;
return 0 ;
V_270:
F_75 ( & V_218 [ 0 ] ) ;
V_269:
F_75 ( & V_149 [ 1 ] ) ;
V_268:
F_75 ( & V_149 [ 0 ] ) ;
V_267:
F_75 ( & V_127 ) ;
V_266:
F_76 ( V_25 ) ;
return V_43 ;
}
