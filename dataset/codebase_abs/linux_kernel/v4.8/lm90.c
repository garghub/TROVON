static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 , V_2 -> V_5 ,
V_2 -> V_6 & ~ V_7 ,
V_8 , V_3 , V_9 , NULL ) ;
}
static int F_3 ( struct V_1 * V_2 , T_2 V_10 )
{
int V_11 ;
if ( V_2 -> V_6 & V_7 ) {
V_11 = F_1 ( V_2 , V_10 ) ;
if ( V_11 >= 0 )
V_11 = F_4 ( V_2 ) ;
} else
V_11 = F_5 ( V_2 , V_10 ) ;
return V_11 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_12 , T_2 V_13 )
{
int V_14 , V_15 , V_16 ;
V_14 = F_3 ( V_2 , V_12 ) ;
if ( V_14 < 0 )
return V_14 ;
V_16 = F_3 ( V_2 , V_13 ) ;
if ( V_16 < 0 )
return V_16 ;
V_15 = F_3 ( V_2 , V_12 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_14 != V_15 ) {
V_16 = F_3 ( V_2 , V_13 ) ;
if ( V_16 < 0 )
return V_16 ;
}
return ( V_15 << 8 ) | V_16 ;
}
static inline int F_7 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
int V_19 )
{
int V_20 ;
if ( V_18 -> V_21 == V_22 ) {
V_20 = F_3 ( V_2 , V_23 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 &= ~ 0x08 ;
if ( V_19 )
V_20 |= 0x08 ;
F_8 ( V_2 , V_24 ,
V_20 ) ;
}
return 0 ;
}
static void F_9 ( struct V_1 * V_2 , struct V_17 * V_18 ,
unsigned int V_25 )
{
int V_26 ;
unsigned int V_27 ;
V_25 <<= 6 ;
for ( V_26 = 0 , V_27 = V_28 << 6 ;
V_26 < V_18 -> V_29 ; V_26 ++ , V_27 >>= 1 )
if ( V_25 >= V_27 * 3 / 4 )
break;
F_8 ( V_2 , V_30 , V_26 ) ;
V_18 -> V_27 = F_10 ( V_27 , 64 ) ;
}
static int F_11 ( struct V_31 * V_32 )
{
struct V_17 * V_18 = F_12 ( V_32 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
int V_33 ;
V_33 = F_3 ( V_2 , V_34 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_35 [ V_36 ] = V_33 ;
V_33 = F_3 ( V_2 , V_37 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_35 [ V_38 ] = V_33 ;
V_33 = F_3 ( V_2 , V_39 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_40 = V_33 ;
V_33 = F_3 ( V_2 , V_41 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_42 [ V_43 ] = V_33 << 8 ;
if ( V_18 -> V_6 & V_44 ) {
V_33 = F_3 ( V_2 , V_45 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_42 [ V_43 ] |= V_33 ;
}
V_33 = F_3 ( V_2 , V_46 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_42 [ V_47 ] = V_33 << 8 ;
if ( V_18 -> V_6 & V_44 ) {
V_33 = F_3 ( V_2 , V_48 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_42 [ V_47 ] |= V_33 ;
}
if ( V_18 -> V_6 & V_49 ) {
V_33 = F_6 ( V_2 , V_50 ,
V_51 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_42 [ V_52 ] = V_33 ;
}
if ( V_18 -> V_6 & V_53 ) {
V_33 = F_3 ( V_2 , V_54 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_35 [ V_55 ] = V_33 ;
V_33 = F_3 ( V_2 , V_56 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_35 [ V_57 ] = V_33 ;
}
if ( V_18 -> V_21 == V_22 ) {
V_33 = F_7 ( V_2 , V_18 , 1 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_3 ( V_2 , V_37 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_35 [ V_58 ] = V_33 ;
V_33 = F_3 ( V_2 , V_56 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_35 [ V_59 ] = V_33 ;
V_33 = F_3 ( V_2 , V_41 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_42 [ V_60 ] = V_33 << 8 ;
V_33 = F_3 ( V_2 , V_46 ) ;
if ( V_33 < 0 )
return V_33 ;
V_18 -> V_42 [ V_61 ] = V_33 << 8 ;
F_7 ( V_2 , V_18 , 0 ) ;
}
return 0 ;
}
static struct V_17 * F_13 ( struct V_31 * V_32 )
{
struct V_17 * V_18 = F_12 ( V_32 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
unsigned long V_62 ;
int V_33 = 0 ;
F_14 ( & V_18 -> V_63 ) ;
if ( ! V_18 -> V_64 ) {
V_33 = F_11 ( V_32 ) ;
if ( V_33 < 0 )
goto error;
}
V_62 = V_18 -> V_65 +
F_15 ( V_18 -> V_27 ) ;
if ( F_16 ( V_66 , V_62 ) || ! V_18 -> V_64 ) {
F_17 ( & V_2 -> V_32 , L_1 ) ;
V_18 -> V_64 = false ;
V_33 = F_3 ( V_2 , V_67 ) ;
if ( V_33 < 0 )
goto error;
V_18 -> V_35 [ V_68 ] = V_33 ;
V_33 = F_3 ( V_2 , V_69 ) ;
if ( V_33 < 0 )
goto error;
V_18 -> V_35 [ V_70 ] = V_33 ;
if ( V_18 -> V_71 ) {
V_33 = F_6 ( V_2 , V_72 ,
V_18 -> V_71 ) ;
if ( V_33 < 0 )
goto error;
V_18 -> V_42 [ V_73 ] = V_33 ;
} else {
V_33 = F_3 ( V_2 , V_72 ) ;
if ( V_33 < 0 )
goto error;
V_18 -> V_42 [ V_73 ] = V_33 << 8 ;
}
V_33 = F_6 ( V_2 , V_74 ,
V_75 ) ;
if ( V_33 < 0 )
goto error;
V_18 -> V_42 [ V_76 ] = V_33 ;
V_33 = F_3 ( V_2 , V_77 ) ;
if ( V_33 < 0 )
goto error;
V_18 -> V_78 = V_33 ;
if ( V_18 -> V_21 == V_22 ) {
V_33 = F_7 ( V_2 , V_18 , 1 ) ;
if ( V_33 < 0 )
goto error;
V_33 = F_6 ( V_2 , V_74 ,
V_75 ) ;
if ( V_33 < 0 )
goto error;
V_18 -> V_42 [ V_79 ] = V_33 ;
F_7 ( V_2 , V_18 , 0 ) ;
V_33 = F_3 ( V_2 , V_80 ) ;
if ( V_33 < 0 )
goto error;
V_18 -> V_78 |= V_33 << 8 ;
}
if ( ! ( V_18 -> V_81 & 0x80 ) &&
! ( V_18 -> V_78 & V_18 -> V_82 ) ) {
V_33 = F_3 ( V_2 , V_23 ) ;
if ( V_33 < 0 )
goto error;
if ( V_33 & 0x80 ) {
F_17 ( & V_2 -> V_32 , L_2 ) ;
F_8 ( V_2 ,
V_24 ,
V_33 & ~ 0x80 ) ;
}
}
V_18 -> V_65 = V_66 ;
V_18 -> V_64 = true ;
}
error:
F_18 ( & V_18 -> V_63 ) ;
if ( V_33 < 0 )
return F_19 ( V_33 ) ;
return V_18 ;
}
static inline int F_20 ( T_3 V_33 )
{
return V_33 * 1000 ;
}
static inline int F_21 ( T_2 V_33 )
{
return V_33 * 1000 ;
}
static inline int F_22 ( T_4 V_33 )
{
return V_33 / 32 * 125 ;
}
static inline int F_23 ( T_5 V_33 )
{
return V_33 / 32 * 125 ;
}
static T_3 F_24 ( long V_33 )
{
if ( V_33 <= - 128000 )
return - 128 ;
if ( V_33 >= 127000 )
return 127 ;
if ( V_33 < 0 )
return ( V_33 - 500 ) / 1000 ;
return ( V_33 + 500 ) / 1000 ;
}
static T_2 F_25 ( long V_33 )
{
if ( V_33 <= 0 )
return 0 ;
if ( V_33 >= 255000 )
return 255 ;
return ( V_33 + 500 ) / 1000 ;
}
static T_4 F_26 ( long V_33 )
{
if ( V_33 <= - 128000 )
return 0x8000 ;
if ( V_33 >= 127875 )
return 0x7FE0 ;
if ( V_33 < 0 )
return ( V_33 - 62 ) / 125 * 32 ;
return ( V_33 + 62 ) / 125 * 32 ;
}
static T_2 F_27 ( long V_33 )
{
if ( V_33 <= 0 )
return 0 ;
if ( V_33 >= 30500 )
return 31 ;
return ( V_33 + 500 ) / 1000 ;
}
static inline int F_28 ( struct V_17 * V_18 , T_2 V_33 )
{
if ( V_18 -> V_6 & V_83 )
return ( V_33 - 64 ) * 1000 ;
return F_20 ( V_33 ) ;
}
static inline int F_29 ( struct V_17 * V_18 , T_5 V_33 )
{
if ( V_18 -> V_6 & V_83 )
return ( V_33 - 0x4000 ) / 64 * 250 ;
return F_22 ( V_33 ) ;
}
static T_2 F_30 ( struct V_17 * V_18 , long V_33 )
{
if ( V_18 -> V_6 & V_83 ) {
if ( V_33 <= - 64000 )
return 0 ;
if ( V_33 >= 191000 )
return 0xFF ;
return ( V_33 + 500 + 64000 ) / 1000 ;
}
if ( V_33 <= 0 )
return 0 ;
if ( V_33 >= 127000 )
return 127 ;
return ( V_33 + 500 ) / 1000 ;
}
static T_5 F_31 ( struct V_17 * V_18 , long V_33 )
{
if ( V_18 -> V_6 & V_83 ) {
if ( V_33 <= - 64000 )
return 0 ;
if ( V_33 >= 191750 )
return 0xFFC0 ;
return ( V_33 + 64000 + 125 ) / 250 * 64 ;
}
if ( V_33 <= 0 )
return 0 ;
if ( V_33 >= 127750 )
return 0x7FC0 ;
return ( V_33 + 125 ) / 250 * 64 ;
}
static T_6 F_32 ( struct V_31 * V_32 , struct V_84 * V_85 ,
char * V_86 )
{
struct V_87 * V_88 = F_33 ( V_85 ) ;
struct V_17 * V_18 = F_13 ( V_32 ) ;
int V_89 ;
if ( F_34 ( V_18 ) )
return F_35 ( V_18 ) ;
if ( V_18 -> V_21 == V_90 || V_18 -> V_21 == V_91 )
V_89 = F_28 ( V_18 , V_18 -> V_35 [ V_88 -> V_92 ] ) ;
else if ( V_18 -> V_21 == V_93 )
V_89 = F_21 ( V_18 -> V_35 [ V_88 -> V_92 ] ) ;
else
V_89 = F_20 ( V_18 -> V_35 [ V_88 -> V_92 ] ) ;
if ( V_18 -> V_21 == V_94 && V_88 -> V_92 == 3 )
V_89 += 16000 ;
return sprintf ( V_86 , L_3 , V_89 ) ;
}
static T_6 F_36 ( struct V_31 * V_32 , struct V_84 * V_85 ,
const char * V_86 , T_7 V_95 )
{
static const T_2 V_10 [ V_96 ] = {
V_97 ,
V_98 ,
V_99 ,
V_100 ,
V_101 ,
V_102 ,
V_100 ,
V_102 ,
} ;
struct V_87 * V_88 = F_33 ( V_85 ) ;
struct V_17 * V_18 = F_12 ( V_32 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
int V_103 = V_88 -> V_92 ;
long V_33 ;
int V_11 ;
V_11 = F_37 ( V_86 , 10 , & V_33 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_18 -> V_21 == V_94 && V_88 -> V_92 == 3 )
V_33 -= 16000 ;
F_14 ( & V_18 -> V_63 ) ;
if ( V_18 -> V_21 == V_90 || V_18 -> V_21 == V_91 )
V_18 -> V_35 [ V_103 ] = F_30 ( V_18 , V_33 ) ;
else if ( V_18 -> V_21 == V_93 )
V_18 -> V_35 [ V_103 ] = F_25 ( V_33 ) ;
else
V_18 -> V_35 [ V_103 ] = F_24 ( V_33 ) ;
F_7 ( V_2 , V_18 , V_103 >= 6 ) ;
F_8 ( V_2 , V_10 [ V_103 ] , V_18 -> V_35 [ V_103 ] ) ;
F_7 ( V_2 , V_18 , 0 ) ;
F_18 ( & V_18 -> V_63 ) ;
return V_95 ;
}
static T_6 F_38 ( struct V_31 * V_32 , struct V_84 * V_85 ,
char * V_86 )
{
struct V_104 * V_88 = F_39 ( V_85 ) ;
struct V_17 * V_18 = F_13 ( V_32 ) ;
int V_89 ;
if ( F_34 ( V_18 ) )
return F_35 ( V_18 ) ;
if ( V_18 -> V_21 == V_90 || V_18 -> V_21 == V_91 )
V_89 = F_29 ( V_18 , V_18 -> V_42 [ V_88 -> V_92 ] ) ;
else if ( V_18 -> V_21 == V_93 )
V_89 = F_23 ( V_18 -> V_42 [ V_88 -> V_92 ] ) ;
else
V_89 = F_22 ( V_18 -> V_42 [ V_88 -> V_92 ] ) ;
if ( V_18 -> V_21 == V_94 && V_88 -> V_92 <= 2 )
V_89 += 16000 ;
return sprintf ( V_86 , L_3 , V_89 ) ;
}
static T_6 F_40 ( struct V_31 * V_32 , struct V_84 * V_85 ,
const char * V_86 , T_7 V_95 )
{
struct {
T_2 V_105 ;
T_2 V_106 ;
int V_19 ;
} V_10 [ 5 ] = {
{ V_107 , V_108 , 0 } ,
{ V_109 , V_110 , 0 } ,
{ V_111 , V_112 , 0 } ,
{ V_107 , V_108 , 1 } ,
{ V_109 , V_110 , 1 }
} ;
struct V_104 * V_88 = F_39 ( V_85 ) ;
struct V_17 * V_18 = F_12 ( V_32 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
int V_103 = V_88 -> V_103 ;
int V_92 = V_88 -> V_92 ;
long V_33 ;
int V_11 ;
V_11 = F_37 ( V_86 , 10 , & V_33 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_18 -> V_21 == V_94 && V_92 <= 2 )
V_33 -= 16000 ;
F_14 ( & V_18 -> V_63 ) ;
if ( V_18 -> V_21 == V_90 || V_18 -> V_21 == V_91 )
V_18 -> V_42 [ V_92 ] = F_31 ( V_18 , V_33 ) ;
else if ( V_18 -> V_21 == V_93 )
V_18 -> V_42 [ V_92 ] = F_25 ( V_33 ) << 8 ;
else if ( V_18 -> V_6 & V_44 )
V_18 -> V_42 [ V_92 ] = F_26 ( V_33 ) ;
else
V_18 -> V_42 [ V_92 ] = F_24 ( V_33 ) << 8 ;
F_7 ( V_2 , V_18 , V_10 [ V_103 ] . V_19 ) ;
F_8 ( V_2 , V_10 [ V_103 ] . V_105 ,
V_18 -> V_42 [ V_92 ] >> 8 ) ;
if ( V_18 -> V_6 & V_44 )
F_8 ( V_2 , V_10 [ V_103 ] . V_106 ,
V_18 -> V_42 [ V_92 ] & 0xff ) ;
F_7 ( V_2 , V_18 , 0 ) ;
F_18 ( & V_18 -> V_63 ) ;
return V_95 ;
}
static T_6 F_41 ( struct V_31 * V_32 ,
struct V_84 * V_85 ,
char * V_86 )
{
struct V_87 * V_88 = F_33 ( V_85 ) ;
struct V_17 * V_18 = F_13 ( V_32 ) ;
int V_89 ;
if ( F_34 ( V_18 ) )
return F_35 ( V_18 ) ;
if ( V_18 -> V_21 == V_90 || V_18 -> V_21 == V_91 )
V_89 = F_28 ( V_18 , V_18 -> V_35 [ V_88 -> V_92 ] ) ;
else if ( V_18 -> V_21 == V_93 )
V_89 = F_21 ( V_18 -> V_35 [ V_88 -> V_92 ] ) ;
else
V_89 = F_20 ( V_18 -> V_35 [ V_88 -> V_92 ] ) ;
if ( V_18 -> V_21 == V_94 && V_88 -> V_92 == 3 )
V_89 += 16000 ;
return sprintf ( V_86 , L_3 , V_89 - F_20 ( V_18 -> V_40 ) ) ;
}
static T_6 F_42 ( struct V_31 * V_32 , struct V_84 * V_113 ,
const char * V_86 , T_7 V_95 )
{
struct V_17 * V_18 = F_12 ( V_32 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
long V_33 ;
int V_11 ;
int V_89 ;
V_11 = F_37 ( V_86 , 10 , & V_33 ) ;
if ( V_11 < 0 )
return V_11 ;
F_14 ( & V_18 -> V_63 ) ;
if ( V_18 -> V_21 == V_90 || V_18 -> V_21 == V_91 )
V_89 = F_28 ( V_18 , V_18 -> V_35 [ V_36 ] ) ;
else if ( V_18 -> V_21 == V_93 )
V_89 = F_21 ( V_18 -> V_35 [ V_36 ] ) ;
else
V_89 = F_20 ( V_18 -> V_35 [ V_36 ] ) ;
V_18 -> V_40 = F_27 ( V_89 - V_33 ) ;
F_8 ( V_2 , V_114 ,
V_18 -> V_40 ) ;
F_18 ( & V_18 -> V_63 ) ;
return V_95 ;
}
static T_6 F_43 ( struct V_31 * V_32 , struct V_84 * V_113 ,
char * V_86 )
{
struct V_17 * V_18 = F_13 ( V_32 ) ;
if ( F_34 ( V_18 ) )
return F_35 ( V_18 ) ;
return sprintf ( V_86 , L_3 , V_18 -> V_78 ) ;
}
static T_6 F_44 ( struct V_31 * V_32 , struct V_84
* V_85 , char * V_86 )
{
struct V_87 * V_88 = F_33 ( V_85 ) ;
struct V_17 * V_18 = F_13 ( V_32 ) ;
int V_115 = V_88 -> V_92 ;
if ( F_34 ( V_18 ) )
return F_35 ( V_18 ) ;
return sprintf ( V_86 , L_3 , ( V_18 -> V_78 >> V_115 ) & 1 ) ;
}
static T_6 F_45 ( struct V_31 * V_32 ,
struct V_84 * V_88 , char * V_86 )
{
struct V_17 * V_18 = F_12 ( V_32 ) ;
return sprintf ( V_86 , L_4 , V_18 -> V_27 ) ;
}
static T_6 F_46 ( struct V_31 * V_32 ,
struct V_84 * V_88 ,
const char * V_86 , T_7 V_95 )
{
struct V_17 * V_18 = F_12 ( V_32 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
unsigned long V_33 ;
int V_11 ;
V_11 = F_47 ( V_86 , 10 , & V_33 ) ;
if ( V_11 )
return V_11 ;
F_14 ( & V_18 -> V_63 ) ;
F_9 ( V_2 , V_18 , F_48 ( V_33 , 0 , 100000 ) ) ;
F_18 ( & V_18 -> V_63 ) ;
return V_95 ;
}
static T_6 F_49 ( struct V_31 * V_32 , struct V_84 * V_113 ,
char * V_86 )
{
struct V_1 * V_2 = F_50 ( V_32 ) ;
return sprintf ( V_86 , L_3 , ! ! ( V_2 -> V_6 & V_7 ) ) ;
}
static T_6 F_51 ( struct V_31 * V_32 , struct V_84 * V_113 ,
const char * V_86 , T_7 V_95 )
{
struct V_1 * V_2 = F_50 ( V_32 ) ;
long V_33 ;
int V_11 ;
V_11 = F_37 ( V_86 , 10 , & V_33 ) ;
if ( V_11 < 0 )
return V_11 ;
switch ( V_33 ) {
case 0 :
V_2 -> V_6 &= ~ V_7 ;
break;
case 1 :
V_2 -> V_6 |= V_7 ;
break;
default:
return - V_116 ;
}
return V_95 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_117 * V_118 )
{
struct V_119 * V_4 = V_2 -> V_4 ;
int V_120 = V_2 -> V_5 ;
const char * V_121 = NULL ;
int V_122 , V_123 , V_124 , V_125 , V_126 ;
if ( ! F_53 ( V_4 , V_127 ) )
return - V_128 ;
V_122 = F_5 ( V_2 , V_129 ) ;
V_123 = F_5 ( V_2 , V_130 ) ;
V_124 = F_5 ( V_2 , V_23 ) ;
V_126 = F_5 ( V_2 , V_131 ) ;
if ( V_122 < 0 || V_123 < 0 || V_124 < 0 || V_126 < 0 )
return - V_128 ;
if ( V_122 == 0x01 || V_122 == 0x5C || V_122 == 0x41 ) {
V_125 = F_5 ( V_2 , V_132 ) ;
if ( V_125 < 0 )
return - V_128 ;
} else
V_125 = 0 ;
if ( ( V_120 == 0x4C || V_120 == 0x4D )
&& V_122 == 0x01 ) {
if ( ( V_124 & 0x2A ) == 0x00
&& ( V_125 & 0xF8 ) == 0x00
&& V_126 <= 0x09 ) {
if ( V_120 == 0x4C
&& ( V_123 & 0xF0 ) == 0x20 ) {
V_121 = L_5 ;
} else
if ( ( V_123 & 0xF0 ) == 0x30 ) {
V_121 = L_6 ;
F_54 ( & V_4 -> V_32 ,
L_7 ,
V_120 ) ;
F_54 ( & V_4 -> V_32 ,
L_8
L_9
L_10 ) ;
} else
if ( V_120 == 0x4C
&& ( V_123 & 0xF0 ) == 0x10 ) {
V_121 = L_11 ;
}
}
} else
if ( ( V_120 == 0x4C || V_120 == 0x4D )
&& V_122 == 0x41 ) {
if ( ( V_123 & 0xF0 ) == 0x40
&& ( V_124 & 0x3F ) == 0x00
&& V_126 <= 0x0A ) {
V_121 = L_12 ;
if ( F_53 ( V_4 ,
V_133 ) )
V_118 -> V_6 |= V_7 ;
} else
if ( V_123 == 0x51
&& ( V_124 & 0x1B ) == 0x00
&& V_126 <= 0x0A ) {
V_121 = L_13 ;
} else
if ( V_123 == 0x57
&& ( V_124 & 0x1B ) == 0x00
&& V_126 <= 0x0A ) {
V_121 = L_14 ;
}
} else
if ( V_122 == 0x4D ) {
int V_134 , V_135 , V_136 ;
V_134 = F_5 ( V_2 ,
V_56 ) ;
V_122 = F_5 ( V_2 ,
V_129 ) ;
V_135 = F_5 ( V_2 ,
V_56 ) ;
V_136 = F_5 ( V_2 ,
V_80 ) ;
if ( V_134 < 0 || V_122 < 0 || V_135 < 0 || V_136 < 0 )
return - V_128 ;
if ( V_123 == V_122
&& ( V_120 == 0x4C || V_120 == 0x4D || V_120 == 0x4E )
&& ( V_124 & 0x1F ) == ( V_122 & 0x0F )
&& V_126 <= 0x09 ) {
if ( V_120 == 0x4C )
V_121 = L_15 ;
else
V_121 = L_16 ;
} else
if ( V_123 == 0x01
&& ( V_124 & 0x10 ) == 0x00
&& ( V_136 & 0x01 ) == 0x00
&& V_134 == V_135
&& V_126 <= 0x07 ) {
V_121 = L_17 ;
} else
if ( V_123 == 0x01
&& ( V_124 & 0x03 ) == 0x00
&& V_126 <= 0x07 ) {
V_121 = L_18 ;
} else
if ( V_123 == 0x59
&& ( V_124 & 0x3f ) == 0x00
&& V_126 <= 0x07 ) {
V_121 = L_19 ;
}
} else
if ( V_120 == 0x4C
&& V_122 == 0x5C ) {
if ( ( V_124 & 0x2A ) == 0x00
&& ( V_125 & 0xF8 ) == 0x00 ) {
if ( V_123 == 0x01
&& V_126 <= 0x09 ) {
V_121 = L_20 ;
} else
if ( ( V_123 & 0xFE ) == 0x10
&& V_126 <= 0x08 ) {
V_121 = L_20 ;
}
}
} else
if ( V_120 >= 0x48 && V_120 <= 0x4F
&& V_122 == 0xA1 ) {
if ( V_123 == 0x00
&& ( V_124 & 0x2A ) == 0x00
&& ( V_125 & 0xFE ) == 0x00
&& V_126 <= 0x09 ) {
V_121 = L_21 ;
}
} else
if ( ( V_120 == 0x4C || V_120 == 0x4D )
&& V_122 == 0x47 ) {
if ( V_123 == 0x01
&& ( V_124 & 0x3F ) == 0x00
&& V_126 <= 0x08 )
V_121 = L_22 ;
} else
if ( V_120 == 0x4C
&& V_122 == 0x55 ) {
int V_137 ;
V_137 = F_5 ( V_2 ,
V_138 ) ;
if ( V_123 == 0x00
&& ( V_124 & 0x1B ) == 0x00
&& V_126 <= 0x09
&& ( V_137 & 0x0F ) == 0x00 )
V_121 = L_23 ;
}
if ( ! V_121 ) {
F_17 ( & V_4 -> V_32 ,
L_24
L_25 , V_120 , V_122 , V_123 ) ;
return - V_128 ;
}
F_55 ( V_118 -> type , V_121 , V_139 ) ;
return 0 ;
}
static void F_56 ( void * V_140 )
{
struct V_17 * V_18 = V_140 ;
struct V_1 * V_2 = V_18 -> V_2 ;
F_8 ( V_2 , V_30 ,
V_18 -> V_141 ) ;
F_8 ( V_2 , V_24 ,
V_18 -> V_81 ) ;
}
static int F_57 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
int V_20 , V_126 ;
V_126 = F_3 ( V_2 , V_131 ) ;
if ( V_126 < 0 )
return V_126 ;
V_18 -> V_141 = V_126 ;
F_9 ( V_2 , V_18 , 500 ) ;
V_20 = F_3 ( V_2 , V_23 ) ;
if ( V_20 < 0 )
return V_20 ;
V_18 -> V_81 = V_20 ;
if ( V_18 -> V_21 == V_90 || V_18 -> V_21 == V_91 ) {
if ( V_20 & 0x04 )
V_18 -> V_6 |= V_83 ;
}
if ( V_18 -> V_21 == V_142 )
V_20 |= 0x18 ;
if ( V_18 -> V_21 == V_22 )
V_20 &= ~ 0x08 ;
V_20 &= 0xBF ;
if ( V_20 != V_18 -> V_81 )
F_8 ( V_2 , V_24 , V_20 ) ;
return F_58 ( & V_2 -> V_32 , F_56 , V_18 ) ;
}
static bool F_59 ( struct V_1 * V_2 , T_5 * V_143 )
{
struct V_17 * V_18 = F_60 ( V_2 ) ;
int V_144 , V_145 = 0 ;
V_144 = F_3 ( V_2 , V_77 ) ;
if ( V_144 < 0 )
return false ;
if ( V_18 -> V_21 == V_22 ) {
V_145 = F_3 ( V_2 , V_80 ) ;
if ( V_145 < 0 )
return false ;
}
* V_143 = V_144 | ( V_145 << 8 ) ;
if ( ( V_144 & 0x7f ) == 0 && ( V_145 & 0xfe ) == 0 )
return false ;
if ( ( V_144 & ( V_146 | V_147 | V_148 ) ) ||
( V_145 & V_149 ) )
F_61 ( & V_2 -> V_32 ,
L_26 , 1 ) ;
if ( ( V_144 & ( V_150 | V_151 | V_152 ) ) ||
( V_145 & V_153 ) )
F_61 ( & V_2 -> V_32 ,
L_26 , 2 ) ;
if ( V_144 & V_154 )
F_61 ( & V_2 -> V_32 ,
L_27 , 2 ) ;
if ( V_145 & ( V_155 | V_156 |
V_157 | V_158 ) )
F_61 ( & V_2 -> V_32 ,
L_26 , 3 ) ;
if ( V_145 & V_159 )
F_61 ( & V_2 -> V_32 ,
L_27 , 3 ) ;
return true ;
}
static T_8 F_62 ( int V_160 , void * V_161 )
{
struct V_1 * V_2 = V_161 ;
T_5 V_143 ;
if ( F_59 ( V_2 , & V_143 ) )
return V_162 ;
else
return V_163 ;
}
static void F_63 ( void * V_32 )
{
F_64 ( V_32 , & V_164 ) ;
}
static void F_65 ( void * V_165 )
{
F_66 ( V_165 ) ;
}
static int F_67 ( struct V_1 * V_2 ,
const struct V_166 * V_167 )
{
struct V_31 * V_32 = & V_2 -> V_32 ;
struct V_119 * V_4 = F_68 ( V_32 -> V_168 ) ;
struct V_17 * V_18 ;
struct V_165 * V_165 ;
struct V_31 * V_169 ;
int V_170 = 0 ;
int V_11 ;
V_165 = F_69 ( V_32 , L_28 ) ;
if ( F_34 ( V_165 ) )
return F_35 ( V_165 ) ;
V_11 = F_70 ( V_165 ) ;
if ( V_11 < 0 ) {
F_71 ( V_32 , L_29 , V_11 ) ;
return V_11 ;
}
V_11 = F_58 ( V_32 , F_65 , V_165 ) ;
if ( V_11 )
return V_11 ;
V_18 = F_72 ( V_32 , sizeof( struct V_17 ) , V_171 ) ;
if ( ! V_18 )
return - V_172 ;
V_18 -> V_2 = V_2 ;
F_73 ( V_2 , V_18 ) ;
F_74 ( & V_18 -> V_63 ) ;
V_18 -> V_21 = V_167 -> V_173 ;
if ( V_18 -> V_21 == V_174 ) {
if ( ! F_53 ( V_4 , V_133 ) )
V_2 -> V_6 &= ~ V_7 ;
}
V_18 -> V_82 = V_175 [ V_18 -> V_21 ] . V_82 ;
V_18 -> V_6 = V_175 [ V_18 -> V_21 ] . V_6 ;
V_18 -> V_71 = V_175 [ V_18 -> V_21 ] . V_71 ;
V_18 -> V_29 = V_175 [ V_18 -> V_21 ] . V_29 ;
V_11 = F_57 ( V_2 , V_18 ) ;
if ( V_11 < 0 ) {
F_71 ( V_32 , L_30 ) ;
return V_11 ;
}
V_18 -> V_170 [ V_170 ++ ] = & V_176 ;
if ( V_18 -> V_6 & V_49 )
V_18 -> V_170 [ V_170 ++ ] = & V_177 ;
if ( V_18 -> V_6 & V_53 )
V_18 -> V_170 [ V_170 ++ ] = & V_178 ;
if ( V_18 -> V_6 & V_179 )
V_18 -> V_170 [ V_170 ++ ] = & V_180 ;
if ( V_18 -> V_6 & V_181 )
V_18 -> V_170 [ V_170 ++ ] = & V_182 ;
if ( V_2 -> V_6 & V_7 ) {
V_11 = F_75 ( V_32 , & V_164 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_58 ( V_32 , F_63 , V_32 ) ;
if ( V_11 )
return V_11 ;
}
V_169 = F_76 ( V_32 , V_2 -> V_121 ,
V_18 , V_18 -> V_170 ) ;
if ( F_34 ( V_169 ) )
return F_35 ( V_169 ) ;
if ( V_2 -> V_160 ) {
F_17 ( V_32 , L_31 , V_2 -> V_160 ) ;
V_11 = F_77 ( V_32 , V_2 -> V_160 ,
NULL , F_62 ,
V_183 | V_184 ,
L_5 , V_2 ) ;
if ( V_11 < 0 ) {
F_71 ( V_32 , L_32 , V_2 -> V_160 ) ;
return V_11 ;
}
}
return 0 ;
}
static void F_78 ( struct V_1 * V_2 , enum V_185 type ,
unsigned int V_186 )
{
T_5 V_78 ;
if ( type != V_187 )
return;
if ( F_59 ( V_2 , & V_78 ) ) {
struct V_17 * V_18 = F_60 ( V_2 ) ;
if ( ( V_18 -> V_6 & V_188 ) &&
( V_78 & V_18 -> V_82 ) ) {
int V_20 ;
F_17 ( & V_2 -> V_32 , L_33 ) ;
V_20 = F_3 ( V_2 , V_23 ) ;
if ( V_20 >= 0 )
F_8 ( V_2 ,
V_24 ,
V_20 | 0x80 ) ;
}
} else {
F_54 ( & V_2 -> V_32 , L_34 ) ;
}
}
