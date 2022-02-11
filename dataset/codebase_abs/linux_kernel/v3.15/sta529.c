static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
return true ;
default:
return false ;
}
}
static int F_2 ( struct V_16 * V_17 , enum
V_18 V_19 )
{
struct V_20 * V_20 = F_3 ( V_17 ) ;
switch ( V_19 ) {
case V_21 :
case V_22 :
F_4 ( V_17 , V_4 , V_23 ,
V_24 ) ;
F_4 ( V_17 , V_15 , V_25 ,
V_26 ) ;
break;
case V_27 :
if ( V_17 -> V_28 . V_29 == V_30 )
F_5 ( V_20 -> V_31 ) ;
F_4 ( V_17 , V_4 ,
V_23 , V_32 ) ;
F_4 ( V_17 , V_4 , V_33 ,
V_34 ) ;
F_4 ( V_17 , V_15 , V_25 ,
V_35 ) ;
break;
case V_30 :
break;
}
V_17 -> V_28 . V_29 = V_19 ;
return 0 ;
}
static int F_6 ( struct V_36 * V_37 ,
struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_16 * V_17 = V_41 -> V_17 ;
int V_42 , V_43 , V_44 ;
int V_45 ;
switch ( F_7 ( V_39 ) ) {
case V_46 :
V_42 = 1 ;
V_45 = 0 ;
break;
case V_47 :
V_42 = 2 ;
V_45 = 1 ;
break;
case V_48 :
V_42 = 3 ;
V_45 = 2 ;
break;
default:
F_8 ( V_17 -> V_2 , L_1 ) ;
return - V_49 ;
}
switch ( F_9 ( V_39 ) ) {
case 8000 :
case 11025 :
V_43 = 0 ;
V_44 = 2 ;
break;
case 16000 :
case 22050 :
V_43 = 1 ;
V_44 = 0 ;
break;
case 32000 :
case 44100 :
case 48000 :
V_43 = 2 ;
V_44 = 0 ;
break;
default:
F_8 ( V_17 -> V_2 , L_2 ) ;
return - V_49 ;
}
if ( V_37 -> V_50 == V_51 ) {
F_4 ( V_17 , V_10 , V_52 ,
V_42 << 6 ) ;
F_4 ( V_17 , V_10 , V_53 ,
V_45 << 4 ) ;
F_4 ( V_17 , V_15 , V_54 ,
V_43 << 4 ) ;
} else {
F_4 ( V_17 , V_12 , V_52 ,
V_42 << 6 ) ;
F_4 ( V_17 , V_12 , V_53 ,
V_45 << 4 ) ;
F_4 ( V_17 , V_15 , V_55 ,
V_44 << 2 ) ;
}
return 0 ;
}
static int F_10 ( struct V_40 * V_41 , int V_56 )
{
T_1 V_57 = 0 ;
if ( V_56 )
V_57 |= V_58 ;
F_4 ( V_41 -> V_17 , V_4 , V_59 , V_57 ) ;
return 0 ;
}
static int F_11 ( struct V_40 * V_60 , T_2 V_61 )
{
struct V_16 * V_17 = V_60 -> V_17 ;
T_1 V_62 = 0 ;
switch ( V_61 & V_63 ) {
case V_64 :
V_62 = V_65 ;
break;
case V_66 :
V_62 = V_67 ;
break;
case V_68 :
V_62 = V_69 ;
break;
default:
return - V_49 ;
}
F_4 ( V_17 , V_9 , V_70 , V_62 ) ;
return 0 ;
}
static int F_12 ( struct V_16 * V_17 )
{
F_2 ( V_17 , V_27 ) ;
return 0 ;
}
static int F_13 ( struct V_16 * V_17 )
{
F_2 ( V_17 , V_30 ) ;
return 0 ;
}
static int F_14 ( struct V_16 * V_17 )
{
F_2 ( V_17 , V_30 ) ;
return 0 ;
}
static int F_15 ( struct V_16 * V_17 )
{
F_2 ( V_17 , V_27 ) ;
return 0 ;
}
static int F_16 ( struct V_71 * V_72 ,
const struct V_73 * V_74 )
{
struct V_20 * V_20 ;
int V_75 ;
if ( ! F_17 ( V_72 -> V_76 , V_77 ) )
return - V_49 ;
V_20 = F_18 ( & V_72 -> V_2 , sizeof( struct V_20 ) , V_78 ) ;
if ( V_20 == NULL ) {
F_8 ( & V_72 -> V_2 , L_3 ) ;
return - V_79 ;
}
V_20 -> V_31 = F_19 ( V_72 , & V_80 ) ;
if ( F_20 ( V_20 -> V_31 ) ) {
V_75 = F_21 ( V_20 -> V_31 ) ;
F_8 ( & V_72 -> V_2 , L_4 , V_75 ) ;
return V_75 ;
}
F_22 ( V_72 , V_20 ) ;
V_75 = F_23 ( & V_72 -> V_2 ,
& V_81 , & V_82 , 1 ) ;
if ( V_75 != 0 )
F_8 ( & V_72 -> V_2 , L_5 , V_75 ) ;
return V_75 ;
}
static int F_24 ( struct V_71 * V_83 )
{
F_25 ( & V_83 -> V_2 ) ;
return 0 ;
}
