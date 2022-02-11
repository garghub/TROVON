static T_1 F_1 ( int V_1 , void * V_2 )
{
T_1 V_3 = V_4 ;
struct V_5 * V_6 = V_2 ;
unsigned int V_7 ;
if ( V_6 -> V_8 == V_9 ) {
F_2 ( V_6 -> V_10 , L_1 ) ;
return V_11 ;
}
V_7 = F_3 ( V_6 ) ;
F_4 ( V_6 , V_7 ) ;
if ( F_5 ( V_7 & F_6 ( V_6 ) ) ) {
F_7 ( V_6 -> V_10 , L_2 ) ;
F_8 ( V_6 -> V_12 ) ;
F_9 ( V_6 -> V_12 , V_13 ) ;
F_10 ( V_6 -> V_12 ) ;
return V_11 ;
}
return V_3 ;
}
static int F_11 ( struct V_14 * V_15 ,
struct V_5 * V_6 )
{
int V_16 ;
if ( ( V_6 -> V_17 & V_18 )
== V_19 ) {
V_16 = 32 ;
} else {
switch ( V_15 -> V_20 ) {
case V_21 :
V_16 = 16 ;
break;
default:
V_16 = 32 ;
break;
}
}
switch ( V_16 ) {
case 32 :
F_12 ( V_6 ) ;
F_13 ( V_6 ) ;
break;
case 16 :
F_14 ( V_6 ) ;
F_15 ( V_6 ) ;
break;
default:
F_7 ( V_6 -> V_10 , L_3 ) ;
return - V_22 ;
}
switch ( V_15 -> V_20 ) {
case V_21 :
F_16 ( V_6 ) ;
break;
case V_23 :
F_17 ( V_6 ) ;
break;
default:
F_7 ( V_6 -> V_10 , L_4 ) ;
return - V_22 ;
}
if ( ( V_15 -> V_24 % 2 ) || ( V_15 -> V_24 < 2 ) ||
( V_15 -> V_24 > 10 ) ) {
F_7 ( V_6 -> V_10 , L_5 , V_25 ) ;
return - V_22 ;
}
F_18 ( V_6 , V_15 -> V_24 / 2 ) ;
F_19 ( V_6 ) ;
return 0 ;
}
static int F_20 ( struct V_14 * V_15 ,
struct V_5 * V_6 )
{
int V_26 ;
unsigned int V_27 [ 4 ] = {
0x04060002 , 0x0C0E080A , 0x14161012 , 0x1C1E181A } ;
V_26 = F_21 ( V_15 ) ;
F_17 ( V_6 ) ;
F_13 ( V_6 ) ;
F_18 ( V_6 , V_26 / 4 / 2 ) ;
F_19 ( V_6 ) ;
F_22 ( V_6 ) ;
F_23 ( V_6 ) ;
F_24 ( V_6 , V_27 ) ;
F_25 ( V_6 , 1_2 , V_27 [ V_28 ] ) ;
F_25 ( V_6 , 3_4 , V_27 [ V_29 ] ) ;
F_25 ( V_6 , 5_6 , V_27 [ V_30 ] ) ;
F_25 ( V_6 , 7_8 , V_27 [ V_31 ] ) ;
return 0 ;
}
static int F_26 ( struct V_32 * V_12 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = F_27 ( V_34 ) ;
struct V_5 * V_6 = V_36 -> V_37 . V_38 ;
struct V_14 * V_15 = V_12 -> V_15 ;
int V_39 , V_40 , V_3 ;
int V_41 = 10 ;
if ( V_6 -> V_8 != V_9 ) {
F_7 ( V_6 -> V_10 , L_6 , V_25 ,
V_6 -> V_8 ) ;
return - V_22 ;
}
if ( V_6 -> V_42 -> type == V_43 ) {
V_39 =
F_21 ( V_15 ) / 4 ;
} else {
V_39 = V_15 -> V_24 * V_44 ;
}
if ( V_6 -> V_45 < V_46 )
V_40 = V_47 - V_39 ;
else
V_40 = V_39 ;
if ( ( ! V_40 % 2 ) ||
( V_40 != 1 && V_39 % 2 ) ||
( V_40 > F_28 ( V_6 ) ) ) {
F_7 ( V_6 -> V_10 , L_7 , V_40 ) ;
return - V_22 ;
}
F_29 ( V_6 , V_40 ) ;
if ( F_30 ( V_6 ) )
V_3 = F_20 ( V_15 , V_6 ) ;
else
V_3 = F_11 ( V_15 , V_6 ) ;
if ( V_3 )
return V_3 ;
switch ( V_6 -> V_17 & V_18 ) {
case V_19 :
F_22 ( V_6 ) ;
F_31 ( V_6 ) ;
break;
case V_48 :
F_22 ( V_6 ) ;
F_32 ( V_6 ) ;
break;
case V_49 :
F_33 ( V_6 ) ;
F_32 ( V_6 ) ;
break;
default:
F_7 ( V_6 -> V_10 , L_4 ) ;
return - V_22 ;
}
switch ( V_6 -> V_17 & V_50 ) {
case V_51 :
F_34 ( V_6 ) ;
F_35 ( V_6 ) ;
break;
case V_52 :
F_36 ( V_6 ) ;
F_35 ( V_6 ) ;
break;
case V_53 :
F_34 ( V_6 ) ;
F_37 ( V_6 ) ;
break;
case V_54 :
F_36 ( V_6 ) ;
F_37 ( V_6 ) ;
break;
}
F_4 ( V_6 , F_3 ( V_6 ) ) ;
F_38 ( V_6 , 0 ) ;
F_39 ( V_6 ) ;
F_40 ( V_6 ) ;
F_41 ( V_6 ) ;
if ( V_6 -> V_42 -> V_55 ) {
F_42 ( V_6 ) ;
F_43 ( V_6 ) ;
}
F_44 ( V_6 ) ;
while ( F_45 ( V_6 ) ) {
F_46 ( 5 ) ;
V_41 -- ;
}
if ( ! V_41 ) {
F_7 ( V_6 -> V_10 , L_8 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_47 ( struct V_5 * V_6 )
{
if ( V_6 -> V_8 != V_9 ) {
F_7 ( V_6 -> V_10 , L_9 , V_25 ) ;
return - V_22 ;
}
F_48 ( V_6 ) ;
F_40 ( V_6 ) ;
F_49 ( V_6 ) ;
V_6 -> V_8 = V_57 ;
return 0 ;
}
static int F_50 ( struct V_5 * V_6 )
{
if ( V_6 -> V_8 == V_9 ) {
F_7 ( V_6 -> V_10 , L_9 , V_25 ) ;
return - V_22 ;
}
F_51 ( V_6 ) ;
F_52 ( V_6 , F_53 ( V_6 ) ) ;
V_6 -> V_8 = V_9 ;
return 0 ;
}
static int F_54 ( struct V_32 * V_12 ,
int V_58 , struct V_33 * V_34 )
{
struct V_35 * V_36 = F_27 ( V_34 ) ;
struct V_5 * V_6 = V_36 -> V_37 . V_38 ;
switch ( V_58 ) {
case V_59 :
return F_47 ( V_6 ) ;
case V_60 :
return F_50 ( V_6 ) ;
default:
return - V_22 ;
}
}
static int F_55 ( struct V_32 * V_12 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = F_27 ( V_34 ) ;
struct V_5 * V_6 = V_36 -> V_37 . V_38 ;
int V_3 ;
if ( ! F_30 ( V_6 ) )
return 0 ;
V_3 = F_56 ( V_12 -> V_15 , 0 ,
V_61 ,
V_62 ,
V_6 , V_61 ,
- 1 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_56 ( V_12 -> V_15 , 0 ,
V_63 ,
V_64 ,
V_6 , V_63 ,
- 1 ) ;
}
static void F_57 ( struct V_32 * V_12 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = F_27 ( V_34 ) ;
struct V_5 * V_6 = V_36 -> V_37 . V_38 ;
if ( V_6 -> V_8 != V_9 ) {
F_50 ( V_6 ) ;
}
}
static int F_58 ( struct V_65 * V_66 ,
struct V_5 * V_6 )
{
struct V_67 * V_42 ;
struct V_68 * V_69 = V_66 -> V_10 . V_70 ;
const char * V_71 ;
V_42 = F_59 ( & V_66 -> V_10 , sizeof( * V_42 ) , V_72 ) ;
if ( ! V_42 )
return - V_73 ;
if ( F_60 ( V_69 , L_10 , & V_6 -> V_45 ) ||
V_6 -> V_45 == V_74 ) {
F_7 ( & V_66 -> V_10 , L_11 ) ;
return - V_22 ;
}
if ( F_61 ( V_69 , L_12 , & V_71 ) ) {
F_7 ( & V_66 -> V_10 , L_13 ) ;
return - V_22 ;
}
if ( strcasecmp ( V_71 , L_14 ) == 0 )
V_42 -> type = V_43 ;
else
V_42 -> type = V_75 ;
V_6 -> V_42 = V_42 ;
return 0 ;
}
int F_62 ( struct V_65 * V_66 ,
struct V_5 * V_6 )
{
int V_3 = 0 ;
V_6 -> V_10 = & V_66 -> V_10 ;
V_6 -> V_8 = V_9 ;
V_6 -> V_76 = & V_77 ;
V_3 = F_58 ( V_66 , V_6 ) ;
if ( V_3 < 0 ) {
F_7 ( V_6 -> V_10 , L_15 ) ;
return V_3 ;
}
if ( F_30 ( V_6 ) )
V_6 -> V_78 = & V_79 ;
else
V_6 -> V_78 = & V_80 ;
V_3 = F_63 ( & V_66 -> V_10 , V_6 -> V_1 ,
F_1 , V_81 ,
F_64 ( & V_66 -> V_10 ) , V_6 ) ;
if ( V_3 < 0 ) {
F_7 ( & V_66 -> V_10 , L_16 ) ;
return - V_82 ;
}
return 0 ;
}
