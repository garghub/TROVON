static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 = 150 ;
V_3 = F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 | V_8 ) ;
if ( V_3 < 0 )
return V_3 ;
while ( V_4 -- > 0 ) {
V_3 = F_3 ( V_2 -> V_5 , V_9 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ( V_3 & V_10 ) == V_10 )
break;
F_4 ( 20 ) ;
}
if ( V_4 < 0 ) {
F_5 ( & V_2 -> V_5 -> V_11 , L_1 ) ;
return - V_12 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_13 [ 3 ] )
{
int V_3 ;
F_7 ( & V_2 -> V_14 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_8 ( & V_2 -> V_14 ) ;
return V_3 ;
}
V_3 = F_9 ( V_2 -> V_5 ,
V_15 , 3 * sizeof( T_1 ) , ( V_16 * ) V_13 ) ;
F_8 ( & V_2 -> V_14 ) ;
return V_3 ;
}
static T_2 F_10 ( struct V_17 * V_11 ,
struct V_18 * V_19 , char * V_13 )
{
return F_11 ( V_13 , V_20 , 8 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
int V_21 , int V_22 )
{
return F_13 ( V_20 , 8 , V_21 ,
V_22 ) ;
}
static int F_14 ( struct V_23 * V_24 ,
struct V_25 const * V_26 ,
int * V_21 , int * V_22 , long V_27 )
{
struct V_1 * V_2 = F_15 ( V_24 ) ;
T_1 V_28 [ 3 ] ;
int V_29 , V_3 ;
switch ( V_27 ) {
case V_30 :
V_3 = F_16 ( V_24 ) ;
if ( V_3 )
return V_3 ;
switch ( V_26 -> type ) {
case V_31 :
V_3 = F_6 ( V_2 , V_28 ) ;
if ( V_3 < 0 )
goto V_32;
* V_21 = F_17 (
F_18 ( V_28 [ V_26 -> V_33 ] ) , 15 ) ;
V_3 = V_34 ;
break;
case V_35 :
F_7 ( & V_2 -> V_14 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_8 ( & V_2 -> V_14 ) ;
goto V_32;
}
V_3 = F_3 ( V_2 -> V_5 ,
V_36 ) ;
F_8 ( & V_2 -> V_14 ) ;
if ( V_3 < 0 )
goto V_32;
* V_21 = F_17 ( V_3 , 7 ) ;
V_3 = V_34 ;
break;
default:
V_3 = - V_37 ;
}
V_32:
F_19 ( V_24 ) ;
return V_3 ;
case V_38 :
switch ( V_26 -> type ) {
case V_31 :
* V_21 = 0 ;
* V_22 = 1000 ;
return V_39 ;
case V_35 :
* V_21 = 1000 ;
return V_34 ;
default:
return - V_37 ;
}
case V_40 :
V_29 = V_2 -> V_7 >> V_41 ;
* V_21 = V_20 [ V_29 ] [ 0 ] ;
* V_22 = V_20 [ V_29 ] [ 1 ] ;
return V_39 ;
case V_42 :
V_3 = F_20 ( V_2 -> V_5 ,
V_43 + 2 * V_26 -> V_33 ) ;
if ( V_3 < 0 )
return V_3 ;
* V_21 = F_17 ( V_3 >> 1 , 14 ) ;
return V_34 ;
}
return - V_37 ;
}
static int F_21 ( struct V_23 * V_24 ,
struct V_25 const * V_26 ,
int V_21 , int V_22 , long V_27 )
{
struct V_1 * V_2 = F_15 ( V_24 ) ;
int V_44 ;
if ( F_22 ( V_24 ) )
return - V_45 ;
switch ( V_27 ) {
case V_40 :
V_44 = F_12 ( V_2 , V_21 , V_22 ) ;
if ( V_44 < 0 )
return - V_37 ;
V_2 -> V_7 &= ~ V_46 ;
V_2 -> V_7 |= V_44 << V_41 ;
return F_2 ( V_2 -> V_5 ,
V_6 , V_2 -> V_7 ) ;
case V_42 :
if ( V_21 < - 10000 || V_21 > 10000 )
return - V_37 ;
return F_23 ( V_2 -> V_5 ,
V_43 + 2 * V_26 -> V_33 , V_21 << 1 ) ;
default:
return - V_37 ;
}
}
static T_3 F_24 ( int V_47 , void * V_48 )
{
struct V_49 * V_50 = V_48 ;
struct V_23 * V_24 = V_50 -> V_24 ;
struct V_1 * V_2 = F_15 ( V_24 ) ;
V_16 V_28 [ 16 ] ;
int V_3 ;
V_3 = F_6 ( V_2 , ( T_1 * ) V_28 ) ;
if ( V_3 < 0 )
goto V_51;
if ( F_25 ( 3 , V_24 -> V_52 ) ) {
V_3 = F_3 ( V_2 -> V_5 ,
V_36 ) ;
if ( V_3 < 0 )
goto V_51;
V_28 [ 6 ] = V_3 ;
}
F_26 ( V_24 , V_28 ,
F_27 ( V_24 ) ) ;
V_51:
F_28 ( V_24 -> V_53 ) ;
return V_54 ;
}
static int F_29 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 & ~ V_55 ) ;
}
static int F_30 ( struct V_56 * V_5 ,
const struct V_57 * V_58 )
{
struct V_1 * V_2 ;
struct V_23 * V_24 ;
int V_3 ;
V_3 = F_3 ( V_5 , V_59 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 != V_60 )
return - V_61 ;
V_24 = F_31 ( & V_5 -> V_11 , sizeof( * V_2 ) ) ;
if ( ! V_24 )
return - V_62 ;
V_2 = F_15 ( V_24 ) ;
V_2 -> V_5 = V_5 ;
F_32 ( & V_2 -> V_14 ) ;
F_33 ( V_5 , V_24 ) ;
V_24 -> V_63 = & V_64 ;
V_24 -> V_65 = V_58 -> V_65 ;
V_24 -> V_11 . V_66 = & V_5 -> V_11 ;
V_24 -> V_67 = V_68 ;
V_24 -> V_69 = V_70 ;
V_24 -> V_71 = F_34 ( V_70 ) ;
V_24 -> V_72 = V_73 ;
V_2 -> V_7 = V_74 << V_41 ;
V_3 = F_2 ( V_5 , V_6 ,
V_2 -> V_7 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_5 , V_75 ,
V_76 ) ;
if ( V_3 < 0 )
goto V_77;
V_3 = F_35 ( V_24 , NULL ,
F_24 , NULL ) ;
if ( V_3 < 0 )
goto V_77;
V_3 = F_36 ( V_24 ) ;
if ( V_3 < 0 )
goto V_78;
return 0 ;
V_78:
F_37 ( V_24 ) ;
V_77:
F_29 ( F_15 ( V_24 ) ) ;
return V_3 ;
}
static int F_38 ( struct V_56 * V_5 )
{
struct V_23 * V_24 = F_39 ( V_5 ) ;
F_40 ( V_24 ) ;
F_37 ( V_24 ) ;
F_29 ( F_15 ( V_24 ) ) ;
return 0 ;
}
static int F_41 ( struct V_17 * V_11 )
{
return F_29 ( F_15 ( F_39 (
F_42 ( V_11 ) ) ) ) ;
}
static int F_43 ( struct V_17 * V_11 )
{
struct V_1 * V_2 = F_15 ( F_39 (
F_42 ( V_11 ) ) ) ;
return F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 ) ;
}
