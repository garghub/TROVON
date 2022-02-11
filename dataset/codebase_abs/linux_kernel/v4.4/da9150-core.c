static int F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 ,
T_1 * V_5 )
{
struct V_6 V_7 ;
int V_8 ;
V_7 . V_3 = V_2 -> V_3 ;
V_7 . V_9 = 0 ;
V_7 . V_10 = 1 ;
V_7 . V_5 = & V_3 ;
V_8 = F_2 ( V_2 -> V_11 , & V_7 , 1 ) ;
if ( V_8 != 1 ) {
if ( V_8 < 0 )
return V_8 ;
else
return - V_12 ;
}
V_7 . V_3 = V_2 -> V_3 ;
V_7 . V_9 = V_13 ;
V_7 . V_10 = V_4 ;
V_7 . V_5 = V_5 ;
V_8 = F_2 ( V_2 -> V_11 , & V_7 , 1 ) ;
if ( V_8 == 1 )
return 0 ;
else if ( V_8 < 0 )
return V_8 ;
else
return - V_12 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 ,
int V_4 , const T_1 * V_5 )
{
struct V_6 V_7 ;
T_1 * V_14 ;
int V_8 ;
V_14 = F_4 ( 1 + V_4 , V_15 ) ;
if ( ! V_14 )
return - V_16 ;
V_14 [ 0 ] = V_3 ;
memcpy ( & V_14 [ 1 ] , V_5 , V_4 ) ;
V_7 . V_3 = V_2 -> V_3 ;
V_7 . V_9 = 0 ;
V_7 . V_10 = 1 + V_4 ;
V_7 . V_5 = V_14 ;
V_8 = F_2 ( V_2 -> V_11 , & V_7 , 1 ) ;
F_5 ( V_14 ) ;
if ( V_8 == 1 )
return 0 ;
else if ( V_8 < 0 )
return V_8 ;
else
return - V_12 ;
}
static bool F_6 ( struct V_17 * V_18 , unsigned int V_19 )
{
switch ( V_19 ) {
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
return true ;
default:
return false ;
}
}
void F_7 ( struct V_71 * V_71 , T_1 V_3 , int V_4 , T_1 * V_5 )
{
int V_8 ;
V_8 = F_1 ( V_71 -> V_72 , V_3 , V_4 , V_5 ) ;
if ( V_8 < 0 )
F_8 ( V_71 -> V_18 , L_1 ,
V_3 , V_8 ) ;
}
void F_9 ( struct V_71 * V_71 , T_1 V_3 , int V_4 , const T_1 * V_5 )
{
int V_8 ;
V_8 = F_3 ( V_71 -> V_72 , V_3 , V_4 , V_5 ) ;
if ( V_8 < 0 )
F_8 ( V_71 -> V_18 , L_2 ,
V_3 , V_8 ) ;
}
T_1 F_10 ( struct V_71 * V_71 , T_2 V_19 )
{
int V_73 , V_8 ;
V_8 = F_11 ( V_71 -> V_74 , V_19 , & V_73 ) ;
if ( V_8 )
F_8 ( V_71 -> V_18 , L_3 ,
V_19 , V_8 ) ;
return ( T_1 ) V_73 ;
}
void F_12 ( struct V_71 * V_71 , T_2 V_19 , T_1 V_73 )
{
int V_8 ;
V_8 = F_13 ( V_71 -> V_74 , V_19 , V_73 ) ;
if ( V_8 )
F_8 ( V_71 -> V_18 , L_4 ,
V_19 , V_8 ) ;
}
void F_14 ( struct V_71 * V_71 , T_2 V_19 , T_1 V_75 , T_1 V_73 )
{
int V_8 ;
V_8 = F_15 ( V_71 -> V_74 , V_19 , V_75 , V_73 ) ;
if ( V_8 )
F_8 ( V_71 -> V_18 , L_5 ,
V_19 , V_8 ) ;
}
void F_16 ( struct V_71 * V_71 , T_2 V_19 , int V_4 , T_1 * V_5 )
{
int V_8 ;
V_8 = F_17 ( V_71 -> V_74 , V_19 , V_5 , V_4 ) ;
if ( V_8 )
F_8 ( V_71 -> V_18 , L_6 ,
V_19 , V_8 ) ;
}
void F_18 ( struct V_71 * V_71 , T_2 V_19 , int V_4 , const T_1 * V_5 )
{
int V_8 ;
V_8 = F_19 ( V_71 -> V_74 , V_19 , V_5 , V_4 ) ;
if ( V_8 )
F_8 ( V_71 -> V_18 , L_7 ,
V_19 , V_8 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
const struct V_76 * V_77 )
{
struct V_71 * V_71 ;
struct V_78 * V_79 = F_21 ( & V_2 -> V_18 ) ;
int V_80 ;
int V_8 ;
V_71 = F_22 ( & V_2 -> V_18 , sizeof( * V_71 ) , V_15 ) ;
if ( ! V_71 )
return - V_16 ;
V_71 -> V_18 = & V_2 -> V_18 ;
V_71 -> V_81 = V_2 -> V_81 ;
F_23 ( V_2 , V_71 ) ;
V_71 -> V_74 = F_24 ( V_2 , & V_82 ) ;
if ( F_25 ( V_71 -> V_74 ) ) {
V_8 = F_26 ( V_71 -> V_74 ) ;
F_8 ( V_71 -> V_18 , L_8 ,
V_8 ) ;
return V_8 ;
}
V_80 = F_10 ( V_71 , V_83 ) ;
V_80 = ( V_80 & V_84 ) >> 1 ;
V_80 |= V_85 ;
V_71 -> V_72 = F_27 ( V_2 -> V_11 , V_80 ) ;
if ( ! V_71 -> V_72 ) {
F_8 ( V_71 -> V_18 , L_9 ) ;
return - V_86 ;
}
F_23 ( V_71 -> V_72 , V_71 ) ;
if ( V_79 ) {
V_71 -> V_87 = V_79 -> V_87 ;
V_88 [ V_89 ] . V_90 = V_79 -> V_91 ;
V_88 [ V_89 ] . V_92 =
sizeof( struct V_93 ) ;
} else {
V_71 -> V_87 = - 1 ;
}
V_8 = F_28 ( V_71 -> V_74 , V_71 -> V_81 ,
V_94 | V_95 ,
V_71 -> V_87 , & V_96 ,
& V_71 -> V_97 ) ;
if ( V_8 ) {
F_8 ( V_71 -> V_18 , L_10 ,
V_8 ) ;
goto V_98;
}
V_71 -> V_87 = F_29 ( V_71 -> V_97 ) ;
F_30 ( V_71 -> V_81 ) ;
V_8 = F_31 ( V_71 -> V_18 , - 1 , V_88 ,
F_32 ( V_88 ) , NULL ,
V_71 -> V_87 , NULL ) ;
if ( V_8 ) {
F_8 ( V_71 -> V_18 , L_11 , V_8 ) ;
goto V_99;
}
return 0 ;
V_99:
F_33 ( V_71 -> V_81 , V_71 -> V_97 ) ;
V_98:
F_34 ( V_71 -> V_72 ) ;
return V_8 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_71 * V_71 = F_36 ( V_2 ) ;
F_33 ( V_71 -> V_81 , V_71 -> V_97 ) ;
F_37 ( V_71 -> V_18 ) ;
F_34 ( V_71 -> V_72 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_71 * V_71 = F_36 ( V_2 ) ;
F_14 ( V_71 , V_100 ,
V_101 ,
V_101 ) ;
F_14 ( V_71 , V_41 ,
V_102 , V_102 ) ;
}
