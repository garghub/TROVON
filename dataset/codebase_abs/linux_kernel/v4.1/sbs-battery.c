static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 = 0 ;
int V_7 = 1 ;
if ( V_5 -> V_8 )
V_7 = F_3 ( V_5 -> V_8 -> V_9 + 1 , 1 ) ;
while ( V_7 > 0 ) {
V_6 = F_4 ( V_2 , V_3 ) ;
if ( V_6 >= 0 )
break;
V_7 -- ;
}
if ( V_6 < 0 ) {
F_5 ( & V_2 -> V_10 ,
L_1 ,
V_11 , V_3 ) ;
return V_6 ;
}
return F_6 ( V_6 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 ,
char * V_12 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 = 0 , V_13 = 0 ;
int V_14 = 1 , V_15 = 1 ;
T_1 V_16 [ V_17 + 1 ] ;
if ( V_5 -> V_8 ) {
V_14 = F_3 ( V_5 -> V_8 -> V_9 + 1 , 1 ) ;
V_15 = F_3 ( V_5 -> V_8 -> V_9 + 1 , 1 ) ;
}
if ( ! F_8 ( V_2 -> V_18 ,
V_19 |
V_20 ) ) {
return - V_21 ;
}
while ( V_14 > 0 ) {
V_6 = F_9 ( V_2 , V_3 ) ;
if ( V_6 >= 0 )
break;
V_14 -- ;
}
if ( V_6 < 0 ) {
F_5 ( & V_2 -> V_10 ,
L_1 ,
V_11 , V_3 ) ;
return V_6 ;
}
V_13 = V_6 ;
if ( V_13 > V_17 ) {
F_10 ( & V_2 -> V_10 ,
L_2 ,
V_11 , V_17 ) ;
return - V_22 ;
}
while ( V_15 > 0 ) {
V_6 = F_11 (
V_2 , V_3 ,
V_13 + 1 , V_16 ) ;
if ( V_6 >= 0 )
break;
V_15 -- ;
}
if ( V_6 < 0 ) {
F_5 ( & V_2 -> V_10 ,
L_1 ,
V_11 , V_3 ) ;
return V_6 ;
}
memcpy ( V_12 , V_16 + 1 , V_13 ) ;
V_12 [ V_13 ] = '\0' ;
return F_6 ( V_6 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_3 ,
T_3 V_23 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 = 0 ;
int V_7 = 1 ;
if ( V_5 -> V_8 )
V_7 = F_3 ( V_5 -> V_8 -> V_9 + 1 , 1 ) ;
while ( V_7 > 0 ) {
V_6 = F_13 ( V_2 , V_3 ,
F_6 ( V_23 ) ) ;
if ( V_6 >= 0 )
break;
V_7 -- ;
}
if ( V_6 < 0 ) {
F_5 ( & V_2 -> V_10 ,
L_3 ,
V_11 , V_3 ) ;
return V_6 ;
}
return 0 ;
}
static int F_14 (
struct V_1 * V_2 , enum V_24 V_25 ,
union V_26 * V_27 )
{
T_2 V_6 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_25 == V_28 &&
V_5 -> V_29 ) {
V_6 = F_15 ( V_5 -> V_8 -> V_30 ) ;
if ( V_6 == V_5 -> V_8 -> V_31 )
V_27 -> V_32 = 1 ;
else
V_27 -> V_32 = 0 ;
V_5 -> V_33 = V_27 -> V_32 ;
return V_6 ;
}
V_6 = F_12 ( V_2 , V_34 [ V_35 ] . V_36 ,
V_37 ) ;
if ( V_6 < 0 ) {
if ( V_25 == V_28 )
V_27 -> V_32 = 0 ;
return V_6 ;
}
V_6 = F_1 ( V_2 , V_34 [ V_35 ] . V_36 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 < V_34 [ V_35 ] . V_38 ||
V_6 > V_34 [ V_35 ] . V_39 ) {
V_27 -> V_32 = 0 ;
return 0 ;
}
V_6 &= 0x0F00 ;
V_6 >>= 8 ;
if ( V_25 == V_28 ) {
if ( V_6 == 0x0F )
V_27 -> V_32 = 0 ;
else
V_27 -> V_32 = 1 ;
} else if ( V_25 == V_40 ) {
if ( V_6 == 0x09 )
V_27 -> V_32 = V_41 ;
else if ( V_6 == 0x0B )
V_27 -> V_32 = V_42 ;
else if ( V_6 == 0x0C )
V_27 -> V_32 = V_43 ;
else
V_27 -> V_32 = V_44 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
int V_45 , enum V_24 V_25 ,
union V_26 * V_27 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 ;
V_6 = F_1 ( V_2 , V_34 [ V_45 ] . V_36 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_34 [ V_45 ] . V_38 < 0 )
V_6 = ( V_46 ) V_6 ;
if ( V_6 >= V_34 [ V_45 ] . V_38 &&
V_6 <= V_34 [ V_45 ] . V_39 ) {
V_27 -> V_32 = V_6 ;
if ( V_25 != V_47 )
return 0 ;
if ( V_6 & V_48 )
V_27 -> V_32 = V_49 ;
else if ( V_6 & V_50 )
V_27 -> V_32 = V_51 ;
else if ( V_6 & V_52 )
V_27 -> V_32 = V_53 ;
else
V_27 -> V_32 = V_54 ;
if ( V_5 -> V_55 == 0 )
V_5 -> V_56 = V_27 -> V_32 ;
else if ( V_5 -> V_56 != V_27 -> V_32 ) {
F_17 ( & V_5 -> V_57 ) ;
F_18 ( V_5 -> V_58 ) ;
V_5 -> V_55 = 0 ;
}
} else {
if ( V_25 == V_47 )
V_27 -> V_32 = V_59 ;
else
V_27 -> V_32 = 0 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
int V_45 , enum V_24 V_25 , char * V_27 )
{
T_2 V_6 ;
V_6 = F_7 ( V_2 , V_34 [ V_45 ] . V_36 , V_27 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 ,
enum V_24 V_25 , union V_26 * V_27 )
{
#define F_21 1000
#define F_22 (10 * BASE_UNIT_CONVERSION)
#define F_23 60
#define F_24 2731
switch ( V_25 ) {
case V_60 :
case V_61 :
case V_62 :
V_27 -> V_32 *= F_22 ;
break;
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
V_27 -> V_32 *= F_21 ;
break;
case V_70 :
V_27 -> V_32 -= F_24 ;
break;
case V_71 :
case V_72 :
V_27 -> V_32 *= F_23 ;
break;
default:
F_5 ( & V_2 -> V_10 ,
L_4 , V_11 , V_25 ) ;
}
}
static enum V_73 F_25 ( struct V_1 * V_2 ,
enum V_73 V_74 )
{
int V_6 , V_75 ;
V_75 = F_1 ( V_2 , V_76 ) ;
if ( V_75 < 0 )
return V_75 ;
if ( ( V_75 & V_77 ) == V_74 )
return V_74 ;
if ( V_74 == V_78 )
V_6 = V_75 & ~ V_77 ;
else
V_6 = V_75 | V_77 ;
V_6 = F_12 ( V_2 , V_76 , V_6 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_75 & V_77 ;
}
static int F_26 ( struct V_1 * V_2 ,
int V_45 , enum V_24 V_25 ,
union V_26 * V_27 )
{
T_2 V_6 ;
enum V_73 V_74 = V_79 ;
if ( F_27 ( V_25 ) )
V_74 = V_78 ;
V_74 = F_25 ( V_2 , V_74 ) ;
if ( V_74 < 0 )
return V_74 ;
V_6 = F_1 ( V_2 , V_34 [ V_45 ] . V_36 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_25 == V_80 ) {
V_27 -> V_32 = F_28 ( V_6 , 100 ) ;
} else
V_27 -> V_32 = V_6 ;
V_6 = F_25 ( V_2 , V_74 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
union V_26 * V_27 )
{
int V_6 ;
V_6 = F_1 ( V_2 , V_34 [ V_81 ] . V_36 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = sprintf ( V_82 , L_5 , V_6 ) ;
V_27 -> V_83 = V_82 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
enum V_24 V_25 )
{
int V_84 ;
for ( V_84 = 0 ; V_84 < F_31 ( V_34 ) ; V_84 ++ )
if ( V_25 == V_34 [ V_84 ] . V_25 )
return V_84 ;
F_32 ( & V_2 -> V_10 ,
L_6 , V_11 , V_25 ) ;
return - V_22 ;
}
static int F_33 ( struct V_58 * V_85 ,
enum V_24 V_25 ,
union V_26 * V_27 )
{
int V_6 = 0 ;
struct V_4 * V_5 = F_34 ( V_85 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
switch ( V_25 ) {
case V_28 :
case V_40 :
V_6 = F_14 ( V_2 , V_25 , V_27 ) ;
if ( V_25 == V_28 )
return 0 ;
break;
case V_86 :
V_27 -> V_32 = V_87 ;
goto V_88;
case V_60 :
case V_61 :
case V_62 :
case V_67 :
case V_68 :
case V_69 :
case V_80 :
V_6 = F_30 ( V_2 , V_25 ) ;
if ( V_6 < 0 )
break;
V_6 = F_26 ( V_2 , V_6 , V_25 , V_27 ) ;
break;
case V_89 :
V_6 = F_29 ( V_2 , V_27 ) ;
break;
case V_47 :
case V_90 :
case V_63 :
case V_66 :
case V_70 :
case V_71 :
case V_72 :
case V_64 :
case V_65 :
V_6 = F_30 ( V_2 , V_25 ) ;
if ( V_6 < 0 )
break;
V_6 = F_16 ( V_2 , V_6 , V_25 , V_27 ) ;
break;
case V_91 :
V_6 = F_30 ( V_2 , V_25 ) ;
if ( V_6 < 0 )
break;
V_6 = F_19 ( V_2 , V_6 , V_25 ,
V_92 ) ;
V_27 -> V_83 = V_92 ;
break;
case V_93 :
V_6 = F_30 ( V_2 , V_25 ) ;
if ( V_6 < 0 )
break;
V_6 = F_19 ( V_2 , V_6 , V_25 ,
V_94 ) ;
V_27 -> V_83 = V_94 ;
break;
default:
F_10 ( & V_2 -> V_10 ,
L_7 , V_11 ) ;
return - V_22 ;
}
if ( ! V_5 -> V_95 )
goto V_88;
if ( ! V_5 -> V_29 &&
V_5 -> V_33 != ( V_6 >= 0 ) ) {
V_5 -> V_33 = ( V_6 >= 0 ) ;
F_18 ( V_5 -> V_58 ) ;
}
V_88:
if ( ! V_6 ) {
F_20 ( V_2 , V_25 , V_27 ) ;
}
F_5 ( & V_2 -> V_10 ,
L_8 , V_11 , V_25 , V_27 -> V_32 ) ;
if ( V_6 && V_5 -> V_33 )
return V_6 ;
if ( V_6 )
return - V_96 ;
return 0 ;
}
static T_4 F_35 ( int V_97 , void * V_98 )
{
struct V_58 * V_99 = V_98 ;
F_18 ( V_99 ) ;
return V_100 ;
}
static void F_36 ( struct V_58 * V_85 )
{
struct V_4 * V_5 = F_34 ( V_85 ) ;
if ( V_5 -> V_101 > 0 ) {
V_5 -> V_101 -- ;
return;
}
F_17 ( & V_5 -> V_57 ) ;
F_37 ( & V_5 -> V_57 , V_102 ) ;
V_5 -> V_55 = V_5 -> V_8 -> V_103 ;
}
static void F_38 ( struct V_104 * V_57 )
{
struct V_4 * V_5 ;
T_2 V_6 ;
V_5 = F_39 ( V_57 , struct V_4 , V_57 . V_57 ) ;
V_6 = F_1 ( V_5 -> V_2 , V_34 [ V_105 ] . V_36 ) ;
if ( V_6 < 0 ) {
V_5 -> V_55 = 0 ;
return;
}
if ( V_6 & V_48 )
V_6 = V_49 ;
else if ( V_6 & V_50 )
V_6 = V_51 ;
else if ( V_6 & V_52 )
V_6 = V_53 ;
else
V_6 = V_54 ;
if ( V_5 -> V_56 != V_6 ) {
V_5 -> V_55 = 0 ;
F_18 ( V_5 -> V_58 ) ;
return;
}
if ( V_5 -> V_55 > 0 ) {
F_37 ( & V_5 -> V_57 , V_102 ) ;
V_5 -> V_55 -- ;
return;
}
}
static struct V_106 * F_40 (
struct V_1 * V_2 )
{
struct V_107 * V_108 = V_2 -> V_10 . V_108 ;
struct V_106 * V_8 = V_2 -> V_10 . V_109 ;
enum V_110 V_111 ;
int V_112 ;
T_5 V_113 ;
if ( ! V_108 )
return NULL ;
if ( V_8 )
return V_8 ;
if ( ! F_41 ( V_108 , L_9 , NULL ) &&
! F_41 ( V_108 , L_10 , NULL ) &&
! F_41 ( V_108 , L_11 , NULL ) )
goto V_114;
V_8 = F_42 ( & V_2 -> V_10 , sizeof( struct V_106 ) ,
V_115 ) ;
if ( ! V_8 )
goto V_114;
V_112 = F_43 ( V_108 , L_9 , & V_113 ) ;
if ( ! V_112 )
V_8 -> V_9 = V_113 ;
V_112 = F_43 ( V_108 , L_10 , & V_113 ) ;
if ( ! V_112 )
V_8 -> V_103 = V_113 ;
if ( ! F_41 ( V_108 , L_11 , NULL ) ) {
V_8 -> V_30 = - 1 ;
goto V_114;
}
V_8 -> V_30 = F_44 ( V_108 ,
L_11 , 0 , & V_111 ) ;
if ( V_111 & V_116 )
V_8 -> V_31 = 0 ;
else
V_8 -> V_31 = 1 ;
V_114:
return V_8 ;
}
static struct V_106 * F_40 (
struct V_1 * V_2 )
{
return V_2 -> V_10 . V_109 ;
}
static int F_45 ( struct V_1 * V_2 ,
const struct V_117 * V_118 )
{
struct V_4 * V_5 ;
struct V_119 * V_120 ;
struct V_106 * V_8 = V_2 -> V_10 . V_109 ;
struct V_121 V_122 = {} ;
int V_112 ;
int V_97 ;
V_120 = F_46 ( & V_2 -> V_10 , & V_123 ,
sizeof( * V_120 ) , V_115 ) ;
if ( ! V_120 )
return - V_124 ;
V_120 -> V_125 = F_47 ( & V_2 -> V_10 , V_115 , L_12 ,
F_48 ( & V_2 -> V_10 ) ) ;
if ( ! V_120 -> V_125 )
return - V_124 ;
V_5 = F_49 ( sizeof( struct V_4 ) , V_115 ) ;
if ( ! V_5 )
return - V_124 ;
V_5 -> V_2 = V_2 ;
V_5 -> V_95 = false ;
V_5 -> V_29 = false ;
V_122 . V_108 = V_2 -> V_10 . V_108 ;
V_122 . V_126 = V_5 ;
V_5 -> V_101 = 1 ;
V_5 -> V_56 = V_59 ;
V_8 = F_40 ( V_2 ) ;
if ( V_8 ) {
V_5 -> V_29 = F_50 ( V_8 -> V_30 ) ;
V_5 -> V_8 = V_8 ;
}
F_51 ( V_2 , V_5 ) ;
if ( ! V_5 -> V_29 )
goto V_127;
V_112 = F_52 ( V_8 -> V_30 , F_48 ( & V_2 -> V_10 ) ) ;
if ( V_112 ) {
F_32 ( & V_2 -> V_10 , L_13 , V_112 ) ;
V_5 -> V_29 = false ;
goto V_127;
}
V_112 = F_53 ( V_8 -> V_30 ) ;
if ( V_112 ) {
F_32 ( & V_2 -> V_10 , L_14 , V_112 ) ;
F_54 ( V_8 -> V_30 ) ;
V_5 -> V_29 = false ;
goto V_127;
}
V_97 = F_55 ( V_8 -> V_30 ) ;
if ( V_97 <= 0 ) {
F_32 ( & V_2 -> V_10 , L_15 , V_97 ) ;
F_54 ( V_8 -> V_30 ) ;
V_5 -> V_29 = false ;
goto V_127;
}
V_112 = F_56 ( V_97 , F_35 ,
V_128 | V_129 ,
F_48 ( & V_2 -> V_10 ) , V_5 -> V_58 ) ;
if ( V_112 ) {
F_32 ( & V_2 -> V_10 , L_16 , V_112 ) ;
F_54 ( V_8 -> V_30 ) ;
V_5 -> V_29 = false ;
goto V_127;
}
V_5 -> V_97 = V_97 ;
V_127:
V_112 = F_1 ( V_2 , V_34 [ V_105 ] . V_36 ) ;
if ( V_112 < 0 ) {
F_10 ( & V_2 -> V_10 , L_17 ,
V_11 ) ;
goto V_130;
}
V_5 -> V_58 = F_57 ( & V_2 -> V_10 , V_120 ,
& V_122 ) ;
if ( F_58 ( V_5 -> V_58 ) ) {
F_10 ( & V_2 -> V_10 ,
L_18 , V_11 ) ;
V_112 = F_59 ( V_5 -> V_58 ) ;
goto V_130;
}
F_60 ( & V_2 -> V_10 ,
L_19 , V_2 -> V_125 ) ;
F_61 ( & V_5 -> V_57 , F_38 ) ;
V_5 -> V_95 = true ;
return 0 ;
V_130:
if ( V_5 -> V_97 )
F_62 ( V_5 -> V_97 , V_5 -> V_58 ) ;
if ( V_5 -> V_29 )
F_54 ( V_8 -> V_30 ) ;
F_63 ( V_5 ) ;
return V_112 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_97 )
F_62 ( V_5 -> V_97 , V_5 -> V_58 ) ;
if ( V_5 -> V_29 )
F_54 ( V_5 -> V_8 -> V_30 ) ;
F_65 ( V_5 -> V_58 ) ;
F_17 ( & V_5 -> V_57 ) ;
F_63 ( V_5 ) ;
V_5 = NULL ;
return 0 ;
}
static int F_66 ( struct V_131 * V_10 )
{
struct V_1 * V_2 = F_67 ( V_10 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 ;
if ( V_5 -> V_55 > 0 )
F_17 ( & V_5 -> V_57 ) ;
V_6 = F_12 ( V_2 , V_34 [ V_35 ] . V_36 ,
V_132 ) ;
if ( V_5 -> V_33 && V_6 < 0 )
return V_6 ;
return 0 ;
}
