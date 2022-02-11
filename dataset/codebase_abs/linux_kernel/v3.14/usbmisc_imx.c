static int F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 ;
unsigned long V_4 ;
T_2 V_5 ;
if ( V_2 -> V_6 > 2 )
return - V_7 ;
V_3 = V_8 -> V_9 + V_10 ;
if ( V_2 -> V_11 ) {
F_2 ( & V_8 -> V_12 , V_4 ) ;
V_5 = F_3 ( V_3 ) ;
F_4 ( V_5 | V_13 , V_3 ) ;
F_5 ( & V_8 -> V_12 , V_4 ) ;
F_6 ( 5000 , 10000 ) ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
T_2 V_5 ;
switch ( V_2 -> V_6 ) {
case 0 :
V_5 = V_14 ;
break;
case 1 :
V_5 = V_15 ;
break;
case 2 :
V_5 = V_16 ;
break;
default:
return - V_7 ;
} ;
F_2 ( & V_8 -> V_12 , V_4 ) ;
if ( V_2 -> V_17 )
V_5 = F_3 ( V_8 -> V_9 ) | V_5 ;
else
V_5 = F_3 ( V_8 -> V_9 ) & ~ V_5 ;
F_4 ( V_5 , V_8 -> V_9 ) ;
F_5 ( & V_8 -> V_12 , V_4 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
void T_1 * V_3 = NULL ;
unsigned long V_4 ;
T_2 V_5 = 0 ;
if ( V_2 -> V_6 > 3 )
return - V_7 ;
if ( V_2 -> V_17 ) {
F_2 ( & V_8 -> V_12 , V_4 ) ;
switch ( V_2 -> V_6 ) {
case 0 :
V_3 = V_8 -> V_9 + V_18 ;
V_5 = F_3 ( V_3 ) | V_19 ;
break;
case 1 :
V_3 = V_8 -> V_9 + V_18 ;
V_5 = F_3 ( V_3 ) | V_20 ;
break;
case 2 :
V_3 = V_8 -> V_9 + V_21 ;
V_5 = F_3 ( V_3 ) | V_22 ;
break;
case 3 :
V_3 = V_8 -> V_9 + V_23 ;
V_5 = F_3 ( V_3 ) | V_22 ;
break;
}
if ( V_3 && V_5 )
F_4 ( V_5 , V_3 ) ;
F_5 ( & V_8 -> V_12 , V_4 ) ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
T_2 V_3 ;
if ( V_2 -> V_6 > 3 )
return - V_7 ;
if ( V_2 -> V_17 ) {
F_2 ( & V_8 -> V_12 , V_4 ) ;
V_3 = F_3 ( V_8 -> V_9 + V_2 -> V_6 * 4 ) ;
F_4 ( V_3 | V_24 ,
V_8 -> V_9 + V_2 -> V_6 * 4 ) ;
F_5 ( & V_8 -> V_12 , V_4 ) ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
if ( ! V_8 )
return - V_25 ;
if ( ! V_8 -> V_26 -> V_27 )
return 0 ;
return V_8 -> V_26 -> V_27 ( V_2 ) ;
}
int F_11 ( struct V_1 * V_2 )
{
if ( ! V_8 )
return - V_25 ;
if ( ! V_8 -> V_26 -> V_28 )
return 0 ;
return V_8 -> V_26 -> V_28 ( V_2 ) ;
}
static int F_12 ( struct V_29 * V_30 )
{
struct V_31 * V_32 ;
struct V_33 * V_2 ;
int V_34 ;
struct V_35 * V_36 ;
if ( V_8 )
return - V_37 ;
V_2 = F_13 ( & V_30 -> V_38 , sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 )
return - V_40 ;
F_14 ( & V_2 -> V_12 ) ;
V_32 = F_15 ( V_30 , V_41 , 0 ) ;
V_2 -> V_9 = F_16 ( & V_30 -> V_38 , V_32 ) ;
if ( F_17 ( V_2 -> V_9 ) )
return F_18 ( V_2 -> V_9 ) ;
V_2 -> V_42 = F_19 ( & V_30 -> V_38 , NULL ) ;
if ( F_17 ( V_2 -> V_42 ) ) {
F_20 ( & V_30 -> V_38 ,
L_1 , F_18 ( V_2 -> V_42 ) ) ;
return F_18 ( V_2 -> V_42 ) ;
}
V_34 = F_21 ( V_2 -> V_42 ) ;
if ( V_34 ) {
F_20 ( & V_30 -> V_38 ,
L_2 , V_34 ) ;
return V_34 ;
}
V_36 = (struct V_35 * )
F_22 ( V_43 , & V_30 -> V_38 ) ;
V_2 -> V_26 = ( const struct V_44 * ) V_36 -> V_2 ;
V_8 = V_2 ;
return 0 ;
}
static int F_23 ( struct V_29 * V_30 )
{
F_24 ( V_8 -> V_42 ) ;
V_8 = NULL ;
return 0 ;
}
