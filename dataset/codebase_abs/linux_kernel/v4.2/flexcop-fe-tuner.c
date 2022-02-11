static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * * V_4 , char * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
return F_2 ( V_4 , V_5 , V_7 -> V_10 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
enum V_11 V_12 )
{
struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
T_1 V_13 ;
F_4 ( L_1 , V_12 ) ;
V_13 = V_7 -> V_14 ( V_7 , V_15 ) ;
switch ( V_12 ) {
case V_16 :
V_13 . V_15 . V_17 = 1 ;
break;
case V_18 :
V_13 . V_15 . V_17 = 0 ;
V_13 . V_15 . V_19 = 0 ;
break;
case V_20 :
V_13 . V_15 . V_17 = 0 ;
V_13 . V_15 . V_19 = 1 ;
break;
default:
F_5 ( L_2 ) ;
return - V_21 ;
}
return V_7 -> V_22 ( V_7 , V_15 , V_13 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
if ( V_7 -> V_23 )
return V_7 -> V_23 ( V_2 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , enum V_24 V_25 )
{
struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
T_1 V_13 ;
T_2 V_26 ;
V_13 . V_27 = 0 ;
F_4 ( L_3 , V_25 ) ;
switch ( V_25 ) {
case V_28 :
V_26 = 0x01ff ;
break;
case V_29 :
V_26 = 0 ;
break;
default:
F_5 ( L_4 ) ;
return - V_21 ;
}
V_13 . V_30 . V_31 = 1 ;
V_13 . V_30 . V_32 = V_26 ;
V_13 . V_30 . V_33 = V_26 == 0 ? 0x1ff : V_26 ;
return V_7 -> V_22 ( V_7 , V_30 , V_13 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_34 )
{
F_7 ( V_2 , V_28 ) ;
F_9 ( V_34 ? 500 : 1000 ) ;
F_7 ( V_2 , V_29 ) ;
F_9 ( V_34 ? 1000 : 500 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_34 )
{
int V_35 , V_36 = 1 , V_37 ;
for ( V_35 = 7 ; V_35 >= 0 ; V_35 -- ) {
V_37 = ( V_34 >> V_35 ) & 1 ;
V_36 ^= V_37 ;
F_8 ( V_2 , V_37 ) ;
}
F_8 ( V_2 , V_36 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
int V_38 , T_3 * V_39 , unsigned long V_40 )
{
int V_35 ;
F_7 ( V_2 , V_29 ) ;
F_12 ( 16 ) ;
for ( V_35 = 0 ; V_35 < V_38 ; V_35 ++ )
F_10 ( V_2 , V_39 [ V_35 ] ) ;
F_12 ( 16 ) ;
if ( V_40 != - 1 ) {
if ( V_40 )
F_10 ( V_2 , 0xff ) ;
else {
F_7 ( V_2 , V_28 ) ;
F_12 ( 12 ) ;
F_9 ( 500 ) ;
F_7 ( V_2 , V_29 ) ;
}
F_13 ( 20 ) ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
return F_11 ( V_2 , V_42 -> V_43 , V_42 -> V_39 , 0 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
enum V_44 V_45 )
{
return F_11 ( V_2 , 0 , NULL , V_45 ) ;
}
static int F_16 ( struct V_6 * V_7 ,
struct V_46 * V_47 )
{
struct V_48 * V_49 ;
V_7 -> V_2 = F_17 ( V_50 , & V_51 , V_47 ) ;
if ( ! V_7 -> V_2 )
return 0 ;
if ( ! F_17 ( V_52 , V_7 -> V_2 , 0x61 , V_47 ,
V_53 ) )
return 0 ;
V_49 = & V_7 -> V_2 -> V_49 ;
V_49 -> V_54 = F_14 ;
V_49 -> V_55 = F_15 ;
V_49 -> V_56 = F_7 ;
V_49 -> V_57 = F_3 ;
V_7 -> V_23 = V_49 -> V_58 ;
V_49 -> V_58 = F_6 ;
return 1 ;
}
static int F_18 ( struct V_1 * V_2 ,
T_4 V_59 , T_4 V_60 )
{
T_3 V_61 = 0 ;
T_3 V_62 = 0 ;
if ( V_59 < 1500000 ) {
V_61 = 0xb7 ; V_62 = 0x47 ;
} else if ( V_59 < 3000000 ) {
V_61 = 0xb7 ; V_62 = 0x4b ;
} else if ( V_59 < 7000000 ) {
V_61 = 0xb7 ; V_62 = 0x4f ;
} else if ( V_59 < 14000000 ) {
V_61 = 0xb7 ; V_62 = 0x53 ;
} else if ( V_59 < 30000000 ) {
V_61 = 0xb6 ; V_62 = 0x53 ;
} else if ( V_59 < 45000000 ) {
V_61 = 0xb4 ; V_62 = 0x51 ;
}
F_19 ( V_2 , 0x13 , V_61 ) ;
F_19 ( V_2 , 0x14 , V_62 ) ;
F_19 ( V_2 , 0x1f , ( V_60 >> 16 ) & 0xff ) ;
F_19 ( V_2 , 0x20 , ( V_60 >> 8 ) & 0xff ) ;
F_19 ( V_2 , 0x21 , V_60 & 0xf0 ) ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 ,
struct V_46 * V_47 )
{
V_7 -> V_2 = F_17 ( V_63 , & V_64 , V_47 ) ;
if ( ! V_7 -> V_2 )
return 0 ;
if ( ! F_17 ( V_52 , V_7 -> V_2 , 0x61 , V_47 ,
V_65 ) )
return 0 ;
V_7 -> V_2 -> V_49 . V_57 = F_3 ;
V_7 -> V_23 = V_7 -> V_2 -> V_49 . V_58 ;
V_7 -> V_2 -> V_49 . V_58 = F_6 ;
return 1 ;
}
static int F_21 ( struct V_6 * V_7 ,
struct V_46 * V_47 )
{
T_1 V_66 ;
struct V_46 * V_67 ;
V_7 -> V_68 [ 0 ] . V_69 = 1 ;
V_7 -> V_2 = F_17 ( V_70 , & V_71 ,
V_47 ) ;
if ( ! V_7 -> V_2 )
goto V_72;
V_67 = F_22 ( V_7 -> V_2 ) ;
if ( ! V_67 )
goto V_72;
V_7 -> V_23 = V_7 -> V_2 -> V_49 . V_58 ;
V_7 -> V_2 -> V_49 . V_58 = F_6 ;
V_7 -> V_68 [ 2 ] . V_69 = 1 ;
if ( ! F_17 ( V_73 , V_7 -> V_2 , & V_7 -> V_68 [ 2 ] . V_74 ,
0x08 , 1 , 1 , false ) ) {
F_5 ( L_5 ) ;
goto V_75;
}
F_23 ( L_6 ) ;
V_66 . V_27 = 0x00000506 ;
V_7 -> V_22 ( V_7 , V_76 , V_66 ) ;
if ( ! F_17 ( V_77 , V_7 -> V_2 , V_67 ,
& V_78 ) ) {
F_5 ( L_7 ) ;
goto V_75;
}
F_23 ( L_8 ) ;
return 1 ;
V_75:
V_7 -> V_68 [ 2 ] . V_69 = 0 ;
V_72:
V_7 -> V_68 [ 0 ] . V_69 = 0 ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 ,
struct V_46 * V_47 )
{
struct V_46 * V_67 ;
V_7 -> V_2 = F_17 ( V_79 , & V_80 ,
V_47 ) ;
if ( ! V_7 -> V_2 )
return 0 ;
V_67 = F_25 ( V_7 -> V_2 ) ;
if ( ! V_67 )
return 0 ;
if ( ! F_17 ( V_81 , V_7 -> V_2 , & V_82 ,
V_67 ) ) {
F_5 ( L_9 ) ;
return 0 ;
}
F_23 ( L_10 ) ;
V_7 -> V_68 [ 2 ] . V_69 = 1 ;
if ( ! F_17 ( V_73 , V_7 -> V_2 , & V_7 -> V_68 [ 2 ] . V_74 ,
0x08 , 0 , 0 , false ) ) {
F_5 ( L_5 ) ;
V_7 -> V_68 [ 2 ] . V_69 = 0 ;
return 0 ;
}
F_23 ( L_6 ) ;
return 1 ;
}
static int F_26 ( struct V_1 * V_2 )
{
static T_3 V_83 [] = { 0x89 , 0x18 , 0x2d } ;
static T_3 V_84 [] = { 0x50 , 0x80 } ;
static T_3 V_85 [] = { 0x8E , 0x40 } ;
static T_3 V_86 [] = { 0x67 , 0x28 , 0xa1 } ;
static T_3 V_87 [] = { 0x75 , 0x32 } ;
F_27 ( V_2 , V_83 , sizeof( V_83 ) ) ;
F_9 ( 2000 ) ;
F_27 ( V_2 , V_84 , sizeof( V_84 ) ) ;
F_27 ( V_2 , V_85 , sizeof( V_85 ) ) ;
F_27 ( V_2 , V_86 , sizeof( V_86 ) ) ;
F_27 ( V_2 , V_87 , sizeof( V_87 ) ) ;
return 0 ;
}
static int F_28 ( struct V_6 * V_7 ,
struct V_46 * V_47 )
{
V_7 -> V_2 = F_17 ( V_88 , & V_89 , V_47 ) ;
if ( ! V_7 -> V_2 )
return 0 ;
return ! ! F_17 ( V_52 , V_7 -> V_2 , 0x61 , NULL ,
V_90 ) ;
}
static int F_29 ( struct V_6 * V_7 ,
struct V_46 * V_47 )
{
V_7 -> V_2 = F_17 ( V_91 , & V_92 , V_47 ) ;
return V_7 -> V_2 != NULL ;
}
static int F_30 ( struct V_6 * V_7 ,
struct V_46 * V_47 )
{
V_7 -> V_2 = F_17 ( V_93 , & V_94 , V_47 ) ;
if ( ! V_7 -> V_2 )
return 0 ;
return ! ! F_17 ( V_52 , V_7 -> V_2 , 0x61 , NULL ,
V_95 ) ;
}
static int F_31 ( struct V_6 * V_7 ,
struct V_46 * V_47 )
{
V_7 -> V_2 = F_17 ( V_96 , & V_97 , V_47 ) ;
if ( ! V_7 -> V_2 )
return 0 ;
return ! ! F_17 ( V_98 , V_7 -> V_2 , V_47 , 0x61 ,
V_99 ) ;
}
static int F_32 ( struct V_6 * V_7 ,
struct V_46 * V_47 )
{
V_7 -> V_68 [ 0 ] . V_69 = 1 ;
V_7 -> V_2 = F_17 ( V_100 , & V_101 , V_47 ) ;
if ( ! V_7 -> V_2 )
goto V_72;
if ( V_7 -> V_2 -> V_49 . V_102 )
V_7 -> V_2 -> V_49 . V_102 ( V_7 -> V_2 , 0 ) ;
V_7 -> V_2 -> V_49 . V_102 = NULL ;
if ( ! F_17 ( V_52 , V_7 -> V_2 , 0x61 ,
& V_7 -> V_68 [ 2 ] . V_74 , V_103 ) )
goto V_72;
return 1 ;
V_72:
V_7 -> V_68 [ 0 ] . V_69 = 0 ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 ,
struct V_46 * V_47 )
{
V_7 -> V_2 = F_17 ( V_104 ,
& V_105 , V_47 ) ;
if ( ! V_7 -> V_2 )
return 0 ;
V_7 -> V_106 = V_107 ;
V_7 -> V_68 [ 2 ] . V_69 = 1 ;
if ( ! F_17 ( V_73 , V_7 -> V_2 , & V_7 -> V_68 [ 2 ] . V_74 ,
0x08 , 0 , 0 , false ) ) {
F_5 ( L_11 ) ;
V_7 -> V_68 [ 2 ] . V_69 = 0 ;
return 0 ;
}
F_23 ( L_12 ) ;
if ( V_7 -> V_108 )
V_7 -> V_109 = 1 ;
return 1 ;
}
int F_34 ( struct V_6 * V_7 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < F_35 ( V_110 ) ; V_35 ++ ) {
if ( ! V_110 [ V_35 ] . V_111 )
continue;
V_7 -> V_106 = V_110 [ V_35 ] . type ;
if ( V_110 [ V_35 ] . V_111 ( V_7 , & V_7 -> V_68 [ 0 ] . V_74 ) )
goto V_112;
if ( V_7 -> V_2 ) {
F_36 ( V_7 -> V_2 ) ;
V_7 -> V_2 = NULL ;
}
}
V_7 -> V_106 = V_113 ;
F_5 ( L_13 ) ;
return - V_114 ;
V_112:
F_23 ( L_14 , V_7 -> V_2 -> V_49 . F_23 . V_5 ) ;
if ( F_37 ( & V_7 -> V_115 , V_7 -> V_2 ) ) {
F_5 ( L_15 ) ;
F_36 ( V_7 -> V_2 ) ;
V_7 -> V_2 = NULL ;
return - V_21 ;
}
V_7 -> V_116 |= V_117 ;
return 0 ;
}
void F_38 ( struct V_6 * V_7 )
{
if ( V_7 -> V_116 & V_117 ) {
F_39 ( V_7 -> V_2 ) ;
F_36 ( V_7 -> V_2 ) ;
}
V_7 -> V_116 &= ~ V_117 ;
}
