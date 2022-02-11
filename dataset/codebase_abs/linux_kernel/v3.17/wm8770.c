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
struct V_10 * V_11 ;
V_11 = V_6 -> V_11 ;
switch ( V_9 ) {
case V_12 :
F_3 ( V_11 , V_13 , 0x180 , 0 ) ;
break;
case V_14 :
F_3 ( V_11 , V_13 , 0x180 , 0x180 ) ;
break;
}
return 0 ;
}
static int F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 , int V_9 )
{
struct V_10 * V_11 ;
V_11 = V_6 -> V_11 ;
switch ( V_9 ) {
case V_12 :
F_3 ( V_11 , V_15 , 0x180 , 0 ) ;
break;
case V_14 :
F_3 ( V_11 , V_15 , 0x180 , 0x180 ) ;
break;
}
return 0 ;
}
static int F_5 ( struct V_10 * V_11 )
{
return F_6 ( V_11 , V_4 , 0 ) ;
}
static int F_7 ( struct V_16 * V_17 , unsigned int V_18 )
{
struct V_10 * V_11 ;
int V_19 , V_20 ;
V_11 = V_17 -> V_11 ;
switch ( V_18 & V_21 ) {
case V_22 :
V_20 = 0x100 ;
break;
case V_23 :
V_20 = 0 ;
break;
default:
return - V_24 ;
}
V_19 = 0 ;
switch ( V_18 & V_25 ) {
case V_26 :
V_19 |= 0x2 ;
break;
case V_27 :
break;
case V_28 :
V_19 |= 0x1 ;
break;
default:
return - V_24 ;
}
switch ( V_18 & V_29 ) {
case V_30 :
break;
case V_31 :
V_19 |= 0xc ;
break;
case V_32 :
V_19 |= 0x8 ;
break;
case V_33 :
V_19 |= 0x4 ;
break;
default:
return - V_24 ;
}
F_3 ( V_11 , V_34 , 0xf , V_19 ) ;
F_3 ( V_11 , V_35 , 0x100 , V_20 ) ;
return 0 ;
}
static int F_8 ( struct V_36 * V_37 ,
struct V_38 * V_39 ,
struct V_16 * V_17 )
{
struct V_10 * V_11 ;
struct V_40 * V_41 ;
int V_42 ;
int V_19 ;
int V_43 ;
int V_44 ;
V_11 = V_17 -> V_11 ;
V_41 = F_9 ( V_11 ) ;
V_19 = 0 ;
switch ( F_10 ( V_39 ) ) {
case 16 :
break;
case 20 :
V_19 |= 0x10 ;
break;
case 24 :
V_19 |= 0x20 ;
break;
case 32 :
V_19 |= 0x30 ;
break;
}
switch ( V_37 -> V_45 ) {
case V_46 :
V_42 = 0 ;
V_43 = 4 ;
break;
case V_47 :
V_42 = 2 ;
V_43 = 0 ;
break;
default:
return - V_24 ;
}
if ( F_11 ( V_11 , V_35 ) & 0x100 ) {
for (; V_42 < F_12 ( V_48 ) ; ++ V_42 ) {
V_44 = V_41 -> V_49 / F_13 ( V_39 ) ;
if ( V_44 == V_48 [ V_42 ] )
break;
}
if ( V_42 == F_12 ( V_48 ) ) {
F_14 ( V_11 -> V_2 ,
L_1 ,
V_41 -> V_49 , F_13 ( V_39 ) ) ;
return - V_24 ;
}
F_15 ( V_11 -> V_2 , L_2 , V_48 [ V_42 ] ) ;
F_3 ( V_11 , V_35 , 0x7 << V_43 ,
V_42 << V_43 ) ;
}
F_3 ( V_11 , V_34 , 0x30 , V_19 ) ;
return 0 ;
}
static int F_16 ( struct V_16 * V_17 , int V_50 )
{
struct V_10 * V_11 ;
V_11 = V_17 -> V_11 ;
return F_3 ( V_11 , V_51 , 0x10 ,
! ! V_50 << 4 ) ;
}
static int F_17 ( struct V_16 * V_17 ,
int V_52 , unsigned int V_53 , int V_54 )
{
struct V_10 * V_11 ;
struct V_40 * V_41 ;
V_11 = V_17 -> V_11 ;
V_41 = F_9 ( V_11 ) ;
V_41 -> V_49 = V_53 ;
return 0 ;
}
static int F_18 ( struct V_10 * V_11 ,
enum V_55 V_56 )
{
int V_57 ;
struct V_40 * V_41 ;
V_41 = F_9 ( V_11 ) ;
switch ( V_56 ) {
case V_58 :
break;
case V_59 :
break;
case V_60 :
if ( V_11 -> V_61 . V_62 == V_63 ) {
V_57 = F_19 ( F_12 ( V_41 -> V_64 ) ,
V_41 -> V_64 ) ;
if ( V_57 ) {
F_14 ( V_11 -> V_2 ,
L_3 ,
V_57 ) ;
return V_57 ;
}
F_20 ( V_41 -> V_65 ) ;
F_6 ( V_11 , V_66 , 0 ) ;
}
break;
case V_63 :
F_6 ( V_11 , V_66 , 1 ) ;
F_21 ( F_12 ( V_41 -> V_64 ) ,
V_41 -> V_64 ) ;
break;
}
V_11 -> V_61 . V_62 = V_56 ;
return 0 ;
}
static int F_22 ( struct V_10 * V_11 )
{
struct V_40 * V_41 ;
int V_57 ;
V_41 = F_9 ( V_11 ) ;
V_41 -> V_11 = V_11 ;
V_57 = F_19 ( F_12 ( V_41 -> V_64 ) ,
V_41 -> V_64 ) ;
if ( V_57 ) {
F_14 ( V_11 -> V_2 , L_3 , V_57 ) ;
return V_57 ;
}
V_57 = F_5 ( V_11 ) ;
if ( V_57 < 0 ) {
F_14 ( V_11 -> V_2 , L_4 , V_57 ) ;
goto V_67;
}
F_3 ( V_11 , V_68 , 0x100 , 0x100 ) ;
F_3 ( V_11 , V_69 , 0x100 , 0x100 ) ;
F_3 ( V_11 , V_70 , 0x100 , 0x100 ) ;
F_3 ( V_11 , V_71 , 0x100 , 0x100 ) ;
F_3 ( V_11 , V_72 , 0x100 , 0x100 ) ;
F_3 ( V_11 , V_73 , 0x100 , 0x100 ) ;
F_3 ( V_11 , V_74 , 0x100 , 0x100 ) ;
F_3 ( V_11 , V_75 , 0x100 , 0x100 ) ;
F_3 ( V_11 , V_76 , 0x100 , 0x100 ) ;
F_3 ( V_11 , V_77 , 0x100 , 0x100 ) ;
F_3 ( V_11 , V_51 , 0x10 , 0x10 ) ;
V_67:
F_21 ( F_12 ( V_41 -> V_64 ) , V_41 -> V_64 ) ;
return V_57 ;
}
static int F_23 ( struct V_78 * V_79 )
{
struct V_40 * V_41 ;
int V_57 , V_42 ;
V_41 = F_24 ( & V_79 -> V_2 , sizeof( struct V_40 ) ,
V_80 ) ;
if ( ! V_41 )
return - V_81 ;
for ( V_42 = 0 ; V_42 < F_12 ( V_41 -> V_64 ) ; V_42 ++ )
V_41 -> V_64 [ V_42 ] . V_82 = V_83 [ V_42 ] ;
V_57 = F_25 ( & V_79 -> V_2 , F_12 ( V_41 -> V_64 ) ,
V_41 -> V_64 ) ;
if ( V_57 ) {
F_14 ( & V_79 -> V_2 , L_5 , V_57 ) ;
return V_57 ;
}
V_41 -> V_84 [ 0 ] . V_85 = V_86 ;
V_41 -> V_84 [ 1 ] . V_85 = V_87 ;
V_41 -> V_84 [ 2 ] . V_85 = V_88 ;
for ( V_42 = 0 ; V_42 < F_12 ( V_41 -> V_64 ) ; V_42 ++ ) {
V_57 = F_26 ( V_41 -> V_64 [ V_42 ] . V_89 ,
& V_41 -> V_84 [ V_42 ] ) ;
if ( V_57 ) {
F_14 ( & V_79 -> V_2 ,
L_6 ,
V_57 ) ;
}
}
V_41 -> V_65 = F_27 ( V_79 , & V_90 ) ;
if ( F_28 ( V_41 -> V_65 ) )
return F_29 ( V_41 -> V_65 ) ;
F_30 ( V_79 , V_41 ) ;
V_57 = F_31 ( & V_79 -> V_2 ,
& V_91 , & V_92 , 1 ) ;
return V_57 ;
}
static int F_32 ( struct V_78 * V_79 )
{
struct V_40 * V_41 = F_33 ( V_79 ) ;
int V_42 ;
for ( V_42 = 0 ; V_42 < F_12 ( V_41 -> V_64 ) ; ++ V_42 )
F_34 ( V_41 -> V_64 [ V_42 ] . V_89 ,
& V_41 -> V_84 [ V_42 ] ) ;
F_35 ( & V_79 -> V_2 ) ;
return 0 ;
}
