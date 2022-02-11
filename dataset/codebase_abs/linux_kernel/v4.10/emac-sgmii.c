static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_7 ;
V_7 = F_2 ( V_6 -> V_8 + V_9 ) ;
if ( V_4 -> V_10 == V_11 ) {
V_7 &= ~ ( V_12 | V_13 ) ;
V_7 |= V_14 ;
F_3 ( V_7 , V_6 -> V_8 + V_9 ) ;
} else {
T_1 V_15 ;
switch ( V_4 -> V_16 ) {
case V_17 :
V_15 = V_18 ;
break;
case V_19 :
V_15 = V_20 ;
break;
case V_21 :
V_15 = V_22 ;
break;
default:
return - V_23 ;
}
if ( V_4 -> V_24 == V_25 )
V_15 |= V_26 ;
V_7 &= ~ V_14 ;
F_3 ( V_15 , V_6 -> V_8 + V_27 ) ;
F_3 ( V_7 , V_6 -> V_8 + V_9 ) ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_28 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_29 ;
F_5 ( V_28 , V_6 -> V_8 + V_30 ) ;
F_5 ( V_31 , V_6 -> V_8 + V_32 ) ;
F_6 () ;
if ( F_7 ( V_6 -> V_8 +
V_33 ,
V_29 , ! ( V_29 & V_28 ) , 1 ,
V_34 ) ) {
F_8 ( V_2 -> V_35 ,
L_1 ,
V_29 , V_28 ) ;
return - V_36 ;
}
F_5 ( 0 , V_6 -> V_8 + V_32 ) ;
F_5 ( 0 , V_6 -> V_8 + V_30 ) ;
F_6 () ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_7 ;
V_7 = F_2 ( V_6 -> V_8 + V_37 ) ;
F_3 ( ( ( V_7 & ~ V_38 ) | V_38 ) , V_6 -> V_8 +
V_37 ) ;
F_10 ( 50 ) ;
V_7 = F_2 ( V_6 -> V_8 + V_37 ) ;
F_3 ( ( V_7 & ~ V_38 ) , V_6 -> V_8 + V_37 ) ;
F_10 ( 50 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
int V_39 ;
F_9 ( V_2 ) ;
V_39 = F_1 ( V_2 ) ;
if ( V_39 ) {
F_8 ( V_2 -> V_35 , L_2 ) ;
return;
}
V_39 = V_2 -> V_6 . V_40 ( V_2 ) ;
if ( V_39 )
F_8 ( V_2 -> V_35 ,
L_3 ,
V_39 ) ;
}
static int F_12 ( struct V_41 * V_42 , void * V_43 )
{
#ifdef F_13
static const struct V_44 V_45 [] = {
{
. V_46 = L_4 ,
} ,
{}
} ;
const struct V_44 * V_46 = F_14 ( V_45 , V_42 ) ;
T_2 * V_40 = V_43 ;
if ( V_46 ) {
T_3 V_47 = F_15 ( V_42 ) ;
unsigned long long V_48 ;
T_4 V_29 ;
V_29 = F_16 ( V_47 , L_5 , NULL , & V_48 ) ;
if ( V_29 ) {
if ( V_29 == V_49 )
V_48 = 1 ;
else
return 0 ;
}
switch ( V_48 ) {
case 1 :
* V_40 = V_50 ;
return 1 ;
case 2 :
* V_40 = V_51 ;
return 1 ;
}
}
#endif
return 0 ;
}
int F_17 ( struct V_52 * V_53 , struct V_1 * V_2 )
{
struct V_52 * V_54 = NULL ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_55 * V_56 ;
int V_39 ;
if ( F_18 ( & V_53 -> V_42 ) ) {
struct V_41 * V_42 ;
V_42 = F_19 ( & V_53 -> V_42 , & V_6 -> V_40 ,
F_12 ) ;
if ( ! V_42 ) {
F_20 ( & V_53 -> V_42 , L_6 ) ;
return - V_57 ;
}
V_54 = F_21 ( V_42 ) ;
} else {
const struct V_58 * V_59 ;
struct V_60 * V_61 ;
V_61 = F_22 ( V_53 -> V_42 . V_62 , L_7 , 0 ) ;
if ( ! V_61 ) {
F_20 ( & V_53 -> V_42 , L_8 ) ;
return - V_57 ;
}
V_54 = F_23 ( V_61 ) ;
if ( ! V_54 ) {
F_20 ( & V_53 -> V_42 , L_9 ) ;
return - V_57 ;
}
V_59 = F_24 ( V_63 , & V_54 -> V_42 ) ;
if ( ! V_59 ) {
F_20 ( & V_53 -> V_42 , L_10 ) ;
V_39 = - V_57 ;
goto V_64;
}
V_6 -> V_40 = ( T_2 ) V_59 -> V_43 ;
}
V_56 = F_25 ( V_54 , V_65 , 0 ) ;
if ( ! V_56 ) {
V_39 = - V_23 ;
goto V_64;
}
V_6 -> V_8 = F_26 ( V_56 -> V_66 , F_27 ( V_56 ) ) ;
if ( ! V_6 -> V_8 ) {
V_39 = - V_67 ;
goto V_64;
}
V_56 = F_25 ( V_54 , V_65 , 1 ) ;
if ( V_56 ) {
V_6 -> V_68 = F_26 ( V_56 -> V_66 , F_27 ( V_56 ) ) ;
if ( ! V_6 -> V_68 ) {
V_39 = - V_67 ;
goto V_69;
}
}
V_39 = V_6 -> V_40 ( V_2 ) ;
if ( V_39 )
goto error;
F_4 ( V_2 , V_70 ) ;
F_28 ( & V_54 -> V_42 ) ;
return 0 ;
error:
if ( V_6 -> V_68 )
F_29 ( V_6 -> V_68 ) ;
V_69:
F_29 ( V_6 -> V_8 ) ;
V_64:
F_28 ( & V_54 -> V_42 ) ;
return V_39 ;
}
