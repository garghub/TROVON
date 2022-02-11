static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_4 ,
enum V_5 V_6 )
{
struct V_1 * V_7 = F_1 ( V_4 ) ;
unsigned int V_8 ;
switch ( V_6 ) {
case V_9 :
case V_10 :
V_8 = 1 ;
break;
default:
V_8 = 0 ;
break;
}
F_4 ( V_7 -> V_11 , V_8 ) ;
return 0 ;
}
static int F_5 ( struct V_12 * V_13 ,
struct V_14 const * V_15 ,
int * V_8 ,
int * V_16 ,
long V_17 )
{
struct V_1 * V_7 = F_6 ( V_13 ) ;
switch ( V_17 ) {
case V_18 :
return F_7 ( V_13 , V_15 , V_8 ) ;
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
static int F_8 ( struct V_2 * V_4 ,
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
static int F_9 ( struct V_36 * V_37 )
{
struct V_1 * V_7 ;
struct V_12 * V_13 ;
int V_38 , V_39 = 0 ;
V_13 = F_10 ( & V_37 -> V_40 , sizeof( * V_7 ) ) ;
if ( ! V_13 )
return - V_41 ;
V_7 = F_6 ( V_13 ) ;
V_7 -> V_21 = 1 ;
F_11 ( & V_7 -> V_3 , V_13 , V_37 , & V_42 ) ;
V_7 -> V_43 = F_12 ( & V_37 -> V_40 , L_1 ) ;
if ( F_13 ( V_7 -> V_43 ) )
return F_14 ( V_7 -> V_43 ) ;
V_38 = F_15 ( V_7 -> V_43 ) ;
if ( V_38 ) {
F_16 ( & V_37 -> V_40 , L_2 ) ;
return V_38 ;
}
V_39 = F_17 ( V_7 -> V_43 ) ;
V_7 -> V_30 =
& V_44 [ F_18 ( V_37 ) -> V_45 ] ;
if ( V_39 )
V_7 -> V_20 = V_39 / 1000 ;
else
F_19 ( & V_37 -> V_40 , L_3 ) ;
F_20 ( V_37 , V_13 ) ;
V_13 -> V_40 . V_46 = & V_37 -> V_40 ;
V_13 -> V_47 = F_18 ( V_37 ) -> V_47 ;
V_13 -> V_48 = V_49 ;
V_13 -> V_50 = & V_7 -> V_30 -> V_51 ;
V_13 -> V_52 = 1 ;
V_13 -> V_53 = & V_54 ;
V_7 -> V_11 = F_21 ( & V_37 -> V_40 ,
L_4 ,
V_55 ) ;
if ( F_13 ( V_7 -> V_11 ) ) {
V_38 = F_14 ( V_7 -> V_11 ) ;
F_16 ( & V_37 -> V_40 , L_5 ,
V_38 ) ;
goto V_56;
}
V_38 = F_22 ( V_13 ) ;
if ( V_38 )
goto V_56;
V_38 = F_23 ( V_13 ) ;
if ( V_38 )
goto V_57;
return 0 ;
V_57:
F_24 ( V_13 ) ;
V_56:
F_25 ( V_7 -> V_43 ) ;
return V_38 ;
}
static int F_26 ( struct V_36 * V_37 )
{
struct V_12 * V_13 = F_27 ( V_37 ) ;
struct V_1 * V_7 = F_6 ( V_13 ) ;
F_28 ( V_13 ) ;
F_24 ( V_13 ) ;
F_25 ( V_7 -> V_43 ) ;
return 0 ;
}
