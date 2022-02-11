static int F_1 ( struct V_1 * V_1 , bool V_2 )
{
int V_3 ;
T_1 V_4 ;
V_4 = V_2 ? V_5 : 0 ;
V_4 |= V_6 ;
V_3 = F_2 ( V_1 -> V_7 , V_8 , V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 )
F_3 ( V_9 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 )
{
int V_3 ;
V_3 = F_1 ( V_1 , V_10 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_2 ( V_1 -> V_7 , V_11 , V_12 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_2 ( V_1 -> V_7 , V_13 , V_14 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_2 ( V_1 -> V_7 , V_15 ,
V_16 ) ;
if ( V_3 )
return V_3 ;
return F_1 ( V_1 , V_17 ) ;
}
static int F_5 ( struct V_1 * V_1 )
{
int V_3 ;
V_3 = F_2 ( V_1 -> V_7 , V_11 , V_18 |
V_19 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_2 ( V_1 -> V_7 , V_13 , 0 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_2 ( V_1 -> V_7 , V_15 , V_20 ) ;
if ( V_3 )
return V_3 ;
return F_2 ( V_1 -> V_7 , V_21 , 0 ) ;
}
static int F_6 ( struct V_1 * V_1 )
{
unsigned int V_22 ;
T_1 V_23 ;
T_1 V_4 ;
int V_3 ;
V_3 = F_7 ( V_1 -> V_7 , V_24 , & V_22 ) ;
if ( V_3 )
return V_3 ;
if ( V_1 -> V_25 ) {
V_23 = V_19 |
V_18 |
V_26 ;
V_4 = V_18 ;
if ( ! V_1 -> V_27 )
V_4 |= V_26 ;
F_8 ( & V_1 -> V_28 ) ;
V_3 = F_9 ( V_1 -> V_7 , V_11 ,
V_23 , V_4 ) ;
if ( V_3 )
return V_3 ;
}
return F_9 ( V_1 -> V_7 ,
V_13 ,
V_29 ,
V_29 ) ;
}
static int F_10 ( struct V_1 * V_1 )
{
int V_30 = 2 ;
unsigned int V_4 ;
int V_3 ;
if ( V_1 -> V_25 ) {
V_3 = F_11 ( & V_1 -> V_28 ,
1 + F_12 ( 1000 ) ) ;
if ( ! V_3 ) {
F_13 ( & V_1 -> V_31 -> V_32 ,
L_1 ) ;
return - V_33 ;
}
return 0 ;
}
do {
F_3 ( V_34 ) ;
V_3 = F_7 ( V_1 -> V_7 , V_35 , & V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_4 & V_36 )
return 0 ;
} while ( -- V_30 );
F_13 ( & V_1 -> V_31 -> V_32 , L_2 ) ;
return - V_33 ;
}
static int F_14 ( struct V_1 * V_1 , T_2 * V_37 )
{
unsigned int V_38 ;
int V_3 ;
V_3 = F_10 ( V_1 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_7 ( V_1 -> V_7 , V_39 , & V_38 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_38 & V_40 ) {
F_13 ( & V_1 -> V_31 -> V_32 ,
L_3 ) ;
return - V_41 ;
}
V_3 = F_15 ( V_1 -> V_7 , V_42 , V_37 , 6 ) ;
if ( V_3 )
return V_3 ;
return V_3 ;
}
static T_3 F_16 ( int V_43 , void * V_44 )
{
struct V_1 * V_1 = V_44 ;
if ( ! V_1 -> V_25 )
return V_45 ;
return V_46 ;
}
static T_3 F_17 ( int V_43 , void * V_44 )
{
struct V_1 * V_1 = V_44 ;
unsigned int V_4 ;
int V_3 ;
V_3 = F_7 ( V_1 -> V_7 , V_35 , & V_4 ) ;
if ( V_3 < 0 ) {
F_13 ( & V_1 -> V_31 -> V_32 , L_4 ) ;
return V_47 ;
}
if ( V_4 & V_36 ) {
F_18 ( & V_1 -> V_28 ) ;
return V_47 ;
}
return V_45 ;
}
static int F_19 ( struct V_1 * V_1 )
{
struct V_48 * V_32 = & V_1 -> V_31 -> V_32 ;
unsigned int V_4 ;
int V_3 ;
V_3 = F_7 ( V_1 -> V_7 , V_49 , & V_4 ) ;
if ( V_3 )
return V_3 ;
if ( V_4 != V_50 ) {
F_13 ( V_32 , L_5 ) ;
return - V_51 ;
}
V_3 = F_9 ( V_1 -> V_7 ,
V_13 ,
V_52 ,
V_52 ) ;
if ( V_3 ) {
F_13 ( V_32 , L_6 ) ;
return V_3 ;
}
F_3 ( V_53 ) ;
V_3 = F_7 ( V_1 -> V_7 , V_49 , & V_4 ) ;
if ( V_3 )
return V_3 ;
if ( V_4 != V_54 ) {
F_13 ( V_32 , L_7 , V_4 ) ;
return - V_51 ;
}
V_3 = F_7 ( V_1 -> V_7 , V_49 , & V_4 ) ;
if ( V_3 )
return V_3 ;
if ( V_4 != V_50 ) {
F_13 ( V_32 , L_8 , V_4 ) ;
return - V_51 ;
}
F_20 ( V_32 , L_9 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_1 , T_1 V_55 , T_4 * V_4 )
{
int V_3 ;
T_2 V_56 ;
V_3 = F_15 ( V_1 -> V_7 , V_55 , & V_56 , 2 ) ;
if ( V_3 )
return V_3 ;
* V_4 = F_22 ( V_56 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_1 )
{
unsigned int V_57 ;
const char * V_58 ;
int V_3 ;
unsigned int V_59 ;
T_4 V_60 ;
V_3 = F_7 ( V_1 -> V_7 , V_61 , & V_57 ) ;
if ( V_3 )
return V_3 ;
switch ( V_57 ) {
case V_62 :
V_58 = L_10 ;
V_3 = F_7 ( V_1 -> V_7 , V_63 , & V_59 ) ;
if ( V_3 )
return V_3 ;
V_59 &= 0x7f ;
V_3 = F_21 ( V_1 , V_64 , & V_60 ) ;
if ( V_3 )
return V_3 ;
F_24 ( & V_1 -> V_31 -> V_32 ,
L_11 ,
V_58 , V_59 , V_60 ) ;
break;
case V_65 :
V_58 = L_12 ;
F_24 ( & V_1 -> V_31 -> V_32 , L_13 ) ;
break;
default:
F_13 ( & V_1 -> V_31 -> V_32 , L_14 ,
V_57 ) ;
return - V_66 ;
}
V_1 -> V_58 = V_58 ;
V_1 -> V_67 = V_57 ;
return 0 ;
}
static int F_25 ( struct V_68 * V_69 ,
struct V_70 const * V_71 ,
int * V_4 , int * V_72 ,
long V_23 )
{
struct V_1 * V_1 = F_26 ( V_69 ) ;
T_2 V_73 [ 3 ] ;
int V_3 = - V_74 ;
F_27 ( & V_1 -> V_31 -> V_32 ) ;
F_28 ( & V_1 -> V_75 ) ;
switch ( V_23 ) {
case V_76 :
if ( V_71 -> V_77 > 2 ) {
F_13 ( & V_1 -> V_31 -> V_32 , L_15 ) ;
V_3 = - V_51 ;
goto V_78;
}
V_3 = F_6 ( V_1 ) ;
if ( V_3 )
goto V_78;
V_3 = F_14 ( V_1 , V_73 ) ;
if ( V_3 )
goto V_78;
* V_4 = F_22 ( V_73 [ V_71 -> V_77 ] ) ;
V_3 = V_79 ;
}
V_78:
F_29 ( & V_1 -> V_75 ) ;
F_30 ( & V_1 -> V_31 -> V_32 ) ;
F_31 ( & V_1 -> V_31 -> V_32 ) ;
return V_3 ;
}
static void F_32 ( struct V_68 * V_69 )
{
struct V_1 * V_1 = F_26 ( V_69 ) ;
int V_3 ;
T_2 V_73 [ 8 ] ;
F_27 ( & V_1 -> V_31 -> V_32 ) ;
F_28 ( & V_1 -> V_75 ) ;
V_3 = F_6 ( V_1 ) ;
if ( V_3 ) {
F_13 ( & V_1 -> V_31 -> V_32 , L_16 ) ;
goto V_78;
}
V_3 = F_14 ( V_1 , V_73 ) ;
if ( V_3 ) {
F_13 ( & V_1 -> V_31 -> V_32 , L_17 ) ;
goto V_78;
}
F_33 ( V_69 , V_73 ,
F_34 ( V_69 ) ) ;
V_78:
F_29 ( & V_1 -> V_75 ) ;
F_30 ( & V_1 -> V_31 -> V_32 ) ;
F_31 ( & V_1 -> V_31 -> V_32 ) ;
}
static T_3 F_35 ( int V_43 , void * V_80 )
{
const struct V_81 * V_82 = V_80 ;
struct V_68 * V_69 = V_82 -> V_69 ;
F_32 ( V_69 ) ;
F_36 ( V_69 -> V_83 ) ;
return V_47 ;
}
static const struct V_84 *
F_37 ( const struct V_68 * V_69 ,
const struct V_70 * V_71 )
{
struct V_1 * V_1 = F_26 ( V_69 ) ;
return & V_1 -> V_85 ;
}
static bool F_38 ( struct V_48 * V_32 , unsigned int V_55 )
{
struct V_86 * V_31 = F_39 ( V_32 ) ;
struct V_68 * V_69 = F_40 ( V_31 ) ;
struct V_1 * V_1 = F_26 ( V_69 ) ;
switch ( V_55 ) {
case V_8 :
case V_11 :
case V_13 :
case V_15 :
case V_87 :
case V_87 + 1 :
case V_21 :
case V_21 + 1 :
return true ;
case V_88 :
case V_88 + 1 :
case V_89 :
case V_89 + 1 :
case V_90 :
case V_90 + 1 :
if ( V_1 -> V_67 == V_65 )
return true ;
return false ;
case V_91 :
case V_91 + 1 :
case V_92 :
case V_92 + 1 :
case V_93 :
case V_93 + 1 :
if ( V_1 -> V_67 == V_62 )
return true ;
return false ;
default:
return false ;
}
}
static int F_41 ( struct V_86 * V_31 ,
const struct V_94 * V_95 )
{
struct V_68 * V_69 ;
struct V_1 * V_1 ;
unsigned long V_96 ;
int V_43 = V_31 -> V_43 ;
int V_3 ;
V_69 = F_42 ( & V_31 -> V_32 , sizeof( * V_1 ) ) ;
if ( V_69 == NULL )
return - V_97 ;
V_1 = F_26 ( V_69 ) ;
F_43 ( V_31 , V_69 ) ;
V_1 -> V_31 = V_31 ;
F_44 ( & V_1 -> V_75 ) ;
V_3 = F_45 ( & V_31 -> V_32 ,
L_18 ,
& V_1 -> V_85 ) ;
if ( V_3 )
return V_3 ;
V_1 -> V_98 [ 0 ] . V_99 = V_100 ;
V_1 -> V_98 [ 1 ] . V_99 = V_101 ;
V_3 = F_46 ( & V_31 -> V_32 ,
F_47 ( V_1 -> V_98 ) ,
V_1 -> V_98 ) ;
if ( V_3 < 0 ) {
F_13 ( & V_31 -> V_32 , L_19 ) ;
return V_3 ;
}
V_3 = F_48 ( F_47 ( V_1 -> V_98 ) , V_1 -> V_98 ) ;
if ( V_3 < 0 ) {
F_13 ( & V_31 -> V_32 , L_20 ) ;
return V_3 ;
}
F_49 ( & V_31 -> V_32 ) ;
F_50 ( & V_31 -> V_32 ) ;
F_51 ( & V_31 -> V_32 ) ;
V_1 -> V_7 = F_52 ( V_31 , & V_102 ) ;
if ( F_53 ( V_1 -> V_7 ) ) {
F_13 ( & V_31 -> V_32 , L_21 ) ;
return F_54 ( V_1 -> V_7 ) ;
}
V_3 = F_1 ( V_1 , V_10 ) ;
if ( V_3 ) {
F_13 ( & V_31 -> V_32 , L_22 ) ;
goto V_103;
}
V_3 = F_23 ( V_1 ) ;
if ( V_3 ) {
F_13 ( & V_31 -> V_32 , L_23 ) ;
goto V_103;
}
V_3 = F_19 ( V_1 ) ;
if ( V_3 )
F_13 ( & V_31 -> V_32 , L_24 ) ;
V_3 = F_4 ( V_1 ) ;
if ( V_3 ) {
F_13 ( & V_31 -> V_32 , L_25 ) ;
goto V_103;
}
F_55 ( & V_31 -> V_32 ,
V_104 ) ;
F_56 ( & V_31 -> V_32 ) ;
F_57 ( & V_31 -> V_32 ) ;
V_69 -> V_32 . V_105 = & V_31 -> V_32 ;
V_69 -> V_106 = V_107 ;
V_69 -> V_108 = F_47 ( V_107 ) ;
V_69 -> V_109 = & V_110 ;
V_69 -> V_111 = V_112 ;
V_69 -> V_113 = V_114 ;
V_69 -> V_58 = V_1 -> V_58 ;
V_3 = F_58 ( V_69 , NULL ,
F_35 ,
NULL ) ;
if ( V_3 ) {
F_13 ( & V_31 -> V_32 , L_26 ) ;
goto V_115;
}
if ( V_43 > 0 ) {
V_96 = F_59 ( F_60 ( V_43 ) ) ;
if ( V_96 == V_116 ) {
F_24 ( & V_31 -> V_32 , L_27 ) ;
} else if ( V_96 == V_117 ) {
V_1 -> V_27 = true ;
F_24 ( & V_31 -> V_32 , L_28 ) ;
} else {
V_96 = V_116 ;
}
V_96 |= V_118 ;
V_96 |= V_119 ;
V_3 = F_61 ( & V_31 -> V_32 ,
V_43 ,
F_16 ,
F_17 ,
V_96 ,
V_1 -> V_58 ,
V_1 ) ;
if ( V_3 ) {
F_13 ( & V_31 -> V_32 , L_29
L_30 ) ;
goto V_120;
}
V_1 -> V_25 = true ;
}
V_120:
V_3 = F_62 ( V_69 ) ;
if ( V_3 ) {
F_13 ( & V_31 -> V_32 , L_31 ) ;
goto V_121;
}
return 0 ;
V_121:
F_63 ( V_69 ) ;
V_115:
F_64 ( & V_31 -> V_32 ) ;
F_65 ( & V_31 -> V_32 ) ;
F_1 ( V_1 , V_17 ) ;
V_103:
F_66 ( F_47 ( V_1 -> V_98 ) , V_1 -> V_98 ) ;
return V_3 ;
}
static int F_67 ( struct V_86 * V_31 )
{
struct V_68 * V_69 = F_40 ( V_31 ) ;
struct V_1 * V_1 = F_26 ( V_69 ) ;
F_68 ( V_69 ) ;
F_63 ( V_69 ) ;
F_27 ( & V_31 -> V_32 ) ;
F_64 ( & V_31 -> V_32 ) ;
F_65 ( & V_31 -> V_32 ) ;
F_1 ( V_1 , V_17 ) ;
F_66 ( F_47 ( V_1 -> V_98 ) , V_1 -> V_98 ) ;
return 0 ;
}
static int T_5 F_69 ( struct V_48 * V_32 )
{
struct V_1 * V_1 =
F_26 ( F_40 ( F_39 ( V_32 ) ) ) ;
F_1 ( V_1 , V_17 ) ;
F_66 ( F_47 ( V_1 -> V_98 ) , V_1 -> V_98 ) ;
return 0 ;
}
static int T_5 F_70 ( struct V_48 * V_32 )
{
struct V_1 * V_1 =
F_26 ( F_40 ( F_39 ( V_32 ) ) ) ;
int V_3 ;
V_3 = F_48 ( F_47 ( V_1 -> V_98 ) , V_1 -> V_98 ) ;
if ( V_3 )
return V_3 ;
F_3 ( V_122 ) ;
V_3 = F_1 ( V_1 , V_10 ) ;
if ( V_3 )
goto V_123;
V_3 = F_5 ( V_1 ) ;
if ( V_3 )
goto V_124;
return 0 ;
V_124:
F_1 ( V_1 , V_17 ) ;
V_123:
F_66 ( F_47 ( V_1 -> V_98 ) , V_1 -> V_98 ) ;
return V_3 ;
}
