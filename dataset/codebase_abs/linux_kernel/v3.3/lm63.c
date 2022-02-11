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
static T_1 F_4 ( struct V_8 * V_9 , struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_5 ( V_11 ) ;
struct V_1 * V_2 = F_6 ( V_9 ) ;
return sprintf ( V_12 , L_1 , F_7 ( V_2 -> V_15 [ V_14 -> V_16 ] ) ) ;
}
static T_1 F_8 ( struct V_8 * V_9 , struct V_10 * V_17 ,
const char * V_12 , T_2 V_18 )
{
struct V_19 * V_20 = F_9 ( V_9 ) ;
struct V_1 * V_2 = F_10 ( V_20 ) ;
unsigned long V_21 ;
int V_22 ;
V_22 = F_11 ( V_12 , 10 , & V_21 ) ;
if ( V_22 )
return V_22 ;
F_12 ( & V_2 -> V_23 ) ;
V_2 -> V_15 [ 1 ] = F_13 ( V_21 ) ;
F_14 ( V_20 , V_24 ,
V_2 -> V_15 [ 1 ] & 0xFF ) ;
F_14 ( V_20 , V_25 ,
V_2 -> V_15 [ 1 ] >> 8 ) ;
F_15 ( & V_2 -> V_23 ) ;
return V_18 ;
}
static T_1 F_16 ( struct V_8 * V_9 , struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_5 ( V_11 ) ;
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_3 = V_14 -> V_16 ;
int V_26 ;
if ( V_2 -> V_27 )
V_26 = V_2 -> V_28 [ V_3 ] ;
else
V_26 = V_2 -> V_28 [ V_3 ] >= 2 * V_2 -> V_29 ?
255 : ( V_2 -> V_28 [ V_3 ] * 255 + V_2 -> V_29 ) /
( 2 * V_2 -> V_29 ) ;
return sprintf ( V_12 , L_1 , V_26 ) ;
}
static T_1 F_17 ( struct V_8 * V_9 , struct V_10 * V_17 ,
const char * V_12 , T_2 V_18 )
{
struct V_19 * V_20 = F_9 ( V_9 ) ;
struct V_1 * V_2 = F_10 ( V_20 ) ;
unsigned long V_21 ;
int V_22 ;
if ( ! ( V_2 -> V_30 & 0x20 ) )
return - V_31 ;
V_22 = F_11 ( V_12 , 10 , & V_21 ) ;
if ( V_22 )
return V_22 ;
V_21 = F_18 ( V_21 , 0 , 255 ) ;
F_12 ( & V_2 -> V_23 ) ;
V_2 -> V_28 [ 0 ] = V_2 -> V_27 ? V_21 :
( V_21 * V_2 -> V_29 * 2 + 127 ) / 255 ;
F_14 ( V_20 , V_32 , V_2 -> V_28 [ 0 ] ) ;
F_15 ( & V_2 -> V_23 ) ;
return V_18 ;
}
static T_1 F_19 ( struct V_8 * V_9 ,
struct V_10 * V_17 , char * V_12 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return sprintf ( V_12 , L_1 , V_2 -> V_30 & 0x20 ? 1 : 2 ) ;
}
static T_1 F_20 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_5 ( V_11 ) ;
struct V_1 * V_2 = F_6 ( V_9 ) ;
return sprintf ( V_12 , L_1 , F_2 ( V_2 -> V_6 [ V_14 -> V_16 ] ) ) ;
}
static T_1 F_21 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_5 ( V_11 ) ;
struct V_1 * V_2 = F_6 ( V_9 ) ;
return sprintf ( V_12 , L_1 , F_1 ( V_2 , V_14 -> V_16 )
+ V_2 -> V_33 ) ;
}
static T_1 F_22 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_5 ( V_11 ) ;
struct V_1 * V_2 = F_6 ( V_9 ) ;
return sprintf ( V_12 , L_1 , F_3 ( V_2 , V_14 -> V_16 )
+ V_2 -> V_33 ) ;
}
static T_1 F_23 ( struct V_8 * V_9 , struct V_10 * V_11 ,
const char * V_12 , T_2 V_18 )
{
struct V_13 * V_14 = F_5 ( V_11 ) ;
struct V_19 * V_20 = F_9 ( V_9 ) ;
struct V_1 * V_2 = F_10 ( V_20 ) ;
int V_3 = V_14 -> V_16 ;
int V_34 = V_3 == 2 ? V_35 : V_36 ;
long V_21 ;
int V_22 ;
int V_37 ;
V_22 = F_24 ( V_12 , 10 , & V_21 ) ;
if ( V_22 )
return V_22 ;
F_12 ( & V_2 -> V_23 ) ;
if ( V_3 == 2 ) {
if ( V_2 -> V_4 )
V_37 = F_25 ( V_21 - V_2 -> V_33 ) ;
else
V_37 = F_26 ( V_21 - V_2 -> V_33 ) ;
} else {
V_37 = F_26 ( V_21 ) ;
}
V_2 -> V_6 [ V_3 ] = V_37 ;
F_14 ( V_20 , V_34 , V_37 ) ;
F_15 ( & V_2 -> V_23 ) ;
return V_18 ;
}
static T_1 F_27 ( struct V_8 * V_9 , struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_5 ( V_11 ) ;
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_3 = V_14 -> V_16 ;
int V_37 ;
if ( ! V_3 ) {
if ( V_2 -> V_38 )
V_37 = F_28 ( V_2 -> V_38 ) ;
else
V_37 = F_28 ( V_2 -> V_39 [ V_3 ] ) ;
} else {
if ( V_2 -> V_4 && V_3 == 2 )
V_37 = F_28 ( ( V_40 ) V_2 -> V_39 [ V_3 ] ) ;
else
V_37 = F_28 ( V_2 -> V_39 [ V_3 ] ) ;
}
return sprintf ( V_12 , L_1 , V_37 + V_2 -> V_33 ) ;
}
static T_1 F_29 ( struct V_8 * V_9 , struct V_10 * V_11 ,
const char * V_12 , T_2 V_18 )
{
static const V_5 V_34 [ 6 ] = {
V_41 ,
V_42 ,
V_43 ,
V_44 ,
V_45 ,
V_46 ,
} ;
struct V_13 * V_14 = F_5 ( V_11 ) ;
struct V_19 * V_20 = F_9 ( V_9 ) ;
struct V_1 * V_2 = F_10 ( V_20 ) ;
long V_21 ;
int V_22 ;
int V_3 = V_14 -> V_16 ;
V_22 = F_24 ( V_12 , 10 , & V_21 ) ;
if ( V_22 )
return V_22 ;
F_12 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_4 && V_3 == 2 )
V_2 -> V_39 [ V_3 ] = F_30 ( V_21 - V_2 -> V_33 ) ;
else
V_2 -> V_39 [ V_3 ] = F_31 ( V_21 - V_2 -> V_33 ) ;
F_14 ( V_20 , V_34 [ ( V_3 - 1 ) * 2 ] ,
V_2 -> V_39 [ V_3 ] >> 8 ) ;
F_14 ( V_20 , V_34 [ ( V_3 - 1 ) * 2 + 1 ] ,
V_2 -> V_39 [ V_3 ] & 0xff ) ;
F_15 ( & V_2 -> V_23 ) ;
return V_18 ;
}
static T_1 F_32 ( struct V_8 * V_9 ,
struct V_10 * V_17 , char * V_12 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return sprintf ( V_12 , L_1 , F_1 ( V_2 , 2 )
+ V_2 -> V_33
- F_2 ( V_2 -> V_47 ) ) ;
}
static T_1 F_33 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_14 = F_5 ( V_11 ) ;
struct V_1 * V_2 = F_6 ( V_9 ) ;
return sprintf ( V_12 , L_1 , F_3 ( V_2 , V_14 -> V_16 )
+ V_2 -> V_33
- F_2 ( V_2 -> V_48 ) ) ;
}
static T_1 F_34 ( struct V_8 * V_9 ,
struct V_10 * V_17 ,
const char * V_12 , T_2 V_18 )
{
struct V_19 * V_20 = F_9 ( V_9 ) ;
struct V_1 * V_2 = F_10 ( V_20 ) ;
long V_21 ;
int V_22 ;
long V_49 ;
V_22 = F_24 ( V_12 , 10 , & V_21 ) ;
if ( V_22 )
return V_22 ;
F_12 ( & V_2 -> V_23 ) ;
V_49 = F_1 ( V_2 , 2 ) + V_2 -> V_33 - V_21 ;
F_14 ( V_20 , V_50 ,
F_35 ( V_49 ) ) ;
F_15 ( & V_2 -> V_23 ) ;
return V_18 ;
}
static void F_36 ( struct V_19 * V_20 , struct V_1 * V_2 ,
unsigned int V_51 )
{
int V_52 ;
unsigned int V_53 ;
V_51 <<= 6 ;
V_53 = ( 1 << ( V_54 + 6 ) ) * 1000
/ V_2 -> V_55 ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ , V_53 >>= 1 )
if ( V_51 >= V_53 * 3 / 4 )
break;
F_14 ( V_20 , V_56 , V_52 ) ;
V_2 -> V_53 = F_37 ( V_2 -> V_55 , V_52 ) ;
}
static T_1 F_38 ( struct V_8 * V_9 ,
struct V_10 * V_14 , char * V_12 )
{
struct V_1 * V_2 = F_39 ( V_9 ) ;
return sprintf ( V_12 , L_2 , V_2 -> V_53 ) ;
}
static T_1 F_40 ( struct V_8 * V_9 ,
struct V_10 * V_14 ,
const char * V_12 , T_2 V_18 )
{
struct V_19 * V_20 = F_9 ( V_9 ) ;
struct V_1 * V_2 = F_10 ( V_20 ) ;
unsigned long V_21 ;
int V_22 ;
V_22 = F_11 ( V_12 , 10 , & V_21 ) ;
if ( V_22 )
return V_22 ;
F_12 ( & V_2 -> V_23 ) ;
F_36 ( V_20 , V_2 , F_18 ( V_21 , 0 , 100000 ) ) ;
F_15 ( & V_2 -> V_23 ) ;
return V_18 ;
}
static T_1 F_41 ( struct V_8 * V_9 , struct V_10 * V_14 ,
char * V_12 )
{
struct V_19 * V_20 = F_9 ( V_9 ) ;
struct V_1 * V_2 = F_10 ( V_20 ) ;
return sprintf ( V_12 , V_2 -> V_57 ? L_3 : L_4 ) ;
}
static T_1 F_42 ( struct V_8 * V_9 , struct V_10 * V_14 ,
const char * V_12 , T_2 V_18 )
{
struct V_19 * V_20 = F_9 ( V_9 ) ;
struct V_1 * V_2 = F_10 ( V_20 ) ;
unsigned long V_21 ;
int V_58 ;
V_5 V_34 ;
V_58 = F_11 ( V_12 , 10 , & V_21 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_21 != 1 && V_21 != 2 )
return - V_59 ;
F_12 ( & V_2 -> V_23 ) ;
V_2 -> V_57 = V_21 == 1 ;
V_34 = F_43 ( V_20 , V_60 ) & ~ 0x02 ;
F_14 ( V_20 , V_60 ,
V_34 | ( V_2 -> V_57 ? 0x02 : 0x00 ) ) ;
V_2 -> V_61 = 0 ;
F_15 ( & V_2 -> V_23 ) ;
return V_18 ;
}
static T_1 F_44 ( struct V_8 * V_9 , struct V_10 * V_17 ,
char * V_12 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
return sprintf ( V_12 , L_2 , V_2 -> V_62 ) ;
}
static T_1 F_45 ( struct V_8 * V_9 , struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_5 ( V_11 ) ;
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_63 = V_14 -> V_16 ;
return sprintf ( V_12 , L_2 , ( V_2 -> V_62 >> V_63 ) & 1 ) ;
}
static T_3 F_46 ( struct V_64 * V_65 ,
struct V_66 * V_14 , int V_16 )
{
struct V_8 * V_9 = F_47 ( V_65 , struct V_8 , V_65 ) ;
struct V_19 * V_20 = F_9 ( V_9 ) ;
struct V_1 * V_2 = F_10 ( V_20 ) ;
if ( V_14 == & V_67 . V_68 . V_14
&& ( V_2 -> V_69 == V_70 ||
( V_2 -> V_69 == V_71 && ( V_2 -> V_72 & 0x02 ) ) ) )
return V_14 -> V_73 | V_74 ;
return V_14 -> V_73 ;
}
static int F_48 ( struct V_19 * V_75 ,
struct V_76 * V_77 )
{
struct V_78 * V_79 = V_75 -> V_79 ;
V_5 V_80 , V_81 , V_82 , V_83 ;
V_5 V_84 , V_85 ;
int V_86 = V_75 -> V_87 ;
if ( ! F_49 ( V_79 , V_88 ) )
return - V_89 ;
V_80 = F_43 ( V_75 , V_90 ) ;
V_81 = F_43 ( V_75 , V_91 ) ;
V_82 = F_43 ( V_75 ,
V_92 ) ;
V_83 = F_43 ( V_75 ,
V_93 ) ;
V_84 = F_43 ( V_75 ,
V_94 ) ;
V_85 = F_43 ( V_75 ,
V_95 ) ;
if ( V_80 != 0x01
|| ( V_82 & 0x18 ) != 0x00
|| ( V_83 & 0xF8 ) != 0x00
|| ( V_84 & 0x20 ) != 0x00
|| ( V_85 & 0xA4 ) != 0xA4 ) {
F_50 ( & V_79 -> V_9 ,
L_5 ,
V_80 , V_81 ) ;
return - V_89 ;
}
if ( V_81 == 0x41 && V_86 == 0x4c )
F_51 ( V_77 -> type , L_6 , V_96 ) ;
else if ( V_81 == 0x51 && ( V_86 == 0x18 || V_86 == 0x4e ) )
F_51 ( V_77 -> type , L_7 , V_96 ) ;
else if ( V_81 == 0x49 && V_86 == 0x4c )
F_51 ( V_77 -> type , L_8 , V_96 ) ;
else
return - V_89 ;
return 0 ;
}
static int F_52 ( struct V_19 * V_75 ,
const struct V_97 * V_98 )
{
struct V_1 * V_2 ;
int V_22 ;
V_2 = F_53 ( sizeof( struct V_1 ) , V_99 ) ;
if ( ! V_2 ) {
V_22 = - V_100 ;
goto exit;
}
F_54 ( V_75 , V_2 ) ;
V_2 -> V_61 = 0 ;
F_55 ( & V_2 -> V_23 ) ;
V_2 -> V_69 = V_98 -> V_101 ;
if ( V_2 -> V_69 == V_70 )
V_2 -> V_33 = 16000 ;
F_56 ( V_75 ) ;
V_22 = F_57 ( & V_75 -> V_9 . V_65 , & V_102 ) ;
if ( V_22 )
goto V_103;
if ( V_2 -> V_72 & 0x04 ) {
V_22 = F_57 ( & V_75 -> V_9 . V_65 ,
& V_104 ) ;
if ( V_22 )
goto V_105;
}
if ( V_2 -> V_69 == V_71 ) {
V_22 = F_58 ( & V_75 -> V_9 ,
& V_106 ) ;
if ( V_22 )
goto V_105;
V_22 = F_57 ( & V_75 -> V_9 . V_65 ,
& V_107 ) ;
if ( V_22 )
goto V_105;
}
V_2 -> V_108 = F_59 ( & V_75 -> V_9 ) ;
if ( F_60 ( V_2 -> V_108 ) ) {
V_22 = F_61 ( V_2 -> V_108 ) ;
goto V_105;
}
return 0 ;
V_105:
F_62 ( & V_75 -> V_9 . V_65 , & V_102 ) ;
F_62 ( & V_75 -> V_9 . V_65 , & V_104 ) ;
if ( V_2 -> V_69 == V_71 ) {
F_63 ( & V_75 -> V_9 , & V_106 ) ;
F_62 ( & V_75 -> V_9 . V_65 ,
& V_107 ) ;
}
V_103:
F_64 ( V_2 ) ;
exit:
return V_22 ;
}
static void F_56 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_10 ( V_20 ) ;
V_5 V_109 ;
V_2 -> V_72 = F_43 ( V_20 , V_92 ) ;
V_2 -> V_30 = F_43 ( V_20 ,
V_110 ) ;
if ( V_2 -> V_72 & 0x40 ) {
F_50 ( & V_20 -> V_9 , L_9 ) ;
V_2 -> V_72 &= 0xA7 ;
F_14 ( V_20 , V_92 ,
V_2 -> V_72 ) ;
}
if ( V_2 -> V_69 == V_70 )
V_2 -> V_72 |= 0x04 ;
V_2 -> V_29 = F_43 ( V_20 , V_111 ) ;
if ( V_2 -> V_29 == 0 )
V_2 -> V_29 = 1 ;
switch ( V_2 -> V_69 ) {
case V_112 :
case V_70 :
V_2 -> V_55 = V_113 ;
V_2 -> V_114 = 8 ;
break;
case V_71 :
V_2 -> V_55 = V_115 ;
V_2 -> V_114 = 12 ;
V_2 -> V_57
= F_43 ( V_20 ,
V_60 ) & 0x02 ;
break;
}
V_109 = F_43 ( V_20 , V_56 ) ;
if ( F_65 ( V_109 > V_54 ) )
V_109 = V_54 ;
V_2 -> V_53 = F_37 ( V_2 -> V_55 ,
V_109 ) ;
if ( V_2 -> V_69 == V_71 ) {
V_5 V_116
= F_43 ( V_20 ,
V_117 ) ;
if ( V_116 & 0x20 )
V_2 -> V_7 = true ;
if ( ( V_116 & 0x10 )
&& ! ( V_2 -> V_30 & 0x08 ) && V_2 -> V_29 == 8 )
V_2 -> V_27 = true ;
if ( V_116 & 0x08 )
V_2 -> V_4 = true ;
}
if ( V_2 -> V_69 == V_112 )
F_50 ( & V_20 -> V_9 , L_10 ,
( V_2 -> V_72 & 0x04 ) ? L_11 :
L_12 ) ;
F_50 ( & V_20 -> V_9 , L_13 ,
( V_2 -> V_30 & 0x08 ) ? L_14 : L_15 ,
( ( V_2 -> V_30 & 0x08 ) ? 700 : 180000 ) / V_2 -> V_29 ) ;
F_50 ( & V_20 -> V_9 , L_16 ,
( V_2 -> V_30 & 0x10 ) ? L_17 : L_18 ,
( V_2 -> V_30 & 0x20 ) ? L_19 : L_20 ) ;
}
static int F_66 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_10 ( V_20 ) ;
F_67 ( V_2 -> V_108 ) ;
F_62 ( & V_20 -> V_9 . V_65 , & V_102 ) ;
F_62 ( & V_20 -> V_9 . V_65 , & V_104 ) ;
if ( V_2 -> V_69 == V_71 ) {
F_63 ( & V_20 -> V_9 , & V_106 ) ;
F_62 ( & V_20 -> V_9 . V_65 , & V_107 ) ;
}
F_64 ( V_2 ) ;
return 0 ;
}
static struct V_1 * F_6 ( struct V_8 * V_9 )
{
struct V_19 * V_20 = F_9 ( V_9 ) ;
struct V_1 * V_2 = F_10 ( V_20 ) ;
unsigned long V_118 ;
int V_52 ;
F_12 ( & V_2 -> V_23 ) ;
V_118 = V_2 -> V_119
+ F_68 ( V_2 -> V_53 ) + 1 ;
if ( F_69 ( V_120 , V_118 ) || ! V_2 -> V_61 ) {
if ( V_2 -> V_72 & 0x04 ) {
V_2 -> V_15 [ 0 ] = F_43 ( V_20 ,
V_121 ) & 0xFC ;
V_2 -> V_15 [ 0 ] |= F_43 ( V_20 ,
V_122 ) << 8 ;
V_2 -> V_15 [ 1 ] = ( F_43 ( V_20 ,
V_24 ) & 0xFC )
| ( F_43 ( V_20 ,
V_25 ) << 8 ) ;
}
V_2 -> V_29 = F_43 ( V_20 ,
V_111 ) ;
if ( V_2 -> V_29 == 0 )
V_2 -> V_29 = 1 ;
V_2 -> V_28 [ 0 ] = F_43 ( V_20 ,
V_32 ) ;
V_2 -> V_6 [ 0 ] = F_43 ( V_20 ,
V_123 ) ;
V_2 -> V_6 [ 1 ] = F_43 ( V_20 ,
V_36 ) ;
V_2 -> V_39 [ 0 ] = F_43 ( V_20 ,
V_124 ) << 8 ;
V_2 -> V_39 [ 0 ] |= F_43 ( V_20 ,
V_125 ) ;
V_2 -> V_39 [ 1 ] = ( F_43 ( V_20 ,
V_41 ) << 8 )
| F_43 ( V_20 ,
V_42 ) ;
V_2 -> V_39 [ 2 ] = ( F_43 ( V_20 ,
V_43 ) << 8 )
| F_43 ( V_20 ,
V_44 ) ;
V_2 -> V_39 [ 3 ] = ( F_43 ( V_20 ,
V_45 ) << 8 )
| F_43 ( V_20 ,
V_46 ) ;
if ( V_2 -> V_69 == V_71 )
V_2 -> V_38 = ( F_43 ( V_20 ,
V_126 ) << 8 )
| F_43 ( V_20 ,
V_127 ) ;
V_2 -> V_6 [ 2 ] = F_43 ( V_20 ,
V_35 ) ;
V_2 -> V_47 = F_43 ( V_20 ,
V_50 ) ;
V_2 -> V_62 = F_43 ( V_20 ,
V_94 ) & 0x7F ;
V_2 -> V_119 = V_120 ;
V_2 -> V_61 = 1 ;
}
if ( F_69 ( V_120 , V_2 -> V_128 + 5 * V_129 ) ||
! V_2 -> V_130 ) {
for ( V_52 = 0 ; V_52 < V_2 -> V_114 ; V_52 ++ ) {
V_2 -> V_28 [ 1 + V_52 ] = F_43 ( V_20 ,
F_70 ( V_52 ) ) ;
V_2 -> V_6 [ 3 + V_52 ] = F_43 ( V_20 ,
F_71 ( V_52 ) ) ;
}
V_2 -> V_48 = F_43 ( V_20 ,
V_131 ) ;
V_2 -> V_128 = V_120 ;
V_2 -> V_130 = 1 ;
}
F_15 ( & V_2 -> V_23 ) ;
return V_2 ;
}
static int T_4 F_72 ( void )
{
return F_73 ( & V_132 ) ;
}
static void T_5 F_74 ( void )
{
F_75 ( & V_132 ) ;
}
