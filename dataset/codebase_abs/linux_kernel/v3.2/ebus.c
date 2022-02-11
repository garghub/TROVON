static void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
T_1 V_5 = 0 ;
F_2 ( V_6 , V_2 -> V_7 + V_8 ) ;
F_3 ( 1 ) ;
if ( V_3 )
return;
for ( V_4 = V_9 ; V_4 > 0 ; V_4 -- ) {
V_5 = F_4 ( V_2 -> V_7 + V_8 ) ;
if ( ! ( V_5 & ( V_10 | V_11 ) ) )
break;
F_3 ( 10 ) ;
}
}
static T_2 F_5 ( int V_12 , void * V_13 )
{
struct V_1 * V_2 = V_13 ;
unsigned long V_14 ;
T_1 V_15 = 0 ;
F_6 ( & V_2 -> V_16 , V_14 ) ;
V_15 = F_4 ( V_2 -> V_7 + V_8 ) ;
F_2 ( V_15 , V_2 -> V_7 + V_8 ) ;
F_7 ( & V_2 -> V_16 , V_14 ) ;
if ( V_15 & V_17 ) {
F_8 ( V_18 L_1 , V_2 -> V_19 ) ;
V_2 -> V_20 ( V_2 , V_21 , V_2 -> V_22 ) ;
return V_23 ;
} else if ( V_15 & V_24 ) {
V_2 -> V_20 ( V_2 ,
( V_15 & V_25 ) ?
V_26 : V_27 ,
V_2 -> V_22 ) ;
return V_23 ;
}
return V_28 ;
}
int F_9 ( struct V_1 * V_2 )
{
T_1 V_15 ;
if ( ! V_2 -> V_7 )
return - V_29 ;
if ( V_2 -> V_14 & ~ ( V_30 |
V_31 ) )
return - V_29 ;
if ( ( V_2 -> V_14 & V_30 ) && ! V_2 -> V_20 )
return - V_29 ;
if ( ! strlen ( V_2 -> V_19 ) )
return - V_29 ;
F_1 ( V_2 , 1 ) ;
V_15 = V_32 | V_33 ;
if ( V_2 -> V_14 & V_31 )
V_15 |= V_34 ;
F_2 ( V_15 , V_2 -> V_7 + V_8 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 , int V_35 )
{
unsigned long V_14 ;
T_1 V_15 ;
if ( V_35 ) {
if ( V_2 -> V_14 & V_30 ) {
if ( F_11 ( V_2 -> V_12 , F_5 , V_36 , V_2 -> V_19 , V_2 ) )
return - V_37 ;
}
F_6 ( & V_2 -> V_16 , V_14 ) ;
V_15 = F_4 ( V_2 -> V_7 + V_8 ) ;
V_15 |= V_38 ;
F_2 ( V_15 , V_2 -> V_7 + V_8 ) ;
F_7 ( & V_2 -> V_16 , V_14 ) ;
} else {
F_6 ( & V_2 -> V_16 , V_14 ) ;
V_15 = F_4 ( V_2 -> V_7 + V_8 ) ;
V_15 &= ~ V_38 ;
F_2 ( V_15 , V_2 -> V_7 + V_8 ) ;
F_7 ( & V_2 -> V_16 , V_14 ) ;
if ( V_2 -> V_14 & V_30 ) {
F_12 ( V_2 -> V_12 , V_2 ) ;
}
}
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
unsigned long V_14 ;
T_1 V_15 ;
int V_39 = 0 ;
F_6 ( & V_2 -> V_16 , V_14 ) ;
V_15 = F_4 ( V_2 -> V_7 + V_8 ) ;
if ( V_15 & V_38 ) {
V_15 &= ~ V_38 ;
F_2 ( V_15 , V_2 -> V_7 + V_8 ) ;
V_39 = 1 ;
}
F_7 ( & V_2 -> V_16 , V_14 ) ;
if ( V_39 )
F_12 ( V_2 -> V_12 , V_2 ) ;
}
int F_14 ( struct V_1 * V_2 , T_3 V_40 , T_4 V_41 )
{
unsigned long V_14 ;
T_1 V_15 ;
int V_42 ;
if ( V_41 >= ( 1 << 24 ) )
return - V_29 ;
F_6 ( & V_2 -> V_16 , V_14 ) ;
V_15 = F_4 ( V_2 -> V_7 + V_8 ) ;
V_42 = - V_29 ;
if ( ! ( V_15 & V_43 ) )
goto V_44;
V_42 = - V_37 ;
if ( V_15 & V_45 )
goto V_44;
F_2 ( V_41 , V_2 -> V_7 + V_46 ) ;
F_2 ( V_40 , V_2 -> V_7 + V_47 ) ;
V_42 = 0 ;
V_44:
F_7 ( & V_2 -> V_16 , V_14 ) ;
return V_42 ;
}
void F_15 ( struct V_1 * V_2 , int V_48 )
{
unsigned long V_14 ;
T_1 V_15 ;
F_6 ( & V_2 -> V_16 , V_14 ) ;
F_1 ( V_2 , 0 ) ;
V_15 = ( V_38 |
V_33 |
V_32 |
V_49 ) ;
if ( V_48 )
V_15 |= V_50 ;
if ( V_2 -> V_14 & V_31 )
V_15 |= V_34 ;
F_2 ( V_15 , V_2 -> V_7 + V_8 ) ;
F_7 ( & V_2 -> V_16 , V_14 ) ;
}
unsigned int F_16 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_7 + V_46 ) ;
}
unsigned int F_17 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_7 + V_47 ) ;
}
void F_18 ( struct V_1 * V_2 , int V_35 )
{
unsigned long V_14 ;
T_1 V_51 , V_15 ;
F_6 ( & V_2 -> V_16 , V_14 ) ;
V_51 = V_15 = F_4 ( V_2 -> V_7 + V_8 ) ;
if ( V_35 )
V_15 |= V_43 ;
else
V_15 &= ~ V_43 ;
if ( ( V_51 & V_43 ) !=
( V_15 & V_43 ) )
F_2 ( V_15 , V_2 -> V_7 + V_8 ) ;
F_7 ( & V_2 -> V_16 , V_14 ) ;
}
