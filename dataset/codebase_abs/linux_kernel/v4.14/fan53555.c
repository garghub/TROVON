static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
if ( V_5 -> V_7 == V_3 )
return 0 ;
V_6 = F_3 ( V_2 , V_3 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_5 -> V_8 , V_5 -> V_9 ,
V_10 , V_6 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 -> V_7 = V_3 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_4 ( V_5 -> V_8 , V_5 -> V_9 ,
V_11 , V_11 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_4 ( V_5 -> V_8 , V_5 -> V_9 ,
V_11 , 0 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_12 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_12 ) {
case V_13 :
F_4 ( V_5 -> V_8 , V_5 -> V_14 ,
V_15 , V_15 ) ;
break;
case V_16 :
F_4 ( V_5 -> V_8 , V_5 -> V_14 , V_15 , 0 ) ;
break;
default:
return - V_17 ;
}
return 0 ;
}
static unsigned int F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_18 ;
int V_6 = 0 ;
V_6 = F_9 ( V_5 -> V_8 , V_5 -> V_14 , & V_18 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_18 & V_15 )
return V_13 ;
else
return V_16 ;
}
static int F_10 ( struct V_1 * V_2 , int V_19 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_20 = - 1 , V_21 ;
for ( V_21 = 0 ; V_21 < F_11 ( V_22 ) ; V_21 ++ ) {
if ( V_19 <= V_22 [ V_21 ] )
V_20 = V_21 ;
else
break;
}
if ( V_20 < 0 ) {
F_12 ( V_5 -> V_23 , L_1 , V_19 ) ;
return - V_17 ;
}
return F_4 ( V_5 -> V_8 , V_24 ,
V_25 , V_20 << V_26 ) ;
}
static int F_13 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_27 ) {
case V_28 :
switch ( V_5 -> V_29 ) {
case V_30 :
V_5 -> V_31 = 600000 ;
V_5 -> V_32 = 10000 ;
break;
case V_33 :
V_5 -> V_31 = 800000 ;
V_5 -> V_32 = 10000 ;
break;
default:
F_12 ( V_5 -> V_23 ,
L_2 ,
V_5 -> V_27 , V_5 -> V_29 ) ;
return - V_17 ;
}
break;
case V_34 :
case V_35 :
case V_36 :
case V_37 :
V_5 -> V_31 = 600000 ;
V_5 -> V_32 = 10000 ;
break;
case V_38 :
V_5 -> V_31 = 603000 ;
V_5 -> V_32 = 12826 ;
break;
default:
F_12 ( V_5 -> V_23 ,
L_3 , V_5 -> V_27 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_14 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_27 ) {
case V_39 :
V_5 -> V_31 = 712500 ;
V_5 -> V_32 = 12500 ;
break;
default:
F_12 ( V_5 -> V_23 ,
L_3 , V_5 -> V_27 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_15 ( struct V_4 * V_5 ,
struct V_40 * V_41 )
{
int V_6 = 0 ;
switch ( V_41 -> V_42 ) {
case V_43 :
V_5 -> V_9 = V_44 ;
V_5 -> V_14 = V_45 ;
break;
case V_46 :
V_5 -> V_9 = V_45 ;
V_5 -> V_14 = V_44 ;
break;
default:
F_12 ( V_5 -> V_23 , L_4 ) ;
return - V_17 ;
}
switch ( V_5 -> V_47 ) {
case V_48 :
V_6 = F_13 ( V_5 ) ;
break;
case V_49 :
V_6 = F_14 ( V_5 ) ;
break;
default:
F_12 ( V_5 -> V_23 , L_5 , V_5 -> V_47 ) ;
return - V_17 ;
}
return V_6 ;
}
static int F_16 ( struct V_4 * V_5 ,
struct V_50 * V_51 )
{
struct V_52 * V_53 = & V_5 -> V_54 ;
V_53 -> V_55 = L_6 ;
V_53 -> V_56 = L_7 ;
V_53 -> V_57 = & V_58 ;
V_53 -> type = V_59 ;
V_53 -> V_60 = V_61 ;
V_53 -> V_62 = V_5 -> V_14 ;
V_53 -> V_63 = V_11 ;
V_53 -> V_64 = V_5 -> V_31 ;
V_53 -> V_65 = V_5 -> V_32 ;
V_53 -> V_66 = V_5 -> V_14 ;
V_53 -> V_67 = V_10 ;
V_53 -> V_68 = V_69 ;
V_5 -> V_2 = F_17 ( V_5 -> V_23 , & V_5 -> V_54 , V_51 ) ;
return F_18 ( V_5 -> V_2 ) ;
}
static struct V_40 * F_19 ( struct V_70 * V_23 ,
struct V_71 * V_72 ,
const struct V_52 * V_54 )
{
struct V_40 * V_41 ;
int V_6 ;
T_1 V_73 ;
V_41 = F_20 ( V_23 , sizeof( * V_41 ) , V_74 ) ;
if ( ! V_41 )
return NULL ;
V_41 -> V_75 = F_21 ( V_23 , V_72 , V_54 ) ;
V_6 = F_22 ( V_72 , L_8 ,
& V_73 ) ;
if ( ! V_6 )
V_41 -> V_42 = V_73 ;
return V_41 ;
}
static int F_23 ( struct V_76 * V_77 ,
const struct V_78 * V_79 )
{
struct V_71 * V_72 = V_77 -> V_23 . V_80 ;
struct V_4 * V_5 ;
struct V_40 * V_41 ;
struct V_50 V_51 = { } ;
unsigned int V_18 ;
int V_6 ;
V_5 = F_20 ( & V_77 -> V_23 , sizeof( struct V_4 ) ,
V_74 ) ;
if ( ! V_5 )
return - V_81 ;
V_41 = F_24 ( & V_77 -> V_23 ) ;
if ( ! V_41 )
V_41 = F_19 ( & V_77 -> V_23 , V_72 , & V_5 -> V_54 ) ;
if ( ! V_41 || ! V_41 -> V_75 ) {
F_12 ( & V_77 -> V_23 , L_9 ) ;
return - V_82 ;
}
V_5 -> V_75 = V_41 -> V_75 ;
if ( V_77 -> V_23 . V_80 ) {
V_5 -> V_47 =
( unsigned long ) F_25 ( & V_77 -> V_23 ) ;
} else {
if ( ! V_5 -> V_75 -> V_83 . V_84 ) {
int V_85 = ( V_41 -> V_86 & 0x7 )
? V_41 -> V_86 : 0 ;
V_5 -> V_75 -> V_83 . V_84
= V_22 [ V_85 ] ;
}
V_5 -> V_47 = V_79 -> V_87 ;
}
V_5 -> V_8 = F_26 ( V_77 , & V_88 ) ;
if ( F_27 ( V_5 -> V_8 ) ) {
F_12 ( & V_77 -> V_23 , L_10 ) ;
return F_28 ( V_5 -> V_8 ) ;
}
V_5 -> V_23 = & V_77 -> V_23 ;
F_29 ( V_77 , V_5 ) ;
V_6 = F_9 ( V_5 -> V_8 , V_89 , & V_18 ) ;
if ( V_6 < 0 ) {
F_12 ( & V_77 -> V_23 , L_11 ) ;
return V_6 ;
}
V_5 -> V_27 = V_18 & V_90 ;
V_6 = F_9 ( V_5 -> V_8 , V_91 , & V_18 ) ;
if ( V_6 < 0 ) {
F_12 ( & V_77 -> V_23 , L_12 ) ;
return V_6 ;
}
V_5 -> V_29 = V_18 & V_92 ;
F_30 ( & V_77 -> V_23 , L_13 ,
V_5 -> V_27 , V_5 -> V_29 ) ;
V_6 = F_15 ( V_5 , V_41 ) ;
if ( V_6 < 0 ) {
F_12 ( & V_77 -> V_23 , L_14 ) ;
return V_6 ;
}
V_51 . V_23 = V_5 -> V_23 ;
V_51 . V_93 = V_5 -> V_75 ;
V_51 . V_8 = V_5 -> V_8 ;
V_51 . V_87 = V_5 ;
V_51 . V_80 = V_72 ;
V_6 = F_16 ( V_5 , & V_51 ) ;
if ( V_6 < 0 )
F_12 ( & V_77 -> V_23 , L_15 ) ;
return V_6 ;
}
