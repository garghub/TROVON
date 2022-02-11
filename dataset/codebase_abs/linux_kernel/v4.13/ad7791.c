static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned int V_4 )
{
F_4 ( V_3 , V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_2 * V_3 ,
enum V_5 V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
switch ( V_6 ) {
case V_8 :
V_6 = V_9 ;
break;
case V_10 :
V_6 = V_11 ;
break;
case V_12 :
case V_13 :
V_6 = V_14 ;
break;
}
V_7 -> V_6 &= ~ V_15 ;
V_7 -> V_6 |= F_6 ( V_6 ) ;
return F_7 ( V_3 , V_16 , sizeof( V_7 -> V_6 ) , V_7 -> V_6 ) ;
}
static int F_8 ( struct V_17 * V_18 ,
const struct V_19 * V_20 , int * V_21 , int * V_22 , long V_23 )
{
struct V_1 * V_7 = F_9 ( V_18 ) ;
bool V_24 = ! ! ( V_7 -> V_6 & V_25 ) ;
switch ( V_23 ) {
case V_26 :
return F_10 ( V_18 , V_20 , V_21 ) ;
case V_27 :
if ( V_24 )
* V_21 = 0 ;
else
* V_21 = - ( 1 << ( V_20 -> V_28 . V_29 - 1 ) ) ;
return V_30 ;
case V_31 :
if ( V_20 -> V_32 == V_33 ) {
* V_21 = 1170 * 5 ;
} else {
int V_34 ;
V_34 = F_11 ( V_7 -> V_35 ) ;
if ( V_34 < 0 )
return V_34 ;
* V_21 = V_34 / 1000 ;
}
if ( V_24 )
* V_22 = V_20 -> V_28 . V_29 ;
else
* V_22 = V_20 -> V_28 . V_29 - 1 ;
return V_36 ;
}
return - V_37 ;
}
static T_1 F_12 ( struct V_38 * V_39 ,
struct V_40 * V_41 , char * V_42 )
{
struct V_17 * V_18 = F_13 ( V_39 ) ;
struct V_1 * V_7 = F_9 ( V_18 ) ;
unsigned int V_43 = V_7 -> V_44 & V_45 ;
return sprintf ( V_42 , L_1 , V_46 [ V_43 ] ) ;
}
static T_1 F_14 ( struct V_38 * V_39 ,
struct V_40 * V_41 , const char * V_42 , T_2 V_47 )
{
struct V_17 * V_18 = F_13 ( V_39 ) ;
struct V_1 * V_7 = F_9 ( V_18 ) ;
int V_48 , V_49 ;
V_48 = F_15 ( V_46 , V_42 ) ;
if ( V_48 < 0 )
return V_48 ;
V_49 = F_16 ( V_18 ) ;
if ( V_49 )
return V_49 ;
V_7 -> V_44 &= ~ V_45 ;
V_7 -> V_44 |= V_48 ;
F_7 ( & V_7 -> V_3 , V_50 , sizeof( V_7 -> V_44 ) ,
V_7 -> V_44 ) ;
F_17 ( V_18 ) ;
return V_47 ;
}
static int F_18 ( struct V_1 * V_7 ,
struct V_51 * V_52 )
{
V_7 -> V_6 = V_53 ;
V_7 -> V_44 = V_54 ;
if ( ! V_52 )
return 0 ;
if ( ( V_7 -> V_23 -> V_55 & V_56 ) && ! V_52 -> V_57 )
V_7 -> V_6 &= ~ V_53 ;
if ( ( V_7 -> V_23 -> V_55 & V_58 ) &&
V_52 -> V_59 )
V_7 -> V_6 |= V_60 ;
if ( ( V_7 -> V_23 -> V_55 & V_61 ) && V_52 -> V_24 )
V_7 -> V_6 |= V_25 ;
return F_7 ( & V_7 -> V_3 , V_16 , sizeof( V_7 -> V_6 ) ,
V_7 -> V_6 ) ;
}
static int F_19 ( struct V_62 * V_63 )
{
struct V_51 * V_52 = V_63 -> V_39 . V_64 ;
struct V_17 * V_18 ;
struct V_1 * V_7 ;
int V_49 ;
if ( ! V_63 -> V_65 ) {
F_20 ( & V_63 -> V_39 , L_2 ) ;
return - V_66 ;
}
V_18 = F_21 ( & V_63 -> V_39 , sizeof( * V_7 ) ) ;
if ( ! V_18 )
return - V_67 ;
V_7 = F_9 ( V_18 ) ;
V_7 -> V_35 = F_22 ( & V_63 -> V_39 , L_3 ) ;
if ( F_23 ( V_7 -> V_35 ) )
return F_24 ( V_7 -> V_35 ) ;
V_49 = F_25 ( V_7 -> V_35 ) ;
if ( V_49 )
return V_49 ;
V_7 -> V_23 = & V_68 [ F_26 ( V_63 ) -> V_69 ] ;
F_27 ( & V_7 -> V_3 , V_18 , V_63 , & V_70 ) ;
F_28 ( V_63 , V_18 ) ;
V_18 -> V_39 . V_71 = & V_63 -> V_39 ;
V_18 -> V_39 . V_72 = V_63 -> V_39 . V_72 ;
V_18 -> V_73 = F_26 ( V_63 ) -> V_73 ;
V_18 -> V_74 = V_75 ;
V_18 -> V_76 = V_7 -> V_23 -> V_76 ;
V_18 -> V_77 = V_7 -> V_23 -> V_77 ;
if ( V_7 -> V_23 -> V_55 & V_78 )
V_18 -> V_23 = & V_79 ;
else
V_18 -> V_23 = & V_80 ;
V_49 = F_29 ( V_18 ) ;
if ( V_49 )
goto V_81;
V_49 = F_18 ( V_7 , V_52 ) ;
if ( V_49 )
goto V_82;
V_49 = F_30 ( V_18 ) ;
if ( V_49 )
goto V_82;
return 0 ;
V_82:
F_31 ( V_18 ) ;
V_81:
F_32 ( V_7 -> V_35 ) ;
return V_49 ;
}
static int F_33 ( struct V_62 * V_63 )
{
struct V_17 * V_18 = F_34 ( V_63 ) ;
struct V_1 * V_7 = F_9 ( V_18 ) ;
F_35 ( V_18 ) ;
F_31 ( V_18 ) ;
F_32 ( V_7 -> V_35 ) ;
return 0 ;
}
