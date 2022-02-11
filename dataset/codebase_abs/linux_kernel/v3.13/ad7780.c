static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_4 ,
enum V_5 V_6 )
{
struct V_1 * V_7 = F_1 ( V_4 ) ;
unsigned V_8 ;
switch ( V_6 ) {
case V_9 :
case V_10 :
V_8 = 1 ;
break;
default:
V_8 = 0 ;
break;
}
if ( F_4 ( V_7 -> V_11 ) )
F_5 ( V_7 -> V_11 , V_8 ) ;
return 0 ;
}
static int F_6 ( struct V_12 * V_13 ,
struct V_14 const * V_15 ,
int * V_8 ,
int * V_16 ,
long V_17 )
{
struct V_1 * V_7 = F_7 ( V_13 ) ;
switch ( V_17 ) {
case V_18 :
return F_8 ( V_13 , V_15 , V_8 ) ;
case V_19 :
* V_8 = V_7 -> V_20 * V_7 -> V_21 ;
* V_16 = V_15 -> V_22 . V_23 - 1 ;
return V_24 ;
case V_25 :
* V_8 -= ( 1 << ( V_15 -> V_22 . V_23 - 1 ) ) ;
return V_26 ;
}
return - V_27 ;
}
static int F_9 ( struct V_2 * V_4 ,
unsigned int V_28 )
{
struct V_1 * V_7 = F_1 ( V_4 ) ;
const struct V_29 * V_30 = V_7 -> V_30 ;
if ( ( V_28 & V_31 ) ||
( ( V_28 & V_30 -> V_32 ) != V_30 -> V_33 ) )
return - V_34 ;
if ( V_28 & V_35 )
V_7 -> V_21 = 1 ;
else
V_7 -> V_21 = 128 ;
return 0 ;
}
static int F_10 ( struct V_36 * V_37 )
{
struct V_38 * V_39 = V_37 -> V_40 . V_41 ;
struct V_1 * V_7 ;
struct V_12 * V_13 ;
int V_42 , V_43 = 0 ;
V_13 = F_11 ( & V_37 -> V_40 , sizeof( * V_7 ) ) ;
if ( V_13 == NULL )
return - V_44 ;
V_7 = F_7 ( V_13 ) ;
V_7 -> V_21 = 1 ;
F_12 ( & V_7 -> V_3 , V_13 , V_37 , & V_45 ) ;
V_7 -> V_46 = F_13 ( & V_37 -> V_40 , L_1 ) ;
if ( ! F_14 ( V_7 -> V_46 ) ) {
V_42 = F_15 ( V_7 -> V_46 ) ;
if ( V_42 )
return V_42 ;
V_43 = F_16 ( V_7 -> V_46 ) ;
}
V_7 -> V_30 =
& V_47 [ F_17 ( V_37 ) -> V_48 ] ;
if ( V_39 && V_39 -> V_49 )
V_7 -> V_20 = V_39 -> V_49 ;
else if ( V_43 )
V_7 -> V_20 = V_43 / 1000 ;
else
F_18 ( & V_37 -> V_40 , L_2 ) ;
F_19 ( V_37 , V_13 ) ;
V_13 -> V_40 . V_50 = & V_37 -> V_40 ;
V_13 -> V_51 = F_17 ( V_37 ) -> V_51 ;
V_13 -> V_52 = V_53 ;
V_13 -> V_54 = & V_7 -> V_30 -> V_55 ;
V_13 -> V_56 = 1 ;
V_13 -> V_57 = & V_58 ;
if ( V_39 && F_4 ( V_39 -> V_59 ) ) {
V_42 = F_20 ( & V_37 -> V_40 , V_39 -> V_59 ,
V_60 , L_3 ) ;
if ( V_42 ) {
F_21 ( & V_37 -> V_40 , L_4 ) ;
goto V_61;
}
V_7 -> V_11 = V_39 -> V_59 ;
} else {
V_7 -> V_11 = - 1 ;
}
V_42 = F_22 ( V_13 ) ;
if ( V_42 )
goto V_61;
V_42 = F_23 ( V_13 ) ;
if ( V_42 )
goto V_62;
return 0 ;
V_62:
F_24 ( V_13 ) ;
V_61:
if ( ! F_14 ( V_7 -> V_46 ) )
F_25 ( V_7 -> V_46 ) ;
return V_42 ;
}
static int F_26 ( struct V_36 * V_37 )
{
struct V_12 * V_13 = F_27 ( V_37 ) ;
struct V_1 * V_7 = F_7 ( V_13 ) ;
F_28 ( V_13 ) ;
F_24 ( V_13 ) ;
if ( ! F_14 ( V_7 -> V_46 ) )
F_25 ( V_7 -> V_46 ) ;
return 0 ;
}
