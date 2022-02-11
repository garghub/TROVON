static T_1 F_1 ( int V_1 , void * V_2 )
{
T_1 V_3 = V_4 ;
struct V_5 * V_6 = V_2 ;
unsigned int V_7 ;
F_2 ( & V_6 -> V_8 ) ;
if ( ! V_6 -> V_9 )
goto V_10;
F_3 ( V_6 -> V_9 ) ;
if ( V_6 -> V_11 == V_12 ) {
F_4 ( V_6 -> V_13 , L_1 ) ;
goto V_14;
}
V_7 = F_5 ( V_6 ) ;
F_6 ( V_6 , V_7 ) ;
if ( F_7 ( V_7 & F_8 ( V_6 ) ) ) {
F_9 ( V_6 -> V_13 , L_2 ) ;
F_10 ( V_6 -> V_9 , V_15 ) ;
V_3 = V_16 ;
}
V_14:
F_11 ( V_6 -> V_9 ) ;
V_10:
F_12 ( & V_6 -> V_8 ) ;
return V_3 ;
}
static int F_13 ( struct V_17 * V_18 ,
struct V_5 * V_6 )
{
int V_19 ;
if ( ( V_6 -> V_20 & V_21 )
== V_22 ) {
V_19 = 32 ;
} else {
switch ( V_18 -> V_23 ) {
case V_24 :
V_19 = 16 ;
break;
default:
V_19 = 32 ;
break;
}
}
switch ( V_19 ) {
case 32 :
F_14 ( V_6 ) ;
F_15 ( V_6 ) ;
break;
case 16 :
F_16 ( V_6 ) ;
F_17 ( V_6 ) ;
break;
default:
F_9 ( V_6 -> V_13 , L_3 ) ;
return - V_25 ;
}
switch ( V_18 -> V_23 ) {
case V_24 :
F_18 ( V_6 ) ;
break;
case V_26 :
F_19 ( V_6 ) ;
break;
default:
F_9 ( V_6 -> V_13 , L_4 ) ;
return - V_25 ;
}
if ( ( V_18 -> V_27 % 2 ) || ( V_18 -> V_27 < 2 ) ||
( V_18 -> V_27 > 10 ) ) {
F_9 ( V_6 -> V_13 , L_5 , V_28 ) ;
return - V_25 ;
}
F_20 ( V_6 , V_18 -> V_27 / 2 ) ;
F_21 ( V_6 ) ;
return 0 ;
}
static int F_22 ( struct V_17 * V_18 ,
struct V_5 * V_6 )
{
int V_29 ;
unsigned int V_30 [ 4 ] = {
0x04060002 , 0x0C0E080A , 0x14161012 , 0x1C1E181A } ;
V_29 = F_23 ( V_18 ) ;
F_19 ( V_6 ) ;
F_15 ( V_6 ) ;
F_20 ( V_6 , V_29 / 4 / 2 ) ;
F_21 ( V_6 ) ;
F_24 ( V_6 ) ;
F_25 ( V_6 ) ;
F_26 ( V_6 , V_30 ) ;
F_27 ( V_6 , 1_2 , V_30 [ V_31 ] ) ;
F_27 ( V_6 , 3_4 , V_30 [ V_32 ] ) ;
F_27 ( V_6 , 5_6 , V_30 [ V_33 ] ) ;
F_27 ( V_6 , 7_8 , V_30 [ V_34 ] ) ;
return 0 ;
}
static int F_28 ( struct V_35 * V_9 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 = F_29 ( V_37 ) ;
struct V_5 * V_6 = V_39 -> V_40 . V_41 ;
struct V_17 * V_18 = V_9 -> V_18 ;
int V_42 , V_43 , V_3 ;
if ( V_6 -> V_11 != V_12 ) {
F_9 ( V_6 -> V_13 , L_6 , V_28 ,
V_6 -> V_11 ) ;
return - V_25 ;
}
if ( V_6 -> type == V_44 ) {
V_42 =
F_23 ( V_18 ) / 4 ;
} else {
V_42 = V_18 -> V_27 * V_45 ;
}
if ( V_6 -> V_46 < V_47 )
V_43 = V_48 - V_42 ;
else
V_43 = V_42 ;
if ( ( ! V_43 % 2 ) ||
( V_43 != 1 && V_42 % 2 ) ||
( V_43 > F_30 ( V_6 ) ) ) {
F_9 ( V_6 -> V_13 , L_7 ,
V_43 ) ;
return - V_25 ;
}
F_31 ( V_6 , V_43 ) ;
if ( F_32 ( V_6 ) )
V_3 = F_22 ( V_18 , V_6 ) ;
else
V_3 = F_13 ( V_18 , V_6 ) ;
if ( V_3 )
return V_3 ;
switch ( V_6 -> V_20 & V_21 ) {
case V_22 :
F_24 ( V_6 ) ;
F_33 ( V_6 ) ;
break;
case V_49 :
F_24 ( V_6 ) ;
F_34 ( V_6 ) ;
break;
case V_50 :
F_35 ( V_6 ) ;
F_34 ( V_6 ) ;
break;
default:
F_9 ( V_6 -> V_13 , L_4 ) ;
return - V_25 ;
}
switch ( V_6 -> V_20 & V_51 ) {
case V_52 :
F_36 ( V_6 ) ;
F_37 ( V_6 ) ;
break;
case V_53 :
F_38 ( V_6 ) ;
F_37 ( V_6 ) ;
break;
case V_54 :
F_36 ( V_6 ) ;
F_39 ( V_6 ) ;
break;
case V_55 :
F_38 ( V_6 ) ;
F_39 ( V_6 ) ;
break;
}
F_6 ( V_6 , F_5 ( V_6 ) ) ;
F_40 ( V_6 , 0 ) ;
F_41 ( V_6 ) ;
F_42 ( V_6 ) ;
F_43 ( V_6 ) ;
if ( V_6 -> V_56 ) {
F_44 ( V_6 ) ;
F_45 ( V_6 ) ;
}
return F_46 ( V_6 ) ;
}
static int F_47 ( struct V_5 * V_6 )
{
if ( V_6 -> V_11 != V_12 ) {
F_9 ( V_6 -> V_13 , L_8 , V_28 ) ;
return - V_25 ;
}
F_48 ( V_6 ) ;
F_42 ( V_6 ) ;
F_49 ( V_6 ) ;
V_6 -> V_11 = V_57 ;
return 0 ;
}
static int F_50 ( struct V_5 * V_6 )
{
if ( V_6 -> V_11 == V_12 ) {
F_9 ( V_6 -> V_13 , L_8 , V_28 ) ;
return - V_25 ;
}
F_51 ( V_6 ) ;
F_52 ( V_6 , F_53 ( V_6 ) ) ;
V_6 -> V_11 = V_12 ;
return 0 ;
}
static int F_54 ( struct V_35 * V_9 ,
int V_58 , struct V_36 * V_37 )
{
struct V_38 * V_39 = F_29 ( V_37 ) ;
struct V_5 * V_6 = V_39 -> V_40 . V_41 ;
switch ( V_58 ) {
case V_59 :
return F_47 ( V_6 ) ;
case V_60 :
return F_50 ( V_6 ) ;
default:
return - V_25 ;
}
}
static int F_55 ( struct V_35 * V_9 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 = F_29 ( V_37 ) ;
struct V_5 * V_6 = V_39 -> V_40 . V_41 ;
unsigned long V_61 ;
int V_3 ;
F_56 ( & V_6 -> V_8 , V_61 ) ;
V_6 -> V_9 = V_9 ;
F_57 ( & V_6 -> V_8 , V_61 ) ;
if ( ! F_32 ( V_6 ) )
return 0 ;
V_3 = F_58 ( V_9 -> V_18 , 0 ,
V_62 ,
V_63 ,
V_6 , V_62 ,
- 1 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_58 ( V_9 -> V_18 , 0 ,
V_64 ,
V_65 ,
V_6 , V_64 ,
- 1 ) ;
}
static void F_59 ( struct V_35 * V_9 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 = F_29 ( V_37 ) ;
struct V_5 * V_6 = V_39 -> V_40 . V_41 ;
unsigned long V_61 ;
F_56 ( & V_6 -> V_8 , V_61 ) ;
if ( V_6 -> V_11 != V_12 ) {
F_50 ( V_6 ) ;
}
V_6 -> V_9 = NULL ;
F_57 ( & V_6 -> V_8 , V_61 ) ;
}
int F_60 ( struct V_66 * V_67 ,
struct V_5 * V_6 )
{
int V_3 = 0 ;
V_6 -> V_13 = & V_67 -> V_13 ;
V_6 -> V_11 = V_12 ;
V_6 -> V_68 = & V_69 ;
if ( F_32 ( V_6 ) )
V_6 -> V_70 = & V_71 ;
else
V_6 -> V_70 = & V_72 ;
V_3 = F_61 ( & V_67 -> V_13 , V_6 -> V_1 ,
F_1 , V_73 ,
F_62 ( & V_67 -> V_13 ) , V_6 ) ;
if ( V_3 < 0 ) {
F_9 ( & V_67 -> V_13 , L_9 ) ;
return - V_74 ;
}
F_63 ( & V_6 -> V_8 ) ;
return 0 ;
}
