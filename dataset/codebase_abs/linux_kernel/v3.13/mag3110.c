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
switch ( V_26 -> type ) {
case V_31 :
V_3 = F_6 ( V_2 , V_28 ) ;
if ( V_3 < 0 )
return V_3 ;
* V_21 = F_16 (
F_17 ( V_28 [ V_26 -> V_32 ] ) , 15 ) ;
return V_33 ;
case V_34 :
F_7 ( & V_2 -> V_14 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_8 ( & V_2 -> V_14 ) ;
return V_3 ;
}
V_3 = F_3 ( V_2 -> V_5 ,
V_35 ) ;
F_8 ( & V_2 -> V_14 ) ;
if ( V_3 < 0 )
return V_3 ;
* V_21 = F_16 ( V_3 , 7 ) ;
return V_33 ;
default:
return - V_36 ;
}
case V_37 :
* V_21 = 0 ;
* V_22 = 1000 ;
return V_38 ;
case V_39 :
V_29 = V_2 -> V_7 >> V_40 ;
* V_21 = V_20 [ V_29 ] [ 0 ] ;
* V_22 = V_20 [ V_29 ] [ 1 ] ;
return V_38 ;
}
return - V_36 ;
}
static int F_18 ( struct V_23 * V_24 ,
struct V_25 const * V_26 ,
int V_21 , int V_22 , long V_27 )
{
struct V_1 * V_2 = F_15 ( V_24 ) ;
int V_41 ;
switch ( V_27 ) {
case V_39 :
V_41 = F_12 ( V_2 , V_21 , V_22 ) ;
if ( V_41 < 0 )
return - V_36 ;
V_2 -> V_7 &= ~ V_42 ;
V_2 -> V_7 |= V_41 << V_40 ;
return F_2 ( V_2 -> V_5 ,
V_6 , V_2 -> V_7 ) ;
default:
return - V_36 ;
}
}
static T_3 F_19 ( int V_43 , void * V_44 )
{
struct V_45 * V_46 = V_44 ;
struct V_23 * V_24 = V_46 -> V_24 ;
struct V_1 * V_2 = F_15 ( V_24 ) ;
V_16 V_28 [ 16 ] ;
int V_3 ;
V_3 = F_6 ( V_2 , ( T_1 * ) V_28 ) ;
if ( V_3 < 0 )
goto V_47;
if ( F_20 ( 3 , V_24 -> V_48 ) ) {
V_3 = F_3 ( V_2 -> V_5 ,
V_35 ) ;
if ( V_3 < 0 )
goto V_47;
V_28 [ 6 ] = V_3 ;
}
F_21 ( V_24 , V_28 ,
F_22 () ) ;
V_47:
F_23 ( V_24 -> V_49 ) ;
return V_50 ;
}
static int F_24 ( struct V_51 * V_5 ,
const struct V_52 * V_53 )
{
struct V_1 * V_2 ;
struct V_23 * V_24 ;
int V_3 ;
V_3 = F_3 ( V_5 , V_54 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 != V_55 )
return - V_56 ;
V_24 = F_25 ( & V_5 -> V_11 , sizeof( * V_2 ) ) ;
if ( ! V_24 )
return - V_57 ;
V_2 = F_15 ( V_24 ) ;
V_2 -> V_5 = V_5 ;
F_26 ( & V_2 -> V_14 ) ;
F_27 ( V_5 , V_24 ) ;
V_24 -> V_58 = & V_59 ;
V_24 -> V_60 = V_53 -> V_60 ;
V_24 -> V_11 . V_61 = & V_5 -> V_11 ;
V_24 -> V_62 = V_63 ;
V_24 -> V_64 = V_65 ;
V_24 -> V_66 = F_28 ( V_65 ) ;
V_24 -> V_67 = V_68 ;
V_2 -> V_7 = V_69 ;
V_3 = F_2 ( V_5 , V_6 ,
V_2 -> V_7 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_5 , V_70 ,
V_71 | V_72 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_29 ( V_24 , NULL ,
F_19 , NULL ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_30 ( V_24 ) ;
if ( V_3 < 0 )
goto V_73;
return 0 ;
V_73:
F_31 ( V_24 ) ;
return V_3 ;
}
static int F_32 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 & ~ V_74 ) ;
}
static int F_33 ( struct V_51 * V_5 )
{
struct V_23 * V_24 = F_34 ( V_5 ) ;
F_35 ( V_24 ) ;
F_31 ( V_24 ) ;
F_32 ( F_15 ( V_24 ) ) ;
return 0 ;
}
static int F_36 ( struct V_17 * V_11 )
{
return F_32 ( F_15 ( F_34 (
F_37 ( V_11 ) ) ) ) ;
}
static int F_38 ( struct V_17 * V_11 )
{
struct V_1 * V_2 = F_15 ( F_34 (
F_37 ( V_11 ) ) ) ;
return F_2 ( V_2 -> V_5 , V_6 ,
V_2 -> V_7 ) ;
}
