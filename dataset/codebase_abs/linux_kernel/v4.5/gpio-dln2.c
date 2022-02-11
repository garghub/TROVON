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
struct V_8 * V_9 = F_13 ( V_20 ) ;
struct V_12 V_13 = {
. V_11 = F_5 ( V_21 ) ,
} ;
struct F_7 V_14 ;
int V_5 = sizeof( V_14 ) ;
int V_3 ;
V_3 = F_4 ( V_9 , V_22 , V_21 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_8 ( V_9 -> V_2 , V_23 ,
& V_13 , sizeof( V_13 ) , & V_14 , & V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_5 < sizeof( V_14 ) || V_13 . V_11 != V_14 . V_11 ) {
V_3 = - V_7 ;
goto V_24;
}
switch ( V_14 . V_15 ) {
case V_25 :
F_14 ( V_21 , V_9 -> V_26 ) ;
return 0 ;
case V_27 :
F_15 ( V_21 , V_9 -> V_26 ) ;
return 0 ;
default:
V_3 = - V_7 ;
goto V_24;
}
V_24:
F_4 ( V_9 , V_28 , V_21 ) ;
return V_3 ;
}
static void F_16 ( struct V_19 * V_20 , unsigned V_21 )
{
struct V_8 * V_9 = F_13 ( V_20 ) ;
F_4 ( V_9 , V_28 , V_21 ) ;
}
static int F_17 ( struct V_19 * V_20 , unsigned V_21 )
{
struct V_8 * V_9 = F_13 ( V_20 ) ;
if ( F_18 ( V_21 , V_9 -> V_26 ) )
return V_29 ;
return V_30 ;
}
static int F_19 ( struct V_19 * V_20 , unsigned int V_21 )
{
struct V_8 * V_9 = F_13 ( V_20 ) ;
int V_31 ;
V_31 = F_17 ( V_20 , V_21 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( V_31 == V_30 )
return F_9 ( V_9 , V_21 ) ;
return F_10 ( V_9 , V_21 ) ;
}
static void F_20 ( struct V_19 * V_20 , unsigned V_21 , int V_15 )
{
struct V_8 * V_9 = F_13 ( V_20 ) ;
F_11 ( V_9 , V_21 , V_15 ) ;
}
static int F_21 ( struct V_19 * V_20 , unsigned V_21 ,
unsigned V_31 )
{
struct V_8 * V_9 = F_13 ( V_20 ) ;
struct F_7 V_13 = {
. V_11 = F_5 ( V_21 ) ,
. V_15 = V_31 ,
} ;
int V_3 ;
V_3 = F_6 ( V_9 -> V_2 , V_32 ,
& V_13 , sizeof( V_13 ) ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_31 == V_27 )
F_15 ( V_21 , V_9 -> V_26 ) ;
else
F_14 ( V_21 , V_9 -> V_26 ) ;
return V_3 ;
}
static int F_22 ( struct V_19 * V_20 , unsigned V_21 )
{
return F_21 ( V_20 , V_21 , V_25 ) ;
}
static int F_23 ( struct V_19 * V_20 , unsigned V_21 ,
int V_15 )
{
struct V_8 * V_9 = F_13 ( V_20 ) ;
int V_3 ;
V_3 = F_11 ( V_9 , V_21 , V_15 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_21 ( V_20 , V_21 , V_27 ) ;
}
static int F_24 ( struct V_19 * V_20 , unsigned V_21 ,
unsigned V_33 )
{
struct V_8 * V_9 = F_13 ( V_20 ) ;
T_2 V_34 = F_25 ( V_33 ) ;
return F_6 ( V_9 -> V_2 , V_35 ,
& V_34 , sizeof( V_34 ) ) ;
}
static int F_26 ( struct V_8 * V_9 , unsigned V_11 ,
unsigned type , unsigned V_36 )
{
struct {
T_1 V_11 ;
T_3 type ;
T_1 V_36 ;
} V_37 V_13 = {
. V_11 = F_5 ( V_11 ) ,
. type = type ,
. V_36 = F_5 ( V_36 ) ,
} ;
return F_6 ( V_9 -> V_2 , V_38 ,
& V_13 , sizeof( V_13 ) ) ;
}
static void F_27 ( struct V_39 * V_40 )
{
struct V_19 * V_41 = F_28 ( V_40 ) ;
struct V_8 * V_9 = F_13 ( V_41 ) ;
int V_11 = F_29 ( V_40 ) ;
F_15 ( V_11 , V_9 -> V_42 ) ;
}
static void F_30 ( struct V_39 * V_40 )
{
struct V_19 * V_41 = F_28 ( V_40 ) ;
struct V_8 * V_9 = F_13 ( V_41 ) ;
int V_11 = F_29 ( V_40 ) ;
F_14 ( V_11 , V_9 -> V_42 ) ;
}
static int F_31 ( struct V_39 * V_40 , unsigned type )
{
struct V_19 * V_41 = F_28 ( V_40 ) ;
struct V_8 * V_9 = F_13 ( V_41 ) ;
int V_11 = F_29 ( V_40 ) ;
switch ( type ) {
case V_43 :
V_9 -> V_44 [ V_11 ] = V_45 ;
break;
case V_46 :
V_9 -> V_44 [ V_11 ] = V_47 ;
break;
case V_48 :
V_9 -> V_44 [ V_11 ] = V_49 ;
break;
case V_50 :
V_9 -> V_44 [ V_11 ] = V_51 ;
break;
case V_52 :
V_9 -> V_44 [ V_11 ] = V_53 ;
break;
default:
return - V_54 ;
}
return 0 ;
}
static void F_32 ( struct V_39 * V_40 )
{
struct V_19 * V_41 = F_28 ( V_40 ) ;
struct V_8 * V_9 = F_13 ( V_41 ) ;
F_33 ( & V_9 -> V_55 ) ;
}
static void F_34 ( struct V_39 * V_40 )
{
struct V_19 * V_41 = F_28 ( V_40 ) ;
struct V_8 * V_9 = F_13 ( V_41 ) ;
int V_11 = F_29 ( V_40 ) ;
int V_56 , V_57 ;
unsigned type ;
int V_3 ;
V_56 = F_18 ( V_11 , V_9 -> V_58 ) ;
V_57 = F_18 ( V_11 , V_9 -> V_42 ) ;
if ( V_56 != V_57 ) {
if ( V_57 ) {
type = V_9 -> V_44 [ V_11 ] & V_59 ;
F_15 ( V_11 , V_9 -> V_58 ) ;
} else {
type = V_60 ;
F_14 ( V_11 , V_9 -> V_58 ) ;
}
V_3 = F_26 ( V_9 , V_11 , type , 0 ) ;
if ( V_3 )
F_35 ( V_9 -> V_61 . V_62 , L_1 ) ;
}
F_36 ( & V_9 -> V_55 ) ;
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
} V_37 * V_66 = V_64 ;
struct V_8 * V_9 = F_38 ( V_2 ) ;
if ( V_5 < sizeof( * V_66 ) ) {
F_35 ( V_9 -> V_61 . V_62 , L_2 ) ;
return;
}
V_11 = F_3 ( V_66 -> V_11 ) ;
if ( V_11 >= V_9 -> V_61 . V_67 ) {
F_35 ( V_9 -> V_61 . V_62 , L_3 , V_11 ) ;
return;
}
V_65 = F_39 ( V_9 -> V_61 . V_68 , V_11 ) ;
if ( ! V_65 ) {
F_35 ( V_9 -> V_61 . V_62 , L_4 , V_11 ) ;
return;
}
switch ( V_9 -> V_44 [ V_11 ] ) {
case V_51 :
if ( V_66 -> V_15 )
F_40 ( V_65 ) ;
break;
case V_53 :
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
struct V_69 * V_70 = & V_2 -> V_70 ;
int V_71 ;
int V_3 ;
V_71 = F_1 ( V_2 ) ;
if ( V_71 < 0 ) {
F_35 ( V_70 , L_5 , V_71 ) ;
return V_71 ;
}
if ( V_71 > V_72 ) {
V_71 = V_72 ;
F_42 ( V_70 , L_6 , V_72 ) ;
}
V_9 = F_43 ( & V_2 -> V_70 , sizeof( * V_9 ) , V_73 ) ;
if ( ! V_9 )
return - V_74 ;
F_44 ( & V_9 -> V_55 ) ;
V_9 -> V_2 = V_2 ;
V_9 -> V_61 . V_75 = L_7 ;
V_9 -> V_61 . V_62 = V_70 ;
V_9 -> V_61 . V_76 = V_77 ;
V_9 -> V_61 . V_78 = - 1 ;
V_9 -> V_61 . V_67 = V_71 ;
V_9 -> V_61 . V_79 = true ;
V_9 -> V_61 . V_80 = true ;
V_9 -> V_61 . V_81 = F_20 ;
V_9 -> V_61 . V_82 = F_19 ;
V_9 -> V_61 . V_83 = F_12 ;
V_9 -> V_61 . free = F_16 ;
V_9 -> V_61 . V_84 = F_17 ;
V_9 -> V_61 . V_85 = F_22 ;
V_9 -> V_61 . V_86 = F_23 ;
V_9 -> V_61 . V_87 = F_24 ;
F_45 ( V_2 , V_9 ) ;
V_3 = F_46 ( & V_9 -> V_61 , V_9 ) ;
if ( V_3 < 0 ) {
F_35 ( V_70 , L_8 , V_3 ) ;
goto V_88;
}
V_3 = F_47 ( & V_9 -> V_61 , & V_89 , 0 ,
V_90 , V_91 ) ;
if ( V_3 < 0 ) {
F_35 ( V_70 , L_9 , V_3 ) ;
goto V_92;
}
V_3 = F_48 ( V_2 , V_93 ,
F_37 ) ;
if ( V_3 ) {
F_35 ( V_70 , L_10 , V_3 ) ;
goto V_92;
}
return 0 ;
V_92:
F_49 ( & V_9 -> V_61 ) ;
V_88:
return V_3 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_38 ( V_2 ) ;
F_51 ( V_2 , V_93 ) ;
F_49 ( & V_9 -> V_61 ) ;
return 0 ;
}
