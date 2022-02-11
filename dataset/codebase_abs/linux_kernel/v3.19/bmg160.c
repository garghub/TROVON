static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 ,
V_6 , V_3 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 , L_1 ) ;
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
V_4 = F_2 ( V_2 -> V_5 , V_13 ,
V_11 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 , L_2 ) ;
return V_4 ;
}
V_2 -> V_11 = V_11 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_8 ( V_2 -> V_5 , V_14 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 , L_3 ) ;
return V_4 ;
}
F_9 ( & V_2 -> V_5 -> V_7 , L_4 , V_4 ) ;
if ( V_4 != V_15 ) {
F_3 ( & V_2 -> V_5 -> V_7 , L_5 , V_4 ) ;
return - V_16 ;
}
V_4 = F_1 ( V_2 , V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
F_10 ( 500 , 1000 ) ;
V_4 = F_6 ( V_2 , V_18 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_2 ( V_2 -> V_5 ,
V_19 ,
V_20 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 , L_6 ) ;
return V_4 ;
}
V_2 -> V_21 = V_20 ;
V_4 = F_8 ( V_2 -> V_5 , V_22 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 , L_7 ) ;
return V_4 ;
}
V_2 -> V_23 = V_4 ;
V_4 = F_8 ( V_2 -> V_5 , V_24 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 , L_8 ) ;
return V_4 ;
}
V_4 &= ~ V_25 ;
V_4 = F_2 ( V_2 -> V_5 ,
V_24 , V_4 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 , L_9 ) ;
return V_4 ;
}
V_4 = F_2 ( V_2 -> V_5 ,
V_26 ,
V_27 |
V_28 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 ,
L_10 ) ;
return V_4 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , bool V_29 )
{
#ifdef F_12
int V_4 ;
if ( V_29 )
V_4 = F_13 ( & V_2 -> V_5 -> V_7 ) ;
else {
F_14 ( & V_2 -> V_5 -> V_7 ) ;
V_4 = F_15 ( & V_2 -> V_5 -> V_7 ) ;
}
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 ,
L_11 , V_29 ) ;
if ( V_29 )
F_16 ( & V_2 -> V_5 -> V_7 ) ;
return V_4 ;
}
#endif
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
bool V_30 )
{
int V_4 ;
V_4 = F_8 ( V_2 -> V_5 , V_31 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 , L_12 ) ;
return V_4 ;
}
if ( V_30 )
V_4 |= V_32 ;
else
V_4 &= ~ V_32 ;
V_4 = F_2 ( V_2 -> V_5 ,
V_31 ,
V_4 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 , L_13 ) ;
return V_4 ;
}
if ( V_30 ) {
V_4 = F_2 ( V_2 -> V_5 ,
V_22 ,
V_2 -> V_23 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 ,
L_14 ) ;
return V_4 ;
}
V_4 = F_2 ( V_2 -> V_5 ,
V_33 ,
V_34 |
V_35 |
V_36 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 ,
L_10 ) ;
return V_4 ;
}
if ( ! V_2 -> V_37 ) {
V_4 = F_2 ( V_2 -> V_5 ,
V_26 ,
V_27 |
V_28 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 ,
L_15 ) ;
return V_4 ;
}
}
V_4 = F_2 ( V_2 -> V_5 ,
V_38 ,
V_39 ) ;
} else
V_4 = F_2 ( V_2 -> V_5 ,
V_38 ,
0 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 , L_16 ) ;
return V_4 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
bool V_30 )
{
int V_4 ;
V_4 = F_8 ( V_2 -> V_5 , V_40 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 , L_17 ) ;
return V_4 ;
}
if ( V_30 )
V_4 |= V_41 ;
else
V_4 &= ~ V_41 ;
V_4 = F_2 ( V_2 -> V_5 ,
V_40 ,
V_4 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 , L_18 ) ;
return V_4 ;
}
if ( V_30 ) {
V_4 = F_2 ( V_2 -> V_5 ,
V_26 ,
V_42 |
V_28 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 ,
L_15 ) ;
return V_4 ;
}
V_4 = F_2 ( V_2 -> V_5 ,
V_38 ,
V_39 ) ;
} else {
V_4 = F_2 ( V_2 -> V_5 ,
V_26 ,
V_27 |
V_28 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 ,
L_15 ) ;
return V_4 ;
}
V_4 = F_2 ( V_2 -> V_5 ,
V_38 ,
0 ) ;
}
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 , L_16 ) ;
return V_4 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int * V_8 )
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
static int F_20 ( struct V_1 * V_2 , int V_8 )
{
int V_4 , V_9 ;
for ( V_9 = 0 ; V_9 < F_5 ( V_44 ) ; ++ V_9 ) {
if ( V_44 [ V_9 ] . V_45 == V_8 ) {
V_4 = F_2 (
V_2 -> V_5 ,
V_19 ,
V_44 [ V_9 ] . V_21 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 ,
L_6 ) ;
return V_4 ;
}
V_2 -> V_21 = V_44 [ V_9 ] . V_21 ;
return 0 ;
}
}
return - V_12 ;
}
static int F_21 ( struct V_1 * V_2 , int * V_8 )
{
int V_4 ;
F_22 ( & V_2 -> V_46 ) ;
V_4 = F_11 ( V_2 , true ) ;
if ( V_4 < 0 ) {
F_23 ( & V_2 -> V_46 ) ;
return V_4 ;
}
V_4 = F_8 ( V_2 -> V_5 , V_47 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 , L_19 ) ;
F_11 ( V_2 , false ) ;
F_23 ( & V_2 -> V_46 ) ;
return V_4 ;
}
* V_8 = F_24 ( V_4 , 7 ) ;
V_4 = F_11 ( V_2 , false ) ;
F_23 ( & V_2 -> V_46 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_43 ;
}
static int F_25 ( struct V_1 * V_2 , int V_48 , int * V_8 )
{
int V_4 ;
F_22 ( & V_2 -> V_46 ) ;
V_4 = F_11 ( V_2 , true ) ;
if ( V_4 < 0 ) {
F_23 ( & V_2 -> V_46 ) ;
return V_4 ;
}
V_4 = F_26 ( V_2 -> V_5 , F_27 ( V_48 ) ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 , L_20 , V_48 ) ;
F_11 ( V_2 , false ) ;
F_23 ( & V_2 -> V_46 ) ;
return V_4 ;
}
* V_8 = F_24 ( V_4 , 15 ) ;
V_4 = F_11 ( V_2 , false ) ;
F_23 ( & V_2 -> V_46 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_43 ;
}
static int F_28 ( struct V_49 * V_50 ,
struct V_51 const * V_52 ,
int * V_8 , int * V_53 , long V_54 )
{
struct V_1 * V_2 = F_29 ( V_50 ) ;
int V_4 ;
switch ( V_54 ) {
case V_55 :
switch ( V_52 -> type ) {
case V_56 :
return F_21 ( V_2 , V_8 ) ;
case V_57 :
if ( F_30 ( V_50 ) )
return - V_58 ;
else
return F_25 ( V_2 , V_52 -> V_59 ,
V_8 ) ;
default:
return - V_12 ;
}
case V_60 :
if ( V_52 -> type == V_56 ) {
* V_8 = V_61 ;
return V_43 ;
} else
return - V_12 ;
case V_62 :
* V_8 = 0 ;
switch ( V_52 -> type ) {
case V_56 :
* V_53 = 500000 ;
return V_63 ;
case V_57 :
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_5 ( V_44 ) ; ++ V_9 ) {
if ( V_44 [ V_9 ] . V_21 ==
V_2 -> V_21 ) {
* V_53 = V_44 [ V_9 ] . V_45 ;
return V_63 ;
}
}
return - V_12 ;
}
default:
return - V_12 ;
}
case V_64 :
* V_53 = 0 ;
F_22 ( & V_2 -> V_46 ) ;
V_4 = F_19 ( V_2 , V_8 ) ;
F_23 ( & V_2 -> V_46 ) ;
return V_4 ;
default:
return - V_12 ;
}
}
static int F_31 ( struct V_49 * V_50 ,
struct V_51 const * V_52 ,
int V_8 , int V_53 , long V_54 )
{
struct V_1 * V_2 = F_29 ( V_50 ) ;
int V_4 ;
switch ( V_54 ) {
case V_64 :
F_22 ( & V_2 -> V_46 ) ;
V_4 = F_11 ( V_2 , true ) ;
if ( V_4 < 0 ) {
F_23 ( & V_2 -> V_46 ) ;
return V_4 ;
}
V_4 = F_6 ( V_2 , V_8 ) ;
if ( V_4 < 0 ) {
F_11 ( V_2 , false ) ;
F_23 ( & V_2 -> V_46 ) ;
return V_4 ;
}
V_4 = F_11 ( V_2 , false ) ;
F_23 ( & V_2 -> V_46 ) ;
return V_4 ;
case V_62 :
if ( V_8 )
return - V_12 ;
F_22 ( & V_2 -> V_46 ) ;
V_4 = F_11 ( V_2 , true ) ;
if ( V_4 < 0 ) {
F_23 ( & V_2 -> V_46 ) ;
return V_4 ;
}
V_4 = F_20 ( V_2 , V_53 ) ;
if ( V_4 < 0 ) {
F_11 ( V_2 , false ) ;
F_23 ( & V_2 -> V_46 ) ;
return V_4 ;
}
V_4 = F_11 ( V_2 , false ) ;
F_23 ( & V_2 -> V_46 ) ;
return V_4 ;
default:
return - V_12 ;
}
return - V_12 ;
}
static int F_32 ( struct V_49 * V_50 ,
const struct V_51 * V_52 ,
enum V_65 type ,
enum V_66 V_67 ,
enum V_68 V_69 ,
int * V_8 , int * V_53 )
{
struct V_1 * V_2 = F_29 ( V_50 ) ;
* V_53 = 0 ;
switch ( V_69 ) {
case V_70 :
* V_8 = V_2 -> V_23 & V_71 ;
break;
default:
return - V_12 ;
}
return V_43 ;
}
static int F_33 ( struct V_49 * V_50 ,
const struct V_51 * V_52 ,
enum V_65 type ,
enum V_66 V_67 ,
enum V_68 V_69 ,
int V_8 , int V_53 )
{
struct V_1 * V_2 = F_29 ( V_50 ) ;
switch ( V_69 ) {
case V_70 :
if ( V_2 -> V_72 )
return - V_58 ;
V_2 -> V_23 &= ~ V_71 ;
V_2 -> V_23 |= ( V_8 & V_71 ) ;
break;
default:
return - V_12 ;
}
return 0 ;
}
static int F_34 ( struct V_49 * V_50 ,
const struct V_51 * V_52 ,
enum V_65 type ,
enum V_66 V_67 )
{
struct V_1 * V_2 = F_29 ( V_50 ) ;
return V_2 -> V_72 ;
}
static int F_35 ( struct V_49 * V_50 ,
const struct V_51 * V_52 ,
enum V_65 type ,
enum V_66 V_67 ,
int V_73 )
{
struct V_1 * V_2 = F_29 ( V_50 ) ;
int V_4 ;
if ( V_73 && V_2 -> V_72 )
return 0 ;
F_22 ( & V_2 -> V_46 ) ;
if ( ! V_73 && V_2 -> V_74 ) {
V_2 -> V_72 = 0 ;
F_23 ( & V_2 -> V_46 ) ;
return 0 ;
}
V_4 = F_11 ( V_2 , V_73 ) ;
if ( V_4 < 0 ) {
F_23 ( & V_2 -> V_46 ) ;
return V_4 ;
}
V_4 = F_17 ( V_2 , V_73 ) ;
if ( V_4 < 0 ) {
F_11 ( V_2 , false ) ;
F_23 ( & V_2 -> V_46 ) ;
return V_4 ;
}
V_2 -> V_72 = V_73 ;
F_23 ( & V_2 -> V_46 ) ;
return 0 ;
}
static int F_36 ( struct V_49 * V_50 ,
struct V_75 * V_76 )
{
struct V_1 * V_2 = F_29 ( V_50 ) ;
if ( V_2 -> V_77 != V_76 && V_2 -> V_78 != V_76 )
return - V_12 ;
return 0 ;
}
static T_2 F_37 ( int V_79 , void * V_80 )
{
struct V_81 * V_82 = V_80 ;
struct V_49 * V_50 = V_82 -> V_50 ;
struct V_1 * V_2 = F_29 ( V_50 ) ;
int V_83 , V_4 , V_9 = 0 ;
F_22 ( & V_2 -> V_46 ) ;
F_38 (bit, indio_dev->buffer->scan_mask,
indio_dev->masklength) {
V_4 = F_26 ( V_2 -> V_5 ,
F_27 ( V_83 ) ) ;
if ( V_4 < 0 ) {
F_23 ( & V_2 -> V_46 ) ;
goto V_84;
}
V_2 -> V_85 [ V_9 ++ ] = V_4 ;
}
F_23 ( & V_2 -> V_46 ) ;
F_39 ( V_50 , V_2 -> V_85 ,
V_2 -> V_86 ) ;
V_84:
F_40 ( V_50 -> V_76 ) ;
return V_87 ;
}
static int F_41 ( struct V_75 * V_76 )
{
struct V_49 * V_50 = F_42 ( V_76 ) ;
struct V_1 * V_2 = F_29 ( V_50 ) ;
int V_4 ;
if ( V_2 -> V_37 )
return 0 ;
V_4 = F_2 ( V_2 -> V_5 ,
V_26 ,
V_27 |
V_28 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 , L_15 ) ;
return V_4 ;
}
return 0 ;
}
static int F_43 ( struct V_75 * V_76 ,
bool V_73 )
{
struct V_49 * V_50 = F_42 ( V_76 ) ;
struct V_1 * V_2 = F_29 ( V_50 ) ;
int V_4 ;
F_22 ( & V_2 -> V_46 ) ;
if ( ! V_73 && V_2 -> V_72 && V_2 -> V_74 ) {
V_2 -> V_74 = false ;
F_23 ( & V_2 -> V_46 ) ;
return 0 ;
}
V_4 = F_11 ( V_2 , V_73 ) ;
if ( V_4 < 0 ) {
F_23 ( & V_2 -> V_46 ) ;
return V_4 ;
}
if ( V_2 -> V_78 == V_76 )
V_4 = F_17 ( V_2 , V_73 ) ;
else
V_4 = F_18 ( V_2 , V_73 ) ;
if ( V_4 < 0 ) {
F_11 ( V_2 , false ) ;
F_23 ( & V_2 -> V_46 ) ;
return V_4 ;
}
if ( V_2 -> V_78 == V_76 )
V_2 -> V_74 = V_73 ;
else
V_2 -> V_37 = V_73 ;
F_23 ( & V_2 -> V_46 ) ;
return 0 ;
}
static T_2 F_44 ( int V_79 , void * V_88 )
{
struct V_49 * V_50 = V_88 ;
struct V_1 * V_2 = F_29 ( V_50 ) ;
int V_4 ;
int V_67 ;
V_4 = F_8 ( V_2 -> V_5 , V_89 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 , L_21 ) ;
goto V_90;
}
if ( V_4 & 0x08 )
V_67 = V_91 ;
else
V_67 = V_92 ;
if ( V_4 & V_93 )
F_45 ( V_50 , F_46 ( V_57 ,
0 ,
V_94 ,
V_95 ,
V_67 ) ,
V_2 -> V_86 ) ;
if ( V_4 & V_96 )
F_45 ( V_50 , F_46 ( V_57 ,
0 ,
V_97 ,
V_95 ,
V_67 ) ,
V_2 -> V_86 ) ;
if ( V_4 & V_98 )
F_45 ( V_50 , F_46 ( V_57 ,
0 ,
V_99 ,
V_95 ,
V_67 ) ,
V_2 -> V_86 ) ;
V_90:
if ( ! V_2 -> V_37 ) {
V_4 = F_2 ( V_2 -> V_5 ,
V_26 ,
V_27 |
V_28 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_5 -> V_7 ,
L_15 ) ;
}
return V_87 ;
}
static T_2 F_47 ( int V_79 , void * V_88 )
{
struct V_49 * V_50 = V_88 ;
struct V_1 * V_2 = F_29 ( V_50 ) ;
V_2 -> V_86 = F_48 () ;
if ( V_2 -> V_37 )
F_49 ( V_2 -> V_77 ) ;
else if ( V_2 -> V_74 )
F_49 ( V_2 -> V_78 ) ;
if ( V_2 -> V_72 )
return V_100 ;
else
return V_87 ;
}
static int F_50 ( struct V_101 * V_5 ,
struct V_1 * V_2 )
{
struct V_102 * V_7 ;
struct V_103 * V_104 ;
int V_4 ;
if ( ! V_5 )
return - V_12 ;
V_7 = & V_5 -> V_7 ;
V_104 = F_51 ( V_7 , V_105 , 0 ) ;
if ( F_52 ( V_104 ) ) {
F_3 ( V_7 , L_22 ) ;
return F_53 ( V_104 ) ;
}
V_4 = F_54 ( V_104 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_55 ( V_104 ) ;
F_9 ( V_7 , L_23 , F_56 ( V_104 ) , V_4 ) ;
return V_4 ;
}
static const char * F_57 ( struct V_102 * V_7 )
{
const struct V_106 * V_107 ;
V_107 = F_58 ( V_7 -> V_108 -> V_109 , V_7 ) ;
if ( ! V_107 )
return NULL ;
return F_59 ( V_7 ) ;
}
static int F_60 ( struct V_101 * V_5 ,
const struct V_110 * V_107 )
{
struct V_1 * V_2 ;
struct V_49 * V_50 ;
int V_4 ;
const char * V_111 = NULL ;
V_50 = F_61 ( & V_5 -> V_7 , sizeof( * V_2 ) ) ;
if ( ! V_50 )
return - V_112 ;
V_2 = F_29 ( V_50 ) ;
F_62 ( V_5 , V_50 ) ;
V_2 -> V_5 = V_5 ;
V_4 = F_7 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
F_63 ( & V_2 -> V_46 ) ;
if ( V_107 )
V_111 = V_107 -> V_111 ;
if ( F_64 ( & V_5 -> V_7 ) )
V_111 = F_57 ( & V_5 -> V_7 ) ;
V_50 -> V_7 . V_113 = & V_5 -> V_7 ;
V_50 -> V_114 = V_115 ;
V_50 -> V_116 = F_5 ( V_115 ) ;
V_50 -> V_111 = V_111 ;
V_50 -> V_117 = V_118 ;
V_50 -> V_69 = & V_119 ;
if ( V_5 -> V_79 <= 0 )
V_5 -> V_79 = F_50 ( V_5 , V_2 ) ;
if ( V_5 -> V_79 > 0 ) {
V_4 = F_65 ( & V_5 -> V_7 ,
V_5 -> V_79 ,
F_47 ,
F_44 ,
V_120 ,
V_121 ,
V_50 ) ;
if ( V_4 )
return V_4 ;
V_2 -> V_77 = F_66 ( & V_5 -> V_7 ,
L_24 ,
V_50 -> V_111 ,
V_50 -> V_107 ) ;
if ( ! V_2 -> V_77 )
return - V_112 ;
V_2 -> V_78 = F_66 ( & V_5 -> V_7 ,
L_25 ,
V_50 -> V_111 ,
V_50 -> V_107 ) ;
if ( ! V_2 -> V_78 )
return - V_112 ;
V_2 -> V_77 -> V_7 . V_113 = & V_5 -> V_7 ;
V_2 -> V_77 -> V_122 = & V_123 ;
F_67 ( V_2 -> V_77 , V_50 ) ;
V_4 = F_68 ( V_2 -> V_77 ) ;
if ( V_4 )
return V_4 ;
V_2 -> V_78 -> V_7 . V_113 = & V_5 -> V_7 ;
V_2 -> V_78 -> V_122 = & V_123 ;
F_67 ( V_2 -> V_78 , V_50 ) ;
V_4 = F_68 ( V_2 -> V_78 ) ;
if ( V_4 ) {
V_2 -> V_78 = NULL ;
goto V_124;
}
V_4 = F_69 ( V_50 ,
NULL ,
F_37 ,
NULL ) ;
if ( V_4 < 0 ) {
F_3 ( & V_5 -> V_7 ,
L_26 ) ;
goto V_124;
}
}
V_4 = F_70 ( V_50 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_5 -> V_7 , L_27 ) ;
goto V_125;
}
V_4 = F_71 ( & V_5 -> V_7 ) ;
if ( V_4 )
goto V_126;
F_72 ( & V_5 -> V_7 ) ;
F_73 ( & V_5 -> V_7 ,
V_127 ) ;
F_74 ( & V_5 -> V_7 ) ;
return 0 ;
V_126:
F_75 ( V_50 ) ;
V_125:
if ( V_2 -> V_77 )
F_76 ( V_50 ) ;
V_124:
if ( V_2 -> V_77 )
F_77 ( V_2 -> V_77 ) ;
if ( V_2 -> V_78 )
F_77 ( V_2 -> V_78 ) ;
return V_4 ;
}
static int F_78 ( struct V_101 * V_5 )
{
struct V_49 * V_50 = F_79 ( V_5 ) ;
struct V_1 * V_2 = F_29 ( V_50 ) ;
F_80 ( & V_5 -> V_7 ) ;
F_81 ( & V_5 -> V_7 ) ;
F_16 ( & V_5 -> V_7 ) ;
F_75 ( V_50 ) ;
if ( V_2 -> V_77 ) {
F_76 ( V_50 ) ;
F_77 ( V_2 -> V_77 ) ;
F_77 ( V_2 -> V_78 ) ;
}
F_22 ( & V_2 -> V_46 ) ;
F_1 ( V_2 , V_128 ) ;
F_23 ( & V_2 -> V_46 ) ;
return 0 ;
}
static int F_82 ( struct V_102 * V_7 )
{
struct V_49 * V_50 = F_79 ( F_83 ( V_7 ) ) ;
struct V_1 * V_2 = F_29 ( V_50 ) ;
F_22 ( & V_2 -> V_46 ) ;
F_1 ( V_2 , V_129 ) ;
F_23 ( & V_2 -> V_46 ) ;
return 0 ;
}
static int F_84 ( struct V_102 * V_7 )
{
struct V_49 * V_50 = F_79 ( F_83 ( V_7 ) ) ;
struct V_1 * V_2 = F_29 ( V_50 ) ;
F_22 ( & V_2 -> V_46 ) ;
if ( V_2 -> V_37 || V_2 -> V_74 ||
V_2 -> V_72 )
F_1 ( V_2 , V_17 ) ;
F_23 ( & V_2 -> V_46 ) ;
return 0 ;
}
static int F_85 ( struct V_102 * V_7 )
{
struct V_49 * V_50 = F_79 ( F_83 ( V_7 ) ) ;
struct V_1 * V_2 = F_29 ( V_50 ) ;
int V_4 ;
V_4 = F_1 ( V_2 , V_129 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_7 , L_28 ) ;
return - V_130 ;
}
return 0 ;
}
static int F_86 ( struct V_102 * V_7 )
{
struct V_49 * V_50 = F_79 ( F_83 ( V_7 ) ) ;
struct V_1 * V_2 = F_29 ( V_50 ) ;
int V_4 ;
V_4 = F_1 ( V_2 , V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
F_87 ( V_131 ) ;
return 0 ;
}
