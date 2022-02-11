void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 ,
T_2 V_5 , T_2 V_6 )
{
T_3 V_7 ;
F_2 ( V_2 , V_3 , V_4 ) ;
V_7 = ( F_3 ( V_2 , V_3 + 1 ) & V_5 ) | V_6 ;
F_4 ( V_2 , V_3 , V_4 , V_7 ) ;
}
T_2 F_5 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 )
{
T_2 V_8 ;
F_2 ( V_2 , V_3 , V_4 ) ;
V_8 = F_3 ( V_2 , V_3 + 1 ) ;
return V_8 ;
}
T_2 F_6 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , T_2 V_5 )
{
T_2 V_8 ;
F_2 ( V_2 , V_3 , V_4 ) ;
V_8 = F_3 ( V_2 , V_3 + 1 ) & V_5 ;
return V_8 ;
}
static int F_7 ( struct V_9 * V_10 , bool * V_11 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
T_1 V_13 , V_14 ;
F_8 ( V_2 ) ;
if ( V_10 -> V_15 -> V_16 == V_17 ) {
V_2 -> V_18 = V_19 ;
F_9 ( L_1 ) ;
} else {
if ( V_10 -> V_15 -> V_20 >= 0x30 ) {
V_2 -> V_18 = V_21 ;
F_9 ( L_2 ) ;
} else if ( V_10 -> V_15 -> V_20 >= 0x20 ) {
V_2 -> V_18 = V_22 ;
F_9 ( L_3 ) ;
} else if ( V_10 -> V_15 -> V_20 >= 0x10 ) {
T_1 V_13 ;
F_10 ( V_2 , 0xf004 , 0x1e6e0000 ) ;
F_10 ( V_2 , 0xf000 , 0x1 ) ;
V_13 = F_11 ( V_2 , 0x1207c ) ;
switch ( V_13 & 0x0300 ) {
case 0x0200 :
V_2 -> V_18 = V_19 ;
F_9 ( L_4 ) ;
break;
case 0x0100 :
V_2 -> V_18 = V_23 ;
F_9 ( L_5 ) ;
break;
case 0x0000 :
V_2 -> V_18 = V_24 ;
F_9 ( L_6 ) ;
break;
default:
V_2 -> V_18 = V_25 ;
F_9 ( L_7 ) ;
break;
}
V_2 -> V_26 = false ;
} else {
V_2 -> V_18 = V_27 ;
F_9 ( L_8 ) ;
}
}
if ( ! F_12 ( V_10 ) ) {
F_13 ( V_10 ) ;
F_14 ( V_10 ) ;
F_9 ( L_9 ) ;
* V_11 = true ;
} else
* V_11 = false ;
V_2 -> V_28 = true ;
V_13 = F_11 ( V_2 , 0xf004 ) ;
if ( V_13 != 0xFFFFFFFF )
V_2 -> V_28 = false ;
switch ( V_2 -> V_18 ) {
case V_29 :
V_2 -> V_30 = true ;
break;
case V_27 :
V_2 -> V_30 = false ;
break;
default:
V_14 = F_6 ( V_2 , V_31 , 0xd0 , 0xff ) ;
if ( ! ( V_14 & 0x80 ) )
V_2 -> V_30 = true ;
else if ( V_14 & 0x01 )
V_2 -> V_30 = true ;
else {
V_2 -> V_30 = false ;
if ( V_2 -> V_28 == false ) {
F_10 ( V_2 , 0xf004 , 0x1e6e0000 ) ;
F_10 ( V_2 , 0xf000 , 0x1 ) ;
V_13 = F_11 ( V_2 , 0x1207c ) ;
V_13 &= 0x300 ;
if ( V_2 -> V_18 == V_22 && V_13 == 0x0 )
V_2 -> V_30 = true ;
if ( V_2 -> V_18 == V_21 && V_13 == 0x100 )
V_2 -> V_30 = true ;
}
}
break;
}
V_2 -> V_32 = V_33 ;
if ( ! * V_11 ) {
V_14 = F_6 ( V_2 , V_31 , 0xa3 , 0xff ) ;
if ( V_14 & 0x80 )
V_2 -> V_32 = V_34 ;
}
if ( ( V_2 -> V_18 == V_22 ) || ( V_2 -> V_18 == V_21 ) ) {
V_14 = F_6 ( V_2 , V_31 , 0xd1 , 0xff ) ;
switch ( V_14 ) {
case 0x04 :
V_2 -> V_32 = V_34 ;
break;
case 0x08 :
V_2 -> V_35 = F_15 ( 32 * 1024 , V_36 ) ;
if ( V_2 -> V_35 ) {
if ( F_16 ( V_10 , V_2 -> V_35 , 32 * 1024 ) ) {
F_17 ( V_2 -> V_35 ) ;
V_2 -> V_35 = NULL ;
}
}
case 0x0c :
V_2 -> V_32 = V_37 ;
}
}
switch( V_2 -> V_32 ) {
case V_34 :
F_9 ( L_10 ) ;
break;
case V_37 :
F_9 ( L_11 ) ;
break;
default:
F_9 ( L_12 ) ;
}
return 0 ;
}
static int F_18 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
T_1 V_13 , V_38 ;
T_1 V_39 , V_40 , div , V_41 ;
if ( V_2 -> V_28 )
{
V_2 -> V_42 = 16 ;
V_2 -> V_43 = V_44 ;
V_2 -> V_45 = 396 ;
}
else
{
F_10 ( V_2 , 0xf004 , 0x1e6e0000 ) ;
F_10 ( V_2 , 0xf000 , 0x1 ) ;
V_13 = F_11 ( V_2 , 0x10004 ) ;
if ( V_13 & 0x40 )
V_2 -> V_42 = 16 ;
else
V_2 -> V_42 = 32 ;
if ( V_2 -> V_18 == V_22 || V_2 -> V_18 == V_21 ) {
switch ( V_13 & 0x03 ) {
case 0 :
V_2 -> V_43 = V_46 ;
break;
default:
case 1 :
V_2 -> V_43 = V_44 ;
break;
case 2 :
V_2 -> V_43 = V_47 ;
break;
case 3 :
V_2 -> V_43 = V_48 ;
break;
}
} else {
switch ( V_13 & 0x0c ) {
case 0 :
case 4 :
V_2 -> V_43 = V_46 ;
break;
case 8 :
if ( V_13 & 0x40 )
V_2 -> V_43 = V_44 ;
else
V_2 -> V_43 = V_49 ;
break;
case 0xc :
V_2 -> V_43 = V_50 ;
break;
}
}
V_13 = F_11 ( V_2 , 0x10120 ) ;
V_38 = F_11 ( V_2 , 0x10170 ) ;
if ( V_38 & 0x2000 )
V_41 = 14318 ;
else
V_41 = 12000 ;
V_39 = V_13 & 0x1f ;
V_40 = ( V_13 & 0x3fe0 ) >> 5 ;
V_13 = ( V_13 & 0xc000 ) >> 14 ;
switch ( V_13 ) {
case 3 :
div = 0x4 ;
break;
case 2 :
case 1 :
div = 0x2 ;
break;
default:
div = 0x1 ;
break;
}
V_2 -> V_45 = V_41 * ( V_40 + 2 ) / ( V_39 + 2 ) * ( div * 1000 ) ;
}
return 0 ;
}
static void F_19 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_20 ( V_52 ) ;
F_21 ( V_54 -> V_55 ) ;
F_22 ( V_52 ) ;
F_17 ( V_52 ) ;
}
int F_23 ( struct V_9 * V_10 ,
struct V_53 * V_54 ,
const struct V_56 * V_57 ,
struct V_58 * V_55 )
{
int V_8 ;
F_24 ( & V_54 -> V_3 , V_57 ) ;
V_54 -> V_55 = V_55 ;
V_8 = F_25 ( V_10 , & V_54 -> V_3 , & V_59 ) ;
if ( V_8 ) {
F_26 ( L_13 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static struct V_51 *
F_27 ( struct V_9 * V_10 ,
struct V_60 * V_61 ,
const struct V_56 * V_57 )
{
struct V_58 * V_55 ;
struct V_53 * V_54 ;
int V_8 ;
V_55 = F_28 ( V_61 , V_57 -> V_62 [ 0 ] ) ;
if ( V_55 == NULL )
return F_29 ( - V_63 ) ;
V_54 = F_15 ( sizeof( * V_54 ) , V_36 ) ;
if ( ! V_54 ) {
F_21 ( V_55 ) ;
return F_29 ( - V_64 ) ;
}
V_8 = F_23 ( V_10 , V_54 , V_57 , V_55 ) ;
if ( V_8 ) {
F_21 ( V_55 ) ;
F_17 ( V_54 ) ;
return F_29 ( V_8 ) ;
}
return & V_54 -> V_3 ;
}
static T_4 F_30 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
T_3 V_14 ;
T_4 V_65 ;
F_8 ( V_2 ) ;
V_65 = V_66 ;
V_14 = F_6 ( V_2 , V_31 , 0xaa , 0xff ) ;
switch ( V_14 & 3 ) {
case 0 : V_65 = V_67 ; break;
case 1 : V_65 = V_68 ; break;
case 2 : V_65 = V_69 ; break;
case 3 : V_65 = V_70 ; break;
}
V_14 = F_6 ( V_2 , V_31 , 0x99 , 0xff ) ;
switch ( V_14 & 0x03 ) {
case 1 :
V_65 -= 0x100000 ;
break;
case 2 :
V_65 -= 0x200000 ;
break;
case 3 :
V_65 -= 0x400000 ;
break;
}
return V_65 ;
}
int F_31 ( struct V_9 * V_10 , unsigned long V_71 )
{
struct V_1 * V_2 ;
bool V_11 ;
int V_8 = 0 ;
V_2 = F_15 ( sizeof( struct V_1 ) , V_36 ) ;
if ( ! V_2 )
return - V_64 ;
V_10 -> V_12 = V_2 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_72 = F_32 ( V_10 -> V_15 , 1 , 0 ) ;
if ( ! V_2 -> V_72 ) {
V_8 = - V_73 ;
goto V_74;
}
if ( ! ( F_33 ( V_10 -> V_15 , 2 ) & V_75 ) ) {
F_9 ( L_14 ) ;
V_2 -> V_76 = V_2 -> V_72 + V_77 ;
}
if ( ! V_2 -> V_76 ) {
V_2 -> V_76 = F_32 ( V_10 -> V_15 , 2 , 0 ) ;
if ( ! V_2 -> V_76 ) {
V_8 = - V_73 ;
goto V_74;
}
}
F_7 ( V_10 , & V_11 ) ;
if ( V_2 -> V_18 != V_29 ) {
V_8 = F_18 ( V_10 ) ;
if ( V_8 )
goto V_74;
V_2 -> V_65 = F_30 ( V_10 ) ;
F_9 ( L_15 , V_2 -> V_45 , V_2 -> V_43 , V_2 -> V_42 , V_2 -> V_65 ) ;
}
if ( V_11 )
F_34 ( V_10 ) ;
V_8 = F_35 ( V_2 ) ;
if ( V_8 )
goto V_74;
F_36 ( V_10 ) ;
V_10 -> V_78 . V_79 = ( void * ) & V_80 ;
V_10 -> V_78 . V_81 = 0 ;
V_10 -> V_78 . V_82 = 0 ;
V_10 -> V_78 . V_83 = 24 ;
V_10 -> V_78 . V_84 = 1 ;
V_10 -> V_78 . V_85 = F_37 ( V_2 -> V_10 -> V_15 , 0 ) ;
if ( V_2 -> V_18 == V_25 ||
V_2 -> V_18 == V_23 ||
V_2 -> V_18 == V_22 ||
V_2 -> V_18 == V_21 ||
V_2 -> V_18 == V_29 ) {
V_10 -> V_78 . V_86 = 1920 ;
V_10 -> V_78 . V_87 = 2048 ;
} else {
V_10 -> V_78 . V_86 = 1600 ;
V_10 -> V_78 . V_87 = 1200 ;
}
V_8 = F_38 ( V_10 ) ;
if ( V_8 )
goto V_74;
V_8 = F_39 ( V_10 ) ;
if ( V_8 )
goto V_74;
return 0 ;
V_74:
F_17 ( V_2 ) ;
V_10 -> V_12 = NULL ;
return V_8 ;
}
int F_40 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
F_17 ( V_2 -> V_35 ) ;
F_41 ( V_10 ) ;
F_42 ( V_10 ) ;
F_43 ( V_10 ) ;
F_44 ( V_2 ) ;
F_45 ( V_10 -> V_15 , V_2 -> V_76 ) ;
F_45 ( V_10 -> V_15 , V_2 -> V_72 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
int F_46 ( struct V_9 * V_10 ,
T_4 V_88 , bool V_89 ,
struct V_58 * * V_55 )
{
struct V_90 * V_91 ;
int V_8 ;
* V_55 = NULL ;
V_88 = F_47 ( V_88 , V_92 ) ;
if ( V_88 == 0 )
return - V_93 ;
V_8 = F_48 ( V_10 , V_88 , 0 , 0 , & V_91 ) ;
if ( V_8 ) {
if ( V_8 != - V_94 )
F_26 ( L_16 ) ;
return V_8 ;
}
* V_55 = & V_91 -> V_95 ;
return 0 ;
}
int F_49 ( struct V_60 * V_96 ,
struct V_9 * V_10 ,
struct V_97 * args )
{
int V_8 ;
struct V_58 * V_98 ;
T_4 V_99 ;
args -> V_100 = args -> V_101 * ( ( args -> V_102 + 7 ) / 8 ) ;
args -> V_88 = args -> V_100 * args -> V_103 ;
V_8 = F_46 ( V_10 , args -> V_88 , false ,
& V_98 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_50 ( V_96 , V_98 , & V_99 ) ;
F_21 ( V_98 ) ;
if ( V_8 )
return V_8 ;
args -> V_99 = V_99 ;
return 0 ;
}
static void F_51 ( struct V_90 * * V_104 )
{
struct V_105 * V_106 ;
if ( ( * V_104 ) == NULL )
return;
V_106 = & ( ( * V_104 ) -> V_104 ) ;
F_52 ( & V_106 ) ;
* V_104 = NULL ;
}
void F_53 ( struct V_58 * V_55 )
{
struct V_90 * V_90 = F_54 ( V_55 ) ;
F_51 ( & V_90 ) ;
}
static inline T_5 F_55 ( struct V_90 * V_104 )
{
return F_56 ( & V_104 -> V_104 . V_107 ) ;
}
int
F_57 ( struct V_60 * V_96 ,
struct V_9 * V_10 ,
T_1 V_99 ,
T_6 * V_108 )
{
struct V_58 * V_55 ;
struct V_90 * V_104 ;
V_55 = F_28 ( V_96 , V_99 ) ;
if ( V_55 == NULL )
return - V_63 ;
V_104 = F_54 ( V_55 ) ;
* V_108 = F_55 ( V_104 ) ;
F_21 ( V_55 ) ;
return 0 ;
}
