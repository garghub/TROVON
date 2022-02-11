static inline int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_2 -> V_4 )
return F_2 ( ( V_5 ) V_2 -> V_6 [ V_3 ] ) ;
return F_2 ( V_2 -> V_6 [ V_3 ] ) ;
}
static inline int F_3 ( struct V_1 * V_2 , int V_3 )
{
return V_2 -> V_6 [ V_3 ] * ( V_2 -> V_7 ? 500 : 1000 ) ;
}
static inline int F_4 ( struct V_1 * V_2 , long V_8 )
{
V_8 -= V_2 -> V_9 ;
if ( V_2 -> V_7 )
return F_5 ( F_6 ( V_8 , 0 , 127500 ) , 500 ) ;
else
return F_5 ( F_6 ( V_8 , 0 , 127000 ) , 1000 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_12 ;
if ( F_8 ( V_13 , V_2 -> V_14 + 5 * V_15 ) ||
! V_2 -> V_16 ) {
for ( V_12 = 0 ; V_12 < V_2 -> V_17 ; V_12 ++ ) {
V_2 -> V_18 [ 1 + V_12 ] = F_9 ( V_11 ,
F_10 ( V_12 ) ) ;
V_2 -> V_6 [ 3 + V_12 ] = F_9 ( V_11 ,
F_11 ( V_12 ) ) ;
}
V_2 -> V_19 = F_9 ( V_11 ,
V_20 ) ;
V_2 -> V_14 = V_13 ;
V_2 -> V_16 = 1 ;
}
}
static struct V_1 * F_12 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_13 ( V_22 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned long V_23 ;
F_14 ( & V_2 -> V_24 ) ;
V_23 = V_2 -> V_25 +
F_15 ( V_2 -> V_26 ) ;
if ( F_8 ( V_13 , V_23 ) || ! V_2 -> V_27 ) {
if ( V_2 -> V_28 & 0x04 ) {
V_2 -> V_29 [ 0 ] = F_9 ( V_11 ,
V_30 ) & 0xFC ;
V_2 -> V_29 [ 0 ] |= F_9 ( V_11 ,
V_31 ) << 8 ;
V_2 -> V_29 [ 1 ] = ( F_9 ( V_11 ,
V_32 ) & 0xFC )
| ( F_9 ( V_11 ,
V_33 ) << 8 ) ;
}
V_2 -> V_34 = F_9 ( V_11 ,
V_35 ) ;
if ( V_2 -> V_34 == 0 )
V_2 -> V_34 = 1 ;
V_2 -> V_18 [ 0 ] = F_9 ( V_11 ,
V_36 ) ;
V_2 -> V_6 [ 0 ] = F_9 ( V_11 ,
V_37 ) ;
V_2 -> V_6 [ 1 ] = F_9 ( V_11 ,
V_38 ) ;
V_2 -> V_39 [ 0 ] = F_9 ( V_11 ,
V_40 ) << 8 ;
V_2 -> V_39 [ 0 ] |= F_9 ( V_11 ,
V_41 ) ;
V_2 -> V_39 [ 1 ] = ( F_9 ( V_11 ,
V_42 ) << 8 )
| F_9 ( V_11 ,
V_43 ) ;
V_2 -> V_39 [ 2 ] = ( F_9 ( V_11 ,
V_44 ) << 8 )
| F_9 ( V_11 ,
V_45 ) ;
V_2 -> V_39 [ 3 ] = ( F_9 ( V_11 ,
V_46 ) << 8 )
| F_9 ( V_11 ,
V_47 ) ;
if ( V_2 -> V_48 == V_49 )
V_2 -> V_50 = ( F_9 ( V_11 ,
V_51 ) << 8 )
| F_9 ( V_11 ,
V_52 ) ;
V_2 -> V_6 [ 2 ] = F_9 ( V_11 ,
V_53 ) ;
V_2 -> V_54 = F_9 ( V_11 ,
V_55 ) ;
V_2 -> V_56 = F_9 ( V_11 ,
V_57 ) & 0x7F ;
V_2 -> V_25 = V_13 ;
V_2 -> V_27 = 1 ;
}
F_7 ( V_2 ) ;
F_16 ( & V_2 -> V_24 ) ;
return V_2 ;
}
static int F_17 ( struct V_21 * V_22 , struct V_1 * V_2 )
{
int V_12 ;
F_14 ( & V_2 -> V_24 ) ;
F_7 ( V_2 ) ;
for ( V_12 = 1 ; V_12 < V_2 -> V_17 ; V_12 ++ ) {
if ( V_2 -> V_18 [ 1 + V_12 - 1 ] > V_2 -> V_18 [ 1 + V_12 ]
|| V_2 -> V_6 [ 3 + V_12 - 1 ] > V_2 -> V_6 [ 3 + V_12 ] ) {
F_18 ( V_22 ,
L_1 ,
V_12 , V_12 + 1 ) ;
break;
}
}
F_16 ( & V_2 -> V_24 ) ;
return V_12 == V_2 -> V_17 ? 0 : 1 ;
}
static T_1 F_19 ( struct V_21 * V_22 , struct V_58 * V_59 ,
char * V_60 )
{
struct V_61 * V_62 = F_20 ( V_59 ) ;
struct V_1 * V_2 = F_12 ( V_22 ) ;
return sprintf ( V_60 , L_2 , F_21 ( V_2 -> V_29 [ V_62 -> V_63 ] ) ) ;
}
static T_1 F_22 ( struct V_21 * V_22 , struct V_58 * V_64 ,
const char * V_60 , T_2 V_65 )
{
struct V_1 * V_2 = F_13 ( V_22 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned long V_8 ;
int V_66 ;
V_66 = F_23 ( V_60 , 10 , & V_8 ) ;
if ( V_66 )
return V_66 ;
F_14 ( & V_2 -> V_24 ) ;
V_2 -> V_29 [ 1 ] = F_24 ( V_8 ) ;
F_25 ( V_11 , V_32 ,
V_2 -> V_29 [ 1 ] & 0xFF ) ;
F_25 ( V_11 , V_33 ,
V_2 -> V_29 [ 1 ] >> 8 ) ;
F_16 ( & V_2 -> V_24 ) ;
return V_65 ;
}
static T_1 F_26 ( struct V_21 * V_22 , struct V_58 * V_59 ,
char * V_60 )
{
struct V_61 * V_62 = F_20 ( V_59 ) ;
struct V_1 * V_2 = F_12 ( V_22 ) ;
int V_3 = V_62 -> V_63 ;
int V_67 ;
if ( V_2 -> V_68 )
V_67 = V_2 -> V_18 [ V_3 ] ;
else
V_67 = V_2 -> V_18 [ V_3 ] >= 2 * V_2 -> V_34 ?
255 : ( V_2 -> V_18 [ V_3 ] * 255 + V_2 -> V_34 ) /
( 2 * V_2 -> V_34 ) ;
return sprintf ( V_60 , L_2 , V_67 ) ;
}
static T_1 F_27 ( struct V_21 * V_22 , struct V_58 * V_59 ,
const char * V_60 , T_2 V_65 )
{
struct V_61 * V_62 = F_20 ( V_59 ) ;
struct V_1 * V_2 = F_13 ( V_22 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_3 = V_62 -> V_63 ;
unsigned long V_8 ;
int V_66 ;
V_5 V_69 ;
if ( ! ( V_2 -> V_70 & 0x20 ) )
return - V_71 ;
V_66 = F_23 ( V_60 , 10 , & V_8 ) ;
if ( V_66 )
return V_66 ;
V_69 = V_3 ? F_10 ( V_3 - 1 ) : V_36 ;
V_8 = F_6 ( V_8 , 0 , 255 ) ;
F_14 ( & V_2 -> V_24 ) ;
V_2 -> V_18 [ V_3 ] = V_2 -> V_68 ? V_8 :
( V_8 * V_2 -> V_34 * 2 + 127 ) / 255 ;
F_25 ( V_11 , V_69 , V_2 -> V_18 [ V_3 ] ) ;
F_16 ( & V_2 -> V_24 ) ;
return V_65 ;
}
static T_1 F_28 ( struct V_21 * V_22 ,
struct V_58 * V_64 , char * V_60 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
return sprintf ( V_60 , L_2 , V_2 -> V_70 & 0x20 ? 1 : 2 ) ;
}
static T_1 F_29 ( struct V_21 * V_22 ,
struct V_58 * V_64 ,
const char * V_60 , T_2 V_65 )
{
struct V_1 * V_2 = F_13 ( V_22 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned long V_8 ;
int V_66 ;
V_66 = F_23 ( V_60 , 10 , & V_8 ) ;
if ( V_66 )
return V_66 ;
if ( V_8 < 1 || V_8 > 2 )
return - V_72 ;
if ( V_8 == 2 && F_17 ( V_22 , V_2 ) )
return - V_71 ;
F_14 ( & V_2 -> V_24 ) ;
V_2 -> V_70 = F_9 ( V_11 ,
V_73 ) ;
if ( V_8 == 1 )
V_2 -> V_70 |= 0x20 ;
else
V_2 -> V_70 &= ~ 0x20 ;
F_25 ( V_11 , V_73 ,
V_2 -> V_70 ) ;
F_16 ( & V_2 -> V_24 ) ;
return V_65 ;
}
static T_1 F_30 ( struct V_21 * V_22 ,
struct V_58 * V_59 ,
char * V_60 )
{
struct V_61 * V_62 = F_20 ( V_59 ) ;
struct V_1 * V_2 = F_12 ( V_22 ) ;
return sprintf ( V_60 , L_2 , F_2 ( V_2 -> V_6 [ V_62 -> V_63 ] ) ) ;
}
static T_1 F_31 ( struct V_21 * V_22 ,
struct V_58 * V_59 ,
char * V_60 )
{
struct V_61 * V_62 = F_20 ( V_59 ) ;
struct V_1 * V_2 = F_12 ( V_22 ) ;
return sprintf ( V_60 , L_2 , F_1 ( V_2 , V_62 -> V_63 )
+ V_2 -> V_9 ) ;
}
static T_1 F_32 ( struct V_21 * V_22 ,
struct V_58 * V_59 ,
char * V_60 )
{
struct V_61 * V_62 = F_20 ( V_59 ) ;
struct V_1 * V_2 = F_12 ( V_22 ) ;
return sprintf ( V_60 , L_2 , F_3 ( V_2 , V_62 -> V_63 )
+ V_2 -> V_9 ) ;
}
static T_1 F_33 ( struct V_21 * V_22 , struct V_58 * V_59 ,
const char * V_60 , T_2 V_65 )
{
struct V_61 * V_62 = F_20 ( V_59 ) ;
struct V_1 * V_2 = F_13 ( V_22 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_3 = V_62 -> V_63 ;
long V_8 ;
int V_66 ;
int V_74 ;
V_5 V_69 ;
V_66 = F_34 ( V_60 , 10 , & V_8 ) ;
if ( V_66 )
return V_66 ;
F_14 ( & V_2 -> V_24 ) ;
switch ( V_3 ) {
case 2 :
V_69 = V_53 ;
if ( V_2 -> V_4 )
V_74 = F_35 ( V_8 - V_2 -> V_9 ) ;
else
V_74 = F_36 ( V_8 - V_2 -> V_9 ) ;
break;
case 1 :
V_69 = V_38 ;
V_74 = F_36 ( V_8 ) ;
break;
default:
V_69 = F_11 ( V_3 - 3 ) ;
V_74 = F_4 ( V_2 , V_8 ) ;
}
V_2 -> V_6 [ V_3 ] = V_74 ;
F_25 ( V_11 , V_69 , V_74 ) ;
F_16 ( & V_2 -> V_24 ) ;
return V_65 ;
}
static T_1 F_37 ( struct V_21 * V_22 , struct V_58 * V_59 ,
char * V_60 )
{
struct V_61 * V_62 = F_20 ( V_59 ) ;
struct V_1 * V_2 = F_12 ( V_22 ) ;
int V_3 = V_62 -> V_63 ;
int V_74 ;
if ( ! V_3 ) {
if ( V_2 -> V_50 )
V_74 = F_38 ( V_2 -> V_50 ) ;
else
V_74 = F_38 ( V_2 -> V_39 [ V_3 ] ) ;
} else {
if ( V_2 -> V_4 && V_3 == 2 )
V_74 = F_38 ( ( V_75 ) V_2 -> V_39 [ V_3 ] ) ;
else
V_74 = F_38 ( V_2 -> V_39 [ V_3 ] ) ;
}
return sprintf ( V_60 , L_2 , V_74 + V_2 -> V_9 ) ;
}
static T_1 F_39 ( struct V_21 * V_22 , struct V_58 * V_59 ,
const char * V_60 , T_2 V_65 )
{
static const V_5 V_69 [ 6 ] = {
V_42 ,
V_43 ,
V_44 ,
V_45 ,
V_46 ,
V_47 ,
} ;
struct V_61 * V_62 = F_20 ( V_59 ) ;
struct V_1 * V_2 = F_13 ( V_22 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
long V_8 ;
int V_66 ;
int V_3 = V_62 -> V_63 ;
V_66 = F_34 ( V_60 , 10 , & V_8 ) ;
if ( V_66 )
return V_66 ;
F_14 ( & V_2 -> V_24 ) ;
if ( V_2 -> V_4 && V_3 == 2 )
V_2 -> V_39 [ V_3 ] = F_40 ( V_8 - V_2 -> V_9 ) ;
else
V_2 -> V_39 [ V_3 ] = F_41 ( V_8 - V_2 -> V_9 ) ;
F_25 ( V_11 , V_69 [ ( V_3 - 1 ) * 2 ] ,
V_2 -> V_39 [ V_3 ] >> 8 ) ;
F_25 ( V_11 , V_69 [ ( V_3 - 1 ) * 2 + 1 ] ,
V_2 -> V_39 [ V_3 ] & 0xff ) ;
F_16 ( & V_2 -> V_24 ) ;
return V_65 ;
}
static T_1 F_42 ( struct V_21 * V_22 ,
struct V_58 * V_64 , char * V_60 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
return sprintf ( V_60 , L_2 , F_1 ( V_2 , 2 )
+ V_2 -> V_9
- F_2 ( V_2 -> V_54 ) ) ;
}
static T_1 F_43 ( struct V_21 * V_22 ,
struct V_58 * V_59 , char * V_60 )
{
struct V_61 * V_62 = F_20 ( V_59 ) ;
struct V_1 * V_2 = F_12 ( V_22 ) ;
return sprintf ( V_60 , L_2 , F_3 ( V_2 , V_62 -> V_63 )
+ V_2 -> V_9
- F_2 ( V_2 -> V_19 ) ) ;
}
static T_1 F_44 ( struct V_21 * V_22 ,
struct V_58 * V_64 ,
const char * V_60 , T_2 V_65 )
{
struct V_1 * V_2 = F_13 ( V_22 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
long V_8 ;
int V_66 ;
long V_76 ;
V_66 = F_34 ( V_60 , 10 , & V_8 ) ;
if ( V_66 )
return V_66 ;
F_14 ( & V_2 -> V_24 ) ;
V_76 = F_1 ( V_2 , 2 ) + V_2 -> V_9 - V_8 ;
F_25 ( V_11 , V_55 ,
F_45 ( V_76 ) ) ;
F_16 ( & V_2 -> V_24 ) ;
return V_65 ;
}
static void F_46 ( struct V_1 * V_2 , unsigned int V_77 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int V_26 ;
int V_12 ;
V_77 <<= 6 ;
V_26 = ( 1 << ( V_78 + 6 ) ) * 1000
/ V_2 -> V_79 ;
for ( V_12 = 0 ; V_12 < V_78 ; V_12 ++ , V_26 >>= 1 )
if ( V_77 >= V_26 * 3 / 4 )
break;
F_25 ( V_11 , V_80 , V_12 ) ;
V_2 -> V_26 = F_47 ( V_2 -> V_79 , V_12 ) ;
}
static T_1 F_48 ( struct V_21 * V_22 ,
struct V_58 * V_62 , char * V_60 )
{
struct V_1 * V_2 = F_13 ( V_22 ) ;
return sprintf ( V_60 , L_3 , V_2 -> V_26 ) ;
}
static T_1 F_49 ( struct V_21 * V_22 ,
struct V_58 * V_62 ,
const char * V_60 , T_2 V_65 )
{
struct V_1 * V_2 = F_13 ( V_22 ) ;
unsigned long V_8 ;
int V_66 ;
V_66 = F_23 ( V_60 , 10 , & V_8 ) ;
if ( V_66 )
return V_66 ;
F_14 ( & V_2 -> V_24 ) ;
F_46 ( V_2 , F_6 ( V_8 , 0 , 100000 ) ) ;
F_16 ( & V_2 -> V_24 ) ;
return V_65 ;
}
static T_1 F_50 ( struct V_21 * V_22 , struct V_58 * V_62 ,
char * V_60 )
{
struct V_1 * V_2 = F_13 ( V_22 ) ;
return sprintf ( V_60 , V_2 -> V_81 ? L_4 : L_5 ) ;
}
static T_1 F_51 ( struct V_21 * V_22 , struct V_58 * V_62 ,
const char * V_60 , T_2 V_65 )
{
struct V_1 * V_2 = F_13 ( V_22 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned long V_8 ;
int V_82 ;
V_5 V_69 ;
V_82 = F_23 ( V_60 , 10 , & V_8 ) ;
if ( V_82 < 0 )
return V_82 ;
if ( V_8 != 1 && V_8 != 2 )
return - V_72 ;
F_14 ( & V_2 -> V_24 ) ;
V_2 -> V_81 = V_8 == 1 ;
V_69 = F_9 ( V_11 , V_83 ) & ~ 0x02 ;
F_25 ( V_11 , V_83 ,
V_69 | ( V_2 -> V_81 ? 0x02 : 0x00 ) ) ;
V_2 -> V_27 = 0 ;
F_16 ( & V_2 -> V_24 ) ;
return V_65 ;
}
static T_1 F_52 ( struct V_21 * V_22 , struct V_58 * V_64 ,
char * V_60 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
return sprintf ( V_60 , L_3 , V_2 -> V_56 ) ;
}
static T_1 F_53 ( struct V_21 * V_22 , struct V_58 * V_59 ,
char * V_60 )
{
struct V_61 * V_62 = F_20 ( V_59 ) ;
struct V_1 * V_2 = F_12 ( V_22 ) ;
int V_84 = V_62 -> V_63 ;
return sprintf ( V_60 , L_3 , ( V_2 -> V_56 >> V_84 ) & 1 ) ;
}
static T_3 F_54 ( struct V_85 * V_86 ,
struct V_87 * V_62 , int V_63 )
{
struct V_21 * V_22 = F_55 ( V_86 , struct V_21 , V_86 ) ;
struct V_1 * V_2 = F_13 ( V_22 ) ;
if ( V_62 == & V_88 . V_89 . V_62
&& ( V_2 -> V_48 == V_90 ||
( V_2 -> V_48 == V_49 && ( V_2 -> V_28 & 0x02 ) ) ) )
return V_62 -> V_91 | V_92 ;
return V_62 -> V_91 ;
}
static int F_56 ( struct V_10 * V_11 ,
struct V_93 * V_94 )
{
struct V_95 * V_96 = V_11 -> V_96 ;
V_5 V_97 , V_98 , V_99 , V_100 ;
V_5 V_101 , V_102 ;
int V_103 = V_11 -> V_104 ;
if ( ! F_57 ( V_96 , V_105 ) )
return - V_106 ;
V_97 = F_9 ( V_11 , V_107 ) ;
V_98 = F_9 ( V_11 , V_108 ) ;
V_99 = F_9 ( V_11 , V_109 ) ;
V_100 = F_9 ( V_11 , V_110 ) ;
V_101 = F_9 ( V_11 ,
V_57 ) ;
V_102 = F_9 ( V_11 , V_111 ) ;
if ( V_97 != 0x01
|| ( V_99 & 0x18 ) != 0x00
|| ( V_100 & 0xF8 ) != 0x00
|| ( V_101 & 0x20 ) != 0x00
|| ( V_102 & 0xA4 ) != 0xA4 ) {
F_58 ( & V_96 -> V_22 ,
L_6 ,
V_97 , V_98 ) ;
return - V_106 ;
}
if ( V_98 == 0x41 && V_103 == 0x4c )
F_59 ( V_94 -> type , L_7 , V_112 ) ;
else if ( V_98 == 0x51 && ( V_103 == 0x18 || V_103 == 0x4e ) )
F_59 ( V_94 -> type , L_8 , V_112 ) ;
else if ( V_98 == 0x49 && V_103 == 0x4c )
F_59 ( V_94 -> type , L_9 , V_112 ) ;
else
return - V_106 ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_21 * V_22 = & V_11 -> V_22 ;
V_5 V_113 ;
V_2 -> V_28 = F_9 ( V_11 , V_109 ) ;
V_2 -> V_70 = F_9 ( V_11 ,
V_73 ) ;
if ( V_2 -> V_28 & 0x40 ) {
F_58 ( V_22 , L_10 ) ;
V_2 -> V_28 &= 0xA7 ;
F_25 ( V_11 , V_109 ,
V_2 -> V_28 ) ;
}
if ( V_2 -> V_48 == V_90 )
V_2 -> V_28 |= 0x04 ;
V_2 -> V_34 = F_9 ( V_11 , V_35 ) ;
if ( V_2 -> V_34 == 0 )
V_2 -> V_34 = 1 ;
switch ( V_2 -> V_48 ) {
case V_114 :
case V_90 :
V_2 -> V_79 = V_115 ;
V_2 -> V_17 = 8 ;
break;
case V_49 :
V_2 -> V_79 = V_116 ;
V_2 -> V_17 = 12 ;
V_2 -> V_81
= F_9 ( V_11 ,
V_83 ) & 0x02 ;
break;
}
V_113 = F_9 ( V_11 , V_80 ) ;
if ( F_61 ( V_113 > V_78 ) )
V_113 = V_78 ;
V_2 -> V_26 = F_47 ( V_2 -> V_79 ,
V_113 ) ;
if ( V_2 -> V_48 == V_49 ) {
V_5 V_117
= F_9 ( V_11 ,
V_118 ) ;
if ( V_117 & 0x20 )
V_2 -> V_7 = true ;
if ( ( V_117 & 0x10 )
&& ! ( V_2 -> V_70 & 0x08 ) && V_2 -> V_34 == 8 )
V_2 -> V_68 = true ;
if ( V_117 & 0x08 )
V_2 -> V_4 = true ;
}
if ( V_2 -> V_48 == V_114 )
F_58 ( V_22 , L_11 ,
( V_2 -> V_28 & 0x04 ) ? L_12 :
L_13 ) ;
F_58 ( V_22 , L_14 ,
( V_2 -> V_70 & 0x08 ) ? L_15 : L_16 ,
( ( V_2 -> V_70 & 0x08 ) ? 700 : 180000 ) / V_2 -> V_34 ) ;
F_58 ( V_22 , L_17 ,
( V_2 -> V_70 & 0x10 ) ? L_18 : L_19 ,
( V_2 -> V_70 & 0x20 ) ? L_20 : L_21 ) ;
}
static int F_62 ( struct V_10 * V_11 ,
const struct V_119 * V_120 )
{
struct V_21 * V_22 = & V_11 -> V_22 ;
struct V_21 * V_121 ;
struct V_1 * V_2 ;
int V_122 = 0 ;
V_2 = F_63 ( V_22 , sizeof( struct V_1 ) , V_123 ) ;
if ( ! V_2 )
return - V_124 ;
V_2 -> V_11 = V_11 ;
F_64 ( & V_2 -> V_24 ) ;
V_2 -> V_48 = V_120 -> V_125 ;
if ( V_2 -> V_48 == V_90 )
V_2 -> V_9 = 16000 ;
F_60 ( V_2 ) ;
V_2 -> V_122 [ V_122 ++ ] = & V_126 ;
if ( V_2 -> V_28 & 0x04 )
V_2 -> V_122 [ V_122 ++ ] = & V_127 ;
if ( V_2 -> V_48 == V_49 ) {
V_2 -> V_122 [ V_122 ++ ] = & V_128 ;
V_2 -> V_122 [ V_122 ++ ] = & V_129 ;
}
V_121 = F_65 ( V_22 , V_11 -> V_130 ,
V_2 , V_2 -> V_122 ) ;
return F_66 ( V_121 ) ;
}
