static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 , enum V_6 V_7 ,
unsigned char * * V_8 , int * V_9 , int * V_10 )
{
struct V_11 * V_12 = & F_2 ( V_5 ) -> V_13 . V_14 ;
int V_15 = F_3 ( V_7 ) ;
const struct V_16 * V_17 ;
struct V_16 V_18 ;
int V_19 ;
int V_20 ;
unsigned char * V_21 ;
int V_22 ;
int V_23 ;
V_17 = F_4 ( V_2 , V_3 , sizeof( V_18 ) , & V_18 ) ;
if ( V_17 == NULL )
return 0 ;
V_20 = V_3 + V_17 -> V_24 * 4 ;
V_19 = V_2 -> V_25 - V_20 ;
if ( V_19 <= 0 )
goto V_26;
if ( * V_8 == NULL ) {
V_21 = F_4 ( V_2 , V_20 , V_19 ,
V_27 ) ;
F_5 ( V_21 == NULL ) ;
if ( V_19 < 4 || V_21 [ 0 ] != 0x03 || V_21 [ 1 ] != 0 ) {
if ( V_12 -> V_28 [ V_15 ] > 0 ) {
F_6 ( L_1
L_2
L_3 , V_12 -> V_28 [ V_15 ] ) ;
if ( V_12 -> V_28 [ V_15 ] <= V_19 ) {
* V_8 = V_21 ;
* V_9 = V_12 -> V_28 [ V_15 ] ;
* V_10 = 0 ;
goto V_29;
}
F_6 ( L_4 ) ;
goto V_26;
}
return 0 ;
}
V_23 = 0 ;
} else {
V_23 = * V_10 + * V_9 ;
V_19 -= V_23 ;
if ( V_19 <= 4 )
goto V_26;
V_21 = * V_8 + * V_9 ;
if ( V_21 [ 0 ] != 0x03 || V_21 [ 1 ] != 0 )
goto V_26;
}
V_22 = V_21 [ 2 ] * 256 + V_21 [ 3 ] ;
if ( V_22 < 4 )
goto V_26;
if ( V_22 > V_19 ) {
if ( V_19 == 4 ) {
F_6 ( L_5
L_6 ,
V_22 - 4 ) ;
V_12 -> V_28 [ V_15 ] = V_22 - 4 ;
return 0 ;
}
F_6 ( L_7 ) ;
goto V_26;
}
* V_8 = V_21 + 4 ;
* V_9 = V_22 - 4 ;
* V_10 = V_23 + 4 ;
V_29:
V_12 -> V_28 [ V_15 ] = 0 ;
return 1 ;
V_26:
V_12 -> V_28 [ V_15 ] = 0 ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 , const unsigned char * V_8 ,
T_1 * V_30 ,
union V_31 * V_32 , T_2 * V_33 )
{
const unsigned char * V_34 ;
int V_25 ;
if ( V_30 -> V_35 != V_36 )
return 0 ;
switch ( V_30 -> V_37 . V_35 ) {
case V_38 :
if ( F_8 ( V_5 ) != V_39 )
return 0 ;
V_34 = V_8 + V_30 -> V_37 . V_40 . V_41 ;
V_25 = 4 ;
break;
case V_42 :
if ( F_8 ( V_5 ) != V_43 )
return 0 ;
V_34 = V_8 + V_30 -> V_37 . V_44 . V_41 ;
V_25 = 16 ;
break;
default:
return 0 ;
}
memcpy ( V_32 , V_34 , V_25 ) ;
memset ( ( void * ) V_32 + V_25 , 0 , sizeof( * V_32 ) - V_25 ) ;
memcpy ( V_33 , V_34 + V_25 , sizeof( T_2 ) ) ;
return 1 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 ,
T_1 * V_30 )
{
int V_15 = F_3 ( V_7 ) ;
int V_45 = 0 ;
T_2 V_33 ;
T_2 V_46 , V_47 ;
union V_31 V_32 ;
struct V_48 * V_49 ;
struct V_48 * V_50 ;
F_10 (nat_rtp_rtcp_hook) V_51 ;
if ( ! F_7 ( V_5 , * V_8 , V_30 , & V_32 , & V_33 ) ||
memcmp ( & V_32 , & V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 , sizeof( V_32 ) ) ||
V_33 == 0 )
return 0 ;
V_46 = V_33 & ~ F_11 ( 1 ) ;
V_47 = V_33 | F_11 ( 1 ) ;
if ( ( V_49 = F_12 ( V_5 ) ) == NULL )
return - 1 ;
F_13 ( V_49 , V_56 , F_8 ( V_5 ) ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
V_58 , NULL , & V_46 ) ;
if ( ( V_50 = F_12 ( V_5 ) ) == NULL ) {
F_14 ( V_49 ) ;
return - 1 ;
}
F_13 ( V_50 , V_56 , F_8 ( V_5 ) ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
V_58 , NULL , & V_47 ) ;
if ( memcmp ( & V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
sizeof( V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 ) ) &&
( V_51 = F_15 ( V_59 ) ) &&
V_5 -> V_60 & V_61 ) {
V_45 = V_51 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
V_30 , V_33 , V_46 , V_49 , V_50 ) ;
} else {
if ( F_16 ( V_49 ) == 0 ) {
if ( F_16 ( V_50 ) == 0 ) {
F_6 ( L_8 ) ;
F_17 ( & V_49 -> V_53 ) ;
F_6 ( L_9 ) ;
F_17 ( & V_50 -> V_53 ) ;
} else {
F_18 ( V_49 ) ;
V_45 = - 1 ;
}
} else
V_45 = - 1 ;
}
F_14 ( V_49 ) ;
F_14 ( V_50 ) ;
return V_45 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 ,
T_1 * V_30 )
{
int V_15 = F_3 ( V_7 ) ;
int V_45 = 0 ;
T_2 V_33 ;
union V_31 V_32 ;
struct V_48 * exp ;
F_10 (nat_t120_hook) V_62 ;
if ( ! F_7 ( V_5 , * V_8 , V_30 , & V_32 , & V_33 ) ||
memcmp ( & V_32 , & V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 , sizeof( V_32 ) ) ||
V_33 == 0 )
return 0 ;
if ( ( exp = F_12 ( V_5 ) ) == NULL )
return - 1 ;
F_13 ( exp , V_56 , F_8 ( V_5 ) ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
V_63 , NULL , & V_33 ) ;
exp -> V_64 = V_65 ;
if ( memcmp ( & V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
sizeof( V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 ) ) &&
( V_62 = F_15 ( V_66 ) ) &&
V_5 -> V_60 & V_61 ) {
V_45 = V_62 ( V_2 , V_5 , V_7 , V_8 , V_10 , V_30 ,
V_33 , exp ) ;
} else {
if ( F_16 ( exp ) == 0 ) {
F_6 ( L_10 ) ;
F_17 ( & exp -> V_53 ) ;
} else
V_45 = - 1 ;
}
F_14 ( exp ) ;
return V_45 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 ,
T_3 * V_67 )
{
int V_45 ;
if ( V_67 -> V_68 & V_69 ) {
V_45 = F_9 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_67 -> V_70 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( V_67 ->
V_68 & V_71 ) {
V_45 = F_9 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_67 -> V_72 ) ;
if ( V_45 < 0 )
return - 1 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 ,
T_4 * V_73 )
{
int V_45 ;
F_6 ( L_11 ) ;
if ( V_73 -> V_74 . V_75 . V_35 ==
V_76 )
{
V_45 = F_20 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_73 ->
V_74 .
V_75 .
V_77 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( ( V_73 -> V_68 &
V_78 ) &&
( V_73 -> V_79 . V_68 &
V_80 )
&& ( V_73 -> V_79 . V_75 .
V_35 ==
V_81 ) )
{
V_45 =
F_20 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_73 ->
V_79 .
V_75 .
V_77 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( ( V_73 -> V_68 & V_82 ) &&
V_73 -> V_74 . V_83 . V_35 ==
V_84 &&
V_73 -> V_74 . V_83 . V_8 . V_85 .
V_35 == V_86 &&
V_73 -> V_74 . V_83 . V_8 . V_85 .
V_87 . V_35 == V_88 &&
V_73 -> V_89 . V_90 . V_35 ==
V_91 ) {
V_45 = F_19 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_73 -> V_89 . V_90 .
V_92 ) ;
if ( V_45 < 0 )
return - 1 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 ,
T_5 * V_93 )
{
T_6 * V_94 ;
int V_45 ;
F_6 ( L_12 ) ;
if ( ( V_93 -> V_68 &
V_95 ) &&
( V_93 -> V_79 . V_68 &
V_96 )
&& ( V_93 -> V_79 . V_75 .
V_35 ==
V_97 ) )
{
V_45 = F_20 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_93 ->
V_79 .
V_75 .
V_77 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( ( V_93 -> V_68 &
V_98 ) &&
( V_93 -> V_99 . V_35 ==
V_100 ) )
{
V_94 = & V_93 -> V_99 .
V_101 ;
if ( V_94 -> V_68 &
V_102 ) {
V_45 = F_9 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_94 -> V_70 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( V_94 -> V_68 &
V_103 ) {
V_45 = F_9 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_94 -> V_72 ) ;
if ( V_45 < 0 )
return - 1 ;
}
}
if ( ( V_93 -> V_68 & V_104 ) &&
V_93 -> V_89 . V_90 . V_35 ==
V_91 ) {
V_45 = F_19 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_93 -> V_89 . V_90 .
V_92 ) ;
if ( V_45 < 0 )
return - 1 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 ,
T_7 * V_105 )
{
switch ( V_105 -> V_35 ) {
case V_106 :
if ( V_105 -> V_107 . V_35 ==
V_108 ) {
return F_21 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_105 -> V_107 . V_109 ) ;
}
F_6 ( L_13 ,
V_105 -> V_107 . V_35 ) ;
break;
case V_110 :
if ( V_105 -> V_111 . V_35 ==
V_112 ) {
return F_22 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_105 -> V_111 .
V_113 ) ;
}
F_6 ( L_14 ,
V_105 -> V_111 . V_35 ) ;
break;
default:
F_6 ( L_15 , V_105 -> V_35 ) ;
break;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 , enum V_6 V_7 )
{
static T_7 V_105 ;
unsigned char * V_8 = NULL ;
int V_9 ;
int V_10 ;
int V_45 ;
if ( V_7 != V_114 && V_7 != V_115 )
return V_116 ;
F_6 ( L_16 , V_2 -> V_25 ) ;
F_25 ( & V_117 ) ;
while ( F_1 ( V_2 , V_3 , V_5 , V_7 ,
& V_8 , & V_9 , & V_10 ) ) {
F_6 ( L_17 , V_9 ) ;
F_17 ( & V_5 -> V_52 [ F_3 ( V_7 ) ] . V_53 ) ;
V_45 = F_26 ( V_8 , V_9 ,
& V_105 ) ;
if ( V_45 < 0 ) {
F_6 ( L_18 ,
V_45 == V_118 ?
L_19 : L_20 ) ;
break;
}
if ( F_23 ( V_2 , V_5 , V_7 , & V_8 , V_10 , & V_105 ) < 0 )
goto V_119;
}
F_27 ( & V_117 ) ;
return V_116 ;
V_119:
F_27 ( & V_117 ) ;
F_28 ( L_21 ) ;
return V_120 ;
}
int F_29 ( struct V_4 * V_5 , unsigned char * V_8 ,
T_8 * V_30 ,
union V_31 * V_32 , T_2 * V_33 )
{
const unsigned char * V_34 ;
int V_25 ;
switch ( V_30 -> V_35 ) {
case V_121 :
if ( F_8 ( V_5 ) != V_39 )
return 0 ;
V_34 = V_8 + V_30 -> V_122 . V_123 ;
V_25 = 4 ;
break;
case V_124 :
if ( F_8 ( V_5 ) != V_43 )
return 0 ;
V_34 = V_8 + V_30 -> V_125 . V_123 ;
V_25 = 16 ;
break;
default:
return 0 ;
}
memcpy ( V_32 , V_34 , V_25 ) ;
memset ( ( void * ) V_32 + V_25 , 0 , sizeof( * V_32 ) - V_25 ) ;
memcpy ( V_33 , V_34 + V_25 , sizeof( T_2 ) ) ;
return 1 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 ,
T_8 * V_30 )
{
int V_15 = F_3 ( V_7 ) ;
int V_45 = 0 ;
T_2 V_33 ;
union V_31 V_32 ;
struct V_48 * exp ;
F_10 (nat_h245_hook) V_126 ;
if ( ! F_29 ( V_5 , * V_8 , V_30 , & V_32 , & V_33 ) ||
memcmp ( & V_32 , & V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 , sizeof( V_32 ) ) ||
V_33 == 0 )
return 0 ;
if ( ( exp = F_12 ( V_5 ) ) == NULL )
return - 1 ;
F_13 ( exp , V_56 , F_8 ( V_5 ) ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
V_63 , NULL , & V_33 ) ;
exp -> V_127 = & V_128 ;
if ( memcmp ( & V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
sizeof( V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 ) ) &&
( V_126 = F_15 ( V_129 ) ) &&
V_5 -> V_60 & V_61 ) {
V_45 = V_126 ( V_2 , V_5 , V_7 , V_8 , V_10 , V_30 ,
V_33 , exp ) ;
} else {
if ( F_16 ( exp ) == 0 ) {
F_6 ( L_22 ) ;
F_17 ( & exp -> V_53 ) ;
} else
V_45 = - 1 ;
}
F_14 ( exp ) ;
return V_45 ;
}
static int F_31 ( const union V_31 * V_54 ,
const union V_31 * V_57 ,
T_9 V_130 )
{
const struct V_131 * V_132 ;
int V_45 = 0 ;
V_132 = F_32 ( V_130 ) ;
if ( ! V_132 )
return 0 ;
switch ( V_130 ) {
case V_39 : {
struct V_133 V_134 , V_135 ;
struct V_136 * V_137 , * V_138 ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
V_134 . V_139 = V_54 -> V_123 ;
memset ( & V_135 , 0 , sizeof( V_135 ) ) ;
V_135 . V_139 = V_57 -> V_123 ;
if ( ! V_132 -> V_140 ( & V_141 , (struct V_142 * * ) & V_137 ,
F_33 ( & V_134 ) , false ) ) {
if ( ! V_132 -> V_140 ( & V_141 , (struct V_142 * * ) & V_138 ,
F_33 ( & V_135 ) , false ) ) {
if ( V_137 -> V_143 == V_138 -> V_143 &&
V_137 -> V_57 . V_144 == V_138 -> V_57 . V_144 )
V_45 = 1 ;
F_34 ( & V_138 -> V_57 ) ;
}
F_34 ( & V_137 -> V_57 ) ;
}
break;
}
#if F_35 ( V_145 )
case V_43 : {
struct V_146 V_134 , V_135 ;
struct V_147 * V_137 , * V_138 ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
V_134 . V_139 = V_54 -> V_148 ;
memset ( & V_135 , 0 , sizeof( V_135 ) ) ;
V_135 . V_139 = V_57 -> V_148 ;
if ( ! V_132 -> V_140 ( & V_141 , (struct V_142 * * ) & V_137 ,
F_36 ( & V_134 ) , false ) ) {
if ( ! V_132 -> V_140 ( & V_141 , (struct V_142 * * ) & V_138 ,
F_36 ( & V_135 ) , false ) ) {
if ( ! memcmp ( & V_137 -> V_149 , & V_138 -> V_149 ,
sizeof( V_137 -> V_149 ) ) &&
V_137 -> V_57 . V_144 == V_138 -> V_57 . V_144 )
V_45 = 1 ;
F_34 ( & V_138 -> V_57 ) ;
}
F_34 ( & V_137 -> V_57 ) ;
}
break;
}
#endif
}
return V_45 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 ,
T_8 * V_30 )
{
int V_15 = F_3 ( V_7 ) ;
int V_45 = 0 ;
T_2 V_33 ;
union V_31 V_32 ;
struct V_48 * exp ;
F_10 (nat_callforwarding_hook) V_150 ;
if ( ! F_29 ( V_5 , * V_8 , V_30 , & V_32 , & V_33 ) || V_33 == 0 )
return 0 ;
if ( V_151 &&
F_31 ( & V_32 , & V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 ,
F_8 ( V_5 ) ) ) {
F_6 ( L_23 ) ;
return 0 ;
}
if ( ( exp = F_12 ( V_5 ) ) == NULL )
return - 1 ;
F_13 ( exp , V_56 , F_8 ( V_5 ) ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 , & V_32 ,
V_63 , NULL , & V_33 ) ;
exp -> V_127 = V_152 ;
if ( memcmp ( & V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
sizeof( V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 ) ) &&
( V_150 = F_15 ( V_153 ) ) &&
V_5 -> V_60 & V_61 ) {
V_45 = V_150 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
V_30 , V_33 , exp ) ;
} else {
if ( F_16 ( exp ) == 0 ) {
F_6 ( L_24 ) ;
F_17 ( & exp -> V_53 ) ;
} else
V_45 = - 1 ;
}
F_14 ( exp ) ;
return V_45 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 ,
T_10 * V_154 )
{
int V_15 = F_3 ( V_7 ) ;
int V_45 ;
int V_155 ;
T_2 V_33 ;
union V_31 V_32 ;
F_10 (set_h225_addr_hook) V_156 ;
F_6 ( L_25 ) ;
if ( V_154 -> V_68 & V_157 ) {
V_45 = F_30 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_154 -> V_158 ) ;
if ( V_45 < 0 )
return - 1 ;
}
V_156 = F_15 ( V_159 ) ;
if ( ( V_154 -> V_68 & V_160 ) &&
( V_156 ) && V_5 -> V_60 & V_61 &&
F_29 ( V_5 , * V_8 , & V_154 -> V_161 ,
& V_32 , & V_33 ) &&
memcmp ( & V_32 , & V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 , sizeof( V_32 ) ) ) {
F_6 ( L_26 ,
& V_32 , F_39 ( V_33 ) , & V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 ,
F_39 ( V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_162 . V_163 . V_33 ) ) ;
V_45 = V_156 ( V_2 , V_8 , V_10 ,
& V_154 -> V_161 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 ,
V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_162 . V_163 . V_33 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( ( V_154 -> V_68 & V_164 ) &&
( V_156 ) && V_5 -> V_60 & V_61 &&
F_29 ( V_5 , * V_8 , & V_154 -> V_165 ,
& V_32 , & V_33 ) &&
memcmp ( & V_32 , & V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 , sizeof( V_32 ) ) ) {
F_6 ( L_27 ,
& V_32 , F_39 ( V_33 ) , & V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
F_39 ( V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_162 . V_163 . V_33 ) ) ;
V_45 = V_156 ( V_2 , V_8 , V_10 ,
& V_154 -> V_165 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_162 . V_163 . V_33 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( V_154 -> V_68 & V_166 ) {
for ( V_155 = 0 ; V_155 < V_154 -> V_167 . V_168 ; V_155 ++ ) {
V_45 = F_21 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_154 -> V_167 . V_169 [ V_155 ] ) ;
if ( V_45 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 ,
T_11 * V_170 )
{
int V_45 ;
int V_155 ;
F_6 ( L_28 ) ;
if ( V_170 -> V_68 & V_171 ) {
V_45 = F_30 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_170 -> V_158 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( V_170 -> V_68 & V_172 ) {
for ( V_155 = 0 ; V_155 < V_170 -> V_167 . V_168 ; V_155 ++ ) {
V_45 = F_21 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_170 -> V_167 . V_169 [ V_155 ] ) ;
if ( V_45 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 ,
T_12 * V_173 )
{
int V_45 ;
int V_155 ;
F_6 ( L_29 ) ;
if ( V_173 -> V_68 & V_174 ) {
V_45 = F_30 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_173 -> V_158 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( V_173 -> V_68 & V_175 ) {
for ( V_155 = 0 ; V_155 < V_173 -> V_167 . V_168 ; V_155 ++ ) {
V_45 = F_21 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_173 -> V_167 . V_169 [ V_155 ] ) ;
if ( V_45 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 ,
T_13 * V_176 )
{
int V_45 ;
int V_155 ;
F_6 ( L_30 ) ;
if ( V_176 -> V_68 & V_177 ) {
V_45 = F_30 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_176 -> V_158 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( V_176 -> V_68 & V_178 ) {
for ( V_155 = 0 ; V_155 < V_176 -> V_167 . V_168 ; V_155 ++ ) {
V_45 = F_21 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_176 -> V_167 . V_169 [ V_155 ] ) ;
if ( V_45 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 ,
T_14 * V_179 )
{
int V_45 ;
int V_155 ;
F_6 ( L_31 ) ;
if ( V_179 -> V_180 . V_35 == V_181 ) {
if ( V_179 -> V_68 & V_182 )
return F_37 ( V_2 , V_5 , V_7 , V_8 ,
V_10 ,
& V_179 ->
V_183 ) ;
return 0 ;
}
if ( V_179 -> V_68 & V_184 ) {
V_45 = F_30 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_179 -> V_158 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( V_179 -> V_68 & V_185 ) {
for ( V_155 = 0 ; V_155 < V_179 -> V_167 . V_168 ; V_155 ++ ) {
V_45 = F_21 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_179 -> V_167 . V_169 [ V_155 ] ) ;
if ( V_45 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 ,
T_15 * V_186 )
{
int V_45 ;
int V_155 ;
F_6 ( L_32 ) ;
if ( V_186 -> V_68 & V_187 ) {
V_45 = F_30 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_186 -> V_158 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( V_186 -> V_68 & V_188 ) {
for ( V_155 = 0 ; V_155 < V_186 -> V_167 . V_168 ; V_155 ++ ) {
V_45 = F_21 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_186 -> V_167 . V_169 [ V_155 ] ) ;
if ( V_45 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 , T_16 * V_189 )
{
T_17 * V_190 = & V_189 -> V_191 . V_192 ;
int V_155 ;
int V_45 = 0 ;
switch ( V_190 -> V_193 . V_35 ) {
case V_194 :
V_45 = F_38 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_190 -> V_193 . V_154 ) ;
break;
case V_195 :
V_45 = F_40 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_190 -> V_193 .
V_196 ) ;
break;
case V_197 :
V_45 = F_41 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_190 -> V_193 . V_173 ) ;
break;
case V_198 :
V_45 = F_42 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_190 -> V_193 . V_199 ) ;
break;
case V_200 :
V_45 = F_43 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_190 -> V_193 . V_179 ) ;
break;
case V_201 :
V_45 = F_44 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_190 -> V_193 . V_186 ) ;
break;
default:
F_6 ( L_33 ,
V_190 -> V_193 . V_35 ) ;
break;
}
if ( V_45 < 0 )
return - 1 ;
if ( V_190 -> V_68 & V_202 ) {
for ( V_155 = 0 ; V_155 < V_190 -> V_203 . V_168 ; V_155 ++ ) {
V_45 = F_23 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_190 -> V_203 . V_169 [ V_155 ] ) ;
if ( V_45 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 , enum V_6 V_7 )
{
static T_16 V_189 ;
unsigned char * V_8 = NULL ;
int V_9 ;
int V_10 ;
int V_45 ;
if ( V_7 != V_114 && V_7 != V_115 )
return V_116 ;
F_6 ( L_34 , V_2 -> V_25 ) ;
F_25 ( & V_117 ) ;
while ( F_1 ( V_2 , V_3 , V_5 , V_7 ,
& V_8 , & V_9 , & V_10 ) ) {
F_6 ( L_35 , V_9 ) ;
F_17 ( & V_5 -> V_52 [ F_3 ( V_7 ) ] . V_53 ) ;
V_45 = F_47 ( V_8 , V_9 , & V_189 ) ;
if ( V_45 < 0 ) {
F_6 ( L_36 ,
V_45 == V_118 ?
L_19 : L_20 ) ;
break;
}
if ( F_45 ( V_2 , V_5 , V_7 , & V_8 , V_10 , & V_189 ) < 0 )
goto V_119;
}
F_27 ( & V_117 ) ;
return V_116 ;
V_119:
F_27 ( & V_117 ) ;
F_28 ( L_37 ) ;
return V_120 ;
}
static unsigned char * F_48 ( struct V_1 * V_2 , unsigned int V_3 ,
int * V_9 )
{
const struct V_204 * V_205 ;
struct V_204 V_206 ;
int V_10 ;
V_205 = F_4 ( V_2 , V_3 , sizeof( V_206 ) , & V_206 ) ;
if ( V_205 == NULL )
return NULL ;
V_10 = V_3 + sizeof( V_206 ) ;
if ( V_10 >= V_2 -> V_25 )
return NULL ;
* V_9 = V_2 -> V_25 - V_10 ;
return F_4 ( V_2 , V_10 , * V_9 , V_27 ) ;
}
static struct V_48 * F_49 ( struct V_4 * V_5 ,
union V_31 * V_32 ,
T_2 V_33 )
{
struct V_207 * V_207 = F_50 ( V_5 ) ;
struct V_48 * exp ;
struct V_208 V_53 ;
memset ( & V_53 . V_54 . V_55 , 0 , sizeof( V_53 . V_54 . V_55 ) ) ;
V_53 . V_54 . V_162 . V_163 . V_33 = 0 ;
memcpy ( & V_53 . V_57 . V_55 , V_32 , sizeof( V_53 . V_57 . V_55 ) ) ;
V_53 . V_57 . V_162 . V_163 . V_33 = V_33 ;
V_53 . V_57 . V_209 = V_63 ;
exp = F_51 ( V_207 , F_52 ( V_5 ) , & V_53 ) ;
if ( exp && exp -> V_210 == V_5 )
return exp ;
return NULL ;
}
static int F_53 ( struct V_48 * exp ,
unsigned int V_211 )
{
if ( ! exp || ! F_54 ( & exp -> V_211 ) )
return 0 ;
exp -> V_211 . V_212 = V_213 + V_211 * V_214 ;
F_55 ( & exp -> V_211 ) ;
return 1 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 ,
T_8 * V_30 , int V_168 )
{
struct V_11 * V_12 = & F_2 ( V_5 ) -> V_13 . V_14 ;
int V_15 = F_3 ( V_7 ) ;
int V_45 = 0 ;
int V_155 ;
T_2 V_33 ;
union V_31 V_32 ;
struct V_48 * exp ;
F_10 (nat_q931_hook) V_215 ;
for ( V_155 = 0 ; V_155 < V_168 ; V_155 ++ ) {
if ( F_29 ( V_5 , * V_8 , & V_30 [ V_155 ] , & V_32 , & V_33 ) &&
memcmp ( & V_32 , & V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 ,
sizeof( V_32 ) ) == 0 && V_33 != 0 )
break;
}
if ( V_155 >= V_168 )
return 0 ;
if ( ( exp = F_12 ( V_5 ) ) == NULL )
return - 1 ;
F_13 ( exp , V_56 , F_8 ( V_5 ) ,
V_216 ?
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 : NULL ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
V_63 , NULL , & V_33 ) ;
exp -> V_127 = V_152 ;
exp -> V_64 = V_65 ;
V_215 = F_15 ( V_217 ) ;
if ( V_215 && V_5 -> V_60 & V_61 ) {
V_45 = V_215 ( V_2 , V_5 , V_7 , V_8 , V_30 , V_155 , V_33 , exp ) ;
} else {
if ( F_16 ( exp ) == 0 ) {
F_6 ( L_38 ) ;
F_17 ( & exp -> V_53 ) ;
V_12 -> V_218 [ V_15 ] = V_33 ;
} else
V_45 = - 1 ;
}
F_14 ( exp ) ;
return V_45 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , T_18 * V_219 )
{
F_10 (set_ras_addr_hook) V_220 ;
F_6 ( L_39 ) ;
V_220 = F_15 ( V_221 ) ;
if ( V_220 && V_5 -> V_60 & V_61 )
return V_220 ( V_2 , V_5 , V_7 , V_8 ,
& V_219 -> V_222 , 1 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , T_19 * V_223 )
{
int V_15 = F_3 ( V_7 ) ;
int V_45 = 0 ;
T_2 V_33 ;
union V_31 V_32 ;
struct V_48 * exp ;
F_6 ( L_40 ) ;
if ( ! F_29 ( V_5 , * V_8 , & V_223 -> V_222 , & V_32 , & V_33 ) )
return 0 ;
if ( ! memcmp ( & V_32 , & V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 , sizeof( V_32 ) ) &&
V_33 == V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_162 . V_224 . V_33 )
return 0 ;
if ( F_59 ( V_225 , & V_5 -> V_60 ) )
return 0 ;
if ( ( exp = F_12 ( V_5 ) ) == NULL )
return - 1 ;
F_13 ( exp , V_56 , F_8 ( V_5 ) ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 , & V_32 ,
V_58 , NULL , & V_33 ) ;
exp -> V_127 = V_226 ;
if ( F_16 ( exp ) == 0 ) {
F_6 ( L_41 ) ;
F_17 ( & exp -> V_53 ) ;
} else
V_45 = - 1 ;
F_14 ( exp ) ;
return V_45 ;
}
static int F_60 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , T_20 * V_227 )
{
struct V_11 * V_12 = & F_2 ( V_5 ) -> V_13 . V_14 ;
int V_45 ;
F_10 (set_ras_addr_hook) V_220 ;
F_6 ( L_42 ) ;
V_45 = F_56 ( V_2 , V_5 , V_7 , V_8 ,
V_227 -> V_228 . V_169 ,
V_227 -> V_228 . V_168 ) ;
if ( V_45 < 0 )
return - 1 ;
V_220 = F_15 ( V_221 ) ;
if ( V_220 && V_5 -> V_60 & V_61 ) {
V_45 = V_220 ( V_2 , V_5 , V_7 , V_8 ,
V_227 -> V_222 . V_169 ,
V_227 -> V_222 . V_168 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( V_227 -> V_68 & V_229 ) {
F_6 ( L_43 , V_227 -> V_230 ) ;
V_12 -> V_211 = V_227 -> V_230 ;
} else
V_12 -> V_211 = V_231 ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , T_21 * V_232 )
{
struct V_11 * V_12 = & F_2 ( V_5 ) -> V_13 . V_14 ;
int V_15 = F_3 ( V_7 ) ;
int V_45 ;
struct V_48 * exp ;
F_10 (set_sig_addr_hook) V_233 ;
F_6 ( L_44 ) ;
V_233 = F_15 ( V_234 ) ;
if ( V_233 && V_5 -> V_60 & V_61 ) {
V_45 = V_233 ( V_2 , V_5 , V_7 , V_8 ,
V_232 -> V_228 . V_169 ,
V_232 -> V_228 . V_168 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( V_232 -> V_68 & V_235 ) {
F_6 ( L_45 , V_232 -> V_230 ) ;
V_12 -> V_211 = V_232 -> V_230 ;
}
if ( V_12 -> V_211 > 0 ) {
F_6 ( L_46
L_47 , V_12 -> V_211 ) ;
F_62 ( V_5 , V_2 , V_12 -> V_211 * V_214 ) ;
F_25 ( & V_236 ) ;
exp = F_49 ( V_5 , & V_5 -> V_52 [ V_15 ] . V_53 . V_57 . V_55 ,
V_12 -> V_218 [ ! V_15 ] ) ;
if ( exp ) {
F_6 ( L_48
L_49 ,
V_12 -> V_211 ) ;
F_17 ( & exp -> V_53 ) ;
F_53 ( exp , V_12 -> V_211 ) ;
}
F_27 ( & V_236 ) ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , T_22 * V_237 )
{
struct V_11 * V_12 = & F_2 ( V_5 ) -> V_13 . V_14 ;
int V_15 = F_3 ( V_7 ) ;
int V_45 ;
F_10 (set_sig_addr_hook) V_233 ;
F_6 ( L_50 ) ;
V_233 = F_15 ( V_234 ) ;
if ( V_233 && V_5 -> V_60 & V_61 ) {
V_45 = V_233 ( V_2 , V_5 , V_7 , V_8 ,
V_237 -> V_228 . V_169 ,
V_237 -> V_228 . V_168 ) ;
if ( V_45 < 0 )
return - 1 ;
}
F_64 ( V_5 ) ;
V_12 -> V_218 [ V_15 ] = 0 ;
V_12 -> V_218 [ ! V_15 ] = 0 ;
F_62 ( V_5 , V_2 , 30 * V_214 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , T_23 * V_238 )
{
const struct V_11 * V_12 = & F_2 ( V_5 ) -> V_13 . V_14 ;
int V_15 = F_3 ( V_7 ) ;
T_2 V_33 ;
union V_31 V_32 ;
F_10 (set_h225_addr_hook) V_156 ;
F_6 ( L_51 ) ;
V_156 = F_15 ( V_159 ) ;
if ( ( V_238 -> V_68 & V_239 ) &&
F_29 ( V_5 , * V_8 , & V_238 -> V_161 ,
& V_32 , & V_33 ) &&
! memcmp ( & V_32 , & V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 , sizeof( V_32 ) ) &&
V_33 == V_12 -> V_218 [ V_15 ] &&
V_156 && V_5 -> V_60 & V_61 ) {
return V_156 ( V_2 , V_8 , 0 ,
& V_238 -> V_161 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
V_12 -> V_218 [ ! V_15 ] ) ;
}
if ( ( V_238 -> V_68 & V_240 ) &&
F_29 ( V_5 , * V_8 , & V_238 -> V_241 ,
& V_32 , & V_33 ) &&
! memcmp ( & V_32 , & V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 , sizeof( V_32 ) ) &&
V_156 && V_5 -> V_60 & V_61 ) {
return V_156 ( V_2 , V_8 , 0 ,
& V_238 -> V_241 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
V_33 ) ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , T_24 * V_242 )
{
int V_15 = F_3 ( V_7 ) ;
int V_45 = 0 ;
T_2 V_33 ;
union V_31 V_32 ;
struct V_48 * exp ;
F_10 (set_sig_addr_hook) V_233 ;
F_6 ( L_52 ) ;
if ( ! F_29 ( V_5 , * V_8 , & V_242 -> V_161 ,
& V_32 , & V_33 ) )
return 0 ;
if ( ! memcmp ( & V_32 , & V_5 -> V_52 [ V_15 ] . V_53 . V_57 . V_55 , sizeof( V_32 ) ) ) {
V_233 = F_15 ( V_234 ) ;
if ( V_233 && V_5 -> V_60 & V_61 )
return V_233 ( V_2 , V_5 , V_7 , V_8 ,
& V_242 -> V_161 , 1 ) ;
return 0 ;
}
if ( ( exp = F_12 ( V_5 ) ) == NULL )
return - 1 ;
F_13 ( exp , V_56 , F_8 ( V_5 ) ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 , & V_32 ,
V_63 , NULL , & V_33 ) ;
exp -> V_64 = V_65 ;
exp -> V_127 = V_152 ;
if ( F_16 ( exp ) == 0 ) {
F_6 ( L_38 ) ;
F_17 ( & exp -> V_53 ) ;
} else
V_45 = - 1 ;
F_14 ( exp ) ;
return V_45 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , T_25 * V_243 )
{
F_10 (set_ras_addr_hook) V_220 ;
F_6 ( L_53 ) ;
V_220 = F_15 ( V_221 ) ;
if ( V_220 && V_5 -> V_60 & V_61 )
return V_220 ( V_2 , V_5 , V_7 , V_8 ,
& V_243 -> V_244 , 1 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , T_26 * V_245 )
{
int V_15 = F_3 ( V_7 ) ;
int V_45 = 0 ;
T_2 V_33 ;
union V_31 V_32 ;
struct V_48 * exp ;
F_6 ( L_54 ) ;
if ( ! F_29 ( V_5 , * V_8 , & V_245 -> V_228 ,
& V_32 , & V_33 ) )
return 0 ;
if ( ( exp = F_12 ( V_5 ) ) == NULL )
return - 1 ;
F_13 ( exp , V_56 , F_8 ( V_5 ) ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 , & V_32 ,
V_63 , NULL , & V_33 ) ;
exp -> V_64 = V_65 ;
exp -> V_127 = V_152 ;
if ( F_16 ( exp ) == 0 ) {
F_6 ( L_38 ) ;
F_17 ( & exp -> V_53 ) ;
} else
V_45 = - 1 ;
F_14 ( exp ) ;
return V_45 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , T_27 * V_246 )
{
int V_45 ;
F_10 (set_ras_addr_hook) V_220 ;
F_10 (set_sig_addr_hook) V_233 ;
F_6 ( L_55 ) ;
V_220 = F_15 ( V_221 ) ;
if ( V_220 && V_5 -> V_60 & V_61 ) {
V_45 = V_220 ( V_2 , V_5 , V_7 , V_8 ,
& V_246 -> V_222 , 1 ) ;
if ( V_45 < 0 )
return - 1 ;
}
V_233 = F_15 ( V_234 ) ;
if ( V_233 && V_5 -> V_60 & V_61 ) {
V_45 = V_233 ( V_2 , V_5 , V_7 , V_8 ,
V_246 -> V_228 . V_169 ,
V_246 -> V_228 . V_168 ) ;
if ( V_45 < 0 )
return - 1 ;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , T_28 * V_247 )
{
switch ( V_247 -> V_35 ) {
case V_248 :
return F_57 ( V_2 , V_5 , V_7 , V_8 ,
& V_247 -> V_249 ) ;
case V_250 :
return F_58 ( V_2 , V_5 , V_7 , V_8 ,
& V_247 -> V_251 ) ;
case V_252 :
return F_60 ( V_2 , V_5 , V_7 , V_8 ,
& V_247 -> V_253 ) ;
case V_254 :
return F_61 ( V_2 , V_5 , V_7 , V_8 ,
& V_247 -> V_255 ) ;
case V_256 :
return F_63 ( V_2 , V_5 , V_7 , V_8 ,
& V_247 -> V_257 ) ;
case V_258 :
return F_65 ( V_2 , V_5 , V_7 , V_8 ,
& V_247 -> V_259 ) ;
case V_260 :
return F_66 ( V_2 , V_5 , V_7 , V_8 ,
& V_247 -> V_261 ) ;
case V_262 :
return F_67 ( V_2 , V_5 , V_7 , V_8 ,
& V_247 -> V_263 ) ;
case V_264 :
return F_68 ( V_2 , V_5 , V_7 , V_8 ,
& V_247 -> V_265 ) ;
case V_266 :
return F_69 ( V_2 , V_5 , V_7 , V_8 ,
& V_247 -> V_267 ) ;
default:
F_6 ( L_56 , V_247 -> V_35 ) ;
break;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 , enum V_6 V_7 )
{
static T_28 V_247 ;
unsigned char * V_8 ;
int V_9 = 0 ;
int V_45 ;
F_6 ( L_57 , V_2 -> V_25 ) ;
F_25 ( & V_117 ) ;
V_8 = F_48 ( V_2 , V_3 , & V_9 ) ;
if ( V_8 == NULL )
goto V_268;
F_6 ( L_58 , V_9 ) ;
F_17 ( & V_5 -> V_52 [ F_3 ( V_7 ) ] . V_53 ) ;
V_45 = F_72 ( V_8 , V_9 , & V_247 ) ;
if ( V_45 < 0 ) {
F_6 ( L_59 ,
V_45 == V_118 ?
L_19 : L_20 ) ;
goto V_268;
}
if ( F_70 ( V_2 , V_5 , V_7 , & V_8 , & V_247 ) < 0 )
goto V_119;
V_268:
F_27 ( & V_117 ) ;
return V_116 ;
V_119:
F_27 ( & V_117 ) ;
F_28 ( L_60 ) ;
return V_120 ;
}
static void T_29 F_73 ( void )
{
F_74 ( & V_226 [ 1 ] ) ;
F_74 ( & V_226 [ 0 ] ) ;
F_74 ( & V_152 [ 1 ] ) ;
F_74 ( & V_152 [ 0 ] ) ;
F_74 ( & V_128 ) ;
F_75 ( V_27 ) ;
F_6 ( L_61 ) ;
}
static int T_30 F_76 ( void )
{
int V_45 ;
V_27 = F_77 ( 65536 , V_269 ) ;
if ( ! V_27 )
return - V_270 ;
V_45 = F_78 ( & V_128 ) ;
if ( V_45 < 0 )
goto V_271;
V_45 = F_78 ( & V_152 [ 0 ] ) ;
if ( V_45 < 0 )
goto V_272;
V_45 = F_78 ( & V_152 [ 1 ] ) ;
if ( V_45 < 0 )
goto V_273;
V_45 = F_78 ( & V_226 [ 0 ] ) ;
if ( V_45 < 0 )
goto V_274;
V_45 = F_78 ( & V_226 [ 1 ] ) ;
if ( V_45 < 0 )
goto V_275;
F_6 ( L_62 ) ;
return 0 ;
V_275:
F_74 ( & V_226 [ 0 ] ) ;
V_274:
F_74 ( & V_152 [ 1 ] ) ;
V_273:
F_74 ( & V_152 [ 0 ] ) ;
V_272:
F_74 ( & V_128 ) ;
V_271:
F_75 ( V_27 ) ;
return V_45 ;
}
