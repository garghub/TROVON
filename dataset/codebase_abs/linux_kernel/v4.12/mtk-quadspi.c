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
static void F_14 ( struct V_1 * V_1 )
{
T_1 V_20 ;
struct V_2 * V_3 = & V_1 -> V_3 ;
V_20 = F_7 ( V_1 -> V_7 + V_13 ) ;
switch ( V_3 -> V_42 ) {
case 3 :
V_20 &= ~ V_43 ;
break;
case 4 :
V_20 |= V_43 ;
break;
default:
F_15 ( V_1 -> V_44 , L_1 ,
V_3 -> V_42 ) ;
break;
}
F_2 ( V_20 , V_1 -> V_7 + V_13 ) ;
}
static void F_16 ( struct V_1 * V_1 , T_2 V_45 )
{
int V_28 ;
F_14 ( V_1 ) ;
for ( V_28 = 0 ; V_28 < 3 ; V_28 ++ ) {
F_2 ( V_45 & 0xff , V_1 -> V_7 + V_46 + V_28 * 4 ) ;
V_45 >>= 8 ;
}
F_2 ( V_45 & 0xff , V_1 -> V_7 + V_47 ) ;
}
static T_3 F_17 ( struct V_2 * V_3 , T_4 V_48 , T_5 V_49 ,
T_6 * V_50 )
{
int V_28 , V_29 ;
int V_45 = ( int ) V_48 ;
T_1 * V_51 = ( T_1 * ) V_50 ;
struct V_1 * V_1 = V_3 -> V_52 ;
F_1 ( V_1 ) ;
F_16 ( V_1 , V_45 ) ;
for ( V_28 = 0 ; V_28 < V_49 ; V_28 ++ ) {
V_29 = F_3 ( V_1 , V_53 ) ;
if ( V_29 < 0 )
return V_29 ;
V_51 [ V_28 ] = F_7 ( V_1 -> V_7 + V_54 ) ;
}
return V_49 ;
}
static int F_18 ( struct V_1 * V_1 ,
int V_45 , int V_49 , T_1 * V_55 )
{
int V_28 , V_29 ;
F_16 ( V_1 , V_45 ) ;
for ( V_28 = 0 ; V_28 < V_49 ; V_28 ++ ) {
F_2 ( * V_55 ++ , V_1 -> V_7 + V_56 ) ;
V_29 = F_3 ( V_1 , V_57 ) ;
if ( V_29 < 0 )
return V_29 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_1 , int V_45 ,
const T_1 * V_51 )
{
int V_28 , V_58 , V_55 ;
F_16 ( V_1 , V_45 ) ;
V_58 = 0 ;
for ( V_28 = 0 ; V_28 < V_59 ; V_28 += 4 ) {
V_55 = V_51 [ V_58 + 3 ] << 24 | V_51 [ V_58 + 2 ] << 16 |
V_51 [ V_58 + 1 ] << 8 | V_51 [ V_58 ] ;
V_58 += 4 ;
F_11 ( V_55 , V_1 -> V_7 + V_60 ) ;
}
return F_3 ( V_1 , V_61 ) ;
}
static T_3 F_20 ( struct V_2 * V_3 , T_4 V_62 , T_5 V_27 ,
const T_6 * V_51 )
{
int V_29 ;
struct V_1 * V_1 = V_3 -> V_52 ;
T_5 V_28 ;
V_29 = F_10 ( V_1 ) ;
if ( V_29 < 0 ) {
F_15 ( V_1 -> V_44 , L_2 ) ;
return V_29 ;
}
for ( V_28 = 0 ; V_28 + V_59 <= V_27 ; V_28 += V_59 ) {
V_29 = F_19 ( V_1 , V_62 , V_51 ) ;
if ( V_29 < 0 ) {
F_21 ( V_1 -> V_44 , L_3 ) ;
return V_29 ;
}
V_62 += V_59 ;
V_51 += V_59 ;
}
V_29 = F_13 ( V_1 ) ;
if ( V_29 < 0 ) {
F_15 ( V_1 -> V_44 , L_4 ) ;
return V_29 ;
}
if ( V_28 < V_27 ) {
V_29 = F_18 ( V_1 , V_62 ,
( int ) ( V_27 - V_28 ) , ( T_1 * ) V_51 ) ;
if ( V_29 < 0 ) {
F_21 ( V_1 -> V_44 , L_5 ) ;
return V_29 ;
}
}
return V_27 ;
}
static int F_22 ( struct V_2 * V_3 , T_1 V_63 , T_1 * V_51 , int V_27 )
{
int V_29 ;
struct V_1 * V_1 = V_3 -> V_52 ;
switch ( V_63 ) {
case V_64 :
V_29 = F_3 ( V_1 , V_65 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_27 == 1 )
* V_51 = F_7 ( V_1 -> V_7 + V_66 ) ;
else
F_21 ( V_1 -> V_44 , L_6 ) ;
break;
default:
V_29 = F_5 ( V_1 , V_63 , NULL , 0 , V_51 , V_27 ) ;
break;
}
return V_29 ;
}
static int F_23 ( struct V_2 * V_3 , T_1 V_63 , T_1 * V_51 ,
int V_27 )
{
int V_29 ;
struct V_1 * V_1 = V_3 -> V_52 ;
switch ( V_63 ) {
case V_67 :
V_29 = F_9 ( V_1 , * V_51 ) ;
break;
default:
V_29 = F_5 ( V_1 , V_63 , V_51 , V_27 , NULL , 0 ) ;
if ( V_29 )
F_15 ( V_1 -> V_44 , L_7 ) ;
break;
}
return V_29 ;
}
static int F_24 ( struct V_1 * V_1 ,
struct V_68 * V_69 )
{
int V_29 ;
struct V_2 * V_3 ;
F_11 ( V_70 , V_1 -> V_7 + V_71 ) ;
V_3 = & V_1 -> V_3 ;
V_3 -> V_44 = V_1 -> V_44 ;
V_3 -> V_52 = V_1 ;
F_25 ( V_3 , V_69 ) ;
V_3 -> V_72 = F_17 ;
V_3 -> V_73 = F_22 ;
V_3 -> V_74 = F_20 ;
V_3 -> V_75 = F_23 ;
V_3 -> V_76 . V_77 = L_8 ;
V_29 = F_26 ( V_3 , NULL , V_11 ) ;
if ( V_29 )
return V_29 ;
return F_27 ( & V_3 -> V_76 , NULL , 0 ) ;
}
static int F_28 ( struct V_78 * V_79 )
{
struct V_68 * V_80 ;
struct V_81 * V_82 ;
int V_29 ;
struct V_1 * V_1 ;
if ( ! V_79 -> V_44 . V_83 ) {
F_21 ( & V_79 -> V_44 , L_9 ) ;
return - V_32 ;
}
V_1 = F_29 ( & V_79 -> V_44 , sizeof( * V_1 ) , V_84 ) ;
if ( ! V_1 )
return - V_85 ;
F_30 ( V_79 , V_1 ) ;
V_82 = F_31 ( V_79 , V_86 , 0 ) ;
V_1 -> V_7 = F_32 ( & V_79 -> V_44 , V_82 ) ;
if ( F_33 ( V_1 -> V_7 ) )
return F_34 ( V_1 -> V_7 ) ;
V_1 -> V_87 = F_35 ( & V_79 -> V_44 , L_10 ) ;
if ( F_33 ( V_1 -> V_87 ) )
return F_34 ( V_1 -> V_87 ) ;
V_1 -> V_88 = F_35 ( & V_79 -> V_44 , L_11 ) ;
if ( F_33 ( V_1 -> V_88 ) )
return F_34 ( V_1 -> V_88 ) ;
V_1 -> V_44 = & V_79 -> V_44 ;
V_29 = F_36 ( V_1 -> V_87 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_36 ( V_1 -> V_88 ) ;
if ( V_29 ) {
F_37 ( V_1 -> V_87 ) ;
return V_29 ;
}
V_80 = F_38 ( V_79 -> V_44 . V_83 , NULL ) ;
if ( ! V_80 ) {
F_21 ( & V_79 -> V_44 , L_12 ) ;
V_29 = - V_89 ;
goto V_90;
}
V_29 = F_24 ( V_1 , V_80 ) ;
V_90:
if ( V_29 ) {
F_37 ( V_1 -> V_87 ) ;
F_37 ( V_1 -> V_88 ) ;
}
return V_29 ;
}
static int F_39 ( struct V_78 * V_79 )
{
struct V_1 * V_1 = F_40 ( V_79 ) ;
F_37 ( V_1 -> V_87 ) ;
F_37 ( V_1 -> V_88 ) ;
return 0 ;
}
