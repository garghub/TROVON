static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_4 -> type = V_9 ;
V_4 -> V_10 = sizeof( V_8 -> V_11 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
memcpy ( V_13 -> V_14 . V_15 . V_16 , V_8 -> V_11 , sizeof( V_8 -> V_11 ) ) ;
return 0 ;
}
static int F_5 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_7 * V_8 = F_6 ( V_20 ) ;
int V_21 = 0 ;
F_7 ( & V_8 -> V_22 ) ;
if ( ! V_8 -> V_23 ) {
V_8 -> V_23 = V_18 ;
} else if ( V_8 -> V_23 != V_18 ) {
F_8 ( V_20 -> V_24 , L_1 ) ;
V_21 = - V_25 ;
}
F_9 ( & V_8 -> V_22 ) ;
return V_21 ;
}
static int F_10 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_7 * V_8 = F_6 ( V_20 ) ;
int V_21 = 0 ;
F_11 ( V_20 -> V_24 , L_2 , V_26 ) ;
V_21 = F_5 ( V_18 , V_20 ) ;
if ( V_21 )
return V_21 ;
if ( V_8 -> V_27 . V_28 -> V_29 ) {
V_21 = V_8 -> V_27 . V_28 -> V_29 ( V_20 -> V_24 -> V_30 , V_8 -> V_27 . V_16 ) ;
if ( V_21 ) {
F_7 ( & V_8 -> V_22 ) ;
V_8 -> V_23 = NULL ;
F_9 ( & V_8 -> V_22 ) ;
return V_21 ;
}
}
if ( V_8 -> V_27 . V_28 -> V_31 ) {
V_21 = V_8 -> V_27 . V_28 -> V_31 ( V_20 -> V_24 -> V_30 , V_8 -> V_27 . V_16 ,
V_8 -> V_11 , sizeof( V_8 -> V_11 ) ) ;
if ( ! V_21 ) {
V_21 = F_12 ( V_18 -> V_32 ,
V_8 -> V_11 ) ;
if ( V_21 )
return V_21 ;
}
}
return 0 ;
}
static void F_13 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_7 * V_8 = F_6 ( V_20 ) ;
F_11 ( V_20 -> V_24 , L_2 , V_26 ) ;
F_14 ( V_8 -> V_23 != V_18 ) ;
V_8 -> V_27 . V_28 -> V_33 ( V_20 -> V_24 -> V_30 , V_8 -> V_27 . V_16 ) ;
F_7 ( & V_8 -> V_22 ) ;
V_8 -> V_23 = NULL ;
F_9 ( & V_8 -> V_22 ) ;
}
static int F_15 ( struct V_17 * V_18 ,
struct V_34 * V_35 ,
struct V_19 * V_20 )
{
struct V_7 * V_8 = F_6 ( V_20 ) ;
struct V_36 V_37 = {
. V_38 = {
. V_39 = { 0 } ,
. V_40 = { 0 } ,
. V_41 = 0 ,
. V_42 = { 0 } ,
}
} ;
int V_21 ;
F_11 ( V_20 -> V_24 , L_3 , V_26 ,
F_16 ( V_35 ) , F_17 ( V_35 ) ,
F_18 ( V_35 ) ) ;
if ( F_16 ( V_35 ) > 24 )
V_35 -> V_43 = 24 ;
V_21 = F_19 ( V_35 , V_37 . V_38 . V_39 ,
sizeof( V_37 . V_38 . V_39 ) ) ;
if ( V_21 < 0 ) {
F_8 ( V_20 -> V_24 , L_4 ,
V_21 ) ;
return V_21 ;
}
V_21 = F_5 ( V_18 , V_20 ) ;
if ( V_21 )
return V_21 ;
F_20 ( & V_37 . V_44 ) ;
V_37 . V_44 . V_45 = F_18 ( V_35 ) ;
V_37 . V_44 . V_46 = V_47 ;
V_37 . V_44 . V_48 = V_49 ;
V_37 . V_44 . V_50 = V_51 ;
V_37 . V_52 = F_16 ( V_35 ) ;
V_37 . V_53 = F_17 ( V_35 ) ;
V_37 . V_45 = F_18 ( V_35 ) ;
return V_8 -> V_27 . V_28 -> V_54 ( V_20 -> V_24 -> V_30 , V_8 -> V_27 . V_16 ,
& V_8 -> V_55 [ V_20 -> V_56 ] , & V_37 ) ;
}
static int F_21 ( struct V_19 * V_20 ,
unsigned int V_57 )
{
struct V_7 * V_8 = F_6 ( V_20 ) ;
struct V_58 V_59 = { 0 } ;
int V_21 = 0 ;
F_11 ( V_20 -> V_24 , L_2 , V_26 ) ;
if ( V_20 -> V_56 == V_60 ) {
V_59 . V_57 = V_61 ;
} else {
switch ( V_57 & V_62 ) {
case V_63 :
V_59 . V_64 = 1 ;
V_59 . V_65 = 1 ;
break;
case V_66 :
V_59 . V_65 = 1 ;
break;
case V_67 :
V_59 . V_64 = 1 ;
break;
case V_68 :
break;
default:
return - V_25 ;
}
switch ( V_57 & V_69 ) {
case V_70 :
break;
case V_71 :
V_59 . V_72 = 1 ;
break;
case V_73 :
V_59 . V_74 = 1 ;
break;
case V_75 :
V_59 . V_72 = 1 ;
V_59 . V_74 = 1 ;
break;
}
switch ( V_57 & V_76 ) {
case V_77 :
V_59 . V_57 = V_78 ;
break;
case V_79 :
V_59 . V_57 = V_80 ;
break;
case V_81 :
V_59 . V_57 = V_82 ;
break;
case V_83 :
V_59 . V_57 = V_84 ;
break;
case V_85 :
V_59 . V_57 = V_86 ;
break;
case V_87 :
V_59 . V_57 = V_88 ;
break;
default:
F_8 ( V_20 -> V_24 , L_5 ) ;
return - V_25 ;
}
}
V_8 -> V_55 [ V_20 -> V_56 ] = V_59 ;
return V_21 ;
}
static int F_22 ( struct V_19 * V_20 , int V_89 )
{
struct V_7 * V_8 = F_6 ( V_20 ) ;
F_11 ( V_20 -> V_24 , L_2 , V_26 ) ;
if ( V_8 -> V_27 . V_28 -> V_90 )
return V_8 -> V_27 . V_28 -> V_90 ( V_20 -> V_24 -> V_30 ,
V_8 -> V_27 . V_16 , V_89 ) ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 ,
struct V_91 * args ,
const char * * V_92 )
{
int V_56 ;
if ( args -> V_93 )
V_56 = args -> args [ 0 ] ;
else
V_56 = 0 ;
if ( V_56 < F_24 ( V_94 ) ) {
* V_92 = V_94 [ V_56 ] ;
return 0 ;
}
return - V_95 ;
}
static int F_25 ( struct V_96 * V_97 )
{
struct V_98 * V_27 = V_97 -> V_24 . V_99 ;
struct V_100 * V_24 = & V_97 -> V_24 ;
struct V_7 * V_8 ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
int V_105 , V_106 = 0 ;
int V_21 ;
F_11 ( V_24 , L_2 , V_26 ) ;
if ( ! V_27 ) {
F_8 ( V_24 , L_6 , V_26 ) ;
return - V_25 ;
}
V_105 = V_27 -> V_107 + V_27 -> V_108 ;
if ( V_105 < 1 || ! V_27 -> V_28 || ! V_27 -> V_28 -> V_54 ||
! V_27 -> V_28 -> V_33 ) {
F_8 ( V_24 , L_7 , V_26 ) ;
return - V_25 ;
}
V_8 = F_26 ( V_24 , sizeof( * V_8 ) , V_109 ) ;
if ( ! V_8 )
return - V_110 ;
V_102 = NULL ;
F_27 (pos, &hdmi_device_list) {
struct V_101 * V_111 = F_28 ( V_104 ) ;
if ( V_111 -> V_24 == V_24 -> V_30 ) {
V_102 = V_111 ;
break;
}
}
if ( ! V_102 ) {
V_102 = F_26 ( V_24 , sizeof( * V_102 ) , V_109 ) ;
if ( ! V_102 )
return - V_110 ;
V_102 -> V_24 = V_24 -> V_30 ;
F_29 ( & V_102 -> V_112 , & V_113 ) ;
}
if ( V_102 -> V_114 >= F_24 ( V_94 ) ) {
F_8 ( V_24 , L_8 ) ;
return - V_25 ;
}
V_8 -> V_27 = * V_27 ;
F_30 ( & V_8 -> V_22 ) ;
V_8 -> V_115 = F_26 ( V_24 , V_105 * sizeof( * V_8 -> V_115 ) ,
V_109 ) ;
if ( ! V_8 -> V_115 )
return - V_110 ;
if ( V_27 -> V_107 ) {
V_8 -> V_115 [ V_106 ] = V_116 ;
V_8 -> V_115 [ V_106 ] . V_117 . V_118 =
V_27 -> V_119 ;
V_8 -> V_115 [ V_106 ] . V_120 = V_94 [ V_102 -> V_114 ++ ] ;
V_106 ++ ;
}
if ( V_27 -> V_108 ) {
V_8 -> V_115 [ V_106 ] = V_121 ;
V_8 -> V_115 [ V_106 ] . V_120 = V_94 [ V_102 -> V_114 ++ ] ;
}
V_21 = F_31 ( V_24 , & V_122 , V_8 -> V_115 ,
V_105 ) ;
if ( V_21 ) {
F_8 ( V_24 , L_9 ,
V_26 , V_21 ) ;
return V_21 ;
}
F_32 ( V_24 , V_8 ) ;
return 0 ;
}
static int F_33 ( struct V_96 * V_97 )
{
F_34 ( & V_97 -> V_24 ) ;
return 0 ;
}
