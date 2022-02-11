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
F_15 ( & V_18 -> V_50 ) ;
if ( F_16 ( V_18 ) ) {
F_17 ( & V_18 -> V_50 ) ;
return - V_51 ;
}
F_17 ( & V_18 -> V_50 ) ;
V_49 = - V_37 ;
for ( V_48 = 0 ; V_48 < F_18 ( V_46 ) ; V_48 ++ ) {
if ( F_19 ( V_46 [ V_48 ] , V_42 ) ) {
F_15 ( & V_18 -> V_50 ) ;
V_7 -> V_44 &= ~ V_45 ;
V_7 -> V_44 |= V_48 ;
F_7 ( & V_7 -> V_3 , V_52 ,
sizeof( V_7 -> V_44 ) , V_7 -> V_44 ) ;
F_17 ( & V_18 -> V_50 ) ;
V_49 = 0 ;
break;
}
}
return V_49 ? V_49 : V_47 ;
}
static int F_20 ( struct V_1 * V_7 ,
struct V_53 * V_54 )
{
V_7 -> V_6 = V_55 ;
V_7 -> V_44 = V_56 ;
if ( ! V_54 )
return 0 ;
if ( ( V_7 -> V_23 -> V_57 & V_58 ) && ! V_54 -> V_59 )
V_7 -> V_6 &= ~ V_55 ;
if ( ( V_7 -> V_23 -> V_57 & V_60 ) &&
V_54 -> V_61 )
V_7 -> V_6 |= V_62 ;
if ( ( V_7 -> V_23 -> V_57 & V_63 ) && V_54 -> V_24 )
V_7 -> V_6 |= V_25 ;
return F_7 ( & V_7 -> V_3 , V_16 , sizeof( V_7 -> V_6 ) ,
V_7 -> V_6 ) ;
}
static int F_21 ( struct V_64 * V_65 )
{
struct V_53 * V_54 = V_65 -> V_39 . V_66 ;
struct V_17 * V_18 ;
struct V_1 * V_7 ;
int V_49 ;
if ( ! V_65 -> V_67 ) {
F_22 ( & V_65 -> V_39 , L_2 ) ;
return - V_68 ;
}
V_18 = F_23 ( & V_65 -> V_39 , sizeof( * V_7 ) ) ;
if ( ! V_18 )
return - V_69 ;
V_7 = F_9 ( V_18 ) ;
V_7 -> V_35 = F_24 ( & V_65 -> V_39 , L_3 ) ;
if ( F_25 ( V_7 -> V_35 ) )
return F_26 ( V_7 -> V_35 ) ;
V_49 = F_27 ( V_7 -> V_35 ) ;
if ( V_49 )
return V_49 ;
V_7 -> V_23 = & V_70 [ F_28 ( V_65 ) -> V_71 ] ;
F_29 ( & V_7 -> V_3 , V_18 , V_65 , & V_72 ) ;
F_30 ( V_65 , V_18 ) ;
V_18 -> V_39 . V_73 = & V_65 -> V_39 ;
V_18 -> V_74 = F_28 ( V_65 ) -> V_74 ;
V_18 -> V_75 = V_76 ;
V_18 -> V_77 = V_7 -> V_23 -> V_77 ;
V_18 -> V_78 = V_7 -> V_23 -> V_78 ;
if ( V_7 -> V_23 -> V_57 & V_79 )
V_18 -> V_23 = & V_80 ;
else
V_18 -> V_23 = & V_81 ;
V_49 = F_31 ( V_18 ) ;
if ( V_49 )
goto V_82;
V_49 = F_20 ( V_7 , V_54 ) ;
if ( V_49 )
goto V_83;
V_49 = F_32 ( V_18 ) ;
if ( V_49 )
goto V_83;
return 0 ;
V_83:
F_33 ( V_18 ) ;
V_82:
F_34 ( V_7 -> V_35 ) ;
return V_49 ;
}
static int F_35 ( struct V_64 * V_65 )
{
struct V_17 * V_18 = F_36 ( V_65 ) ;
struct V_1 * V_7 = F_9 ( V_18 ) ;
F_37 ( V_18 ) ;
F_33 ( V_18 ) ;
F_34 ( V_7 -> V_35 ) ;
return 0 ;
}
