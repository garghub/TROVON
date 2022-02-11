static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
T_2 V_8 ;
F_2 ( L_1 , V_3 ) ;
V_8 = V_5 -> V_9 ( V_5 , V_10 ) ;
switch ( V_3 ) {
case V_11 :
V_8 . V_10 . V_12 = 1 ;
break;
case V_13 :
V_8 . V_10 . V_12 = 0 ;
V_8 . V_10 . V_14 = 0 ;
break;
case V_15 :
V_8 . V_10 . V_12 = 0 ;
V_8 . V_10 . V_14 = 1 ;
break;
default:
F_3 ( L_2 ) ;
return - V_16 ;
}
return V_5 -> V_17 ( V_5 , V_10 , V_8 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
if ( V_5 -> V_18 )
return V_5 -> V_18 ( V_2 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_3 V_19 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
T_2 V_8 ;
T_4 V_20 ;
V_8 . V_21 = 0 ;
F_2 ( L_3 , V_19 ) ;
switch ( V_19 ) {
case V_22 :
V_20 = 0x01ff ;
break;
case V_23 :
V_20 = 0 ;
break;
default:
F_3 ( L_4 ) ;
return - V_16 ;
}
V_8 . V_24 . V_25 = 1 ;
V_8 . V_24 . V_26 = V_20 ;
V_8 . V_24 . V_27 = V_20 == 0 ? 0x1ff : V_20 ;
return V_5 -> V_17 ( V_5 , V_24 , V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_28 )
{
F_5 ( V_2 , V_22 ) ;
F_7 ( V_28 ? 500 : 1000 ) ;
F_5 ( V_2 , V_23 ) ;
F_7 ( V_28 ? 1000 : 500 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_28 )
{
int V_29 , V_30 = 1 , V_31 ;
for ( V_29 = 7 ; V_29 >= 0 ; V_29 -- ) {
V_31 = ( V_28 >> V_29 ) & 1 ;
V_30 ^= V_31 ;
F_6 ( V_2 , V_31 ) ;
}
F_6 ( V_2 , V_30 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
int V_32 , T_5 * V_33 , unsigned long V_34 )
{
int V_29 ;
F_5 ( V_2 , V_23 ) ;
F_10 ( 16 ) ;
for ( V_29 = 0 ; V_29 < V_32 ; V_29 ++ )
F_8 ( V_2 , V_33 [ V_29 ] ) ;
F_10 ( 16 ) ;
if ( V_34 != - 1 ) {
if ( V_34 )
F_8 ( V_2 , 0xff ) ;
else {
F_5 ( V_2 , V_22 ) ;
F_10 ( 12 ) ;
F_7 ( 500 ) ;
F_5 ( V_2 , V_23 ) ;
}
F_11 ( 20 ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
return F_9 ( V_2 , V_36 -> V_37 , V_36 -> V_33 , 0 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
T_6 V_38 )
{
return F_9 ( V_2 , 0 , NULL , V_38 ) ;
}
static int F_14 ( struct V_4 * V_5 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 ;
V_5 -> V_2 = F_15 ( V_43 , & V_44 , V_40 ) ;
if ( ! V_5 -> V_2 )
return 0 ;
if ( ! F_15 ( V_45 , V_5 -> V_2 , 0x61 , V_40 ,
V_46 ) )
return 0 ;
V_42 = & V_5 -> V_2 -> V_42 ;
V_42 -> V_47 = F_12 ;
V_42 -> V_48 = F_13 ;
V_42 -> V_49 = F_5 ;
V_42 -> V_50 = F_1 ;
V_5 -> V_18 = V_42 -> V_51 ;
V_42 -> V_51 = F_4 ;
return 1 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_7 V_52 , T_7 V_53 )
{
T_5 V_54 = 0 ;
T_5 V_55 = 0 ;
if ( V_52 < 1500000 ) {
V_54 = 0xb7 ; V_55 = 0x47 ;
} else if ( V_52 < 3000000 ) {
V_54 = 0xb7 ; V_55 = 0x4b ;
} else if ( V_52 < 7000000 ) {
V_54 = 0xb7 ; V_55 = 0x4f ;
} else if ( V_52 < 14000000 ) {
V_54 = 0xb7 ; V_55 = 0x53 ;
} else if ( V_52 < 30000000 ) {
V_54 = 0xb6 ; V_55 = 0x53 ;
} else if ( V_52 < 45000000 ) {
V_54 = 0xb4 ; V_55 = 0x51 ;
}
F_17 ( V_2 , 0x13 , V_54 ) ;
F_17 ( V_2 , 0x14 , V_55 ) ;
F_17 ( V_2 , 0x1f , ( V_53 >> 16 ) & 0xff ) ;
F_17 ( V_2 , 0x20 , ( V_53 >> 8 ) & 0xff ) ;
F_17 ( V_2 , 0x21 , V_53 & 0xf0 ) ;
return 0 ;
}
static int F_18 ( struct V_4 * V_5 ,
struct V_39 * V_40 )
{
V_5 -> V_2 = F_15 ( V_56 , & V_57 , V_40 ) ;
if ( ! V_5 -> V_2 )
return 0 ;
if ( ! F_15 ( V_45 , V_5 -> V_2 , 0x61 , V_40 ,
V_58 ) )
return 0 ;
V_5 -> V_2 -> V_42 . V_50 = F_1 ;
V_5 -> V_18 = V_5 -> V_2 -> V_42 . V_51 ;
V_5 -> V_2 -> V_42 . V_51 = F_4 ;
return 1 ;
}
static int F_19 ( struct V_4 * V_5 ,
struct V_39 * V_40 )
{
T_2 V_59 ;
struct V_39 * V_60 ;
V_5 -> V_61 [ 0 ] . V_62 = 1 ;
V_5 -> V_2 = F_15 ( V_63 , & V_64 ,
V_40 ) ;
if ( ! V_5 -> V_2 )
goto V_65;
V_60 = F_20 ( V_5 -> V_2 ) ;
if ( ! V_60 )
goto V_65;
V_5 -> V_18 = V_5 -> V_2 -> V_42 . V_51 ;
V_5 -> V_2 -> V_42 . V_51 = F_4 ;
V_5 -> V_61 [ 2 ] . V_62 = 1 ;
if ( ! F_15 ( V_66 , V_5 -> V_2 , & V_5 -> V_61 [ 2 ] . V_67 ,
0x08 , 1 , 1 ) ) {
F_3 ( L_5 ) ;
goto V_68;
}
F_21 ( L_6 ) ;
V_59 . V_21 = 0x00000506 ;
V_5 -> V_17 ( V_5 , V_69 , V_59 ) ;
if ( ! F_15 ( V_70 , V_5 -> V_2 , V_60 ,
& V_71 ) ) {
F_3 ( L_7 ) ;
goto V_68;
}
F_21 ( L_8 ) ;
return 1 ;
V_68:
V_5 -> V_61 [ 2 ] . V_62 = 0 ;
V_65:
V_5 -> V_61 [ 0 ] . V_62 = 0 ;
return 0 ;
}
static int F_22 ( struct V_4 * V_5 ,
struct V_39 * V_40 )
{
struct V_39 * V_60 ;
V_5 -> V_2 = F_15 ( V_72 , & V_73 ,
V_40 ) ;
if ( ! V_5 -> V_2 )
return 0 ;
V_60 = F_23 ( V_5 -> V_2 ) ;
if ( ! V_60 )
return 0 ;
if ( ! F_15 ( V_74 , V_5 -> V_2 , & V_75 ,
V_60 ) ) {
F_3 ( L_9 ) ;
return 0 ;
}
F_21 ( L_10 ) ;
V_5 -> V_61 [ 2 ] . V_62 = 1 ;
if ( ! F_15 ( V_66 , V_5 -> V_2 , & V_5 -> V_61 [ 2 ] . V_67 ,
0x08 , 0 , 0 ) ) {
F_3 ( L_5 ) ;
V_5 -> V_61 [ 2 ] . V_62 = 0 ;
return 0 ;
}
F_21 ( L_6 ) ;
return 1 ;
}
static int F_24 ( struct V_1 * V_2 )
{
static T_5 V_76 [] = { 0x89 , 0x18 , 0x2d } ;
static T_5 V_77 [] = { 0x50 , 0x80 } ;
static T_5 V_78 [] = { 0x8E , 0x40 } ;
static T_5 V_79 [] = { 0x67 , 0x28 , 0xa1 } ;
static T_5 V_80 [] = { 0x75 , 0x32 } ;
F_25 ( V_2 , V_76 , sizeof( V_76 ) ) ;
F_7 ( 2000 ) ;
F_25 ( V_2 , V_77 , sizeof( V_77 ) ) ;
F_25 ( V_2 , V_78 , sizeof( V_78 ) ) ;
F_25 ( V_2 , V_79 , sizeof( V_79 ) ) ;
F_25 ( V_2 , V_80 , sizeof( V_80 ) ) ;
return 0 ;
}
static int F_26 ( struct V_4 * V_5 ,
struct V_39 * V_40 )
{
V_5 -> V_2 = F_15 ( V_81 , & V_82 , V_40 ) ;
if ( ! V_5 -> V_2 )
return 0 ;
return ! ! F_15 ( V_45 , V_5 -> V_2 , 0x61 , NULL ,
V_83 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
const struct V_84 * * V_85 , char * V_86 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
return F_28 ( V_85 , V_86 , V_5 -> V_87 ) ;
}
static int F_29 ( struct V_4 * V_5 ,
struct V_39 * V_40 )
{
V_5 -> V_2 = F_15 ( V_88 , & V_89 , V_40 ) ;
return V_5 -> V_2 != NULL ;
}
static int F_30 ( struct V_4 * V_5 ,
struct V_39 * V_40 )
{
V_5 -> V_2 = F_15 ( V_90 , & V_91 , V_40 ) ;
if ( ! V_5 -> V_2 )
return 0 ;
return ! ! F_15 ( V_45 , V_5 -> V_2 , 0x61 , NULL ,
V_92 ) ;
}
static int F_31 ( struct V_4 * V_5 ,
struct V_39 * V_40 )
{
V_5 -> V_2 = F_15 ( V_93 , & V_94 , V_40 ) ;
if ( ! V_5 -> V_2 )
return 0 ;
return ! ! F_15 ( V_95 , V_5 -> V_2 , V_40 , 0x61 ,
V_96 ) ;
}
static int F_32 ( struct V_4 * V_5 ,
struct V_39 * V_40 )
{
V_5 -> V_61 [ 0 ] . V_62 = 1 ;
V_5 -> V_2 = F_15 ( V_97 , & V_98 , V_40 ) ;
if ( ! V_5 -> V_2 )
goto V_65;
if ( V_5 -> V_2 -> V_42 . V_99 )
V_5 -> V_2 -> V_42 . V_99 ( V_5 -> V_2 , 0 ) ;
V_5 -> V_2 -> V_42 . V_99 = NULL ;
if ( ! F_15 ( V_45 , V_5 -> V_2 , 0x61 ,
& V_5 -> V_61 [ 2 ] . V_67 , V_100 ) )
goto V_65;
return 1 ;
V_65:
V_5 -> V_61 [ 0 ] . V_62 = 0 ;
return 0 ;
}
int F_33 ( struct V_4 * V_5 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < F_34 ( V_101 ) ; V_29 ++ ) {
if ( ! V_101 [ V_29 ] . V_102 )
continue;
V_5 -> V_103 = V_101 [ V_29 ] . type ;
if ( V_101 [ V_29 ] . V_102 ( V_5 , & V_5 -> V_61 [ 0 ] . V_67 ) )
goto V_104;
if ( V_5 -> V_2 ) {
F_35 ( V_5 -> V_2 ) ;
V_5 -> V_2 = NULL ;
}
}
V_5 -> V_103 = V_105 ;
F_3 ( L_11 ) ;
return - V_106 ;
V_104:
F_21 ( L_12 , V_5 -> V_2 -> V_42 . F_21 . V_86 ) ;
if ( F_36 ( & V_5 -> V_107 , V_5 -> V_2 ) ) {
F_3 ( L_13 ) ;
F_35 ( V_5 -> V_2 ) ;
V_5 -> V_2 = NULL ;
return - V_16 ;
}
V_5 -> V_108 |= V_109 ;
return 0 ;
}
void F_37 ( struct V_4 * V_5 )
{
if ( V_5 -> V_108 & V_109 ) {
F_38 ( V_5 -> V_2 ) ;
F_35 ( V_5 -> V_2 ) ;
}
V_5 -> V_108 &= ~ V_109 ;
}
