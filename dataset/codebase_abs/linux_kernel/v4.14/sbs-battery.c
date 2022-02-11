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
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 ,
char * V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 = 0 , V_12 = 0 ;
int V_13 = 1 , V_14 = 1 ;
T_1 V_15 [ V_16 + 1 ] ;
V_13 = V_5 -> V_8 ;
V_14 = V_5 -> V_8 ;
if ( ! F_6 ( V_2 -> V_17 ,
V_18 |
V_19 ) ) {
return - V_20 ;
}
while ( V_13 > 0 ) {
V_6 = F_7 ( V_2 , V_3 ) ;
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
F_8 ( & V_2 -> V_9 ,
L_2 ,
V_10 , V_16 ) ;
return - V_21 ;
}
while ( V_14 > 0 ) {
V_6 = F_9 (
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
return V_6 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 ,
T_3 V_22 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 = 0 ;
int V_7 = 1 ;
V_7 = V_5 -> V_8 ;
while ( V_7 > 0 ) {
V_6 = F_11 ( V_2 , V_3 , V_22 ) ;
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
static int F_12 ( struct V_1 * V_2 , int * V_23 )
{
int V_6 ;
V_6 = F_1 ( V_2 , V_24 [ V_25 ] . V_26 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = ( V_27 ) V_6 ;
if ( V_6 == 0 )
* V_23 = V_28 ;
if ( * V_23 == V_28 ) {
if ( V_6 > 0 )
* V_23 = V_29 ;
else if ( V_6 < 0 )
* V_23 = V_30 ;
}
return 0 ;
}
static int F_13 (
struct V_1 * V_2 , enum V_31 V_32 ,
union V_33 * V_34 )
{
T_2 V_6 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_32 == V_35 && V_5 -> V_36 ) {
V_6 = F_14 ( V_5 -> V_36 ) ;
if ( V_6 < 0 )
return V_6 ;
V_34 -> V_23 = V_6 ;
V_5 -> V_37 = V_34 -> V_23 ;
return V_6 ;
}
F_10 ( V_2 , V_24 [ V_38 ] . V_26 ,
V_39 ) ;
V_6 = F_1 ( V_2 , V_24 [ V_38 ] . V_26 ) ;
if ( V_6 < 0 ) {
if ( V_32 == V_35 )
V_34 -> V_23 = 0 ;
return V_6 ;
}
if ( V_6 < V_24 [ V_38 ] . V_40 ||
V_6 > V_24 [ V_38 ] . V_41 ) {
V_34 -> V_23 = 0 ;
return 0 ;
}
V_6 &= 0x0F00 ;
V_6 >>= 8 ;
if ( V_32 == V_35 ) {
if ( V_6 == 0x0F )
V_34 -> V_23 = 0 ;
else
V_34 -> V_23 = 1 ;
} else if ( V_32 == V_42 ) {
if ( V_6 == 0x09 )
V_34 -> V_23 = V_43 ;
else if ( V_6 == 0x0B )
V_34 -> V_23 = V_44 ;
else if ( V_6 == 0x0C )
V_34 -> V_23 = V_45 ;
else
V_34 -> V_23 = V_46 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
int V_47 , enum V_31 V_32 ,
union V_33 * V_34 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 ;
V_6 = F_1 ( V_2 , V_24 [ V_47 ] . V_26 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_24 [ V_47 ] . V_40 < 0 )
V_6 = ( V_27 ) V_6 ;
if ( V_6 >= V_24 [ V_47 ] . V_40 &&
V_6 <= V_24 [ V_47 ] . V_41 ) {
V_34 -> V_23 = V_6 ;
if ( V_32 == V_48 ) {
if ( ! ( V_6 & V_49 ) )
V_34 -> V_23 =
V_50 ;
else if ( V_6 & V_51 )
V_34 -> V_23 =
V_52 ;
else if ( V_6 & V_53 )
V_34 -> V_23 =
V_54 ;
else
V_34 -> V_23 =
V_55 ;
return 0 ;
} else if ( V_32 != V_56 ) {
return 0 ;
}
if ( V_6 & V_51 )
V_34 -> V_23 = V_28 ;
else if ( V_6 & V_57 )
V_34 -> V_23 = V_30 ;
else
V_34 -> V_23 = V_29 ;
F_12 ( V_2 , & V_34 -> V_23 ) ;
if ( V_5 -> V_58 == 0 )
V_5 -> V_59 = V_34 -> V_23 ;
else if ( V_5 -> V_59 != V_34 -> V_23 ) {
F_16 ( & V_5 -> V_60 ) ;
F_17 ( V_5 -> V_61 ) ;
V_5 -> V_58 = 0 ;
}
} else {
if ( V_32 == V_56 )
V_34 -> V_23 = V_62 ;
else if ( V_32 == V_63 )
V_34 -> V_23 = F_18 ( V_6 , 100 ) ;
else
V_34 -> V_23 = 0 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
int V_47 , enum V_31 V_32 , char * V_34 )
{
T_2 V_6 ;
V_6 = F_5 ( V_2 , V_24 [ V_47 ] . V_26 , V_34 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 ,
enum V_31 V_32 , union V_33 * V_34 )
{
#define F_21 1000
#define F_22 (10 * BASE_UNIT_CONVERSION)
#define F_23 60
#define F_24 2731
switch ( V_32 ) {
case V_64 :
case V_65 :
case V_66 :
V_34 -> V_23 *= F_22 ;
break;
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
V_34 -> V_23 *= F_21 ;
break;
case V_74 :
V_34 -> V_23 -= F_24 ;
break;
case V_75 :
case V_76 :
V_34 -> V_23 *= F_23 ;
break;
default:
F_4 ( & V_2 -> V_9 ,
L_4 , V_10 , V_32 ) ;
}
}
static enum V_77 F_25 ( struct V_1 * V_2 ,
enum V_77 V_78 )
{
int V_6 , V_79 ;
V_79 = F_1 ( V_2 , V_80 ) ;
if ( V_79 < 0 )
return V_79 ;
if ( ( V_79 & V_81 ) == V_78 )
return V_78 ;
if ( V_78 == V_82 )
V_6 = V_79 & ~ V_81 ;
else
V_6 = V_79 | V_81 ;
V_6 = F_10 ( V_2 , V_80 , V_6 ) ;
if ( V_6 < 0 )
return V_6 ;
F_26 ( 1000 , 2000 ) ;
return V_79 & V_81 ;
}
static int F_27 ( struct V_1 * V_2 ,
int V_47 , enum V_31 V_32 ,
union V_33 * V_34 )
{
T_2 V_6 ;
enum V_77 V_78 = V_83 ;
if ( F_28 ( V_32 ) )
V_78 = V_82 ;
V_78 = F_25 ( V_2 , V_78 ) ;
if ( V_78 < 0 )
return V_78 ;
V_6 = F_1 ( V_2 , V_24 [ V_47 ] . V_26 ) ;
if ( V_6 < 0 )
return V_6 ;
V_34 -> V_23 = V_6 ;
V_6 = F_25 ( V_2 , V_78 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
union V_33 * V_34 )
{
int V_6 ;
V_6 = F_1 ( V_2 , V_24 [ V_84 ] . V_26 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = sprintf ( V_85 , L_5 , V_6 ) ;
V_34 -> V_86 = V_85 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
enum V_31 V_32 )
{
int V_87 ;
for ( V_87 = 0 ; V_87 < F_31 ( V_24 ) ; V_87 ++ )
if ( V_32 == V_24 [ V_87 ] . V_32 )
return V_87 ;
F_32 ( & V_2 -> V_9 ,
L_6 , V_10 , V_32 ) ;
return - V_21 ;
}
static int F_33 ( struct V_61 * V_88 ,
enum V_31 V_32 ,
union V_33 * V_34 )
{
int V_6 = 0 ;
struct V_4 * V_5 = F_34 ( V_88 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
switch ( V_32 ) {
case V_35 :
case V_42 :
V_6 = F_13 ( V_2 , V_32 , V_34 ) ;
if ( V_32 == V_35 )
return 0 ;
break;
case V_89 :
V_34 -> V_23 = V_90 ;
goto V_91;
case V_64 :
case V_65 :
case V_66 :
case V_71 :
case V_72 :
case V_73 :
V_6 = F_30 ( V_2 , V_32 ) ;
if ( V_6 < 0 )
break;
F_35 ( & V_5 -> V_92 ) ;
V_6 = F_27 ( V_2 , V_6 , V_32 , V_34 ) ;
F_36 ( & V_5 -> V_92 ) ;
break;
case V_93 :
V_6 = F_29 ( V_2 , V_34 ) ;
break;
case V_56 :
case V_48 :
case V_94 :
case V_67 :
case V_70 :
case V_74 :
case V_75 :
case V_76 :
case V_68 :
case V_69 :
case V_63 :
V_6 = F_30 ( V_2 , V_32 ) ;
if ( V_6 < 0 )
break;
V_6 = F_15 ( V_2 , V_6 , V_32 , V_34 ) ;
break;
case V_95 :
V_6 = F_30 ( V_2 , V_32 ) ;
if ( V_6 < 0 )
break;
V_6 = F_19 ( V_2 , V_6 , V_32 ,
V_96 ) ;
V_34 -> V_86 = V_96 ;
break;
case V_97 :
V_6 = F_30 ( V_2 , V_32 ) ;
if ( V_6 < 0 )
break;
V_6 = F_19 ( V_2 , V_6 , V_32 ,
V_98 ) ;
V_34 -> V_86 = V_98 ;
break;
default:
F_8 ( & V_2 -> V_9 ,
L_7 , V_10 ) ;
return - V_21 ;
}
if ( ! V_5 -> V_99 )
goto V_91;
if ( ! V_5 -> V_36 &&
V_5 -> V_37 != ( V_6 >= 0 ) ) {
V_5 -> V_37 = ( V_6 >= 0 ) ;
F_17 ( V_5 -> V_61 ) ;
}
V_91:
if ( ! V_6 ) {
F_20 ( V_2 , V_32 , V_34 ) ;
}
F_4 ( & V_2 -> V_9 ,
L_8 , V_10 , V_32 , V_34 -> V_23 ) ;
if ( V_6 && V_5 -> V_37 )
return V_6 ;
if ( V_6 )
return - V_100 ;
return 0 ;
}
static void F_37 ( struct V_4 * V_5 )
{
struct V_61 * V_101 = V_5 -> V_61 ;
int V_6 ;
V_6 = F_14 ( V_5 -> V_36 ) ;
if ( V_6 < 0 )
return;
V_5 -> V_37 = V_6 ;
F_17 ( V_101 ) ;
}
static T_4 F_38 ( int V_102 , void * V_103 )
{
F_37 ( V_103 ) ;
return V_104 ;
}
static void F_39 ( struct V_1 * V_2 , enum V_105 V_106 ,
unsigned int V_107 )
{
F_37 ( F_2 ( V_2 ) ) ;
}
static void F_40 ( struct V_61 * V_88 )
{
struct V_4 * V_5 = F_34 ( V_88 ) ;
F_16 ( & V_5 -> V_60 ) ;
F_41 ( & V_5 -> V_60 , V_108 ) ;
V_5 -> V_58 = V_5 -> V_109 ;
}
static void F_42 ( struct V_110 * V_60 )
{
struct V_4 * V_5 ;
T_2 V_6 ;
V_5 = F_43 ( V_60 , struct V_4 , V_60 . V_60 ) ;
V_6 = F_1 ( V_5 -> V_2 , V_24 [ V_111 ] . V_26 ) ;
if ( V_6 < 0 ) {
V_5 -> V_58 = 0 ;
return;
}
if ( V_6 & V_51 )
V_6 = V_28 ;
else if ( V_6 & V_57 )
V_6 = V_30 ;
else
V_6 = V_29 ;
F_12 ( V_5 -> V_2 , & V_6 ) ;
if ( V_5 -> V_59 != V_6 ) {
V_5 -> V_58 = 0 ;
F_17 ( V_5 -> V_61 ) ;
return;
}
if ( V_5 -> V_58 > 0 ) {
F_41 ( & V_5 -> V_60 , V_108 ) ;
V_5 -> V_58 -- ;
return;
}
}
static int F_44 ( struct V_1 * V_2 ,
const struct V_112 * V_113 )
{
struct V_4 * V_5 ;
struct V_114 * V_115 ;
struct V_116 * V_117 = V_2 -> V_9 . V_118 ;
struct V_119 V_120 = {} ;
int V_121 ;
int V_102 ;
V_115 = F_45 ( & V_2 -> V_9 , & V_122 ,
sizeof( * V_115 ) , V_123 ) ;
if ( ! V_115 )
return - V_124 ;
V_115 -> V_125 = F_46 ( & V_2 -> V_9 , V_123 , L_9 ,
F_47 ( & V_2 -> V_9 ) ) ;
if ( ! V_115 -> V_125 )
return - V_124 ;
V_5 = F_48 ( & V_2 -> V_9 , sizeof( struct V_4 ) , V_123 ) ;
if ( ! V_5 )
return - V_124 ;
V_5 -> V_2 = V_2 ;
V_5 -> V_99 = false ;
V_120 . V_126 = V_2 -> V_9 . V_126 ;
V_120 . V_127 = V_5 ;
V_5 -> V_59 = V_62 ;
F_49 ( & V_5 -> V_92 ) ;
V_121 = F_50 ( V_2 -> V_9 . V_126 , L_10 ,
& V_5 -> V_8 ) ;
if ( V_121 )
V_5 -> V_8 = 0 ;
V_121 = F_50 ( V_2 -> V_9 . V_126 , L_11 ,
& V_5 -> V_109 ) ;
if ( V_121 )
V_5 -> V_109 = 0 ;
if ( V_117 ) {
V_5 -> V_109 = V_117 -> V_109 ;
V_5 -> V_8 = V_117 -> V_8 ;
}
V_5 -> V_8 = V_5 -> V_8 + 1 ;
V_5 -> V_36 = F_51 ( & V_2 -> V_9 ,
L_12 , V_128 ) ;
if ( F_52 ( V_5 -> V_36 ) ) {
F_8 ( & V_2 -> V_9 , L_13 ,
F_53 ( V_5 -> V_36 ) ) ;
return F_53 ( V_5 -> V_36 ) ;
}
F_54 ( V_2 , V_5 ) ;
if ( ! V_5 -> V_36 )
goto V_129;
V_102 = F_55 ( V_5 -> V_36 ) ;
if ( V_102 <= 0 ) {
F_32 ( & V_2 -> V_9 , L_14 , V_102 ) ;
goto V_129;
}
V_121 = F_56 ( & V_2 -> V_9 , V_102 , NULL , F_38 ,
V_130 | V_131 | V_132 ,
F_47 ( & V_2 -> V_9 ) , V_5 ) ;
if ( V_121 ) {
F_32 ( & V_2 -> V_9 , L_15 , V_121 ) ;
goto V_129;
}
V_129:
if ( ! ( V_133 || V_5 -> V_36 ) ) {
V_121 = F_1 ( V_2 , V_24 [ V_111 ] . V_26 ) ;
if ( V_121 < 0 ) {
F_8 ( & V_2 -> V_9 , L_16 ,
V_10 ) ;
goto V_134;
}
}
V_5 -> V_61 = F_57 ( & V_2 -> V_9 , V_115 ,
& V_120 ) ;
if ( F_52 ( V_5 -> V_61 ) ) {
F_8 ( & V_2 -> V_9 ,
L_17 , V_10 ) ;
V_121 = F_53 ( V_5 -> V_61 ) ;
goto V_134;
}
F_58 ( & V_2 -> V_9 ,
L_18 , V_2 -> V_125 ) ;
F_59 ( & V_5 -> V_60 , F_42 ) ;
V_5 -> V_99 = true ;
return 0 ;
V_134:
return V_121 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_16 ( & V_5 -> V_60 ) ;
return 0 ;
}
static int F_61 ( struct V_135 * V_9 )
{
struct V_1 * V_2 = F_62 ( V_9 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_58 > 0 )
F_16 ( & V_5 -> V_60 ) ;
F_10 ( V_2 , V_24 [ V_38 ] . V_26 ,
V_136 ) ;
return 0 ;
}
