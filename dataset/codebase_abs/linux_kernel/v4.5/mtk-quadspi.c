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
static int F_15 ( struct V_2 * V_3 , T_3 V_45 , T_4 V_46 ,
T_4 * V_47 , T_5 * V_48 )
{
int V_28 , V_29 ;
int V_42 = ( int ) V_45 ;
T_1 * V_49 = ( T_1 * ) V_48 ;
struct V_1 * V_1 = V_3 -> V_50 ;
F_1 ( V_1 ) ;
F_14 ( V_1 , V_42 ) ;
for ( V_28 = 0 ; V_28 < V_46 ; V_28 ++ , ( * V_47 ) ++ ) {
V_29 = F_3 ( V_1 , V_51 ) ;
if ( V_29 < 0 )
return V_29 ;
V_49 [ V_28 ] = F_7 ( V_1 -> V_7 + V_52 ) ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_1 ,
int V_42 , int V_46 , T_1 * V_53 )
{
int V_28 , V_29 ;
F_14 ( V_1 , V_42 ) ;
for ( V_28 = 0 ; V_28 < V_46 ; V_28 ++ ) {
F_2 ( * V_53 ++ , V_1 -> V_7 + V_54 ) ;
V_29 = F_3 ( V_1 , V_55 ) ;
if ( V_29 < 0 )
return V_29 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_1 , int V_42 ,
const T_1 * V_49 )
{
int V_28 , V_56 , V_53 ;
F_14 ( V_1 , V_42 ) ;
V_56 = 0 ;
for ( V_28 = 0 ; V_28 < V_57 ; V_28 += 4 ) {
V_53 = V_49 [ V_56 + 3 ] << 24 | V_49 [ V_56 + 2 ] << 16 |
V_49 [ V_56 + 1 ] << 8 | V_49 [ V_56 ] ;
V_56 += 4 ;
F_11 ( V_53 , V_1 -> V_7 + V_58 ) ;
}
return F_3 ( V_1 , V_59 ) ;
}
static void F_18 ( struct V_2 * V_3 , T_3 V_60 , T_4 V_27 ,
T_4 * V_47 , const T_5 * V_49 )
{
int V_29 ;
struct V_1 * V_1 = V_3 -> V_50 ;
V_29 = F_10 ( V_1 ) ;
if ( V_29 < 0 )
F_19 ( V_1 -> V_61 , L_1 ) ;
while ( V_27 >= V_57 ) {
V_29 = F_17 ( V_1 , V_60 , V_49 ) ;
if ( V_29 < 0 )
F_20 ( V_1 -> V_61 , L_2 ) ;
V_27 -= V_57 ;
V_60 += V_57 ;
V_49 += V_57 ;
( * V_47 ) += V_57 ;
}
V_29 = F_13 ( V_1 ) ;
if ( V_29 < 0 )
F_19 ( V_1 -> V_61 , L_3 ) ;
if ( V_27 ) {
V_29 = F_16 ( V_1 , V_60 , ( int ) V_27 ,
( T_1 * ) V_49 ) ;
if ( V_29 < 0 )
F_20 ( V_1 -> V_61 , L_4 ) ;
( * V_47 ) += V_27 ;
}
}
static int F_21 ( struct V_2 * V_3 , T_1 V_62 , T_1 * V_49 , int V_27 )
{
int V_29 ;
struct V_1 * V_1 = V_3 -> V_50 ;
switch ( V_62 ) {
case V_63 :
V_29 = F_3 ( V_1 , V_64 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_27 == 1 )
* V_49 = F_7 ( V_1 -> V_7 + V_65 ) ;
else
F_20 ( V_1 -> V_61 , L_5 ) ;
break;
default:
V_29 = F_5 ( V_1 , V_62 , NULL , 0 , V_49 , V_27 ) ;
break;
}
return V_29 ;
}
static int F_22 ( struct V_2 * V_3 , T_1 V_62 , T_1 * V_49 ,
int V_27 )
{
int V_29 ;
struct V_1 * V_1 = V_3 -> V_50 ;
switch ( V_62 ) {
case V_66 :
V_29 = F_9 ( V_1 , * V_49 ) ;
break;
default:
V_29 = F_5 ( V_1 , V_62 , V_49 , V_27 , NULL , 0 ) ;
if ( V_29 )
F_19 ( V_1 -> V_61 , L_6 ) ;
break;
}
return V_29 ;
}
static int T_6 F_23 ( struct V_1 * V_1 ,
struct V_67 * V_68 )
{
int V_29 ;
struct V_2 * V_3 ;
F_11 ( V_69 , V_1 -> V_7 + V_70 ) ;
V_3 = & V_1 -> V_3 ;
V_3 -> V_61 = V_1 -> V_61 ;
V_3 -> V_50 = V_1 ;
F_24 ( V_3 , V_68 ) ;
V_3 -> V_71 = F_15 ;
V_3 -> V_72 = F_21 ;
V_3 -> V_73 = F_18 ;
V_3 -> V_74 = F_22 ;
V_3 -> V_75 . V_76 = L_7 ;
V_29 = F_25 ( V_3 , NULL , V_11 ) ;
if ( V_29 )
return V_29 ;
return F_26 ( & V_3 -> V_75 , NULL , 0 ) ;
}
static int F_27 ( struct V_77 * V_78 )
{
struct V_67 * V_79 ;
struct V_80 * V_81 ;
int V_29 ;
struct V_1 * V_1 ;
if ( ! V_78 -> V_61 . V_82 ) {
F_20 ( & V_78 -> V_61 , L_8 ) ;
return - V_32 ;
}
V_1 = F_28 ( & V_78 -> V_61 , sizeof( * V_1 ) , V_83 ) ;
if ( ! V_1 )
return - V_84 ;
F_29 ( V_78 , V_1 ) ;
V_81 = F_30 ( V_78 , V_85 , 0 ) ;
V_1 -> V_7 = F_31 ( & V_78 -> V_61 , V_81 ) ;
if ( F_32 ( V_1 -> V_7 ) )
return F_33 ( V_1 -> V_7 ) ;
V_1 -> V_86 = F_34 ( & V_78 -> V_61 , L_9 ) ;
if ( F_32 ( V_1 -> V_86 ) )
return F_33 ( V_1 -> V_86 ) ;
V_1 -> V_87 = F_34 ( & V_78 -> V_61 , L_10 ) ;
if ( F_32 ( V_1 -> V_87 ) )
return F_33 ( V_1 -> V_87 ) ;
V_1 -> V_61 = & V_78 -> V_61 ;
V_29 = F_35 ( V_1 -> V_86 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_35 ( V_1 -> V_87 ) ;
if ( V_29 ) {
F_36 ( V_1 -> V_86 ) ;
return V_29 ;
}
V_79 = F_37 ( V_78 -> V_61 . V_82 , NULL ) ;
if ( ! V_79 ) {
F_20 ( & V_78 -> V_61 , L_11 ) ;
V_29 = - V_88 ;
goto V_89;
}
V_29 = F_23 ( V_1 , V_79 ) ;
V_89:
if ( V_29 ) {
F_36 ( V_1 -> V_86 ) ;
F_36 ( V_1 -> V_87 ) ;
}
return V_29 ;
}
static int F_38 ( struct V_77 * V_78 )
{
struct V_1 * V_1 = F_39 ( V_78 ) ;
F_36 ( V_1 -> V_86 ) ;
F_36 ( V_1 -> V_87 ) ;
return 0 ;
}
