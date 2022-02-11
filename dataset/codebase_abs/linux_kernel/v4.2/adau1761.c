static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
F_4 ( V_9 -> V_10 , V_11 , 0 ) ;
if ( ! V_9 -> V_12 )
F_4 ( V_9 -> V_10 , V_11 , 3 ) ;
return 0 ;
}
static int F_5 ( struct V_6 * V_7 ,
enum V_13 V_14 )
{
struct V_9 * V_9 = F_3 ( V_7 ) ;
switch ( V_14 ) {
case V_15 :
break;
case V_16 :
break;
case V_17 :
F_6 ( V_9 -> V_10 , V_18 ,
V_19 ,
V_19 ) ;
break;
case V_20 :
F_6 ( V_9 -> V_10 , V_18 ,
V_19 , 0 ) ;
break;
}
return 0 ;
}
static enum V_21 F_7 (
struct V_6 * V_7 )
{
struct V_22 * V_23 = V_7 -> V_24 -> V_25 ;
if ( V_23 )
return V_23 -> V_26 ;
return V_27 ;
}
static int F_8 ( struct V_6 * V_7 )
{
struct V_28 * V_8 = F_9 ( V_7 ) ;
struct V_22 * V_23 = V_7 -> V_24 -> V_25 ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
enum V_29 V_30 ;
unsigned int V_31 = 0 ;
int V_32 ;
if ( V_23 )
V_30 = V_23 -> V_33 ;
else
V_30 = V_34 ;
switch ( V_30 ) {
case V_35 :
switch ( V_23 -> V_36 ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
V_31 |= V_23 -> V_36 << 6 ;
break;
default:
return - V_41 ;
}
if ( V_23 -> V_42 )
V_31 |= V_43 ;
V_32 = F_10 ( V_7 ,
V_44 ,
F_11 ( V_44 ) ) ;
if ( V_32 )
return V_32 ;
case V_34 :
V_32 = F_12 ( V_8 , V_45 ,
F_11 ( V_45 ) ) ;
if ( V_32 )
return V_32 ;
break;
case V_46 :
V_32 = F_13 ( V_8 , V_47 ,
F_11 ( V_47 ) ) ;
if ( V_32 )
return V_32 ;
V_32 = F_12 ( V_8 , V_48 ,
F_11 ( V_48 ) ) ;
if ( V_32 )
return V_32 ;
V_31 |= V_49 ;
break;
default:
return - V_41 ;
}
F_4 ( V_9 -> V_10 , V_50 , V_31 ) ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 )
{
struct V_28 * V_8 = F_9 ( V_7 ) ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
struct V_22 * V_23 = V_7 -> V_24 -> V_25 ;
enum V_21 V_30 ;
int V_32 ;
if ( V_23 )
V_30 = V_23 -> V_51 ;
else
V_30 = V_52 ;
switch ( V_30 ) {
case V_27 :
break;
case V_53 :
F_6 ( V_9 -> V_10 , V_54 ,
V_55 |
V_56 ,
V_55 |
V_56 ) ;
case V_52 :
F_6 ( V_9 -> V_10 , V_57 ,
V_58 ,
V_58 ) ;
break;
default:
return - V_41 ;
}
if ( V_30 == V_53 ) {
V_32 = F_13 ( V_8 ,
V_59 ,
F_11 ( V_59 ) ) ;
if ( V_32 )
return V_32 ;
V_32 = F_12 ( V_8 ,
V_60 ,
F_11 ( V_60 ) ) ;
} else {
V_32 = F_10 ( V_7 , V_61 ,
F_11 ( V_61 ) ) ;
if ( V_32 )
return V_32 ;
V_32 = F_13 ( V_8 ,
V_62 ,
F_11 ( V_62 ) ) ;
if ( V_32 )
return V_32 ;
V_32 = F_12 ( V_8 ,
V_63 ,
F_11 ( V_63 ) ) ;
}
return V_32 ;
}
static bool F_15 ( struct V_64 * V_24 , unsigned int V_65 )
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
case V_11 :
case V_84 :
case V_85 :
return true ;
default:
break;
}
return F_16 ( V_24 , V_65 ) ;
}
static int F_17 ( struct V_6 * V_7 )
{
struct V_28 * V_8 = F_9 ( V_7 ) ;
struct V_22 * V_23 = V_7 -> V_24 -> V_25 ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
int V_32 ;
V_32 = F_18 ( V_7 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_23 && V_23 -> V_86 ) {
F_6 ( V_9 -> V_10 , V_70 ,
V_87 ,
V_87 ) ;
F_6 ( V_9 -> V_10 , V_71 ,
V_87 ,
V_87 ) ;
V_32 = F_10 ( V_7 ,
V_88 ,
F_11 ( V_88 ) ) ;
if ( V_32 )
return V_32 ;
} else {
V_32 = F_10 ( V_7 ,
V_89 ,
F_11 ( V_89 ) ) ;
if ( V_32 )
return V_32 ;
}
switch ( F_7 ( V_7 ) ) {
case V_27 :
break;
case V_52 :
F_6 ( V_9 -> V_10 , V_80 ,
V_90 ,
V_90 ) ;
F_6 ( V_9 -> V_10 , V_81 ,
V_91 ,
V_91 ) ;
break;
default:
return - V_41 ;
}
V_32 = F_14 ( V_7 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_8 ( V_7 ) ;
if ( V_32 )
return V_32 ;
if ( V_9 -> type == V_92 ) {
V_32 = F_13 ( V_8 , V_93 ,
F_11 ( V_93 ) ) ;
if ( V_32 )
return V_32 ;
V_32 = F_12 ( V_8 , V_94 ,
F_11 ( V_94 ) ) ;
if ( V_32 )
return V_32 ;
}
V_32 = F_19 ( V_7 ) ;
if ( V_32 < 0 )
return V_32 ;
return 0 ;
}
int F_20 ( struct V_64 * V_24 , struct V_10 * V_10 ,
enum V_95 type , void (* F_21)( struct V_64 * V_24 ) )
{
struct V_96 * V_97 ;
const char * V_98 ;
int V_32 ;
if ( type == V_99 ) {
V_97 = & V_100 ;
V_98 = NULL ;
} else {
V_97 = & V_101 ;
V_98 = V_102 ;
}
V_32 = F_22 ( V_24 , V_10 , type , F_21 , V_98 ) ;
if ( V_32 )
return V_32 ;
return F_23 ( V_24 , & V_103 , V_97 , 1 ) ;
}
