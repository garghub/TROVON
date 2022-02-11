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
static int F_5 ( struct V_1 * V_2 , unsigned int V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_11 ) {
case V_12 :
F_4 ( V_5 -> V_8 , V_5 -> V_13 ,
V_14 , V_14 ) ;
break;
case V_15 :
F_4 ( V_5 -> V_8 , V_5 -> V_13 , V_14 , 0 ) ;
break;
default:
return - V_16 ;
}
return 0 ;
}
static unsigned int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_17 ;
int V_6 = 0 ;
V_6 = F_7 ( V_5 -> V_8 , V_5 -> V_13 , & V_17 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_17 & V_14 )
return V_12 ;
else
return V_15 ;
}
static int F_8 ( struct V_1 * V_2 , int V_18 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_19 = - 1 , V_20 ;
for ( V_20 = 0 ; V_20 < F_9 ( V_21 ) ; V_20 ++ ) {
if ( V_18 <= V_21 [ V_20 ] )
V_19 = V_20 ;
else
break;
}
if ( V_19 < 0 ) {
F_10 ( V_5 -> V_22 , L_1 , V_18 ) ;
return - V_16 ;
}
return F_4 ( V_5 -> V_8 , V_23 ,
V_24 , V_19 << V_25 ) ;
}
static int F_11 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_26 ) {
case V_27 :
case V_28 :
case V_29 :
case V_30 :
V_5 -> V_31 = 600000 ;
V_5 -> V_32 = 10000 ;
break;
case V_33 :
V_5 -> V_31 = 603000 ;
V_5 -> V_32 = 12826 ;
break;
default:
F_10 ( V_5 -> V_22 ,
L_2 , V_5 -> V_26 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_12 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_26 ) {
case V_34 :
V_5 -> V_31 = 712500 ;
V_5 -> V_32 = 12500 ;
break;
default:
F_10 ( V_5 -> V_22 ,
L_2 , V_5 -> V_26 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_13 ( struct V_4 * V_5 ,
struct V_35 * V_36 )
{
int V_6 = 0 ;
switch ( V_36 -> V_37 ) {
case V_38 :
V_5 -> V_9 = V_39 ;
V_5 -> V_13 = V_40 ;
break;
case V_41 :
V_5 -> V_9 = V_40 ;
V_5 -> V_13 = V_39 ;
break;
default:
F_10 ( V_5 -> V_22 , L_3 ) ;
return - V_16 ;
}
switch ( V_5 -> V_42 ) {
case V_43 :
V_6 = F_11 ( V_5 ) ;
break;
case V_44 :
V_6 = F_12 ( V_5 ) ;
break;
default:
F_10 ( V_5 -> V_22 , L_4 , V_5 -> V_42 ) ;
return - V_16 ;
}
return V_6 ;
}
static int F_14 ( struct V_4 * V_5 ,
struct V_45 * V_46 )
{
struct V_47 * V_48 = & V_5 -> V_49 ;
V_48 -> V_50 = L_5 ;
V_48 -> V_51 = L_6 ;
V_48 -> V_52 = & V_53 ;
V_48 -> type = V_54 ;
V_48 -> V_55 = V_56 ;
V_48 -> V_57 = V_5 -> V_13 ;
V_48 -> V_58 = V_59 ;
V_48 -> V_60 = V_5 -> V_31 ;
V_48 -> V_61 = V_5 -> V_32 ;
V_48 -> V_62 = V_5 -> V_13 ;
V_48 -> V_63 = V_10 ;
V_48 -> V_64 = V_65 ;
V_5 -> V_2 = F_15 ( V_5 -> V_22 , & V_5 -> V_49 , V_46 ) ;
return F_16 ( V_5 -> V_2 ) ;
}
static struct V_35 * F_17 ( struct V_66 * V_22 ,
struct V_67 * V_68 ,
const struct V_47 * V_49 )
{
struct V_35 * V_36 ;
int V_6 ;
T_1 V_69 ;
V_36 = F_18 ( V_22 , sizeof( * V_36 ) , V_70 ) ;
if ( ! V_36 )
return NULL ;
V_36 -> V_71 = F_19 ( V_22 , V_68 , V_49 ) ;
V_6 = F_20 ( V_68 , L_7 ,
& V_69 ) ;
if ( ! V_6 )
V_36 -> V_37 = V_69 ;
return V_36 ;
}
static int F_21 ( struct V_72 * V_73 ,
const struct V_74 * V_75 )
{
struct V_67 * V_68 = V_73 -> V_22 . V_76 ;
struct V_4 * V_5 ;
struct V_35 * V_36 ;
struct V_45 V_46 = { } ;
unsigned int V_17 ;
int V_6 ;
V_5 = F_18 ( & V_73 -> V_22 , sizeof( struct V_4 ) ,
V_70 ) ;
if ( ! V_5 )
return - V_77 ;
V_36 = F_22 ( & V_73 -> V_22 ) ;
if ( ! V_36 )
V_36 = F_17 ( & V_73 -> V_22 , V_68 , & V_5 -> V_49 ) ;
if ( ! V_36 || ! V_36 -> V_71 ) {
F_10 ( & V_73 -> V_22 , L_8 ) ;
return - V_78 ;
}
V_5 -> V_71 = V_36 -> V_71 ;
if ( V_73 -> V_22 . V_76 ) {
const struct V_79 * V_80 ;
V_80 = F_23 ( F_24 ( V_81 ) ,
& V_73 -> V_22 ) ;
if ( ! V_80 )
return - V_78 ;
V_5 -> V_42 = ( unsigned long ) V_80 -> V_82 ;
} else {
if ( ! V_5 -> V_71 -> V_83 . V_84 ) {
int V_85 = ( V_36 -> V_86 & 0x7 )
? V_36 -> V_86 : 0 ;
V_5 -> V_71 -> V_83 . V_84
= V_21 [ V_85 ] ;
}
V_5 -> V_42 = V_75 -> V_87 ;
}
V_5 -> V_8 = F_25 ( V_73 , & V_88 ) ;
if ( F_26 ( V_5 -> V_8 ) ) {
F_10 ( & V_73 -> V_22 , L_9 ) ;
return F_27 ( V_5 -> V_8 ) ;
}
V_5 -> V_22 = & V_73 -> V_22 ;
F_28 ( V_73 , V_5 ) ;
V_6 = F_7 ( V_5 -> V_8 , V_89 , & V_17 ) ;
if ( V_6 < 0 ) {
F_10 ( & V_73 -> V_22 , L_10 ) ;
return V_6 ;
}
V_5 -> V_26 = V_17 & V_90 ;
V_6 = F_7 ( V_5 -> V_8 , V_91 , & V_17 ) ;
if ( V_6 < 0 ) {
F_10 ( & V_73 -> V_22 , L_11 ) ;
return V_6 ;
}
V_5 -> V_92 = V_17 & V_93 ;
F_29 ( & V_73 -> V_22 , L_12 ,
V_5 -> V_26 , V_5 -> V_92 ) ;
V_6 = F_13 ( V_5 , V_36 ) ;
if ( V_6 < 0 ) {
F_10 ( & V_73 -> V_22 , L_13 ) ;
return V_6 ;
}
V_46 . V_22 = V_5 -> V_22 ;
V_46 . V_94 = V_5 -> V_71 ;
V_46 . V_8 = V_5 -> V_8 ;
V_46 . V_87 = V_5 ;
V_46 . V_76 = V_68 ;
V_6 = F_14 ( V_5 , & V_46 ) ;
if ( V_6 < 0 )
F_10 ( & V_73 -> V_22 , L_14 ) ;
return V_6 ;
}
