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
static int F_5 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_11 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_3 ) ;
return V_5 ;
}
F_6 ( & V_2 -> V_6 -> V_8 , L_4 , V_5 ) ;
V_5 = F_1 ( V_2 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_1 ) ;
return V_5 ;
}
V_5 |= V_12 ;
V_5 &= ~ V_13 ;
V_5 |= V_14 ;
V_5 = F_4 ( V_2 -> V_6 , V_7 ,
V_5 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_5 ) ;
return V_5 ;
}
V_5 = F_2 ( V_2 -> V_6 , V_15 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_6 ) ;
return V_5 ;
}
V_2 -> V_16 = V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_17 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_7 ) ;
return V_5 ;
}
if ( V_2 -> V_18 )
V_5 |= V_19 ;
else
V_5 &= ~ V_19 ;
V_5 = F_4 ( V_2 -> V_6 , V_17 ,
V_5 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_8 ) ;
return V_5 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
bool V_20 )
{
int V_5 ;
V_5 = F_1 ( V_2 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_17 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_7 ) ;
return V_5 ;
}
if ( V_20 )
V_5 |= V_21 ;
else
V_5 &= ~ V_21 ;
V_5 = F_4 ( V_2 -> V_6 , V_17 ,
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
if ( V_20 )
V_5 |= V_22 ;
else
V_5 &= ~ V_22 ;
V_5 = F_4 ( V_2 -> V_6 ,
V_7 , V_5 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_2 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_8 ( int V_23 , int V_24 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < F_9 ( V_26 ) ; ++ V_25 ) {
if ( V_26 [ V_25 ] . V_23 == V_23 &&
V_26 [ V_25 ] . V_24 == V_24 ) {
return V_26 [ V_25 ] . V_16 ;
}
}
return - V_27 ;
}
static int F_10 ( struct V_1 * V_2 , int V_23 , int V_24 )
{
int V_5 ;
int V_16 ;
V_16 = F_8 ( V_23 , V_24 ) ;
if ( V_16 < 0 )
return V_16 ;
V_5 = F_1 ( V_2 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_4 ( V_2 -> V_6 , V_15 ,
V_16 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_9 ) ;
return V_5 ;
}
V_2 -> V_16 = V_16 ;
if ( V_2 -> V_28 ) {
V_5 = F_1 ( V_2 , V_29 ) ;
if ( V_5 < 0 )
return V_5 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int * V_23 , int * V_24 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < F_9 ( V_26 ) ; ++ V_25 ) {
if ( V_26 [ V_25 ] . V_16 == V_2 -> V_16 ) {
* V_23 = V_26 [ V_25 ] . V_23 ;
* V_24 = V_26 [ V_25 ] . V_24 ;
return V_30 ;
}
}
return - V_27 ;
}
static int F_12 ( struct V_1 * V_2 , int V_31 )
{
T_1 V_32 = V_33 + V_31 * 2 ;
int V_5 ;
V_5 = F_13 ( V_2 -> V_6 , V_32 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 ,
L_10 , 'x' + V_31 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < F_9 ( V_34 ) ; ++ V_25 ) {
if ( V_34 [ V_25 ] . V_16 == V_2 -> V_16 )
return V_34 [ V_25 ] . V_35 ;
}
return V_36 ;
}
static int F_15 ( struct V_37 * V_38 ,
struct V_39 const * V_40 , int * V_23 ,
int * V_24 , long V_41 )
{
struct V_1 * V_2 = F_16 ( V_38 ) ;
int V_5 ;
switch ( V_41 ) {
case V_42 :
F_17 ( & V_2 -> V_43 ) ;
if ( F_18 ( V_38 ) )
V_5 = - V_44 ;
else {
int V_45 ;
V_5 = F_1 ( V_2 , V_29 ) ;
if ( V_5 < 0 ) {
F_19 ( & V_2 -> V_43 ) ;
return V_5 ;
}
++ V_2 -> V_28 ;
V_45 = F_14 ( V_2 ) ;
if ( V_45 < 20000 )
F_20 ( V_45 , 20000 ) ;
else
F_21 ( V_45 / 1000 ) ;
V_5 = F_12 ( V_2 , V_40 -> V_46 ) ;
if ( -- V_2 -> V_28 == 0 )
F_1 ( V_2 , V_9 ) ;
}
F_19 ( & V_2 -> V_43 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_23 = F_22 ( V_5 >> 4 , 11 ) ;
return V_47 ;
case V_48 :
* V_23 = 0 ;
* V_24 = 19163 ;
return V_30 ;
case V_49 :
F_17 ( & V_2 -> V_43 ) ;
V_5 = F_11 ( V_2 , V_23 , V_24 ) ;
F_19 ( & V_2 -> V_43 ) ;
return V_5 ;
default:
return - V_27 ;
}
}
static int F_23 ( struct V_37 * V_38 ,
struct V_39 const * V_40 , int V_23 ,
int V_24 , long V_41 )
{
struct V_1 * V_2 = F_16 ( V_38 ) ;
int V_5 ;
switch ( V_41 ) {
case V_49 :
F_17 ( & V_2 -> V_43 ) ;
V_5 = F_10 ( V_2 , V_23 , V_24 ) ;
F_19 ( & V_2 -> V_43 ) ;
break;
default:
V_5 = - V_27 ;
}
return V_5 ;
}
static int F_24 ( struct V_37 * V_38 ,
struct V_50 * V_51 )
{
struct V_1 * V_2 = F_16 ( V_38 ) ;
if ( V_2 -> V_51 != V_51 )
return - V_27 ;
return 0 ;
}
static T_2 F_25 ( int V_52 , void * V_53 )
{
struct V_54 * V_55 = V_53 ;
struct V_37 * V_38 = V_55 -> V_38 ;
struct V_1 * V_2 = F_16 ( V_38 ) ;
int V_56 , V_5 , V_25 = 0 ;
F_17 ( & V_2 -> V_43 ) ;
F_26 (bit, indio_dev->buffer->scan_mask,
indio_dev->masklength) {
V_5 = F_12 ( V_2 , V_56 ) ;
if ( V_5 < 0 ) {
F_19 ( & V_2 -> V_43 ) ;
goto V_57;
}
V_2 -> V_58 [ V_25 ++ ] = V_5 ;
}
F_19 ( & V_2 -> V_43 ) ;
F_27 ( V_38 , V_2 -> V_58 ,
V_55 -> V_59 ) ;
V_57:
F_28 ( V_38 -> V_51 ) ;
return V_60 ;
}
static int F_29 ( struct V_50 * V_51 )
{
struct V_37 * V_38 = F_30 ( V_51 ) ;
struct V_1 * V_2 = F_16 ( V_38 ) ;
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_61 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_8 , L_11 ) ;
return V_5 ;
}
return 0 ;
}
static int F_31 ( struct V_50 * V_51 ,
bool V_62 )
{
struct V_37 * V_38 = F_30 ( V_51 ) ;
struct V_1 * V_2 = F_16 ( V_38 ) ;
F_17 ( & V_2 -> V_43 ) ;
if ( V_62 ) {
F_7 ( V_2 , true ) ;
F_1 ( V_2 , V_29 ) ;
++ V_2 -> V_28 ;
} else {
if ( -- V_2 -> V_28 ) {
F_19 ( & V_2 -> V_43 ) ;
return 0 ;
}
F_7 ( V_2 , false ) ;
F_1 ( V_2 , V_9 ) ;
}
F_19 ( & V_2 -> V_43 ) ;
return 0 ;
}
static int F_32 ( struct V_63 * V_6 ,
struct V_1 * V_2 )
{
const struct V_64 * V_65 ;
struct V_66 * V_8 ;
struct V_67 * V_68 ;
int V_5 ;
if ( ! V_6 )
return - V_27 ;
V_8 = & V_6 -> V_8 ;
if ( ! F_33 ( V_8 ) )
return - V_69 ;
V_65 = F_34 ( V_8 -> V_70 -> V_71 , V_8 ) ;
if ( ! V_65 )
return - V_69 ;
V_68 = F_35 ( V_8 , L_12 , 0 ) ;
if ( F_36 ( V_68 ) ) {
F_3 ( V_8 , L_13 ) ;
return F_37 ( V_68 ) ;
}
V_5 = F_38 ( V_68 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_39 ( V_68 ) ;
F_6 ( V_8 , L_14 , F_40 ( V_68 ) , V_5 ) ;
return V_5 ;
}
static int F_41 ( struct V_63 * V_6 ,
const struct V_72 * V_65 )
{
struct V_1 * V_2 ;
struct V_37 * V_38 ;
struct V_50 * V_51 = NULL ;
struct V_73 * V_74 ;
int V_5 ;
V_38 = F_42 ( & V_6 -> V_8 , sizeof( * V_2 ) ) ;
if ( ! V_38 )
return - V_75 ;
V_2 = F_16 ( V_38 ) ;
F_43 ( V_6 , V_38 ) ;
V_2 -> V_6 = V_6 ;
V_74 = F_44 ( & V_6 -> V_8 ) ;
if ( V_74 )
V_2 -> V_18 = V_74 -> V_18 ;
else
V_2 -> V_18 = true ;
V_5 = F_5 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
F_45 ( & V_2 -> V_43 ) ;
V_38 -> V_8 . V_76 = & V_6 -> V_8 ;
V_38 -> V_77 = V_78 ;
V_38 -> V_79 = F_9 ( V_78 ) ;
V_38 -> V_80 = V_81 ;
V_38 -> V_82 = V_83 ;
V_38 -> V_84 = & V_85 ;
if ( V_6 -> V_52 < 0 )
V_6 -> V_52 = F_32 ( V_6 , V_2 ) ;
if ( V_6 -> V_52 >= 0 ) {
V_51 = F_46 ( L_15 , V_38 -> V_80 ,
V_38 -> V_65 ) ;
if ( ! V_51 )
return - V_75 ;
V_2 -> V_86 = true ;
V_5 = F_47 ( & V_6 -> V_8 , V_6 -> V_52 ,
V_87 ,
V_88 ,
V_89 ,
V_51 ) ;
if ( V_5 ) {
F_3 ( & V_6 -> V_8 , L_16 ) ;
goto V_90;
}
V_51 -> V_8 . V_76 = & V_6 -> V_8 ;
V_51 -> V_91 = & V_92 ;
F_48 ( V_51 , V_38 ) ;
V_2 -> V_51 = V_51 ;
V_38 -> V_51 = V_51 ;
F_49 ( V_38 -> V_51 ) ;
V_5 = F_50 ( V_51 ) ;
if ( V_5 )
goto V_90;
V_5 = F_51 ( V_38 ,
& V_93 ,
F_25 ,
NULL ) ;
if ( V_5 < 0 ) {
F_3 ( & V_6 -> V_8 ,
L_17 ) ;
goto V_94;
}
}
V_5 = F_52 ( & V_6 -> V_8 , V_38 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_6 -> V_8 , L_18 ) ;
goto V_95;
}
return 0 ;
V_95:
if ( V_2 -> V_86 )
F_53 ( V_38 ) ;
V_94:
if ( V_2 -> V_86 )
F_54 ( V_51 ) ;
V_90:
if ( V_2 -> V_86 )
F_55 ( V_51 ) ;
return V_5 ;
}
static int F_56 ( struct V_63 * V_6 )
{
struct V_37 * V_38 = F_57 ( V_6 ) ;
struct V_1 * V_2 = F_16 ( V_38 ) ;
if ( V_2 -> V_86 ) {
F_53 ( V_38 ) ;
F_54 ( V_2 -> V_51 ) ;
F_55 ( V_2 -> V_51 ) ;
}
F_17 ( & V_2 -> V_43 ) ;
F_1 ( V_2 , V_9 ) ;
F_19 ( & V_2 -> V_43 ) ;
return 0 ;
}
static int F_58 ( struct V_66 * V_8 )
{
struct V_37 * V_38 = F_57 ( F_59 ( V_8 ) ) ;
struct V_1 * V_2 = F_16 ( V_38 ) ;
F_17 ( & V_2 -> V_43 ) ;
F_1 ( V_2 , V_9 ) ;
F_19 ( & V_2 -> V_43 ) ;
return 0 ;
}
static int F_60 ( struct V_66 * V_8 )
{
struct V_37 * V_38 = F_57 ( F_59 ( V_8 ) ) ;
struct V_1 * V_2 = F_16 ( V_38 ) ;
F_17 ( & V_2 -> V_43 ) ;
if ( V_2 -> V_28 )
F_1 ( V_2 , V_29 ) ;
F_19 ( & V_2 -> V_43 ) ;
return 0 ;
}
