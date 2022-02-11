static unsigned int F_1 ( struct V_1 * V_1 ,
unsigned int V_2 )
{
const unsigned int * V_3 = NULL ;
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
if ( V_5 [ V_4 ] . V_2 == V_2 ) {
V_3 = V_5 [ V_4 ] . V_3 ;
break;
}
}
if ( ! V_3 )
return - V_6 ;
for ( V_4 = 0 ; V_3 [ V_4 ] ; V_4 ++ ) {
if ( V_3 [ V_4 ] == V_1 -> V_7 )
return V_4 ;
}
return - V_6 ;
}
static int F_3 ( struct V_8 * V_9 ,
struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_1 * V_1 = F_4 ( V_15 ) ;
unsigned int V_2 = F_5 ( V_11 ) ;
unsigned int V_16 , V_17 ;
int V_18 ;
int V_19 ;
V_18 = F_1 ( V_1 , V_2 ) ;
if ( V_18 < 0 )
return V_18 ;
V_17 = V_20 ;
if ( V_2 >= 8000 && V_2 <= 12000 )
V_16 = V_21 ;
else if ( V_2 >= 16000 && V_2 <= 24000 )
V_16 = V_22 ;
else if ( V_2 >= 32000 && V_2 <= 48000 )
V_16 = V_23 ;
else if ( V_2 >= 64000 && V_2 <= 96000 )
V_16 = V_24 ;
else
return - V_6 ;
if ( V_1 -> V_25 ) {
switch ( F_6 ( V_11 ) ) {
case 16 :
V_16 |= V_26 ;
break;
case 24 :
V_16 |= V_27 ;
break;
default:
return - V_6 ;
}
V_17 |= V_28 ;
}
V_19 = F_7 ( V_1 -> V_29 , V_30 ,
V_31 , V_31 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_7 ( V_1 -> V_29 , V_32 ,
V_17 , V_16 ) ;
if ( V_19 < 0 )
return V_19 ;
return F_7 ( V_1 -> V_29 , V_33 ,
V_34 , V_18 << 1 ) ;
}
static int F_8 ( struct V_12 * V_13 , int V_35 )
{
struct V_1 * V_1 = F_4 ( V_13 -> V_15 ) ;
unsigned int V_36 ;
if ( V_35 )
V_36 = V_37 ;
else
V_36 = 0 ;
return F_7 ( V_1 -> V_29 , V_38 ,
V_37 , V_36 ) ;
}
static int F_9 ( struct V_12 * V_13 , unsigned int V_39 )
{
struct V_1 * V_1 = F_4 ( V_13 -> V_15 ) ;
unsigned int V_16 = 0 , V_40 = 0 ;
bool V_41 ;
int V_19 ;
switch ( V_39 & V_42 ) {
case V_43 :
break;
default:
return - V_6 ;
}
switch ( V_39 & V_44 ) {
case V_45 :
V_41 = false ;
break;
case V_46 :
V_40 |= V_47 ;
V_41 = false ;
break;
case V_48 :
V_41 = true ;
break;
case V_49 :
V_40 |= V_47 ;
V_41 = true ;
break;
default:
return - V_6 ;
}
V_1 -> V_25 = false ;
switch ( V_39 & V_50 ) {
case V_51 :
V_16 |= V_52 ;
break;
case V_53 :
V_16 |= V_54 ;
V_41 = ! V_41 ;
break;
case V_55 :
V_16 |= V_27 ;
V_1 -> V_25 = true ;
V_41 = ! V_41 ;
break;
case V_56 :
V_40 |= V_57 ;
V_16 |= V_52 ;
V_41 = false ;
break;
case V_58 :
V_40 |= V_57 ;
V_16 |= V_54 ;
V_41 = false ;
break;
default:
return - V_6 ;
}
if ( V_41 )
V_40 |= V_59 ;
V_19 = F_10 ( V_1 -> V_29 , V_32 , V_16 ) ;
if ( V_19 )
return V_19 ;
return F_10 ( V_1 -> V_29 , V_60 , V_40 ) ;
}
static int F_11 ( struct V_1 * V_1 , bool V_61 )
{
int V_19 = 0 ;
if ( ! V_61 ) {
V_19 = F_7 ( V_1 -> V_29 , V_33 ,
V_62 , V_62 ) ;
F_12 ( V_1 -> V_29 ) ;
}
if ( F_13 ( V_1 -> V_63 ) )
F_14 ( V_1 -> V_63 , V_61 ) ;
F_15 ( V_1 -> V_29 , ! V_61 ) ;
if ( V_61 ) {
V_19 = F_7 ( V_1 -> V_29 , V_33 ,
V_62 | V_64 , 0x00 ) ;
F_16 ( V_1 -> V_29 ) ;
}
return V_19 ;
}
static int F_17 ( struct V_14 * V_15 ,
enum V_65 V_66 )
{
struct V_1 * V_1 = F_4 ( V_15 ) ;
int V_19 = 0 ;
switch ( V_66 ) {
case V_67 :
break;
case V_68 :
break;
case V_69 :
if ( F_18 ( V_15 ) == V_70 )
V_19 = F_11 ( V_1 , true ) ;
break;
case V_70 :
V_19 = F_11 ( V_1 , false ) ;
break;
}
return V_19 ;
}
static int F_19 ( struct V_12 * V_13 , unsigned int V_71 ,
unsigned int V_72 , int V_73 , int V_74 )
{
struct V_1 * V_1 = F_4 ( V_13 -> V_15 ) ;
unsigned int V_16 , V_40 ;
int V_75 , V_76 ;
int V_19 ;
if ( V_73 == 0 )
return F_7 ( V_1 -> V_29 ,
V_32 , V_77 ,
V_78 ) ;
if ( V_71 == 0 || V_72 != 0 )
return - V_6 ;
if ( V_73 == 1 ) {
if ( V_71 != 1 )
return - V_6 ;
V_75 = 0 ;
V_76 = 0 ;
} else {
V_75 = F_20 ( V_71 ) ;
V_71 &= ~ ( 1 << V_75 ) ;
if ( V_71 == 0 ) {
V_76 = V_75 ;
} else {
V_76 = F_20 ( V_71 ) ;
V_71 &= ~ ( 1 << V_76 ) ;
}
}
if ( V_71 != 0 || V_75 >= V_73 || V_76 >= V_73 )
return - V_6 ;
switch ( V_74 ) {
case 16 :
V_40 = V_79 ;
break;
case 24 :
V_40 = V_80 ;
break;
case 32 :
V_40 = V_81 ;
break;
default:
return - V_6 ;
}
switch ( V_73 ) {
case 1 :
V_16 = V_82 ;
break;
case 2 :
V_16 = V_83 ;
break;
case 4 :
V_16 = V_84 ;
break;
case 8 :
V_16 = V_85 ;
break;
case 16 :
V_16 = V_86 ;
break;
default:
return - V_6 ;
}
V_19 = F_10 ( V_1 -> V_29 , V_87 ,
( V_75 << V_88 ) |
( V_76 << V_89 ) ) ;
if ( V_19 )
return V_19 ;
V_19 = F_7 ( V_1 -> V_29 , V_32 ,
V_77 , V_16 ) ;
if ( V_19 )
return V_19 ;
return F_7 ( V_1 -> V_29 , V_60 ,
V_90 , V_40 ) ;
}
static int F_21 ( struct V_8 * V_9 ,
struct V_12 * V_13 )
{
struct V_1 * V_1 = F_4 ( V_13 -> V_15 ) ;
if ( V_1 -> V_91 )
F_22 ( V_9 -> V_92 , 0 ,
V_93 , V_1 -> V_91 ) ;
return 0 ;
}
static int F_23 ( struct V_14 * V_15 , int V_94 ,
int V_95 , unsigned int V_96 , int V_97 )
{
struct V_1 * V_1 = F_4 ( V_15 ) ;
unsigned int V_36 ;
if ( V_94 != V_98 )
return - V_6 ;
switch ( V_95 ) {
case V_99 :
V_36 = 0 ;
break;
case V_100 :
V_36 = V_101 ;
break;
default:
return - V_6 ;
}
switch ( V_96 ) {
case 0 :
V_1 -> V_91 = NULL ;
break;
case 2048000 :
case 4096000 :
case 8192000 :
case 3200000 :
case 6400000 :
case 12800000 :
V_1 -> V_91 = & V_102 ;
break;
case 2822000 :
case 5644800 :
case 11289600 :
case 16934400 :
case 22579200 :
case 33868800 :
case 4410000 :
case 8820000 :
case 17640000 :
V_1 -> V_91 = & V_103 ;
break;
case 3072000 :
case 6144000 :
case 38864000 :
case 4800000 :
case 9600000 :
case 19200000 :
V_1 -> V_91 = & V_104 ;
break;
case 12288000 :
case 16384000 :
case 24576000 :
V_1 -> V_91 = & V_105 ;
break;
default:
return - V_6 ;
}
V_1 -> V_7 = V_96 ;
return F_7 ( V_1 -> V_29 , V_33 ,
V_101 , V_36 ) ;
}
static int F_24 ( struct V_106 * V_107 ,
const struct V_108 * V_109 )
{
struct V_110 * V_111 = V_107 -> V_112 . V_113 ;
struct V_1 * V_1 ;
int V_19 ;
V_1 = F_25 ( & V_107 -> V_112 , sizeof( * V_1 ) , V_114 ) ;
if ( V_1 == NULL )
return - V_115 ;
if ( V_111 ) {
V_1 -> V_63 = V_111 -> V_63 ;
} else if ( V_107 -> V_112 . V_116 ) {
V_1 -> V_63 = F_26 ( V_107 -> V_112 . V_116 , 0 ) ;
if ( V_1 -> V_63 < 0 && V_1 -> V_63 != - V_117 )
return V_1 -> V_63 ;
} else {
V_1 -> V_63 = - 1 ;
}
if ( F_13 ( V_1 -> V_63 ) ) {
V_19 = F_27 ( & V_107 -> V_112 , V_1 -> V_63 ,
V_118 , L_1 ) ;
if ( V_19 )
return V_19 ;
}
F_28 ( V_107 , V_1 ) ;
V_1 -> V_29 = F_29 ( V_107 , & V_119 ) ;
if ( F_30 ( V_1 -> V_29 ) )
return F_31 ( V_1 -> V_29 ) ;
F_32 ( V_1 -> V_29 , true ) ;
V_19 = F_10 ( V_1 -> V_29 , V_33 ,
V_64 ) ;
F_32 ( V_1 -> V_29 , false ) ;
if ( V_19 )
return V_19 ;
V_19 = F_7 ( V_1 -> V_29 , V_120 ,
V_121 , 0x00 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_11 ( V_1 , false ) ;
if ( V_19 )
return V_19 ;
return F_33 ( & V_107 -> V_112 , & V_122 ,
& V_123 , 1 ) ;
}
static int F_34 ( struct V_106 * V_124 )
{
F_35 ( & V_124 -> V_112 ) ;
return 0 ;
}
