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
T_3 V_12 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 = 0 ;
int V_7 = 1 ;
if ( V_5 -> V_8 )
V_7 = F_3 ( V_5 -> V_8 -> V_9 + 1 , 1 ) ;
while ( V_7 > 0 ) {
V_6 = F_8 ( V_2 , V_3 ,
F_6 ( V_12 ) ) ;
if ( V_6 >= 0 )
break;
V_7 -- ;
}
if ( V_6 < 0 ) {
F_5 ( & V_2 -> V_10 ,
L_2 ,
V_11 , V_3 ) ;
return V_6 ;
}
return 0 ;
}
static int F_9 (
struct V_1 * V_2 , enum V_13 V_14 ,
union V_15 * V_16 )
{
T_2 V_6 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_14 == V_17 &&
V_5 -> V_18 ) {
V_6 = F_10 ( V_5 -> V_8 -> V_19 ) ;
if ( V_6 == V_5 -> V_8 -> V_20 )
V_16 -> V_21 = 1 ;
else
V_16 -> V_21 = 0 ;
V_5 -> V_22 = V_16 -> V_21 ;
return V_6 ;
}
V_6 = F_7 ( V_2 , V_23 [ V_24 ] . V_25 ,
V_26 ) ;
if ( V_6 < 0 ) {
if ( V_14 == V_17 )
V_16 -> V_21 = 0 ;
return V_6 ;
}
V_6 = F_1 ( V_2 , V_23 [ V_24 ] . V_25 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 < V_23 [ V_24 ] . V_27 ||
V_6 > V_23 [ V_24 ] . V_28 ) {
V_16 -> V_21 = 0 ;
return 0 ;
}
V_6 &= 0x0F00 ;
V_6 >>= 8 ;
if ( V_14 == V_17 ) {
if ( V_6 == 0x0F )
V_16 -> V_21 = 0 ;
else
V_16 -> V_21 = 1 ;
} else if ( V_14 == V_29 ) {
if ( V_6 == 0x09 )
V_16 -> V_21 = V_30 ;
else if ( V_6 == 0x0B )
V_16 -> V_21 = V_31 ;
else if ( V_6 == 0x0C )
V_16 -> V_21 = V_32 ;
else
V_16 -> V_21 = V_33 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
int V_34 , enum V_13 V_14 ,
union V_15 * V_16 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 ;
V_6 = F_1 ( V_2 , V_23 [ V_34 ] . V_25 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_23 [ V_34 ] . V_27 < 0 )
V_6 = ( V_35 ) V_6 ;
if ( V_6 >= V_23 [ V_34 ] . V_27 &&
V_6 <= V_23 [ V_34 ] . V_28 ) {
V_16 -> V_21 = V_6 ;
if ( V_14 != V_36 )
return 0 ;
if ( V_6 & V_37 )
V_16 -> V_21 = V_38 ;
else if ( V_6 & V_39 )
V_16 -> V_21 = V_40 ;
else if ( V_6 & V_41 )
V_16 -> V_21 = V_42 ;
else
V_16 -> V_21 = V_43 ;
if ( V_5 -> V_44 == 0 )
V_5 -> V_45 = V_16 -> V_21 ;
else if ( V_5 -> V_45 != V_16 -> V_21 ) {
F_12 ( & V_5 -> V_46 ) ;
F_13 ( & V_5 -> V_47 ) ;
V_5 -> V_44 = 0 ;
}
} else {
if ( V_14 == V_36 )
V_16 -> V_21 = V_48 ;
else
V_16 -> V_21 = 0 ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_2 ,
enum V_13 V_14 , union V_15 * V_16 )
{
#define F_15 1000
#define F_16 (10 * BASE_UNIT_CONVERSION)
#define F_17 60
#define F_18 2731
switch ( V_14 ) {
case V_49 :
case V_50 :
case V_51 :
V_16 -> V_21 *= F_16 ;
break;
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
V_16 -> V_21 *= F_15 ;
break;
case V_58 :
V_16 -> V_21 -= F_18 ;
break;
case V_59 :
case V_60 :
V_16 -> V_21 *= F_17 ;
break;
default:
F_5 ( & V_2 -> V_10 ,
L_3 , V_11 , V_14 ) ;
}
}
static enum V_61 F_19 ( struct V_1 * V_2 ,
enum V_61 V_62 )
{
int V_6 , V_63 ;
V_63 = F_1 ( V_2 , V_64 ) ;
if ( V_63 < 0 )
return V_63 ;
if ( ( V_63 & V_65 ) == V_62 )
return V_62 ;
if ( V_62 == V_66 )
V_6 = V_63 & ~ V_65 ;
else
V_6 = V_63 | V_65 ;
V_6 = F_7 ( V_2 , V_64 , V_6 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_63 & V_65 ;
}
static int F_20 ( struct V_1 * V_2 ,
int V_34 , enum V_13 V_14 ,
union V_15 * V_16 )
{
T_2 V_6 ;
enum V_61 V_62 = V_67 ;
if ( F_21 ( V_14 ) )
V_62 = V_66 ;
V_62 = F_19 ( V_2 , V_62 ) ;
if ( V_62 < 0 )
return V_62 ;
V_6 = F_1 ( V_2 , V_23 [ V_34 ] . V_25 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_14 == V_68 ) {
V_16 -> V_21 = F_22 ( V_6 , 100 ) ;
} else
V_16 -> V_21 = V_6 ;
V_6 = F_19 ( V_2 , V_62 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
union V_15 * V_16 )
{
int V_6 ;
V_6 = F_1 ( V_2 , V_23 [ V_69 ] . V_25 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = sprintf ( V_70 , L_4 , V_6 ) ;
V_16 -> V_71 = V_70 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
enum V_13 V_14 )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < F_25 ( V_23 ) ; V_72 ++ )
if ( V_14 == V_23 [ V_72 ] . V_14 )
return V_72 ;
F_26 ( & V_2 -> V_10 ,
L_5 , V_11 , V_14 ) ;
return - V_73 ;
}
static int F_27 ( struct V_47 * V_74 ,
enum V_13 V_14 ,
union V_15 * V_16 )
{
int V_6 = 0 ;
struct V_4 * V_5 = F_28 ( V_74 ,
struct V_4 , V_47 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
switch ( V_14 ) {
case V_17 :
case V_29 :
V_6 = F_9 ( V_2 , V_14 , V_16 ) ;
if ( V_14 == V_17 )
return 0 ;
break;
case V_75 :
V_16 -> V_21 = V_76 ;
break;
case V_49 :
case V_50 :
case V_51 :
case V_55 :
case V_56 :
case V_57 :
case V_68 :
V_6 = F_24 ( V_2 , V_14 ) ;
if ( V_6 < 0 )
break;
V_6 = F_20 ( V_2 , V_6 , V_14 , V_16 ) ;
break;
case V_77 :
V_6 = F_23 ( V_2 , V_16 ) ;
break;
case V_36 :
case V_78 :
case V_52 :
case V_54 :
case V_58 :
case V_59 :
case V_60 :
case V_53 :
V_6 = F_24 ( V_2 , V_14 ) ;
if ( V_6 < 0 )
break;
V_6 = F_11 ( V_2 , V_6 , V_14 , V_16 ) ;
break;
default:
F_29 ( & V_2 -> V_10 ,
L_6 , V_11 ) ;
return - V_73 ;
}
if ( ! V_5 -> V_79 )
goto V_80;
if ( ! V_5 -> V_18 &&
V_5 -> V_22 != ( V_6 >= 0 ) ) {
V_5 -> V_22 = ( V_6 >= 0 ) ;
F_13 ( & V_5 -> V_47 ) ;
}
V_80:
if ( ! V_6 ) {
F_14 ( V_2 , V_14 , V_16 ) ;
}
F_5 ( & V_2 -> V_10 ,
L_7 , V_11 , V_14 , V_16 -> V_21 ) ;
if ( V_6 && V_5 -> V_22 )
return V_6 ;
if ( V_6 )
return - V_81 ;
return 0 ;
}
static T_4 F_30 ( int V_82 , void * V_83 )
{
struct V_47 * V_84 = V_83 ;
F_13 ( V_84 ) ;
return V_85 ;
}
static void F_31 ( struct V_47 * V_74 )
{
struct V_4 * V_5 ;
V_5 = F_28 ( V_74 , struct V_4 , V_47 ) ;
if ( V_5 -> V_86 > 0 ) {
V_5 -> V_86 -- ;
return;
}
F_12 ( & V_5 -> V_46 ) ;
F_32 ( & V_5 -> V_46 , V_87 ) ;
V_5 -> V_44 = V_5 -> V_8 -> V_88 ;
}
static void F_33 ( struct V_89 * V_46 )
{
struct V_4 * V_5 ;
T_2 V_6 ;
V_5 = F_28 ( V_46 , struct V_4 , V_46 . V_46 ) ;
V_6 = F_1 ( V_5 -> V_2 , V_23 [ V_90 ] . V_25 ) ;
if ( V_6 < 0 ) {
V_5 -> V_44 = 0 ;
return;
}
if ( V_6 & V_37 )
V_6 = V_38 ;
else if ( V_6 & V_39 )
V_6 = V_40 ;
else if ( V_6 & V_41 )
V_6 = V_42 ;
else
V_6 = V_43 ;
if ( V_5 -> V_45 != V_6 ) {
V_5 -> V_44 = 0 ;
F_13 ( & V_5 -> V_47 ) ;
return;
}
if ( V_5 -> V_44 > 0 ) {
F_32 ( & V_5 -> V_46 , V_87 ) ;
V_5 -> V_44 -- ;
return;
}
}
static struct V_91 * F_34 (
struct V_1 * V_2 )
{
struct V_92 * V_93 = V_2 -> V_10 . V_93 ;
struct V_91 * V_8 = V_2 -> V_10 . V_94 ;
enum V_95 V_96 ;
int V_97 ;
T_5 V_98 ;
if ( ! V_93 )
return NULL ;
if ( V_8 )
return V_8 ;
if ( ! F_35 ( V_93 , L_8 , NULL ) &&
! F_35 ( V_93 , L_9 , NULL ) &&
! F_35 ( V_93 , L_10 , NULL ) )
goto V_99;
V_8 = F_36 ( & V_2 -> V_10 , sizeof( struct V_91 ) ,
V_100 ) ;
if ( ! V_8 )
goto V_99;
V_97 = F_37 ( V_93 , L_8 , & V_98 ) ;
if ( ! V_97 )
V_8 -> V_9 = V_98 ;
V_97 = F_37 ( V_93 , L_9 , & V_98 ) ;
if ( ! V_97 )
V_8 -> V_88 = V_98 ;
if ( ! F_35 ( V_93 , L_10 , NULL ) ) {
V_8 -> V_19 = - 1 ;
goto V_99;
}
V_8 -> V_19 = F_38 ( V_93 ,
L_10 , 0 , & V_96 ) ;
if ( V_96 & V_101 )
V_8 -> V_20 = 0 ;
else
V_8 -> V_20 = 1 ;
V_99:
return V_8 ;
}
static struct V_91 * F_34 (
struct V_1 * V_2 )
{
return V_2 -> V_10 . V_94 ;
}
static int T_6 F_39 ( struct V_1 * V_2 ,
const struct V_102 * V_103 )
{
struct V_4 * V_5 ;
struct V_91 * V_8 = V_2 -> V_10 . V_94 ;
int V_97 ;
int V_82 ;
char * V_104 ;
V_104 = F_40 ( V_100 , L_11 , F_41 ( & V_2 -> V_10 ) ) ;
if ( ! V_104 ) {
F_29 ( & V_2 -> V_10 , L_12 ) ;
return - V_105 ;
}
V_5 = F_42 ( sizeof( struct V_4 ) , V_100 ) ;
if ( ! V_5 ) {
V_97 = - V_105 ;
goto V_106;
}
V_5 -> V_2 = V_2 ;
V_5 -> V_79 = false ;
V_5 -> V_18 = false ;
V_5 -> V_47 . V_104 = V_104 ;
V_5 -> V_47 . type = V_107 ;
V_5 -> V_47 . V_108 = V_109 ;
V_5 -> V_47 . V_110 = F_25 ( V_109 ) ;
V_5 -> V_47 . V_111 = F_27 ;
V_5 -> V_86 = 1 ;
V_5 -> V_45 = V_48 ;
V_5 -> V_47 . V_112 = F_31 ;
V_8 = F_34 ( V_2 ) ;
if ( V_8 ) {
V_5 -> V_18 = F_43 ( V_8 -> V_19 ) ;
V_5 -> V_8 = V_8 ;
}
F_44 ( V_2 , V_5 ) ;
if ( ! V_5 -> V_18 )
goto V_113;
V_97 = F_45 ( V_8 -> V_19 , F_41 ( & V_2 -> V_10 ) ) ;
if ( V_97 ) {
F_26 ( & V_2 -> V_10 , L_13 , V_97 ) ;
V_5 -> V_18 = false ;
goto V_113;
}
V_97 = F_46 ( V_8 -> V_19 ) ;
if ( V_97 ) {
F_26 ( & V_2 -> V_10 , L_14 , V_97 ) ;
F_47 ( V_8 -> V_19 ) ;
V_5 -> V_18 = false ;
goto V_113;
}
V_82 = F_48 ( V_8 -> V_19 ) ;
if ( V_82 <= 0 ) {
F_26 ( & V_2 -> V_10 , L_15 , V_82 ) ;
F_47 ( V_8 -> V_19 ) ;
V_5 -> V_18 = false ;
goto V_113;
}
V_97 = F_49 ( V_82 , F_30 ,
V_114 | V_115 ,
F_41 ( & V_2 -> V_10 ) , & V_5 -> V_47 ) ;
if ( V_97 ) {
F_26 ( & V_2 -> V_10 , L_16 , V_97 ) ;
F_47 ( V_8 -> V_19 ) ;
V_5 -> V_18 = false ;
goto V_113;
}
V_5 -> V_82 = V_82 ;
V_113:
V_97 = F_50 ( & V_2 -> V_10 , & V_5 -> V_47 ) ;
if ( V_97 ) {
F_29 ( & V_2 -> V_10 ,
L_17 , V_11 ) ;
goto V_116;
}
F_51 ( & V_2 -> V_10 ,
L_18 , V_2 -> V_104 ) ;
F_52 ( & V_5 -> V_46 , F_33 ) ;
V_5 -> V_79 = true ;
return 0 ;
V_116:
if ( V_5 -> V_82 )
F_53 ( V_5 -> V_82 , & V_5 -> V_47 ) ;
if ( V_5 -> V_18 )
F_47 ( V_8 -> V_19 ) ;
F_54 ( V_5 ) ;
V_106:
F_54 ( V_104 ) ;
return V_97 ;
}
static int T_7 F_55 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_82 )
F_53 ( V_5 -> V_82 , & V_5 -> V_47 ) ;
if ( V_5 -> V_18 )
F_47 ( V_5 -> V_8 -> V_19 ) ;
F_56 ( & V_5 -> V_47 ) ;
F_12 ( & V_5 -> V_46 ) ;
F_54 ( V_5 -> V_47 . V_104 ) ;
F_54 ( V_5 ) ;
V_5 = NULL ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
T_8 V_117 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_6 ;
if ( V_5 -> V_44 > 0 )
F_12 ( & V_5 -> V_46 ) ;
V_6 = F_7 ( V_2 , V_23 [ V_24 ] . V_25 ,
V_118 ) ;
if ( V_5 -> V_22 && V_6 < 0 )
return V_6 ;
return 0 ;
}
static int T_9 F_58 ( void )
{
return F_59 ( & V_119 ) ;
}
static void T_10 F_60 ( void )
{
F_61 ( & V_119 ) ;
}
