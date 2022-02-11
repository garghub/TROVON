static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned long V_4 ;
V_3 = F_2 ( V_2 -> V_5 ,
V_6 ) ;
if ( V_3 < 0 )
return V_3 ;
V_4 = V_3 * V_2 -> V_7 / V_8 ;
if ( V_4 > 0xffff )
V_4 = 0xffff ;
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_9 )
{
int V_3 ;
V_3 = F_4 ( V_2 -> V_5 , V_10 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = V_3 | V_11 ;
V_3 = V_3 & ~ V_12 ;
V_3 = V_3 | ( V_9 << V_13 ) ;
V_3 = F_5 ( V_2 -> V_5 , V_10 , V_3 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_9 == V_2 -> V_14 )
return 0 ;
V_3 = F_5 ( V_2 -> V_5 , V_15 ,
V_16 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_14 = V_9 ;
F_6 ( V_17 ) ;
return 0 ;
}
static int F_7 ( struct V_18 * V_19 ,
struct V_20 const * V_21 , int * V_22 ,
int * V_23 , long V_24 )
{
struct V_1 * V_2 = F_8 ( V_19 ) ;
int V_3 ;
switch ( V_24 ) {
case V_25 :
switch ( V_21 -> type ) {
case V_26 :
F_9 ( & V_2 -> V_27 ) ;
V_3 = F_3 ( V_2 , V_28 ) ;
if ( V_3 < 0 )
goto V_29;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
goto V_29;
F_10 ( & V_2 -> V_27 ) ;
* V_22 = V_3 ;
return V_30 ;
case V_31 :
F_9 ( & V_2 -> V_27 ) ;
V_3 = F_3 ( V_2 , V_32 ) ;
if ( V_3 < 0 )
goto V_29;
V_3 = F_2 ( V_2 -> V_5 ,
V_33 ) ;
if ( V_3 < 0 )
goto V_29;
F_10 ( & V_2 -> V_27 ) ;
* V_22 = V_3 ;
return V_30 ;
default:
return - V_34 ;
}
case V_35 :
V_3 = F_4 ( V_2 -> V_5 , V_36 ) ;
if ( V_3 < 0 )
return V_3 ;
* V_22 = 0 ;
* V_23 = V_37 [ V_3 & V_38 ] ;
return V_39 ;
default:
return - V_34 ;
}
return - V_34 ;
V_29:
F_10 ( & V_2 -> V_27 ) ;
return V_3 ;
}
static int F_11 ( struct V_1 * V_2 , int V_40 )
{
T_2 V_41 = F_12 ( V_2 -> V_42 [ V_40 ] ) ;
int V_3 ;
V_3 = F_5 ( V_2 -> V_5 , V_43 ,
( ( T_1 * ) & V_41 ) [ 0 ] ) ;
if ( V_3 < 0 )
return V_3 ;
return F_5 ( V_2 -> V_5 , V_43 + 1 ,
( ( T_1 * ) & V_41 ) [ 1 ] ) ;
}
static int F_13 ( struct V_1 * V_2 , int V_40 )
{
int V_3 ;
V_3 = F_4 ( V_2 -> V_5 , V_36 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = V_3 & ( ~ V_38 ) ;
V_3 |= V_40 ;
V_3 = F_5 ( V_2 -> V_5 , V_36 , V_3 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_11 ( V_2 , V_40 ) ;
}
static int F_14 ( struct V_18 * V_19 ,
struct V_20 const * V_21 , int V_22 ,
int V_23 , long V_24 )
{
struct V_1 * V_2 = F_8 ( V_19 ) ;
int V_3 , V_44 ;
switch ( V_24 ) {
case V_35 :
if ( V_22 != 0 )
return - V_34 ;
for ( V_44 = 0 ; V_44 < F_15 ( V_37 ) ; V_44 ++ )
if ( V_23 == V_37 [ V_44 ] ) {
F_9 ( & V_2 -> V_27 ) ;
V_3 = F_13 ( V_2 , V_44 ) ;
F_10 ( & V_2 -> V_27 ) ;
return V_3 ;
}
break;
default:
return - V_34 ;
}
return - V_34 ;
}
static int F_16 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_8 ( V_19 ) ;
return F_5 ( V_2 -> V_5 , V_45 ,
V_46 ) ;
}
static int F_17 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_8 ( V_19 ) ;
int V_44 , V_3 ;
V_3 = F_16 ( V_19 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_14 = 0 ;
for ( V_44 = 0 ; V_44 < F_15 ( V_47 ) ; V_44 ++ ) {
V_3 = F_5 ( V_2 -> V_5 ,
V_47 [ V_44 ] . V_48 ,
V_47 [ V_44 ] . V_22 ) ;
if ( V_3 < 0 )
return V_3 ;
}
return 0 ;
}
static void F_18 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_8 ( V_19 ) ;
if ( F_19 ( & V_2 -> V_5 -> V_49 , L_1 ,
& V_2 -> V_7 ) )
V_2 -> V_7 = V_8 ;
if ( F_20 ( & V_2 -> V_5 -> V_49 ,
L_2 ,
V_2 -> V_42 ,
F_15 ( V_50 ) ) )
V_2 -> V_42 = V_50 ;
if ( F_21 ( & V_2 -> V_5 -> V_49 ,
L_3 ,
& V_2 -> V_51 ) )
V_2 -> V_51 = V_52 ;
if ( F_21 ( & V_2 -> V_5 -> V_49 ,
L_4 ,
& V_2 -> V_53 ) )
V_2 -> V_53 = V_54 ;
}
static int F_22 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_8 ( V_19 ) ;
int V_3 ;
V_3 = F_11 ( V_2 , V_55 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_5 ( V_2 -> V_5 ,
V_56 ,
V_2 -> V_53 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_5 ( V_2 -> V_5 ,
V_57 ,
V_2 -> V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_5 ( V_2 -> V_5 , V_58 ,
V_59 ) ;
}
static int F_23 ( struct V_60 * V_5 ,
const struct V_61 * V_62 )
{
struct V_1 * V_2 ;
struct V_18 * V_19 ;
int V_3 ;
V_19 = F_24 ( & V_5 -> V_49 , sizeof( * V_2 ) ) ;
if ( ! V_19 )
return - V_63 ;
V_2 = F_8 ( V_19 ) ;
F_25 ( V_5 , V_19 ) ;
V_2 -> V_5 = V_5 ;
F_26 ( & V_2 -> V_27 ) ;
V_19 -> V_49 . V_64 = & V_5 -> V_49 ;
V_19 -> V_65 = & V_66 ;
V_19 -> V_67 = V_68 ;
V_19 -> V_69 = V_70 ;
V_19 -> V_71 = F_15 ( V_70 ) ;
V_19 -> V_72 = V_73 ;
V_3 = F_4 ( V_2 -> V_5 , V_74 ) ;
if ( V_3 != V_75 ) {
F_27 ( & V_2 -> V_5 -> V_49 ,
L_5 ) ;
return ( V_3 < 0 ) ? V_3 : - V_76 ;
}
F_18 ( V_19 ) ;
V_3 = F_17 ( V_19 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_22 ( V_19 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_28 ( V_19 ) ;
}
static int F_29 ( struct V_60 * V_5 )
{
F_30 ( F_31 ( V_5 ) ) ;
return F_5 ( V_5 , V_10 ,
V_77 ) ;
}
