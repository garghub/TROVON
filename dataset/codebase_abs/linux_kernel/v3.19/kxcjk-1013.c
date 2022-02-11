static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_1 ) ;
return V_5 ;
}
if ( V_4 == V_9 )
V_5 &= ~ V_10 ;
else
V_5 |= V_10 ;
V_5 = F_4 ( V_2 -> V_6 ,
V_7 , V_5 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_2 ) ;
return V_5 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
enum V_3 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_1 ) ;
return V_5 ;
}
if ( V_5 & V_10 )
* V_4 = V_11 ;
else
* V_4 = V_9 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , int V_12 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_1 ) ;
return V_5 ;
}
V_5 &= ~ ( V_13 |
V_14 ) ;
V_5 |= ( V_15 [ V_12 ] . V_16 << 3 ) ;
V_5 |= ( V_15 [ V_12 ] . V_17 << 4 ) ;
V_5 = F_4 ( V_2 -> V_6 ,
V_7 ,
V_5 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_2 ) ;
return V_5 ;
}
V_2 -> V_18 = V_12 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_19 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_3 ) ;
return V_5 ;
}
F_8 ( & V_2 -> V_6 -> V_8 , L_4 , V_5 ) ;
V_5 = F_1 ( V_2 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_1 ) ;
return V_5 ;
}
V_5 |= V_20 ;
V_5 = F_4 ( V_2 -> V_6 , V_7 ,
V_5 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_5 ) ;
return V_5 ;
}
V_5 = F_6 ( V_2 , V_21 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_22 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_6 ) ;
return V_5 ;
}
V_2 -> V_23 = V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_24 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_7 ) ;
return V_5 ;
}
if ( V_2 -> V_25 )
V_5 |= V_26 ;
else
V_5 &= ~ V_26 ;
V_5 = F_4 ( V_2 -> V_6 , V_24 ,
V_5 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_8 ) ;
return V_5 ;
}
V_5 = F_1 ( V_2 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_27 = V_28 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_29 ;
int V_30 = V_2 -> V_31 ;
for ( V_29 = 0 ; V_29 < F_10 ( V_32 [ V_30 ] ) ; ++ V_29 ) {
if ( V_32 [ V_30 ] [ V_29 ] . V_23 == V_2 -> V_23 )
return V_32 [ V_30 ] [ V_29 ] . V_33 ;
}
return V_34 ;
}
static int F_11 ( struct V_1 * V_2 , bool V_35 )
{
int V_5 ;
if ( V_35 )
V_5 = F_12 ( & V_2 -> V_6 -> V_8 ) ;
else {
F_13 ( & V_2 -> V_6 -> V_8 ) ;
V_5 = F_14 ( & V_2 -> V_6 -> V_8 ) ;
}
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 ,
L_9 , V_35 ) ;
return V_5 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_4 ( V_2 -> V_6 ,
V_36 ,
V_2 -> V_37 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 ,
L_10 ) ;
return V_5 ;
}
V_5 = F_4 ( V_2 -> V_6 ,
V_38 ,
V_2 -> V_27 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_11 ) ;
return V_5 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
bool V_39 )
{
int V_5 ;
enum V_3 V_40 ;
V_5 = F_5 ( V_2 , & V_40 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_1 ( V_2 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_15 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_24 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_7 ) ;
return V_5 ;
}
if ( V_39 )
V_5 |= V_41 ;
else
V_5 &= ~ V_41 ;
V_5 = F_4 ( V_2 -> V_6 , V_24 ,
V_5 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_8 ) ;
return V_5 ;
}
V_5 = F_2 ( V_2 -> V_6 , V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_1 ) ;
return V_5 ;
}
if ( V_39 )
V_5 |= V_42 ;
else
V_5 &= ~ V_42 ;
V_5 = F_4 ( V_2 -> V_6 ,
V_7 , V_5 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_2 ) ;
return V_5 ;
}
if ( V_40 == V_11 ) {
V_5 = F_1 ( V_2 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
bool V_39 )
{
int V_5 ;
enum V_3 V_40 ;
V_5 = F_5 ( V_2 , & V_40 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_1 ( V_2 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_24 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_7 ) ;
return V_5 ;
}
if ( V_39 )
V_5 |= V_41 ;
else
V_5 &= ~ V_41 ;
V_5 = F_4 ( V_2 -> V_6 , V_24 ,
V_5 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_8 ) ;
return V_5 ;
}
V_5 = F_2 ( V_2 -> V_6 , V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_1 ) ;
return V_5 ;
}
if ( V_39 )
V_5 |= V_43 ;
else
V_5 &= ~ V_43 ;
V_5 = F_4 ( V_2 -> V_6 ,
V_7 , V_5 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_2 ) ;
return V_5 ;
}
if ( V_40 == V_11 ) {
V_5 = F_1 ( V_2 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
}
return 0 ;
}
static int F_18 ( int V_44 , int V_45 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < F_10 ( V_46 ) ; ++ V_29 ) {
if ( V_46 [ V_29 ] . V_44 == V_44 &&
V_46 [ V_29 ] . V_45 == V_45 ) {
return V_46 [ V_29 ] . V_23 ;
}
}
return - V_47 ;
}
static int F_19 ( int V_44 , int V_45 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < F_10 ( V_48 ) ; ++ V_29 ) {
if ( V_48 [ V_29 ] . V_44 == V_44 &&
V_48 [ V_29 ] . V_45 == V_45 ) {
return V_48 [ V_29 ] . V_23 ;
}
}
return - V_47 ;
}
static int F_20 ( struct V_1 * V_2 , int V_44 , int V_45 )
{
int V_5 ;
int V_23 ;
enum V_3 V_40 ;
V_5 = F_5 ( V_2 , & V_40 ) ;
if ( V_5 < 0 )
return V_5 ;
V_23 = F_18 ( V_44 , V_45 ) ;
if ( V_23 < 0 )
return V_23 ;
V_5 = F_1 ( V_2 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_4 ( V_2 -> V_6 , V_22 ,
V_23 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_12 ) ;
return V_5 ;
}
V_2 -> V_23 = V_23 ;
V_23 = F_19 ( V_44 , V_45 ) ;
if ( V_23 < 0 )
return V_23 ;
V_5 = F_4 ( V_2 -> V_6 , V_49 ,
V_23 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_13 ) ;
return V_5 ;
}
if ( V_40 == V_11 ) {
V_5 = F_1 ( V_2 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , int * V_44 , int * V_45 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < F_10 ( V_46 ) ; ++ V_29 ) {
if ( V_46 [ V_29 ] . V_23 == V_2 -> V_23 ) {
* V_44 = V_46 [ V_29 ] . V_44 ;
* V_45 = V_46 [ V_29 ] . V_45 ;
return V_50 ;
}
}
return - V_47 ;
}
static int F_22 ( struct V_1 * V_2 , int V_51 )
{
T_1 V_52 = V_53 + V_51 * 2 ;
int V_5 ;
V_5 = F_23 ( V_2 -> V_6 , V_52 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 ,
L_14 , 'x' + V_51 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_24 ( struct V_1 * V_2 , int V_44 )
{
int V_5 , V_29 ;
enum V_3 V_40 ;
for ( V_29 = 0 ; V_29 < F_10 ( V_15 ) ; ++ V_29 ) {
if ( V_15 [ V_29 ] . V_54 == V_44 ) {
V_5 = F_5 ( V_2 , & V_40 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_1 ( V_2 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_6 ( V_2 , V_29 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_40 == V_11 ) {
V_5 = F_1 ( V_2 , V_11 ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
}
return - V_47 ;
}
static int F_25 ( struct V_55 * V_56 ,
struct V_57 const * V_58 , int * V_44 ,
int * V_45 , long V_59 )
{
struct V_1 * V_2 = F_26 ( V_56 ) ;
int V_5 ;
switch ( V_59 ) {
case V_60 :
F_27 ( & V_2 -> V_61 ) ;
if ( F_28 ( V_56 ) )
V_5 = - V_62 ;
else {
V_5 = F_11 ( V_2 , true ) ;
if ( V_5 < 0 ) {
F_29 ( & V_2 -> V_61 ) ;
return V_5 ;
}
V_5 = F_22 ( V_2 , V_58 -> V_63 ) ;
if ( V_5 < 0 ) {
F_11 ( V_2 , false ) ;
F_29 ( & V_2 -> V_61 ) ;
return V_5 ;
}
* V_44 = F_30 ( V_5 >> 4 , 11 ) ;
V_5 = F_11 ( V_2 , false ) ;
}
F_29 ( & V_2 -> V_61 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_64 ;
case V_65 :
* V_44 = 0 ;
* V_45 = V_15 [ V_2 -> V_18 ] . V_54 ;
return V_50 ;
case V_66 :
F_27 ( & V_2 -> V_61 ) ;
V_5 = F_21 ( V_2 , V_44 , V_45 ) ;
F_29 ( & V_2 -> V_61 ) ;
return V_5 ;
default:
return - V_47 ;
}
}
static int F_31 ( struct V_55 * V_56 ,
struct V_57 const * V_58 , int V_44 ,
int V_45 , long V_59 )
{
struct V_1 * V_2 = F_26 ( V_56 ) ;
int V_5 ;
switch ( V_59 ) {
case V_66 :
F_27 ( & V_2 -> V_61 ) ;
V_5 = F_20 ( V_2 , V_44 , V_45 ) ;
F_29 ( & V_2 -> V_61 ) ;
break;
case V_65 :
if ( V_44 )
return - V_47 ;
F_27 ( & V_2 -> V_61 ) ;
V_5 = F_24 ( V_2 , V_45 ) ;
F_29 ( & V_2 -> V_61 ) ;
break;
default:
V_5 = - V_47 ;
}
return V_5 ;
}
static int F_32 ( struct V_55 * V_56 ,
const struct V_57 * V_58 ,
enum V_67 type ,
enum V_68 V_69 ,
enum V_70 V_71 ,
int * V_44 , int * V_45 )
{
struct V_1 * V_2 = F_26 ( V_56 ) ;
* V_45 = 0 ;
switch ( V_71 ) {
case V_72 :
* V_44 = V_2 -> V_27 ;
break;
case V_73 :
* V_44 = V_2 -> V_37 ;
break;
default:
return - V_47 ;
}
return V_64 ;
}
static int F_33 ( struct V_55 * V_56 ,
const struct V_57 * V_58 ,
enum V_67 type ,
enum V_68 V_69 ,
enum V_70 V_71 ,
int V_44 , int V_45 )
{
struct V_1 * V_2 = F_26 ( V_56 ) ;
if ( V_2 -> V_74 )
return - V_62 ;
switch ( V_71 ) {
case V_72 :
V_2 -> V_27 = V_44 ;
break;
case V_73 :
V_2 -> V_37 = V_44 ;
break;
default:
return - V_47 ;
}
return 0 ;
}
static int F_34 ( struct V_55 * V_56 ,
const struct V_57 * V_58 ,
enum V_67 type ,
enum V_68 V_69 )
{
struct V_1 * V_2 = F_26 ( V_56 ) ;
return V_2 -> V_74 ;
}
static int F_35 ( struct V_55 * V_56 ,
const struct V_57 * V_58 ,
enum V_67 type ,
enum V_68 V_69 ,
int V_75 )
{
struct V_1 * V_2 = F_26 ( V_56 ) ;
int V_5 ;
if ( V_75 && V_2 -> V_74 )
return 0 ;
F_27 ( & V_2 -> V_61 ) ;
if ( ! V_75 && V_2 -> V_76 ) {
V_2 -> V_74 = 0 ;
F_29 ( & V_2 -> V_61 ) ;
return 0 ;
}
V_5 = F_11 ( V_2 , V_75 ) ;
if ( V_5 < 0 ) {
F_29 ( & V_2 -> V_61 ) ;
return V_5 ;
}
V_5 = F_16 ( V_2 , V_75 ) ;
if ( V_5 < 0 ) {
F_29 ( & V_2 -> V_61 ) ;
return V_5 ;
}
V_2 -> V_74 = V_75 ;
F_29 ( & V_2 -> V_61 ) ;
return 0 ;
}
static int F_36 ( struct V_55 * V_56 ,
struct V_77 * V_78 )
{
struct V_1 * V_2 = F_26 ( V_56 ) ;
if ( V_2 -> V_79 != V_78 && V_2 -> V_80 != V_78 )
return - V_47 ;
return 0 ;
}
static T_2 F_37 ( int V_81 , void * V_82 )
{
struct V_83 * V_84 = V_82 ;
struct V_55 * V_56 = V_84 -> V_56 ;
struct V_1 * V_2 = F_26 ( V_56 ) ;
int V_85 , V_5 , V_29 = 0 ;
F_27 ( & V_2 -> V_61 ) ;
F_38 (bit, indio_dev->buffer->scan_mask,
indio_dev->masklength) {
V_5 = F_22 ( V_2 , V_85 ) ;
if ( V_5 < 0 ) {
F_29 ( & V_2 -> V_61 ) ;
goto V_86;
}
V_2 -> V_87 [ V_29 ++ ] = V_5 ;
}
F_29 ( & V_2 -> V_61 ) ;
F_39 ( V_56 , V_2 -> V_87 ,
V_2 -> V_88 ) ;
V_86:
F_40 ( V_56 -> V_78 ) ;
return V_89 ;
}
static int F_41 ( struct V_77 * V_78 )
{
struct V_55 * V_56 = F_42 ( V_78 ) ;
struct V_1 * V_2 = F_26 ( V_56 ) ;
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_90 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_15 ) ;
return V_5 ;
}
return 0 ;
}
static int F_43 ( struct V_77 * V_78 ,
bool V_75 )
{
struct V_55 * V_56 = F_42 ( V_78 ) ;
struct V_1 * V_2 = F_26 ( V_56 ) ;
int V_5 ;
F_27 ( & V_2 -> V_61 ) ;
if ( ! V_75 && V_2 -> V_74 && V_2 -> V_76 ) {
V_2 -> V_76 = false ;
F_29 ( & V_2 -> V_61 ) ;
return 0 ;
}
V_5 = F_11 ( V_2 , V_75 ) ;
if ( V_5 < 0 ) {
F_29 ( & V_2 -> V_61 ) ;
return V_5 ;
}
if ( V_2 -> V_80 == V_78 )
V_5 = F_16 ( V_2 , V_75 ) ;
else
V_5 = F_17 ( V_2 , V_75 ) ;
if ( V_5 < 0 ) {
F_29 ( & V_2 -> V_61 ) ;
return V_5 ;
}
if ( V_2 -> V_80 == V_78 )
V_2 -> V_76 = V_75 ;
else
V_2 -> V_91 = V_75 ;
F_29 ( & V_2 -> V_61 ) ;
return 0 ;
}
static T_2 F_44 ( int V_81 , void * V_92 )
{
struct V_55 * V_56 = V_92 ;
struct V_1 * V_2 = F_26 ( V_56 ) ;
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_93 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_16 ) ;
goto V_94;
}
if ( V_5 & 0x02 ) {
V_5 = F_2 ( V_2 -> V_6 ,
V_95 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 ,
L_17 ) ;
goto V_94;
}
if ( V_5 & V_96 )
F_45 ( V_56 ,
F_46 ( V_97 ,
0 ,
V_98 ,
V_99 ,
V_100 ) ,
V_2 -> V_88 ) ;
if ( V_5 & V_101 )
F_45 ( V_56 ,
F_46 ( V_97 ,
0 ,
V_98 ,
V_99 ,
V_102 ) ,
V_2 -> V_88 ) ;
if ( V_5 & V_103 )
F_45 ( V_56 ,
F_46 ( V_97 ,
0 ,
V_104 ,
V_99 ,
V_100 ) ,
V_2 -> V_88 ) ;
if ( V_5 & V_105 )
F_45 ( V_56 ,
F_46 ( V_97 ,
0 ,
V_104 ,
V_99 ,
V_102 ) ,
V_2 -> V_88 ) ;
if ( V_5 & V_106 )
F_45 ( V_56 ,
F_46 ( V_97 ,
0 ,
V_107 ,
V_99 ,
V_100 ) ,
V_2 -> V_88 ) ;
if ( V_5 & V_108 )
F_45 ( V_56 ,
F_46 ( V_97 ,
0 ,
V_107 ,
V_99 ,
V_102 ) ,
V_2 -> V_88 ) ;
}
V_94:
if ( V_2 -> V_91 )
return V_89 ;
V_5 = F_2 ( V_2 -> V_6 , V_90 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_6 -> V_8 , L_15 ) ;
return V_89 ;
}
static T_2 F_47 ( int V_81 , void * V_92 )
{
struct V_55 * V_56 = V_92 ;
struct V_1 * V_2 = F_26 ( V_56 ) ;
V_2 -> V_88 = F_48 () ;
if ( V_2 -> V_91 )
F_49 ( V_2 -> V_79 ) ;
else if ( V_2 -> V_76 )
F_49 ( V_2 -> V_80 ) ;
if ( V_2 -> V_74 )
return V_109 ;
else
return V_89 ;
}
static const char * F_50 ( struct V_110 * V_8 ,
enum V_111 * V_31 )
{
const struct V_112 * V_113 ;
V_113 = F_51 ( V_8 -> V_114 -> V_115 , V_8 ) ;
if ( ! V_113 )
return NULL ;
* V_31 = (enum V_111 ) V_113 -> V_116 ;
return F_52 ( V_8 ) ;
}
static int F_53 ( struct V_117 * V_6 ,
struct V_1 * V_2 )
{
struct V_110 * V_8 ;
struct V_118 * V_119 ;
int V_5 ;
if ( ! V_6 )
return - V_47 ;
V_8 = & V_6 -> V_8 ;
V_119 = F_54 ( V_8 , L_18 , 0 ) ;
if ( F_55 ( V_119 ) ) {
F_3 ( V_8 , L_19 ) ;
return F_56 ( V_119 ) ;
}
V_5 = F_57 ( V_119 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_58 ( V_119 ) ;
F_8 ( V_8 , L_20 , F_59 ( V_119 ) , V_5 ) ;
return V_5 ;
}
static int F_60 ( struct V_117 * V_6 ,
const struct V_120 * V_113 )
{
struct V_1 * V_2 ;
struct V_55 * V_56 ;
struct V_121 * V_122 ;
const char * V_123 ;
int V_5 ;
V_56 = F_61 ( & V_6 -> V_8 , sizeof( * V_2 ) ) ;
if ( ! V_56 )
return - V_124 ;
V_2 = F_26 ( V_56 ) ;
F_62 ( V_6 , V_56 ) ;
V_2 -> V_6 = V_6 ;
V_122 = F_63 ( & V_6 -> V_8 ) ;
if ( V_122 )
V_2 -> V_25 = V_122 -> V_25 ;
else
V_2 -> V_25 = true ;
if ( V_113 ) {
V_2 -> V_31 = (enum V_111 ) ( V_113 -> V_116 ) ;
V_123 = V_113 -> V_123 ;
} else if ( F_64 ( & V_6 -> V_8 ) ) {
V_123 = F_50 ( & V_6 -> V_8 ,
& V_2 -> V_31 ) ;
} else
return - V_125 ;
V_5 = F_7 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
F_65 ( & V_2 -> V_61 ) ;
V_56 -> V_8 . V_126 = & V_6 -> V_8 ;
V_56 -> V_127 = V_128 ;
V_56 -> V_129 = F_10 ( V_128 ) ;
V_56 -> V_123 = V_123 ;
V_56 -> V_130 = V_131 ;
V_56 -> V_71 = & V_132 ;
if ( V_6 -> V_81 < 0 )
V_6 -> V_81 = F_53 ( V_6 , V_2 ) ;
if ( V_6 -> V_81 >= 0 ) {
V_5 = F_66 ( & V_6 -> V_8 , V_6 -> V_81 ,
F_47 ,
F_44 ,
V_133 ,
V_134 ,
V_56 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_79 = F_67 ( & V_6 -> V_8 ,
L_21 ,
V_56 -> V_123 ,
V_56 -> V_113 ) ;
if ( ! V_2 -> V_79 )
return - V_124 ;
V_2 -> V_80 = F_67 ( & V_6 -> V_8 ,
L_22 ,
V_56 -> V_123 ,
V_56 -> V_113 ) ;
if ( ! V_2 -> V_80 )
return - V_124 ;
V_2 -> V_79 -> V_8 . V_126 = & V_6 -> V_8 ;
V_2 -> V_79 -> V_135 = & V_136 ;
F_68 ( V_2 -> V_79 , V_56 ) ;
V_56 -> V_78 = V_2 -> V_79 ;
F_69 ( V_56 -> V_78 ) ;
V_5 = F_70 ( V_2 -> V_79 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_80 -> V_8 . V_126 = & V_6 -> V_8 ;
V_2 -> V_80 -> V_135 = & V_136 ;
F_68 ( V_2 -> V_80 , V_56 ) ;
V_5 = F_70 ( V_2 -> V_80 ) ;
if ( V_5 ) {
V_2 -> V_80 = NULL ;
goto V_137;
}
V_5 = F_71 ( V_56 ,
& V_138 ,
F_37 ,
NULL ) ;
if ( V_5 < 0 ) {
F_3 ( & V_6 -> V_8 ,
L_23 ) ;
goto V_137;
}
}
V_5 = F_72 ( V_56 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_6 -> V_8 , L_24 ) ;
goto V_139;
}
V_5 = F_73 ( & V_6 -> V_8 ) ;
if ( V_5 )
goto V_140;
F_74 ( & V_6 -> V_8 ) ;
F_75 ( & V_6 -> V_8 ,
V_141 ) ;
F_76 ( & V_6 -> V_8 ) ;
return 0 ;
V_140:
F_77 ( V_56 ) ;
V_139:
if ( V_2 -> V_79 )
F_78 ( V_56 ) ;
V_137:
if ( V_2 -> V_79 )
F_79 ( V_2 -> V_79 ) ;
if ( V_2 -> V_80 )
F_79 ( V_2 -> V_80 ) ;
return V_5 ;
}
static int F_80 ( struct V_117 * V_6 )
{
struct V_55 * V_56 = F_81 ( V_6 ) ;
struct V_1 * V_2 = F_26 ( V_56 ) ;
F_82 ( & V_6 -> V_8 ) ;
F_83 ( & V_6 -> V_8 ) ;
F_84 ( & V_6 -> V_8 ) ;
F_77 ( V_56 ) ;
if ( V_2 -> V_79 ) {
F_78 ( V_56 ) ;
F_79 ( V_2 -> V_79 ) ;
F_79 ( V_2 -> V_80 ) ;
}
F_27 ( & V_2 -> V_61 ) ;
F_1 ( V_2 , V_9 ) ;
F_29 ( & V_2 -> V_61 ) ;
return 0 ;
}
static int F_85 ( struct V_110 * V_8 )
{
struct V_55 * V_56 = F_81 ( F_86 ( V_8 ) ) ;
struct V_1 * V_2 = F_26 ( V_56 ) ;
int V_5 ;
F_27 ( & V_2 -> V_61 ) ;
V_5 = F_1 ( V_2 , V_9 ) ;
F_29 ( & V_2 -> V_61 ) ;
return V_5 ;
}
static int F_87 ( struct V_110 * V_8 )
{
struct V_55 * V_56 = F_81 ( F_86 ( V_8 ) ) ;
struct V_1 * V_2 = F_26 ( V_56 ) ;
int V_5 = 0 ;
F_27 ( & V_2 -> V_61 ) ;
if ( V_2 -> V_91 || V_2 -> V_76 ||
V_2 -> V_74 )
V_5 = F_1 ( V_2 , V_11 ) ;
F_29 ( & V_2 -> V_61 ) ;
return V_5 ;
}
static int F_88 ( struct V_110 * V_8 )
{
struct V_55 * V_56 = F_81 ( F_86 ( V_8 ) ) ;
struct V_1 * V_2 = F_26 ( V_56 ) ;
return F_1 ( V_2 , V_9 ) ;
}
static int F_89 ( struct V_110 * V_8 )
{
struct V_55 * V_56 = F_81 ( F_86 ( V_8 ) ) ;
struct V_1 * V_2 = F_26 ( V_56 ) ;
int V_5 ;
int V_142 ;
V_5 = F_1 ( V_2 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
V_142 = F_9 ( V_2 ) ;
if ( V_142 < 20000 )
F_90 ( V_142 , 20000 ) ;
else
F_91 ( V_142 / 1000 ) ;
return 0 ;
}
