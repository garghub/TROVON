static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_7 ;
struct V_10 * V_11 ;
int V_12 ;
unsigned int V_13 ;
unsigned int V_14 ;
T_1 V_15 ;
T_1 V_16 , V_17 ;
V_11 = F_2 ( V_9 -> V_18 , V_2 ) ;
V_13 = F_3 ( V_2 ) ;
V_14 = V_6 -> V_19 * V_13 ;
V_15 = V_4 -> V_20 + V_14 ;
if ( V_2 -> V_21 == V_22 ) {
V_16 = V_15 ;
V_17 = V_11 -> V_23 ;
V_12 = V_11 -> V_24 ;
} else {
V_16 = V_11 -> V_25 ;
V_17 = V_15 ;
V_12 = V_11 -> V_26 ;
}
if ( ! F_4 ( F_5 ( V_12 ) ,
F_6 ( V_12 ) ) )
return;
if ( F_7 ( F_5 ( V_12 ) , F_6 ( V_12 ) ) ) {
F_8 ( V_27 L_1 ) ;
return;
}
F_9 ( V_13 & 15 ) ;
F_10 ( F_5 ( V_12 ) , F_6 ( V_12 ) ,
V_16 , V_17 , V_13 ) ;
V_6 -> V_19 ++ ;
if ( F_11 ( V_6 -> V_19 >= V_4 -> V_28 ) )
V_6 -> V_19 = 0 ;
}
static T_2 F_12 ( int V_29 , void * V_30 )
{
struct V_31 * V_32 = V_30 ;
struct V_8 * V_4 = V_32 -> V_7 ;
struct V_5 * V_6 ;
unsigned int V_33 ;
int V_34 , V_35 = V_36 ;
for ( V_34 = 0 ; V_34 < 2 ; ++ V_34 ) {
struct V_1 * V_2 = V_32 -> V_37 [ V_34 ] . V_2 ;
struct V_10 * V_38 =
F_2 ( V_4 -> V_18 , V_2 ) ;
T_3 V_12 ;
unsigned int V_39 ;
if ( V_2 == V_22 )
V_12 = V_38 -> V_24 ;
else
V_12 = V_38 -> V_26 ;
V_33 = V_38 -> V_40 ( V_4 -> V_18 ) ;
if ( ! V_12 )
continue;
if ( F_11 ( V_33 & ( 1 << V_34 ) ) &&
V_2 -> V_4 &&
F_13 ( V_2 ) ) {
F_14 ( V_32 -> V_41 , L_2 ) ;
F_15 ( V_2 , V_42 ) ;
V_35 = V_43 ;
}
V_39 = F_16 ( F_5 ( V_12 ) ,
F_6 ( V_12 ) ) ;
if ( V_39 & 1 ) {
V_35 = V_43 ;
if ( F_17 ( V_2 -> V_4 &&
F_13 ( V_2 ) ) ) {
F_18 ( V_2 ) ;
F_14 ( V_32 -> V_41 , L_3 ,
F_19 ( F_5 ( V_12 ) ,
F_6 ( V_12 ) ) ,
F_20 ( F_5 ( V_12 ) ,
F_6 ( V_12 ) ) ) ;
V_6 = V_2 -> V_4 -> V_7 ;
F_21 ( & V_6 -> V_44 ) ;
F_1 ( V_2 ) ;
F_22 ( & V_6 -> V_44 ) ;
}
}
if ( F_11 ( V_39 & ~ 7 ) ) {
if ( V_39 & ( 1 << 3 ) )
F_8 ( V_45
L_4 ,
V_12 ) ;
if ( V_39 & ( 1 << 4 ) )
F_8 ( V_45
L_5 ,
V_12 ) ;
if ( V_39 & 0x1e0 )
F_8 ( V_45
L_6
L_7 ,
V_12 , V_39 >> 5 ) ;
}
}
return V_35 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_4 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_7 ;
struct V_10 * V_11 ;
unsigned long V_46 ;
int V_47 ;
T_3 V_48 ;
V_11 = F_2 ( V_9 -> V_18 , V_2 ) ;
F_24 ( & V_6 -> V_44 , V_46 ) ;
if ( V_2 -> V_21 == V_22 ) {
V_47 = 1 ;
V_48 = V_11 -> V_24 ;
} else {
V_47 = 0 ;
V_48 = V_11 -> V_26 ;
}
F_25 ( F_5 ( V_48 ) , F_6 ( V_48 ) ,
1 ,
0 ,
V_47 ,
V_47 ^ 1 ,
0 ,
0 ,
0 ,
4 ,
- 1 ,
0 ,
0 ,
1 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
F_26 ( & V_6 -> V_44 , V_46 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_4 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_7 ;
struct V_10 * V_11 ;
unsigned long V_46 ;
T_3 V_12 ;
V_11 = F_2 ( V_9 -> V_18 , V_2 ) ;
if ( V_2 -> V_21 == V_22 )
V_12 = V_11 -> V_24 ;
else
V_12 = V_11 -> V_26 ;
F_28 ( F_5 ( V_12 ) ,
F_6 ( V_12 ) , 0 ) ;
F_24 ( & V_6 -> V_44 , V_46 ) ;
F_29 ( F_5 ( V_12 ) , F_6 ( V_12 ) ) ;
F_26 ( & V_6 -> V_44 , V_46 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , int V_49 )
{
struct V_8 * V_9 = V_2 -> V_7 ;
struct V_10 * V_11 ;
int V_35 ;
V_11 = F_2 ( V_9 -> V_18 , V_2 ) ;
V_35 = V_11 -> V_50 ( V_2 , V_49 , 0 ) ;
if ( V_35 < 0 )
return V_35 ;
switch ( V_49 ) {
case V_51 :
case V_52 :
case V_53 :
V_35 = F_23 ( V_2 ) ;
break;
case V_54 :
case V_55 :
case V_56 :
V_35 = F_27 ( V_2 ) ;
break;
default:
V_35 = - V_57 ;
}
if ( V_35 < 0 )
return V_35 ;
return V_11 -> V_50 ( V_2 , V_49 , 1 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_4 -> V_7 ;
V_6 -> V_19 = 0 ;
return 0 ;
}
static T_4 F_32 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_7 ;
struct V_10 * V_11 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_46 ;
unsigned int V_58 ;
T_1 V_59 ;
V_11 = F_2 ( V_9 -> V_18 , V_2 ) ;
F_24 ( & V_6 -> V_44 , V_46 ) ;
if ( V_2 -> V_21 == V_22 )
V_59 = F_19 ( F_5 ( V_11 -> V_24 ) ,
F_6 ( V_11 -> V_24 ) ) ;
else
V_59 = F_20 ( F_5 ( V_11 -> V_26 ) ,
F_6 ( V_11 -> V_26 ) ) ;
V_59 -= V_4 -> V_20 ;
F_26 ( & V_6 -> V_44 , V_46 ) ;
V_58 = F_33 ( V_4 , V_59 ) ;
if ( F_11 ( V_58 >= V_4 -> V_60 ) )
V_58 = 0 ;
return V_58 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_7 ;
struct V_10 * V_11 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
int V_35 ;
V_11 = F_2 ( V_9 -> V_18 , V_2 ) ;
F_35 ( V_2 , & V_61 ) ;
V_35 = F_36 ( V_4 , 0 ,
V_62 , 16 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_36 ( V_4 , 0 ,
V_63 , 16 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_37 ( V_4 ,
V_64 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_11 -> V_65 ) {
int V_66 ;
F_21 ( & V_11 -> V_44 ) ;
V_66 = V_11 -> V_66 ;
F_22 ( & V_11 -> V_44 ) ;
if ( V_66 != - 1 ) {
V_35 = F_38 ( V_4 ,
V_67 ,
V_66 , V_66 ) ;
if ( V_35 < 0 )
return V_35 ;
}
}
V_6 = F_39 ( sizeof( struct V_5 ) , V_68 ) ;
if ( V_6 == NULL )
return - V_69 ;
F_40 ( & V_6 -> V_44 ) ;
V_4 -> V_7 = V_6 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
F_42 ( V_6 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_70 * V_71 )
{
struct V_8 * V_9 = V_2 -> V_7 ;
struct V_10 * V_11 ;
int V_35 ;
V_35 = F_44 ( V_2 ,
F_45 ( V_71 ) ) ;
if ( V_35 < 0 ) {
F_8 ( V_45 L_8 ) ;
return V_35 ;
}
V_11 = F_2 ( V_9 -> V_18 , V_2 ) ;
if ( V_11 -> V_65 ) {
F_21 ( & V_11 -> V_44 ) ;
if ( V_11 -> V_66 == - 1 ||
! ( V_11 -> V_72 & ~ ( 1 << V_2 -> V_21 ) ) ) {
V_11 -> V_66 = F_46 ( V_71 ) ;
V_11 -> V_72 |= 1 << V_2 -> V_21 ;
} else if ( F_46 ( V_71 ) != V_11 -> V_66 ) {
F_47 ( V_2 ) ;
V_11 -> V_72 &= ~ ( 1 << V_2 -> V_21 ) ;
V_35 = - V_73 ;
}
F_22 ( & V_11 -> V_44 ) ;
}
return V_35 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_7 ;
struct V_10 * V_11 =
F_2 ( V_9 -> V_18 , V_2 ) ;
F_21 ( & V_11 -> V_44 ) ;
V_11 -> V_72 &= ~ ( 1 << V_2 -> V_21 ) ;
if ( ! V_11 -> V_72 )
V_11 -> V_66 = - 1 ;
F_22 ( & V_11 -> V_44 ) ;
return F_47 ( V_2 ) ;
}
static void F_49 ( struct V_31 * V_32 )
{
struct V_8 * V_4 = V_32 -> V_7 ;
struct V_10 * V_38 =
F_2 ( V_4 -> V_18 ,
V_32 -> V_37 [ V_22 ] . V_2 ) ;
F_50 ( V_38 -> V_29 , V_32 ) ;
F_51 ( V_32 ) ;
}
static int F_52 ( struct V_8 * V_4 )
{
struct V_74 * V_75 = V_4 -> V_75 -> V_74 ;
struct V_31 * V_32 = V_4 -> V_32 ;
struct V_10 * V_38 ;
int V_76 ;
V_38 = F_2 ( V_4 -> V_18 ,
V_32 -> V_37 [ V_22 ] . V_2 ) ;
if ( ! V_75 -> V_41 -> V_77 )
V_75 -> V_41 -> V_77 = & V_78 ;
if ( ! V_75 -> V_41 -> V_79 )
V_75 -> V_41 -> V_79 = F_53 ( 32 ) ;
if ( V_38 -> V_26 ) {
F_29 ( F_5 ( V_38 -> V_26 ) ,
F_6 ( V_38 -> V_26 ) ) ;
F_16 ( F_5 ( V_38 -> V_26 ) ,
F_6 ( V_38 -> V_26 ) ) ;
}
if ( V_38 -> V_24 ) {
F_29 ( F_5 ( V_38 -> V_24 ) ,
F_6 ( V_38 -> V_24 ) ) ;
F_16 ( F_5 ( V_38 -> V_24 ) ,
F_6 ( V_38 -> V_24 ) ) ;
}
V_76 = F_54 ( V_38 -> V_29 , F_12 , V_80 ,
L_9 , V_32 ) ;
if ( V_76 ) {
F_8 ( V_27 L_10 ) ;
return V_76 ;
}
V_76 = F_55 ( V_32 ,
V_81 ,
V_75 -> V_41 ,
V_82 ,
V_83 ) ;
if ( V_76 )
F_8 ( V_45 L_11 ) ;
F_40 ( & V_38 -> V_44 ) ;
V_38 -> V_72 = 0 ;
V_38 -> V_66 = - 1 ;
return 0 ;
}
static int T_5 F_56 ( struct V_84 * V_85 )
{
return F_57 ( & V_85 -> V_41 , & V_86 ) ;
}
static int T_6 F_58 ( struct V_84 * V_85 )
{
F_59 ( & V_85 -> V_41 ) ;
return 0 ;
}
