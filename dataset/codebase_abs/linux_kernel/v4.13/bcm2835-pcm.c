static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ) ;
F_3 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
void F_4 ( struct V_4 * V_5 )
{
unsigned int V_6 = 0 ;
int V_7 = 0 ;
F_2 ( L_2 , V_5 ,
V_5 ? V_5 -> V_8 : 0 ) ;
if ( V_5 -> V_9 )
V_6 = F_5 ( V_5 ) ;
if ( V_5 -> V_10 ) {
if ( ( V_5 -> V_11 / V_5 -> V_10 ) !=
( ( V_5 -> V_11 + V_6 ) / V_5 -> V_10 ) )
V_7 = 1 ;
}
F_6 ( L_3 ,
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
F_9 ( L_4 ) ;
}
}
static int F_10 (
struct V_16 * V_8 , int V_17 )
{
struct V_18 * V_19 = F_11 ( V_8 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_4 * V_5 ;
int V_20 ;
int V_21 ;
if ( F_12 ( & V_19 -> V_22 ) ) {
F_13 ( L_5 ) ;
return - V_23 ;
}
F_2 ( L_6 , V_8 -> V_24 ) ;
V_20 = V_8 -> V_24 ;
if ( V_17 && V_19 -> V_25 ) {
V_21 = - V_26 ;
goto V_27;
} else if ( ! V_17 && ( V_19 -> V_25 & ( 1 << V_20 ) ) ) {
V_21 = - V_26 ;
goto V_27;
}
if ( V_20 >= V_28 ) {
F_13
( L_7 ,
V_20 , V_28 ) ;
V_21 = - V_29 ;
goto V_27;
}
if ( ! ( V_19 -> V_30 & ( 1 << V_20 ) ) ) {
F_13 ( L_8 , V_20 ) ;
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
F_15 ( & V_5 -> V_34 ) ;
V_21 = F_16 ( V_5 ) ;
if ( V_21 ) {
F_3 ( V_5 ) ;
goto V_27;
}
V_2 -> V_3 = V_5 ;
V_2 -> V_35 = F_1 ;
if ( V_17 ) {
V_2 -> V_36 = V_37 ;
} else {
V_19 -> V_38 = 0 ;
V_2 -> V_36 = V_39 ;
}
F_17 ( V_2 ,
0 ,
V_40 ,
16 ) ;
V_19 -> V_5 [ V_20 ] = V_5 ;
V_19 -> V_25 |= ( 1 << V_20 ) ;
V_5 -> V_9 = 1 ;
V_5 -> V_41 = 1 ;
V_27:
F_18 ( & V_19 -> V_22 ) ;
return V_21 ;
}
static int F_19 ( struct V_16 * V_8 )
{
return F_10 ( V_8 , 0 ) ;
}
static int F_20 ( struct V_16 * V_8 )
{
return F_10 ( V_8 , 1 ) ;
}
static int F_21 ( struct V_16 * V_8 )
{
struct V_18 * V_19 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
V_19 = F_11 ( V_8 ) ;
if ( F_12 ( & V_19 -> V_22 ) ) {
F_13 ( L_5 ) ;
return - V_23 ;
}
V_2 = V_8 -> V_2 ;
V_5 = V_2 -> V_3 ;
F_2 ( L_9 ) ;
if ( V_5 -> V_42 ) {
int V_21 ;
V_21 = F_22 ( V_5 ) ;
V_5 -> V_42 = 0 ;
if ( V_21 )
F_13 ( L_10 ) ;
}
V_5 -> V_10 = 0 ;
V_5 -> V_12 = 0 ;
if ( V_5 -> V_9 ) {
V_5 -> V_9 = 0 ;
F_23 ( V_5 ) ;
}
if ( V_5 -> V_19 )
V_5 -> V_19 -> V_5 [ V_5 -> V_20 ] = NULL ;
V_19 -> V_25 &= ~ ( 1 << V_8 -> V_24 ) ;
F_18 ( & V_19 -> V_22 ) ;
return 0 ;
}
static int F_24 ( struct V_16 * V_8 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_3 ;
int V_21 ;
V_21 = F_25 ( V_8 , F_26 ( V_44 ) ) ;
if ( V_21 < 0 ) {
F_13
( L_11 ) ;
return V_21 ;
}
V_5 -> V_45 = F_27 ( V_44 ) ;
V_5 -> V_46 = V_46 ( V_44 ) ;
V_5 -> V_47 = F_28 ( F_29 ( V_44 ) ) ;
return V_21 ;
}
static int F_30 ( struct V_16 * V_8 )
{
return F_31 ( V_8 ) ;
}
static int F_32 ( struct V_16 * V_8 )
{
struct V_18 * V_19 = F_11 ( V_8 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_3 ;
int V_45 ;
int V_21 ;
if ( F_12 ( & V_19 -> V_22 ) )
return - V_23 ;
if ( V_19 -> V_38 & V_48 )
V_45 = 0 ;
else
V_45 = V_5 -> V_45 ;
V_21 = F_33 ( V_5 , V_45 ,
V_5 -> V_46 ,
V_5 -> V_47 ) ;
if ( V_21 < 0 )
F_13 ( L_12 ) ;
F_34 ( V_5 ) ;
F_35 ( V_5 -> V_19 ) ;
memset ( & V_5 -> V_49 , 0 , sizeof( V_5 -> V_49 ) ) ;
V_5 -> V_49 . V_50 =
V_5 -> V_49 . V_51 =
F_36 ( V_8 ) ;
V_5 -> V_12 = F_36 ( V_8 ) ;
V_5 -> V_10 = F_37 ( V_8 ) ;
V_5 -> V_11 = 0 ;
F_6 ( L_13 ,
V_5 -> V_12 , V_5 -> V_10 ,
V_5 -> V_11 , V_2 -> V_52 ) ;
F_18 ( & V_19 -> V_22 ) ;
return 0 ;
}
static void F_38 ( struct V_16 * V_8 ,
struct V_53 * V_54 , T_1 V_55 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_3 ;
void * V_56 = ( void * ) ( V_8 -> V_2 -> V_57 + V_54 -> V_58 ) ;
int V_21 ;
V_21 = F_39 ( V_5 , V_55 , V_56 ) ;
if ( V_21 )
F_13 ( L_14 , V_21 ) ;
}
static int F_40 ( struct V_16 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_3 ;
struct V_53 * V_49 = & V_5 -> V_49 ;
V_49 -> V_59 = V_2 -> V_36 . V_60 ;
return F_41 ( V_8 , V_49 ,
F_38 ) ;
}
static int F_42 ( struct V_16 * V_8 , int V_61 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_3 ;
int V_21 = 0 ;
switch ( V_61 ) {
case V_62 :
F_6 ( L_15 ,
V_5 -> V_42 ) ;
if ( ! V_5 -> V_42 ) {
V_21 = F_43 ( V_5 ) ;
if ( ! V_21 ) {
V_5 -> V_49 . V_63 =
V_5 -> V_49 . V_64 =
F_44 ( V_2 ,
V_5 -> V_11 ) ;
V_8 -> V_65 -> V_66 ( V_8 ) ;
V_5 -> V_42 = 1 ;
V_5 -> V_41 = 1 ;
} else {
F_13 ( L_16 , V_21 ) ;
}
}
break;
case V_67 :
F_6
( L_17 ,
V_5 -> V_42 , V_2 -> V_14 -> V_68 == V_69 ) ;
if ( V_2 -> V_14 -> V_68 == V_69 ) {
F_2 ( L_18 ) ;
V_5 -> V_41 = 1 ;
} else {
F_2 ( L_19 ) ;
V_5 -> V_41 = 0 ;
}
if ( V_5 -> V_42 ) {
V_21 = F_22 ( V_5 ) ;
if ( V_21 != 0 )
F_13 ( L_20 , V_21 ) ;
V_5 -> V_42 = 0 ;
}
break;
default:
V_21 = - V_70 ;
}
return V_21 ;
}
static T_2
F_45 ( struct V_16 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_3 ;
F_6 ( L_21 , 0 ,
F_7 ( V_2 , V_2 -> V_14 -> V_15 ) ,
F_7 ( V_2 , V_2 -> V_71 -> V_72 ) ,
V_5 -> V_11 ) ;
return F_46 ( V_8 ,
& V_5 -> V_49 ,
V_5 -> V_11 ) ;
}
static int F_47 ( struct V_16 * V_8 ,
unsigned int V_61 , void * V_73 )
{
int V_74 = F_48 ( V_8 , V_61 , V_73 ) ;
F_2 ( L_22 , V_8 ,
V_61 , V_73 , V_73 ? * ( unsigned * ) V_73 : 0 , V_74 ) ;
return V_74 ;
}
int F_49 ( struct V_18 * V_19 , T_3 V_75 )
{
struct V_76 * V_77 ;
int V_21 ;
F_50 ( & V_19 -> V_22 ) ;
if ( F_12 ( & V_19 -> V_22 ) ) {
F_13 ( L_5 ) ;
return - V_23 ;
}
V_21 = F_51 ( V_19 -> V_78 , L_23 , 0 , V_75 , 0 , & V_77 ) ;
if ( V_21 < 0 )
goto V_27;
V_77 -> V_3 = V_19 ;
strcpy ( V_77 -> V_79 , L_23 ) ;
V_19 -> V_77 = V_77 ;
V_19 -> V_80 = V_81 ;
V_19 -> V_82 = F_52 ( 0 ) ;
V_19 -> V_83 = V_84 ;
F_53 ( V_77 , V_85 ,
& V_86 ) ;
F_54 ( V_77 , V_87 ,
F_55 ( V_32 ) ,
V_39 . V_60 ,
V_39 . V_60 ) ;
V_27:
F_18 ( & V_19 -> V_22 ) ;
return 0 ;
}
int F_56 ( struct V_18 * V_19 )
{
struct V_76 * V_77 ;
int V_21 ;
if ( F_12 ( & V_19 -> V_22 ) ) {
F_13 ( L_5 ) ;
return - V_23 ;
}
V_21 = F_51 ( V_19 -> V_78 , L_23 , 1 , 1 , 0 , & V_77 ) ;
if ( V_21 < 0 )
goto V_27;
V_77 -> V_3 = V_19 ;
strcpy ( V_77 -> V_79 , L_24 ) ;
V_19 -> V_88 = V_77 ;
F_53 ( V_77 , V_85 ,
& V_89 ) ;
F_54 ( V_77 , V_87 ,
F_55 ( V_32 ) ,
V_37 . V_60 , V_37 . V_60 ) ;
V_27:
F_18 ( & V_19 -> V_22 ) ;
return 0 ;
}
int F_57 ( struct V_18 * V_19 ,
const char * V_79 ,
enum V_90 V_91 ,
T_3 V_75 )
{
struct V_76 * V_77 ;
int V_21 ;
F_50 ( & V_19 -> V_22 ) ;
V_21 = F_51 ( V_19 -> V_78 , V_79 , 0 , V_75 ,
0 , & V_77 ) ;
if ( V_21 )
return V_21 ;
V_77 -> V_3 = V_19 ;
strcpy ( V_77 -> V_79 , V_79 ) ;
V_19 -> V_77 = V_77 ;
V_19 -> V_80 = V_91 ;
V_19 -> V_82 = F_52 ( 0 ) ;
V_19 -> V_83 = V_84 ;
F_53 ( V_77 , V_85 ,
& V_86 ) ;
F_54 (
V_77 ,
V_87 ,
F_55 ( V_32 ) ,
V_39 . V_60 ,
V_39 . V_60 ) ;
return 0 ;
}
