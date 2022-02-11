static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_7 = F_2 ( V_6 ) ;
int V_8 ;
V_8 = F_3 ( V_7 -> V_9 , & V_7 -> V_10 ) ;
if ( V_8 < 0 )
goto V_11;
F_4 ( V_6 , V_7 -> V_12 ,
V_4 -> V_13 ) ;
V_11:
F_5 ( V_6 -> V_14 ) ;
return V_15 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_2 ( V_6 ) ;
int V_8 ;
V_8 = F_7 ( F_8 ( V_7 -> V_16 ) , V_7 -> V_16 ) ;
if ( V_8 < 0 ) {
F_9 ( & V_7 -> V_9 -> V_17 , L_1 ,
V_8 ) ;
return V_8 ;
}
V_8 = F_10 ( V_7 -> V_18 ) ;
if ( V_8 < 0 ) {
F_9 ( & V_7 -> V_9 -> V_17 , L_2 , V_8 ) ;
F_11 ( F_8 ( V_7 -> V_16 ) , V_7 -> V_16 ) ;
return V_8 ;
}
F_12 ( V_7 -> V_19 , 0 ) ;
return 0 ;
}
static int F_13 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_2 ( V_6 ) ;
F_12 ( V_7 -> V_19 , 1 ) ;
F_14 ( 20 ) ;
F_15 ( V_7 -> V_18 ) ;
F_11 ( F_8 ( V_7 -> V_16 ) , V_7 -> V_16 ) ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 ,
const struct V_20 * V_21 , int * V_22 , int * V_23 , long V_24 )
{
struct V_7 * V_7 = F_2 ( V_6 ) ;
struct V_25 * V_26 = V_7 -> V_16 [ V_27 ] . V_28 ;
int V_29 ;
switch ( V_24 ) {
case V_30 :
V_29 = F_17 ( V_26 ) ;
if ( V_29 < 0 )
return V_29 ;
* V_22 = V_29 / 1000 ;
* V_23 = V_21 -> V_31 . V_32 ;
return V_33 ;
case V_34 :
* V_22 = F_18 ( V_7 -> V_18 ) /
V_7 -> V_35 -> V_36 ;
return V_37 ;
}
return - V_38 ;
}
static T_1 F_19 ( int V_1 , void * V_39 )
{
F_20 ( V_39 ) ;
return V_15 ;
}
static int F_21 ( struct V_40 * V_14 , bool V_41 )
{
struct V_7 * V_7 = F_22 ( V_14 ) ;
if ( V_41 )
F_23 ( V_7 -> V_9 -> V_1 ) ;
else
F_24 ( V_7 -> V_9 -> V_1 ) ;
return 0 ;
}
static int F_25 ( struct V_42 * V_9 )
{
const struct V_43 * V_44 = F_26 ( V_9 ) ;
struct V_5 * V_6 ;
struct V_7 * V_7 ;
int V_8 ;
V_6 = F_27 ( & V_9 -> V_17 , sizeof( * V_7 ) ) ;
if ( ! V_6 )
return - V_45 ;
V_7 = F_2 ( V_6 ) ;
V_7 -> V_35 = & V_46 [ V_44 -> V_47 ] ;
V_7 -> V_18 = F_28 ( & V_9 -> V_17 , L_3 ) ;
if ( F_29 ( V_7 -> V_18 ) )
return F_30 ( V_7 -> V_18 ) ;
V_7 -> V_16 [ V_48 ] . V_49 = L_4 ;
V_7 -> V_16 [ V_50 ] . V_49 = L_5 ;
V_7 -> V_16 [ V_27 ] . V_49 = L_6 ;
V_8 = F_31 ( & V_9 -> V_17 , F_8 ( V_7 -> V_16 ) ,
V_7 -> V_16 ) ;
if ( V_8 )
return V_8 ;
V_7 -> V_19 = F_32 ( & V_9 -> V_17 , L_7 ,
V_51 ) ;
if ( F_29 ( V_7 -> V_19 ) )
return F_30 ( V_7 -> V_19 ) ;
V_6 -> V_17 . V_52 = & V_9 -> V_17 ;
V_6 -> V_53 = F_26 ( V_9 ) -> V_53 ;
V_6 -> V_54 = V_55 ;
V_6 -> V_56 = V_57 ;
V_6 -> V_58 = F_8 ( V_57 ) ;
V_6 -> V_24 = & V_59 ;
if ( V_9 -> V_1 > 0 ) {
V_7 -> V_14 = F_33 ( & V_9 -> V_17 , L_8 ,
V_6 -> V_53 , V_6 -> V_44 ) ;
if ( ! V_7 -> V_14 )
return - V_45 ;
V_7 -> V_14 -> V_60 = & V_61 ;
V_7 -> V_14 -> V_17 . V_52 = & V_9 -> V_17 ;
F_34 ( V_7 -> V_14 , V_7 ) ;
V_8 = F_35 ( & V_9 -> V_17 , V_9 -> V_1 , F_19 ,
V_62 , F_36 ( & V_9 -> V_17 ) ,
V_7 -> V_14 ) ;
if ( V_8 < 0 )
return V_8 ;
F_24 ( V_9 -> V_1 ) ;
V_8 = F_37 ( & V_9 -> V_17 , V_7 -> V_14 ) ;
if ( V_8 )
return V_8 ;
}
F_38 ( V_9 , V_6 ) ;
V_7 -> V_9 = V_9 ;
V_7 -> V_63 . V_64 = & V_7 -> V_12 [ 1 ] ;
V_7 -> V_63 . V_65 = 3 ;
F_39 ( & V_7 -> V_10 ) ;
F_40 ( & V_7 -> V_63 , & V_7 -> V_10 ) ;
V_8 = F_41 ( & V_9 -> V_17 , V_6 ,
& V_66 , & F_1 ,
& V_67 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_42 ( & V_9 -> V_17 , V_6 ) ;
if ( V_8 )
return V_8 ;
return 0 ;
}
