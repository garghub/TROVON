static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ) ;
if ( V_2 -> V_3 )
F_3 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
void F_4 ( struct V_4 * V_5 )
{
unsigned int V_6 = 0 ;
int V_7 = 0 ;
F_2 ( L_2 ) ;
F_2 ( L_3 , V_5 ,
V_5 ? V_5 -> V_8 : 0 ) ;
if ( V_5 -> V_9 )
V_6 = F_5 ( V_5 ) ;
if ( V_5 -> V_10 ) {
if ( ( V_5 -> V_11 / V_5 -> V_10 ) !=
( ( V_5 -> V_11 + V_6 ) / V_5 -> V_10 ) )
V_7 = 1 ;
}
F_6 ( L_4 ,
V_5 -> V_11 ,
V_6 ,
V_5 -> V_12 ,
( int ) ( V_5 -> V_10 * V_5 -> V_8 -> V_2 -> V_13 ) ,
F_7 ( V_5 -> V_8 -> V_2 , V_5 -> V_8 -> V_2 -> V_14 -> V_15 ) ,
V_7 ) ;
if ( V_5 -> V_12 ) {
V_5 -> V_11 += V_6 & ~ ( 1 << 30 ) ;
V_5 -> V_11 %= V_5 -> V_12 ;
}
if ( V_5 -> V_8 ) {
if ( V_7 )
F_8 ( V_5 -> V_8 ) ;
} else {
F_9 ( L_5 ) ;
}
F_2 ( L_6 ) ;
}
static int F_10 (
struct V_16 * V_8 , int V_17 )
{
struct V_18 * V_19 = F_11 ( V_8 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_4 * V_5 ;
int V_20 ;
int V_21 ;
F_2 ( L_7 , V_8 -> V_22 ) ;
if ( F_12 ( & V_19 -> V_23 ) ) {
F_13 ( L_8 ) ;
return - V_24 ;
}
F_2 ( L_9 , V_8 -> V_22 ) ;
V_20 = V_8 -> V_22 ;
if ( V_17 && V_19 -> V_25 ) {
V_21 = - V_26 ;
goto V_27;
} else if ( ! V_17 && ( V_19 -> V_25 & ( 1 << V_20 ) ) ) {
V_21 = - V_26 ;
goto V_27;
}
if ( V_20 >= V_28 ) {
F_13
( L_10 ,
V_20 , V_28 ) ;
V_21 = - V_29 ;
goto V_27;
}
if ( ! ( V_19 -> V_30 & ( 1 << V_20 ) ) ) {
F_13 ( L_11 , V_20 ) ;
V_21 = - V_31 ;
goto V_27;
}
V_5 = F_14 ( sizeof( * V_5 ) , V_32 ) ;
if ( ! V_5 ) {
V_21 = - V_33 ;
goto V_27;
}
V_5 -> V_19 = V_19 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_20 = V_20 ;
F_15 ( & V_5 -> V_34 , 0 ) ;
F_15 ( & V_5 -> V_35 , 0 ) ;
F_16 ( & V_5 -> V_36 ) ;
V_21 = F_17 ( V_5 ) ;
if ( V_21 ) {
F_3 ( V_5 ) ;
goto V_27;
}
V_2 -> V_3 = V_5 ;
V_2 -> V_37 = F_1 ;
if ( V_17 ) {
V_2 -> V_38 = V_39 ;
} else {
V_19 -> V_40 = 0 ;
V_2 -> V_38 = V_41 ;
}
F_18 ( V_2 ,
0 ,
V_42 ,
16 ) ;
V_19 -> V_5 [ V_20 ] = V_5 ;
V_19 -> V_25 |= ( 1 << V_20 ) ;
V_5 -> V_9 = 1 ;
V_5 -> V_43 = 1 ;
V_27:
F_19 ( & V_19 -> V_23 ) ;
F_2 ( L_12 , V_21 ) ;
return V_21 ;
}
static int F_20 ( struct V_16 * V_8 )
{
return F_10 ( V_8 , 0 ) ;
}
static int F_21 ( struct V_16 * V_8 )
{
return F_10 ( V_8 , 1 ) ;
}
static int F_22 ( struct V_16 * V_8 )
{
struct V_18 * V_19 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
F_2 ( L_2 ) ;
V_19 = F_11 ( V_8 ) ;
if ( F_12 ( & V_19 -> V_23 ) ) {
F_13 ( L_8 ) ;
return - V_24 ;
}
V_2 = V_8 -> V_2 ;
V_5 = V_2 -> V_3 ;
F_2 ( L_13 ) ;
if ( V_5 -> V_44 ) {
int V_21 ;
V_21 = F_23 ( V_5 ) ;
V_5 -> V_44 = 0 ;
if ( V_21 )
F_13 ( L_14 ) ;
}
V_5 -> V_10 = 0 ;
V_5 -> V_12 = 0 ;
if ( V_5 -> V_9 ) {
V_5 -> V_9 = 0 ;
F_24 ( V_5 ) ;
}
if ( V_5 -> V_19 )
V_5 -> V_19 -> V_5 [ V_5 -> V_20 ] = NULL ;
V_19 -> V_25 &= ~ ( 1 << V_8 -> V_22 ) ;
F_19 ( & V_19 -> V_23 ) ;
F_2 ( L_6 ) ;
return 0 ;
}
static int F_25 ( struct V_16 * V_8 ,
struct V_45 * V_46 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_3 ;
int V_21 ;
F_2 ( L_2 ) ;
V_21 = F_26 ( V_8 , F_27 ( V_46 ) ) ;
if ( V_21 < 0 ) {
F_13
( L_15 ) ;
return V_21 ;
}
V_5 -> V_47 = F_28 ( V_46 ) ;
V_5 -> V_48 = V_48 ( V_46 ) ;
V_5 -> V_49 = F_29 ( F_30 ( V_46 ) ) ;
F_2 ( L_6 ) ;
return V_21 ;
}
static int F_31 ( struct V_16 * V_8 )
{
F_2 ( L_2 ) ;
return F_32 ( V_8 ) ;
}
static int F_33 ( struct V_16 * V_8 )
{
struct V_18 * V_19 = F_11 ( V_8 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_3 ;
int V_47 ;
int V_21 ;
F_2 ( L_2 ) ;
if ( F_12 ( & V_19 -> V_23 ) )
return - V_24 ;
if ( V_19 -> V_40 & V_50 )
V_47 = 0 ;
else
V_47 = V_5 -> V_47 ;
V_21 = F_34 ( V_5 , V_47 ,
V_5 -> V_48 ,
V_5 -> V_49 ) ;
if ( V_21 < 0 ) {
F_13 ( L_16 ) ;
}
F_35 ( V_5 ) ;
F_36 ( V_5 -> V_19 ) ;
memset ( & V_5 -> V_51 , 0 , sizeof( V_5 -> V_51 ) ) ;
V_5 -> V_51 . V_52 =
V_5 -> V_51 . V_53 =
F_37 ( V_8 ) ;
V_5 -> V_12 = F_37 ( V_8 ) ;
V_5 -> V_10 = F_38 ( V_8 ) ;
V_5 -> V_11 = 0 ;
F_6 ( L_17 ,
V_5 -> V_12 , V_5 -> V_10 ,
V_5 -> V_11 , V_2 -> V_54 ) ;
F_19 ( & V_19 -> V_23 ) ;
F_2 ( L_6 ) ;
return 0 ;
}
static void F_39 ( struct V_16 * V_8 ,
struct V_55 * V_56 , T_1 V_57 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_3 ;
void * V_58 = ( void * ) ( V_8 -> V_2 -> V_59 + V_56 -> V_60 ) ;
int V_21 ;
V_21 = F_40 ( V_5 , V_57 , V_58 ) ;
if ( V_21 )
F_13 ( L_18 , V_21 ) ;
}
static int F_41 ( struct V_16 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_3 ;
struct V_55 * V_51 = & V_5 -> V_51 ;
V_51 -> V_61 = V_2 -> V_38 . V_62 ;
F_42 ( V_8 , V_51 ,
F_39 ) ;
return 0 ;
}
static int F_43 ( struct V_16 * V_8 , int V_63 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_3 ;
int V_21 = 0 ;
F_2 ( L_2 ) ;
switch ( V_63 ) {
case V_64 :
F_6 ( L_19 ,
V_5 -> V_44 ) ;
if ( ! V_5 -> V_44 ) {
V_21 = F_44 ( V_5 ) ;
if ( ! V_21 ) {
V_5 -> V_51 . V_65 =
V_5 -> V_51 . V_66 =
F_45 ( V_2 ,
V_5 -> V_11 ) ;
V_8 -> V_67 -> V_68 ( V_8 ) ;
V_5 -> V_44 = 1 ;
V_5 -> V_43 = 1 ;
} else {
F_13 ( L_20 , V_21 ) ;
}
}
break;
case V_69 :
F_6
( L_21 ,
V_5 -> V_44 , V_2 -> V_14 -> V_70 == V_71 ) ;
if ( V_2 -> V_14 -> V_70 == V_71 ) {
F_2 ( L_22 ) ;
V_5 -> V_43 = 1 ;
} else {
F_2 ( L_23 ) ;
V_5 -> V_43 = 0 ;
}
if ( V_5 -> V_44 ) {
V_21 = F_23 ( V_5 ) ;
if ( V_21 != 0 )
F_13 ( L_24 , V_21 ) ;
V_5 -> V_44 = 0 ;
}
break;
default:
V_21 = - V_72 ;
}
F_2 ( L_6 ) ;
return V_21 ;
}
static T_2
F_46 ( struct V_16 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_3 ;
F_2 ( L_2 ) ;
F_6 ( L_25 , 0 ,
F_7 ( V_2 , V_2 -> V_14 -> V_15 ) ,
F_7 ( V_2 , V_2 -> V_73 -> V_74 ) ,
V_5 -> V_11 ) ;
F_2 ( L_6 ) ;
return F_47 ( V_8 ,
& V_5 -> V_51 ,
V_5 -> V_11 ) ;
}
static int F_48 ( struct V_16 * V_8 ,
unsigned int V_63 , void * V_75 )
{
int V_76 = F_49 ( V_8 , V_63 , V_75 ) ;
F_2 ( L_26 , V_8 ,
V_63 , V_75 , V_75 ? * ( unsigned * ) V_75 : 0 , V_76 ) ;
return V_76 ;
}
int F_50 ( struct V_18 * V_19 )
{
struct V_77 * V_78 ;
int V_21 ;
F_2 ( L_2 ) ;
F_51 ( & V_19 -> V_23 ) ;
if ( F_12 ( & V_19 -> V_23 ) ) {
F_13 ( L_8 ) ;
return - V_24 ;
}
V_21 = F_52 ( V_19 -> V_79 , L_27 , 0 , V_28 , 0 , & V_78 ) ;
if ( V_21 < 0 )
goto V_27;
V_78 -> V_3 = V_19 ;
strcpy ( V_78 -> V_80 , L_27 ) ;
V_19 -> V_78 = V_78 ;
V_19 -> V_81 = V_82 ;
V_19 -> V_83 = F_53 ( 0 ) ;
V_19 -> V_84 = V_85 ;
F_54 ( V_78 , V_86 ,
& V_87 ) ;
F_55 ( V_78 , V_88 ,
F_56 ( V_32 ) ,
V_41 . V_62 ,
V_41 . V_62 ) ;
V_27:
F_19 ( & V_19 -> V_23 ) ;
F_2 ( L_6 ) ;
return 0 ;
}
int F_57 ( struct V_18 * V_19 )
{
struct V_77 * V_78 ;
int V_21 ;
F_2 ( L_2 ) ;
if ( F_12 ( & V_19 -> V_23 ) ) {
F_13 ( L_8 ) ;
return - V_24 ;
}
V_21 = F_52 ( V_19 -> V_79 , L_27 , 1 , 1 , 0 , & V_78 ) ;
if ( V_21 < 0 )
goto V_27;
V_78 -> V_3 = V_19 ;
strcpy ( V_78 -> V_80 , L_28 ) ;
V_19 -> V_89 = V_78 ;
F_54 ( V_78 , V_86 ,
& V_90 ) ;
F_55 ( V_78 , V_88 ,
F_56 ( V_32 ) ,
V_39 . V_62 , V_39 . V_62 ) ;
V_27:
F_19 ( & V_19 -> V_23 ) ;
F_2 ( L_6 ) ;
return 0 ;
}
