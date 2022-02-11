static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 = 0 ;
int V_7 = 1 ;
V_7 = V_5 -> V_8 ;
while ( V_7 > 0 ) {
V_6 = F_3 ( V_2 , V_3 ) ;
if ( V_6 >= 0 )
break;
V_7 -- ;
}
if ( V_6 < 0 ) {
F_4 ( & V_2 -> V_9 ,
L_1 ,
V_10 , V_3 ) ;
return V_6 ;
}
return F_5 ( V_6 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 ,
char * V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 = 0 , V_12 = 0 ;
int V_13 = 1 , V_14 = 1 ;
T_1 V_15 [ V_16 + 1 ] ;
V_13 = V_5 -> V_8 ;
V_14 = V_5 -> V_8 ;
if ( ! F_7 ( V_2 -> V_17 ,
V_18 |
V_19 ) ) {
return - V_20 ;
}
while ( V_13 > 0 ) {
V_6 = F_8 ( V_2 , V_3 ) ;
if ( V_6 >= 0 )
break;
V_13 -- ;
}
if ( V_6 < 0 ) {
F_4 ( & V_2 -> V_9 ,
L_1 ,
V_10 , V_3 ) ;
return V_6 ;
}
V_12 = V_6 ;
if ( V_12 > V_16 ) {
F_9 ( & V_2 -> V_9 ,
L_2 ,
V_10 , V_16 ) ;
return - V_21 ;
}
while ( V_14 > 0 ) {
V_6 = F_10 (
V_2 , V_3 ,
V_12 + 1 , V_15 ) ;
if ( V_6 >= 0 )
break;
V_14 -- ;
}
if ( V_6 < 0 ) {
F_4 ( & V_2 -> V_9 ,
L_1 ,
V_10 , V_3 ) ;
return V_6 ;
}
memcpy ( V_11 , V_15 + 1 , V_12 ) ;
V_11 [ V_12 ] = '\0' ;
return F_5 ( V_6 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 ,
T_3 V_22 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 = 0 ;
int V_7 = 1 ;
V_7 = V_5 -> V_8 ;
while ( V_7 > 0 ) {
V_6 = F_12 ( V_2 , V_3 ,
F_5 ( V_22 ) ) ;
if ( V_6 >= 0 )
break;
V_7 -- ;
}
if ( V_6 < 0 ) {
F_4 ( & V_2 -> V_9 ,
L_3 ,
V_10 , V_3 ) ;
return V_6 ;
}
return 0 ;
}
static int F_13 (
struct V_1 * V_2 , enum V_23 V_24 ,
union V_25 * V_26 )
{
T_2 V_6 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_24 == V_27 && V_5 -> V_28 ) {
V_6 = F_14 ( V_5 -> V_28 ) ;
if ( V_6 < 0 )
return V_6 ;
V_26 -> V_29 = V_6 ;
V_5 -> V_30 = V_26 -> V_29 ;
return V_6 ;
}
F_11 ( V_2 , V_31 [ V_32 ] . V_33 ,
V_34 ) ;
V_6 = F_1 ( V_2 , V_31 [ V_32 ] . V_33 ) ;
if ( V_6 < 0 ) {
if ( V_24 == V_27 )
V_26 -> V_29 = 0 ;
return V_6 ;
}
if ( V_6 < V_31 [ V_32 ] . V_35 ||
V_6 > V_31 [ V_32 ] . V_36 ) {
V_26 -> V_29 = 0 ;
return 0 ;
}
V_6 &= 0x0F00 ;
V_6 >>= 8 ;
if ( V_24 == V_27 ) {
if ( V_6 == 0x0F )
V_26 -> V_29 = 0 ;
else
V_26 -> V_29 = 1 ;
} else if ( V_24 == V_37 ) {
if ( V_6 == 0x09 )
V_26 -> V_29 = V_38 ;
else if ( V_6 == 0x0B )
V_26 -> V_29 = V_39 ;
else if ( V_6 == 0x0C )
V_26 -> V_29 = V_40 ;
else
V_26 -> V_29 = V_41 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
int V_42 , enum V_23 V_24 ,
union V_25 * V_26 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 ;
V_6 = F_1 ( V_2 , V_31 [ V_42 ] . V_33 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_31 [ V_42 ] . V_35 < 0 )
V_6 = ( V_43 ) V_6 ;
if ( V_6 >= V_31 [ V_42 ] . V_35 &&
V_6 <= V_31 [ V_42 ] . V_36 ) {
V_26 -> V_29 = V_6 ;
if ( V_24 == V_44 ) {
if ( ! ( V_6 & V_45 ) )
V_26 -> V_29 =
V_46 ;
else if ( V_6 & V_47 )
V_26 -> V_29 =
V_48 ;
else if ( V_6 & V_49 )
V_26 -> V_29 =
V_50 ;
else
V_26 -> V_29 =
V_51 ;
return 0 ;
} else if ( V_24 != V_52 ) {
return 0 ;
}
if ( V_6 & V_47 )
V_26 -> V_29 = V_53 ;
else if ( V_6 & V_54 )
V_26 -> V_29 = V_55 ;
else
V_26 -> V_29 = V_56 ;
if ( V_5 -> V_57 == 0 )
V_5 -> V_58 = V_26 -> V_29 ;
else if ( V_5 -> V_58 != V_26 -> V_29 ) {
F_16 ( & V_5 -> V_59 ) ;
F_17 ( V_5 -> V_60 ) ;
V_5 -> V_57 = 0 ;
}
} else {
if ( V_24 == V_52 )
V_26 -> V_29 = V_61 ;
else
V_26 -> V_29 = 0 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
int V_42 , enum V_23 V_24 , char * V_26 )
{
T_2 V_6 ;
V_6 = F_6 ( V_2 , V_31 [ V_42 ] . V_33 , V_26 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 ,
enum V_23 V_24 , union V_25 * V_26 )
{
#define F_20 1000
#define F_21 (10 * BASE_UNIT_CONVERSION)
#define F_22 60
#define F_23 2731
switch ( V_24 ) {
case V_62 :
case V_63 :
case V_64 :
V_26 -> V_29 *= F_21 ;
break;
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
V_26 -> V_29 *= F_20 ;
break;
case V_72 :
V_26 -> V_29 -= F_23 ;
break;
case V_73 :
case V_74 :
V_26 -> V_29 *= F_22 ;
break;
default:
F_4 ( & V_2 -> V_9 ,
L_4 , V_10 , V_24 ) ;
}
}
static enum V_75 F_24 ( struct V_1 * V_2 ,
enum V_75 V_76 )
{
int V_6 , V_77 ;
V_77 = F_1 ( V_2 , V_78 ) ;
if ( V_77 < 0 )
return V_77 ;
if ( ( V_77 & V_79 ) == V_76 )
return V_76 ;
if ( V_76 == V_80 )
V_6 = V_77 & ~ V_79 ;
else
V_6 = V_77 | V_79 ;
V_6 = F_11 ( V_2 , V_78 , V_6 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_77 & V_79 ;
}
static int F_25 ( struct V_1 * V_2 ,
int V_42 , enum V_23 V_24 ,
union V_25 * V_26 )
{
T_2 V_6 ;
enum V_75 V_76 = V_81 ;
if ( F_26 ( V_24 ) )
V_76 = V_80 ;
V_76 = F_24 ( V_2 , V_76 ) ;
if ( V_76 < 0 )
return V_76 ;
V_6 = F_1 ( V_2 , V_31 [ V_42 ] . V_33 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_24 == V_82 ) {
V_26 -> V_29 = F_27 ( V_6 , 100 ) ;
} else
V_26 -> V_29 = V_6 ;
V_6 = F_24 ( V_2 , V_76 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
union V_25 * V_26 )
{
int V_6 ;
V_6 = F_1 ( V_2 , V_31 [ V_83 ] . V_33 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = sprintf ( V_84 , L_5 , V_6 ) ;
V_26 -> V_85 = V_84 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
enum V_23 V_24 )
{
int V_86 ;
for ( V_86 = 0 ; V_86 < F_30 ( V_31 ) ; V_86 ++ )
if ( V_24 == V_31 [ V_86 ] . V_24 )
return V_86 ;
F_31 ( & V_2 -> V_9 ,
L_6 , V_10 , V_24 ) ;
return - V_21 ;
}
static int F_32 ( struct V_60 * V_87 ,
enum V_23 V_24 ,
union V_25 * V_26 )
{
int V_6 = 0 ;
struct V_4 * V_5 = F_33 ( V_87 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
switch ( V_24 ) {
case V_27 :
case V_37 :
V_6 = F_13 ( V_2 , V_24 , V_26 ) ;
if ( V_24 == V_27 )
return 0 ;
break;
case V_88 :
V_26 -> V_29 = V_89 ;
goto V_90;
case V_62 :
case V_63 :
case V_64 :
case V_69 :
case V_70 :
case V_71 :
case V_82 :
V_6 = F_29 ( V_2 , V_24 ) ;
if ( V_6 < 0 )
break;
V_6 = F_25 ( V_2 , V_6 , V_24 , V_26 ) ;
break;
case V_91 :
V_6 = F_28 ( V_2 , V_26 ) ;
break;
case V_52 :
case V_44 :
case V_92 :
case V_65 :
case V_68 :
case V_72 :
case V_73 :
case V_74 :
case V_66 :
case V_67 :
V_6 = F_29 ( V_2 , V_24 ) ;
if ( V_6 < 0 )
break;
V_6 = F_15 ( V_2 , V_6 , V_24 , V_26 ) ;
break;
case V_93 :
V_6 = F_29 ( V_2 , V_24 ) ;
if ( V_6 < 0 )
break;
V_6 = F_18 ( V_2 , V_6 , V_24 ,
V_94 ) ;
V_26 -> V_85 = V_94 ;
break;
case V_95 :
V_6 = F_29 ( V_2 , V_24 ) ;
if ( V_6 < 0 )
break;
V_6 = F_18 ( V_2 , V_6 , V_24 ,
V_96 ) ;
V_26 -> V_85 = V_96 ;
break;
default:
F_9 ( & V_2 -> V_9 ,
L_7 , V_10 ) ;
return - V_21 ;
}
if ( ! V_5 -> V_97 )
goto V_90;
if ( ! V_5 -> V_28 &&
V_5 -> V_30 != ( V_6 >= 0 ) ) {
V_5 -> V_30 = ( V_6 >= 0 ) ;
F_17 ( V_5 -> V_60 ) ;
}
V_90:
if ( ! V_6 ) {
F_19 ( V_2 , V_24 , V_26 ) ;
}
F_4 ( & V_2 -> V_9 ,
L_8 , V_10 , V_24 , V_26 -> V_29 ) ;
if ( V_6 && V_5 -> V_30 )
return V_6 ;
if ( V_6 )
return - V_98 ;
return 0 ;
}
static T_4 F_34 ( int V_99 , void * V_100 )
{
struct V_4 * V_5 = V_100 ;
struct V_60 * V_101 = V_5 -> V_60 ;
int V_6 ;
V_6 = F_14 ( V_5 -> V_28 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 -> V_30 = V_6 ;
F_17 ( V_101 ) ;
return V_102 ;
}
static void F_35 ( struct V_60 * V_87 )
{
struct V_4 * V_5 = F_33 ( V_87 ) ;
if ( V_5 -> V_103 > 0 ) {
V_5 -> V_103 -- ;
return;
}
F_16 ( & V_5 -> V_59 ) ;
F_36 ( & V_5 -> V_59 , V_104 ) ;
V_5 -> V_57 = V_5 -> V_105 ;
}
static void F_37 ( struct V_106 * V_59 )
{
struct V_4 * V_5 ;
T_2 V_6 ;
V_5 = F_38 ( V_59 , struct V_4 , V_59 . V_59 ) ;
V_6 = F_1 ( V_5 -> V_2 , V_31 [ V_107 ] . V_33 ) ;
if ( V_6 < 0 ) {
V_5 -> V_57 = 0 ;
return;
}
if ( V_6 & V_47 )
V_6 = V_53 ;
else if ( V_6 & V_54 )
V_6 = V_55 ;
else
V_6 = V_56 ;
if ( V_5 -> V_58 != V_6 ) {
V_5 -> V_57 = 0 ;
F_17 ( V_5 -> V_60 ) ;
return;
}
if ( V_5 -> V_57 > 0 ) {
F_36 ( & V_5 -> V_59 , V_104 ) ;
V_5 -> V_57 -- ;
return;
}
}
static int F_39 ( struct V_1 * V_2 ,
const struct V_108 * V_109 )
{
struct V_4 * V_5 ;
struct V_110 * V_111 ;
struct V_112 * V_113 = V_2 -> V_9 . V_114 ;
struct V_115 V_116 = {} ;
int V_117 ;
int V_99 ;
V_111 = F_40 ( & V_2 -> V_9 , & V_118 ,
sizeof( * V_111 ) , V_119 ) ;
if ( ! V_111 )
return - V_120 ;
V_111 -> V_121 = F_41 ( & V_2 -> V_9 , V_119 , L_9 ,
F_42 ( & V_2 -> V_9 ) ) ;
if ( ! V_111 -> V_121 )
return - V_120 ;
V_5 = F_43 ( & V_2 -> V_9 , sizeof( struct V_4 ) , V_119 ) ;
if ( ! V_5 )
return - V_120 ;
V_5 -> V_2 = V_2 ;
V_5 -> V_97 = false ;
V_116 . V_122 = V_2 -> V_9 . V_122 ;
V_116 . V_123 = V_5 ;
V_5 -> V_103 = 1 ;
V_5 -> V_58 = V_61 ;
V_117 = F_44 ( V_2 -> V_9 . V_122 , L_10 ,
& V_5 -> V_8 ) ;
if ( V_117 )
V_5 -> V_8 = 0 ;
V_117 = F_44 ( V_2 -> V_9 . V_122 , L_11 ,
& V_5 -> V_105 ) ;
if ( V_117 )
V_5 -> V_105 = 0 ;
if ( V_113 ) {
V_5 -> V_105 = V_113 -> V_105 ;
V_5 -> V_8 = V_113 -> V_8 ;
}
V_5 -> V_8 = V_5 -> V_8 + 1 ;
V_5 -> V_28 = F_45 ( & V_2 -> V_9 ,
L_12 , V_124 ) ;
if ( F_46 ( V_5 -> V_28 ) ) {
F_9 ( & V_2 -> V_9 , L_13 ,
F_47 ( V_5 -> V_28 ) ) ;
return F_47 ( V_5 -> V_28 ) ;
}
F_48 ( V_2 , V_5 ) ;
if ( ! V_5 -> V_28 )
goto V_125;
V_99 = F_49 ( V_5 -> V_28 ) ;
if ( V_99 <= 0 ) {
F_31 ( & V_2 -> V_9 , L_14 , V_99 ) ;
goto V_125;
}
V_117 = F_50 ( & V_2 -> V_9 , V_99 , NULL , F_34 ,
V_126 | V_127 ,
F_42 ( & V_2 -> V_9 ) , V_5 ) ;
if ( V_117 ) {
F_31 ( & V_2 -> V_9 , L_15 , V_117 ) ;
goto V_125;
}
V_125:
if ( ! ( V_128 || V_5 -> V_28 ) ) {
V_117 = F_1 ( V_2 , V_31 [ V_107 ] . V_33 ) ;
if ( V_117 < 0 ) {
F_9 ( & V_2 -> V_9 , L_16 ,
V_10 ) ;
goto V_129;
}
}
V_5 -> V_60 = F_51 ( & V_2 -> V_9 , V_111 ,
& V_116 ) ;
if ( F_46 ( V_5 -> V_60 ) ) {
F_9 ( & V_2 -> V_9 ,
L_17 , V_10 ) ;
V_117 = F_47 ( V_5 -> V_60 ) ;
goto V_129;
}
F_52 ( & V_2 -> V_9 ,
L_18 , V_2 -> V_121 ) ;
F_53 ( & V_5 -> V_59 , F_37 ) ;
V_5 -> V_97 = true ;
return 0 ;
V_129:
return V_117 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_16 ( & V_5 -> V_59 ) ;
return 0 ;
}
static int F_55 ( struct V_130 * V_9 )
{
struct V_1 * V_2 = F_56 ( V_9 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_57 > 0 )
F_16 ( & V_5 -> V_59 ) ;
F_11 ( V_2 , V_31 [ V_32 ] . V_33 ,
V_131 ) ;
return 0 ;
}
