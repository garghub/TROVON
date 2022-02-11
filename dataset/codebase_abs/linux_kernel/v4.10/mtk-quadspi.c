static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_3 ;
switch ( V_3 -> V_4 ) {
case V_5 :
F_2 ( V_3 -> V_6 , V_1 -> V_7 +
V_8 ) ;
F_2 ( V_9 , V_1 -> V_7 +
V_10 ) ;
break;
case V_11 :
F_2 ( V_3 -> V_6 , V_1 -> V_7 +
V_8 ) ;
F_2 ( V_12 , V_1 -> V_7 +
V_13 ) ;
break;
case V_14 :
F_2 ( V_3 -> V_6 , V_1 -> V_7 +
V_15 ) ;
F_2 ( V_16 , V_1 -> V_7 +
V_13 ) ;
break;
default:
F_2 ( V_17 , V_1 -> V_7 +
V_13 ) ;
break;
}
}
static int F_3 ( struct V_1 * V_1 , T_1 V_18 )
{
int V_19 ;
T_1 V_20 = V_18 & 0x1f ;
F_2 ( V_18 , V_1 -> V_7 + V_21 ) ;
return F_4 ( V_1 -> V_7 + V_21 , V_19 ,
! ( V_19 & V_20 ) , 100 , 10000 ) ;
}
static int F_5 ( struct V_1 * V_1 , T_1 V_22 ,
T_1 * V_23 , int V_24 , T_1 * V_25 , int V_26 )
{
int V_27 = 1 + V_24 + V_26 ;
int V_28 , V_29 , V_30 ;
if ( V_27 > V_31 )
return - V_32 ;
F_2 ( V_27 * 8 , V_1 -> V_7 + V_33 ) ;
V_30 = V_34 - 1 ;
F_2 ( V_22 , V_1 -> V_7 + F_6 ( V_30 ) ) ;
V_30 -- ;
for ( V_28 = 0 ; V_28 < V_24 ; V_28 ++ , V_30 -- )
F_2 ( V_23 [ V_28 ] , V_1 -> V_7 + F_6 ( V_30 ) ) ;
while ( V_30 >= 0 ) {
F_2 ( 0 , V_1 -> V_7 + F_6 ( V_30 ) ) ;
V_30 -- ;
}
V_29 = F_3 ( V_1 , V_35 ) ;
if ( V_29 )
return V_29 ;
V_30 = V_26 - 1 ;
for ( V_28 = 0 ; V_28 < V_26 ; V_28 ++ , V_30 -- )
V_25 [ V_28 ] = F_7 ( V_1 -> V_7 + F_8 ( V_30 ) ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_1 , T_1 V_36 )
{
F_2 ( V_36 , V_1 -> V_7 + V_37 ) ;
F_2 ( 8 , V_1 -> V_7 + V_33 ) ;
return F_3 ( V_1 , V_38 ) ;
}
static int F_10 ( struct V_1 * V_1 )
{
T_1 V_19 ;
F_11 ( V_39 , V_1 -> V_7 + V_40 ) ;
return F_12 ( V_1 -> V_7 + V_40 , V_19 ,
0x01 == ( V_19 & 0x01 ) , 100 , 10000 ) ;
}
static int F_13 ( struct V_1 * V_1 )
{
T_1 V_19 ;
F_11 ( V_41 , V_1 -> V_7 + V_40 ) ;
return F_12 ( V_1 -> V_7 + V_40 , V_19 ,
V_41 == ( V_19 & 0x1 ) , 100 ,
10000 ) ;
}
static void F_14 ( struct V_1 * V_1 , T_2 V_42 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < 3 ; V_28 ++ ) {
F_2 ( V_42 & 0xff , V_1 -> V_7 + V_43 + V_28 * 4 ) ;
V_42 >>= 8 ;
}
F_2 ( V_42 & 0xff , V_1 -> V_7 + V_44 ) ;
}
static T_3 F_15 ( struct V_2 * V_3 , T_4 V_45 , T_5 V_46 ,
T_6 * V_47 )
{
int V_28 , V_29 ;
int V_42 = ( int ) V_45 ;
T_1 * V_48 = ( T_1 * ) V_47 ;
struct V_1 * V_1 = V_3 -> V_49 ;
F_1 ( V_1 ) ;
F_14 ( V_1 , V_42 ) ;
for ( V_28 = 0 ; V_28 < V_46 ; V_28 ++ ) {
V_29 = F_3 ( V_1 , V_50 ) ;
if ( V_29 < 0 )
return V_29 ;
V_48 [ V_28 ] = F_7 ( V_1 -> V_7 + V_51 ) ;
}
return V_46 ;
}
static int F_16 ( struct V_1 * V_1 ,
int V_42 , int V_46 , T_1 * V_52 )
{
int V_28 , V_29 ;
F_14 ( V_1 , V_42 ) ;
for ( V_28 = 0 ; V_28 < V_46 ; V_28 ++ ) {
F_2 ( * V_52 ++ , V_1 -> V_7 + V_53 ) ;
V_29 = F_3 ( V_1 , V_54 ) ;
if ( V_29 < 0 )
return V_29 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_1 , int V_42 ,
const T_1 * V_48 )
{
int V_28 , V_55 , V_52 ;
F_14 ( V_1 , V_42 ) ;
V_55 = 0 ;
for ( V_28 = 0 ; V_28 < V_56 ; V_28 += 4 ) {
V_52 = V_48 [ V_55 + 3 ] << 24 | V_48 [ V_55 + 2 ] << 16 |
V_48 [ V_55 + 1 ] << 8 | V_48 [ V_55 ] ;
V_55 += 4 ;
F_11 ( V_52 , V_1 -> V_7 + V_57 ) ;
}
return F_3 ( V_1 , V_58 ) ;
}
static T_3 F_18 ( struct V_2 * V_3 , T_4 V_59 , T_5 V_27 ,
const T_6 * V_48 )
{
int V_29 ;
struct V_1 * V_1 = V_3 -> V_49 ;
T_5 V_28 ;
V_29 = F_10 ( V_1 ) ;
if ( V_29 < 0 ) {
F_19 ( V_1 -> V_60 , L_1 ) ;
return V_29 ;
}
for ( V_28 = 0 ; V_28 + V_56 <= V_27 ; V_28 += V_56 ) {
V_29 = F_17 ( V_1 , V_59 , V_48 ) ;
if ( V_29 < 0 ) {
F_20 ( V_1 -> V_60 , L_2 ) ;
return V_29 ;
}
V_59 += V_56 ;
V_48 += V_56 ;
}
V_29 = F_13 ( V_1 ) ;
if ( V_29 < 0 ) {
F_19 ( V_1 -> V_60 , L_3 ) ;
return V_29 ;
}
if ( V_28 < V_27 ) {
V_29 = F_16 ( V_1 , V_59 ,
( int ) ( V_27 - V_28 ) , ( T_1 * ) V_48 ) ;
if ( V_29 < 0 ) {
F_20 ( V_1 -> V_60 , L_4 ) ;
return V_29 ;
}
}
return V_27 ;
}
static int F_21 ( struct V_2 * V_3 , T_1 V_61 , T_1 * V_48 , int V_27 )
{
int V_29 ;
struct V_1 * V_1 = V_3 -> V_49 ;
switch ( V_61 ) {
case V_62 :
V_29 = F_3 ( V_1 , V_63 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_27 == 1 )
* V_48 = F_7 ( V_1 -> V_7 + V_64 ) ;
else
F_20 ( V_1 -> V_60 , L_5 ) ;
break;
default:
V_29 = F_5 ( V_1 , V_61 , NULL , 0 , V_48 , V_27 ) ;
break;
}
return V_29 ;
}
static int F_22 ( struct V_2 * V_3 , T_1 V_61 , T_1 * V_48 ,
int V_27 )
{
int V_29 ;
struct V_1 * V_1 = V_3 -> V_49 ;
switch ( V_61 ) {
case V_65 :
V_29 = F_9 ( V_1 , * V_48 ) ;
break;
default:
V_29 = F_5 ( V_1 , V_61 , V_48 , V_27 , NULL , 0 ) ;
if ( V_29 )
F_19 ( V_1 -> V_60 , L_6 ) ;
break;
}
return V_29 ;
}
static int F_23 ( struct V_1 * V_1 ,
struct V_66 * V_67 )
{
int V_29 ;
struct V_2 * V_3 ;
F_11 ( V_68 , V_1 -> V_7 + V_69 ) ;
V_3 = & V_1 -> V_3 ;
V_3 -> V_60 = V_1 -> V_60 ;
V_3 -> V_49 = V_1 ;
F_24 ( V_3 , V_67 ) ;
V_3 -> V_70 = F_15 ;
V_3 -> V_71 = F_21 ;
V_3 -> V_72 = F_18 ;
V_3 -> V_73 = F_22 ;
V_3 -> V_74 . V_75 = L_7 ;
V_29 = F_25 ( V_3 , NULL , V_11 ) ;
if ( V_29 )
return V_29 ;
return F_26 ( & V_3 -> V_74 , NULL , 0 ) ;
}
static int F_27 ( struct V_76 * V_77 )
{
struct V_66 * V_78 ;
struct V_79 * V_80 ;
int V_29 ;
struct V_1 * V_1 ;
if ( ! V_77 -> V_60 . V_81 ) {
F_20 ( & V_77 -> V_60 , L_8 ) ;
return - V_32 ;
}
V_1 = F_28 ( & V_77 -> V_60 , sizeof( * V_1 ) , V_82 ) ;
if ( ! V_1 )
return - V_83 ;
F_29 ( V_77 , V_1 ) ;
V_80 = F_30 ( V_77 , V_84 , 0 ) ;
V_1 -> V_7 = F_31 ( & V_77 -> V_60 , V_80 ) ;
if ( F_32 ( V_1 -> V_7 ) )
return F_33 ( V_1 -> V_7 ) ;
V_1 -> V_85 = F_34 ( & V_77 -> V_60 , L_9 ) ;
if ( F_32 ( V_1 -> V_85 ) )
return F_33 ( V_1 -> V_85 ) ;
V_1 -> V_86 = F_34 ( & V_77 -> V_60 , L_10 ) ;
if ( F_32 ( V_1 -> V_86 ) )
return F_33 ( V_1 -> V_86 ) ;
V_1 -> V_60 = & V_77 -> V_60 ;
V_29 = F_35 ( V_1 -> V_85 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_35 ( V_1 -> V_86 ) ;
if ( V_29 ) {
F_36 ( V_1 -> V_85 ) ;
return V_29 ;
}
V_78 = F_37 ( V_77 -> V_60 . V_81 , NULL ) ;
if ( ! V_78 ) {
F_20 ( & V_77 -> V_60 , L_11 ) ;
V_29 = - V_87 ;
goto V_88;
}
V_29 = F_23 ( V_1 , V_78 ) ;
V_88:
if ( V_29 ) {
F_36 ( V_1 -> V_85 ) ;
F_36 ( V_1 -> V_86 ) ;
}
return V_29 ;
}
static int F_38 ( struct V_76 * V_77 )
{
struct V_1 * V_1 = F_39 ( V_77 ) ;
F_36 ( V_1 -> V_85 ) ;
F_36 ( V_1 -> V_86 ) ;
return 0 ;
}
