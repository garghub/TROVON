static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , V_7 ) ;
if ( V_6 -> V_8 > 1 ) {
unsigned int V_9 = 0 , V_10 = 0 ;
int V_11 = F_3 ( F_2 ( V_2 , V_12 ) ,
2 , V_13 , & V_9 , & V_10 ) ;
if ( V_11 >= 0 && V_10 ) {
V_2 -> V_14 = V_9 ;
V_2 -> V_15 = V_10 ;
}
return V_11 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_16 = F_2 ( V_2 , V_12 ) ;
if ( V_16 -> V_8 > F_5 ( 22050 ) || V_16 -> V_17 <= F_5 ( 11025 ) ) {
struct V_5 V_18 = { . V_8 = 1 , . V_17 = 1 } ;
return F_6 ( F_2 ( V_2 , V_7 ) , & V_18 ) ;
}
return 0 ;
}
static int F_7 ( struct V_19 * V_20 )
{
unsigned long V_21 ;
struct V_22 * V_23 = F_8 ( V_20 ) ;
struct V_24 * V_25 = V_20 -> V_25 ;
unsigned int V_26 , V_27 , V_28 , V_29 ;
unsigned char V_30 ;
unsigned char V_31 = V_25 -> V_32 > 1 ;
int V_33 ;
V_27 = V_25 -> V_27 ;
switch ( V_23 -> V_34 ) {
case V_35 :
if ( V_25 -> V_30 == V_36 ) {
if ( V_23 -> V_37 & V_38 )
return - V_39 ;
else
V_23 -> V_37 |= V_40 ;
}
V_23 -> V_41 = V_42 ;
break;
case V_43 :
if ( V_25 -> V_32 > 1 ) {
if ( F_9 ( V_27 != F_5 ( 11025 ) &&
V_27 != F_5 ( 22050 ) ) )
return - V_44 ;
V_23 -> V_41 = V_45 ;
break;
}
case V_46 :
if ( V_27 > 23000 ) {
V_23 -> V_41 = V_45 ;
break;
}
case V_47 :
V_23 -> V_41 = V_42 ;
break;
case V_48 :
V_23 -> V_41 = V_49 ;
break;
default:
return - V_44 ;
}
if ( V_23 -> V_37 & V_40 ) {
V_30 = V_31 ? V_50 : V_51 ;
V_33 = V_23 -> V_52 ;
} else {
V_30 = V_31 ? V_53 : V_54 ;
V_23 -> V_37 |= V_55 ;
V_33 = V_23 -> V_56 ;
}
V_28 = V_23 -> V_57 = F_10 ( V_20 ) ;
V_29 = V_23 -> V_58 = F_11 ( V_20 ) ;
F_12 ( & V_23 -> V_59 , V_21 ) ;
F_13 ( V_23 , V_60 ) ;
if ( V_23 -> V_34 == V_35 )
F_13 ( V_23 , V_30 ) ;
else if ( V_31 ) {
F_14 ( & V_23 -> V_61 ) ;
V_26 = F_15 ( V_23 , V_62 ) ;
F_16 ( V_23 , V_62 , V_26 | 0x02 ) ;
F_17 ( & V_23 -> V_61 ) ;
F_13 ( V_23 , V_63 ) ;
V_25 -> V_64 [ 0 ] = 0x80 ;
F_18 ( V_33 , V_25 -> V_65 , 1 , V_66 ) ;
F_13 ( V_23 , V_49 ) ;
F_13 ( V_23 , 0 ) ;
F_13 ( V_23 , 0 ) ;
}
F_13 ( V_23 , V_67 ) ;
if ( V_31 ) {
F_13 ( V_23 , 256 - V_25 -> V_15 / 2 ) ;
F_14 ( & V_23 -> V_61 ) ;
V_26 = F_15 ( V_23 , V_68 ) ;
F_16 ( V_23 , V_68 , V_26 | 0x20 ) ;
F_17 ( & V_23 -> V_61 ) ;
V_23 -> V_69 = V_26 ;
} else {
F_13 ( V_23 , 256 - V_25 -> V_15 ) ;
}
if ( V_23 -> V_41 != V_49 ) {
if ( V_23 -> V_37 & V_40 )
V_29 /= 2 ;
V_29 -- ;
F_13 ( V_23 , V_70 ) ;
F_13 ( V_23 , V_29 & 0xff ) ;
F_13 ( V_23 , V_29 >> 8 ) ;
}
F_19 ( & V_23 -> V_59 , V_21 ) ;
F_18 ( V_33 , V_25 -> V_65 ,
V_28 , V_66 | V_71 ) ;
return 0 ;
}
static int F_20 ( struct V_19 * V_20 ,
int V_72 )
{
unsigned long V_21 ;
struct V_22 * V_23 = F_8 ( V_20 ) ;
unsigned int V_29 ;
F_12 ( & V_23 -> V_59 , V_21 ) ;
switch ( V_72 ) {
case V_73 :
F_13 ( V_23 , V_23 -> V_41 ) ;
if ( V_23 -> V_41 == V_49 ) {
V_29 = V_23 -> V_58 - 1 ;
F_13 ( V_23 , V_29 & 0xff ) ;
F_13 ( V_23 , V_29 >> 8 ) ;
}
break;
case V_74 :
if ( V_23 -> V_41 == V_45 ) {
struct V_24 * V_25 = V_20 -> V_25 ;
F_21 ( V_23 ) ;
if ( V_25 -> V_32 > 1 ) {
F_14 ( & V_23 -> V_61 ) ;
F_16 ( V_23 , V_62 , V_23 -> V_69 & ~ 0x02 ) ;
F_17 ( & V_23 -> V_61 ) ;
}
} else {
F_13 ( V_23 , V_75 ) ;
}
F_13 ( V_23 , V_76 ) ;
}
F_19 ( & V_23 -> V_59 , V_21 ) ;
return 0 ;
}
static int F_22 ( struct V_19 * V_20 ,
struct V_1 * V_77 )
{
return F_23 ( V_20 , F_24 ( V_77 ) ) ;
}
static int F_25 ( struct V_19 * V_20 )
{
F_26 ( V_20 ) ;
return 0 ;
}
static int F_27 ( struct V_19 * V_20 )
{
unsigned long V_21 ;
struct V_22 * V_23 = F_8 ( V_20 ) ;
struct V_24 * V_25 = V_20 -> V_25 ;
unsigned int V_26 , V_27 , V_28 , V_29 ;
unsigned char V_30 ;
unsigned char V_31 = V_25 -> V_32 > 1 ;
int V_33 ;
V_27 = V_25 -> V_27 ;
switch ( V_23 -> V_34 ) {
case V_35 :
if ( V_25 -> V_30 == V_36 ) {
if ( V_23 -> V_37 & V_40 )
return - V_39 ;
else
V_23 -> V_37 |= V_38 ;
}
V_23 -> V_78 = V_79 ;
break;
case V_43 :
if ( V_25 -> V_32 > 1 ) {
if ( F_9 ( V_27 != F_5 ( 11025 ) &&
V_27 != F_5 ( 22050 ) ) )
return - V_44 ;
V_23 -> V_78 = V_80 ;
break;
}
V_23 -> V_78 = ( V_27 > 23000 ) ? V_80 : V_79 ;
break;
case V_46 :
if ( V_27 > 13000 ) {
V_23 -> V_78 = V_80 ;
break;
}
case V_47 :
V_23 -> V_78 = V_79 ;
break;
case V_48 :
V_23 -> V_78 = V_81 ;
break;
default:
return - V_44 ;
}
if ( V_23 -> V_37 & V_38 ) {
V_30 = V_31 ? V_50 : V_51 ;
V_33 = V_23 -> V_52 ;
} else {
V_30 = V_31 ? V_53 : V_54 ;
V_23 -> V_37 |= V_82 ;
V_33 = V_23 -> V_56 ;
}
V_28 = V_23 -> V_83 = F_10 ( V_20 ) ;
V_29 = V_23 -> V_84 = F_11 ( V_20 ) ;
F_12 ( & V_23 -> V_59 , V_21 ) ;
F_13 ( V_23 , V_76 ) ;
if ( V_23 -> V_34 == V_35 )
F_13 ( V_23 , V_30 ) ;
else if ( V_31 )
F_13 ( V_23 , V_53 ) ;
F_13 ( V_23 , V_67 ) ;
if ( V_31 ) {
F_13 ( V_23 , 256 - V_25 -> V_15 / 2 ) ;
F_14 ( & V_23 -> V_61 ) ;
V_26 = F_15 ( V_23 , V_85 ) ;
F_16 ( V_23 , V_85 , V_26 | 0x20 ) ;
F_17 ( & V_23 -> V_61 ) ;
V_23 -> V_69 = V_26 ;
} else {
F_13 ( V_23 , 256 - V_25 -> V_15 ) ;
}
if ( V_23 -> V_78 != V_81 ) {
if ( V_23 -> V_37 & V_40 )
V_29 /= 2 ;
V_29 -- ;
F_13 ( V_23 , V_70 ) ;
F_13 ( V_23 , V_29 & 0xff ) ;
F_13 ( V_23 , V_29 >> 8 ) ;
}
F_19 ( & V_23 -> V_59 , V_21 ) ;
F_18 ( V_33 , V_25 -> V_65 ,
V_28 , V_86 | V_71 ) ;
return 0 ;
}
static int F_28 ( struct V_19 * V_20 ,
int V_72 )
{
unsigned long V_21 ;
struct V_22 * V_23 = F_8 ( V_20 ) ;
unsigned int V_29 ;
F_12 ( & V_23 -> V_59 , V_21 ) ;
switch ( V_72 ) {
case V_73 :
F_13 ( V_23 , V_23 -> V_78 ) ;
if ( V_23 -> V_78 == V_81 ) {
V_29 = V_23 -> V_84 - 1 ;
F_13 ( V_23 , V_29 & 0xff ) ;
F_13 ( V_23 , V_29 >> 8 ) ;
}
break;
case V_74 :
if ( V_23 -> V_78 == V_80 ) {
struct V_24 * V_25 = V_20 -> V_25 ;
F_21 ( V_23 ) ;
if ( V_25 -> V_32 > 1 ) {
F_14 ( & V_23 -> V_61 ) ;
F_16 ( V_23 , V_85 , V_23 -> V_69 ) ;
F_17 ( & V_23 -> V_61 ) ;
F_13 ( V_23 , V_54 ) ;
}
} else {
F_13 ( V_23 , V_75 ) ;
}
F_13 ( V_23 , V_76 ) ;
}
F_19 ( & V_23 -> V_59 , V_21 ) ;
return 0 ;
}
T_1 F_29 ( struct V_22 * V_23 )
{
struct V_19 * V_20 ;
struct V_24 * V_25 ;
F_30 ( V_23 ) ;
switch ( V_23 -> V_37 ) {
case V_40 :
if ( V_23 -> V_34 != V_35 )
break;
case V_55 :
V_20 = V_23 -> V_87 ;
V_25 = V_20 -> V_25 ;
if ( V_23 -> V_41 == V_49 )
F_20 ( V_20 , V_73 ) ;
F_31 ( V_20 ) ;
break;
case V_38 :
if ( V_23 -> V_34 != V_35 )
break;
case V_82 :
V_20 = V_23 -> V_88 ;
V_25 = V_20 -> V_25 ;
if ( V_23 -> V_78 == V_81 )
F_28 ( V_20 , V_73 ) ;
F_31 ( V_20 ) ;
break;
}
return V_89 ;
}
static T_2 F_32 ( struct V_19 * V_20 )
{
struct V_22 * V_23 = F_8 ( V_20 ) ;
T_3 V_90 ;
int V_33 ;
if ( V_23 -> V_37 & V_55 )
V_33 = V_23 -> V_56 ;
else if ( V_23 -> V_37 & V_40 )
V_33 = V_23 -> V_52 ;
else
return 0 ;
V_90 = F_33 ( V_33 , V_23 -> V_57 ) ;
return F_34 ( V_20 -> V_25 , V_90 ) ;
}
static T_2 F_35 ( struct V_19 * V_20 )
{
struct V_22 * V_23 = F_8 ( V_20 ) ;
T_3 V_90 ;
int V_33 ;
if ( V_23 -> V_37 & V_82 )
V_33 = V_23 -> V_56 ;
else if ( V_23 -> V_37 & V_38 )
V_33 = V_23 -> V_52 ;
else
return 0 ;
V_90 = F_33 ( V_33 , V_23 -> V_83 ) ;
return F_34 ( V_20 -> V_25 , V_90 ) ;
}
static int F_36 ( struct V_19 * V_20 )
{
struct V_22 * V_23 = F_8 ( V_20 ) ;
struct V_24 * V_25 = V_20 -> V_25 ;
unsigned long V_21 ;
F_12 ( & V_23 -> V_91 , V_21 ) ;
if ( V_23 -> V_92 ) {
F_19 ( & V_23 -> V_91 , V_21 ) ;
return - V_93 ;
}
V_23 -> V_92 |= V_94 ;
F_19 ( & V_23 -> V_91 , V_21 ) ;
if ( V_20 -> V_95 == V_96 ) {
V_23 -> V_87 = V_20 ;
V_25 -> V_97 = V_98 ;
} else {
V_23 -> V_88 = V_20 ;
V_25 -> V_97 = V_99 ;
}
switch ( V_23 -> V_34 ) {
case V_35 :
if ( V_23 -> V_52 == 5 || V_23 -> V_52 == 7 )
V_25 -> V_97 . V_100 |= V_101 ;
V_25 -> V_97 . V_102 |= V_103 ;
V_25 -> V_97 . V_104 = 4000 ;
V_25 -> V_97 . V_105 = 50000 ;
V_25 -> V_97 . V_106 = 2 ;
break;
case V_43 :
V_25 -> V_97 . V_105 = 44100 ;
V_25 -> V_97 . V_106 = 2 ;
F_37 ( V_25 , 0 , V_12 ,
F_1 , NULL ,
V_7 ,
V_12 , - 1 ) ;
F_37 ( V_25 , 0 , V_7 ,
F_4 , NULL ,
V_12 , - 1 ) ;
break;
case V_46 :
if ( V_20 -> V_95 == V_96 ) {
V_25 -> V_97 . V_105 = 44100 ;
} else {
V_25 -> V_97 . V_105 = 15000 ;
}
default:
break;
}
F_38 ( V_25 , 0 , V_12 ,
& V_107 ) ;
if ( V_23 -> V_56 > 3 || V_23 -> V_52 >= 0 ) {
F_39 ( V_25 , 0 ,
V_108 , 2 ) ;
F_39 ( V_25 , 0 ,
V_109 , 2 ) ;
V_25 -> V_97 . V_110 = 128 * 1024 * 1024 ;
V_25 -> V_97 . V_111 = 128 * 1024 * 1024 ;
}
return 0 ;
}
static int F_40 ( struct V_19 * V_20 )
{
unsigned long V_21 ;
struct V_22 * V_23 = F_8 ( V_20 ) ;
V_23 -> V_87 = NULL ;
V_23 -> V_88 = NULL ;
F_12 ( & V_23 -> V_91 , V_21 ) ;
V_23 -> V_92 &= ~ V_94 ;
if ( V_20 -> V_95 == V_96 )
V_23 -> V_37 &= ~ V_112 ;
else
V_23 -> V_37 &= ~ V_113 ;
F_19 ( & V_23 -> V_91 , V_21 ) ;
return 0 ;
}
int F_41 ( struct V_22 * V_23 , int V_114 )
{
struct V_115 * V_116 = V_23 -> V_116 ;
struct V_117 * V_118 ;
int V_11 ;
T_3 V_119 = 64 * 1024 ;
if ( ( V_11 = F_42 ( V_116 , L_1 , V_114 , 1 , 1 , & V_118 ) ) < 0 )
return V_11 ;
sprintf ( V_118 -> V_120 , L_2 , V_23 -> V_121 >> 8 , V_23 -> V_121 & 0xff ) ;
V_118 -> V_122 = V_123 ;
V_118 -> V_124 = V_23 ;
F_43 ( V_118 , V_96 , & V_125 ) ;
F_43 ( V_118 , V_126 , & V_127 ) ;
if ( V_23 -> V_56 > 3 || V_23 -> V_52 >= 0 )
V_119 = 128 * 1024 ;
F_44 ( V_118 , V_128 ,
F_45 () ,
64 * 1024 , V_119 ) ;
return 0 ;
}
static int T_4 F_46 ( void )
{
return 0 ;
}
static void T_5 F_47 ( void )
{
}
