static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 ;
V_7 = V_2 -> V_7 ;
switch ( V_5 ) {
case V_8 :
F_2 ( V_7 , V_9 , 0x180 , 0 ) ;
break;
case V_10 :
F_2 ( V_7 , V_9 , 0x180 , 0x180 ) ;
break;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 ;
V_7 = V_2 -> V_7 ;
switch ( V_5 ) {
case V_8 :
F_2 ( V_7 , V_11 , 0x180 , 0 ) ;
break;
case V_10 :
F_2 ( V_7 , V_11 , 0x180 , 0x180 ) ;
break;
}
return 0 ;
}
static int F_4 ( struct V_6 * V_7 )
{
return F_5 ( V_7 , V_12 , 0 ) ;
}
static int F_6 ( struct V_13 * V_14 , unsigned int V_15 )
{
struct V_6 * V_7 ;
int V_16 , V_17 ;
V_7 = V_14 -> V_7 ;
switch ( V_15 & V_18 ) {
case V_19 :
V_17 = 0x100 ;
break;
case V_20 :
V_17 = 0 ;
break;
default:
return - V_21 ;
}
V_16 = 0 ;
switch ( V_15 & V_22 ) {
case V_23 :
V_16 |= 0x2 ;
break;
case V_24 :
break;
case V_25 :
V_16 |= 0x1 ;
break;
default:
return - V_21 ;
}
switch ( V_15 & V_26 ) {
case V_27 :
break;
case V_28 :
V_16 |= 0xc ;
break;
case V_29 :
V_16 |= 0x8 ;
break;
case V_30 :
V_16 |= 0x4 ;
break;
default:
return - V_21 ;
}
F_2 ( V_7 , V_31 , 0xf , V_16 ) ;
F_2 ( V_7 , V_32 , 0x100 , V_17 ) ;
return 0 ;
}
static int F_7 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
struct V_13 * V_14 )
{
struct V_6 * V_7 ;
struct V_37 * V_38 ;
int V_39 ;
int V_16 ;
int V_40 ;
int V_41 ;
V_7 = V_14 -> V_7 ;
V_38 = F_8 ( V_7 ) ;
V_16 = 0 ;
switch ( F_9 ( V_36 ) ) {
case V_42 :
break;
case V_43 :
V_16 |= 0x10 ;
break;
case V_44 :
V_16 |= 0x20 ;
break;
case V_45 :
V_16 |= 0x30 ;
break;
}
switch ( V_34 -> V_46 ) {
case V_47 :
V_39 = 0 ;
V_40 = 4 ;
break;
case V_48 :
V_39 = 2 ;
V_40 = 0 ;
break;
default:
return - V_21 ;
}
if ( F_10 ( V_7 , V_32 ) & 0x100 ) {
for (; V_39 < F_11 ( V_49 ) ; ++ V_39 ) {
V_41 = V_38 -> V_50 / F_12 ( V_36 ) ;
if ( V_41 == V_49 [ V_39 ] )
break;
}
if ( V_39 == F_11 ( V_49 ) ) {
F_13 ( V_7 -> V_51 ,
L_1 ,
V_38 -> V_50 , F_12 ( V_36 ) ) ;
return - V_21 ;
}
F_14 ( V_7 -> V_51 , L_2 , V_49 [ V_39 ] ) ;
F_2 ( V_7 , V_32 , 0x7 << V_40 ,
V_39 << V_40 ) ;
}
F_2 ( V_7 , V_31 , 0x30 , V_16 ) ;
return 0 ;
}
static int F_15 ( struct V_13 * V_14 , int V_52 )
{
struct V_6 * V_7 ;
V_7 = V_14 -> V_7 ;
return F_2 ( V_7 , V_53 , 0x10 ,
! ! V_52 << 4 ) ;
}
static int F_16 ( struct V_13 * V_14 ,
int V_54 , unsigned int V_55 , int V_56 )
{
struct V_6 * V_7 ;
struct V_37 * V_38 ;
V_7 = V_14 -> V_7 ;
V_38 = F_8 ( V_7 ) ;
V_38 -> V_50 = V_55 ;
return 0 ;
}
static void F_17 ( struct V_6 * V_7 )
{
int V_39 ;
T_1 * V_57 ;
if ( ! V_7 -> V_58 )
return;
V_7 -> V_59 = 0 ;
V_57 = V_7 -> V_60 ;
for ( V_39 = 0 ; V_39 < V_7 -> V_61 -> V_62 ; V_39 ++ ) {
if ( V_39 == V_12 || V_57 [ V_39 ] == V_63 [ V_39 ] )
continue;
F_5 ( V_7 , V_39 , V_57 [ V_39 ] ) ;
}
V_7 -> V_58 = 0 ;
}
static int F_18 ( struct V_6 * V_7 ,
enum V_64 V_65 )
{
int V_66 ;
struct V_37 * V_38 ;
V_38 = F_8 ( V_7 ) ;
switch ( V_65 ) {
case V_67 :
break;
case V_68 :
break;
case V_69 :
if ( V_7 -> V_70 . V_71 == V_72 ) {
V_66 = F_19 ( F_11 ( V_38 -> V_73 ) ,
V_38 -> V_73 ) ;
if ( V_66 ) {
F_13 ( V_7 -> V_51 ,
L_3 ,
V_66 ) ;
return V_66 ;
}
F_17 ( V_7 ) ;
F_5 ( V_7 , V_74 , 0 ) ;
}
break;
case V_72 :
F_5 ( V_7 , V_74 , 1 ) ;
F_20 ( F_11 ( V_38 -> V_73 ) ,
V_38 -> V_73 ) ;
break;
}
V_7 -> V_70 . V_71 = V_65 ;
return 0 ;
}
static int F_21 ( struct V_6 * V_7 )
{
F_18 ( V_7 , V_72 ) ;
return 0 ;
}
static int F_22 ( struct V_6 * V_7 )
{
F_18 ( V_7 , V_69 ) ;
return 0 ;
}
static int F_23 ( struct V_6 * V_7 )
{
struct V_37 * V_38 ;
int V_66 ;
int V_39 ;
V_38 = F_8 ( V_7 ) ;
V_38 -> V_7 = V_7 ;
V_66 = F_24 ( V_7 , 7 , 9 , V_38 -> V_75 ) ;
if ( V_66 < 0 ) {
F_13 ( V_7 -> V_51 , L_4 , V_66 ) ;
return V_66 ;
}
for ( V_39 = 0 ; V_39 < F_11 ( V_38 -> V_73 ) ; V_39 ++ )
V_38 -> V_73 [ V_39 ] . V_76 = V_77 [ V_39 ] ;
V_66 = F_25 ( V_7 -> V_51 , F_11 ( V_38 -> V_73 ) ,
V_38 -> V_73 ) ;
if ( V_66 ) {
F_13 ( V_7 -> V_51 , L_5 , V_66 ) ;
return V_66 ;
}
V_38 -> V_78 [ 0 ] . V_79 = V_80 ;
V_38 -> V_78 [ 1 ] . V_79 = V_81 ;
V_38 -> V_78 [ 2 ] . V_79 = V_82 ;
for ( V_39 = 0 ; V_39 < F_11 ( V_38 -> V_73 ) ; V_39 ++ ) {
V_66 = F_26 ( V_38 -> V_73 [ V_39 ] . V_83 ,
& V_38 -> V_78 [ V_39 ] ) ;
if ( V_66 ) {
F_13 ( V_7 -> V_51 ,
L_6 ,
V_66 ) ;
}
}
V_66 = F_19 ( F_11 ( V_38 -> V_73 ) ,
V_38 -> V_73 ) ;
if ( V_66 ) {
F_13 ( V_7 -> V_51 , L_3 , V_66 ) ;
goto V_84;
}
V_66 = F_4 ( V_7 ) ;
if ( V_66 < 0 ) {
F_13 ( V_7 -> V_51 , L_7 , V_66 ) ;
goto V_85;
}
F_18 ( V_7 , V_69 ) ;
F_2 ( V_7 , V_86 , 0x100 , 0x100 ) ;
F_2 ( V_7 , V_87 , 0x100 , 0x100 ) ;
F_2 ( V_7 , V_88 , 0x100 , 0x100 ) ;
F_2 ( V_7 , V_89 , 0x100 , 0x100 ) ;
F_2 ( V_7 , V_90 , 0x100 , 0x100 ) ;
F_2 ( V_7 , V_91 , 0x100 , 0x100 ) ;
F_2 ( V_7 , V_92 , 0x100 , 0x100 ) ;
F_2 ( V_7 , V_93 , 0x100 , 0x100 ) ;
F_2 ( V_7 , V_94 , 0x100 , 0x100 ) ;
F_2 ( V_7 , V_95 , 0x100 , 0x100 ) ;
F_2 ( V_7 , V_53 , 0x10 , 0x10 ) ;
F_27 ( V_7 , V_96 ,
F_11 ( V_96 ) ) ;
F_28 ( & V_7 -> V_70 , V_97 ,
F_11 ( V_97 ) ) ;
F_29 ( & V_7 -> V_70 , V_98 ,
F_11 ( V_98 ) ) ;
return 0 ;
V_85:
F_20 ( F_11 ( V_38 -> V_73 ) , V_38 -> V_73 ) ;
V_84:
F_30 ( F_11 ( V_38 -> V_73 ) , V_38 -> V_73 ) ;
return V_66 ;
}
static int F_31 ( struct V_6 * V_7 )
{
struct V_37 * V_38 ;
int V_39 ;
V_38 = F_8 ( V_7 ) ;
F_18 ( V_7 , V_72 ) ;
for ( V_39 = 0 ; V_39 < F_11 ( V_38 -> V_73 ) ; ++ V_39 )
F_32 ( V_38 -> V_73 [ V_39 ] . V_83 ,
& V_38 -> V_78 [ V_39 ] ) ;
F_30 ( F_11 ( V_38 -> V_73 ) , V_38 -> V_73 ) ;
return 0 ;
}
static int T_2 F_33 ( struct V_99 * V_100 )
{
struct V_37 * V_38 ;
int V_66 ;
V_38 = F_34 ( & V_100 -> V_51 , sizeof( struct V_37 ) ,
V_101 ) ;
if ( ! V_38 )
return - V_102 ;
V_38 -> V_75 = V_103 ;
F_35 ( V_100 , V_38 ) ;
V_66 = F_36 ( & V_100 -> V_51 ,
& V_104 , & V_105 , 1 ) ;
return V_66 ;
}
static int T_3 F_37 ( struct V_99 * V_100 )
{
F_38 ( & V_100 -> V_51 ) ;
return 0 ;
}
static int T_4 F_39 ( void )
{
int V_66 = 0 ;
V_66 = F_40 ( & V_106 ) ;
if ( V_66 ) {
F_41 ( V_107 L_8 ,
V_66 ) ;
}
return V_66 ;
}
static void T_5 F_42 ( void )
{
F_43 ( & V_106 ) ;
}
