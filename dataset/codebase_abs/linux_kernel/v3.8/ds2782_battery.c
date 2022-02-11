static inline int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_3 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_7 , L_1 ) ;
return V_5 ;
}
* V_4 = V_5 ;
return 0 ;
}
static inline int F_4 ( struct V_1 * V_2 , int V_8 ,
T_2 * V_4 )
{
int V_5 ;
V_5 = F_5 ( V_2 -> V_6 , V_8 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_7 , L_1 ) ;
return V_5 ;
}
* V_4 = F_6 ( V_5 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , int * V_9 )
{
T_2 V_10 ;
int V_11 ;
V_11 = F_4 ( V_2 , V_12 , & V_10 ) ;
if ( V_11 )
return V_11 ;
* V_9 = ( ( V_10 / 32 ) * 125 ) / 100 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , int * V_13 )
{
int V_14 ;
int V_11 ;
T_1 V_15 ;
T_2 V_10 ;
V_11 = F_1 ( V_2 , V_16 , & V_15 ) ;
if ( V_11 )
return V_11 ;
if ( V_15 == 0 ) {
F_3 ( & V_2 -> V_6 -> V_7 , L_2 ) ;
return - V_17 ;
}
V_14 = 1000 / V_15 ;
F_9 ( & V_2 -> V_6 -> V_7 , L_3 ,
V_14 ) ;
V_11 = F_4 ( V_2 , V_18 , & V_10 ) ;
if ( V_11 )
return V_11 ;
* V_13 = V_10 * ( V_19 / V_14 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , int * V_20 )
{
T_2 V_10 ;
int V_11 ;
V_11 = F_4 ( V_2 , V_21 , & V_10 ) ;
if ( V_11 )
return V_11 ;
* V_20 = ( V_10 / 32 ) * 4800 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int * V_22 )
{
int V_11 ;
T_1 V_10 ;
V_11 = F_1 ( V_2 , V_23 , & V_10 ) ;
if ( V_11 )
return V_11 ;
* V_22 = V_10 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , int * V_13 )
{
int V_11 ;
T_2 V_10 ;
V_11 = F_4 ( V_2 , V_18 , & V_10 ) ;
if ( V_11 )
return V_11 ;
* V_13 = ( V_10 / 16 ) * ( V_24 / V_2 -> V_25 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int * V_20 )
{
T_2 V_10 ;
int V_11 ;
V_11 = F_4 ( V_2 , V_21 , & V_10 ) ;
if ( V_11 )
return V_11 ;
* V_20 = ( V_10 / 8 ) * 1220 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int * V_22 )
{
int V_11 ;
T_1 V_10 ;
V_11 = F_1 ( V_2 , V_26 , & V_10 ) ;
if ( V_11 )
return V_11 ;
* V_22 = V_10 / 2 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int * V_27 )
{
int V_11 ;
int V_13 ;
int V_22 ;
V_11 = V_2 -> V_28 -> V_29 ( V_2 , & V_13 ) ;
if ( V_11 )
return V_11 ;
V_11 = V_2 -> V_28 -> V_30 ( V_2 , & V_22 ) ;
if ( V_11 )
return V_11 ;
if ( V_22 == 100 )
* V_27 = V_31 ;
else if ( V_13 == 0 )
* V_27 = V_32 ;
else if ( V_13 < 0 )
* V_27 = V_33 ;
else
* V_27 = V_34 ;
return 0 ;
}
static int F_16 ( struct V_35 * V_36 ,
enum V_37 V_38 ,
union V_39 * V_4 )
{
struct V_1 * V_2 = F_17 ( V_36 ) ;
int V_5 ;
switch ( V_38 ) {
case V_40 :
V_5 = F_15 ( V_2 , & V_4 -> V_41 ) ;
break;
case V_42 :
V_5 = V_2 -> V_28 -> V_30 ( V_2 , & V_4 -> V_41 ) ;
break;
case V_43 :
V_5 = V_2 -> V_28 -> V_44 ( V_2 , & V_4 -> V_41 ) ;
break;
case V_45 :
V_5 = V_2 -> V_28 -> V_29 ( V_2 , & V_4 -> V_41 ) ;
break;
case V_46 :
V_5 = F_7 ( V_2 , & V_4 -> V_41 ) ;
break;
default:
V_5 = - V_47 ;
}
return V_5 ;
}
static void F_18 ( struct V_35 * V_48 )
{
V_48 -> type = V_49 ;
V_48 -> V_50 = V_51 ;
V_48 -> V_52 = F_19 ( V_51 ) ;
V_48 -> V_53 = F_16 ;
V_48 -> V_54 = NULL ;
}
static int F_20 ( struct V_55 * V_6 )
{
struct V_1 * V_2 = F_21 ( V_6 ) ;
F_22 ( & V_2 -> V_48 ) ;
F_23 ( V_2 -> V_48 . V_56 ) ;
F_24 ( & V_57 ) ;
F_25 ( & V_58 , V_2 -> V_59 ) ;
F_26 ( & V_57 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_55 * V_6 ,
const struct V_60 * V_59 )
{
struct V_61 * V_62 = V_6 -> V_7 . V_63 ;
struct V_1 * V_2 ;
int V_5 ;
int V_64 ;
if ( V_59 -> V_65 == V_66 && ! V_62 ) {
F_3 ( & V_6 -> V_7 , L_4 ) ;
return - V_47 ;
}
V_5 = F_28 ( & V_58 , V_67 ) ;
if ( V_5 == 0 ) {
V_5 = - V_68 ;
goto V_69;
}
F_24 ( & V_57 ) ;
V_5 = F_29 ( & V_58 , V_6 , & V_64 ) ;
F_26 ( & V_57 ) ;
if ( V_5 < 0 )
goto V_69;
V_2 = F_30 ( sizeof( * V_2 ) , V_67 ) ;
if ( ! V_2 ) {
V_5 = - V_68 ;
goto V_70;
}
V_2 -> V_48 . V_56 = F_31 ( V_67 , L_5 , V_6 -> V_56 , V_64 ) ;
if ( ! V_2 -> V_48 . V_56 ) {
V_5 = - V_68 ;
goto V_71;
}
if ( V_59 -> V_65 == V_66 )
V_2 -> V_25 = V_62 -> V_25 ;
F_32 ( V_6 , V_2 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_59 = V_64 ;
V_2 -> V_28 = & V_72 [ V_59 -> V_65 ] ;
F_18 ( & V_2 -> V_48 ) ;
V_5 = F_33 ( & V_6 -> V_7 , & V_2 -> V_48 ) ;
if ( V_5 ) {
F_3 ( & V_6 -> V_7 , L_6 ) ;
goto V_73;
}
return 0 ;
V_73:
F_23 ( V_2 -> V_48 . V_56 ) ;
V_71:
F_23 ( V_2 ) ;
V_70:
F_24 ( & V_57 ) ;
F_25 ( & V_58 , V_64 ) ;
F_26 ( & V_57 ) ;
V_69:
return V_5 ;
}
