static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 150 ;
while ( V_3 -- > 0 ) {
int V_4 = F_2 ( V_2 -> V_5 ,
V_6 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( ( V_4 & V_7 ) == V_7 )
return 0 ;
F_3 ( 20 ) ;
}
F_4 ( & V_2 -> V_5 -> V_8 , L_1 ) ;
return - V_9 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_10 [ 3 ] )
{
int V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_6 ( V_2 -> V_5 ,
V_11 , 3 * sizeof( T_1 ) , ( V_12 * ) V_10 ) ;
}
static T_2 F_7 ( struct V_13 * V_8 ,
struct V_14 * V_15 , char * V_10 )
{
return F_8 ( V_10 , V_16 ,
F_9 ( V_16 ) ) ;
}
static T_2 F_10 ( struct V_13 * V_8 ,
struct V_14 * V_15 , char * V_10 )
{
return F_8 ( V_10 , V_17 ,
F_9 ( V_17 ) ) ;
}
static int F_11 ( struct V_1 * V_2 ,
int V_18 , int V_19 )
{
return F_12 ( V_16 ,
F_9 ( V_16 ) , V_18 , V_19 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
int V_18 , int V_19 )
{
return F_12 ( V_17 ,
F_9 ( V_17 ) , V_18 , V_19 ) ;
}
static int F_14 ( struct V_20 * V_21 ,
struct V_22 const * V_23 ,
int * V_18 , int * V_19 , long V_24 )
{
struct V_1 * V_2 = F_15 ( V_21 ) ;
T_1 V_25 [ 3 ] ;
int V_26 , V_4 ;
switch ( V_24 ) {
case V_27 :
if ( F_16 ( V_21 ) )
return - V_28 ;
F_17 ( & V_2 -> V_29 ) ;
V_4 = F_5 ( V_2 , V_25 ) ;
F_18 ( & V_2 -> V_29 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_18 = F_19 (
F_20 ( V_25 [ V_23 -> V_30 ] ) >> 4 , 11 ) ;
return V_31 ;
case V_32 :
V_26 = V_2 -> V_33 & V_34 ;
* V_18 = V_17 [ V_26 ] [ 0 ] ;
* V_19 = V_17 [ V_26 ] [ 1 ] ;
return V_35 ;
case V_36 :
V_26 = ( V_2 -> V_37 & V_38 ) >>
V_39 ;
* V_18 = V_16 [ V_26 ] [ 0 ] ;
* V_19 = V_16 [ V_26 ] [ 1 ] ;
return V_35 ;
case V_40 :
V_4 = F_2 ( V_2 -> V_5 , V_41 +
V_23 -> V_30 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_18 = F_19 ( V_4 , 7 ) ;
return V_31 ;
}
return - V_42 ;
}
static int F_21 ( struct V_1 * V_2 )
{
return F_22 ( V_2 -> V_5 , V_43 ,
V_2 -> V_37 & ~ V_44 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
return F_22 ( V_2 -> V_5 , V_43 ,
V_2 -> V_37 ) ;
}
static int F_24 ( struct V_1 * V_2 , V_12 V_45 , V_12 V_18 )
{
int V_4 ;
F_17 ( & V_2 -> V_29 ) ;
V_4 = F_21 ( V_2 ) ;
if ( V_4 < 0 )
goto V_46;
V_4 = F_22 ( V_2 -> V_5 , V_45 , V_18 ) ;
if ( V_4 < 0 )
goto V_46;
V_4 = F_23 ( V_2 ) ;
if ( V_4 < 0 )
goto V_46;
V_4 = 0 ;
V_46:
F_18 ( & V_2 -> V_29 ) ;
return V_4 ;
}
static int F_25 ( struct V_20 * V_21 ,
struct V_22 const * V_23 ,
int V_18 , int V_19 , long V_24 )
{
struct V_1 * V_2 = F_15 ( V_21 ) ;
int V_26 ;
if ( F_16 ( V_21 ) )
return - V_28 ;
switch ( V_24 ) {
case V_36 :
V_26 = F_11 ( V_2 , V_18 , V_19 ) ;
if ( V_26 < 0 )
return - V_42 ;
V_2 -> V_37 &= ~ V_38 ;
V_2 -> V_37 |= V_26 << V_39 ;
return F_24 ( V_2 , V_43 ,
V_2 -> V_37 ) ;
case V_32 :
V_26 = F_13 ( V_2 , V_18 , V_19 ) ;
if ( V_26 < 0 )
return - V_42 ;
V_2 -> V_33 &= ~ V_34 ;
V_2 -> V_33 |= V_26 ;
return F_24 ( V_2 , V_47 ,
V_2 -> V_33 ) ;
case V_40 :
if ( V_18 < - 128 || V_18 > 127 )
return - V_42 ;
return F_24 ( V_2 , V_41 +
V_23 -> V_30 , V_18 ) ;
default:
return - V_42 ;
}
}
static T_3 F_26 ( int V_48 , void * V_49 )
{
struct V_50 * V_51 = V_49 ;
struct V_20 * V_21 = V_51 -> V_21 ;
struct V_1 * V_2 = F_15 ( V_21 ) ;
V_12 V_25 [ 16 ] ;
int V_4 ;
V_4 = F_5 ( V_2 , ( T_1 * ) V_25 ) ;
if ( V_4 < 0 )
goto V_52;
F_27 ( V_21 , V_25 ,
F_28 () ) ;
V_52:
F_29 ( V_21 -> V_53 ) ;
return V_54 ;
}
static int F_30 ( struct V_55 * V_5 ,
const struct V_56 * V_57 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
int V_4 ;
V_4 = F_2 ( V_5 , V_58 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 != V_59 )
return - V_60 ;
V_21 = F_31 ( & V_5 -> V_8 , sizeof( * V_2 ) ) ;
if ( ! V_21 )
return - V_61 ;
V_2 = F_15 ( V_21 ) ;
V_2 -> V_5 = V_5 ;
F_32 ( & V_2 -> V_29 ) ;
F_33 ( V_5 , V_21 ) ;
V_21 -> V_62 = & V_63 ;
V_21 -> V_64 = V_57 -> V_64 ;
V_21 -> V_8 . V_65 = & V_5 -> V_8 ;
V_21 -> V_66 = V_67 ;
V_21 -> V_68 = V_69 ;
V_21 -> V_70 = F_9 ( V_69 ) ;
V_21 -> V_71 = V_72 ;
V_2 -> V_37 = V_44 |
( V_73 << V_39 ) ;
V_4 = F_22 ( V_5 , V_43 ,
V_2 -> V_37 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_33 = V_74 ;
V_4 = F_22 ( V_5 , V_47 ,
V_2 -> V_33 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_34 ( V_21 , NULL ,
F_26 , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_35 ( V_21 ) ;
if ( V_4 < 0 )
goto V_75;
return 0 ;
V_75:
F_36 ( V_21 ) ;
return V_4 ;
}
static int F_37 ( struct V_55 * V_5 )
{
struct V_20 * V_21 = F_38 ( V_5 ) ;
F_39 ( V_21 ) ;
F_36 ( V_21 ) ;
F_21 ( F_15 ( V_21 ) ) ;
return 0 ;
}
static int F_40 ( struct V_13 * V_8 )
{
return F_21 ( F_15 ( F_38 (
F_41 ( V_8 ) ) ) ) ;
}
static int F_42 ( struct V_13 * V_8 )
{
return F_23 ( F_15 ( F_38 (
F_41 ( V_8 ) ) ) ) ;
}
