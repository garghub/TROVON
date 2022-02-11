static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_4 = 0 ;
if ( V_2 -> V_5 > 1 )
return - V_6 ;
F_2 ( & V_7 -> V_8 , V_3 ) ;
switch ( V_2 -> V_5 ) {
case 0 :
V_4 = F_3 ( V_7 -> V_9 ) ;
V_4 &= ~ ( V_10 | V_11 ) ;
V_4 |= ( V_12 & V_13 ) << V_14 ;
V_4 |= ( V_15 | V_16 ) ;
F_4 ( V_4 , V_7 -> V_9 ) ;
break;
case 1 :
V_4 = F_3 ( V_7 -> V_9 ) ;
V_4 &= ~ ( V_17 | V_18 | V_19 ) ;
V_4 |= ( V_20 & V_13 ) << V_21 ;
V_4 |= ( V_22 | V_23 | V_24 |
V_25 | V_26 ) ;
F_4 ( V_4 , V_7 -> V_9 ) ;
break;
}
F_5 ( & V_7 -> V_8 , V_3 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
void T_2 * V_27 ;
unsigned long V_3 ;
T_1 V_4 ;
if ( V_2 -> V_5 > 2 )
return - V_6 ;
V_27 = V_7 -> V_9 + V_28 ;
if ( V_2 -> V_29 ) {
F_2 ( & V_7 -> V_8 , V_3 ) ;
V_4 = F_3 ( V_27 ) ;
F_4 ( V_4 | V_30 , V_27 ) ;
F_5 ( & V_7 -> V_8 , V_3 ) ;
F_7 ( 5000 , 10000 ) ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_4 ;
switch ( V_2 -> V_5 ) {
case 0 :
V_4 = V_31 ;
break;
case 1 :
V_4 = V_32 ;
break;
case 2 :
V_4 = V_33 ;
break;
default:
return - V_6 ;
} ;
F_2 ( & V_7 -> V_8 , V_3 ) ;
if ( V_2 -> V_34 )
V_4 = F_3 ( V_7 -> V_9 ) | V_4 ;
else
V_4 = F_3 ( V_7 -> V_9 ) & ~ V_4 ;
F_4 ( V_4 , V_7 -> V_9 ) ;
F_5 ( & V_7 -> V_8 , V_3 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
void T_2 * V_27 = NULL ;
unsigned long V_3 ;
T_1 V_4 = 0 ;
if ( V_2 -> V_5 > 3 )
return - V_6 ;
V_27 = V_7 -> V_9 + V_35 ;
V_4 = F_3 ( V_27 ) ;
V_4 &= ~ V_36 ;
V_4 |= V_37 ;
F_4 ( V_4 , V_7 -> V_9 + V_35 ) ;
if ( V_2 -> V_34 ) {
F_2 ( & V_7 -> V_8 , V_3 ) ;
switch ( V_2 -> V_5 ) {
case 0 :
V_27 = V_7 -> V_9 + V_38 ;
V_4 = F_3 ( V_27 ) | V_39 ;
break;
case 1 :
V_27 = V_7 -> V_9 + V_38 ;
V_4 = F_3 ( V_27 ) | V_40 ;
break;
case 2 :
V_27 = V_7 -> V_9 + V_41 ;
V_4 = F_3 ( V_27 ) | V_42 ;
break;
case 3 :
V_27 = V_7 -> V_9 + V_43 ;
V_4 = F_3 ( V_27 ) | V_42 ;
break;
}
if ( V_27 && V_4 )
F_4 ( V_4 , V_27 ) ;
F_5 ( & V_7 -> V_8 , V_3 ) ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_27 ;
if ( V_2 -> V_5 > 3 )
return - V_6 ;
if ( V_2 -> V_34 ) {
F_2 ( & V_7 -> V_8 , V_3 ) ;
V_27 = F_3 ( V_7 -> V_9 + V_2 -> V_5 * 4 ) ;
F_4 ( V_27 | V_44 ,
V_7 -> V_9 + V_2 -> V_5 * 4 ) ;
F_5 ( & V_7 -> V_8 , V_3 ) ;
}
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
if ( ! V_7 )
return - V_45 ;
if ( ! V_7 -> V_46 -> V_47 )
return 0 ;
return V_7 -> V_46 -> V_47 ( V_2 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
if ( ! V_7 )
return - V_45 ;
if ( ! V_7 -> V_46 -> V_48 )
return 0 ;
return V_7 -> V_46 -> V_48 ( V_2 ) ;
}
static int F_13 ( struct V_49 * V_50 )
{
struct V_51 * V_52 ;
struct V_53 * V_2 ;
int V_54 ;
struct V_55 * V_56 ;
if ( V_7 )
return - V_57 ;
V_2 = F_14 ( & V_50 -> V_58 , sizeof( * V_2 ) , V_59 ) ;
if ( ! V_2 )
return - V_60 ;
F_15 ( & V_2 -> V_8 ) ;
V_52 = F_16 ( V_50 , V_61 , 0 ) ;
V_2 -> V_9 = F_17 ( & V_50 -> V_58 , V_52 ) ;
if ( F_18 ( V_2 -> V_9 ) )
return F_19 ( V_2 -> V_9 ) ;
V_2 -> V_62 = F_20 ( & V_50 -> V_58 , NULL ) ;
if ( F_18 ( V_2 -> V_62 ) ) {
F_21 ( & V_50 -> V_58 ,
L_1 , F_19 ( V_2 -> V_62 ) ) ;
return F_19 ( V_2 -> V_62 ) ;
}
V_54 = F_22 ( V_2 -> V_62 ) ;
if ( V_54 ) {
F_21 ( & V_50 -> V_58 ,
L_2 , V_54 ) ;
return V_54 ;
}
V_56 = (struct V_55 * )
F_23 ( V_63 , & V_50 -> V_58 ) ;
V_2 -> V_46 = ( const struct V_64 * ) V_56 -> V_2 ;
V_7 = V_2 ;
return 0 ;
}
static int F_24 ( struct V_49 * V_50 )
{
F_25 ( V_7 -> V_62 ) ;
V_7 = NULL ;
return 0 ;
}
