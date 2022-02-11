static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 , V_3 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 , L_1 ) ;
return V_4 ;
}
return 0 ;
}
static int F_4 ( int V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_5 ( V_10 ) ; ++ V_9 ) {
if ( V_10 [ V_9 ] . V_8 == V_8 )
return V_10 [ V_9 ] . V_11 ;
}
return - V_12 ;
}
static int F_6 ( struct V_1 * V_2 , int V_8 )
{
int V_4 ;
int V_11 ;
V_11 = F_4 ( V_8 ) ;
if ( V_11 < 0 )
return V_11 ;
V_4 = F_2 ( V_2 -> V_5 , V_13 , V_11 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 , L_2 ) ;
return V_4 ;
}
V_2 -> V_11 = V_11 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_4 ;
unsigned int V_8 ;
V_4 = F_8 ( V_2 -> V_5 , V_14 , & V_8 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 , L_3 ) ;
return V_4 ;
}
F_9 ( V_2 -> V_7 , L_4 , V_8 ) ;
if ( V_8 != V_15 ) {
F_3 ( V_2 -> V_7 , L_5 , V_8 ) ;
return - V_16 ;
}
V_4 = F_1 ( V_2 , V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
F_10 ( 500 , 1000 ) ;
V_4 = F_6 ( V_2 , V_18 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_19 , V_20 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 , L_6 ) ;
return V_4 ;
}
V_2 -> V_21 = V_20 ;
V_4 = F_8 ( V_2 -> V_5 , V_22 , & V_8 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 , L_7 ) ;
return V_4 ;
}
V_2 -> V_23 = V_8 ;
V_4 = F_11 ( V_2 -> V_5 , V_24 ,
V_25 , 0 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 , L_8 ) ;
return V_4 ;
}
V_4 = F_2 ( V_2 -> V_5 , V_26 ,
V_27 |
V_28 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 ,
L_9 ) ;
return V_4 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , bool V_29 )
{
#ifdef F_13
int V_4 ;
if ( V_29 )
V_4 = F_14 ( V_2 -> V_7 ) ;
else {
F_15 ( V_2 -> V_7 ) ;
V_4 = F_16 ( V_2 -> V_7 ) ;
}
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 ,
L_10 , V_29 ) ;
if ( V_29 )
F_17 ( V_2 -> V_7 ) ;
return V_4 ;
}
#endif
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
bool V_30 )
{
int V_4 ;
V_4 = F_11 ( V_2 -> V_5 , V_31 ,
V_32 ,
( V_30 ? V_32 : 0 ) ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 , L_11 ) ;
return V_4 ;
}
if ( V_30 ) {
V_4 = F_2 ( V_2 -> V_5 , V_22 ,
V_2 -> V_23 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 ,
L_12 ) ;
return V_4 ;
}
V_4 = F_2 ( V_2 -> V_5 , V_33 ,
V_34 | V_35 |
V_36 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 ,
L_9 ) ;
return V_4 ;
}
if ( ! V_2 -> V_37 ) {
V_4 = F_2 ( V_2 -> V_5 ,
V_26 ,
V_27 |
V_28 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 ,
L_13 ) ;
return V_4 ;
}
}
V_4 = F_2 ( V_2 -> V_5 , V_38 ,
V_39 ) ;
} else {
V_4 = F_2 ( V_2 -> V_5 , V_38 , 0 ) ;
}
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 , L_14 ) ;
return V_4 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
bool V_30 )
{
int V_4 ;
V_4 = F_11 ( V_2 -> V_5 , V_40 ,
V_41 ,
( V_30 ? V_41 : 0 ) ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 , L_15 ) ;
return V_4 ;
}
if ( V_30 ) {
V_4 = F_2 ( V_2 -> V_5 , V_26 ,
V_42 |
V_28 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 ,
L_13 ) ;
return V_4 ;
}
V_4 = F_2 ( V_2 -> V_5 , V_38 ,
V_39 ) ;
} else {
V_4 = F_2 ( V_2 -> V_5 , V_26 ,
V_27 |
V_28 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 ,
L_13 ) ;
return V_4 ;
}
V_4 = F_2 ( V_2 -> V_5 , V_38 , 0 ) ;
}
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 , L_14 ) ;
return V_4 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int * V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_5 ( V_10 ) ; ++ V_9 ) {
if ( V_10 [ V_9 ] . V_11 == V_2 -> V_11 ) {
* V_8 = V_10 [ V_9 ] . V_8 ;
return V_43 ;
}
}
return - V_12 ;
}
static int F_21 ( struct V_1 * V_2 , int V_8 )
{
int V_4 , V_9 ;
for ( V_9 = 0 ; V_9 < F_5 ( V_44 ) ; ++ V_9 ) {
if ( V_44 [ V_9 ] . V_45 == V_8 ) {
V_4 = F_2 ( V_2 -> V_5 , V_19 ,
V_44 [ V_9 ] . V_21 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 ,
L_6 ) ;
return V_4 ;
}
V_2 -> V_21 = V_44 [ V_9 ] . V_21 ;
return 0 ;
}
}
return - V_12 ;
}
static int F_22 ( struct V_1 * V_2 , int * V_8 )
{
int V_4 ;
unsigned int V_46 ;
F_23 ( & V_2 -> V_47 ) ;
V_4 = F_12 ( V_2 , true ) ;
if ( V_4 < 0 ) {
F_24 ( & V_2 -> V_47 ) ;
return V_4 ;
}
V_4 = F_8 ( V_2 -> V_5 , V_48 , & V_46 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 , L_16 ) ;
F_12 ( V_2 , false ) ;
F_24 ( & V_2 -> V_47 ) ;
return V_4 ;
}
* V_8 = F_25 ( V_46 , 7 ) ;
V_4 = F_12 ( V_2 , false ) ;
F_24 ( & V_2 -> V_47 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_43 ;
}
static int F_26 ( struct V_1 * V_2 , int V_49 , int * V_8 )
{
int V_4 ;
T_2 V_46 ;
F_23 ( & V_2 -> V_47 ) ;
V_4 = F_12 ( V_2 , true ) ;
if ( V_4 < 0 ) {
F_24 ( & V_2 -> V_47 ) ;
return V_4 ;
}
V_4 = F_27 ( V_2 -> V_5 , F_28 ( V_49 ) , & V_46 ,
sizeof( V_46 ) ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 , L_17 , V_49 ) ;
F_12 ( V_2 , false ) ;
F_24 ( & V_2 -> V_47 ) ;
return V_4 ;
}
* V_8 = F_25 ( F_29 ( V_46 ) , 15 ) ;
V_4 = F_12 ( V_2 , false ) ;
F_24 ( & V_2 -> V_47 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_43 ;
}
static int F_30 ( struct V_50 * V_51 ,
struct V_52 const * V_53 ,
int * V_8 , int * V_54 , long V_55 )
{
struct V_1 * V_2 = F_31 ( V_51 ) ;
int V_4 ;
switch ( V_55 ) {
case V_56 :
switch ( V_53 -> type ) {
case V_57 :
return F_22 ( V_2 , V_8 ) ;
case V_58 :
if ( F_32 ( V_51 ) )
return - V_59 ;
else
return F_26 ( V_2 , V_53 -> V_60 ,
V_8 ) ;
default:
return - V_12 ;
}
case V_61 :
if ( V_53 -> type == V_57 ) {
* V_8 = V_62 ;
return V_43 ;
} else
return - V_12 ;
case V_63 :
* V_8 = 0 ;
switch ( V_53 -> type ) {
case V_57 :
* V_54 = 500000 ;
return V_64 ;
case V_58 :
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_5 ( V_44 ) ; ++ V_9 ) {
if ( V_44 [ V_9 ] . V_21 ==
V_2 -> V_21 ) {
* V_54 = V_44 [ V_9 ] . V_45 ;
return V_64 ;
}
}
return - V_12 ;
}
default:
return - V_12 ;
}
case V_65 :
* V_54 = 0 ;
F_23 ( & V_2 -> V_47 ) ;
V_4 = F_20 ( V_2 , V_8 ) ;
F_24 ( & V_2 -> V_47 ) ;
return V_4 ;
default:
return - V_12 ;
}
}
static int F_33 ( struct V_50 * V_51 ,
struct V_52 const * V_53 ,
int V_8 , int V_54 , long V_55 )
{
struct V_1 * V_2 = F_31 ( V_51 ) ;
int V_4 ;
switch ( V_55 ) {
case V_65 :
F_23 ( & V_2 -> V_47 ) ;
V_4 = F_12 ( V_2 , true ) ;
if ( V_4 < 0 ) {
F_24 ( & V_2 -> V_47 ) ;
return V_4 ;
}
V_4 = F_6 ( V_2 , V_8 ) ;
if ( V_4 < 0 ) {
F_12 ( V_2 , false ) ;
F_24 ( & V_2 -> V_47 ) ;
return V_4 ;
}
V_4 = F_12 ( V_2 , false ) ;
F_24 ( & V_2 -> V_47 ) ;
return V_4 ;
case V_63 :
if ( V_8 )
return - V_12 ;
F_23 ( & V_2 -> V_47 ) ;
V_4 = F_12 ( V_2 , true ) ;
if ( V_4 < 0 ) {
F_24 ( & V_2 -> V_47 ) ;
return V_4 ;
}
V_4 = F_21 ( V_2 , V_54 ) ;
if ( V_4 < 0 ) {
F_12 ( V_2 , false ) ;
F_24 ( & V_2 -> V_47 ) ;
return V_4 ;
}
V_4 = F_12 ( V_2 , false ) ;
F_24 ( & V_2 -> V_47 ) ;
return V_4 ;
default:
return - V_12 ;
}
return - V_12 ;
}
static int F_34 ( struct V_50 * V_51 ,
const struct V_52 * V_53 ,
enum V_66 type ,
enum V_67 V_68 ,
enum V_69 V_70 ,
int * V_8 , int * V_54 )
{
struct V_1 * V_2 = F_31 ( V_51 ) ;
* V_54 = 0 ;
switch ( V_70 ) {
case V_71 :
* V_8 = V_2 -> V_23 & V_72 ;
break;
default:
return - V_12 ;
}
return V_43 ;
}
static int F_35 ( struct V_50 * V_51 ,
const struct V_52 * V_53 ,
enum V_66 type ,
enum V_67 V_68 ,
enum V_69 V_70 ,
int V_8 , int V_54 )
{
struct V_1 * V_2 = F_31 ( V_51 ) ;
switch ( V_70 ) {
case V_71 :
if ( V_2 -> V_73 )
return - V_59 ;
V_2 -> V_23 &= ~ V_72 ;
V_2 -> V_23 |= ( V_8 & V_72 ) ;
break;
default:
return - V_12 ;
}
return 0 ;
}
static int F_36 ( struct V_50 * V_51 ,
const struct V_52 * V_53 ,
enum V_66 type ,
enum V_67 V_68 )
{
struct V_1 * V_2 = F_31 ( V_51 ) ;
return V_2 -> V_73 ;
}
static int F_37 ( struct V_50 * V_51 ,
const struct V_52 * V_53 ,
enum V_66 type ,
enum V_67 V_68 ,
int V_74 )
{
struct V_1 * V_2 = F_31 ( V_51 ) ;
int V_4 ;
if ( V_74 && V_2 -> V_73 )
return 0 ;
F_23 ( & V_2 -> V_47 ) ;
if ( ! V_74 && V_2 -> V_75 ) {
V_2 -> V_73 = 0 ;
F_24 ( & V_2 -> V_47 ) ;
return 0 ;
}
V_4 = F_12 ( V_2 , V_74 ) ;
if ( V_4 < 0 ) {
F_24 ( & V_2 -> V_47 ) ;
return V_4 ;
}
V_4 = F_18 ( V_2 , V_74 ) ;
if ( V_4 < 0 ) {
F_12 ( V_2 , false ) ;
F_24 ( & V_2 -> V_47 ) ;
return V_4 ;
}
V_2 -> V_73 = V_74 ;
F_24 ( & V_2 -> V_47 ) ;
return 0 ;
}
static T_3 F_38 ( int V_76 , void * V_77 )
{
struct V_78 * V_79 = V_77 ;
struct V_50 * V_51 = V_79 -> V_51 ;
struct V_1 * V_2 = F_31 ( V_51 ) ;
int V_80 , V_4 , V_9 = 0 ;
unsigned int V_8 ;
F_23 ( & V_2 -> V_47 ) ;
F_39 (bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_4 = F_27 ( V_2 -> V_5 , F_28 ( V_80 ) ,
& V_8 , 2 ) ;
if ( V_4 < 0 ) {
F_24 ( & V_2 -> V_47 ) ;
goto V_81;
}
V_2 -> V_82 [ V_9 ++ ] = V_8 ;
}
F_24 ( & V_2 -> V_47 ) ;
F_40 ( V_51 , V_2 -> V_82 ,
V_79 -> V_83 ) ;
V_81:
F_41 ( V_51 -> V_84 ) ;
return V_85 ;
}
static int F_42 ( struct V_86 * V_84 )
{
struct V_50 * V_51 = F_43 ( V_84 ) ;
struct V_1 * V_2 = F_31 ( V_51 ) ;
int V_4 ;
if ( V_2 -> V_37 )
return 0 ;
V_4 = F_2 ( V_2 -> V_5 , V_26 ,
V_27 |
V_28 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 , L_13 ) ;
return V_4 ;
}
return 0 ;
}
static int F_44 ( struct V_86 * V_84 ,
bool V_74 )
{
struct V_50 * V_51 = F_43 ( V_84 ) ;
struct V_1 * V_2 = F_31 ( V_51 ) ;
int V_4 ;
F_23 ( & V_2 -> V_47 ) ;
if ( ! V_74 && V_2 -> V_73 && V_2 -> V_75 ) {
V_2 -> V_75 = false ;
F_24 ( & V_2 -> V_47 ) ;
return 0 ;
}
V_4 = F_12 ( V_2 , V_74 ) ;
if ( V_4 < 0 ) {
F_24 ( & V_2 -> V_47 ) ;
return V_4 ;
}
if ( V_2 -> V_87 == V_84 )
V_4 = F_18 ( V_2 , V_74 ) ;
else
V_4 = F_19 ( V_2 , V_74 ) ;
if ( V_4 < 0 ) {
F_12 ( V_2 , false ) ;
F_24 ( & V_2 -> V_47 ) ;
return V_4 ;
}
if ( V_2 -> V_87 == V_84 )
V_2 -> V_75 = V_74 ;
else
V_2 -> V_37 = V_74 ;
F_24 ( & V_2 -> V_47 ) ;
return 0 ;
}
static T_3 F_45 ( int V_76 , void * V_88 )
{
struct V_50 * V_51 = V_88 ;
struct V_1 * V_2 = F_31 ( V_51 ) ;
int V_4 ;
int V_68 ;
unsigned int V_8 ;
V_4 = F_8 ( V_2 -> V_5 , V_89 , & V_8 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 , L_18 ) ;
goto V_90;
}
if ( V_8 & 0x08 )
V_68 = V_91 ;
else
V_68 = V_92 ;
if ( V_8 & V_93 )
F_46 ( V_51 , F_47 ( V_58 ,
0 ,
V_94 ,
V_95 ,
V_68 ) ,
F_48 () ) ;
if ( V_8 & V_96 )
F_46 ( V_51 , F_47 ( V_58 ,
0 ,
V_97 ,
V_95 ,
V_68 ) ,
F_48 () ) ;
if ( V_8 & V_98 )
F_46 ( V_51 , F_47 ( V_58 ,
0 ,
V_99 ,
V_95 ,
V_68 ) ,
F_48 () ) ;
V_90:
if ( ! V_2 -> V_37 ) {
V_4 = F_2 ( V_2 -> V_5 , V_26 ,
V_27 |
V_28 ) ;
if ( V_4 < 0 )
F_3 ( V_2 -> V_7 ,
L_13 ) ;
}
return V_85 ;
}
static T_3 F_49 ( int V_76 , void * V_88 )
{
struct V_50 * V_51 = V_88 ;
struct V_1 * V_2 = F_31 ( V_51 ) ;
if ( V_2 -> V_37 )
F_50 ( V_2 -> V_100 ) ;
else if ( V_2 -> V_75 )
F_50 ( V_2 -> V_87 ) ;
if ( V_2 -> V_73 )
return V_101 ;
else
return V_85 ;
}
static int F_51 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_31 ( V_51 ) ;
return F_12 ( V_2 , true ) ;
}
static int F_52 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_31 ( V_51 ) ;
return F_12 ( V_2 , false ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_102 * V_7 ;
struct V_103 * V_104 ;
V_7 = V_2 -> V_7 ;
V_104 = F_54 ( V_7 , V_105 , 0 , V_106 ) ;
if ( F_55 ( V_104 ) ) {
F_3 ( V_7 , L_19 ) ;
return F_56 ( V_104 ) ;
}
V_2 -> V_76 = F_57 ( V_104 ) ;
F_9 ( V_7 , L_20 , F_58 ( V_104 ) ,
V_2 -> V_76 ) ;
return 0 ;
}
static const char * F_59 ( struct V_102 * V_7 )
{
const struct V_107 * V_108 ;
V_108 = F_60 ( V_7 -> V_109 -> V_110 , V_7 ) ;
if ( ! V_108 )
return NULL ;
return F_61 ( V_7 ) ;
}
int F_62 ( struct V_102 * V_7 , struct V_5 * V_5 , int V_76 ,
const char * V_111 )
{
struct V_1 * V_2 ;
struct V_50 * V_51 ;
int V_4 ;
V_51 = F_63 ( V_7 , sizeof( * V_2 ) ) ;
if ( ! V_51 )
return - V_112 ;
V_2 = F_31 ( V_51 ) ;
F_64 ( V_7 , V_51 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_76 = V_76 ;
V_2 -> V_5 = V_5 ;
V_4 = F_7 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
F_65 ( & V_2 -> V_47 ) ;
if ( F_66 ( V_7 ) )
V_111 = F_59 ( V_7 ) ;
V_51 -> V_7 . V_113 = V_7 ;
V_51 -> V_114 = V_115 ;
V_51 -> V_116 = F_5 ( V_115 ) ;
V_51 -> V_111 = V_111 ;
V_51 -> V_117 = V_118 ;
V_51 -> V_70 = & V_119 ;
if ( V_2 -> V_76 <= 0 )
F_53 ( V_2 ) ;
if ( V_2 -> V_76 > 0 ) {
V_4 = F_67 ( V_7 ,
V_2 -> V_76 ,
F_49 ,
F_45 ,
V_120 ,
V_121 ,
V_51 ) ;
if ( V_4 )
return V_4 ;
V_2 -> V_100 = F_68 ( V_7 ,
L_21 ,
V_51 -> V_111 ,
V_51 -> V_108 ) ;
if ( ! V_2 -> V_100 )
return - V_112 ;
V_2 -> V_87 = F_68 ( V_7 ,
L_22 ,
V_51 -> V_111 ,
V_51 -> V_108 ) ;
if ( ! V_2 -> V_87 )
return - V_112 ;
V_2 -> V_100 -> V_7 . V_113 = V_7 ;
V_2 -> V_100 -> V_122 = & V_123 ;
F_69 ( V_2 -> V_100 , V_51 ) ;
V_4 = F_70 ( V_2 -> V_100 ) ;
if ( V_4 )
return V_4 ;
V_2 -> V_87 -> V_7 . V_113 = V_7 ;
V_2 -> V_87 -> V_122 = & V_123 ;
F_69 ( V_2 -> V_87 , V_51 ) ;
V_4 = F_70 ( V_2 -> V_87 ) ;
if ( V_4 ) {
V_2 -> V_87 = NULL ;
goto V_124;
}
}
V_4 = F_71 ( V_51 ,
V_125 ,
F_38 ,
& V_126 ) ;
if ( V_4 < 0 ) {
F_3 ( V_7 ,
L_23 ) ;
goto V_124;
}
V_4 = F_72 ( V_7 ) ;
if ( V_4 )
goto V_127;
F_73 ( V_7 ) ;
F_74 ( V_7 ,
V_128 ) ;
F_75 ( V_7 ) ;
V_4 = F_76 ( V_51 ) ;
if ( V_4 < 0 ) {
F_3 ( V_7 , L_24 ) ;
goto V_127;
}
return 0 ;
V_127:
F_77 ( V_51 ) ;
V_124:
if ( V_2 -> V_100 )
F_78 ( V_2 -> V_100 ) ;
if ( V_2 -> V_87 )
F_78 ( V_2 -> V_87 ) ;
return V_4 ;
}
void F_79 ( struct V_102 * V_7 )
{
struct V_50 * V_51 = F_80 ( V_7 ) ;
struct V_1 * V_2 = F_31 ( V_51 ) ;
F_81 ( V_51 ) ;
F_82 ( V_7 ) ;
F_83 ( V_7 ) ;
F_17 ( V_7 ) ;
F_77 ( V_51 ) ;
if ( V_2 -> V_100 ) {
F_78 ( V_2 -> V_100 ) ;
F_78 ( V_2 -> V_87 ) ;
}
F_23 ( & V_2 -> V_47 ) ;
F_1 ( V_2 , V_129 ) ;
F_24 ( & V_2 -> V_47 ) ;
}
static int F_84 ( struct V_102 * V_7 )
{
struct V_50 * V_51 = F_80 ( V_7 ) ;
struct V_1 * V_2 = F_31 ( V_51 ) ;
F_23 ( & V_2 -> V_47 ) ;
F_1 ( V_2 , V_130 ) ;
F_24 ( & V_2 -> V_47 ) ;
return 0 ;
}
static int F_85 ( struct V_102 * V_7 )
{
struct V_50 * V_51 = F_80 ( V_7 ) ;
struct V_1 * V_2 = F_31 ( V_51 ) ;
F_23 ( & V_2 -> V_47 ) ;
if ( V_2 -> V_37 || V_2 -> V_75 ||
V_2 -> V_73 )
F_1 ( V_2 , V_17 ) ;
F_24 ( & V_2 -> V_47 ) ;
return 0 ;
}
static int F_86 ( struct V_102 * V_7 )
{
struct V_50 * V_51 = F_80 ( V_7 ) ;
struct V_1 * V_2 = F_31 ( V_51 ) ;
int V_4 ;
V_4 = F_1 ( V_2 , V_130 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_7 , L_25 ) ;
return - V_131 ;
}
return 0 ;
}
static int F_87 ( struct V_102 * V_7 )
{
struct V_50 * V_51 = F_80 ( V_7 ) ;
struct V_1 * V_2 = F_31 ( V_51 ) ;
int V_4 ;
V_4 = F_1 ( V_2 , V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
F_88 ( V_132 ) ;
return 0 ;
}
