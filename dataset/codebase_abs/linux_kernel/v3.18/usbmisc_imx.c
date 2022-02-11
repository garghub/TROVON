static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
unsigned long V_6 ;
T_1 V_7 = 0 ;
if ( V_2 -> V_8 > 1 )
return - V_9 ;
F_3 ( & V_4 -> V_10 , V_6 ) ;
switch ( V_2 -> V_8 ) {
case 0 :
V_7 = F_4 ( V_4 -> V_11 ) ;
V_7 &= ~ ( V_12 | V_13 ) ;
V_7 |= ( V_14 & V_15 ) << V_16 ;
V_7 |= ( V_17 | V_18 ) ;
F_5 ( V_7 , V_4 -> V_11 ) ;
break;
case 1 :
V_7 = F_4 ( V_4 -> V_11 ) ;
V_7 &= ~ ( V_19 | V_20 | V_21 ) ;
V_7 |= ( V_22 & V_15 ) << V_23 ;
V_7 |= ( V_24 | V_25 | V_26 |
V_27 | V_28 ) ;
F_5 ( V_7 , V_4 -> V_11 ) ;
break;
}
F_6 ( & V_4 -> V_10 , V_6 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
void T_2 * V_29 ;
unsigned long V_6 ;
T_1 V_7 ;
if ( V_2 -> V_8 > 2 )
return - V_9 ;
V_29 = V_4 -> V_11 + V_30 ;
if ( V_2 -> V_31 ) {
F_3 ( & V_4 -> V_10 , V_6 ) ;
V_7 = F_4 ( V_29 ) ;
F_5 ( V_7 | V_32 , V_29 ) ;
F_6 ( & V_4 -> V_10 , V_6 ) ;
F_8 ( 5000 , 10000 ) ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
unsigned long V_6 ;
T_1 V_7 ;
switch ( V_2 -> V_8 ) {
case 0 :
V_7 = V_33 ;
break;
case 1 :
V_7 = V_34 ;
break;
case 2 :
V_7 = V_35 ;
break;
default:
return - V_9 ;
} ;
F_3 ( & V_4 -> V_10 , V_6 ) ;
if ( V_2 -> V_36 )
V_7 = F_4 ( V_4 -> V_11 ) | V_7 ;
else
V_7 = F_4 ( V_4 -> V_11 ) & ~ V_7 ;
F_5 ( V_7 , V_4 -> V_11 ) ;
F_6 ( & V_4 -> V_10 , V_6 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
void T_2 * V_29 = NULL ;
unsigned long V_6 ;
T_1 V_7 = 0 ;
if ( V_2 -> V_8 > 3 )
return - V_9 ;
V_29 = V_4 -> V_11 + V_37 ;
V_7 = F_4 ( V_29 ) ;
V_7 &= ~ V_38 ;
V_7 |= V_39 ;
F_5 ( V_7 , V_4 -> V_11 + V_37 ) ;
if ( V_2 -> V_36 ) {
F_3 ( & V_4 -> V_10 , V_6 ) ;
switch ( V_2 -> V_8 ) {
case 0 :
V_29 = V_4 -> V_11 + V_40 ;
V_7 = F_4 ( V_29 ) | V_41 ;
break;
case 1 :
V_29 = V_4 -> V_11 + V_40 ;
V_7 = F_4 ( V_29 ) | V_42 ;
break;
case 2 :
V_29 = V_4 -> V_11 + V_43 ;
V_7 = F_4 ( V_29 ) | V_44 ;
break;
case 3 :
V_29 = V_4 -> V_11 + V_45 ;
V_7 = F_4 ( V_29 ) | V_44 ;
break;
}
if ( V_29 && V_7 )
F_5 ( V_7 , V_29 ) ;
F_6 ( & V_4 -> V_10 , V_6 ) ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
unsigned long V_6 ;
T_1 V_29 ;
if ( V_2 -> V_8 > 3 )
return - V_9 ;
if ( V_2 -> V_36 ) {
F_3 ( & V_4 -> V_10 , V_6 ) ;
V_29 = F_4 ( V_4 -> V_11 + V_2 -> V_8 * 4 ) ;
F_5 ( V_29 | V_46 ,
V_4 -> V_11 + V_2 -> V_8 * 4 ) ;
F_6 ( & V_4 -> V_10 , V_6 ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
T_1 V_29 ;
if ( V_2 -> V_8 >= 1 )
return - V_9 ;
if ( V_2 -> V_36 ) {
V_29 = F_4 ( V_4 -> V_11 ) ;
F_5 ( V_29 | V_47 , V_4 -> V_11 ) ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
if ( ! V_4 -> V_48 -> V_49 )
return 0 ;
return V_4 -> V_48 -> V_49 ( V_2 ) ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
if ( ! V_4 -> V_48 -> V_50 )
return 0 ;
return V_4 -> V_48 -> V_50 ( V_2 ) ;
}
static int F_15 ( struct V_51 * V_52 )
{
struct V_53 * V_54 ;
struct V_3 * V_2 ;
int V_55 ;
struct V_56 * V_57 ;
V_2 = F_16 ( & V_52 -> V_5 , sizeof( * V_2 ) , V_58 ) ;
if ( ! V_2 )
return - V_59 ;
F_17 ( & V_2 -> V_10 ) ;
V_54 = F_18 ( V_52 , V_60 , 0 ) ;
V_2 -> V_11 = F_19 ( & V_52 -> V_5 , V_54 ) ;
if ( F_20 ( V_2 -> V_11 ) )
return F_21 ( V_2 -> V_11 ) ;
V_2 -> V_61 = F_22 ( & V_52 -> V_5 , NULL ) ;
if ( F_20 ( V_2 -> V_61 ) ) {
F_23 ( & V_52 -> V_5 ,
L_1 , F_21 ( V_2 -> V_61 ) ) ;
return F_21 ( V_2 -> V_61 ) ;
}
V_55 = F_24 ( V_2 -> V_61 ) ;
if ( V_55 ) {
F_23 ( & V_52 -> V_5 ,
L_2 , V_55 ) ;
return V_55 ;
}
V_57 = (struct V_56 * )
F_25 ( V_62 , & V_52 -> V_5 ) ;
V_2 -> V_48 = ( const struct V_63 * ) V_57 -> V_2 ;
F_26 ( V_52 , V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_51 * V_52 )
{
struct V_3 * V_4 = F_2 ( & V_52 -> V_5 ) ;
F_28 ( V_4 -> V_61 ) ;
return 0 ;
}
