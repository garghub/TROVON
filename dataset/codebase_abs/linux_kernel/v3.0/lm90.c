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
V_33 = V_19 -> V_35
+ F_16 ( V_19 -> V_28 ) + 1 ;
if ( F_17 ( V_36 , V_33 ) || ! V_19 -> V_37 ) {
T_2 V_38 , V_17 ;
T_2 V_39 ;
F_18 ( & V_2 -> V_12 , L_2 ) ;
F_3 ( V_2 , V_40 , & V_19 -> V_41 [ 0 ] ) ;
F_3 ( V_2 , V_42 , & V_19 -> V_41 [ 1 ] ) ;
F_3 ( V_2 , V_43 , & V_19 -> V_41 [ 2 ] ) ;
F_3 ( V_2 , V_44 , & V_19 -> V_41 [ 3 ] ) ;
F_3 ( V_2 , V_45 , & V_19 -> V_46 ) ;
if ( V_19 -> V_6 & V_47 ) {
F_7 ( V_2 , V_48 ,
V_49 ,
& V_19 -> V_50 [ 4 ] ) ;
} else {
if ( F_3 ( V_2 , V_48 ,
& V_38 ) == 0 )
V_19 -> V_50 [ 4 ] = V_38 << 8 ;
}
F_7 ( V_2 , V_51 ,
V_52 , & V_19 -> V_50 [ 0 ] ) ;
if ( F_3 ( V_2 , V_53 , & V_38 ) == 0 ) {
V_19 -> V_50 [ 1 ] = V_38 << 8 ;
if ( ( V_19 -> V_6 & V_54 )
&& F_3 ( V_2 , V_55 ,
& V_17 ) == 0 )
V_19 -> V_50 [ 1 ] |= V_17 ;
}
if ( F_3 ( V_2 , V_56 , & V_38 ) == 0 ) {
V_19 -> V_50 [ 2 ] = V_38 << 8 ;
if ( ( V_19 -> V_6 & V_54 )
&& F_3 ( V_2 , V_57 ,
& V_17 ) == 0 )
V_19 -> V_50 [ 2 ] |= V_17 ;
}
if ( V_19 -> V_6 & V_58 ) {
if ( F_3 ( V_2 , V_59 ,
& V_38 ) == 0
&& F_3 ( V_2 , V_60 ,
& V_17 ) == 0 )
V_19 -> V_50 [ 3 ] = ( V_38 << 8 ) | V_17 ;
}
if ( V_19 -> V_6 & V_61 ) {
F_3 ( V_2 , V_62 ,
& V_19 -> V_41 [ 4 ] ) ;
F_3 ( V_2 , V_63 ,
& V_19 -> V_41 [ 5 ] ) ;
}
F_3 ( V_2 , V_64 , & V_39 ) ;
V_19 -> V_39 = V_39 ;
if ( V_19 -> V_22 == V_23 ) {
F_8 ( V_2 , V_19 , 1 ) ;
F_3 ( V_2 , V_44 ,
& V_19 -> V_41 [ 6 ] ) ;
F_3 ( V_2 , V_63 ,
& V_19 -> V_41 [ 7 ] ) ;
F_7 ( V_2 , V_51 ,
V_52 , & V_19 -> V_50 [ 5 ] ) ;
if ( ! F_3 ( V_2 , V_53 , & V_38 ) )
V_19 -> V_50 [ 6 ] = V_38 << 8 ;
if ( ! F_3 ( V_2 , V_56 , & V_38 ) )
V_19 -> V_50 [ 7 ] = V_38 << 8 ;
F_8 ( V_2 , V_19 , 0 ) ;
if ( ! F_3 ( V_2 , V_65 ,
& V_39 ) )
V_19 -> V_39 |= V_39 << 8 ;
}
if ( ( V_19 -> V_66 & 0x80 ) == 0
&& ( V_19 -> V_39 & V_19 -> V_67 ) == 0 ) {
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
static inline int F_20 ( T_4 V_68 )
{
return V_68 * 1000 ;
}
static inline int F_21 ( T_2 V_68 )
{
return V_68 * 1000 ;
}
static inline int F_22 ( T_5 V_68 )
{
return V_68 / 32 * 125 ;
}
static inline int F_23 ( T_3 V_68 )
{
return V_68 / 32 * 125 ;
}
static T_4 F_24 ( long V_68 )
{
if ( V_68 <= - 128000 )
return - 128 ;
if ( V_68 >= 127000 )
return 127 ;
if ( V_68 < 0 )
return ( V_68 - 500 ) / 1000 ;
return ( V_68 + 500 ) / 1000 ;
}
static T_2 F_25 ( long V_68 )
{
if ( V_68 <= 0 )
return 0 ;
if ( V_68 >= 255000 )
return 255 ;
return ( V_68 + 500 ) / 1000 ;
}
static T_5 F_26 ( long V_68 )
{
if ( V_68 <= - 128000 )
return 0x8000 ;
if ( V_68 >= 127875 )
return 0x7FE0 ;
if ( V_68 < 0 )
return ( V_68 - 62 ) / 125 * 32 ;
return ( V_68 + 62 ) / 125 * 32 ;
}
static T_2 F_27 ( long V_68 )
{
if ( V_68 <= 0 )
return 0 ;
if ( V_68 >= 30500 )
return 31 ;
return ( V_68 + 500 ) / 1000 ;
}
static inline int F_28 ( struct V_18 * V_19 , T_2 V_68 )
{
if ( V_19 -> V_6 & V_69 )
return ( V_68 - 64 ) * 1000 ;
else
return F_20 ( V_68 ) ;
}
static inline int F_29 ( struct V_18 * V_19 , T_3 V_68 )
{
if ( V_19 -> V_6 & V_69 )
return ( V_68 - 0x4000 ) / 64 * 250 ;
else
return F_22 ( V_68 ) ;
}
static T_2 F_30 ( struct V_18 * V_19 , long V_68 )
{
if ( V_19 -> V_6 & V_69 ) {
if ( V_68 <= - 64000 )
return 0 ;
if ( V_68 >= 191000 )
return 0xFF ;
return ( V_68 + 500 + 64000 ) / 1000 ;
} else {
if ( V_68 <= 0 )
return 0 ;
if ( V_68 >= 127000 )
return 127 ;
return ( V_68 + 500 ) / 1000 ;
}
}
static T_3 F_31 ( struct V_18 * V_19 , long V_68 )
{
if ( V_19 -> V_6 & V_69 ) {
if ( V_68 <= - 64000 )
return 0 ;
if ( V_68 >= 191750 )
return 0xFFC0 ;
return ( V_68 + 64000 + 125 ) / 250 * 64 ;
} else {
if ( V_68 <= 0 )
return 0 ;
if ( V_68 >= 127750 )
return 0x7FC0 ;
return ( V_68 + 125 ) / 250 * 64 ;
}
}
static T_6 F_32 ( struct V_32 * V_12 , struct V_70 * V_71 ,
char * V_72 )
{
struct V_73 * V_74 = F_33 ( V_71 ) ;
struct V_18 * V_19 = F_12 ( V_12 ) ;
int V_75 ;
if ( V_19 -> V_22 == V_76 )
V_75 = F_28 ( V_19 , V_19 -> V_41 [ V_74 -> V_77 ] ) ;
else if ( V_19 -> V_22 == V_78 )
V_75 = F_21 ( V_19 -> V_41 [ V_74 -> V_77 ] ) ;
else
V_75 = F_20 ( V_19 -> V_41 [ V_74 -> V_77 ] ) ;
if ( V_19 -> V_22 == V_79 && V_74 -> V_77 == 3 )
V_75 += 16000 ;
return sprintf ( V_72 , L_4 , V_75 ) ;
}
static T_6 F_34 ( struct V_32 * V_12 , struct V_70 * V_71 ,
const char * V_72 , T_7 V_80 )
{
static const T_2 V_10 [ 8 ] = {
V_81 ,
V_82 ,
V_83 ,
V_84 ,
V_85 ,
V_86 ,
V_84 ,
V_86 ,
} ;
struct V_73 * V_74 = F_33 ( V_71 ) ;
struct V_1 * V_2 = F_13 ( V_12 ) ;
struct V_18 * V_19 = F_14 ( V_2 ) ;
int V_87 = V_74 -> V_77 ;
long V_68 ;
int V_11 ;
V_11 = F_35 ( V_72 , 10 , & V_68 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_19 -> V_22 == V_79 && V_74 -> V_77 == 3 )
V_68 -= 16000 ;
F_15 ( & V_19 -> V_34 ) ;
if ( V_19 -> V_22 == V_76 )
V_19 -> V_41 [ V_87 ] = F_30 ( V_19 , V_68 ) ;
else if ( V_19 -> V_22 == V_78 )
V_19 -> V_41 [ V_87 ] = F_25 ( V_68 ) ;
else
V_19 -> V_41 [ V_87 ] = F_24 ( V_68 ) ;
F_8 ( V_2 , V_19 , V_87 >= 6 ) ;
F_9 ( V_2 , V_10 [ V_87 ] , V_19 -> V_41 [ V_87 ] ) ;
F_8 ( V_2 , V_19 , 0 ) ;
F_19 ( & V_19 -> V_34 ) ;
return V_80 ;
}
static T_6 F_36 ( struct V_32 * V_12 , struct V_70 * V_71 ,
char * V_72 )
{
struct V_88 * V_74 = F_37 ( V_71 ) ;
struct V_18 * V_19 = F_12 ( V_12 ) ;
int V_75 ;
if ( V_19 -> V_22 == V_76 )
V_75 = F_29 ( V_19 , V_19 -> V_50 [ V_74 -> V_77 ] ) ;
else if ( V_19 -> V_22 == V_78 )
V_75 = F_23 ( V_19 -> V_50 [ V_74 -> V_77 ] ) ;
else
V_75 = F_22 ( V_19 -> V_50 [ V_74 -> V_77 ] ) ;
if ( V_19 -> V_22 == V_79 && V_74 -> V_77 <= 2 )
V_75 += 16000 ;
return sprintf ( V_72 , L_4 , V_75 ) ;
}
static T_6 F_38 ( struct V_32 * V_12 , struct V_70 * V_71 ,
const char * V_72 , T_7 V_80 )
{
struct {
T_2 V_89 ;
T_2 V_90 ;
int V_20 ;
} V_10 [ 5 ] = {
{ V_91 , V_92 , 0 } ,
{ V_93 , V_94 , 0 } ,
{ V_95 , V_96 , 0 } ,
{ V_91 , V_92 , 1 } ,
{ V_93 , V_94 , 1 }
} ;
struct V_88 * V_74 = F_37 ( V_71 ) ;
struct V_1 * V_2 = F_13 ( V_12 ) ;
struct V_18 * V_19 = F_14 ( V_2 ) ;
int V_87 = V_74 -> V_87 ;
int V_77 = V_74 -> V_77 ;
long V_68 ;
int V_11 ;
V_11 = F_35 ( V_72 , 10 , & V_68 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_19 -> V_22 == V_79 && V_77 <= 2 )
V_68 -= 16000 ;
F_15 ( & V_19 -> V_34 ) ;
if ( V_19 -> V_22 == V_76 )
V_19 -> V_50 [ V_77 ] = F_31 ( V_19 , V_68 ) ;
else if ( V_19 -> V_22 == V_78 )
V_19 -> V_50 [ V_77 ] = F_25 ( V_68 ) << 8 ;
else if ( V_19 -> V_6 & V_54 )
V_19 -> V_50 [ V_77 ] = F_26 ( V_68 ) ;
else
V_19 -> V_50 [ V_77 ] = F_24 ( V_68 ) << 8 ;
F_8 ( V_2 , V_19 , V_10 [ V_87 ] . V_20 ) ;
F_9 ( V_2 , V_10 [ V_87 ] . V_89 ,
V_19 -> V_50 [ V_77 ] >> 8 ) ;
if ( V_19 -> V_6 & V_54 )
F_9 ( V_2 , V_10 [ V_87 ] . V_90 ,
V_19 -> V_50 [ V_77 ] & 0xff ) ;
F_8 ( V_2 , V_19 , 0 ) ;
F_19 ( & V_19 -> V_34 ) ;
return V_80 ;
}
static T_6 F_39 ( struct V_32 * V_12 ,
struct V_70 * V_71 ,
char * V_72 )
{
struct V_73 * V_74 = F_33 ( V_71 ) ;
struct V_18 * V_19 = F_12 ( V_12 ) ;
int V_75 ;
if ( V_19 -> V_22 == V_76 )
V_75 = F_28 ( V_19 , V_19 -> V_41 [ V_74 -> V_77 ] ) ;
else if ( V_19 -> V_22 == V_78 )
V_75 = F_21 ( V_19 -> V_41 [ V_74 -> V_77 ] ) ;
else
V_75 = F_20 ( V_19 -> V_41 [ V_74 -> V_77 ] ) ;
if ( V_19 -> V_22 == V_79 && V_74 -> V_77 == 3 )
V_75 += 16000 ;
return sprintf ( V_72 , L_4 , V_75 - F_20 ( V_19 -> V_46 ) ) ;
}
static T_6 F_40 ( struct V_32 * V_12 , struct V_70 * V_97 ,
const char * V_72 , T_7 V_80 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
struct V_18 * V_19 = F_14 ( V_2 ) ;
long V_68 ;
int V_11 ;
int V_75 ;
V_11 = F_35 ( V_72 , 10 , & V_68 ) ;
if ( V_11 < 0 )
return V_11 ;
F_15 ( & V_19 -> V_34 ) ;
if ( V_19 -> V_22 == V_76 )
V_75 = F_28 ( V_19 , V_19 -> V_41 [ 2 ] ) ;
else if ( V_19 -> V_22 == V_78 )
V_75 = F_21 ( V_19 -> V_41 [ 2 ] ) ;
else
V_75 = F_20 ( V_19 -> V_41 [ 2 ] ) ;
V_19 -> V_46 = F_27 ( V_75 - V_68 ) ;
F_9 ( V_2 , V_98 ,
V_19 -> V_46 ) ;
F_19 ( & V_19 -> V_34 ) ;
return V_80 ;
}
static T_6 F_41 ( struct V_32 * V_12 , struct V_70 * V_97 ,
char * V_72 )
{
struct V_18 * V_19 = F_12 ( V_12 ) ;
return sprintf ( V_72 , L_4 , V_19 -> V_39 ) ;
}
static T_6 F_42 ( struct V_32 * V_12 , struct V_70
* V_71 , char * V_72 )
{
struct V_73 * V_74 = F_33 ( V_71 ) ;
struct V_18 * V_19 = F_12 ( V_12 ) ;
int V_99 = V_74 -> V_77 ;
return sprintf ( V_72 , L_4 , ( V_19 -> V_39 >> V_99 ) & 1 ) ;
}
static T_6 F_43 ( struct V_32 * V_12 ,
struct V_70 * V_74 , char * V_72 )
{
struct V_18 * V_19 = F_44 ( V_12 ) ;
return sprintf ( V_72 , L_5 , V_19 -> V_28 ) ;
}
static T_6 F_45 ( struct V_32 * V_12 ,
struct V_70 * V_74 ,
const char * V_72 , T_7 V_80 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
struct V_18 * V_19 = F_14 ( V_2 ) ;
unsigned long V_68 ;
int V_11 ;
V_11 = F_46 ( V_72 , 10 , & V_68 ) ;
if ( V_11 )
return V_11 ;
F_15 ( & V_19 -> V_34 ) ;
F_10 ( V_2 , V_19 , V_68 ) ;
F_19 ( & V_19 -> V_34 ) ;
return V_80 ;
}
static T_6 F_47 ( struct V_32 * V_12 , struct V_70 * V_97 ,
char * V_72 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
return sprintf ( V_72 , L_4 , ! ! ( V_2 -> V_6 & V_7 ) ) ;
}
static T_6 F_48 ( struct V_32 * V_12 , struct V_70 * V_97 ,
const char * V_72 , T_7 V_80 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
long V_68 ;
int V_11 ;
V_11 = F_35 ( V_72 , 10 , & V_68 ) ;
if ( V_11 < 0 )
return V_11 ;
switch ( V_68 ) {
case 0 :
V_2 -> V_6 &= ~ V_7 ;
break;
case 1 :
V_2 -> V_6 |= V_7 ;
break;
default:
return - V_100 ;
}
return V_80 ;
}
static int F_49 ( struct V_1 * V_101 ,
struct V_102 * V_103 )
{
struct V_104 * V_4 = V_101 -> V_4 ;
int V_105 = V_101 -> V_5 ;
const char * V_106 = NULL ;
int V_107 , V_108 , V_109 , V_110 ;
if ( ! F_50 ( V_4 , V_111 ) )
return - V_112 ;
if ( ( V_107 = F_5 ( V_101 ,
V_113 ) ) < 0
|| ( V_108 = F_5 ( V_101 ,
V_114 ) ) < 0
|| ( V_109 = F_5 ( V_101 ,
V_24 ) ) < 0
|| ( V_110 = F_5 ( V_101 ,
V_115 ) ) < 0 )
return - V_112 ;
if ( ( V_105 == 0x4C || V_105 == 0x4D )
&& V_107 == 0x01 ) {
int V_116 ;
V_116 = F_5 ( V_101 ,
V_117 ) ;
if ( V_116 < 0 )
return - V_112 ;
if ( ( V_109 & 0x2A ) == 0x00
&& ( V_116 & 0xF8 ) == 0x00
&& V_110 <= 0x09 ) {
if ( V_105 == 0x4C
&& ( V_108 & 0xF0 ) == 0x20 ) {
V_106 = L_6 ;
} else
if ( ( V_108 & 0xF0 ) == 0x30 ) {
V_106 = L_7 ;
F_51 ( & V_4 -> V_12 ,
L_8 ,
V_105 ) ;
F_51 ( & V_4 -> V_12 ,
L_9
L_10
L_11 ) ;
} else
if ( V_105 == 0x4C
&& ( V_108 & 0xF0 ) == 0x10 ) {
V_106 = L_12 ;
}
}
} else
if ( ( V_105 == 0x4C || V_105 == 0x4D )
&& V_107 == 0x41 ) {
if ( ( V_108 & 0xF0 ) == 0x40
&& ( V_109 & 0x3F ) == 0x00
&& V_110 <= 0x0A ) {
V_106 = L_13 ;
if ( F_50 ( V_4 ,
V_118 ) )
V_103 -> V_6 |= V_7 ;
} else
if ( V_108 == 0x51
&& ( V_109 & 0x1B ) == 0x00
&& V_110 <= 0x0A ) {
V_106 = L_14 ;
} else
if ( V_108 == 0x57
&& ( V_109 & 0x1B ) == 0x00
&& V_110 <= 0x0A ) {
V_106 = L_15 ;
}
} else
if ( V_107 == 0x4D ) {
int V_119 , V_120 , V_121 ;
if ( ( V_119 = F_5 ( V_101 ,
V_63 ) ) < 0
|| F_5 ( V_101 , V_113 ) < 0
|| ( V_120 = F_5 ( V_101 ,
V_63 ) ) < 0
|| ( V_121 = F_5 ( V_101 ,
V_65 ) ) < 0 )
return - V_112 ;
if ( V_108 == V_107
&& ( V_105 == 0x4C || V_105 == 0x4D || V_105 == 0x4E )
&& ( V_109 & 0x1F ) == ( V_107 & 0x0F )
&& V_110 <= 0x09 ) {
if ( V_105 == 0x4C )
V_106 = L_16 ;
else
V_106 = L_17 ;
} else
if ( V_108 == 0x01
&& ( V_109 & 0x10 ) == 0x00
&& ( V_121 & 0x01 ) == 0x00
&& V_119 == V_120
&& V_110 <= 0x07 ) {
V_106 = L_18 ;
} else
if ( V_108 == 0x01
&& ( V_109 & 0x03 ) == 0x00
&& V_110 <= 0x07 ) {
V_106 = L_19 ;
} else
if ( V_108 == 0x59
&& ( V_109 & 0x3f ) == 0x00
&& V_110 <= 0x07 ) {
V_106 = L_20 ;
}
} else
if ( V_105 == 0x4C
&& V_107 == 0x5C ) {
int V_116 ;
V_116 = F_5 ( V_101 ,
V_117 ) ;
if ( V_116 < 0 )
return - V_112 ;
if ( ( V_109 & 0x2A ) == 0x00
&& ( V_116 & 0xF8 ) == 0x00 ) {
if ( V_108 == 0x01
&& V_110 <= 0x09 ) {
V_106 = L_21 ;
} else
if ( ( V_108 & 0xFE ) == 0x10
&& V_110 <= 0x08 ) {
V_106 = L_21 ;
}
}
}
if ( ! V_106 ) {
F_18 ( & V_4 -> V_12 ,
L_22
L_23 , V_105 , V_107 , V_108 ) ;
return - V_112 ;
}
F_52 ( V_103 -> type , V_106 , V_122 ) ;
return 0 ;
}
static void F_53 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
if ( V_19 -> V_6 & V_123 )
F_54 ( & V_2 -> V_12 . V_124 , & V_125 ) ;
if ( V_19 -> V_6 & V_126 )
F_54 ( & V_2 -> V_12 . V_124 ,
& V_127 ) ;
if ( V_19 -> V_6 & V_61 )
F_54 ( & V_2 -> V_12 . V_124 ,
& V_128 ) ;
if ( V_19 -> V_6 & V_58 )
F_55 ( & V_2 -> V_12 ,
& V_129 . V_130 ) ;
F_55 ( & V_2 -> V_12 , & V_131 ) ;
F_54 ( & V_2 -> V_12 . V_124 , & V_132 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
T_2 V_21 , V_133 ;
struct V_18 * V_19 = F_14 ( V_2 ) ;
if ( F_3 ( V_2 , V_115 , & V_133 ) < 0 ) {
F_6 ( & V_2 -> V_12 , L_24 ) ;
V_133 = V_134 ;
}
V_19 -> V_135 = V_133 ;
F_10 ( V_2 , V_19 , 500 ) ;
if ( F_3 ( V_2 , V_24 , & V_21 ) < 0 ) {
F_6 ( & V_2 -> V_12 , L_25 ) ;
return;
}
V_19 -> V_66 = V_21 ;
if ( V_19 -> V_22 == V_76 ) {
if ( V_21 & 0x04 )
V_19 -> V_6 |= V_69 ;
}
if ( V_19 -> V_22 == V_136 )
V_21 |= 0x18 ;
if ( V_19 -> V_22 == V_23 )
V_21 &= ~ 0x08 ;
V_21 &= 0xBF ;
if ( V_21 != V_19 -> V_66 )
F_9 ( V_2 , V_25 , V_21 ) ;
}
static int F_57 ( struct V_1 * V_101 ,
const struct V_137 * V_138 )
{
struct V_104 * V_4 = F_58 ( V_101 -> V_12 . V_139 ) ;
struct V_18 * V_19 ;
int V_11 ;
V_19 = F_59 ( sizeof( struct V_18 ) , V_140 ) ;
if ( ! V_19 ) {
V_11 = - V_141 ;
goto exit;
}
F_60 ( V_101 , V_19 ) ;
F_61 ( & V_19 -> V_34 ) ;
V_19 -> V_22 = V_138 -> V_142 ;
if ( V_19 -> V_22 == V_143 ) {
if ( ! F_50 ( V_4 , V_118 ) )
V_101 -> V_6 &= ~ V_7 ;
}
V_19 -> V_67 = V_144 [ V_19 -> V_22 ] . V_67 ;
V_19 -> V_6 = V_144 [ V_19 -> V_22 ] . V_6 ;
V_19 -> V_30 = V_144 [ V_19 -> V_22 ] . V_30 ;
F_56 ( V_101 ) ;
V_11 = F_62 ( & V_101 -> V_12 . V_124 , & V_132 ) ;
if ( V_11 )
goto V_145;
if ( V_101 -> V_6 & V_7 ) {
V_11 = F_63 ( & V_101 -> V_12 , & V_131 ) ;
if ( V_11 )
goto V_146;
}
if ( V_19 -> V_6 & V_58 ) {
V_11 = F_63 ( & V_101 -> V_12 ,
& V_129 . V_130 ) ;
if ( V_11 )
goto V_146;
}
if ( V_19 -> V_6 & V_61 ) {
V_11 = F_62 ( & V_101 -> V_12 . V_124 ,
& V_128 ) ;
if ( V_11 )
goto V_146;
}
if ( V_19 -> V_6 & V_126 ) {
V_11 = F_62 ( & V_101 -> V_12 . V_124 ,
& V_127 ) ;
if ( V_11 )
goto V_146;
}
if ( V_19 -> V_6 & V_123 ) {
V_11 = F_62 ( & V_101 -> V_12 . V_124 ,
& V_125 ) ;
if ( V_11 )
goto V_146;
}
V_19 -> V_147 = F_64 ( & V_101 -> V_12 ) ;
if ( F_65 ( V_19 -> V_147 ) ) {
V_11 = F_66 ( V_19 -> V_147 ) ;
goto V_146;
}
return 0 ;
V_146:
F_53 ( V_101 , V_19 ) ;
V_145:
F_67 ( V_19 ) ;
exit:
return V_11 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_14 ( V_2 ) ;
F_69 ( V_19 -> V_147 ) ;
F_53 ( V_2 , V_19 ) ;
F_9 ( V_2 , V_31 ,
V_19 -> V_135 ) ;
F_9 ( V_2 , V_25 ,
V_19 -> V_66 ) ;
F_67 ( V_19 ) ;
return 0 ;
}
static void F_70 ( struct V_1 * V_2 , unsigned int V_148 )
{
struct V_18 * V_19 = F_14 ( V_2 ) ;
T_2 V_21 , V_39 , V_149 = 0 ;
F_3 ( V_2 , V_64 , & V_39 ) ;
if ( V_19 -> V_22 == V_23 )
F_3 ( V_2 , V_65 , & V_149 ) ;
if ( ( V_39 & 0x7f ) == 0 && ( V_149 & 0xfe ) == 0 ) {
F_51 ( & V_2 -> V_12 , L_26 ) ;
} else {
if ( V_39 & 0x61 )
F_6 ( & V_2 -> V_12 ,
L_27 , 1 ) ;
if ( V_39 & 0x1a )
F_6 ( & V_2 -> V_12 ,
L_27 , 2 ) ;
if ( V_39 & 0x04 )
F_6 ( & V_2 -> V_12 ,
L_28 , 2 ) ;
if ( V_149 & 0x18 )
F_6 ( & V_2 -> V_12 ,
L_27 , 3 ) ;
if ( ( V_19 -> V_6 & V_150 )
&& ( V_39 & V_19 -> V_67 ) ) {
F_18 ( & V_2 -> V_12 , L_29 ) ;
F_3 ( V_2 , V_24 , & V_21 ) ;
F_9 ( V_2 , V_25 ,
V_21 | 0x80 ) ;
}
}
}
static int T_8 F_71 ( void )
{
return F_72 ( & V_151 ) ;
}
static void T_9 F_73 ( void )
{
F_74 ( & V_151 ) ;
}
