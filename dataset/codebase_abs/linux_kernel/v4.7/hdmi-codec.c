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
V_21 = V_8 -> V_27 . V_28 -> V_29 ( V_20 -> V_24 -> V_30 ) ;
if ( V_21 ) {
F_7 ( & V_8 -> V_22 ) ;
V_8 -> V_23 = NULL ;
F_9 ( & V_8 -> V_22 ) ;
return V_21 ;
}
}
if ( V_8 -> V_27 . V_28 -> V_31 ) {
V_21 = V_8 -> V_27 . V_28 -> V_31 ( V_20 -> V_24 -> V_30 , V_8 -> V_11 ,
sizeof( V_8 -> V_11 ) ) ;
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
V_8 -> V_27 . V_28 -> V_33 ( V_20 -> V_24 -> V_30 ) ;
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
return V_8 -> V_27 . V_28 -> V_54 ( V_20 -> V_24 -> V_30 , & V_8 -> V_55 [ V_20 -> V_56 ] ,
& V_37 ) ;
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
return V_8 -> V_27 . V_28 -> V_90 ( V_20 -> V_24 -> V_30 , V_89 ) ;
return 0 ;
}
static int F_23 ( struct V_91 * V_92 )
{
struct V_93 * V_27 = V_92 -> V_24 . V_94 ;
struct V_95 * V_24 = & V_92 -> V_24 ;
struct V_7 * V_8 ;
int V_96 , V_97 = 0 ;
int V_21 ;
F_11 ( V_24 , L_2 , V_26 ) ;
if ( ! V_27 ) {
F_8 ( V_24 , L_6 , V_26 ) ;
return - V_25 ;
}
V_96 = V_27 -> V_98 + V_27 -> V_99 ;
if ( V_96 < 1 || ! V_27 -> V_28 || ! V_27 -> V_28 -> V_54 ||
! V_27 -> V_28 -> V_33 ) {
F_8 ( V_24 , L_7 , V_26 ) ;
return - V_25 ;
}
V_8 = F_24 ( V_24 , sizeof( * V_8 ) , V_100 ) ;
if ( ! V_8 )
return - V_101 ;
V_8 -> V_27 = * V_27 ;
F_25 ( & V_8 -> V_22 ) ;
V_8 -> V_102 = F_24 ( V_24 , V_96 * sizeof( * V_8 -> V_102 ) ,
V_100 ) ;
if ( ! V_8 -> V_102 )
return - V_101 ;
if ( V_27 -> V_98 ) {
V_8 -> V_102 [ V_97 ] = V_103 ;
V_8 -> V_102 [ V_97 ] . V_104 . V_105 =
V_27 -> V_106 ;
V_97 ++ ;
}
if ( V_27 -> V_99 )
V_8 -> V_102 [ V_97 ] = V_107 ;
V_21 = F_26 ( V_24 , & V_108 , V_8 -> V_102 ,
V_96 ) ;
if ( V_21 ) {
F_8 ( V_24 , L_8 ,
V_26 , V_21 ) ;
return V_21 ;
}
F_27 ( V_24 , V_8 ) ;
return 0 ;
}
static int F_28 ( struct V_91 * V_92 )
{
F_29 ( & V_92 -> V_24 ) ;
return 0 ;
}
