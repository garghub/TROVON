static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 -> V_7 ) ;
F_3 ( V_6 -> V_8 , V_9 , 0 ) ;
if ( ! V_6 -> V_10 )
F_3 ( V_6 -> V_8 , V_9 , 3 ) ;
return 0 ;
}
static int F_4 ( struct V_11 * V_7 ,
enum V_12 V_13 )
{
struct V_6 * V_6 = F_2 ( V_7 ) ;
switch ( V_13 ) {
case V_14 :
break;
case V_15 :
break;
case V_16 :
F_5 ( V_6 -> V_8 , V_17 ,
V_18 ,
V_18 ) ;
break;
case V_19 :
F_5 ( V_6 -> V_8 , V_17 ,
V_18 , 0 ) ;
break;
}
V_7 -> V_20 . V_21 = V_13 ;
return 0 ;
}
static enum V_22 F_6 (
struct V_11 * V_7 )
{
struct V_23 * V_24 = V_7 -> V_25 -> V_26 ;
if ( V_24 )
return V_24 -> V_27 ;
return V_28 ;
}
static int F_7 ( struct V_11 * V_7 )
{
struct V_23 * V_24 = V_7 -> V_25 -> V_26 ;
struct V_6 * V_6 = F_2 ( V_7 ) ;
enum V_29 V_30 ;
unsigned int V_31 = 0 ;
int V_32 ;
if ( V_24 )
V_30 = V_24 -> V_33 ;
else
V_30 = V_34 ;
switch ( V_30 ) {
case V_35 :
switch ( V_24 -> V_36 ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
V_31 |= V_24 -> V_36 << 6 ;
break;
default:
return - V_41 ;
}
if ( V_24 -> V_42 )
V_31 |= V_43 ;
V_32 = F_8 ( V_7 ,
V_44 ,
F_9 ( V_44 ) ) ;
if ( V_32 )
return V_32 ;
case V_34 :
V_32 = F_10 ( & V_7 -> V_20 ,
V_45 ,
F_9 ( V_45 ) ) ;
if ( V_32 )
return V_32 ;
break;
case V_46 :
V_32 = F_11 ( & V_7 -> V_20 ,
V_47 ,
F_9 ( V_47 ) ) ;
if ( V_32 )
return V_32 ;
V_32 = F_10 ( & V_7 -> V_20 ,
V_48 ,
F_9 ( V_48 ) ) ;
if ( V_32 )
return V_32 ;
V_31 |= V_49 ;
break;
default:
return - V_41 ;
}
F_3 ( V_6 -> V_8 , V_50 , V_31 ) ;
return 0 ;
}
static int F_12 ( struct V_11 * V_7 )
{
struct V_6 * V_6 = F_2 ( V_7 ) ;
struct V_23 * V_24 = V_7 -> V_25 -> V_26 ;
enum V_22 V_30 ;
int V_32 ;
if ( V_24 )
V_30 = V_24 -> V_51 ;
else
V_30 = V_52 ;
switch ( V_30 ) {
case V_28 :
break;
case V_53 :
F_5 ( V_6 -> V_8 , V_54 ,
V_55 |
V_56 ,
V_55 |
V_56 ) ;
case V_52 :
F_5 ( V_6 -> V_8 , V_57 ,
V_58 ,
V_58 ) ;
break;
default:
return - V_41 ;
}
if ( V_30 == V_53 ) {
V_32 = F_11 ( & V_7 -> V_20 ,
V_59 ,
F_9 ( V_59 ) ) ;
if ( V_32 )
return V_32 ;
V_32 = F_10 ( & V_7 -> V_20 ,
V_60 ,
F_9 ( V_60 ) ) ;
} else {
V_32 = F_8 ( V_7 , V_61 ,
F_9 ( V_61 ) ) ;
if ( V_32 )
return V_32 ;
V_32 = F_11 ( & V_7 -> V_20 ,
V_62 ,
F_9 ( V_62 ) ) ;
if ( V_32 )
return V_32 ;
V_32 = F_10 ( & V_7 -> V_20 ,
V_63 ,
F_9 ( V_63 ) ) ;
}
return V_32 ;
}
static bool F_13 ( struct V_64 * V_25 , unsigned int V_65 )
{
switch ( V_65 ) {
case V_50 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_57 :
case V_80 :
case V_81 :
case V_54 :
case V_82 :
case V_83 :
case V_9 :
case V_84 :
case V_85 :
return true ;
default:
break;
}
return F_14 ( V_25 , V_65 ) ;
}
static int F_15 ( struct V_11 * V_7 )
{
struct V_23 * V_24 = V_7 -> V_25 -> V_26 ;
struct V_6 * V_6 = F_2 ( V_7 ) ;
int V_32 ;
V_32 = F_16 ( V_7 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_24 && V_24 -> V_86 ) {
F_5 ( V_6 -> V_8 , V_70 ,
V_87 ,
V_87 ) ;
F_5 ( V_6 -> V_8 , V_71 ,
V_87 ,
V_87 ) ;
V_32 = F_8 ( V_7 ,
V_88 ,
F_9 ( V_88 ) ) ;
if ( V_32 )
return V_32 ;
} else {
V_32 = F_8 ( V_7 ,
V_89 ,
F_9 ( V_89 ) ) ;
if ( V_32 )
return V_32 ;
}
switch ( F_6 ( V_7 ) ) {
case V_28 :
break;
case V_52 :
F_5 ( V_6 -> V_8 , V_80 ,
V_90 ,
V_90 ) ;
F_5 ( V_6 -> V_8 , V_81 ,
V_91 ,
V_91 ) ;
break;
default:
return - V_41 ;
}
V_32 = F_12 ( V_7 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_7 ( V_7 ) ;
if ( V_32 )
return V_32 ;
if ( V_6 -> type == V_92 ) {
V_32 = F_11 ( & V_7 -> V_20 ,
V_93 ,
F_9 ( V_93 ) ) ;
if ( V_32 )
return V_32 ;
V_32 = F_10 ( & V_7 -> V_20 ,
V_94 ,
F_9 ( V_94 ) ) ;
if ( V_32 )
return V_32 ;
V_32 = F_17 ( V_6 , V_7 -> V_25 ,
V_95 ) ;
if ( V_32 )
F_18 ( V_7 -> V_25 , L_1 ) ;
}
V_32 = F_19 ( V_7 ) ;
if ( V_32 < 0 )
return V_32 ;
return 0 ;
}
int F_20 ( struct V_64 * V_25 , struct V_8 * V_8 ,
enum V_96 type , void (* F_21)( struct V_64 * V_25 ) )
{
struct V_97 * V_98 ;
int V_32 ;
V_32 = F_22 ( V_25 , V_8 , type , F_21 ) ;
if ( V_32 )
return V_32 ;
if ( type == V_99 )
V_98 = & V_100 ;
else
V_98 = & V_101 ;
return F_23 ( V_25 , & V_102 , V_98 , 1 ) ;
}
