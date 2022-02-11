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
if ( V_19 -> V_47 ) {
F_7 ( V_2 , V_48 ,
V_19 -> V_47 ,
& V_19 -> V_49 [ 4 ] ) ;
} else {
if ( F_3 ( V_2 , V_48 ,
& V_38 ) == 0 )
V_19 -> V_49 [ 4 ] = V_38 << 8 ;
}
F_7 ( V_2 , V_50 ,
V_51 , & V_19 -> V_49 [ 0 ] ) ;
if ( F_3 ( V_2 , V_52 , & V_38 ) == 0 ) {
V_19 -> V_49 [ 1 ] = V_38 << 8 ;
if ( ( V_19 -> V_6 & V_53 )
&& F_3 ( V_2 , V_54 ,
& V_17 ) == 0 )
V_19 -> V_49 [ 1 ] |= V_17 ;
}
if ( F_3 ( V_2 , V_55 , & V_38 ) == 0 ) {
V_19 -> V_49 [ 2 ] = V_38 << 8 ;
if ( ( V_19 -> V_6 & V_53 )
&& F_3 ( V_2 , V_56 ,
& V_17 ) == 0 )
V_19 -> V_49 [ 2 ] |= V_17 ;
}
if ( V_19 -> V_6 & V_57 ) {
if ( F_3 ( V_2 , V_58 ,
& V_38 ) == 0
&& F_3 ( V_2 , V_59 ,
& V_17 ) == 0 )
V_19 -> V_49 [ 3 ] = ( V_38 << 8 ) | V_17 ;
}
if ( V_19 -> V_6 & V_60 ) {
F_3 ( V_2 , V_61 ,
& V_19 -> V_41 [ 4 ] ) ;
F_3 ( V_2 , V_62 ,
& V_19 -> V_41 [ 5 ] ) ;
}
F_3 ( V_2 , V_63 , & V_39 ) ;
V_19 -> V_39 = V_39 ;
if ( V_19 -> V_22 == V_23 ) {
F_8 ( V_2 , V_19 , 1 ) ;
F_3 ( V_2 , V_44 ,
& V_19 -> V_41 [ 6 ] ) ;
F_3 ( V_2 , V_62 ,
& V_19 -> V_41 [ 7 ] ) ;
F_7 ( V_2 , V_50 ,
V_51 , & V_19 -> V_49 [ 5 ] ) ;
if ( ! F_3 ( V_2 , V_52 , & V_38 ) )
V_19 -> V_49 [ 6 ] = V_38 << 8 ;
if ( ! F_3 ( V_2 , V_55 , & V_38 ) )
V_19 -> V_49 [ 7 ] = V_38 << 8 ;
F_8 ( V_2 , V_19 , 0 ) ;
if ( ! F_3 ( V_2 , V_64 ,
& V_39 ) )
V_19 -> V_39 |= V_39 << 8 ;
}
if ( ( V_19 -> V_65 & 0x80 ) == 0
&& ( V_19 -> V_39 & V_19 -> V_66 ) == 0 ) {
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
static inline int F_20 ( T_4 V_67 )
{
return V_67 * 1000 ;
}
static inline int F_21 ( T_2 V_67 )
{
return V_67 * 1000 ;
}
static inline int F_22 ( T_5 V_67 )
{
return V_67 / 32 * 125 ;
}
static inline int F_23 ( T_3 V_67 )
{
return V_67 / 32 * 125 ;
}
static T_4 F_24 ( long V_67 )
{
if ( V_67 <= - 128000 )
return - 128 ;
if ( V_67 >= 127000 )
return 127 ;
if ( V_67 < 0 )
return ( V_67 - 500 ) / 1000 ;
return ( V_67 + 500 ) / 1000 ;
}
static T_2 F_25 ( long V_67 )
{
if ( V_67 <= 0 )
return 0 ;
if ( V_67 >= 255000 )
return 255 ;
return ( V_67 + 500 ) / 1000 ;
}
static T_5 F_26 ( long V_67 )
{
if ( V_67 <= - 128000 )
return 0x8000 ;
if ( V_67 >= 127875 )
return 0x7FE0 ;
if ( V_67 < 0 )
return ( V_67 - 62 ) / 125 * 32 ;
return ( V_67 + 62 ) / 125 * 32 ;
}
static T_2 F_27 ( long V_67 )
{
if ( V_67 <= 0 )
return 0 ;
if ( V_67 >= 30500 )
return 31 ;
return ( V_67 + 500 ) / 1000 ;
}
static inline int F_28 ( struct V_18 * V_19 , T_2 V_67 )
{
if ( V_19 -> V_6 & V_68 )
return ( V_67 - 64 ) * 1000 ;
else
return F_20 ( V_67 ) ;
}
static inline int F_29 ( struct V_18 * V_19 , T_3 V_67 )
{
if ( V_19 -> V_6 & V_68 )
return ( V_67 - 0x4000 ) / 64 * 250 ;
else
return F_22 ( V_67 ) ;
}
static T_2 F_30 ( struct V_18 * V_19 , long V_67 )
{
if ( V_19 -> V_6 & V_68 ) {
if ( V_67 <= - 64000 )
return 0 ;
if ( V_67 >= 191000 )
return 0xFF ;
return ( V_67 + 500 + 64000 ) / 1000 ;
} else {
if ( V_67 <= 0 )
return 0 ;
if ( V_67 >= 127000 )
return 127 ;
return ( V_67 + 500 ) / 1000 ;
}
}
static T_3 F_31 ( struct V_18 * V_19 , long V_67 )
{
if ( V_19 -> V_6 & V_68 ) {
if ( V_67 <= - 64000 )
return 0 ;
if ( V_67 >= 191750 )
return 0xFFC0 ;
return ( V_67 + 64000 + 125 ) / 250 * 64 ;
} else {
if ( V_67 <= 0 )
return 0 ;
if ( V_67 >= 127750 )
return 0x7FC0 ;
return ( V_67 + 125 ) / 250 * 64 ;
}
}
static T_6 F_32 ( struct V_32 * V_12 , struct V_69 * V_70 ,
char * V_71 )
{
struct V_72 * V_73 = F_33 ( V_70 ) ;
struct V_18 * V_19 = F_12 ( V_12 ) ;
int V_74 ;
if ( V_19 -> V_22 == V_75 )
V_74 = F_28 ( V_19 , V_19 -> V_41 [ V_73 -> V_76 ] ) ;
else if ( V_19 -> V_22 == V_77 )
V_74 = F_21 ( V_19 -> V_41 [ V_73 -> V_76 ] ) ;
else
V_74 = F_20 ( V_19 -> V_41 [ V_73 -> V_76 ] ) ;
if ( V_19 -> V_22 == V_78 && V_73 -> V_76 == 3 )
V_74 += 16000 ;
return sprintf ( V_71 , L_4 , V_74 ) ;
}
static T_6 F_34 ( struct V_32 * V_12 , struct V_69 * V_70 ,
const char * V_71 , T_7 V_79 )
{
static const T_2 V_10 [ 8 ] = {
V_80 ,
V_81 ,
V_82 ,
V_83 ,
V_84 ,
V_85 ,
V_83 ,
V_85 ,
} ;
struct V_72 * V_73 = F_33 ( V_70 ) ;
struct V_1 * V_2 = F_13 ( V_12 ) ;
struct V_18 * V_19 = F_14 ( V_2 ) ;
int V_86 = V_73 -> V_76 ;
long V_67 ;
int V_11 ;
V_11 = F_35 ( V_71 , 10 , & V_67 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_19 -> V_22 == V_78 && V_73 -> V_76 == 3 )
V_67 -= 16000 ;
F_15 ( & V_19 -> V_34 ) ;
if ( V_19 -> V_22 == V_75 )
V_19 -> V_41 [ V_86 ] = F_30 ( V_19 , V_67 ) ;
else if ( V_19 -> V_22 == V_77 )
V_19 -> V_41 [ V_86 ] = F_25 ( V_67 ) ;
else
V_19 -> V_41 [ V_86 ] = F_24 ( V_67 ) ;
F_8 ( V_2 , V_19 , V_86 >= 6 ) ;
F_9 ( V_2 , V_10 [ V_86 ] , V_19 -> V_41 [ V_86 ] ) ;
F_8 ( V_2 , V_19 , 0 ) ;
F_19 ( & V_19 -> V_34 ) ;
return V_79 ;
}
static T_6 F_36 ( struct V_32 * V_12 , struct V_69 * V_70 ,
char * V_71 )
{
struct V_87 * V_73 = F_37 ( V_70 ) ;
struct V_18 * V_19 = F_12 ( V_12 ) ;
int V_74 ;
if ( V_19 -> V_22 == V_75 )
V_74 = F_29 ( V_19 , V_19 -> V_49 [ V_73 -> V_76 ] ) ;
else if ( V_19 -> V_22 == V_77 )
V_74 = F_23 ( V_19 -> V_49 [ V_73 -> V_76 ] ) ;
else
V_74 = F_22 ( V_19 -> V_49 [ V_73 -> V_76 ] ) ;
if ( V_19 -> V_22 == V_78 && V_73 -> V_76 <= 2 )
V_74 += 16000 ;
return sprintf ( V_71 , L_4 , V_74 ) ;
}
static T_6 F_38 ( struct V_32 * V_12 , struct V_69 * V_70 ,
const char * V_71 , T_7 V_79 )
{
struct {
T_2 V_88 ;
T_2 V_89 ;
int V_20 ;
} V_10 [ 5 ] = {
{ V_90 , V_91 , 0 } ,
{ V_92 , V_93 , 0 } ,
{ V_94 , V_95 , 0 } ,
{ V_90 , V_91 , 1 } ,
{ V_92 , V_93 , 1 }
} ;
struct V_87 * V_73 = F_37 ( V_70 ) ;
struct V_1 * V_2 = F_13 ( V_12 ) ;
struct V_18 * V_19 = F_14 ( V_2 ) ;
int V_86 = V_73 -> V_86 ;
int V_76 = V_73 -> V_76 ;
long V_67 ;
int V_11 ;
V_11 = F_35 ( V_71 , 10 , & V_67 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_19 -> V_22 == V_78 && V_76 <= 2 )
V_67 -= 16000 ;
F_15 ( & V_19 -> V_34 ) ;
if ( V_19 -> V_22 == V_75 )
V_19 -> V_49 [ V_76 ] = F_31 ( V_19 , V_67 ) ;
else if ( V_19 -> V_22 == V_77 )
V_19 -> V_49 [ V_76 ] = F_25 ( V_67 ) << 8 ;
else if ( V_19 -> V_6 & V_53 )
V_19 -> V_49 [ V_76 ] = F_26 ( V_67 ) ;
else
V_19 -> V_49 [ V_76 ] = F_24 ( V_67 ) << 8 ;
F_8 ( V_2 , V_19 , V_10 [ V_86 ] . V_20 ) ;
F_9 ( V_2 , V_10 [ V_86 ] . V_88 ,
V_19 -> V_49 [ V_76 ] >> 8 ) ;
if ( V_19 -> V_6 & V_53 )
F_9 ( V_2 , V_10 [ V_86 ] . V_89 ,
V_19 -> V_49 [ V_76 ] & 0xff ) ;
F_8 ( V_2 , V_19 , 0 ) ;
F_19 ( & V_19 -> V_34 ) ;
return V_79 ;
}
static T_6 F_39 ( struct V_32 * V_12 ,
struct V_69 * V_70 ,
char * V_71 )
{
struct V_72 * V_73 = F_33 ( V_70 ) ;
struct V_18 * V_19 = F_12 ( V_12 ) ;
int V_74 ;
if ( V_19 -> V_22 == V_75 )
V_74 = F_28 ( V_19 , V_19 -> V_41 [ V_73 -> V_76 ] ) ;
else if ( V_19 -> V_22 == V_77 )
V_74 = F_21 ( V_19 -> V_41 [ V_73 -> V_76 ] ) ;
else
V_74 = F_20 ( V_19 -> V_41 [ V_73 -> V_76 ] ) ;
if ( V_19 -> V_22 == V_78 && V_73 -> V_76 == 3 )
V_74 += 16000 ;
return sprintf ( V_71 , L_4 , V_74 - F_20 ( V_19 -> V_46 ) ) ;
}
static T_6 F_40 ( struct V_32 * V_12 , struct V_69 * V_96 ,
const char * V_71 , T_7 V_79 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
struct V_18 * V_19 = F_14 ( V_2 ) ;
long V_67 ;
int V_11 ;
int V_74 ;
V_11 = F_35 ( V_71 , 10 , & V_67 ) ;
if ( V_11 < 0 )
return V_11 ;
F_15 ( & V_19 -> V_34 ) ;
if ( V_19 -> V_22 == V_75 )
V_74 = F_28 ( V_19 , V_19 -> V_41 [ 2 ] ) ;
else if ( V_19 -> V_22 == V_77 )
V_74 = F_21 ( V_19 -> V_41 [ 2 ] ) ;
else
V_74 = F_20 ( V_19 -> V_41 [ 2 ] ) ;
V_19 -> V_46 = F_27 ( V_74 - V_67 ) ;
F_9 ( V_2 , V_97 ,
V_19 -> V_46 ) ;
F_19 ( & V_19 -> V_34 ) ;
return V_79 ;
}
static T_6 F_41 ( struct V_32 * V_12 , struct V_69 * V_96 ,
char * V_71 )
{
struct V_18 * V_19 = F_12 ( V_12 ) ;
return sprintf ( V_71 , L_4 , V_19 -> V_39 ) ;
}
static T_6 F_42 ( struct V_32 * V_12 , struct V_69
* V_70 , char * V_71 )
{
struct V_72 * V_73 = F_33 ( V_70 ) ;
struct V_18 * V_19 = F_12 ( V_12 ) ;
int V_98 = V_73 -> V_76 ;
return sprintf ( V_71 , L_4 , ( V_19 -> V_39 >> V_98 ) & 1 ) ;
}
static T_6 F_43 ( struct V_32 * V_12 ,
struct V_69 * V_73 , char * V_71 )
{
struct V_18 * V_19 = F_44 ( V_12 ) ;
return sprintf ( V_71 , L_5 , V_19 -> V_28 ) ;
}
static T_6 F_45 ( struct V_32 * V_12 ,
struct V_69 * V_73 ,
const char * V_71 , T_7 V_79 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
struct V_18 * V_19 = F_14 ( V_2 ) ;
unsigned long V_67 ;
int V_11 ;
V_11 = F_46 ( V_71 , 10 , & V_67 ) ;
if ( V_11 )
return V_11 ;
F_15 ( & V_19 -> V_34 ) ;
F_10 ( V_2 , V_19 , F_47 ( V_67 , 0 , 100000 ) ) ;
F_19 ( & V_19 -> V_34 ) ;
return V_79 ;
}
static T_6 F_48 ( struct V_32 * V_12 , struct V_69 * V_96 ,
char * V_71 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
return sprintf ( V_71 , L_4 , ! ! ( V_2 -> V_6 & V_7 ) ) ;
}
static T_6 F_49 ( struct V_32 * V_12 , struct V_69 * V_96 ,
const char * V_71 , T_7 V_79 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
long V_67 ;
int V_11 ;
V_11 = F_35 ( V_71 , 10 , & V_67 ) ;
if ( V_11 < 0 )
return V_11 ;
switch ( V_67 ) {
case 0 :
V_2 -> V_6 &= ~ V_7 ;
break;
case 1 :
V_2 -> V_6 |= V_7 ;
break;
default:
return - V_99 ;
}
return V_79 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_100 * V_101 )
{
struct V_102 * V_4 = V_2 -> V_4 ;
int V_103 = V_2 -> V_5 ;
const char * V_104 = NULL ;
int V_105 , V_106 , V_107 , V_108 , V_109 ;
if ( ! F_51 ( V_4 , V_110 ) )
return - V_111 ;
V_105 = F_5 ( V_2 , V_112 ) ;
V_106 = F_5 ( V_2 , V_113 ) ;
V_107 = F_5 ( V_2 , V_24 ) ;
V_109 = F_5 ( V_2 , V_114 ) ;
if ( V_105 < 0 || V_106 < 0 || V_107 < 0 || V_109 < 0 )
return - V_111 ;
if ( V_105 == 0x01 || V_105 == 0x5C || V_105 == 0x41 ) {
V_108 = F_5 ( V_2 , V_115 ) ;
if ( V_108 < 0 )
return - V_111 ;
} else
V_108 = 0 ;
if ( ( V_103 == 0x4C || V_103 == 0x4D )
&& V_105 == 0x01 ) {
if ( ( V_107 & 0x2A ) == 0x00
&& ( V_108 & 0xF8 ) == 0x00
&& V_109 <= 0x09 ) {
if ( V_103 == 0x4C
&& ( V_106 & 0xF0 ) == 0x20 ) {
V_104 = L_6 ;
} else
if ( ( V_106 & 0xF0 ) == 0x30 ) {
V_104 = L_7 ;
F_52 ( & V_4 -> V_12 ,
L_8 ,
V_103 ) ;
F_52 ( & V_4 -> V_12 ,
L_9
L_10
L_11 ) ;
} else
if ( V_103 == 0x4C
&& ( V_106 & 0xF0 ) == 0x10 ) {
V_104 = L_12 ;
}
}
} else
if ( ( V_103 == 0x4C || V_103 == 0x4D )
&& V_105 == 0x41 ) {
if ( ( V_106 & 0xF0 ) == 0x40
&& ( V_107 & 0x3F ) == 0x00
&& V_109 <= 0x0A ) {
V_104 = L_13 ;
if ( F_51 ( V_4 ,
V_116 ) )
V_101 -> V_6 |= V_7 ;
} else
if ( V_106 == 0x51
&& ( V_107 & 0x1B ) == 0x00
&& V_109 <= 0x0A ) {
V_104 = L_14 ;
} else
if ( V_106 == 0x57
&& ( V_107 & 0x1B ) == 0x00
&& V_109 <= 0x0A ) {
V_104 = L_15 ;
}
} else
if ( V_105 == 0x4D ) {
int V_117 , V_118 , V_119 ;
V_117 = F_5 ( V_2 ,
V_62 ) ;
V_105 = F_5 ( V_2 ,
V_112 ) ;
V_118 = F_5 ( V_2 ,
V_62 ) ;
V_119 = F_5 ( V_2 ,
V_64 ) ;
if ( V_117 < 0 || V_105 < 0 || V_118 < 0 || V_119 < 0 )
return - V_111 ;
if ( V_106 == V_105
&& ( V_103 == 0x4C || V_103 == 0x4D || V_103 == 0x4E )
&& ( V_107 & 0x1F ) == ( V_105 & 0x0F )
&& V_109 <= 0x09 ) {
if ( V_103 == 0x4C )
V_104 = L_16 ;
else
V_104 = L_17 ;
} else
if ( V_106 == 0x01
&& ( V_107 & 0x10 ) == 0x00
&& ( V_119 & 0x01 ) == 0x00
&& V_117 == V_118
&& V_109 <= 0x07 ) {
V_104 = L_18 ;
} else
if ( V_106 == 0x01
&& ( V_107 & 0x03 ) == 0x00
&& V_109 <= 0x07 ) {
V_104 = L_19 ;
} else
if ( V_106 == 0x59
&& ( V_107 & 0x3f ) == 0x00
&& V_109 <= 0x07 ) {
V_104 = L_20 ;
}
} else
if ( V_103 == 0x4C
&& V_105 == 0x5C ) {
if ( ( V_107 & 0x2A ) == 0x00
&& ( V_108 & 0xF8 ) == 0x00 ) {
if ( V_106 == 0x01
&& V_109 <= 0x09 ) {
V_104 = L_21 ;
} else
if ( ( V_106 & 0xFE ) == 0x10
&& V_109 <= 0x08 ) {
V_104 = L_21 ;
}
}
} else
if ( V_103 >= 0x48 && V_103 <= 0x4F
&& V_105 == 0xA1 ) {
if ( V_106 == 0x00
&& ( V_107 & 0x2A ) == 0x00
&& ( V_108 & 0xFE ) == 0x00
&& V_109 <= 0x09 ) {
V_104 = L_22 ;
}
} else
if ( ( V_103 == 0x4C || V_103 == 0x4D )
&& V_105 == 0x47 ) {
if ( V_106 == 0x01
&& ( V_107 & 0x3F ) == 0x00
&& V_109 <= 0x08 )
V_104 = L_23 ;
}
if ( ! V_104 ) {
F_18 ( & V_4 -> V_12 ,
L_24
L_25 , V_103 , V_105 , V_106 ) ;
return - V_111 ;
}
F_53 ( V_101 -> type , V_104 , V_120 ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_32 * V_12 = & V_2 -> V_12 ;
if ( V_19 -> V_6 & V_121 )
F_55 ( & V_12 -> V_122 , & V_123 ) ;
if ( V_19 -> V_6 & V_124 )
F_55 ( & V_12 -> V_122 , & V_125 ) ;
if ( V_19 -> V_6 & V_60 )
F_55 ( & V_12 -> V_122 , & V_126 ) ;
if ( V_19 -> V_6 & V_57 )
F_56 ( V_12 , & V_127 . V_128 ) ;
F_56 ( V_12 , & V_129 ) ;
F_55 ( & V_12 -> V_122 , & V_130 ) ;
}
static void F_57 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
F_9 ( V_2 , V_31 ,
V_19 -> V_131 ) ;
F_9 ( V_2 , V_25 ,
V_19 -> V_65 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
T_2 V_21 , V_109 ;
struct V_18 * V_19 = F_14 ( V_2 ) ;
if ( F_3 ( V_2 , V_114 , & V_109 ) < 0 ) {
F_6 ( & V_2 -> V_12 , L_26 ) ;
V_109 = V_132 ;
}
V_19 -> V_131 = V_109 ;
F_10 ( V_2 , V_19 , 500 ) ;
if ( F_3 ( V_2 , V_24 , & V_21 ) < 0 ) {
F_6 ( & V_2 -> V_12 , L_27 ) ;
return;
}
V_19 -> V_65 = V_21 ;
if ( V_19 -> V_22 == V_75 ) {
if ( V_21 & 0x04 )
V_19 -> V_6 |= V_68 ;
}
if ( V_19 -> V_22 == V_133 )
V_21 |= 0x18 ;
if ( V_19 -> V_22 == V_23 )
V_21 &= ~ 0x08 ;
V_21 &= 0xBF ;
if ( V_21 != V_19 -> V_65 )
F_9 ( V_2 , V_25 , V_21 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
const struct V_134 * V_135 )
{
struct V_32 * V_12 = & V_2 -> V_12 ;
struct V_102 * V_4 = F_60 ( V_12 -> V_136 ) ;
struct V_18 * V_19 ;
int V_11 ;
V_19 = F_61 ( & V_2 -> V_12 , sizeof( struct V_18 ) , V_137 ) ;
if ( ! V_19 )
return - V_138 ;
F_62 ( V_2 , V_19 ) ;
F_63 ( & V_19 -> V_34 ) ;
V_19 -> V_22 = V_135 -> V_139 ;
if ( V_19 -> V_22 == V_140 ) {
if ( ! F_51 ( V_4 , V_116 ) )
V_2 -> V_6 &= ~ V_7 ;
}
V_19 -> V_66 = V_141 [ V_19 -> V_22 ] . V_66 ;
V_19 -> V_6 = V_141 [ V_19 -> V_22 ] . V_6 ;
V_19 -> V_47 = V_141 [ V_19 -> V_22 ] . V_47 ;
V_19 -> V_30 = V_141 [ V_19 -> V_22 ] . V_30 ;
F_58 ( V_2 ) ;
V_11 = F_64 ( & V_12 -> V_122 , & V_130 ) ;
if ( V_11 )
goto V_142;
if ( V_2 -> V_6 & V_7 ) {
V_11 = F_65 ( V_12 , & V_129 ) ;
if ( V_11 )
goto V_143;
}
if ( V_19 -> V_6 & V_57 ) {
V_11 = F_65 ( V_12 ,
& V_127 . V_128 ) ;
if ( V_11 )
goto V_143;
}
if ( V_19 -> V_6 & V_60 ) {
V_11 = F_64 ( & V_12 -> V_122 , & V_126 ) ;
if ( V_11 )
goto V_143;
}
if ( V_19 -> V_6 & V_124 ) {
V_11 = F_64 ( & V_12 -> V_122 ,
& V_125 ) ;
if ( V_11 )
goto V_143;
}
if ( V_19 -> V_6 & V_121 ) {
V_11 = F_64 ( & V_12 -> V_122 , & V_123 ) ;
if ( V_11 )
goto V_143;
}
V_19 -> V_144 = F_66 ( V_12 ) ;
if ( F_67 ( V_19 -> V_144 ) ) {
V_11 = F_68 ( V_19 -> V_144 ) ;
goto V_143;
}
return 0 ;
V_143:
F_54 ( V_2 , V_19 ) ;
V_142:
F_57 ( V_2 , V_19 ) ;
return V_11 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_14 ( V_2 ) ;
F_70 ( V_19 -> V_144 ) ;
F_54 ( V_2 , V_19 ) ;
F_57 ( V_2 , V_19 ) ;
return 0 ;
}
static void F_71 ( struct V_1 * V_2 , unsigned int V_145 )
{
struct V_18 * V_19 = F_14 ( V_2 ) ;
T_2 V_21 , V_39 , V_146 = 0 ;
F_3 ( V_2 , V_63 , & V_39 ) ;
if ( V_19 -> V_22 == V_23 )
F_3 ( V_2 , V_64 , & V_146 ) ;
if ( ( V_39 & 0x7f ) == 0 && ( V_146 & 0xfe ) == 0 ) {
F_52 ( & V_2 -> V_12 , L_28 ) ;
} else {
if ( V_39 & 0x61 )
F_6 ( & V_2 -> V_12 ,
L_29 , 1 ) ;
if ( V_39 & 0x1a )
F_6 ( & V_2 -> V_12 ,
L_29 , 2 ) ;
if ( V_39 & 0x04 )
F_6 ( & V_2 -> V_12 ,
L_30 , 2 ) ;
if ( V_146 & 0x18 )
F_6 ( & V_2 -> V_12 ,
L_29 , 3 ) ;
if ( ( V_19 -> V_6 & V_147 )
&& ( V_39 & V_19 -> V_66 ) ) {
F_18 ( & V_2 -> V_12 , L_31 ) ;
F_3 ( V_2 , V_24 , & V_21 ) ;
F_9 ( V_2 , V_25 ,
V_21 | 0x80 ) ;
}
}
}
