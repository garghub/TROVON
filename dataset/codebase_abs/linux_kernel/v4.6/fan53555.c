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
case V_29 :
case V_30 :
case V_31 :
V_5 -> V_32 = 600000 ;
V_5 -> V_33 = 10000 ;
break;
case V_34 :
V_5 -> V_32 = 603000 ;
V_5 -> V_33 = 12826 ;
break;
default:
F_12 ( V_5 -> V_23 ,
L_2 , V_5 -> V_27 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_14 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_27 ) {
case V_35 :
V_5 -> V_32 = 712500 ;
V_5 -> V_33 = 12500 ;
break;
default:
F_12 ( V_5 -> V_23 ,
L_2 , V_5 -> V_27 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_15 ( struct V_4 * V_5 ,
struct V_36 * V_37 )
{
int V_6 = 0 ;
switch ( V_37 -> V_38 ) {
case V_39 :
V_5 -> V_9 = V_40 ;
V_5 -> V_14 = V_41 ;
break;
case V_42 :
V_5 -> V_9 = V_41 ;
V_5 -> V_14 = V_40 ;
break;
default:
F_12 ( V_5 -> V_23 , L_3 ) ;
return - V_17 ;
}
switch ( V_5 -> V_43 ) {
case V_44 :
V_6 = F_13 ( V_5 ) ;
break;
case V_45 :
V_6 = F_14 ( V_5 ) ;
break;
default:
F_12 ( V_5 -> V_23 , L_4 , V_5 -> V_43 ) ;
return - V_17 ;
}
return V_6 ;
}
static int F_16 ( struct V_4 * V_5 ,
struct V_46 * V_47 )
{
struct V_48 * V_49 = & V_5 -> V_50 ;
V_49 -> V_51 = L_5 ;
V_49 -> V_52 = L_6 ;
V_49 -> V_53 = & V_54 ;
V_49 -> type = V_55 ;
V_49 -> V_56 = V_57 ;
V_49 -> V_58 = V_5 -> V_14 ;
V_49 -> V_59 = V_11 ;
V_49 -> V_60 = V_5 -> V_32 ;
V_49 -> V_61 = V_5 -> V_33 ;
V_49 -> V_62 = V_5 -> V_14 ;
V_49 -> V_63 = V_10 ;
V_49 -> V_64 = V_65 ;
V_5 -> V_2 = F_17 ( V_5 -> V_23 , & V_5 -> V_50 , V_47 ) ;
return F_18 ( V_5 -> V_2 ) ;
}
static struct V_36 * F_19 ( struct V_66 * V_23 ,
struct V_67 * V_68 ,
const struct V_48 * V_50 )
{
struct V_36 * V_37 ;
int V_6 ;
T_1 V_69 ;
V_37 = F_20 ( V_23 , sizeof( * V_37 ) , V_70 ) ;
if ( ! V_37 )
return NULL ;
V_37 -> V_71 = F_21 ( V_23 , V_68 , V_50 ) ;
V_6 = F_22 ( V_68 , L_7 ,
& V_69 ) ;
if ( ! V_6 )
V_37 -> V_38 = V_69 ;
return V_37 ;
}
static int F_23 ( struct V_72 * V_73 ,
const struct V_74 * V_75 )
{
struct V_67 * V_68 = V_73 -> V_23 . V_76 ;
struct V_4 * V_5 ;
struct V_36 * V_37 ;
struct V_46 V_47 = { } ;
unsigned int V_18 ;
int V_6 ;
V_5 = F_20 ( & V_73 -> V_23 , sizeof( struct V_4 ) ,
V_70 ) ;
if ( ! V_5 )
return - V_77 ;
V_37 = F_24 ( & V_73 -> V_23 ) ;
if ( ! V_37 )
V_37 = F_19 ( & V_73 -> V_23 , V_68 , & V_5 -> V_50 ) ;
if ( ! V_37 || ! V_37 -> V_71 ) {
F_12 ( & V_73 -> V_23 , L_8 ) ;
return - V_78 ;
}
V_5 -> V_71 = V_37 -> V_71 ;
if ( V_73 -> V_23 . V_76 ) {
const struct V_79 * V_80 ;
V_80 = F_25 ( F_26 ( V_81 ) ,
& V_73 -> V_23 ) ;
if ( ! V_80 )
return - V_78 ;
V_5 -> V_43 = ( unsigned long ) V_80 -> V_82 ;
} else {
if ( ! V_5 -> V_71 -> V_83 . V_84 ) {
int V_85 = ( V_37 -> V_86 & 0x7 )
? V_37 -> V_86 : 0 ;
V_5 -> V_71 -> V_83 . V_84
= V_22 [ V_85 ] ;
}
V_5 -> V_43 = V_75 -> V_87 ;
}
V_5 -> V_8 = F_27 ( V_73 , & V_88 ) ;
if ( F_28 ( V_5 -> V_8 ) ) {
F_12 ( & V_73 -> V_23 , L_9 ) ;
return F_29 ( V_5 -> V_8 ) ;
}
V_5 -> V_23 = & V_73 -> V_23 ;
F_30 ( V_73 , V_5 ) ;
V_6 = F_9 ( V_5 -> V_8 , V_89 , & V_18 ) ;
if ( V_6 < 0 ) {
F_12 ( & V_73 -> V_23 , L_10 ) ;
return V_6 ;
}
V_5 -> V_27 = V_18 & V_90 ;
V_6 = F_9 ( V_5 -> V_8 , V_91 , & V_18 ) ;
if ( V_6 < 0 ) {
F_12 ( & V_73 -> V_23 , L_11 ) ;
return V_6 ;
}
V_5 -> V_92 = V_18 & V_93 ;
F_31 ( & V_73 -> V_23 , L_12 ,
V_5 -> V_27 , V_5 -> V_92 ) ;
V_6 = F_15 ( V_5 , V_37 ) ;
if ( V_6 < 0 ) {
F_12 ( & V_73 -> V_23 , L_13 ) ;
return V_6 ;
}
V_47 . V_23 = V_5 -> V_23 ;
V_47 . V_94 = V_5 -> V_71 ;
V_47 . V_8 = V_5 -> V_8 ;
V_47 . V_87 = V_5 ;
V_47 . V_76 = V_68 ;
V_6 = F_16 ( V_5 , & V_47 ) ;
if ( V_6 < 0 )
F_12 ( & V_73 -> V_23 , L_14 ) ;
return V_6 ;
}
