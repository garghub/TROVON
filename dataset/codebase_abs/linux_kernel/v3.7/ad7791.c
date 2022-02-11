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
unsigned long long V_26 ;
switch ( V_23 ) {
case V_27 :
return F_10 ( V_18 , V_20 , V_21 ) ;
case V_28 :
if ( V_24 )
* V_21 = 0 ;
else
* V_21 = - ( 1 << ( V_20 -> V_29 . V_30 - 1 ) ) ;
return V_31 ;
case V_32 :
if ( V_20 -> V_33 == V_34 ) {
V_26 = 5850000000000ULL ;
} else {
int V_35 ;
V_35 = F_11 ( V_7 -> V_36 ) ;
if ( V_35 < 0 )
return V_35 ;
V_26 = ( unsigned long long ) V_35 * 1000000 ;
}
if ( V_24 )
V_26 >>= V_20 -> V_29 . V_30 ;
else
V_26 >>= V_20 -> V_29 . V_30 - 1 ;
* V_22 = F_12 ( V_26 , 1000000000 ) ;
* V_21 = V_26 ;
return V_37 ;
}
return - V_38 ;
}
static T_1 F_13 ( struct V_39 * V_40 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_17 * V_18 = F_14 ( V_40 ) ;
struct V_1 * V_7 = F_9 ( V_18 ) ;
unsigned int V_44 = V_7 -> V_45 & V_46 ;
return sprintf ( V_43 , L_1 , V_47 [ V_44 ] ) ;
}
static T_1 F_15 ( struct V_39 * V_40 ,
struct V_41 * V_42 , const char * V_43 , T_2 V_48 )
{
struct V_17 * V_18 = F_14 ( V_40 ) ;
struct V_1 * V_7 = F_9 ( V_18 ) ;
int V_49 , V_50 ;
F_16 ( & V_18 -> V_51 ) ;
if ( F_17 ( V_18 ) ) {
F_18 ( & V_18 -> V_51 ) ;
return - V_52 ;
}
F_18 ( & V_18 -> V_51 ) ;
V_50 = - V_38 ;
for ( V_49 = 0 ; V_49 < F_19 ( V_47 ) ; V_49 ++ ) {
if ( F_20 ( V_47 [ V_49 ] , V_43 ) ) {
F_16 ( & V_18 -> V_51 ) ;
V_7 -> V_45 &= ~ V_46 ;
V_7 -> V_45 |= V_49 ;
F_7 ( & V_7 -> V_3 , V_53 ,
sizeof( V_7 -> V_45 ) , V_7 -> V_45 ) ;
F_18 ( & V_18 -> V_51 ) ;
V_50 = 0 ;
break;
}
}
return V_50 ? V_50 : V_48 ;
}
static int T_3 F_21 ( struct V_1 * V_7 ,
struct V_54 * V_55 )
{
V_7 -> V_6 = V_56 ;
V_7 -> V_45 = V_57 ;
if ( ! V_55 )
return 0 ;
if ( ( V_7 -> V_23 -> V_58 & V_59 ) && ! V_55 -> V_60 )
V_7 -> V_6 &= ~ V_56 ;
if ( ( V_7 -> V_23 -> V_58 & V_61 ) &&
V_55 -> V_62 )
V_7 -> V_6 |= V_63 ;
if ( ( V_7 -> V_23 -> V_58 & V_64 ) && V_55 -> V_24 )
V_7 -> V_6 |= V_25 ;
return F_7 ( & V_7 -> V_3 , V_16 , sizeof( V_7 -> V_6 ) ,
V_7 -> V_6 ) ;
}
static int T_3 F_22 ( struct V_65 * V_66 )
{
struct V_54 * V_55 = V_66 -> V_40 . V_67 ;
struct V_17 * V_18 ;
struct V_1 * V_7 ;
int V_50 ;
if ( ! V_66 -> V_68 ) {
F_23 ( & V_66 -> V_40 , L_2 ) ;
return - V_69 ;
}
V_18 = F_24 ( sizeof( * V_7 ) ) ;
if ( ! V_18 )
return - V_70 ;
V_7 = F_9 ( V_18 ) ;
V_7 -> V_36 = F_25 ( & V_66 -> V_40 , L_3 ) ;
if ( F_26 ( V_7 -> V_36 ) ) {
V_50 = F_27 ( V_7 -> V_36 ) ;
goto V_71;
}
V_50 = F_28 ( V_7 -> V_36 ) ;
if ( V_50 )
goto V_72;
V_7 -> V_23 = & V_73 [ F_29 ( V_66 ) -> V_74 ] ;
F_30 ( & V_7 -> V_3 , V_18 , V_66 , & V_75 ) ;
F_31 ( V_66 , V_18 ) ;
V_18 -> V_40 . V_76 = & V_66 -> V_40 ;
V_18 -> V_77 = F_29 ( V_66 ) -> V_77 ;
V_18 -> V_78 = V_79 ;
V_18 -> V_80 = V_7 -> V_23 -> V_80 ;
V_18 -> V_81 = V_7 -> V_23 -> V_81 ;
if ( V_7 -> V_23 -> V_58 & V_82 )
V_18 -> V_23 = & V_83 ;
else
V_18 -> V_23 = & V_84 ;
V_50 = F_32 ( V_18 ) ;
if ( V_50 )
goto V_85;
V_50 = F_21 ( V_7 , V_55 ) ;
if ( V_50 )
goto V_86;
V_50 = F_33 ( V_18 ) ;
if ( V_50 )
goto V_86;
return 0 ;
V_86:
F_34 ( V_18 ) ;
V_85:
F_35 ( V_7 -> V_36 ) ;
V_72:
F_36 ( V_7 -> V_36 ) ;
V_71:
F_37 ( V_18 ) ;
return V_50 ;
}
static int T_4 F_38 ( struct V_65 * V_66 )
{
struct V_17 * V_18 = F_39 ( V_66 ) ;
struct V_1 * V_7 = F_9 ( V_18 ) ;
F_40 ( V_18 ) ;
F_34 ( V_18 ) ;
F_35 ( V_7 -> V_36 ) ;
F_36 ( V_7 -> V_36 ) ;
F_37 ( V_18 ) ;
return 0 ;
}
