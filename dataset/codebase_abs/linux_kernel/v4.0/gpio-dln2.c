static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
int V_5 = sizeof( V_4 ) ;
V_3 = F_2 ( V_2 , V_6 , & V_4 , & V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_5 < sizeof( V_4 ) )
return - V_7 ;
return F_3 ( V_4 ) ;
}
static int F_4 ( struct V_8 * V_9 , int V_10 , unsigned V_11 )
{
struct V_12 V_13 = {
. V_11 = F_5 ( V_11 ) ,
} ;
return F_6 ( V_9 -> V_2 , V_10 , & V_13 , sizeof( V_13 ) ) ;
}
static int F_7 ( struct V_8 * V_9 , int V_10 , unsigned int V_11 )
{
int V_3 ;
struct V_12 V_13 = {
. V_11 = F_5 ( V_11 ) ,
} ;
struct F_7 V_14 ;
int V_5 = sizeof( V_14 ) ;
V_3 = F_8 ( V_9 -> V_2 , V_10 , & V_13 , sizeof( V_13 ) , & V_14 , & V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_5 < sizeof( V_14 ) || V_13 . V_11 != V_14 . V_11 )
return - V_7 ;
return V_14 . V_15 ;
}
static int F_9 ( struct V_8 * V_9 , unsigned int V_11 )
{
int V_3 ;
V_3 = F_7 ( V_9 , V_16 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
return ! ! V_3 ;
}
static int F_10 ( struct V_8 * V_9 , unsigned int V_11 )
{
int V_3 ;
V_3 = F_7 ( V_9 , V_17 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
return ! ! V_3 ;
}
static int F_11 ( struct V_8 * V_9 ,
unsigned int V_11 , int V_15 )
{
struct F_7 V_13 = {
. V_11 = F_5 ( V_11 ) ,
. V_15 = V_15 ,
} ;
return F_6 ( V_9 -> V_2 , V_18 , & V_13 ,
sizeof( V_13 ) ) ;
}
static int F_12 ( struct V_19 * V_20 , unsigned V_21 )
{
struct V_8 * V_9 = F_13 ( V_20 , struct V_8 , V_22 ) ;
struct V_12 V_13 = {
. V_11 = F_5 ( V_21 ) ,
} ;
struct F_7 V_14 ;
int V_5 = sizeof( V_14 ) ;
int V_3 ;
V_3 = F_4 ( V_9 , V_23 , V_21 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_8 ( V_9 -> V_2 , V_24 ,
& V_13 , sizeof( V_13 ) , & V_14 , & V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_5 < sizeof( V_14 ) || V_13 . V_11 != V_14 . V_11 ) {
V_3 = - V_7 ;
goto V_25;
}
switch ( V_14 . V_15 ) {
case V_26 :
F_14 ( V_21 , V_9 -> V_27 ) ;
return 0 ;
case V_28 :
F_15 ( V_21 , V_9 -> V_27 ) ;
return 0 ;
default:
V_3 = - V_7 ;
goto V_25;
}
V_25:
F_4 ( V_9 , V_29 , V_21 ) ;
return V_3 ;
}
static void F_16 ( struct V_19 * V_20 , unsigned V_21 )
{
struct V_8 * V_9 = F_13 ( V_20 , struct V_8 , V_22 ) ;
F_4 ( V_9 , V_29 , V_21 ) ;
}
static int F_17 ( struct V_19 * V_20 , unsigned V_21 )
{
struct V_8 * V_9 = F_13 ( V_20 , struct V_8 , V_22 ) ;
if ( F_18 ( V_21 , V_9 -> V_27 ) )
return V_30 ;
return V_31 ;
}
static int F_19 ( struct V_19 * V_20 , unsigned int V_21 )
{
struct V_8 * V_9 = F_13 ( V_20 , struct V_8 , V_22 ) ;
int V_32 ;
V_32 = F_17 ( V_20 , V_21 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_32 == V_31 )
return F_9 ( V_9 , V_21 ) ;
return F_10 ( V_9 , V_21 ) ;
}
static void F_20 ( struct V_19 * V_20 , unsigned V_21 , int V_15 )
{
struct V_8 * V_9 = F_13 ( V_20 , struct V_8 , V_22 ) ;
F_11 ( V_9 , V_21 , V_15 ) ;
}
static int F_21 ( struct V_19 * V_20 , unsigned V_21 ,
unsigned V_32 )
{
struct V_8 * V_9 = F_13 ( V_20 , struct V_8 , V_22 ) ;
struct F_7 V_13 = {
. V_11 = F_5 ( V_21 ) ,
. V_15 = V_32 ,
} ;
int V_3 ;
V_3 = F_6 ( V_9 -> V_2 , V_33 ,
& V_13 , sizeof( V_13 ) ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_32 == V_28 )
F_15 ( V_21 , V_9 -> V_27 ) ;
else
F_14 ( V_21 , V_9 -> V_27 ) ;
return V_3 ;
}
static int F_22 ( struct V_19 * V_20 , unsigned V_21 )
{
return F_21 ( V_20 , V_21 , V_26 ) ;
}
static int F_23 ( struct V_19 * V_20 , unsigned V_21 ,
int V_15 )
{
struct V_8 * V_9 = F_13 ( V_20 , struct V_8 , V_22 ) ;
int V_3 ;
V_3 = F_11 ( V_9 , V_21 , V_15 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_21 ( V_20 , V_21 , V_28 ) ;
}
static int F_24 ( struct V_19 * V_20 , unsigned V_21 ,
unsigned V_34 )
{
struct V_8 * V_9 = F_13 ( V_20 , struct V_8 , V_22 ) ;
T_2 V_35 = F_25 ( V_34 ) ;
return F_6 ( V_9 -> V_2 , V_36 ,
& V_35 , sizeof( V_35 ) ) ;
}
static int F_26 ( struct V_8 * V_9 , unsigned V_11 ,
unsigned type , unsigned V_37 )
{
struct {
T_1 V_11 ;
T_3 type ;
T_1 V_37 ;
} V_38 V_13 = {
. V_11 = F_5 ( V_11 ) ,
. type = type ,
. V_37 = F_5 ( V_37 ) ,
} ;
return F_6 ( V_9 -> V_2 , V_39 ,
& V_13 , sizeof( V_13 ) ) ;
}
static void F_27 ( struct V_40 * V_41 )
{
struct V_19 * V_42 = F_28 ( V_41 ) ;
struct V_8 * V_9 = F_13 ( V_42 , struct V_8 , V_22 ) ;
int V_11 = F_29 ( V_41 ) ;
F_15 ( V_11 , V_9 -> V_43 ) ;
}
static void F_30 ( struct V_40 * V_41 )
{
struct V_19 * V_42 = F_28 ( V_41 ) ;
struct V_8 * V_9 = F_13 ( V_42 , struct V_8 , V_22 ) ;
int V_11 = F_29 ( V_41 ) ;
F_14 ( V_11 , V_9 -> V_43 ) ;
}
static int F_31 ( struct V_40 * V_41 , unsigned type )
{
struct V_19 * V_42 = F_28 ( V_41 ) ;
struct V_8 * V_9 = F_13 ( V_42 , struct V_8 , V_22 ) ;
int V_11 = F_29 ( V_41 ) ;
switch ( type ) {
case V_44 :
V_9 -> V_45 [ V_11 ] = V_46 ;
break;
case V_47 :
V_9 -> V_45 [ V_11 ] = V_48 ;
break;
case V_49 :
V_9 -> V_45 [ V_11 ] = V_50 ;
break;
case V_51 :
V_9 -> V_45 [ V_11 ] = V_52 ;
break;
case V_53 :
V_9 -> V_45 [ V_11 ] = V_54 ;
break;
default:
return - V_55 ;
}
return 0 ;
}
static void F_32 ( struct V_40 * V_41 )
{
struct V_19 * V_42 = F_28 ( V_41 ) ;
struct V_8 * V_9 = F_13 ( V_42 , struct V_8 , V_22 ) ;
F_33 ( & V_9 -> V_56 ) ;
}
static void F_34 ( struct V_40 * V_41 )
{
struct V_19 * V_42 = F_28 ( V_41 ) ;
struct V_8 * V_9 = F_13 ( V_42 , struct V_8 , V_22 ) ;
int V_11 = F_29 ( V_41 ) ;
int V_57 , V_58 ;
unsigned type ;
int V_3 ;
V_57 = F_18 ( V_11 , V_9 -> V_59 ) ;
V_58 = F_18 ( V_11 , V_9 -> V_43 ) ;
if ( V_57 != V_58 ) {
if ( V_58 ) {
type = V_9 -> V_45 [ V_11 ] & V_60 ;
F_15 ( V_11 , V_9 -> V_59 ) ;
} else {
type = V_61 ;
F_14 ( V_11 , V_9 -> V_59 ) ;
}
V_3 = F_26 ( V_9 , V_11 , type , 0 ) ;
if ( V_3 )
F_35 ( V_9 -> V_22 . V_62 , L_1 ) ;
}
F_36 ( & V_9 -> V_56 ) ;
}
static void F_37 ( struct V_1 * V_2 , T_4 V_63 ,
const void * V_64 , int V_5 )
{
int V_11 , V_65 ;
const struct {
T_1 V_4 ;
T_5 type ;
T_1 V_11 ;
T_5 V_15 ;
} V_38 * V_66 = V_64 ;
struct V_8 * V_9 = F_38 ( V_2 ) ;
if ( V_5 < sizeof( * V_66 ) ) {
F_35 ( V_9 -> V_22 . V_62 , L_2 ) ;
return;
}
V_11 = F_3 ( V_66 -> V_11 ) ;
if ( V_11 >= V_9 -> V_22 . V_67 ) {
F_35 ( V_9 -> V_22 . V_62 , L_3 , V_11 ) ;
return;
}
V_65 = F_39 ( V_9 -> V_22 . V_68 , V_11 ) ;
if ( ! V_65 ) {
F_35 ( V_9 -> V_22 . V_62 , L_4 , V_11 ) ;
return;
}
switch ( V_9 -> V_45 [ V_11 ] ) {
case V_52 :
if ( V_66 -> V_15 )
F_40 ( V_65 ) ;
break;
case V_54 :
if ( ! V_66 -> V_15 )
F_40 ( V_65 ) ;
break;
default:
F_40 ( V_65 ) ;
}
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_69 * V_62 = & V_2 -> V_62 ;
int V_70 ;
int V_3 ;
V_70 = F_1 ( V_2 ) ;
if ( V_70 < 0 ) {
F_35 ( V_62 , L_5 , V_70 ) ;
return V_70 ;
}
if ( V_70 > V_71 ) {
V_70 = V_71 ;
F_42 ( V_62 , L_6 , V_71 ) ;
}
V_9 = F_43 ( & V_2 -> V_62 , sizeof( * V_9 ) , V_72 ) ;
if ( ! V_9 )
return - V_73 ;
F_44 ( & V_9 -> V_56 ) ;
V_9 -> V_2 = V_2 ;
V_9 -> V_22 . V_74 = L_7 ;
V_9 -> V_22 . V_62 = V_62 ;
V_9 -> V_22 . V_75 = V_76 ;
V_9 -> V_22 . V_77 = - 1 ;
V_9 -> V_22 . V_67 = V_70 ;
V_9 -> V_22 . V_78 = true ;
V_9 -> V_22 . V_79 = true ;
V_9 -> V_22 . V_80 = true ;
V_9 -> V_22 . V_81 = F_20 ;
V_9 -> V_22 . V_82 = F_19 ;
V_9 -> V_22 . V_83 = F_12 ;
V_9 -> V_22 . free = F_16 ;
V_9 -> V_22 . V_84 = F_17 ;
V_9 -> V_22 . V_85 = F_22 ;
V_9 -> V_22 . V_86 = F_23 ;
V_9 -> V_22 . V_87 = F_24 ;
F_45 ( V_2 , V_9 ) ;
V_3 = F_46 ( & V_9 -> V_22 ) ;
if ( V_3 < 0 ) {
F_35 ( V_62 , L_8 , V_3 ) ;
goto V_88;
}
V_3 = F_47 ( & V_9 -> V_22 , & V_89 , 0 ,
V_90 , V_91 ) ;
if ( V_3 < 0 ) {
F_35 ( V_62 , L_9 , V_3 ) ;
goto V_92;
}
V_3 = F_48 ( V_2 , V_93 ,
F_37 ) ;
if ( V_3 ) {
F_35 ( V_62 , L_10 , V_3 ) ;
goto V_92;
}
return 0 ;
V_92:
F_49 ( & V_9 -> V_22 ) ;
V_88:
return V_3 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_38 ( V_2 ) ;
F_51 ( V_2 , V_93 ) ;
F_49 ( & V_9 -> V_22 ) ;
return 0 ;
}
