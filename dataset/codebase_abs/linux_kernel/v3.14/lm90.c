static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 , V_2 -> V_5 ,
V_2 -> V_6 & ~ V_7 ,
V_8 , V_3 , V_9 , NULL ) ;
}
static int F_3 ( struct V_1 * V_2 , T_2 V_10 , T_2 * V_3 )
{
int V_11 ;
if ( V_2 -> V_6 & V_7 ) {
V_11 = F_1 ( V_2 , V_10 ) ;
if ( V_11 >= 0 )
V_11 = F_4 ( V_2 ) ;
} else
V_11 = F_5 ( V_2 , V_10 ) ;
if ( V_11 < 0 ) {
F_6 ( & V_2 -> V_12 , L_1 ,
V_10 , V_11 ) ;
return V_11 ;
}
* V_3 = V_11 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_2 V_13 , T_2 V_14 , T_3 * V_3 )
{
int V_11 ;
T_2 V_15 , V_16 , V_17 ;
if ( ( V_11 = F_3 ( V_2 , V_13 , & V_15 ) )
|| ( V_11 = F_3 ( V_2 , V_14 , & V_17 ) )
|| ( V_11 = F_3 ( V_2 , V_13 , & V_16 ) ) )
return V_11 ;
if ( V_15 != V_16 ) {
V_11 = F_3 ( V_2 , V_14 , & V_17 ) ;
if ( V_11 )
return V_11 ;
}
* V_3 = ( V_16 << 8 ) | V_17 ;
return 0 ;
}
static inline void F_8 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
int V_20 )
{
T_2 V_21 ;
if ( V_19 -> V_22 == V_23 ) {
F_3 ( V_2 , V_24 , & V_21 ) ;
V_21 &= ~ 0x08 ;
if ( V_20 )
V_21 |= 0x08 ;
F_9 ( V_2 , V_25 ,
V_21 ) ;
}
}
static void F_10 ( struct V_1 * V_2 , struct V_18 * V_19 ,
unsigned int V_26 )
{
int V_27 ;
unsigned int V_28 ;
V_26 <<= 6 ;
for ( V_27 = 0 , V_28 = V_29 << 6 ;
V_27 < V_19 -> V_30 ; V_27 ++ , V_28 >>= 1 )
if ( V_26 >= V_28 * 3 / 4 )
break;
F_9 ( V_2 , V_31 , V_27 ) ;
V_19 -> V_28 = F_11 ( V_28 , 64 ) ;
}
static struct V_18 * F_12 ( struct V_32 * V_12 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
struct V_18 * V_19 = F_14 ( V_2 ) ;
unsigned long V_33 ;
F_15 ( & V_19 -> V_34 ) ;
V_33 = V_19 -> V_35 +
F_16 ( V_19 -> V_28 ) ;
if ( F_17 ( V_36 , V_33 ) || ! V_19 -> V_37 ) {
T_2 V_38 , V_17 ;
T_2 V_39 ;
F_18 ( & V_2 -> V_12 , L_2 ) ;
F_3 ( V_2 , V_40 ,
& V_19 -> V_41 [ V_42 ] ) ;
F_3 ( V_2 , V_43 ,
& V_19 -> V_41 [ V_44 ] ) ;
F_3 ( V_2 , V_45 ,
& V_19 -> V_41 [ V_46 ] ) ;
F_3 ( V_2 , V_47 ,
& V_19 -> V_41 [ V_48 ] ) ;
F_3 ( V_2 , V_49 , & V_19 -> V_50 ) ;
if ( V_19 -> V_51 ) {
F_7 ( V_2 , V_52 ,
V_19 -> V_51 ,
& V_19 -> V_53 [ V_54 ] ) ;
} else {
if ( F_3 ( V_2 , V_52 ,
& V_38 ) == 0 )
V_19 -> V_53 [ V_54 ] = V_38 << 8 ;
}
F_7 ( V_2 , V_55 ,
V_56 ,
& V_19 -> V_53 [ V_57 ] ) ;
if ( F_3 ( V_2 , V_58 , & V_38 ) == 0 ) {
V_19 -> V_53 [ V_59 ] = V_38 << 8 ;
if ( ( V_19 -> V_6 & V_60 )
&& F_3 ( V_2 , V_61 ,
& V_17 ) == 0 )
V_19 -> V_53 [ V_59 ] |= V_17 ;
}
if ( F_3 ( V_2 , V_62 , & V_38 ) == 0 ) {
V_19 -> V_53 [ V_63 ] = V_38 << 8 ;
if ( ( V_19 -> V_6 & V_60 )
&& F_3 ( V_2 , V_64 ,
& V_17 ) == 0 )
V_19 -> V_53 [ V_63 ] |= V_17 ;
}
if ( V_19 -> V_6 & V_65 ) {
if ( F_3 ( V_2 , V_66 ,
& V_38 ) == 0
&& F_3 ( V_2 , V_67 ,
& V_17 ) == 0 )
V_19 -> V_53 [ V_68 ] = ( V_38 << 8 ) | V_17 ;
}
if ( V_19 -> V_6 & V_69 ) {
F_3 ( V_2 , V_70 ,
& V_19 -> V_41 [ V_71 ] ) ;
F_3 ( V_2 , V_72 ,
& V_19 -> V_41 [ V_73 ] ) ;
}
F_3 ( V_2 , V_74 , & V_39 ) ;
V_19 -> V_39 = V_39 ;
if ( V_19 -> V_22 == V_23 ) {
F_8 ( V_2 , V_19 , 1 ) ;
F_3 ( V_2 , V_47 ,
& V_19 -> V_41 [ V_75 ] ) ;
F_3 ( V_2 , V_72 ,
& V_19 -> V_41 [ V_76 ] ) ;
F_7 ( V_2 , V_55 ,
V_56 ,
& V_19 -> V_53 [ V_77 ] ) ;
if ( ! F_3 ( V_2 , V_58 , & V_38 ) )
V_19 -> V_53 [ V_78 ] = V_38 << 8 ;
if ( ! F_3 ( V_2 , V_62 , & V_38 ) )
V_19 -> V_53 [ V_79 ] = V_38 << 8 ;
F_8 ( V_2 , V_19 , 0 ) ;
if ( ! F_3 ( V_2 , V_80 ,
& V_39 ) )
V_19 -> V_39 |= V_39 << 8 ;
}
if ( ( V_19 -> V_81 & 0x80 ) == 0
&& ( V_19 -> V_39 & V_19 -> V_82 ) == 0 ) {
T_2 V_21 ;
F_3 ( V_2 , V_24 , & V_21 ) ;
if ( V_21 & 0x80 ) {
F_18 ( & V_2 -> V_12 , L_3 ) ;
F_9 ( V_2 ,
V_25 ,
V_21 & ~ 0x80 ) ;
}
}
V_19 -> V_35 = V_36 ;
V_19 -> V_37 = 1 ;
}
F_19 ( & V_19 -> V_34 ) ;
return V_19 ;
}
static inline int F_20 ( T_4 V_83 )
{
return V_83 * 1000 ;
}
static inline int F_21 ( T_2 V_83 )
{
return V_83 * 1000 ;
}
static inline int F_22 ( T_5 V_83 )
{
return V_83 / 32 * 125 ;
}
static inline int F_23 ( T_3 V_83 )
{
return V_83 / 32 * 125 ;
}
static T_4 F_24 ( long V_83 )
{
if ( V_83 <= - 128000 )
return - 128 ;
if ( V_83 >= 127000 )
return 127 ;
if ( V_83 < 0 )
return ( V_83 - 500 ) / 1000 ;
return ( V_83 + 500 ) / 1000 ;
}
static T_2 F_25 ( long V_83 )
{
if ( V_83 <= 0 )
return 0 ;
if ( V_83 >= 255000 )
return 255 ;
return ( V_83 + 500 ) / 1000 ;
}
static T_5 F_26 ( long V_83 )
{
if ( V_83 <= - 128000 )
return 0x8000 ;
if ( V_83 >= 127875 )
return 0x7FE0 ;
if ( V_83 < 0 )
return ( V_83 - 62 ) / 125 * 32 ;
return ( V_83 + 62 ) / 125 * 32 ;
}
static T_2 F_27 ( long V_83 )
{
if ( V_83 <= 0 )
return 0 ;
if ( V_83 >= 30500 )
return 31 ;
return ( V_83 + 500 ) / 1000 ;
}
static inline int F_28 ( struct V_18 * V_19 , T_2 V_83 )
{
if ( V_19 -> V_6 & V_84 )
return ( V_83 - 64 ) * 1000 ;
else
return F_20 ( V_83 ) ;
}
static inline int F_29 ( struct V_18 * V_19 , T_3 V_83 )
{
if ( V_19 -> V_6 & V_84 )
return ( V_83 - 0x4000 ) / 64 * 250 ;
else
return F_22 ( V_83 ) ;
}
static T_2 F_30 ( struct V_18 * V_19 , long V_83 )
{
if ( V_19 -> V_6 & V_84 ) {
if ( V_83 <= - 64000 )
return 0 ;
if ( V_83 >= 191000 )
return 0xFF ;
return ( V_83 + 500 + 64000 ) / 1000 ;
} else {
if ( V_83 <= 0 )
return 0 ;
if ( V_83 >= 127000 )
return 127 ;
return ( V_83 + 500 ) / 1000 ;
}
}
static T_3 F_31 ( struct V_18 * V_19 , long V_83 )
{
if ( V_19 -> V_6 & V_84 ) {
if ( V_83 <= - 64000 )
return 0 ;
if ( V_83 >= 191750 )
return 0xFFC0 ;
return ( V_83 + 64000 + 125 ) / 250 * 64 ;
} else {
if ( V_83 <= 0 )
return 0 ;
if ( V_83 >= 127750 )
return 0x7FC0 ;
return ( V_83 + 125 ) / 250 * 64 ;
}
}
static T_6 F_32 ( struct V_32 * V_12 , struct V_85 * V_86 ,
char * V_87 )
{
struct V_88 * V_89 = F_33 ( V_86 ) ;
struct V_18 * V_19 = F_12 ( V_12 ) ;
int V_90 ;
if ( V_19 -> V_22 == V_91 || V_19 -> V_22 == V_92 )
V_90 = F_28 ( V_19 , V_19 -> V_41 [ V_89 -> V_93 ] ) ;
else if ( V_19 -> V_22 == V_94 )
V_90 = F_21 ( V_19 -> V_41 [ V_89 -> V_93 ] ) ;
else
V_90 = F_20 ( V_19 -> V_41 [ V_89 -> V_93 ] ) ;
if ( V_19 -> V_22 == V_95 && V_89 -> V_93 == 3 )
V_90 += 16000 ;
return sprintf ( V_87 , L_4 , V_90 ) ;
}
static T_6 F_34 ( struct V_32 * V_12 , struct V_85 * V_86 ,
const char * V_87 , T_7 V_96 )
{
static const T_2 V_10 [ V_97 ] = {
V_98 ,
V_99 ,
V_100 ,
V_101 ,
V_102 ,
V_103 ,
V_101 ,
V_103 ,
} ;
struct V_88 * V_89 = F_33 ( V_86 ) ;
struct V_1 * V_2 = F_13 ( V_12 ) ;
struct V_18 * V_19 = F_14 ( V_2 ) ;
int V_104 = V_89 -> V_93 ;
long V_83 ;
int V_11 ;
V_11 = F_35 ( V_87 , 10 , & V_83 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_19 -> V_22 == V_95 && V_89 -> V_93 == 3 )
V_83 -= 16000 ;
F_15 ( & V_19 -> V_34 ) ;
if ( V_19 -> V_22 == V_91 || V_19 -> V_22 == V_92 )
V_19 -> V_41 [ V_104 ] = F_30 ( V_19 , V_83 ) ;
else if ( V_19 -> V_22 == V_94 )
V_19 -> V_41 [ V_104 ] = F_25 ( V_83 ) ;
else
V_19 -> V_41 [ V_104 ] = F_24 ( V_83 ) ;
F_8 ( V_2 , V_19 , V_104 >= 6 ) ;
F_9 ( V_2 , V_10 [ V_104 ] , V_19 -> V_41 [ V_104 ] ) ;
F_8 ( V_2 , V_19 , 0 ) ;
F_19 ( & V_19 -> V_34 ) ;
return V_96 ;
}
static T_6 F_36 ( struct V_32 * V_12 , struct V_85 * V_86 ,
char * V_87 )
{
struct V_105 * V_89 = F_37 ( V_86 ) ;
struct V_18 * V_19 = F_12 ( V_12 ) ;
int V_90 ;
if ( V_19 -> V_22 == V_91 || V_19 -> V_22 == V_92 )
V_90 = F_29 ( V_19 , V_19 -> V_53 [ V_89 -> V_93 ] ) ;
else if ( V_19 -> V_22 == V_94 )
V_90 = F_23 ( V_19 -> V_53 [ V_89 -> V_93 ] ) ;
else
V_90 = F_22 ( V_19 -> V_53 [ V_89 -> V_93 ] ) ;
if ( V_19 -> V_22 == V_95 && V_89 -> V_93 <= 2 )
V_90 += 16000 ;
return sprintf ( V_87 , L_4 , V_90 ) ;
}
static T_6 F_38 ( struct V_32 * V_12 , struct V_85 * V_86 ,
const char * V_87 , T_7 V_96 )
{
struct {
T_2 V_106 ;
T_2 V_107 ;
int V_20 ;
} V_10 [ 5 ] = {
{ V_108 , V_109 , 0 } ,
{ V_110 , V_111 , 0 } ,
{ V_112 , V_113 , 0 } ,
{ V_108 , V_109 , 1 } ,
{ V_110 , V_111 , 1 }
} ;
struct V_105 * V_89 = F_37 ( V_86 ) ;
struct V_1 * V_2 = F_13 ( V_12 ) ;
struct V_18 * V_19 = F_14 ( V_2 ) ;
int V_104 = V_89 -> V_104 ;
int V_93 = V_89 -> V_93 ;
long V_83 ;
int V_11 ;
V_11 = F_35 ( V_87 , 10 , & V_83 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_19 -> V_22 == V_95 && V_93 <= 2 )
V_83 -= 16000 ;
F_15 ( & V_19 -> V_34 ) ;
if ( V_19 -> V_22 == V_91 || V_19 -> V_22 == V_92 )
V_19 -> V_53 [ V_93 ] = F_31 ( V_19 , V_83 ) ;
else if ( V_19 -> V_22 == V_94 )
V_19 -> V_53 [ V_93 ] = F_25 ( V_83 ) << 8 ;
else if ( V_19 -> V_6 & V_60 )
V_19 -> V_53 [ V_93 ] = F_26 ( V_83 ) ;
else
V_19 -> V_53 [ V_93 ] = F_24 ( V_83 ) << 8 ;
F_8 ( V_2 , V_19 , V_10 [ V_104 ] . V_20 ) ;
F_9 ( V_2 , V_10 [ V_104 ] . V_106 ,
V_19 -> V_53 [ V_93 ] >> 8 ) ;
if ( V_19 -> V_6 & V_60 )
F_9 ( V_2 , V_10 [ V_104 ] . V_107 ,
V_19 -> V_53 [ V_93 ] & 0xff ) ;
F_8 ( V_2 , V_19 , 0 ) ;
F_19 ( & V_19 -> V_34 ) ;
return V_96 ;
}
static T_6 F_39 ( struct V_32 * V_12 ,
struct V_85 * V_86 ,
char * V_87 )
{
struct V_88 * V_89 = F_33 ( V_86 ) ;
struct V_18 * V_19 = F_12 ( V_12 ) ;
int V_90 ;
if ( V_19 -> V_22 == V_91 || V_19 -> V_22 == V_92 )
V_90 = F_28 ( V_19 , V_19 -> V_41 [ V_89 -> V_93 ] ) ;
else if ( V_19 -> V_22 == V_94 )
V_90 = F_21 ( V_19 -> V_41 [ V_89 -> V_93 ] ) ;
else
V_90 = F_20 ( V_19 -> V_41 [ V_89 -> V_93 ] ) ;
if ( V_19 -> V_22 == V_95 && V_89 -> V_93 == 3 )
V_90 += 16000 ;
return sprintf ( V_87 , L_4 , V_90 - F_20 ( V_19 -> V_50 ) ) ;
}
static T_6 F_40 ( struct V_32 * V_12 , struct V_85 * V_114 ,
const char * V_87 , T_7 V_96 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
struct V_18 * V_19 = F_14 ( V_2 ) ;
long V_83 ;
int V_11 ;
int V_90 ;
V_11 = F_35 ( V_87 , 10 , & V_83 ) ;
if ( V_11 < 0 )
return V_11 ;
F_15 ( & V_19 -> V_34 ) ;
if ( V_19 -> V_22 == V_91 || V_19 -> V_22 == V_92 )
V_90 = F_28 ( V_19 , V_19 -> V_41 [ V_46 ] ) ;
else if ( V_19 -> V_22 == V_94 )
V_90 = F_21 ( V_19 -> V_41 [ V_46 ] ) ;
else
V_90 = F_20 ( V_19 -> V_41 [ V_46 ] ) ;
V_19 -> V_50 = F_27 ( V_90 - V_83 ) ;
F_9 ( V_2 , V_115 ,
V_19 -> V_50 ) ;
F_19 ( & V_19 -> V_34 ) ;
return V_96 ;
}
static T_6 F_41 ( struct V_32 * V_12 , struct V_85 * V_114 ,
char * V_87 )
{
struct V_18 * V_19 = F_12 ( V_12 ) ;
return sprintf ( V_87 , L_4 , V_19 -> V_39 ) ;
}
static T_6 F_42 ( struct V_32 * V_12 , struct V_85
* V_86 , char * V_87 )
{
struct V_88 * V_89 = F_33 ( V_86 ) ;
struct V_18 * V_19 = F_12 ( V_12 ) ;
int V_116 = V_89 -> V_93 ;
return sprintf ( V_87 , L_4 , ( V_19 -> V_39 >> V_116 ) & 1 ) ;
}
static T_6 F_43 ( struct V_32 * V_12 ,
struct V_85 * V_89 , char * V_87 )
{
struct V_18 * V_19 = F_44 ( V_12 ) ;
return sprintf ( V_87 , L_5 , V_19 -> V_28 ) ;
}
static T_6 F_45 ( struct V_32 * V_12 ,
struct V_85 * V_89 ,
const char * V_87 , T_7 V_96 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
struct V_18 * V_19 = F_14 ( V_2 ) ;
unsigned long V_83 ;
int V_11 ;
V_11 = F_46 ( V_87 , 10 , & V_83 ) ;
if ( V_11 )
return V_11 ;
F_15 ( & V_19 -> V_34 ) ;
F_10 ( V_2 , V_19 , F_47 ( V_83 , 0 , 100000 ) ) ;
F_19 ( & V_19 -> V_34 ) ;
return V_96 ;
}
static T_6 F_48 ( struct V_32 * V_12 , struct V_85 * V_114 ,
char * V_87 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
return sprintf ( V_87 , L_4 , ! ! ( V_2 -> V_6 & V_7 ) ) ;
}
static T_6 F_49 ( struct V_32 * V_12 , struct V_85 * V_114 ,
const char * V_87 , T_7 V_96 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
long V_83 ;
int V_11 ;
V_11 = F_35 ( V_87 , 10 , & V_83 ) ;
if ( V_11 < 0 )
return V_11 ;
switch ( V_83 ) {
case 0 :
V_2 -> V_6 &= ~ V_7 ;
break;
case 1 :
V_2 -> V_6 |= V_7 ;
break;
default:
return - V_117 ;
}
return V_96 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
struct V_120 * V_4 = V_2 -> V_4 ;
int V_121 = V_2 -> V_5 ;
const char * V_122 = NULL ;
int V_123 , V_124 , V_125 , V_126 , V_127 ;
if ( ! F_51 ( V_4 , V_128 ) )
return - V_129 ;
V_123 = F_5 ( V_2 , V_130 ) ;
V_124 = F_5 ( V_2 , V_131 ) ;
V_125 = F_5 ( V_2 , V_24 ) ;
V_127 = F_5 ( V_2 , V_132 ) ;
if ( V_123 < 0 || V_124 < 0 || V_125 < 0 || V_127 < 0 )
return - V_129 ;
if ( V_123 == 0x01 || V_123 == 0x5C || V_123 == 0x41 ) {
V_126 = F_5 ( V_2 , V_133 ) ;
if ( V_126 < 0 )
return - V_129 ;
} else
V_126 = 0 ;
if ( ( V_121 == 0x4C || V_121 == 0x4D )
&& V_123 == 0x01 ) {
if ( ( V_125 & 0x2A ) == 0x00
&& ( V_126 & 0xF8 ) == 0x00
&& V_127 <= 0x09 ) {
if ( V_121 == 0x4C
&& ( V_124 & 0xF0 ) == 0x20 ) {
V_122 = L_6 ;
} else
if ( ( V_124 & 0xF0 ) == 0x30 ) {
V_122 = L_7 ;
F_52 ( & V_4 -> V_12 ,
L_8 ,
V_121 ) ;
F_52 ( & V_4 -> V_12 ,
L_9
L_10
L_11 ) ;
} else
if ( V_121 == 0x4C
&& ( V_124 & 0xF0 ) == 0x10 ) {
V_122 = L_12 ;
}
}
} else
if ( ( V_121 == 0x4C || V_121 == 0x4D )
&& V_123 == 0x41 ) {
if ( ( V_124 & 0xF0 ) == 0x40
&& ( V_125 & 0x3F ) == 0x00
&& V_127 <= 0x0A ) {
V_122 = L_13 ;
if ( F_51 ( V_4 ,
V_134 ) )
V_119 -> V_6 |= V_7 ;
} else
if ( V_124 == 0x51
&& ( V_125 & 0x1B ) == 0x00
&& V_127 <= 0x0A ) {
V_122 = L_14 ;
} else
if ( V_124 == 0x57
&& ( V_125 & 0x1B ) == 0x00
&& V_127 <= 0x0A ) {
V_122 = L_15 ;
}
} else
if ( V_123 == 0x4D ) {
int V_135 , V_136 , V_137 ;
V_135 = F_5 ( V_2 ,
V_72 ) ;
V_123 = F_5 ( V_2 ,
V_130 ) ;
V_136 = F_5 ( V_2 ,
V_72 ) ;
V_137 = F_5 ( V_2 ,
V_80 ) ;
if ( V_135 < 0 || V_123 < 0 || V_136 < 0 || V_137 < 0 )
return - V_129 ;
if ( V_124 == V_123
&& ( V_121 == 0x4C || V_121 == 0x4D || V_121 == 0x4E )
&& ( V_125 & 0x1F ) == ( V_123 & 0x0F )
&& V_127 <= 0x09 ) {
if ( V_121 == 0x4C )
V_122 = L_16 ;
else
V_122 = L_17 ;
} else
if ( V_124 == 0x01
&& ( V_125 & 0x10 ) == 0x00
&& ( V_137 & 0x01 ) == 0x00
&& V_135 == V_136
&& V_127 <= 0x07 ) {
V_122 = L_18 ;
} else
if ( V_124 == 0x01
&& ( V_125 & 0x03 ) == 0x00
&& V_127 <= 0x07 ) {
V_122 = L_19 ;
} else
if ( V_124 == 0x59
&& ( V_125 & 0x3f ) == 0x00
&& V_127 <= 0x07 ) {
V_122 = L_20 ;
}
} else
if ( V_121 == 0x4C
&& V_123 == 0x5C ) {
if ( ( V_125 & 0x2A ) == 0x00
&& ( V_126 & 0xF8 ) == 0x00 ) {
if ( V_124 == 0x01
&& V_127 <= 0x09 ) {
V_122 = L_21 ;
} else
if ( ( V_124 & 0xFE ) == 0x10
&& V_127 <= 0x08 ) {
V_122 = L_21 ;
}
}
} else
if ( V_121 >= 0x48 && V_121 <= 0x4F
&& V_123 == 0xA1 ) {
if ( V_124 == 0x00
&& ( V_125 & 0x2A ) == 0x00
&& ( V_126 & 0xFE ) == 0x00
&& V_127 <= 0x09 ) {
V_122 = L_22 ;
}
} else
if ( ( V_121 == 0x4C || V_121 == 0x4D )
&& V_123 == 0x47 ) {
if ( V_124 == 0x01
&& ( V_125 & 0x3F ) == 0x00
&& V_127 <= 0x08 )
V_122 = L_23 ;
} else
if ( V_121 == 0x4C
&& V_123 == 0x55 ) {
int V_138 ;
V_138 = F_5 ( V_2 ,
V_139 ) ;
if ( V_124 == 0x00
&& ( V_125 & 0x1B ) == 0x00
&& V_127 <= 0x09
&& ( V_138 & 0x0F ) == 0x00 )
V_122 = L_24 ;
}
if ( ! V_122 ) {
F_18 ( & V_4 -> V_12 ,
L_25
L_26 , V_121 , V_123 , V_124 ) ;
return - V_129 ;
}
F_53 ( V_119 -> type , V_122 , V_140 ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_32 * V_12 = & V_2 -> V_12 ;
if ( V_19 -> V_6 & V_141 )
F_55 ( & V_12 -> V_142 , & V_143 ) ;
if ( V_19 -> V_6 & V_144 )
F_55 ( & V_12 -> V_142 , & V_145 ) ;
if ( V_19 -> V_6 & V_69 )
F_55 ( & V_12 -> V_142 , & V_146 ) ;
if ( V_19 -> V_6 & V_65 )
F_56 ( V_12 , & V_147 . V_148 ) ;
F_56 ( V_12 , & V_149 ) ;
F_55 ( & V_12 -> V_142 , & V_150 ) ;
}
static void F_57 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
F_9 ( V_2 , V_31 ,
V_19 -> V_151 ) ;
F_9 ( V_2 , V_25 ,
V_19 -> V_81 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
T_2 V_21 , V_127 ;
struct V_18 * V_19 = F_14 ( V_2 ) ;
if ( F_3 ( V_2 , V_132 , & V_127 ) < 0 ) {
F_6 ( & V_2 -> V_12 , L_27 ) ;
V_127 = V_152 ;
}
V_19 -> V_151 = V_127 ;
F_10 ( V_2 , V_19 , 500 ) ;
if ( F_3 ( V_2 , V_24 , & V_21 ) < 0 ) {
F_6 ( & V_2 -> V_12 , L_28 ) ;
return;
}
V_19 -> V_81 = V_21 ;
if ( V_19 -> V_22 == V_91 || V_19 -> V_22 == V_92 ) {
if ( V_21 & 0x04 )
V_19 -> V_6 |= V_84 ;
}
if ( V_19 -> V_22 == V_153 )
V_21 |= 0x18 ;
if ( V_19 -> V_22 == V_23 )
V_21 &= ~ 0x08 ;
V_21 &= 0xBF ;
if ( V_21 != V_19 -> V_81 )
F_9 ( V_2 , V_25 , V_21 ) ;
}
static bool F_59 ( struct V_1 * V_2 , T_3 * V_154 )
{
struct V_18 * V_19 = F_14 ( V_2 ) ;
T_2 V_155 , V_156 = 0 ;
F_3 ( V_2 , V_74 , & V_155 ) ;
if ( V_19 -> V_22 == V_23 )
F_3 ( V_2 , V_80 , & V_156 ) ;
* V_154 = V_155 | ( V_156 << 8 ) ;
if ( ( V_155 & 0x7f ) == 0 && ( V_156 & 0xfe ) == 0 )
return false ;
if ( ( V_155 & ( V_157 | V_158 | V_159 ) ) ||
( V_156 & V_160 ) )
F_6 ( & V_2 -> V_12 ,
L_29 , 1 ) ;
if ( ( V_155 & ( V_161 | V_162 | V_163 ) ) ||
( V_156 & V_164 ) )
F_6 ( & V_2 -> V_12 ,
L_29 , 2 ) ;
if ( V_155 & V_165 )
F_6 ( & V_2 -> V_12 ,
L_30 , 2 ) ;
if ( V_156 & ( V_166 | V_167 |
V_168 | V_169 ) )
F_6 ( & V_2 -> V_12 ,
L_29 , 3 ) ;
if ( V_156 & V_170 )
F_6 ( & V_2 -> V_12 ,
L_30 , 3 ) ;
return true ;
}
static T_8 F_60 ( int V_171 , void * V_172 )
{
struct V_1 * V_2 = V_172 ;
T_3 V_154 ;
if ( F_59 ( V_2 , & V_154 ) )
return V_173 ;
else
return V_174 ;
}
static int F_61 ( struct V_1 * V_2 ,
const struct V_175 * V_176 )
{
struct V_32 * V_12 = & V_2 -> V_12 ;
struct V_120 * V_4 = F_62 ( V_12 -> V_177 ) ;
struct V_18 * V_19 ;
struct V_178 * V_178 ;
int V_11 ;
V_178 = F_63 ( V_12 , L_31 ) ;
if ( F_64 ( V_178 ) )
return F_65 ( V_178 ) ;
V_11 = F_66 ( V_178 ) ;
if ( V_11 < 0 ) {
F_67 ( & V_2 -> V_12 ,
L_32 , V_11 ) ;
return V_11 ;
}
V_19 = F_68 ( & V_2 -> V_12 , sizeof( struct V_18 ) , V_179 ) ;
if ( ! V_19 )
return - V_180 ;
F_69 ( V_2 , V_19 ) ;
F_70 ( & V_19 -> V_34 ) ;
V_19 -> V_178 = V_178 ;
V_19 -> V_22 = V_176 -> V_181 ;
if ( V_19 -> V_22 == V_182 ) {
if ( ! F_51 ( V_4 , V_134 ) )
V_2 -> V_6 &= ~ V_7 ;
}
V_19 -> V_82 = V_183 [ V_19 -> V_22 ] . V_82 ;
V_19 -> V_6 = V_183 [ V_19 -> V_22 ] . V_6 ;
V_19 -> V_51 = V_183 [ V_19 -> V_22 ] . V_51 ;
V_19 -> V_30 = V_183 [ V_19 -> V_22 ] . V_30 ;
F_58 ( V_2 ) ;
V_11 = F_71 ( & V_12 -> V_142 , & V_150 ) ;
if ( V_11 )
goto V_184;
if ( V_2 -> V_6 & V_7 ) {
V_11 = F_72 ( V_12 , & V_149 ) ;
if ( V_11 )
goto V_185;
}
if ( V_19 -> V_6 & V_65 ) {
V_11 = F_72 ( V_12 ,
& V_147 . V_148 ) ;
if ( V_11 )
goto V_185;
}
if ( V_19 -> V_6 & V_69 ) {
V_11 = F_71 ( & V_12 -> V_142 , & V_146 ) ;
if ( V_11 )
goto V_185;
}
if ( V_19 -> V_6 & V_144 ) {
V_11 = F_71 ( & V_12 -> V_142 ,
& V_145 ) ;
if ( V_11 )
goto V_185;
}
if ( V_19 -> V_6 & V_141 ) {
V_11 = F_71 ( & V_12 -> V_142 , & V_143 ) ;
if ( V_11 )
goto V_185;
}
V_19 -> V_186 = F_73 ( V_12 ) ;
if ( F_64 ( V_19 -> V_186 ) ) {
V_11 = F_65 ( V_19 -> V_186 ) ;
goto V_185;
}
if ( V_2 -> V_171 ) {
F_18 ( V_12 , L_33 , V_2 -> V_171 ) ;
V_11 = F_74 ( V_12 , V_2 -> V_171 ,
NULL , F_60 ,
V_187 | V_188 ,
L_6 , V_2 ) ;
if ( V_11 < 0 ) {
F_67 ( V_12 , L_34 , V_2 -> V_171 ) ;
goto V_189;
}
}
return 0 ;
V_189:
F_75 ( V_19 -> V_186 ) ;
V_185:
F_54 ( V_2 , V_19 ) ;
V_184:
F_57 ( V_2 , V_19 ) ;
F_76 ( V_19 -> V_178 ) ;
return V_11 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_14 ( V_2 ) ;
F_75 ( V_19 -> V_186 ) ;
F_54 ( V_2 , V_19 ) ;
F_57 ( V_2 , V_19 ) ;
F_76 ( V_19 -> V_178 ) ;
return 0 ;
}
static void F_78 ( struct V_1 * V_2 , unsigned int V_190 )
{
T_3 V_39 ;
if ( F_59 ( V_2 , & V_39 ) ) {
struct V_18 * V_19 = F_14 ( V_2 ) ;
if ( ( V_19 -> V_6 & V_191 )
&& ( V_39 & V_19 -> V_82 ) ) {
T_2 V_21 ;
F_18 ( & V_2 -> V_12 , L_35 ) ;
F_3 ( V_2 , V_24 , & V_21 ) ;
F_9 ( V_2 , V_25 ,
V_21 | 0x80 ) ;
}
} else {
F_52 ( & V_2 -> V_12 , L_36 ) ;
}
}
