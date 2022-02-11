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
case V_45 :
break;
case V_46 :
V_19 |= 0x10 ;
break;
case V_47 :
V_19 |= 0x20 ;
break;
case V_48 :
V_19 |= 0x30 ;
break;
}
switch ( V_37 -> V_49 ) {
case V_50 :
V_42 = 0 ;
V_43 = 4 ;
break;
case V_51 :
V_42 = 2 ;
V_43 = 0 ;
break;
default:
return - V_24 ;
}
if ( F_11 ( V_11 , V_35 ) & 0x100 ) {
for (; V_42 < F_12 ( V_52 ) ; ++ V_42 ) {
V_44 = V_41 -> V_53 / F_13 ( V_39 ) ;
if ( V_44 == V_52 [ V_42 ] )
break;
}
if ( V_42 == F_12 ( V_52 ) ) {
F_14 ( V_11 -> V_2 ,
L_1 ,
V_41 -> V_53 , F_13 ( V_39 ) ) ;
return - V_24 ;
}
F_15 ( V_11 -> V_2 , L_2 , V_52 [ V_42 ] ) ;
F_3 ( V_11 , V_35 , 0x7 << V_43 ,
V_42 << V_43 ) ;
}
F_3 ( V_11 , V_34 , 0x30 , V_19 ) ;
return 0 ;
}
static int F_16 ( struct V_16 * V_17 , int V_54 )
{
struct V_10 * V_11 ;
V_11 = V_17 -> V_11 ;
return F_3 ( V_11 , V_55 , 0x10 ,
! ! V_54 << 4 ) ;
}
static int F_17 ( struct V_16 * V_17 ,
int V_56 , unsigned int V_57 , int V_58 )
{
struct V_10 * V_11 ;
struct V_40 * V_41 ;
V_11 = V_17 -> V_11 ;
V_41 = F_9 ( V_11 ) ;
V_41 -> V_53 = V_57 ;
return 0 ;
}
static int F_18 ( struct V_10 * V_11 ,
enum V_59 V_60 )
{
int V_61 ;
struct V_40 * V_41 ;
V_41 = F_9 ( V_11 ) ;
switch ( V_60 ) {
case V_62 :
break;
case V_63 :
break;
case V_64 :
if ( V_11 -> V_65 . V_66 == V_67 ) {
V_61 = F_19 ( F_12 ( V_41 -> V_68 ) ,
V_41 -> V_68 ) ;
if ( V_61 ) {
F_14 ( V_11 -> V_2 ,
L_3 ,
V_61 ) ;
return V_61 ;
}
F_20 ( V_41 -> V_69 ) ;
F_6 ( V_11 , V_70 , 0 ) ;
}
break;
case V_67 :
F_6 ( V_11 , V_70 , 1 ) ;
F_21 ( F_12 ( V_41 -> V_68 ) ,
V_41 -> V_68 ) ;
break;
}
V_11 -> V_65 . V_66 = V_60 ;
return 0 ;
}
static int F_22 ( struct V_10 * V_11 )
{
struct V_40 * V_41 ;
int V_61 ;
V_41 = F_9 ( V_11 ) ;
V_41 -> V_11 = V_11 ;
V_61 = F_23 ( V_11 , 7 , 9 , V_71 ) ;
if ( V_61 < 0 ) {
F_14 ( V_11 -> V_2 , L_4 , V_61 ) ;
return V_61 ;
}
V_61 = F_19 ( F_12 ( V_41 -> V_68 ) ,
V_41 -> V_68 ) ;
if ( V_61 ) {
F_14 ( V_11 -> V_2 , L_3 , V_61 ) ;
return V_61 ;
}
V_61 = F_5 ( V_11 ) ;
if ( V_61 < 0 ) {
F_14 ( V_11 -> V_2 , L_5 , V_61 ) ;
goto V_72;
}
F_3 ( V_11 , V_73 , 0x100 , 0x100 ) ;
F_3 ( V_11 , V_74 , 0x100 , 0x100 ) ;
F_3 ( V_11 , V_75 , 0x100 , 0x100 ) ;
F_3 ( V_11 , V_76 , 0x100 , 0x100 ) ;
F_3 ( V_11 , V_77 , 0x100 , 0x100 ) ;
F_3 ( V_11 , V_78 , 0x100 , 0x100 ) ;
F_3 ( V_11 , V_79 , 0x100 , 0x100 ) ;
F_3 ( V_11 , V_80 , 0x100 , 0x100 ) ;
F_3 ( V_11 , V_81 , 0x100 , 0x100 ) ;
F_3 ( V_11 , V_82 , 0x100 , 0x100 ) ;
F_3 ( V_11 , V_55 , 0x10 , 0x10 ) ;
V_72:
F_21 ( F_12 ( V_41 -> V_68 ) , V_41 -> V_68 ) ;
return V_61 ;
}
static int F_24 ( struct V_83 * V_84 )
{
struct V_40 * V_41 ;
int V_61 , V_42 ;
V_41 = F_25 ( & V_84 -> V_2 , sizeof( struct V_40 ) ,
V_85 ) ;
if ( ! V_41 )
return - V_86 ;
for ( V_42 = 0 ; V_42 < F_12 ( V_41 -> V_68 ) ; V_42 ++ )
V_41 -> V_68 [ V_42 ] . V_87 = V_88 [ V_42 ] ;
V_61 = F_26 ( & V_84 -> V_2 , F_12 ( V_41 -> V_68 ) ,
V_41 -> V_68 ) ;
if ( V_61 ) {
F_14 ( & V_84 -> V_2 , L_6 , V_61 ) ;
return V_61 ;
}
V_41 -> V_89 [ 0 ] . V_90 = V_91 ;
V_41 -> V_89 [ 1 ] . V_90 = V_92 ;
V_41 -> V_89 [ 2 ] . V_90 = V_93 ;
for ( V_42 = 0 ; V_42 < F_12 ( V_41 -> V_68 ) ; V_42 ++ ) {
V_61 = F_27 ( V_41 -> V_68 [ V_42 ] . V_94 ,
& V_41 -> V_89 [ V_42 ] ) ;
if ( V_61 ) {
F_14 ( & V_84 -> V_2 ,
L_7 ,
V_61 ) ;
}
}
V_41 -> V_69 = F_28 ( V_84 , & V_95 ) ;
if ( F_29 ( V_41 -> V_69 ) )
return F_30 ( V_41 -> V_69 ) ;
F_31 ( V_84 , V_41 ) ;
V_61 = F_32 ( & V_84 -> V_2 ,
& V_96 , & V_97 , 1 ) ;
return V_61 ;
}
static int F_33 ( struct V_83 * V_84 )
{
struct V_40 * V_41 = F_34 ( V_84 ) ;
int V_42 ;
for ( V_42 = 0 ; V_42 < F_12 ( V_41 -> V_68 ) ; ++ V_42 )
F_35 ( V_41 -> V_68 [ V_42 ] . V_94 ,
& V_41 -> V_89 [ V_42 ] ) ;
F_36 ( & V_84 -> V_2 ) ;
return 0 ;
}
