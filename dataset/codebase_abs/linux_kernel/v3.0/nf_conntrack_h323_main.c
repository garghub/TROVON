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
V_33 &= F_11 ( ~ 1 ) ;
V_46 = V_33 ;
V_47 = F_11 ( F_12 ( V_33 ) + 1 ) ;
if ( ( V_49 = F_13 ( V_5 ) ) == NULL )
return - 1 ;
F_14 ( V_49 , V_56 , F_8 ( V_5 ) ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
V_58 , NULL , & V_46 ) ;
if ( ( V_50 = F_13 ( V_5 ) ) == NULL ) {
F_15 ( V_49 ) ;
return - 1 ;
}
F_14 ( V_50 , V_56 , F_8 ( V_5 ) ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
V_58 , NULL , & V_47 ) ;
if ( memcmp ( & V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
sizeof( V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 ) ) &&
( V_51 = F_16 ( V_59 ) ) &&
V_5 -> V_60 & V_61 ) {
V_45 = V_51 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
V_30 , V_33 , V_46 , V_49 , V_50 ) ;
} else {
if ( F_17 ( V_49 ) == 0 ) {
if ( F_17 ( V_50 ) == 0 ) {
F_6 ( L_8 ) ;
F_18 ( & V_49 -> V_53 ) ;
F_6 ( L_9 ) ;
F_18 ( & V_50 -> V_53 ) ;
} else {
F_19 ( V_49 ) ;
V_45 = - 1 ;
}
} else
V_45 = - 1 ;
}
F_15 ( V_49 ) ;
F_15 ( V_50 ) ;
return V_45 ;
}
static int F_20 ( struct V_1 * V_2 ,
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
if ( ( exp = F_13 ( V_5 ) ) == NULL )
return - 1 ;
F_14 ( exp , V_56 , F_8 ( V_5 ) ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
V_63 , NULL , & V_33 ) ;
exp -> V_64 = V_65 ;
if ( memcmp ( & V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
sizeof( V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 ) ) &&
( V_62 = F_16 ( V_66 ) ) &&
V_5 -> V_60 & V_61 ) {
V_45 = V_62 ( V_2 , V_5 , V_7 , V_8 , V_10 , V_30 ,
V_33 , exp ) ;
} else {
if ( F_17 ( exp ) == 0 ) {
F_6 ( L_10 ) ;
F_18 ( & exp -> V_53 ) ;
} else
V_45 = - 1 ;
}
F_15 ( exp ) ;
return V_45 ;
}
static int F_21 ( struct V_1 * V_2 ,
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
static int F_22 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 ,
T_4 * V_73 )
{
int V_45 ;
F_6 ( L_11 ) ;
if ( V_73 -> V_74 . V_75 . V_35 ==
V_76 )
{
V_45 = F_21 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
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
F_21 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
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
V_45 = F_20 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_73 -> V_89 . V_90 .
V_92 ) ;
if ( V_45 < 0 )
return - 1 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_4 * V_5 ,
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
V_45 = F_21 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
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
V_45 = F_20 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_93 -> V_89 . V_90 .
V_92 ) ;
if ( V_45 < 0 )
return - 1 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 ,
T_7 * V_105 )
{
switch ( V_105 -> V_35 ) {
case V_106 :
if ( V_105 -> V_107 . V_35 ==
V_108 ) {
return F_22 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_105 -> V_107 . V_109 ) ;
}
F_6 ( L_13 ,
V_105 -> V_107 . V_35 ) ;
break;
case V_110 :
if ( V_105 -> V_111 . V_35 ==
V_112 ) {
return F_23 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
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
static int F_25 ( struct V_1 * V_2 , unsigned int V_3 ,
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
F_26 ( & V_117 ) ;
while ( F_1 ( V_2 , V_3 , V_5 , V_7 ,
& V_8 , & V_9 , & V_10 ) ) {
F_6 ( L_17 , V_9 ) ;
F_18 ( & V_5 -> V_52 [ F_3 ( V_7 ) ] . V_53 ) ;
V_45 = F_27 ( V_8 , V_9 ,
& V_105 ) ;
if ( V_45 < 0 ) {
F_6 ( L_18 ,
V_45 == V_118 ?
L_19 : L_20 ) ;
break;
}
if ( F_24 ( V_2 , V_5 , V_7 , & V_8 , V_10 , & V_105 ) < 0 )
goto V_119;
}
F_28 ( & V_117 ) ;
return V_116 ;
V_119:
F_28 ( & V_117 ) ;
if ( F_29 () )
F_30 ( L_21 ) ;
return V_120 ;
}
int F_31 ( struct V_4 * V_5 , unsigned char * V_8 ,
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
static int F_32 ( struct V_1 * V_2 , struct V_4 * V_5 ,
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
if ( ! F_31 ( V_5 , * V_8 , V_30 , & V_32 , & V_33 ) ||
memcmp ( & V_32 , & V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 , sizeof( V_32 ) ) ||
V_33 == 0 )
return 0 ;
if ( ( exp = F_13 ( V_5 ) ) == NULL )
return - 1 ;
F_14 ( exp , V_56 , F_8 ( V_5 ) ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
V_63 , NULL , & V_33 ) ;
exp -> V_127 = & V_128 ;
if ( memcmp ( & V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
sizeof( V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 ) ) &&
( V_126 = F_16 ( V_129 ) ) &&
V_5 -> V_60 & V_61 ) {
V_45 = V_126 ( V_2 , V_5 , V_7 , V_8 , V_10 , V_30 ,
V_33 , exp ) ;
} else {
if ( F_17 ( exp ) == 0 ) {
F_6 ( L_22 ) ;
F_18 ( & exp -> V_53 ) ;
} else
V_45 = - 1 ;
}
F_15 ( exp ) ;
return V_45 ;
}
static int F_33 ( const union V_31 * V_54 ,
const union V_31 * V_57 ,
T_9 V_130 )
{
const struct V_131 * V_132 ;
int V_45 = 0 ;
V_132 = F_34 ( V_130 ) ;
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
F_35 ( & V_134 ) , false ) ) {
if ( ! V_132 -> V_140 ( & V_141 , (struct V_142 * * ) & V_138 ,
F_35 ( & V_135 ) , false ) ) {
if ( V_137 -> V_143 == V_138 -> V_143 &&
V_137 -> V_57 . V_144 == V_138 -> V_57 . V_144 )
V_45 = 1 ;
F_36 ( & V_138 -> V_57 ) ;
}
F_36 ( & V_137 -> V_57 ) ;
}
break;
}
#if F_37 ( V_145 ) || \
F_37 ( V_146 )
case V_43 : {
struct V_147 V_134 , V_135 ;
struct V_148 * V_137 , * V_138 ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
F_38 ( & V_134 . V_139 , & V_54 -> V_149 ) ;
memset ( & V_135 , 0 , sizeof( V_135 ) ) ;
F_38 ( & V_135 . V_139 , & V_57 -> V_149 ) ;
if ( ! V_132 -> V_140 ( & V_141 , (struct V_142 * * ) & V_137 ,
F_39 ( & V_134 ) , false ) ) {
if ( ! V_132 -> V_140 ( & V_141 , (struct V_142 * * ) & V_138 ,
F_39 ( & V_135 ) , false ) ) {
if ( ! memcmp ( & V_137 -> V_150 , & V_138 -> V_150 ,
sizeof( V_137 -> V_150 ) ) &&
V_137 -> V_57 . V_144 == V_138 -> V_57 . V_144 )
V_45 = 1 ;
F_36 ( & V_138 -> V_57 ) ;
}
F_36 ( & V_137 -> V_57 ) ;
}
break;
}
#endif
}
return V_45 ;
}
static int F_40 ( struct V_1 * V_2 ,
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
F_10 (nat_callforwarding_hook) V_151 ;
if ( ! F_31 ( V_5 , * V_8 , V_30 , & V_32 , & V_33 ) || V_33 == 0 )
return 0 ;
if ( V_152 &&
F_33 ( & V_32 , & V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 ,
F_8 ( V_5 ) ) ) {
F_6 ( L_23 ) ;
return 0 ;
}
if ( ( exp = F_13 ( V_5 ) ) == NULL )
return - 1 ;
F_14 ( exp , V_56 , F_8 ( V_5 ) ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 , & V_32 ,
V_63 , NULL , & V_33 ) ;
exp -> V_127 = V_153 ;
if ( memcmp ( & V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
sizeof( V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 ) ) &&
( V_151 = F_16 ( V_154 ) ) &&
V_5 -> V_60 & V_61 ) {
V_45 = V_151 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
V_30 , V_33 , exp ) ;
} else {
if ( F_17 ( exp ) == 0 ) {
F_6 ( L_24 ) ;
F_18 ( & exp -> V_53 ) ;
} else
V_45 = - 1 ;
}
F_15 ( exp ) ;
return V_45 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 ,
T_10 * V_155 )
{
int V_15 = F_3 ( V_7 ) ;
int V_45 ;
int V_156 ;
T_2 V_33 ;
union V_31 V_32 ;
F_10 (set_h225_addr_hook) V_157 ;
F_6 ( L_25 ) ;
if ( V_155 -> V_68 & V_158 ) {
V_45 = F_32 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_155 -> V_159 ) ;
if ( V_45 < 0 )
return - 1 ;
}
V_157 = F_16 ( V_160 ) ;
if ( ( V_155 -> V_68 & V_161 ) &&
( V_157 ) && V_5 -> V_60 & V_61 &&
F_31 ( V_5 , * V_8 , & V_155 -> V_162 ,
& V_32 , & V_33 ) &&
memcmp ( & V_32 , & V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 , sizeof( V_32 ) ) ) {
F_6 ( L_26 ,
& V_32 , F_12 ( V_33 ) , & V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 ,
F_12 ( V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_163 . V_164 . V_33 ) ) ;
V_45 = V_157 ( V_2 , V_8 , V_10 ,
& V_155 -> V_162 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 ,
V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_163 . V_164 . V_33 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( ( V_155 -> V_68 & V_165 ) &&
( V_157 ) && V_5 -> V_60 & V_61 &&
F_31 ( V_5 , * V_8 , & V_155 -> V_166 ,
& V_32 , & V_33 ) &&
memcmp ( & V_32 , & V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 , sizeof( V_32 ) ) ) {
F_6 ( L_27 ,
& V_32 , F_12 ( V_33 ) , & V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
F_12 ( V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_163 . V_164 . V_33 ) ) ;
V_45 = V_157 ( V_2 , V_8 , V_10 ,
& V_155 -> V_166 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_163 . V_164 . V_33 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( V_155 -> V_68 & V_167 ) {
for ( V_156 = 0 ; V_156 < V_155 -> V_168 . V_169 ; V_156 ++ ) {
V_45 = F_22 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_155 -> V_168 . V_170 [ V_156 ] ) ;
if ( V_45 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 ,
T_11 * V_171 )
{
int V_45 ;
int V_156 ;
F_6 ( L_28 ) ;
if ( V_171 -> V_68 & V_172 ) {
V_45 = F_32 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_171 -> V_159 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( V_171 -> V_68 & V_173 ) {
for ( V_156 = 0 ; V_156 < V_171 -> V_168 . V_169 ; V_156 ++ ) {
V_45 = F_22 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_171 -> V_168 . V_170 [ V_156 ] ) ;
if ( V_45 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 ,
T_12 * V_174 )
{
int V_45 ;
int V_156 ;
F_6 ( L_29 ) ;
if ( V_174 -> V_68 & V_175 ) {
V_45 = F_32 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_174 -> V_159 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( V_174 -> V_68 & V_176 ) {
for ( V_156 = 0 ; V_156 < V_174 -> V_168 . V_169 ; V_156 ++ ) {
V_45 = F_22 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_174 -> V_168 . V_170 [ V_156 ] ) ;
if ( V_45 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 ,
T_13 * V_177 )
{
int V_45 ;
int V_156 ;
F_6 ( L_30 ) ;
if ( V_177 -> V_68 & V_178 ) {
V_45 = F_32 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_177 -> V_159 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( V_177 -> V_68 & V_179 ) {
for ( V_156 = 0 ; V_156 < V_177 -> V_168 . V_169 ; V_156 ++ ) {
V_45 = F_22 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_177 -> V_168 . V_170 [ V_156 ] ) ;
if ( V_45 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 ,
T_14 * V_180 )
{
int V_45 ;
int V_156 ;
F_6 ( L_31 ) ;
if ( V_180 -> V_181 . V_35 == V_182 ) {
if ( V_180 -> V_68 & V_183 )
return F_40 ( V_2 , V_5 , V_7 , V_8 ,
V_10 ,
& V_180 ->
V_184 ) ;
return 0 ;
}
if ( V_180 -> V_68 & V_185 ) {
V_45 = F_32 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_180 -> V_159 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( V_180 -> V_68 & V_186 ) {
for ( V_156 = 0 ; V_156 < V_180 -> V_168 . V_169 ; V_156 ++ ) {
V_45 = F_22 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_180 -> V_168 . V_170 [ V_156 ] ) ;
if ( V_45 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 ,
T_15 * V_187 )
{
int V_45 ;
int V_156 ;
F_6 ( L_32 ) ;
if ( V_187 -> V_68 & V_188 ) {
V_45 = F_32 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_187 -> V_159 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( V_187 -> V_68 & V_189 ) {
for ( V_156 = 0 ; V_156 < V_187 -> V_168 . V_169 ; V_156 ++ ) {
V_45 = F_22 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_187 -> V_168 . V_170 [ V_156 ] ) ;
if ( V_45 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , int V_10 , T_16 * V_190 )
{
T_17 * V_191 = & V_190 -> V_192 . V_193 ;
int V_156 ;
int V_45 = 0 ;
switch ( V_191 -> V_194 . V_35 ) {
case V_195 :
V_45 = F_41 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_191 -> V_194 . V_155 ) ;
break;
case V_196 :
V_45 = F_42 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_191 -> V_194 .
V_197 ) ;
break;
case V_198 :
V_45 = F_43 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_191 -> V_194 . V_174 ) ;
break;
case V_199 :
V_45 = F_44 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_191 -> V_194 . V_200 ) ;
break;
case V_201 :
V_45 = F_45 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_191 -> V_194 . V_180 ) ;
break;
case V_202 :
V_45 = F_46 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_191 -> V_194 . V_187 ) ;
break;
default:
F_6 ( L_33 ,
V_191 -> V_194 . V_35 ) ;
break;
}
if ( V_45 < 0 )
return - 1 ;
if ( V_191 -> V_68 & V_203 ) {
for ( V_156 = 0 ; V_156 < V_191 -> V_204 . V_169 ; V_156 ++ ) {
V_45 = F_24 ( V_2 , V_5 , V_7 , V_8 , V_10 ,
& V_191 -> V_204 . V_170 [ V_156 ] ) ;
if ( V_45 < 0 )
return - 1 ;
}
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 , enum V_6 V_7 )
{
static T_16 V_190 ;
unsigned char * V_8 = NULL ;
int V_9 ;
int V_10 ;
int V_45 ;
if ( V_7 != V_114 && V_7 != V_115 )
return V_116 ;
F_6 ( L_34 , V_2 -> V_25 ) ;
F_26 ( & V_117 ) ;
while ( F_1 ( V_2 , V_3 , V_5 , V_7 ,
& V_8 , & V_9 , & V_10 ) ) {
F_6 ( L_35 , V_9 ) ;
F_18 ( & V_5 -> V_52 [ F_3 ( V_7 ) ] . V_53 ) ;
V_45 = F_49 ( V_8 , V_9 , & V_190 ) ;
if ( V_45 < 0 ) {
F_6 ( L_36 ,
V_45 == V_118 ?
L_19 : L_20 ) ;
break;
}
if ( F_47 ( V_2 , V_5 , V_7 , & V_8 , V_10 , & V_190 ) < 0 )
goto V_119;
}
F_28 ( & V_117 ) ;
return V_116 ;
V_119:
F_28 ( & V_117 ) ;
if ( F_29 () )
F_30 ( L_37 ) ;
return V_120 ;
}
static unsigned char * F_50 ( struct V_1 * V_2 , unsigned int V_3 ,
int * V_9 )
{
const struct V_205 * V_206 ;
struct V_205 V_207 ;
int V_10 ;
V_206 = F_4 ( V_2 , V_3 , sizeof( V_207 ) , & V_207 ) ;
if ( V_206 == NULL )
return NULL ;
V_10 = V_3 + sizeof( V_207 ) ;
if ( V_10 >= V_2 -> V_25 )
return NULL ;
* V_9 = V_2 -> V_25 - V_10 ;
return F_4 ( V_2 , V_10 , * V_9 , V_27 ) ;
}
static struct V_48 * F_51 ( struct V_4 * V_5 ,
union V_31 * V_32 ,
T_2 V_33 )
{
struct V_208 * V_208 = F_52 ( V_5 ) ;
struct V_48 * exp ;
struct V_209 V_53 ;
memset ( & V_53 . V_54 . V_55 , 0 , sizeof( V_53 . V_54 . V_55 ) ) ;
V_53 . V_54 . V_163 . V_164 . V_33 = 0 ;
memcpy ( & V_53 . V_57 . V_55 , V_32 , sizeof( V_53 . V_57 . V_55 ) ) ;
V_53 . V_57 . V_163 . V_164 . V_33 = V_33 ;
V_53 . V_57 . V_210 = V_63 ;
exp = F_53 ( V_208 , F_54 ( V_5 ) , & V_53 ) ;
if ( exp && exp -> V_211 == V_5 )
return exp ;
return NULL ;
}
static int F_55 ( struct V_48 * exp ,
unsigned V_212 )
{
if ( ! exp || ! F_56 ( & exp -> V_212 ) )
return 0 ;
exp -> V_212 . V_213 = V_214 + V_212 * V_215 ;
F_57 ( & exp -> V_212 ) ;
return 1 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 ,
T_8 * V_30 , int V_169 )
{
struct V_11 * V_12 = & F_2 ( V_5 ) -> V_13 . V_14 ;
int V_15 = F_3 ( V_7 ) ;
int V_45 = 0 ;
int V_156 ;
T_2 V_33 ;
union V_31 V_32 ;
struct V_48 * exp ;
F_10 (nat_q931_hook) V_216 ;
for ( V_156 = 0 ; V_156 < V_169 ; V_156 ++ ) {
if ( F_31 ( V_5 , * V_8 , & V_30 [ V_156 ] , & V_32 , & V_33 ) &&
memcmp ( & V_32 , & V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 ,
sizeof( V_32 ) ) == 0 && V_33 != 0 )
break;
}
if ( V_156 >= V_169 )
return 0 ;
if ( ( exp = F_13 ( V_5 ) ) == NULL )
return - 1 ;
F_14 ( exp , V_56 , F_8 ( V_5 ) ,
V_217 ?
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 : NULL ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
V_63 , NULL , & V_33 ) ;
exp -> V_127 = V_153 ;
exp -> V_64 = V_65 ;
V_216 = F_16 ( V_218 ) ;
if ( V_216 && V_5 -> V_60 & V_61 ) {
V_45 = V_216 ( V_2 , V_5 , V_7 , V_8 , V_30 , V_156 , V_33 , exp ) ;
} else {
if ( F_17 ( exp ) == 0 ) {
F_6 ( L_38 ) ;
F_18 ( & exp -> V_53 ) ;
V_12 -> V_219 [ V_15 ] = V_33 ;
} else
V_45 = - 1 ;
}
F_15 ( exp ) ;
return V_45 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , T_18 * V_220 )
{
F_10 (set_ras_addr_hook) V_221 ;
F_6 ( L_39 ) ;
V_221 = F_16 ( V_222 ) ;
if ( V_221 && V_5 -> V_60 & V_61 )
return V_221 ( V_2 , V_5 , V_7 , V_8 ,
& V_220 -> V_223 , 1 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , T_19 * V_224 )
{
int V_15 = F_3 ( V_7 ) ;
int V_45 = 0 ;
T_2 V_33 ;
union V_31 V_32 ;
struct V_48 * exp ;
F_6 ( L_40 ) ;
if ( ! F_31 ( V_5 , * V_8 , & V_224 -> V_223 , & V_32 , & V_33 ) )
return 0 ;
if ( ! memcmp ( & V_32 , & V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 , sizeof( V_32 ) ) &&
V_33 == V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_163 . V_225 . V_33 )
return 0 ;
if ( F_61 ( V_226 , & V_5 -> V_60 ) )
return 0 ;
if ( ( exp = F_13 ( V_5 ) ) == NULL )
return - 1 ;
F_14 ( exp , V_56 , F_8 ( V_5 ) ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 , & V_32 ,
V_58 , NULL , & V_33 ) ;
exp -> V_127 = V_227 ;
if ( F_17 ( exp ) == 0 ) {
F_6 ( L_41 ) ;
F_18 ( & exp -> V_53 ) ;
} else
V_45 = - 1 ;
F_15 ( exp ) ;
return V_45 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , T_20 * V_228 )
{
struct V_11 * V_12 = & F_2 ( V_5 ) -> V_13 . V_14 ;
int V_45 ;
F_10 (set_ras_addr_hook) V_221 ;
F_6 ( L_42 ) ;
V_45 = F_58 ( V_2 , V_5 , V_7 , V_8 ,
V_228 -> V_229 . V_170 ,
V_228 -> V_229 . V_169 ) ;
if ( V_45 < 0 )
return - 1 ;
V_221 = F_16 ( V_222 ) ;
if ( V_221 && V_5 -> V_60 & V_61 ) {
V_45 = V_221 ( V_2 , V_5 , V_7 , V_8 ,
V_228 -> V_223 . V_170 ,
V_228 -> V_223 . V_169 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( V_228 -> V_68 & V_230 ) {
F_6 ( L_43 , V_228 -> V_231 ) ;
V_12 -> V_212 = V_228 -> V_231 ;
} else
V_12 -> V_212 = V_232 ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , T_21 * V_233 )
{
struct V_11 * V_12 = & F_2 ( V_5 ) -> V_13 . V_14 ;
int V_15 = F_3 ( V_7 ) ;
int V_45 ;
struct V_48 * exp ;
F_10 (set_sig_addr_hook) V_234 ;
F_6 ( L_44 ) ;
V_234 = F_16 ( V_235 ) ;
if ( V_234 && V_5 -> V_60 & V_61 ) {
V_45 = V_234 ( V_2 , V_5 , V_7 , V_8 ,
V_233 -> V_229 . V_170 ,
V_233 -> V_229 . V_169 ) ;
if ( V_45 < 0 )
return - 1 ;
}
if ( V_233 -> V_68 & V_236 ) {
F_6 ( L_45 , V_233 -> V_231 ) ;
V_12 -> V_212 = V_233 -> V_231 ;
}
if ( V_12 -> V_212 > 0 ) {
F_6 ( L_46
L_47 , V_12 -> V_212 ) ;
F_64 ( V_5 , V_2 , V_12 -> V_212 * V_215 ) ;
F_26 ( & V_237 ) ;
exp = F_51 ( V_5 , & V_5 -> V_52 [ V_15 ] . V_53 . V_57 . V_55 ,
V_12 -> V_219 [ ! V_15 ] ) ;
if ( exp ) {
F_6 ( L_48
L_49 ,
V_12 -> V_212 ) ;
F_18 ( & exp -> V_53 ) ;
F_55 ( exp , V_12 -> V_212 ) ;
}
F_28 ( & V_237 ) ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , T_22 * V_238 )
{
struct V_11 * V_12 = & F_2 ( V_5 ) -> V_13 . V_14 ;
int V_15 = F_3 ( V_7 ) ;
int V_45 ;
F_10 (set_sig_addr_hook) V_234 ;
F_6 ( L_50 ) ;
V_234 = F_16 ( V_235 ) ;
if ( V_234 && V_5 -> V_60 & V_61 ) {
V_45 = V_234 ( V_2 , V_5 , V_7 , V_8 ,
V_238 -> V_229 . V_170 ,
V_238 -> V_229 . V_169 ) ;
if ( V_45 < 0 )
return - 1 ;
}
F_66 ( V_5 ) ;
V_12 -> V_219 [ V_15 ] = 0 ;
V_12 -> V_219 [ ! V_15 ] = 0 ;
F_64 ( V_5 , V_2 , 30 * V_215 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , T_23 * V_239 )
{
const struct V_11 * V_12 = & F_2 ( V_5 ) -> V_13 . V_14 ;
int V_15 = F_3 ( V_7 ) ;
T_2 V_33 ;
union V_31 V_32 ;
F_10 (set_h225_addr_hook) V_157 ;
F_6 ( L_51 ) ;
V_157 = F_16 ( V_160 ) ;
if ( ( V_239 -> V_68 & V_240 ) &&
F_31 ( V_5 , * V_8 , & V_239 -> V_162 ,
& V_32 , & V_33 ) &&
! memcmp ( & V_32 , & V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 , sizeof( V_32 ) ) &&
V_33 == V_12 -> V_219 [ V_15 ] &&
V_157 && V_5 -> V_60 & V_61 ) {
return V_157 ( V_2 , V_8 , 0 ,
& V_239 -> V_162 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
V_12 -> V_219 [ ! V_15 ] ) ;
}
if ( ( V_239 -> V_68 & V_241 ) &&
F_31 ( V_5 , * V_8 , & V_239 -> V_242 ,
& V_32 , & V_33 ) &&
! memcmp ( & V_32 , & V_5 -> V_52 [ V_15 ] . V_53 . V_54 . V_55 , sizeof( V_32 ) ) &&
V_157 && V_5 -> V_60 & V_61 ) {
return V_157 ( V_2 , V_8 , 0 ,
& V_239 -> V_242 ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_57 . V_55 ,
V_33 ) ;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , T_24 * V_243 )
{
int V_15 = F_3 ( V_7 ) ;
int V_45 = 0 ;
T_2 V_33 ;
union V_31 V_32 ;
struct V_48 * exp ;
F_10 (set_sig_addr_hook) V_234 ;
F_6 ( L_52 ) ;
if ( ! F_31 ( V_5 , * V_8 , & V_243 -> V_162 ,
& V_32 , & V_33 ) )
return 0 ;
if ( ! memcmp ( & V_32 , & V_5 -> V_52 [ V_15 ] . V_53 . V_57 . V_55 , sizeof( V_32 ) ) ) {
V_234 = F_16 ( V_235 ) ;
if ( V_234 && V_5 -> V_60 & V_61 )
return V_234 ( V_2 , V_5 , V_7 , V_8 ,
& V_243 -> V_162 , 1 ) ;
return 0 ;
}
if ( ( exp = F_13 ( V_5 ) ) == NULL )
return - 1 ;
F_14 ( exp , V_56 , F_8 ( V_5 ) ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 , & V_32 ,
V_63 , NULL , & V_33 ) ;
exp -> V_64 = V_65 ;
exp -> V_127 = V_153 ;
if ( F_17 ( exp ) == 0 ) {
F_6 ( L_38 ) ;
F_18 ( & exp -> V_53 ) ;
} else
V_45 = - 1 ;
F_15 ( exp ) ;
return V_45 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , T_25 * V_244 )
{
F_10 (set_ras_addr_hook) V_221 ;
F_6 ( L_53 ) ;
V_221 = F_16 ( V_222 ) ;
if ( V_221 && V_5 -> V_60 & V_61 )
return V_221 ( V_2 , V_5 , V_7 , V_8 ,
& V_244 -> V_245 , 1 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , T_26 * V_246 )
{
int V_15 = F_3 ( V_7 ) ;
int V_45 = 0 ;
T_2 V_33 ;
union V_31 V_32 ;
struct V_48 * exp ;
F_6 ( L_54 ) ;
if ( ! F_31 ( V_5 , * V_8 , & V_246 -> V_229 ,
& V_32 , & V_33 ) )
return 0 ;
if ( ( exp = F_13 ( V_5 ) ) == NULL )
return - 1 ;
F_14 ( exp , V_56 , F_8 ( V_5 ) ,
& V_5 -> V_52 [ ! V_15 ] . V_53 . V_54 . V_55 , & V_32 ,
V_63 , NULL , & V_33 ) ;
exp -> V_64 = V_65 ;
exp -> V_127 = V_153 ;
if ( F_17 ( exp ) == 0 ) {
F_6 ( L_38 ) ;
F_18 ( & exp -> V_53 ) ;
} else
V_45 = - 1 ;
F_15 ( exp ) ;
return V_45 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , T_27 * V_247 )
{
int V_45 ;
F_10 (set_ras_addr_hook) V_221 ;
F_10 (set_sig_addr_hook) V_234 ;
F_6 ( L_55 ) ;
V_221 = F_16 ( V_222 ) ;
if ( V_221 && V_5 -> V_60 & V_61 ) {
V_45 = V_221 ( V_2 , V_5 , V_7 , V_8 ,
& V_247 -> V_223 , 1 ) ;
if ( V_45 < 0 )
return - 1 ;
}
V_234 = F_16 ( V_235 ) ;
if ( V_234 && V_5 -> V_60 & V_61 ) {
V_45 = V_234 ( V_2 , V_5 , V_7 , V_8 ,
V_247 -> V_229 . V_170 ,
V_247 -> V_229 . V_169 ) ;
if ( V_45 < 0 )
return - 1 ;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_6 V_7 ,
unsigned char * * V_8 , T_28 * V_248 )
{
switch ( V_248 -> V_35 ) {
case V_249 :
return F_59 ( V_2 , V_5 , V_7 , V_8 ,
& V_248 -> V_250 ) ;
case V_251 :
return F_60 ( V_2 , V_5 , V_7 , V_8 ,
& V_248 -> V_252 ) ;
case V_253 :
return F_62 ( V_2 , V_5 , V_7 , V_8 ,
& V_248 -> V_254 ) ;
case V_255 :
return F_63 ( V_2 , V_5 , V_7 , V_8 ,
& V_248 -> V_256 ) ;
case V_257 :
return F_65 ( V_2 , V_5 , V_7 , V_8 ,
& V_248 -> V_258 ) ;
case V_259 :
return F_67 ( V_2 , V_5 , V_7 , V_8 ,
& V_248 -> V_260 ) ;
case V_261 :
return F_68 ( V_2 , V_5 , V_7 , V_8 ,
& V_248 -> V_262 ) ;
case V_263 :
return F_69 ( V_2 , V_5 , V_7 , V_8 ,
& V_248 -> V_264 ) ;
case V_265 :
return F_70 ( V_2 , V_5 , V_7 , V_8 ,
& V_248 -> V_266 ) ;
case V_267 :
return F_71 ( V_2 , V_5 , V_7 , V_8 ,
& V_248 -> V_268 ) ;
default:
F_6 ( L_56 , V_248 -> V_35 ) ;
break;
}
return 0 ;
}
static int F_73 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 , enum V_6 V_7 )
{
static T_28 V_248 ;
unsigned char * V_8 ;
int V_9 = 0 ;
int V_45 ;
F_6 ( L_57 , V_2 -> V_25 ) ;
F_26 ( & V_117 ) ;
V_8 = F_50 ( V_2 , V_3 , & V_9 ) ;
if ( V_8 == NULL )
goto V_269;
F_6 ( L_58 , V_9 ) ;
F_18 ( & V_5 -> V_52 [ F_3 ( V_7 ) ] . V_53 ) ;
V_45 = F_74 ( V_8 , V_9 , & V_248 ) ;
if ( V_45 < 0 ) {
F_6 ( L_59 ,
V_45 == V_118 ?
L_19 : L_20 ) ;
goto V_269;
}
if ( F_72 ( V_2 , V_5 , V_7 , & V_8 , & V_248 ) < 0 )
goto V_119;
V_269:
F_28 ( & V_117 ) ;
return V_116 ;
V_119:
F_28 ( & V_117 ) ;
if ( F_29 () )
F_30 ( L_60 ) ;
return V_120 ;
}
static void T_29 F_75 ( void )
{
F_76 ( & V_227 [ 1 ] ) ;
F_76 ( & V_227 [ 0 ] ) ;
F_76 ( & V_153 [ 1 ] ) ;
F_76 ( & V_153 [ 0 ] ) ;
F_76 ( & V_128 ) ;
F_77 ( V_27 ) ;
F_6 ( L_61 ) ;
}
static int T_30 F_78 ( void )
{
int V_45 ;
V_27 = F_79 ( 65536 , V_270 ) ;
if ( ! V_27 )
return - V_271 ;
V_45 = F_80 ( & V_128 ) ;
if ( V_45 < 0 )
goto V_272;
V_45 = F_80 ( & V_153 [ 0 ] ) ;
if ( V_45 < 0 )
goto V_273;
V_45 = F_80 ( & V_153 [ 1 ] ) ;
if ( V_45 < 0 )
goto V_274;
V_45 = F_80 ( & V_227 [ 0 ] ) ;
if ( V_45 < 0 )
goto V_275;
V_45 = F_80 ( & V_227 [ 1 ] ) ;
if ( V_45 < 0 )
goto V_276;
F_6 ( L_62 ) ;
return 0 ;
V_276:
F_76 ( & V_227 [ 0 ] ) ;
V_275:
F_76 ( & V_153 [ 1 ] ) ;
V_274:
F_76 ( & V_153 [ 0 ] ) ;
V_273:
F_76 ( & V_128 ) ;
V_272:
F_77 ( V_27 ) ;
return V_45 ;
}
