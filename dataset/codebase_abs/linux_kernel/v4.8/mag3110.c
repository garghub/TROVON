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
if ( F_16 ( V_24 ) )
return - V_31 ;
switch ( V_26 -> type ) {
case V_32 :
V_3 = F_6 ( V_2 , V_28 ) ;
if ( V_3 < 0 )
return V_3 ;
* V_21 = F_17 (
F_18 ( V_28 [ V_26 -> V_33 ] ) , 15 ) ;
return V_34 ;
case V_35 :
F_7 ( & V_2 -> V_14 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_8 ( & V_2 -> V_14 ) ;
return V_3 ;
}
V_3 = F_3 ( V_2 -> V_5 ,
V_36 ) ;
F_8 ( & V_2 -> V_14 ) ;
if ( V_3 < 0 )
return V_3 ;
* V_21 = F_17 ( V_3 , 7 ) ;
return V_34 ;
default:
return - V_37 ;
}
case V_38 :
switch ( V_26 -> type ) {
case V_32 :
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
V_3 = F_19 ( V_2 -> V_5 ,
V_43 + 2 * V_26 -> V_33 ) ;
if ( V_3 < 0 )
return V_3 ;
* V_21 = F_17 ( V_3 >> 1 , 14 ) ;
return V_34 ;
}
return - V_37 ;
}
static int F_20 ( struct V_23 * V_24 ,
struct V_25 const * V_26 ,
int V_21 , int V_22 , long V_27 )
{
struct V_1 * V_2 = F_15 ( V_24 ) ;
int V_44 ;
if ( F_16 ( V_24 ) )
return - V_31 ;
switch ( V_27 ) {
case V_40 :
V_44 = F_12 ( V_2 , V_21 , V_22 ) ;
if ( V_44 < 0 )
return - V_37 ;
V_2 -> V_7 &= ~ V_45 ;
V_2 -> V_7 |= V_44 << V_41 ;
return F_2 ( V_2 -> V_5 ,
V_6 , V_2 -> V_7 ) ;
case V_42 :
if ( V_21 < - 10000 || V_21 > 10000 )
return - V_37 ;
return F_21 ( V_2 -> V_5 ,
V_43 + 2 * V_26 -> V_33 , V_21 << 1 ) ;
default:
return - V_37 ;
}
}
static T_3 F_22 ( int V_46 , void * V_47 )
{
struct V_48 * V_49 = V_47 ;
struct V_23 * V_24 = V_49 -> V_24 ;
struct V_1 * V_2 = F_15 ( V_24 ) ;
V_16 V_28 [ 16 ] ;
int V_3 ;
V_3 = F_6 ( V_2 , ( T_1 * ) V_28 ) ;
if ( V_3 < 0 )
goto V_50;
if ( F_23 ( 3 , V_24 -> V_51 ) ) {
V_3 = F_3 ( V_2 -> V_5 ,
V_36 ) ;
if ( V_3 < 0 )
goto V_50;
V_28 [ 6 ] = V_3 ;
}
F_24 ( V_24 , V_28 ,
F_25 ( V_24 ) ) ;
V_50:
F_26 ( V_24 -> V_52 ) ;
return V_53 ;
}
static int F_27 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 & ~ V_54 ) ;
}
static int F_28 ( struct V_55 * V_5 ,
const struct V_56 * V_57 )
{
struct V_1 * V_2 ;
struct V_23 * V_24 ;
int V_3 ;
V_3 = F_3 ( V_5 , V_58 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 != V_59 )
return - V_60 ;
V_24 = F_29 ( & V_5 -> V_11 , sizeof( * V_2 ) ) ;
if ( ! V_24 )
return - V_61 ;
V_2 = F_15 ( V_24 ) ;
V_2 -> V_5 = V_5 ;
F_30 ( & V_2 -> V_14 ) ;
F_31 ( V_5 , V_24 ) ;
V_24 -> V_62 = & V_63 ;
V_24 -> V_64 = V_57 -> V_64 ;
V_24 -> V_11 . V_65 = & V_5 -> V_11 ;
V_24 -> V_66 = V_67 ;
V_24 -> V_68 = V_69 ;
V_24 -> V_70 = F_32 ( V_69 ) ;
V_24 -> V_71 = V_72 ;
V_2 -> V_7 = V_73 << V_41 ;
V_3 = F_2 ( V_5 , V_6 ,
V_2 -> V_7 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_5 , V_74 ,
V_75 ) ;
if ( V_3 < 0 )
goto V_76;
V_3 = F_33 ( V_24 , NULL ,
F_22 , NULL ) ;
if ( V_3 < 0 )
goto V_76;
V_3 = F_34 ( V_24 ) ;
if ( V_3 < 0 )
goto V_77;
return 0 ;
V_77:
F_35 ( V_24 ) ;
V_76:
F_27 ( F_15 ( V_24 ) ) ;
return V_3 ;
}
static int F_36 ( struct V_55 * V_5 )
{
struct V_23 * V_24 = F_37 ( V_5 ) ;
F_38 ( V_24 ) ;
F_35 ( V_24 ) ;
F_27 ( F_15 ( V_24 ) ) ;
return 0 ;
}
static int F_39 ( struct V_17 * V_11 )
{
return F_27 ( F_15 ( F_37 (
F_40 ( V_11 ) ) ) ) ;
}
static int F_41 ( struct V_17 * V_11 )
{
struct V_1 * V_2 = F_15 ( F_37 (
F_40 ( V_11 ) ) ) ;
return F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 ) ;
}
