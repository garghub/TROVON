static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
return true ;
default:
return false ;
}
}
static int F_2 ( struct V_5 * V_6 ,
struct V_7 * V_8 , int V_9 )
{
struct V_10 * V_11 = F_3 ( V_6 -> V_12 ) ;
switch ( V_9 ) {
case V_13 :
F_4 ( V_11 , V_14 , 0x180 , 0 ) ;
break;
case V_15 :
F_4 ( V_11 , V_14 , 0x180 , 0x180 ) ;
break;
}
return 0 ;
}
static int F_5 ( struct V_5 * V_6 ,
struct V_7 * V_8 , int V_9 )
{
struct V_10 * V_11 = F_3 ( V_6 -> V_12 ) ;
switch ( V_9 ) {
case V_13 :
F_4 ( V_11 , V_16 , 0x180 , 0 ) ;
break;
case V_15 :
F_4 ( V_11 , V_16 , 0x180 , 0x180 ) ;
break;
}
return 0 ;
}
static int F_6 ( struct V_10 * V_11 )
{
return F_7 ( V_11 , V_4 , 0 ) ;
}
static int F_8 ( struct V_17 * V_18 , unsigned int V_19 )
{
struct V_10 * V_11 ;
int V_20 , V_21 ;
V_11 = V_18 -> V_11 ;
switch ( V_19 & V_22 ) {
case V_23 :
V_21 = 0x100 ;
break;
case V_24 :
V_21 = 0 ;
break;
default:
return - V_25 ;
}
V_20 = 0 ;
switch ( V_19 & V_26 ) {
case V_27 :
V_20 |= 0x2 ;
break;
case V_28 :
break;
case V_29 :
V_20 |= 0x1 ;
break;
default:
return - V_25 ;
}
switch ( V_19 & V_30 ) {
case V_31 :
break;
case V_32 :
V_20 |= 0xc ;
break;
case V_33 :
V_20 |= 0x8 ;
break;
case V_34 :
V_20 |= 0x4 ;
break;
default:
return - V_25 ;
}
F_4 ( V_11 , V_35 , 0xf , V_20 ) ;
F_4 ( V_11 , V_36 , 0x100 , V_21 ) ;
return 0 ;
}
static int F_9 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_17 * V_18 )
{
struct V_10 * V_11 ;
struct V_41 * V_42 ;
int V_43 ;
int V_20 ;
int V_44 ;
int V_45 ;
V_11 = V_18 -> V_11 ;
V_42 = F_10 ( V_11 ) ;
V_20 = 0 ;
switch ( F_11 ( V_40 ) ) {
case 16 :
break;
case 20 :
V_20 |= 0x10 ;
break;
case 24 :
V_20 |= 0x20 ;
break;
case 32 :
V_20 |= 0x30 ;
break;
}
switch ( V_38 -> V_46 ) {
case V_47 :
V_43 = 0 ;
V_44 = 4 ;
break;
case V_48 :
V_43 = 2 ;
V_44 = 0 ;
break;
default:
return - V_25 ;
}
if ( F_12 ( V_11 , V_36 ) & 0x100 ) {
for (; V_43 < F_13 ( V_49 ) ; ++ V_43 ) {
V_45 = V_42 -> V_50 / F_14 ( V_40 ) ;
if ( V_45 == V_49 [ V_43 ] )
break;
}
if ( V_43 == F_13 ( V_49 ) ) {
F_15 ( V_11 -> V_2 ,
L_1 ,
V_42 -> V_50 , F_14 ( V_40 ) ) ;
return - V_25 ;
}
F_16 ( V_11 -> V_2 , L_2 , V_49 [ V_43 ] ) ;
F_4 ( V_11 , V_36 , 0x7 << V_44 ,
V_43 << V_44 ) ;
}
F_4 ( V_11 , V_35 , 0x30 , V_20 ) ;
return 0 ;
}
static int F_17 ( struct V_17 * V_18 , int V_51 )
{
struct V_10 * V_11 ;
V_11 = V_18 -> V_11 ;
return F_4 ( V_11 , V_52 , 0x10 ,
! ! V_51 << 4 ) ;
}
static int F_18 ( struct V_17 * V_18 ,
int V_53 , unsigned int V_54 , int V_55 )
{
struct V_10 * V_11 ;
struct V_41 * V_42 ;
V_11 = V_18 -> V_11 ;
V_42 = F_10 ( V_11 ) ;
V_42 -> V_50 = V_54 ;
return 0 ;
}
static int F_19 ( struct V_10 * V_11 ,
enum V_56 V_57 )
{
int V_58 ;
struct V_41 * V_42 ;
V_42 = F_10 ( V_11 ) ;
switch ( V_57 ) {
case V_59 :
break;
case V_60 :
break;
case V_61 :
if ( V_11 -> V_12 . V_62 == V_63 ) {
V_58 = F_20 ( F_13 ( V_42 -> V_64 ) ,
V_42 -> V_64 ) ;
if ( V_58 ) {
F_15 ( V_11 -> V_2 ,
L_3 ,
V_58 ) ;
return V_58 ;
}
F_21 ( V_42 -> V_65 ) ;
F_7 ( V_11 , V_66 , 0 ) ;
}
break;
case V_63 :
F_7 ( V_11 , V_66 , 1 ) ;
F_22 ( F_13 ( V_42 -> V_64 ) ,
V_42 -> V_64 ) ;
break;
}
V_11 -> V_12 . V_62 = V_57 ;
return 0 ;
}
static int F_23 ( struct V_10 * V_11 )
{
struct V_41 * V_42 ;
int V_58 ;
V_42 = F_10 ( V_11 ) ;
V_42 -> V_11 = V_11 ;
V_58 = F_20 ( F_13 ( V_42 -> V_64 ) ,
V_42 -> V_64 ) ;
if ( V_58 ) {
F_15 ( V_11 -> V_2 , L_3 , V_58 ) ;
return V_58 ;
}
V_58 = F_6 ( V_11 ) ;
if ( V_58 < 0 ) {
F_15 ( V_11 -> V_2 , L_4 , V_58 ) ;
goto V_67;
}
F_4 ( V_11 , V_68 , 0x100 , 0x100 ) ;
F_4 ( V_11 , V_69 , 0x100 , 0x100 ) ;
F_4 ( V_11 , V_70 , 0x100 , 0x100 ) ;
F_4 ( V_11 , V_71 , 0x100 , 0x100 ) ;
F_4 ( V_11 , V_72 , 0x100 , 0x100 ) ;
F_4 ( V_11 , V_73 , 0x100 , 0x100 ) ;
F_4 ( V_11 , V_74 , 0x100 , 0x100 ) ;
F_4 ( V_11 , V_75 , 0x100 , 0x100 ) ;
F_4 ( V_11 , V_76 , 0x100 , 0x100 ) ;
F_4 ( V_11 , V_77 , 0x100 , 0x100 ) ;
F_4 ( V_11 , V_52 , 0x10 , 0x10 ) ;
V_67:
F_22 ( F_13 ( V_42 -> V_64 ) , V_42 -> V_64 ) ;
return V_58 ;
}
static int F_24 ( struct V_78 * V_79 )
{
struct V_41 * V_42 ;
int V_58 , V_43 ;
V_42 = F_25 ( & V_79 -> V_2 , sizeof( struct V_41 ) ,
V_80 ) ;
if ( ! V_42 )
return - V_81 ;
for ( V_43 = 0 ; V_43 < F_13 ( V_42 -> V_64 ) ; V_43 ++ )
V_42 -> V_64 [ V_43 ] . V_82 = V_83 [ V_43 ] ;
V_58 = F_26 ( & V_79 -> V_2 , F_13 ( V_42 -> V_64 ) ,
V_42 -> V_64 ) ;
if ( V_58 ) {
F_15 ( & V_79 -> V_2 , L_5 , V_58 ) ;
return V_58 ;
}
V_42 -> V_84 [ 0 ] . V_85 = V_86 ;
V_42 -> V_84 [ 1 ] . V_85 = V_87 ;
V_42 -> V_84 [ 2 ] . V_85 = V_88 ;
for ( V_43 = 0 ; V_43 < F_13 ( V_42 -> V_64 ) ; V_43 ++ ) {
V_58 = F_27 ( V_42 -> V_64 [ V_43 ] . V_89 ,
& V_42 -> V_84 [ V_43 ] ) ;
if ( V_58 ) {
F_15 ( & V_79 -> V_2 ,
L_6 ,
V_58 ) ;
}
}
V_42 -> V_65 = F_28 ( V_79 , & V_90 ) ;
if ( F_29 ( V_42 -> V_65 ) )
return F_30 ( V_42 -> V_65 ) ;
F_31 ( V_79 , V_42 ) ;
V_58 = F_32 ( & V_79 -> V_2 ,
& V_91 , & V_92 , 1 ) ;
return V_58 ;
}
static int F_33 ( struct V_78 * V_79 )
{
struct V_41 * V_42 = F_34 ( V_79 ) ;
int V_43 ;
for ( V_43 = 0 ; V_43 < F_13 ( V_42 -> V_64 ) ; ++ V_43 )
F_35 ( V_42 -> V_64 [ V_43 ] . V_89 ,
& V_42 -> V_84 [ V_43 ] ) ;
F_36 ( & V_79 -> V_2 ) ;
return 0 ;
}
