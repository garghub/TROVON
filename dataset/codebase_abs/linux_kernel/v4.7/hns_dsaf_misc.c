static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
if ( V_2 -> V_5 )
F_2 ( V_2 -> V_5 , V_3 , V_4 ) ;
else
F_3 ( V_2 -> V_6 , V_3 , V_4 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_7 ;
if ( V_2 -> V_5 )
V_7 = F_5 ( V_2 -> V_5 , V_3 ) ;
else
V_7 = F_6 ( V_2 -> V_6 , V_3 ) ;
return V_7 ;
}
void F_7 ( struct V_8 * V_9 , int V_10 ,
T_2 V_11 , int V_12 )
{
int V_13 = 0 ;
T_3 V_14 ;
if ( ! V_9 ) {
F_8 ( L_1 ) ;
return;
}
if ( ! V_9 -> V_15 ) {
F_9 ( V_9 -> V_16 , L_2 ,
V_9 -> V_17 ) ;
return;
}
if ( V_11 == V_18 )
V_13 = 1 ;
V_14 = V_9 -> V_19 ;
if ( V_10 ) {
F_10 ( V_14 , V_20 , V_10 ) ;
F_11 ( V_14 , V_21 ,
V_22 , V_13 ) ;
F_10 ( V_14 , V_23 , V_12 ) ;
if ( V_14 != V_9 -> V_19 ) {
F_2 ( V_9 -> V_15 ,
V_9 -> V_24 , V_14 ) ;
V_9 -> V_19 = V_14 ;
}
} else {
F_2 ( V_9 -> V_15 , V_9 -> V_24 ,
V_25 ) ;
V_9 -> V_19 = V_25 ;
}
}
void F_12 ( struct V_8 * V_9 )
{
if ( ! V_9 || ! V_9 -> V_15 )
return;
F_2 ( V_9 -> V_15 , V_9 -> V_24 ,
V_25 ) ;
V_9 -> V_19 = V_25 ;
}
int F_13 ( struct V_8 * V_9 ,
enum V_26 V_27 )
{
switch ( V_27 ) {
case V_28 :
V_9 -> V_19 =
F_5 ( V_9 -> V_15 ,
V_9 -> V_24 ) ;
F_10 ( V_9 -> V_19 , V_29 ,
V_30 ) ;
F_2 ( V_9 -> V_15 , V_9 -> V_24 ,
V_9 -> V_19 ) ;
return 2 ;
case V_31 :
F_10 ( V_9 -> V_19 , V_29 ,
V_25 ) ;
F_2 ( V_9 -> V_15 , V_9 -> V_24 ,
V_9 -> V_19 ) ;
break;
default:
break;
}
return 0 ;
}
void F_14 ( struct V_1 * V_2 , T_1 V_4 )
{
T_1 V_32 ;
T_1 V_33 ;
if ( ! V_4 ) {
V_32 = V_34 ;
V_33 = V_35 ;
} else {
V_32 = V_36 ;
V_33 = V_37 ;
}
F_1 ( V_2 , V_32 , V_38 ) ;
F_1 ( V_2 , V_33 , V_38 ) ;
}
void F_15 ( struct V_1 * V_2 , T_1 V_39 , T_1 V_4 )
{
T_1 V_40 = 0 ;
T_1 V_41 ;
if ( V_39 >= V_42 )
return;
V_40 |= V_38 ;
V_40 |= 0x2082082 << V_2 -> V_9 [ V_39 ] -> V_43 ;
if ( V_4 == 0 )
V_41 = V_44 ;
else
V_41 = V_45 ;
F_1 ( V_2 , V_41 , V_40 ) ;
}
void F_16 ( struct V_1 * V_2 ,
T_1 V_39 , T_1 V_4 )
{
T_1 V_40 = 0 ;
T_1 V_41 ;
if ( V_39 >= V_42 )
return;
V_40 |= V_46
<< V_2 -> V_9 [ V_39 ] -> V_43 ;
if ( V_4 == 0 )
V_41 = V_44 ;
else
V_41 = V_45 ;
F_1 ( V_2 , V_41 , V_40 ) ;
}
void F_17 ( struct V_1 * V_2 , T_1 V_39 , T_1 V_4 )
{
T_1 V_47 ;
T_1 V_48 ;
T_1 V_43 ;
if ( V_39 >= V_49 )
return;
if ( ! F_18 ( V_2 ) ) {
V_47 = 0x1 << V_39 ;
V_43 = V_2 -> V_9 [ V_39 ] -> V_43 ;
if ( F_19 ( V_2 -> V_50 ) )
V_48 = 0x1041041 << V_43 ;
else
V_48 = 0x2082082 << V_43 ;
if ( V_4 == 0 ) {
F_1 ( V_2 , V_51 ,
V_47 ) ;
F_1 ( V_2 , V_52 ,
V_48 ) ;
} else {
F_1 ( V_2 , V_53 ,
V_48 ) ;
F_1 ( V_2 , V_54 ,
V_47 ) ;
}
} else {
V_47 = 0x15540 << V_2 -> V_55 ;
V_48 = 0x100 << V_2 -> V_55 ;
if ( V_4 == 0 ) {
F_1 ( V_2 , V_51 ,
V_47 ) ;
F_1 ( V_2 , V_56 ,
V_48 ) ;
} else {
F_1 ( V_2 , V_54 ,
V_47 ) ;
F_1 ( V_2 , V_57 ,
V_48 ) ;
}
}
}
void F_20 ( struct V_1 * V_2 , T_1 V_39 , T_1 V_4 )
{
T_1 V_40 = 0 ;
T_1 V_41 ;
V_40 |= V_38 << V_2 -> V_9 [ V_39 ] -> V_43 ;
if ( V_4 == 0 )
V_41 = V_56 ;
else
V_41 = V_57 ;
F_1 ( V_2 , V_41 , V_40 ) ;
}
void F_21 ( struct V_58 * V_59 , T_1 V_4 )
{
struct V_1 * V_2 = V_59 -> V_2 ;
T_1 V_40 ;
T_1 V_41 ;
if ( ! F_18 ( V_2 ) ) {
V_40 = V_38 ;
if ( V_4 == 0 )
V_41 = V_60 ;
else
V_41 = V_61 ;
} else {
V_40 = 0x100 << V_2 -> V_55 ;
if ( V_4 == 0 )
V_41 = V_56 ;
else
V_41 = V_57 ;
}
F_1 ( V_2 , V_41 , V_40 ) ;
}
T_4 F_22 ( struct V_8 * V_9 )
{
T_1 V_62 ;
T_1 V_3 ;
bool V_63 = F_19 ( V_9 -> V_2 -> V_50 ) ;
int V_17 = V_9 -> V_17 ;
T_4 V_64 ;
if ( V_63 ) {
if ( F_18 ( V_9 -> V_2 ) )
return V_65 ;
if ( V_17 >= 0 && V_17 <= 3 )
V_3 = V_66 ;
else
V_3 = V_67 ;
} else{
if ( ! F_18 ( V_9 -> V_2 ) && V_17 <= 3 )
V_3 = V_68 ;
else
V_3 = V_69 ;
}
V_62 = F_4 ( V_9 -> V_2 , V_3 ) ;
if ( F_23 ( V_62 , V_9 -> V_70 ) )
V_64 = V_71 ;
else
V_64 = V_65 ;
return V_64 ;
}
int F_24 ( struct V_8 * V_9 , int * V_72 )
{
if ( ! V_9 -> V_15 )
return - V_73 ;
* V_72 = ! F_5 ( V_9 -> V_15 , V_9 -> V_24
+ V_74 ) ;
return 0 ;
}
int F_25 ( struct V_8 * V_9 , T_3 V_75 )
{
T_3 * V_76 = ( T_3 * ) V_9 -> V_77 +
( V_9 -> V_17 <= 3 ? 0x00280000 : 0x00200000 ) ;
const T_3 V_78 [] = {
0 ,
1 ,
2 ,
3 ,
2 ,
3 ,
0 ,
1
} ;
#define F_26 ( T_5 , V_3 ) ((0x4080 + (reg) * 0x0002 + (lane) * 0x0200) * 2)
T_6 V_79 = F_26 ( V_78 [ V_9 -> V_17 ] , 0 ) ;
int V_72 ;
int V_7 = F_24 ( V_9 , & V_72 ) ;
if ( ! V_9 -> V_80 ) {
if ( V_7 )
F_27 ( L_3 ) ;
else
if ( ! V_72 )
F_27 ( L_4 ) ;
}
if ( V_9 -> V_81 ) {
T_1 V_82 = F_5 ( V_9 -> V_81 , V_79 ) ;
F_11 ( V_82 , 1ull << 10 , 10 , ! ! V_75 ) ;
F_2 ( V_9 -> V_81 , V_79 , V_82 ) ;
} else {
F_28 ( V_76 , V_79 , 1ull << 10 , 10 , ! ! V_75 ) ;
}
return 0 ;
}
