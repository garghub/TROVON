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
else
V_27 -> V_32 = V_52 ;
if ( V_5 -> V_53 == 0 )
V_5 -> V_54 = V_27 -> V_32 ;
else if ( V_5 -> V_54 != V_27 -> V_32 ) {
F_17 ( & V_5 -> V_55 ) ;
F_18 ( V_5 -> V_56 ) ;
V_5 -> V_53 = 0 ;
}
} else {
if ( V_25 == V_47 )
V_27 -> V_32 = V_57 ;
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
case V_58 :
case V_59 :
case V_60 :
V_27 -> V_32 *= F_22 ;
break;
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
V_27 -> V_32 *= F_21 ;
break;
case V_68 :
V_27 -> V_32 -= F_24 ;
break;
case V_69 :
case V_70 :
V_27 -> V_32 *= F_23 ;
break;
default:
F_5 ( & V_2 -> V_10 ,
L_4 , V_11 , V_25 ) ;
}
}
static enum V_71 F_25 ( struct V_1 * V_2 ,
enum V_71 V_72 )
{
int V_6 , V_73 ;
V_73 = F_1 ( V_2 , V_74 ) ;
if ( V_73 < 0 )
return V_73 ;
if ( ( V_73 & V_75 ) == V_72 )
return V_72 ;
if ( V_72 == V_76 )
V_6 = V_73 & ~ V_75 ;
else
V_6 = V_73 | V_75 ;
V_6 = F_12 ( V_2 , V_74 , V_6 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_73 & V_75 ;
}
static int F_26 ( struct V_1 * V_2 ,
int V_45 , enum V_24 V_25 ,
union V_26 * V_27 )
{
T_2 V_6 ;
enum V_71 V_72 = V_77 ;
if ( F_27 ( V_25 ) )
V_72 = V_76 ;
V_72 = F_25 ( V_2 , V_72 ) ;
if ( V_72 < 0 )
return V_72 ;
V_6 = F_1 ( V_2 , V_34 [ V_45 ] . V_36 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_25 == V_78 ) {
V_27 -> V_32 = F_28 ( V_6 , 100 ) ;
} else
V_27 -> V_32 = V_6 ;
V_6 = F_25 ( V_2 , V_72 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
union V_26 * V_27 )
{
int V_6 ;
V_6 = F_1 ( V_2 , V_34 [ V_79 ] . V_36 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = sprintf ( V_80 , L_5 , V_6 ) ;
V_27 -> V_81 = V_80 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
enum V_24 V_25 )
{
int V_82 ;
for ( V_82 = 0 ; V_82 < F_31 ( V_34 ) ; V_82 ++ )
if ( V_25 == V_34 [ V_82 ] . V_25 )
return V_82 ;
F_32 ( & V_2 -> V_10 ,
L_6 , V_11 , V_25 ) ;
return - V_22 ;
}
static int F_33 ( struct V_56 * V_83 ,
enum V_24 V_25 ,
union V_26 * V_27 )
{
int V_6 = 0 ;
struct V_4 * V_5 = F_34 ( V_83 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
switch ( V_25 ) {
case V_28 :
case V_40 :
V_6 = F_14 ( V_2 , V_25 , V_27 ) ;
if ( V_25 == V_28 )
return 0 ;
break;
case V_84 :
V_27 -> V_32 = V_85 ;
goto V_86;
case V_58 :
case V_59 :
case V_60 :
case V_65 :
case V_66 :
case V_67 :
case V_78 :
V_6 = F_30 ( V_2 , V_25 ) ;
if ( V_6 < 0 )
break;
V_6 = F_26 ( V_2 , V_6 , V_25 , V_27 ) ;
break;
case V_87 :
V_6 = F_29 ( V_2 , V_27 ) ;
break;
case V_47 :
case V_88 :
case V_61 :
case V_64 :
case V_68 :
case V_69 :
case V_70 :
case V_62 :
case V_63 :
V_6 = F_30 ( V_2 , V_25 ) ;
if ( V_6 < 0 )
break;
V_6 = F_16 ( V_2 , V_6 , V_25 , V_27 ) ;
break;
case V_89 :
V_6 = F_30 ( V_2 , V_25 ) ;
if ( V_6 < 0 )
break;
V_6 = F_19 ( V_2 , V_6 , V_25 ,
V_90 ) ;
V_27 -> V_81 = V_90 ;
break;
case V_91 :
V_6 = F_30 ( V_2 , V_25 ) ;
if ( V_6 < 0 )
break;
V_6 = F_19 ( V_2 , V_6 , V_25 ,
V_92 ) ;
V_27 -> V_81 = V_92 ;
break;
default:
F_10 ( & V_2 -> V_10 ,
L_7 , V_11 ) ;
return - V_22 ;
}
if ( ! V_5 -> V_93 )
goto V_86;
if ( ! V_5 -> V_29 &&
V_5 -> V_33 != ( V_6 >= 0 ) ) {
V_5 -> V_33 = ( V_6 >= 0 ) ;
F_18 ( V_5 -> V_56 ) ;
}
V_86:
if ( ! V_6 ) {
F_20 ( V_2 , V_25 , V_27 ) ;
}
F_5 ( & V_2 -> V_10 ,
L_8 , V_11 , V_25 , V_27 -> V_32 ) ;
if ( V_6 && V_5 -> V_33 )
return V_6 ;
if ( V_6 )
return - V_94 ;
return 0 ;
}
static T_4 F_35 ( int V_95 , void * V_96 )
{
struct V_56 * V_97 = V_96 ;
F_18 ( V_97 ) ;
return V_98 ;
}
static void F_36 ( struct V_56 * V_83 )
{
struct V_4 * V_5 = F_34 ( V_83 ) ;
if ( V_5 -> V_99 > 0 ) {
V_5 -> V_99 -- ;
return;
}
F_17 ( & V_5 -> V_55 ) ;
F_37 ( & V_5 -> V_55 , V_100 ) ;
V_5 -> V_53 = V_5 -> V_8 -> V_101 ;
}
static void F_38 ( struct V_102 * V_55 )
{
struct V_4 * V_5 ;
T_2 V_6 ;
V_5 = F_39 ( V_55 , struct V_4 , V_55 . V_55 ) ;
V_6 = F_1 ( V_5 -> V_2 , V_34 [ V_103 ] . V_36 ) ;
if ( V_6 < 0 ) {
V_5 -> V_53 = 0 ;
return;
}
if ( V_6 & V_48 )
V_6 = V_49 ;
else if ( V_6 & V_50 )
V_6 = V_51 ;
else
V_6 = V_52 ;
if ( V_5 -> V_54 != V_6 ) {
V_5 -> V_53 = 0 ;
F_18 ( V_5 -> V_56 ) ;
return;
}
if ( V_5 -> V_53 > 0 ) {
F_37 ( & V_5 -> V_55 , V_100 ) ;
V_5 -> V_53 -- ;
return;
}
}
static struct V_104 * F_40 (
struct V_1 * V_2 )
{
struct V_105 * V_106 = V_2 -> V_10 . V_106 ;
struct V_104 * V_8 = V_2 -> V_10 . V_107 ;
enum V_108 V_109 ;
int V_110 ;
T_5 V_111 ;
if ( ! V_106 )
return NULL ;
if ( V_8 )
return V_8 ;
if ( ! F_41 ( V_106 , L_9 , NULL ) &&
! F_41 ( V_106 , L_10 , NULL ) &&
! F_41 ( V_106 , L_11 , NULL ) )
goto V_112;
V_8 = F_42 ( & V_2 -> V_10 , sizeof( struct V_104 ) ,
V_113 ) ;
if ( ! V_8 )
goto V_112;
V_110 = F_43 ( V_106 , L_9 , & V_111 ) ;
if ( ! V_110 )
V_8 -> V_9 = V_111 ;
V_110 = F_43 ( V_106 , L_10 , & V_111 ) ;
if ( ! V_110 )
V_8 -> V_101 = V_111 ;
if ( ! F_41 ( V_106 , L_11 , NULL ) ) {
V_8 -> V_30 = - 1 ;
goto V_112;
}
V_8 -> V_30 = F_44 ( V_106 ,
L_11 , 0 , & V_109 ) ;
if ( V_109 & V_114 )
V_8 -> V_31 = 0 ;
else
V_8 -> V_31 = 1 ;
V_112:
return V_8 ;
}
static struct V_104 * F_40 (
struct V_1 * V_2 )
{
return V_2 -> V_10 . V_107 ;
}
static int F_45 ( struct V_1 * V_2 ,
const struct V_115 * V_116 )
{
struct V_4 * V_5 ;
struct V_117 * V_118 ;
struct V_104 * V_8 = V_2 -> V_10 . V_107 ;
struct V_119 V_120 = {} ;
int V_110 ;
int V_95 ;
V_118 = F_46 ( & V_2 -> V_10 , & V_121 ,
sizeof( * V_118 ) , V_113 ) ;
if ( ! V_118 )
return - V_122 ;
V_118 -> V_123 = F_47 ( & V_2 -> V_10 , V_113 , L_12 ,
F_48 ( & V_2 -> V_10 ) ) ;
if ( ! V_118 -> V_123 )
return - V_122 ;
V_5 = F_49 ( sizeof( struct V_4 ) , V_113 ) ;
if ( ! V_5 )
return - V_122 ;
V_5 -> V_2 = V_2 ;
V_5 -> V_93 = false ;
V_5 -> V_29 = false ;
V_120 . V_106 = V_2 -> V_10 . V_106 ;
V_120 . V_124 = V_5 ;
V_5 -> V_99 = 1 ;
V_5 -> V_54 = V_57 ;
V_8 = F_40 ( V_2 ) ;
if ( V_8 ) {
V_5 -> V_29 = F_50 ( V_8 -> V_30 ) ;
V_5 -> V_8 = V_8 ;
}
F_51 ( V_2 , V_5 ) ;
if ( ! V_5 -> V_29 )
goto V_125;
V_110 = F_52 ( V_8 -> V_30 , F_48 ( & V_2 -> V_10 ) ) ;
if ( V_110 ) {
F_32 ( & V_2 -> V_10 , L_13 , V_110 ) ;
V_5 -> V_29 = false ;
goto V_125;
}
V_110 = F_53 ( V_8 -> V_30 ) ;
if ( V_110 ) {
F_32 ( & V_2 -> V_10 , L_14 , V_110 ) ;
F_54 ( V_8 -> V_30 ) ;
V_5 -> V_29 = false ;
goto V_125;
}
V_95 = F_55 ( V_8 -> V_30 ) ;
if ( V_95 <= 0 ) {
F_32 ( & V_2 -> V_10 , L_15 , V_95 ) ;
F_54 ( V_8 -> V_30 ) ;
V_5 -> V_29 = false ;
goto V_125;
}
V_110 = F_56 ( V_95 , F_35 ,
V_126 | V_127 ,
F_48 ( & V_2 -> V_10 ) , V_5 -> V_56 ) ;
if ( V_110 ) {
F_32 ( & V_2 -> V_10 , L_16 , V_110 ) ;
F_54 ( V_8 -> V_30 ) ;
V_5 -> V_29 = false ;
goto V_125;
}
V_5 -> V_95 = V_95 ;
V_125:
if ( ! V_128 ) {
V_110 = F_1 ( V_2 , V_34 [ V_103 ] . V_36 ) ;
if ( V_110 < 0 ) {
F_10 ( & V_2 -> V_10 , L_17 ,
V_11 ) ;
goto V_129;
}
}
V_5 -> V_56 = F_57 ( & V_2 -> V_10 , V_118 ,
& V_120 ) ;
if ( F_58 ( V_5 -> V_56 ) ) {
F_10 ( & V_2 -> V_10 ,
L_18 , V_11 ) ;
V_110 = F_59 ( V_5 -> V_56 ) ;
goto V_129;
}
F_60 ( & V_2 -> V_10 ,
L_19 , V_2 -> V_123 ) ;
F_61 ( & V_5 -> V_55 , F_38 ) ;
V_5 -> V_93 = true ;
return 0 ;
V_129:
if ( V_5 -> V_95 )
F_62 ( V_5 -> V_95 , V_5 -> V_56 ) ;
if ( V_5 -> V_29 )
F_54 ( V_8 -> V_30 ) ;
F_63 ( V_5 ) ;
return V_110 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_95 )
F_62 ( V_5 -> V_95 , V_5 -> V_56 ) ;
if ( V_5 -> V_29 )
F_54 ( V_5 -> V_8 -> V_30 ) ;
F_65 ( V_5 -> V_56 ) ;
F_17 ( & V_5 -> V_55 ) ;
F_63 ( V_5 ) ;
V_5 = NULL ;
return 0 ;
}
static int F_66 ( struct V_130 * V_10 )
{
struct V_1 * V_2 = F_67 ( V_10 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 ;
if ( V_5 -> V_53 > 0 )
F_17 ( & V_5 -> V_55 ) ;
V_6 = F_12 ( V_2 , V_34 [ V_35 ] . V_36 ,
V_131 ) ;
if ( V_5 -> V_33 && V_6 < 0 )
return V_6 ;
return 0 ;
}
